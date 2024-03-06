#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

#include "group_user.hpp"
using namespace std;

// User表的ORM类
class Group {
 private:
  int id;
  string name;
  string desc;
  vector<GroupUser> users;

 public:
  Group(int id = -1, string name = "", string desc = "") {
    this->id = id;
    this->name = name;
    this->desc = desc;
  }

  void setId(int id) { this->id = id; }
  void setName(string name) { this->name = name; }
  void setDesc(string desc) { this->desc = desc; }

  int getId() { return this->id; }
  string getName() { return this->name; }
  string getDesc() { return this->name; }
  vector<GroupUser> &getUsers() { return this->users; }
};

#endif