 /*#include <iostream>

#include <Windows.h>

using namespace std;

void gotoxy(int x,int y)

{

COORD loc={x,y};

HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleCursorPosition(hOutput,loc);

}

int main()

{

gotoxy(50,0);

cout<<"Hello World!"<<endl;

system("pause");

return 0;

}
  ���� windos,h   ������һ��  ��Ȼ����ǿ��  */
#include<stdio.h>    
#include<windows.h>   
int main()    
{  
  HANDLE hOut;  
  COORD pos= {0, 0}; 
  int i;  
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);   //�������
  SetConsoleTextAttribute(hOut, 0x01|0x05); //��ɫ����  
  for(i=0;i<20;i++)    
  {  
  pos.X=i;   
  pos.Y=i;  
  SetConsoleCursorPosition(hOut, pos);  //���궨λ
  printf("%d %d:Hello World!\n",pos.X,pos.Y);    
}  
  return 0;   
} 