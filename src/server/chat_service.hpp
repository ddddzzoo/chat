#ifndef CHAT_SERVICE_H
#define CHAT_SERVICE_H

#include <muduo/net/TcpConnection.h>

#include <functional>
#include <mutex>
#include <string>
#include <unordered_map>

#include "json.hpp"
#include "model/offline_message_model.hpp"
#include "model/user_model.hpp"

using namespace std;
using namespace muduo;
using namespace muduo::net;
using json = nlohmann::json;

// 处理消息的事件回调方法类型
using MsgHandler =
    std::function<void(const TcpConnectionPtr& conn, json& js, Timestamp time)>;

class ChatService {
 public:
  // 获取单对象接口函数
  static ChatService& instance();

  // 处理登录业务
  void login(const TcpConnectionPtr& conn, json& js, Timestamp time);

  // 处理注册业务
  void reg(const TcpConnectionPtr& conn, json& js, Timestamp time);

  // 处理客户端异常退出
  void clientCloseException(const TcpConnectionPtr& conn);

  // 获取消息对应处理器
  MsgHandler getHandler(int msgid);

  // 一对一聊天业务
  void oneChat(const TcpConnectionPtr& conn, json& js, Timestamp time);

  // 服务器异常退出，重置用户state
  void reset();

 private:
  ChatService();

  // 储存消息id和其对应业务处理方法
  unordered_map<int, MsgHandler> _msgHandlerMap;
  // 储存在线用户的通信连接
  unordered_map<int, TcpConnectionPtr> _userConnMap;
  // 定义互斥锁，保证_userConnMap的线程安全
  mutex _connMutex;

  // 数据操作类对象
  UserModel _userModel;
  OfflineMsgModel _offlineMsgModel;
};

#endif