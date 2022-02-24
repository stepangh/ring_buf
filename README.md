## Кольцевой буфер ##
### Определение ###
Кольцевой буфер, или циклический буфер (англ. ring-buffer) — это структура данных, использующая единственный буфер фиксированного размера таким образом, как будто бы после последнего элемента сразу же снова идет первый. Такая структура легко предоставляет возможность буферизации потоков данных.Кольцевой буфер находит очень широкое применение в том числе при программировании микроконтроллеров. Данные структуры часто используют для организации различных очередей сообщений и буферов приёма-передачи различных коммуникационных интерфейсов. Популярность КБ обусловлена тем, что это один из самых простых и эффективных способов организовать FIFO (англ. first in — first out, «первым пришёл — первым вышел») без использования динамической памяти.
### Структура ###
```C
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

//Инициализация буфера
void init(sCircularBuffer *buff, int size);

//Запись значения 'value' в буфер
int write(sCircularBuffer *buff, int8_t value);

//Запись блока данных в буфер
void writeBlock(sCircularBuffer *buff, size_t bl_size, int8_t block[bl_size]);

//Чтение байта из буфера
int8_t read(sCircularBuffer *buff);

//Очистить буфер
void clear(sCircularBuffer *buff);

//Возврат флага 'isEmpty'
int isEmpty(sCircularBuffer *buff);

//Возврат флага 'isFull'
int isFull(sCircularBuffer *buff);

//Узнать количество полезных данных в буфере
int8_t getCount(sCircularBuffer *buff);

//Вывод буфера в консоль
void display(sCircularBuffer *buff);
```
