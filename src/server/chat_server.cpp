#include "chat_server.hpp"

#include <functional>
using namespace std;
using namespace placeholders;

// 初始化聊天服务器对象
ChatServer::ChatServer(EventLoop* loop, const InetAddress& listenAddr,
                       const string& nameArg)
    : _server(loop, listenAddr, nameArg) {
  // 注册连接回调
  _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));

  // 注册消息回调
  _server.setMessageCallback(
      std::bind(&ChatServer::onMessage, this, _1, _2, _3));

  // 设置线程数量
  _server.setThreadNum(4);
}

// 启动服务
void ChatServer::start() { _server.start(); }

// 上报连接相关信息回调函数
void ChatServer::onConnection(const TcpConnectionPtr&) {}

// 上报读写相关信息回调函数
void ChatServer::onMessage(const TcpConnectionPtr&, Buffer*, Timestamp) {}