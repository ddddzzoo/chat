#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>

using namespace muduo;
using namespace muduo::net;

// 聊天服务器主类
class ChatServer {
 public:
  // 初始化聊天服务器对象
  ChatServer(EventLoop* loop, const InetAddress& listenAddr,
             const string& nameArg);
  ~ChatServer() = default;

  // 启动服务
  void start();

 private:
  // 上报连接相关信息回调函数
  void onConnection(const TcpConnectionPtr&);
  // 上报读写相关信息回调函数
  void onMessage(const TcpConnectionPtr&, Buffer*, Timestamp);

  TcpServer _server;  // muduo库，实现服务器功能类
  EventLoop* _loop;   // muduo库，指向事件循环指针
};

#endif