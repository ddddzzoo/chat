#include "CServer.h"

#include "HttpConnection.h"

CServer::CServer(net::io_context& ioc, unsigned short port)
    : _ioc(ioc), _acceptor(ioc, tcp::endpoint(tcp::v4(), port)), _socket(ioc) {}

void CServer::Start() {
  auto self = shared_from_this();
  _acceptor.async_accept(_socket, [self](beast::error_code ec) {
    try {
      // 出错放弃该链接，继续监听其他链接
      if (ec) {
        self->Start();
        return;
      }
      // 处理新链接，创建HpptConnection类管理新连接
      // 将_socket内部数据转移给HttpConnection管理，_socket继续接受链接
      std::make_shared<HttpConnection>(std::move(self->_socket))->Start();

      // 继续监听
      self->Start();

    } catch (const std::exception& exp) {
      std::cout << "exception is " << exp.what() << std::endl;
      self->Start();
    }
  });
}
