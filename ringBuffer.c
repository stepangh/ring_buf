#include "ringBuffer.h"

void init(sCircularBuffer *buff, int size)
{
  buff->readIndex  = 0;
  buff->writeIndex = 0;
  buff->isEmpty    = 1;
  buff->isFull     = 0;
  buff->size       = size;
  buff->data = (int8_t*)malloc(size*sizeof(int8_t));
  buff->mutex = PTHREAD_MUTEX_INITIALIZER;
}

int write(sCircularBuffer *buff, int8_t value)
{
  pthread_mutex_lock(&buff->mutex);
  if(buff->isFull)
  {
	//printf("Buffer is full\n");
	pthread_mutex_unlock(&buff->mutex);
	return -1;
  }
  if(buff->writeIndex >= buff->size)
  {
	buff->writeIndex = 0;
  }
    buff->isEmpty = 0;
    buff->data[buff->writeIndex++] = value;

    if (buff->writeIndex == buff->readIndex)
	{
		buff->isFull  = 1;
	}
    pthread_mutex_unlock(&buff->mutex);
    return 1;
}

void writeBlock(sCircularBuffer *buff, size_t bl_size, int8_t block[bl_size])
{
  for (int i = 0; i < bl_size; i++)
  {
	write(buff, block[i]);
  }
}

int8_t read(sCircularBuffer *buff)
{
  pthread_mutex_lock(&buff->mutex);
  if(buff->isEmpty)
  {
	//printf("Buffer is empty\n");
	pthread_mutex_unlock(&buff->mutex);
    return -1;
  }
  buff->isFull = 0;

  if(buff->readIndex >= buff->size)
    
	{
	  buff->readIndex = 0;
	}

  int8_t res = buff->data[buff->readIndex++];

  if(buff->readIndex == buff->writeIndex)
  {
	buff->isEmpty = 1;
  }
  
  pthread_mutex_unlock(&buff->mutex);
  return res;
}

void clear(sCircularBuffer *buff)
{
  buff->isEmpty    = 1;
  buff->isFull     = 0;
  buff->writeIndex = 0;
  buff->readIndex  = 0;
  free(buff->data);
}

int isEmpty(sCircularBuffer *buff)
{
  return buff->isEmpty;
}

int isFull(sCircularBuffer *buff)
{
  return buff->isFull;
}

int8_t getCount (sCircularBuffer *buff)
{
    int8_t res = 0;
    if (buff->writeIndex <= buff->readIndex) 
	{
		res = buff->size + buff->writeIndex - buff->readIndex;
    }
	else
	{		
		res = buff->writeIndex - buff->readIndex;
    }
	return res;
}

void display(sCircularBuffer *buff)
{
	int i;
	for (i = 0; i < buff->size; i++)
	{
		printf("%d ", buff->data[i]);
	}
	printf("\n\n");
}