#include "ringBuffer.h"
#include "TEST_ringBuffer.h"

int main()
{
  sCircularBuffer buff;
  int buffer_size = 10;
  test(buff, buffer_size);
  return 0;
}