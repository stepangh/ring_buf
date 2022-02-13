#include <stdio.h>
#include <stdint.h>
#include "ringBuffer.h"
//#define BUFFER_SIZE 10

int main()
{
  sCircularBuffer buff;
  int buffer_size = 10;
  int8_t r;
  printf("\n�ந��樠�����㥬 ����� � �뢥��� ���, ����稬 �����४�� ���祭�� �����: \n");
  init(&buff, buffer_size);
  display(&buff);
  
  printf("������ �஢�ਬ �㭪�� ����� � �����, ������� 1 � 2 � ᭮�� �뢥��� ���祭��: \n");
  write(&buff, 1);
  write(&buff, 2);
  display(&buff);
  
  printf("����� ������� ���� ����⮢, ���ਬ�� 8 �஥� � ᭮�� �뢥��� ��� ����: \n");
  int8_t block[] = {3, 3, 3, 3, 3, 3, 3, 3};
  size_t bl_size = sizeof(block)/sizeof(block[0]);
  writeBlock(&buff, bl_size, block);
  display(&buff);
  
  printf("������ ���஡㥬 ����� ���祭�� �� ���� � �뢥�� ��� �� �࠭, ⠪�� �뢥��� �������, �⢥��騥 �� ������ � �⥭��: \n");
  r = read(&buff);
  printf("��⠭�� ����� ࠢ�� %d\n", r);
  printf("readIndex: %d\n", buff.readIndex);
  printf("writeIndex: %d\n", buff.writeIndex);
  printf("������ �⥭�� ࠢ�� 1, ⠪ ��� ��⠫� �� ���� �����, � ������ ����� 10, ⠪ ��� ������ �⮫쪮 ����⮢ �� ����ᠫ� \n");
  
  printf("\n������ ���஡㥬 ������� �᫠ 4 � 5 � ��� ���� � ᭮�� �뢥��� ���: \n");
  write(&buff, 4);
  write(&buff, 5);
  display(&buff);
  printf("����� �����, � ���஬ ��� ����������� 5, � ⠪�� ᮮ�饭��, � ⮬ �� ���� �����. \n");
  
  printf("\n���஡㥬 ����� �����, � ��⥬ ᭮�� ���஡㥬 �������� ���祭�� 5, ⥯��� ��� �������� \n");
  r = read(&buff);
  printf("��⠭�� ����� ࠢ�� %d\n", r);
  write(&buff, 5);
  display(&buff);
  
  printf("������ ��⠥� �� ������ �� ���� � ����稬 ᮮ�饭�� � ⮬, �� ���� ���� \n");
  for(int i = 0; i <= buffer_size; i++)
	r = read(&buff);

  printf("\n����� ���஢����\n");
  
  return 0;
}