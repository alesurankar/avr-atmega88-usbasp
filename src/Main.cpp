#include "Counter.h"

int main()
{
  Counter count;

  while(1) {
    count.Count();
    //count.Test();
    count.SetOutput();
  }
}