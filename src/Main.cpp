#include "Counter.h"

int main()
{
  Counter count;

  while(1) {
    count.Btn1Read();
    count.Btn2Read();
    count.Count();
    //count.Test();
    count.ShowOutput();
  }
}