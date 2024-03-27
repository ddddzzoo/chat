#include "HttpMgr.h"

HttpMgr::~HttpMgr() {}

HttpMgr::HttpMgr() {
  // 连接http请求和完成信号，信号槽机制保证队列消费
  connect(this, &HttpMgr::sig_http_finish, this, &HttpMgr::slot_http_finish);
}

void HttpMgr::PostHttpReg(QUrl url, QJsonObject json, ReqId req_id,
                          Modules mod) {
  // 创建一个http post请求 并设置请求头
  QByteArray data = QJsonDocument(json).toJson();

  QNetworkRequest request(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  request.setHeader(QNetworkRequest::ContentLengthHeader,
                    QByteArray::number(data.length()));
  // 外部使用智能指针管理HttpMgr shared_from_this生成智能指针
  // 获取自己的智能指针，构造伪闭包并增加智能指针引用计数，智能指针的引用计数一致
  auto self = shared_from_this();
  // 调用post请求发送数据
  QNetworkReply* reply = _manager.post(request, data);

  // 发送完成后回收reply指针 无法确定回收信号时HttpMgr存活
  // 捕获智能指针避免程序崩溃
  QObject::connect(
      reply, &QNetworkReply::finished, [self, reply, req_id, mod]() {
        // 处理错误情况
        if (reply->error() != QNetworkReply::NoError) {
          qDebug() << reply->errorString();
          // 发送错误信号
          emit self->sig_http_finish(req_id, "", ErrorCodes::ERR_NETWORK, mod);
          reply->deleteLater();
          return;
        }

        // 无错误读回请求
        QString res = reply->readAll();

        // 发送信号通知完成
        emit self->sig_http_finish(req_id, res, ErrorCodes::SUCCESS, mod);
        reply->deleteLater();
        return;
      });
}

void HttpMgr::slot_http_finish(ReqId id, QString res, ErrorCodes err,
                               Modules mod) {
  if (mod == Modules::REGISTERMOD) {
    // 发送信号通知指定模块http响应结束
    emit sig_reg_mod_finish(id, res, err);
  }
}
