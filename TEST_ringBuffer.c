#include "TEST_ringBuffer.h"

void test(sCircularBuffer buff, int buffer_size)
{
  printf("Write_block_test: ");
  init(&buff, buffer_size);
  int8_t test[] = {1, 1, 1, 1, 1, 1, 1, 1};
  int8_t block[] = {1, 1, 1, 1, 1, 1, 1, 1};
  size_t bl_size = sizeof(block)/sizeof(block[0]);
  writeBlock(&buff, bl_size, block);
  //display(&buff);
  int i = 0;
  for (i = 0; i < 8; i++)
  {
	if (test[i] != buff.data[i])
		break;
  }
  if (i==8)
  {
	  printf("Correct\n");
  }
  else
  {
	  printf("Incorrect\n");
  }
  //----------------------------------------------------------
  printf("Write_byte_test: ");
  write(&buff, 2);
  write(&buff, 3);
  if (buff.data[8] == 2 && buff.data[9] == 3)
  {
	  printf("Correct\n");
  }
  else
  {
	  printf("Incorrect\n");
  }
  //----------------------------------------------------------
  printf("Read_byte_test: ");
  int8_t r;
  r = read(&buff);
  if (r == buff.data[0])
  {
	  printf("Correct\n");
  }
  else
  {
	  printf("Incorrect\n");
  }
  //----------------------------------------------------------
  printf("Get_count_test: ");
  r = getCount(&buff);
  if (r == 9)
  {
	  printf("Correct\n");
  }
  else
  {
	  printf("Incorrect\n");
  }
  //----------------------------------------------------------
  //display(&buff);
  printf("Write_overflow: ");
  int8_t block2[] = {4, 4, 4};
  size_t bl2_size = sizeof(block2)/sizeof(block2[0]);
  writeBlock(&buff, bl2_size, block2);
  int8_t test2[] = {4, 1, 1, 1, 1, 1, 1, 1, 2, 3}; //записаться должна только первая четвёрка
  for (i = 0; i < 10; i++)
  {
	if (test2[i] != buff.data[i])
		break;
  }
  if (i==10)
  {
	  printf("Correct\n");
  }
  else
  {
	  printf("Incorrect\n");
  }
  printf("\nTHE END OF TEST\n");
  clear(&buff);
}