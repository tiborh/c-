#include "hello.h"

int main (int argc, char ** argv)
{
  hello *default_hello = new hello();
  hello *custom_hello = new hello("今日は！","今日は世界！");
  //hello *another_hello = new hello("ようこそ","ようこそ,世界！");

  return(Fl::run());
}
