#pragma once

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QString>
#include <QUrl>

#include "Global.h"
#include "Singleton.h"

// CRTP
class HttpMgr : public QObject,
                public Singleton<HttpMgr>,
                public std::enable_shared_from_this<HttpMgr> {
  Q_OBJECT

 public:
  ~HttpMgr();

 private:
  HttpMgr();

  void PostHttpReg(QUrl url, QJsonObject json, ReqId req_id, Modules mod);

  friend class Singleton<HttpMgr>;
  QNetworkAccessManager _manager;

 public slots:
  void slot_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod);

 signals:
  void sig_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod);

  // 注册模块http相关请求完成发送信号
  void sig_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
};
