#include "chat_service.hpp"

#include <muduo/base/Logging.h>

#include "../public.hpp"

using namespace muduo;

// 获取单例函数对象
ChatService& ChatService::instance() {
  static ChatService chatService;
  return chatService;
}

// 注册消息以及对应Handler回调操作
ChatService::ChatService() {
  _msgHandlerMap.insert(
      {LOGIN_MSG, std::bind(&ChatService::login, this, _1, _2, _3)});
  _msgHandlerMap.insert(
      {REG_MSG, std::bind(&ChatService::reg, this, _1, _2, _3)});
}

// 处理登录业务
void ChatService::login(const TcpConnectionPtr& conn, json& js,
                        Timestamp time) {
  LOG_INFO << "login";
}

// 处理注册业务
void ChatService::reg(const TcpConnectionPtr& conn, json& js, Timestamp time) {
  LOG_INFO << "reg";
}

// 获取消息对应处理器
MsgHandler ChatService::getHandler(int msgid) {
  // 记录错误日志，msgid没有对应事件处理回调
  auto it = _msgHandlerMap.find(msgid);
  if (it == _msgHandlerMap.end()) {
    // 返回一个默认的处理器，空操作
    return [=](const TcpConnectionPtr& conn, json& js, Timestamp) {
      LOG_ERROR << "msgid:" << msgid << " can not find handler!";
    };
  }
  else {
    return _msgHandlerMap[msgid];
  }
}