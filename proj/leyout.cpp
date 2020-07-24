#include<windows.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int i;
int x,v,y;
char c;
void gotoxy (int coluna, int linha){
	COORD point;
	point.X = coluna; point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
 void quadrado(){

system("COLOR 70");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
for (i=0;i<6;i++){
	
	gotoxy(4,1+i);
       if (i==0 || i==5){
       	for (int j=0;j<28;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                          %c",219,219);
		   }	
	printf("\n");
}
//system("COLOR 43");
for (i=0;i<6;i++){
	gotoxy(4,8+i);
       if (i==0 || i==5){
       	for (int j=0;j<28;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                          %c",219,219);
		   }	
	printf("\n");
}
for (i=0;i<6;i++){
	gotoxy(4,15+i);
       if (i==0 || i==5){
       	for (int j=0;j<28;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                          %c",219,219);
		   }	
	printf("\n");
}
for (i=0;i<6;i++){
	gotoxy(4,22+i);
       if (i==0 || i==5){
       	for (int j=0;j<28;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                          %c",219,219);
		   }	
	printf("\n");
}
 }
 int movimento(){
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
for (i=0;i<6;i++){

	gotoxy(4,1+i+v);
       if (i==0 || i==5){
       	for (int j=0;j<28;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                          %c",219,219);
		   }	
	printf("\n");
}
 
	
 	
 }
 int retardado(){
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);	
 for (i=0;i<6;i++){

	gotoxy(4,1+i+v);
       if (i==0 || i==5){
       	for (int j=0;j<28;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                          %c",219,219);
		   }	
	printf("\n");
}	
 }
   int movendo(){
   	char c;
   	  while(c!=13){
   	  	c=getch();
   	  	if (c==80){
   	  		retardado();
   	  		v=v+7;
   	  		movimento();
			 }else if (c==72){
			 	retardado();
			 	v=v-7;
			 	movimento();
			 	
			 }
   	  	
		 }
   	
   }
 
 int main(){
 	
 	quadrado();
 	//getch();
 	movimento();
 movendo();
 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
 	getch();
 }
 
 
