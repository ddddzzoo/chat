#ifndef OFFLINE_MESSAGE_MODEL_H
#define OFFLINE_MESSAGE_MODEL_H

#include <string>
#include <vector>
using namespace std;

// 提供离线消息表操作接口
class OfflineMsgModel {
 public:
  // 存储用户离线消息
  void insert(int userid, string msg);

  // 删除用户离线消息
  void remove(int userid);

  // 查询用户离线消息
  vector<string> query(int userid);
};

#endif