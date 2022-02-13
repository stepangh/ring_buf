#include <stdio.h>
#include <stdint.h>
#include "ringBuffer.h"
//#define BUFFER_SIZE 10

int main()
{
  sCircularBuffer buff;
  int buffer_size = 10;
  int8_t r;
  printf("\nПроинициализируем буффер и выведем его, получим некорректные значения внутри: \n");
  init(&buff, buffer_size);
  display(&buff);
  
  printf("Теперь проверим функцию записи в буффер, добавив 1 и 2 и снова выведем значения: \n");
  write(&buff, 1);
  write(&buff, 2);
  display(&buff);
  
  printf("Далее добавим блок элементов, например 8 троек и снова выведем наш буфер: \n");
  int8_t block[] = {3, 3, 3, 3, 3, 3, 3, 3};
  size_t bl_size = sizeof(block)/sizeof(block[0]);
  writeBlock(&buff, bl_size, block);
  display(&buff);
  
  printf("Теперь попробуем считать значение из буфера и вывести его на экран, также выведем индексы, отвечающие за запись и чтение: \n");
  r = read(&buff);
  printf("Считанный элемент равен %d\n", r);
  printf("readIndex: %d\n", buff.readIndex);
  printf("writeIndex: %d\n", buff.writeIndex);
  printf("Индекс чтения равен 1, так как считали мы один элемент, а индекс записи 10, так как именно столько элементов мы записали \n");
  
  printf("\nТеперь попробуем записать числа 4 и 5 в наш буфер и снова выведем его: \n");
  write(&buff, 4);
  write(&buff, 5);
  display(&buff);
  printf("Видим буффер, в котором нет добавленной 5, а также сообщение, о том что буфер полон. \n");
  
  printf("\nПопробуем считать элемент, а затем снова попробуем добавить значение 5, теперь всё получится \n");
  r = read(&buff);
  printf("Считанный элемент равен %d\n", r);
  write(&buff, 5);
  display(&buff);
  
  printf("Теперь считаем все элементы из буфера и получим сообщение о том, что буфер пуст \n");
  for(int i = 0; i <= buffer_size; i++)
	r = read(&buff);

  printf("\nКонец тестирования\n");
  
  return 0;
}