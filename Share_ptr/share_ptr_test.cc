#include <string>

#include "share_ptr.h"
void Test1() {
  printf(">>>>>>>>>>>>>>构造函数、拷贝构造函数、拷贝赋值函数测试,作用域结束后自动销毁 测试>>>>>>>>>>>>>>>>>>>\n");
  rain::share_ptr<std::string> sp1(new std::string("hello"));  // 构造函数测试
  rain::share_ptr<std::string> sp2(sp1);                       // 拷贝构造函数测试
  printf("sp1.use_cout[%d] sp1.ptr[%s] sp2.use_cout[%d] sp2.ptr[%s]\n", sp1.use_count(), sp1->c_str(), sp2.use_count(),
         sp2->c_str());
  rain::share_ptr<std::string> sp3(new std::string("word"));
  sp1 = sp3;
  printf("sp1.use_cout[%d] sp1.ptr[%s] sp2.use_cout[%d] sp2.ptr[%s] sp3.use_count[%d] sp3.ptr[%s]\n", sp1.use_count(),
         sp1->c_str(), sp2.use_count(), sp2->c_str(), sp3.use_count(), sp3->c_str());
  printf(">>>>>>>>>>>>>>测试结束>>>>>>>>>>>>>>>>>>>\n");
}

void Test2() {
  printf(">>>>>>>>>>>>>>自赋值 测试>>>>>>>>>>>>>>>>>>>\n");
  rain::share_ptr<std::string> sp1(new std::string("hello"));
  rain::share_ptr<std::string> sp2(sp1);
  sp2 = sp1;
  printf(">>>>>>>>>>>>>>测试结束>>>>>>>>>>>>>>>>>>>\n");
}

void Test3() {
  printf(">>>>>>>>>>>>>>当资源没有指针指向时,自动销毁 测试>>>>>>>>>>>>>>>>>>>\n");
  rain::share_ptr<std::string> sp1(new std::string("hello"));
  rain::share_ptr<std::string> sp2;
  sp2 = sp1;
  rain::share_ptr<std::string> sp3(new std::string("word"));
  sp1 = sp3;
  sp2 = sp3;
  printf("sp1.use_cout[%d] sp1.ptr[%s] sp2.use_cout[%d] sp2.ptr[%s] sp3.use_count[%d] sp3.ptr[%s]\n", sp1.use_count(),
         sp1->c_str(), sp2.use_count(), sp2->c_str(), sp3.use_count(), sp3->c_str());
  printf(">>>>>>>>>>>>>>测试结束>>>>>>>>>>>>>>>>>>>\n");
}

void Test4() {
  printf(">>>>>>>>>>>>>>用智能指针的裸指针初始化测试  会出现double free的问题 >>>>>>>>>>>>>>>>>>>\n");
  rain::share_ptr<std::string> sp1(new std::string("hello"));
  rain::share_ptr<std::string> sp2(sp1.get());
  printf("sp1.use_cout[%d] sp1.ptr[%s] sp2.use_cout[%d] sp2.ptr[%s] \n", sp1.use_count(), sp1->c_str(), sp2.use_count(),
         sp2->c_str());
  printf(">>>>>>>>>>>>>>测试结束>>>>>>>>>>>>>>>>>>>\n");
}

int main() {
  Test1();
  Test2();
  Test3();
  // Test4();
}