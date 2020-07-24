#include<windows.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int i,x,y;
 void menu_de_viaturas();
 
void gotoxy (int coluna, int linha){
	COORD point;
	point.X = coluna; point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void organizacao_de_menu_principal(){
	system("color F0");

	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
for (i=0;i<24;i++){
	
	gotoxy(11,3+i);
       if (i==0 || i==23){
       	for (int j=0;j<51;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                                                 %c",219,219);
		   }	
	printf("\n");
}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xCC); 
	for (i=0;i<24;i++){
	
	gotoxy(9,2+i);
       if (i==0 || i==23){
       	for (int j=0;j<51;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                                                 %c",219,219);
		   }	
	printf("\n");
}

	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00); 
    for (i=0;i<89;i++){
    	gotoxy(12+i,28);
    	printf("       ");
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF); 
   for (i=0;i<6;i++){
	
	gotoxy(14,4+i);
       if (i==0 || i==5){
       	for (int j=0;j<20;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                  %c",219,219);
		   }	
	printf("\n");
}   for (i=0;i<6;i++){
	
	gotoxy(35,4+i);
       if (i==0 || i==5){
       	for (int j=0;j<20;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                  %c",219,219);
		   }	
	printf("\n");
}
for (i=0;i<6;i++){
	
	gotoxy(35,11+i);
       if (i==0 || i==5){
       	for (int j=0;j<20;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                  %c",219,219);
		   }	
	printf("\n");
}
 for (i=0;i<6;i++){
	
	gotoxy(14,11+i);
       if (i==0 || i==5){
       	for (int j=0;j<20;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                  %c",219,219);
		   }	
	printf("\n");
} for (i=0;i<6;i++){
	
	gotoxy(35,18+i);
       if (i==0 || i==5){
       	for (int j=0;j<20;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                  %c",219,219);
		   }	
	printf("\n");
}
 for (i=0;i<6;i++){
	
	gotoxy(14,18+i);
       if (i==0 || i==5){
       	for (int j=0;j<20;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                  %c",219,219);
		   }	
	printf("\n");
}	
}
void cobertura(){
	 		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
	  for (i=0;i<6;i++){
	
	gotoxy(14+x,4+i+y);
       if (i==0 || i==5){
       	for (int j=0;j<20;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                  %c",219,219);
		   }	
	printf("\n");
} 
}
   void movel(){
  	
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFE);
	  for (i=0;i<6;i++){
	
	gotoxy(14+x,4+i+y);
       if (i==0 || i==5){
       	for (int j=0;j<20;j++){
       		printf("%c",219);
		   }
	   }else
	   {
	   	printf("%c                  %c",219,219);
		   }	
	printf("\n");
} 	
   }
     void letras(){
   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	gotoxy(18,7);
   	printf("P A R Q U E");
   	gotoxy(37,7);
   	printf("U S U A R I O S");
   	gotoxy(17,14);
   	printf("C L I E N T E S");
   	gotoxy(38,14);
   	printf("+  M A I S");
   	gotoxy(40,21);
   	printf("S A I R");
   	gotoxy(16,21);
   	printf("R E L A T O R I O");
   }
   void menu_principal(){
   	char c;
   	x=0;
   	y=0;
   	organizacao_de_menu_principal();movel();	letras();
   	while(c!=13){
   		c=getch();
   		if (c==80){
   			cobertura();
   			y=y+7;
   			movel();
   			letras();
		   }else if(c==72){
		   	cobertura();
		   	y=y-7;
		   	movel();
		   		letras();
		   }else if (c==77){
		   	cobertura();
		   	x=x+21;
		   	movel();
		   		letras();
		   }else if (c==75){
		   	cobertura();
		   	x=x-21;
		   	movel();
		   		letras();
		   }
	   }
	   //printf("  %d       %d",x,y);
	 if (x==0 && y==0){
	 	system("cls");
 menu_de_viaturas();
	 	//menu de viaturas.
	 }
   	
   }
 void viatura_layout(){
 	
 		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
 		    for (i=0;i<30;i++){
 		    	gotoxy(0,0+i);
 		    	 if (i<3){
printf("                                                                                                                         ");
				  }else{
				  
 		    	
 		    		printf("                                    ");
			}
			 }
			 	
			 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
				for (i=0;i<22;i++){
   		gotoxy(42,6+i);
   		printf("                                   ");
	   }	 
				 
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		gotoxy(80,1);
		printf("F I N D  A  S E T T I N G S     ");	
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
		gotoxy(10,28);
		printf("+ M A I S +");		 
				 
			
 }
   void estampa(){
   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xAA);
   	for (i=0;i<22;i++){
   		gotoxy(41,5+i);
   		printf("                                   ");
	   }
	     
   }  
   void barra_retardada(){
   	 	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
			 	gotoxy(0+x,3+y);
			 	printf("                                    ");
			 	gotoxy(0+x,4+y);
			 		printf("                                    ");
			 			gotoxy(0+x,5+y);
			 		printf("                                    ");
   }
   void barra(){
   	 	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x33);
			 	gotoxy(0+x,3+y);
			 	printf("                                    ");
			 	gotoxy(0+x,4+y);
			 		printf("                                    ");
			 			gotoxy(0+x,5+y);
			 		printf("                                    ");
   }
    void menu_de_viaturas(){
    	char c;
    	viatura_layout();
    	estampa();
    	barra();
    	while(c!=13){
    		c=getch();
    		if (c==80){
    			barra_retardada();
    			estampa();
    			y=y+3;
    			barra();
			}else if(c==72){
				barra_retardada();
				estampa();
				y=y-3;
				barra();
			} 
		}
	}

int main(){

	system("color F0");
	menu_principal();
	//movendo_barra();
	//viatura_layout();estampa(); barra();
	//organizacao_de_menu_principal();movel();movendo();
	getch();
}
