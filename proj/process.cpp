#include<windows.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int i,j;
void gotoxy (int coluna, int linha){
	COORD point;
	point.X = coluna; point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void processing(){
for (i=0;i<300;i++){
	printf("     %d    %c",i,i);
}	
getch();
   for (i=0;i<3;i++){
	
	gotoxy(4,1+i);
       if (i==0 || i==2){
       	for (int j=0;j<28;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                          %c",219,219);
		   }	
	printf("\n");
}}

void verificacao(){
	
	printf("V E R I F I C A N D O  N O V A S   A C T U A L I Z A C O E S");
	j=1;
	for (i=0;i<1023;i++){
	
	//SLEEP;
	gotoxy(4,4);
	printf("%d  D E  1022",i);
}
	
}
int main(){
	verificacao();
//	processing();
//	sleep(1);
//system("sleep(1)");
}
