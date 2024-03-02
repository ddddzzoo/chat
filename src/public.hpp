#ifndef PUBLIC_H
#define PUBLIC_H

// 服务器和客户端的公共文件
enum EnMsgType {
  LOGIN_MSG = 1,  // 登录消息
  REG_MSG,        // 注册消息
  REG_MSG_ACK,    // 注册响应消息

};

#endif