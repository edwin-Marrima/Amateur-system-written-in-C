#include<windows.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
int i,j,y;

void caixinha_2();
void text_cliente();
void degi();
void moviing();
void gotoxy (int coluna, int linha){
	COORD point;
	point.X = coluna; point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

int layout_cliente(){
	
	
	
	system("COLOR F0");	
	
	
	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x33); 
             for (i=0;i<4;i++){
             gotoxy(19,2+i);
			 printf("                                                                                    ");	
			 }gotoxy(19,19);
			  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF3); 
		
			 
         
}
void risco(){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x33);
	gotoxy(19,5);
	 printf("                                                                                    ");
}
void words_cliente(){
	begin:
		system("cls");
		 layout_cliente();
	  	
	char c='\0';
	int y=0;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x37);
	gotoxy(22,4);
	
	printf("P E N D E N T E ");
	gotoxy(43,4);
	printf("M O V I M E N T A C A O");
	gotoxy(72,4);
	printf("L I S T A R");
	gotoxy(89,4);
	printf("A L E R T A");
	  while(c!=13){
	  	c=getch();
	  	if (c==77){
	  		y=y+1;
		  }
		  else if (c==75){
		  	y=y-1;
		  }
		  if (y==1){
		  	risco();
		  gotoxy(22,4);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x3F);
	printf("P E N D E N T E ");
		 gotoxy(22,5);
	printf("_______________");
	gotoxy(43,4);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x37);
	printf("M O V I M E N T A C A O");
	gotoxy(72,4);
	printf("L I S T A R");
	gotoxy(89,4);
	printf("A L E R T A");
		
		  }else if (y==2){
		  	
		  	risco();
		  gotoxy(22,4);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x37);
	printf("P E N D E N T E ");
	gotoxy(43,4);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x3F);
	printf("M O V I M E N T A C A O");
	gotoxy(43,5);
	printf("_______________________");
	gotoxy(72,4);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x37);
	printf("L I S T A R");
	gotoxy(89,4);
	printf("A L E R T A");
  	
		  }else if(y==3){
		  	risco();
		  gotoxy(22,4);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x37);
	printf("P E N D E N T E ");
	gotoxy(43,4);
	
	printf("M O V I M E N T A C A O");
	gotoxy(72,4);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x3F);
	printf("L I S T A R");
  	gotoxy(72,5);
  	printf("___________");
  	gotoxy(89,4);
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x37);
	printf("A L E R T A");
		  }else if (y==4){
		  	risco();
		  gotoxy(22,4);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x37);
	printf("P E N D E N T E ");
	gotoxy(43,4);
	
	printf("M O V I M E N T A C A O");
	gotoxy(72,4);

	printf("L I S T A R");
  	gotoxy(89,4);
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x3F);
	printf("A L E R T A");		  	
    gotoxy(89,5);
  	printf("___________");
		  }if (y==5){
		  	y=1;
		  }else if (y==0){
		  	y=3;
		  }
	  	
	  }
	  if (y==1){
	  	//pendente....
	  degi();text_cliente();caixinha_2();moviing();
	  goto begin;	
	  }else if (y==2){
	  	degi();text_cliente();caixinha_2();moviing();
	  goto begin;
	  	//movmentacao...
	  }else if (y==3){
	  	degi();text_cliente();caixinha_2();moviing();
	  	goto begin;
		  //lstar
	  }else if (y==4){
	  	degi();text_cliente();caixinha_2();moviing();
	 goto begin;
	  	//alerta..
	  }
	  
	
}
 void degi(){
 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
    for (i=0;i<18;i++){
    	gotoxy(32,8+i);
    	printf("                                                                           ");
	}
	 	
 }
 void text_cliente(){
 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(34,9);
	printf("  M A R C A:                      ");
	gotoxy(34,11);
	printf("  M O D E L O:                    ");
	gotoxy(34,13);
	printf("  M A T R I C U L A:              ");
	gotoxy(34,15);
	printf("  Q U I L O M E T R A G:          ");
	gotoxy(34,17);
	printf("  E S T  D E  A Q S:              ");
	gotoxy(34,19);
	printf("  E S T   D E  D E V:             ");
	
	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
	gotoxy(34,23);
	printf("  P R E C O  P A G O:             ");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(71,9);
	printf("  E N D E R E C O:                ");
	gotoxy(71,11);
	printf("  I D A D E:                      ");
	gotoxy(71,13);
	printf("  T E L E F O N E:                ");
	gotoxy(71,15);
	printf("  T E L E F O N E:                ");
	gotoxy(71,17);
	printf("  N R  I D E N T:                 ");
	gotoxy(71,19);
	printf("  D E S T/D I S T:                ");
	gotoxy(71,21);
	printf("  D A T A  D E  A Q S:            ");
	gotoxy(71,23);
	printf("  D A T A  D E  D E V:            ");
 }
void caixinha(){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
	for (i=0;i<16;i++){
		gotoxy(4,9+i);
		printf("                       ");
	}
	
	
}
void caixinha_2(){
caixinha();
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
	for (i=0;i<14;i++){
		gotoxy(5,10+i);
		printf("                     ");
	}

}
  void barra_retardada(){
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
  	gotoxy(5,10+y);
  	printf("                     ");
  	gotoxy(5,12+y);
  	printf("                     ");
  	gotoxy(5,11+y);
  	printf(" ");
  	gotoxy(25,11+y);
  	printf(" ");
  }
  void moving_barra(){
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
  	gotoxy(5,10+y);
  	printf("                     ");
  	gotoxy(5,12+y);
  	printf("                     ");
  	gotoxy(5,11+y);
  	printf(" ");
  	gotoxy(25,11+y);
  	printf(" ");
  }
  void moviing(){
  	char c='\0';
  	while(c!=13){
  		c=getch();
  		if (c==80){
  			barra_retardada();
  			y=y+2;
  			moving_barra();
		  }else if (c==72){
		  	barra_retardada();
		  	y=y-2;
		  	moving_barra();
		  	
		  }
		  
	  }
  }
int main(){
	
words_cliente();

//degi();text_cliente();caixinha_2();moviing();
//text_cliente();	

//moving_barra();
//words_cliente();
getch();
}
