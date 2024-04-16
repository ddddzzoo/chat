#pragma once

#include <functional>
#include <map>

#include "Singleton.h"
#include "const.h"

class HttpConnection;
using HttpHandler = std::function<void(std::shared_ptr<HttpConnection>)>;

class LogicSystem : public Singleton<LogicSystem> {
  friend class Singleton<LogicSystem>;

 public:
  ~LogicSystem() = default;
  bool HandleGet(std::string path, std::shared_ptr<HttpConnection> con);
  void RegGet(std::string url, HttpHandler handler);

 private:
  LogicSystem();
  // post请求回调函数map key：路由 value：回调函数指针
  std::map<std::string, HttpHandler> _post_handlers;
  // get请求回调函数map
  std::map<std::string, HttpHandler> _get_handlers;
};
