#pragma once

// 单例模板
template <typename T>
class Singleton {
 public:
  static T& GetInstance() {
    static T instance;
    return instance;
  }

  Singleton(Singleton&&) = delete;
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

 protected:
  Singleton() = default;
  virtual ~Singleton() = default;
};