#include <string>

#include "unique_ptr.h"
void Test1() {
  printf(">>>>>>>>>>>>>>>>>>>堆栈分配内存自动释放>>>>>>>>>>>>>>>>>>>\n");
  rain::unique_ptr<std::string> str(new std::string("unique"));
  printf(">>>>>>>>>>>>>>>>>>>测试结束>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

void Test2() {
  printf(">>>>>>>>>>>>>>>>>>>>移动构造测试>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  rain::unique_ptr<std::string> str(new std::string("unique"));
  rain::unique_ptr<std::string> str2 = std::move(str);
  printf(">>>>>>>>>>>>>>>>>>>>测试结束>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

void Test3() {
  printf(">>>>>>>>>>>>>>>>>>>>移动赋值测试>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
  rain::unique_ptr<std::string> str(new std::string("unique"));
  rain::unique_ptr<std::string> str2(new std::string("ptr"));
  str2 = std::move(str);
  printf(">>>>>>>>>>>>>>>>>>>>测试结束>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}

int main() {
  Test1();
  Test2();
  Test3();
}