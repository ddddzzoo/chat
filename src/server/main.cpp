#include <signal.h>

#include <iostream>

#include "chat_server.hpp"
#include "chat_service.hpp"

using namespace std;

// 处理服务器CTRL+C结束，重置user状态信息
void resetHandler(int) {
  ChatService::instance();
  exit(0);
}

int main() {
  signal(SIGINT, resetHandler);

  EventLoop loop;
  InetAddress addr("127.0.0.1", 6000);

  ChatServer server(&loop, addr, "ChatServer");

  server.start();
  loop.loop();

  return 0;
}