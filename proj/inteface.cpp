#include<windows.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int i,j,x=0;
void gotoxy (int coluna, int linha){
	COORD point;
	point.X = coluna; point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
int layout(){
	  
	system("COLOR F0");	
	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00); 
	 for (i=0;i<11;i++){
	 	gotoxy(26,2+i);
	 	for (j=0;j<62;j++){
	 		printf("%c",219);
		 }
		 printf("\n");
	 }
	  for (i=0;i<11;i++){
	 	gotoxy(28,3+i);
	 	for (j=0;j<62;j++){
	 		printf("%c",219);
		 }
		 printf("\n");
	 }
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	for (i=0;i<9;i++){
		gotoxy(14+20,3+i);
		if (i==0 || i==4 || i==8){
			printf(" ");
			for (j=0;j<9;j++){
					printf("%c",219);
			}
		}else if (i<4){
			printf("%c",219);
			
		}else {
			printf("          %c",219);
		}
		
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
	for (i=0;i<9;i++){
gotoxy(52+i+20,3+i);
     printf("%c",219);
}

	for (i=0;i<9;i++){
	gotoxy(52-i+20,3+i);
		if (i!=5){

     printf("%c",219);
}else {
	for (j=1;j<12;j++){
		printf("%c",219);
	}
}
	 
	 }
	    for (i=0;i<9;i++){
gotoxy(29+20,3+i);
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
      if (i==0){
      	printf("  ");
      	   for (j=0;j<8;j++){
      	   	printf("%c",219);
			 }
	  }else if(i==1){
	  	printf(" %c",219);
	  	
	  }	else if (i==5){
	  printf("%c    %c%c%c%c%c%c",219,219,219,219,219,219,219);
	  
	  }else if(i>4 && i<7){
	  	
	  	printf("%c          %c",219,219);
	  	
	  	
	  }else if (i>1 && i<7) {
   	printf("%c",219);
	  	
	  } else if (i==7){
	  	printf(" %c        %c",219,219);
	  }
	  else if (i==8){
	  	printf("  ");
      	   for (j=0;j<8;j++){
      	   	printf("%c",219);
			 }
	  }
	  
	  
	     	
		}
		
		gotoxy(22,15);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFA);
		printf("S I S T E M A  D E  G E S T A O  D E  A L U G U E L  D E  V I A T U R A S");

         
}

void lay_out_de_login(){
	system("COLOR F0");	
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);		
	for (i=0;i<16;i++){
	
	gotoxy(38,6+i);
       if (i==0 || i==15){
       	for (int j=0;j<38;j++){
       		printf(" ");
		}
	   }else if (i==1){
		   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		   	for (int j=0;j<38;j++){
			   
       		printf(" ");}
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);   
		   }else
	   {
	   	printf("                                      ");
		   }
		   	
	printf("\n");
}gotoxy(45,6);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	printf("W E L C O M E  B A C K");
gotoxy(42,12);
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x8F);
printf("USER:");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(47,12);
printf("                       ");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x8F);
gotoxy(42,15);
printf("SENHA:");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(47,15);
printf("                       ");
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
 gotoxy(53,17);
 printf(" LOGIN ");
	
}
   void escrita_do_inicio(){
   	char c;
   	while(c!=13){
 
   		c=getch();
if (c==77){
x=x+1;}else if (c==75){
	x=x-1;
}
  if (x==1){
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
   	gotoxy(22,26);
   	printf("L O G I N");
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
   	gotoxy(42,26);
   	printf("A B O U T");
   	gotoxy(62,26);
    	printf("S U G G E S T I O N");
   	gotoxy(93,26);
   	printf("E X I T"); 

}else if (x==2){
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
   	gotoxy(22,26);
   	printf("L O G I N");
   	gotoxy(42,26);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
   	printf("A B O U T");
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
   	gotoxy(62,26);
   	 	printf("S U G G E S T I O N");
   	gotoxy(93,26);
   	printf("E X I T");

}else if (x==3){
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
   	gotoxy(22,26);
   	printf("L O G I N");
   	gotoxy(42,26);
   	printf("A B O U T");
   	gotoxy(62,26);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
    	printf("S U G G E S T I O N");
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
   		gotoxy(93,26);
   	printf("E X I T");
}
else if (x==4){
	  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
   	gotoxy(22,26);
   	printf("L O G I N");
   	gotoxy(42,26);
   	printf("A B O U T");
   	gotoxy(62,26);
   	printf("S U G G E S T I O N");
   		gotoxy(93,26);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
   	printf("E X I T");
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
}else if (x<0 || x>4){
	if(x<0){
		x=4;
	}else if (x>4){
		x=0;
	}
	
}

   }
   printf("%d",x);
   if (x==1){
   	system("cls");
   	lay_out_de_login();
   	
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   }
   }
    void imformacao_do_sistem(){

    	
	}



int main(){
//layout();
escrita_do_inicio();
//login_about();
//lay_out_de_login();
///escrita_do_inicio();
getch();	
}
