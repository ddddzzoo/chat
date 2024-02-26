#include "thirdparty/json.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

using json = nlohmann::json;

std::string fun1() {
  json js;
  js["msg_type"] = 2;
  js["from"] = "zhang san";
  js["to"] = "li si";
  js["msg"] = "yi dao sha le ni";

  std::string send_buf = js.dump();
  // std::cout << send_buf.c_str() << std::endl;
  return send_buf;
}

void fun2() {
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

std::string fun3() {
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

  // std::cout << js << std::endl;
  std::string send_buf = js.dump();
  return send_buf;
}

int main() {
  std::string recv_buf1 = fun1();
  // 数据反序列化
  json js_buf1 = json::parse(recv_buf1);
  std::cout << js_buf1["msg_type"] << std::endl;
  std::cout << js_buf1["from"] << std::endl;
  std::cout << js_buf1["to"] << std::endl;
  std::cout << js_buf1["msg"] << std::endl;

fun2();

  std::string recv_buf2 = fun3();

  json js_buf2 = json::parse(recv_buf2);

  std::vector<int> vec = js_buf2["list"];
  for (auto &i : vec) {
    std::cout << i << " ";
  }

  std::map<int, std::string> m = js_buf2["map"];
  for (auto &i : m) {
    std::cout << i.first  << " " << i.second << std::endl;
  }

  return 0;
}