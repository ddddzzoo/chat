#pragma once

#include "const.h"

class CServer : public std::enable_shared_from_this<CServer> {
 public:
  CServer() = default;
  CServer(net::io_context& ioc, unsigned short port);
  void Start();

 private:
  tcp::acceptor _acceptor;
  net::io_context& _ioc;  // 事件循环上下文
  tcp::socket _socket;
};
