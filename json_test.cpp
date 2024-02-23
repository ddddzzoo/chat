#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "thirdparty/json.hpp"

using json = nlohmann::json;

void fun1()
{
  json js;
  js["msg_type"] = 2;
  js["from"] = "zhang san";
  js["to"] = "li si";
  js["msg"] = "yi dao sha le ni";

  std::string send_buf = js.dump();
  std::cout << send_buf.c_str() << std::endl;
}

void fun2()
{
  json js;
  // 添加数组
  js["id"] = {1, 2, 3, 4, 5};
  // 添加 key-value
  js["name"] = "zhang san";
  // 添加对象
  js["msg"]["zhang san"] = "zhang san";
  js["msg"]["li si"] = "li si";
  // 统一添加
  js["msg"] = {{"zhang san", "zhang san"}, {"li si", "li si"}};
  std::cout << js << std::endl;
}

void fun3()
{
  json js;

  std::vector<int> vec;
  vec.emplace_back(1);
  vec.emplace_back(2);
  vec.emplace_back(3);

  js["list"] = vec;

  std::map<int, std::string> m;
  m.insert({1, "zhang san"});
  m.insert({2, "li si"});
  m.insert({3, "wang wu"});

  js["map"] = m;

  std::cout << js << std::endl;
}

int main()
{
  fun1();

  fun2();

  fun3();

  return 0;
}