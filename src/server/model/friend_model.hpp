#ifndef FRIEND_MODEL_H
#define FRIEND_MODEL_H

#include <vector>

#include "user.hpp"
using namespace std;

// 维护好友信息的操作接口
class FriendModel {
 public:
  // 添加好友关系
  void insert(int userid, int friendid);

  // 返回用户好友列表
  vector<User> query(int userid);
};

#endif