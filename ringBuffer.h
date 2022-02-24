#ifndef RING_BUFFER_
#define RING_BUFFER_
//------------------------------------------------
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>

typedef struct
{
  int readIndex;
  int writeIndex;
  int isEmpty;
  int isFull;
  int8_t size;
  int8_t *data;
  pthread_mutex_t mutex;
}sCircularBuffer;

void init(sCircularBuffer *buff, int size);
int write(sCircularBuffer *buff, int8_t value);
void writeBlock(sCircularBuffer *buff, size_t bl_size, int8_t block[bl_size]);
int8_t read(sCircularBuffer *buff);
void clear(sCircularBuffer *buff);
int isEmpty(sCircularBuffer *buff);
int isFull(sCircularBuffer *buff);
int8_t getCount(sCircularBuffer *buff);
void display(sCircularBuffer *buff);
//----------------------------------------------
#endif /* RING_BUFFER_ */