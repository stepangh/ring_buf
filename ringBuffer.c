#include "ringBuffer.h"

void init(sCircularBuffer *buff, int size)
{
  buff->readIndex  = 0;
  buff->writeIndex = 0;
  buff->isEmpty    = 1;
  buff->isFull     = 0;
  buff->size       = size;
  buff->data = (int8_t*)malloc(size*sizeof(int8_t));
}
//------------------------------------------------------------------------------
int write(sCircularBuffer *buff, int8_t aValue)
{
  if(buff->isFull)
  {
	printf("Buffer is full\n");
	return -1;
  }
  if(buff->writeIndex >= BUFFER_SIZE)
    buff->writeIndex = 0;

  if(buff->isEmpty)
  {
    buff->isEmpty = 0;
    buff->data[buff->writeIndex++] = aValue;

    if (buff->writeIndex == buff->readIndex)
      buff->isFull  = 1;
    return 1;
  }

  buff->data[buff->writeIndex++] = aValue;

  if (buff->writeIndex == buff->readIndex)
    buff->isFull  = 1;

  return 1;
}
//------------------------------------------------------------------------------
void writeBlock(sCircularBuffer *buff, size_t bl_size, int8_t block[bl_size])
{
  for (int i = 0; i <= bl_size - 1; i++)
  {
	write(buff, block[i]);
  }
}
//------------------------------------------------------------------------------
int8_t read(sCircularBuffer *buff)
{
  if(buff->isEmpty)
  {
	printf("Buffer is empty\n");
    return -1;
  }
  buff->isFull = 0;

  if(buff->readIndex >= BUFFER_SIZE)
    buff->readIndex = 0;

  int8_t res = buff->data[buff->readIndex++];

  if(buff->readIndex == buff->writeIndex)
    buff->isEmpty = 1;

  return  res;
}
//------------------------------------------------------------------------------
void clear(sCircularBuffer *buff)
{
  buff->isEmpty    = 1;
  buff->isFull     = 0;
  buff->writeIndex = 0;
  buff->readIndex  = 0;
  free(buff->data);
}
//------------------------------------------------------------------------------
int isEmpty(sCircularBuffer *buff)
{
  return buff->isEmpty;
}
//------------------------------------------------------------------------------
int isFull(sCircularBuffer *buff)
{
  return buff->isFull;
}

void display(sCircularBuffer *buff)
{
	int i;
	for (i = 0; i <= BUFFER_SIZE - 1; i++)
		printf("%d ", buff->data[i]);
	printf("\n\n");
}
