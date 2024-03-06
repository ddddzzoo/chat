#ifndef GROUP_MODEL_H
#define GROUP_MODEL_H

#include <string>
#include <vector>

#include "group.hpp"
using namespace std;

// 维护群组信息操作接口
class GroupModel {
 public:
  // 创建群组
  bool creatGroup(Group &group);
  // 加入群组
  void addGroup(int userid, int groupid, string role);
  // 查询群组
  vector<Group> queryGroup(int userid);
  // 根据指定groupid查询群组用户id列表
  vector<int> queryGroupUsers(int userid, int groupid);
};

#endif