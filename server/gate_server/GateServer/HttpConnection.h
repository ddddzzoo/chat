#pragma once
#include "const.h"

class HttpConnection : public std::enable_shared_from_this<HttpConnection> {
  friend class LogicSystem;

 public:
  HttpConnection() = default;
  HttpConnection(tcp::socket socket);
  void Start();

 private:
  // 心跳包检测
  void CheckDeadline();
  void WriteResponse();
  void HandleReq();

  tcp::socket _socket;
  // 缓冲区
  beast::flat_buffer _buffer{8192};
  // 请求消息
  http::request<http::dynamic_body> _request;
  // 应答消息
  http::response<http::dynamic_body> _response;
  // 心跳超时时间
  net::steady_timer _deadline{_socket.get_executor(), std::chrono::seconds(60)};
};
