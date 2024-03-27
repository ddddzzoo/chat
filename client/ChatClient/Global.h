#pragma once

#include <QRegularExpression>
#include <QStyle>
#include <QWidget>
#include <functional>

// 用于刷新qss
extern std::function<void(QWidget *)> repolish;

enum ReqId {
  ID_GET_VARIFY_CODE = 1001,  // 获取验证码
  ID_REG_USER = 1002,         // 注册用户
};

enum Modules {
  REGISTERMOD = 0,  // 注册模块
};

enum ErrorCodes {
  SUCCESS = 0,
  ERR_JSON = 1,     // json解析失败
  ERR_NETWORK = 2,  // 网络错误
};