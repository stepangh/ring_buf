#include <stdio.h>
#include <stdint.h>
#define BUFFER_SIZE 5

typedef struct
{
  int readIndex;
  int writeIndex;
  int isEmpty;
  int isFull;
  int8_t data[BUFFER_SIZE];
}sCircularBuffer;

void init(sCircularBuffer *apArray)
{
  apArray->readIndex  = 0;
  apArray->writeIndex = 0;
  apArray->isEmpty    = 1;
  apArray->isFull     = 0;
}
//------------------------------------------------------------------------------
int write(sCircularBuffer *apArray, int8_t aValue)
{
  if(apArray->isFull)
  {
	printf("Buffer is full\n");
	return -1;
  }
  if(apArray->writeIndex >= BUFFER_SIZE)
    apArray->writeIndex = 0;

  if(apArray->isEmpty)
  {
    apArray->isEmpty = 0;
    apArray->data[apArray->writeIndex++] = aValue;

    if (apArray->writeIndex == apArray->readIndex)
      apArray->isFull  = 1;
    return 1;
  }

  apArray->data[apArray->writeIndex++] = aValue;

  if (apArray->writeIndex == apArray->readIndex)
    apArray->isFull  = 1;

  return 1;
}
//------------------------------------------------------------------------------
char read(sCircularBuffer *apArray)
{
  if(apArray->isEmpty)
  {
	printf("Buffer is empty\n");
    return -1;
  }
  apArray->isFull = 0;

  if(apArray->readIndex >= BUFFER_SIZE)
    apArray->readIndex = 0;

  char res = apArray->data[apArray->readIndex++];

  if(apArray->readIndex == apArray->writeIndex)
    apArray->isEmpty = 1;

  return  res;
}
//------------------------------------------------------------------------------
void clear(sCircularBuffer *apArray)
{
  apArray->isEmpty    = 1;
  apArray->isFull     = 0;
  apArray->writeIndex = 0;
  apArray->readIndex  = 0;
}
//------------------------------------------------------------------------------
int isEmpty(sCircularBuffer *apArray)
{
  return apArray->isEmpty;
}
//------------------------------------------------------------------------------
int isFull(sCircularBuffer *apArray)
{
  return apArray->isFull;
}

void display(sCircularBuffer *apArray)
{
	int i;
	//if (apArray->readIndex <= apArray->writeIndex)
	//{
		for (i = 0; i <= BUFFER_SIZE - 1; i++)
			printf("%d ", apArray->data[i]);
	//}		
	/*
	else
	{
		for (i = apArray->readIndex; i <= BUFFER_SIZE - 1; i++)
			printf("%3d", apArray->data[i]);
		for(i = 0; i <= apArray->writeIndex; i++)
			printf("%3d", apArray->data[i]);
	}
	*/
	printf("\n");
}

//------------------------------------------------------------------------------
int main()
{
	
  //printf("readIndex: %d\n", buff.readIndex);
  //printf("writeIndex: %d\n", buff.writeIndex);
  //display(&buff); //ВЫВОД БУФЕРА
  sCircularBuffer buff;
  int r;
  init(&buff);
  display(&buff);
  write(&buff, 1);
  r = read(&buff);
  display(&buff); //ВЫВОД БУФЕРА
  printf("readIndex: %d\n", buff.readIndex);
  printf("writeIndex: %d\n", buff.writeIndex);
  printf("EmptyFlag = %d\n", buff.isEmpty);
  printf("FullFlag = %d\n", buff.isFull);
  
  write(&buff, 1);
  display(&buff); //ВЫВОД БУФЕРА
  printf("readIndex: %d\n", buff.readIndex);
  printf("writeIndex: %d\n", buff.writeIndex);
  printf("EmptyFlag = %d\n", buff.isEmpty);
  printf("FullFlag = %d\n", buff.isFull);
  
  write(&buff, 1);
  
  write(&buff, 1);
  
  write(&buff, 1);
  write(&buff, 3);
  
  display(&buff);
  printf("readIndex: %d\n", buff.readIndex);
  printf("writeIndex: %d\n", buff.writeIndex);
  printf("EmptyFlag = %d\n", buff.isEmpty);
  printf("FullFlag = %d\n", buff.isFull);
  write(&buff, 3);
  display(&buff);
  return 0;
}