#include <string>
#include "share_ptr.h"
int main() {
  rain::share_ptr<std::string> sp1(new std::string("hello"));
  rain::share_ptr<std::string> sp2(sp1);
  printf("sp1.use_cout[%d] sp2.use_cout[%d]\n", sp1.use_count(), sp2.use_count());
  rain::share_ptr<std::string> sp3(new std::string("word"));
  sp2 = sp3;
  sp1 = sp2;
  printf("sp1.use_cout[%d] sp2.use_cout[%d] sp3.use_count[%d]\n", sp1.use_count(), sp2.use_count(),
         sp3.use_count());
  printf("sp1.ptr[%s]\n", sp1->c_str());
}