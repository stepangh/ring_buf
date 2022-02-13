#ifndef RING_BUFFER_
#define RING_BUFFER_
//------------------------------------------------
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <malloc.h>
#define BUFFER_SIZE 10
typedef struct
{
  int readIndex;
  int writeIndex;
  int isEmpty;
  int isFull;
  int8_t size;
  int8_t *data;
  //int8_t *data = (int8_t*)malloc(size + 1);
  //int8_t data[size];
}sCircularBuffer;

void init(sCircularBuffer *buff, int size);
int write(sCircularBuffer *buff, int8_t aValue);
void writeBlock(sCircularBuffer *buff, size_t bl_size, int8_t block[bl_size]);
int8_t read(sCircularBuffer *buff);
void clear(sCircularBuffer *buff);
int isEmpty(sCircularBuffer *buff);
int isFull(sCircularBuffer *buff);
void display(sCircularBuffer *buff);
//----------------------------------------------
#endif /* RING_BUFFER_ */