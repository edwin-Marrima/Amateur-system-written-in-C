#include<windows.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

struct agenda{
	char actividade[50];
	int dia;
	int ano;
	int mes;
};
struct usuarios{
	char nome[20];
	char user_name[20];
	int codigo;
	int confiabilidade;
	char estado[20];
};

struct viatura{
	char marca[15];
	char modelo[15];
	char matricula[20];
	char categoria[10];
	int lotacao;
	int preco_aquisicao;
	char estado[10];
	char situacao[50];
	int preco_aluguel;
	
	
};
struct cliente{
	char marca[10];
	char modelo[10];
	char matricula[10];
	char nome[50];
	char endereco[50];
	int idade;
	int telefone;
	int telefone2;
    int documento;
    int dia_entrega;
    int mes_entrega;
    int hora_entrega;
    int ano_entrega;
    int dia_leva;
    int ano_leva;
    int hora_leva;
    int mes_leva;
	char estado_leva[20];
	char estado_entrega[20];
	int preco_pago;
	char destino[20];
	int distancia;
	
}temp2;
char datestr[10],activo[20];
char timestr[10];
char vett[4];
int dia;
int mes;
int ano;
int hora;
int minuto;
int tam_agenda;//numero de actividades que estao na agenda..
int i,v,numero_de_usuarios,confiabilidade=0;
int tamanho;// pARA delimitaro tamanho do meu vector de objectosapartirdo arquivo...
int tamanho_2,j,x,y;// tira o tamanho dosdados que estaono arquivo de apagados..
int tamanho_de_vector_cliente;
//objectivo de guardar o numero de clientes apos os mesmes serem lidos no arquivo..
FILE *p;
FILE *aux_recuperar;//ponteiro de arquivo para dados perdidos ou apagados.....
FILE *arq;//arquivo para estrutura relacionadacom funcionarios da empresa
FILE *arq1;
FILE *agn;

void gotoxy (int coluna, int linha){
	COORD point;
	point.X = coluna; point.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void caixinha_2();
void text_cliente();
void degi();
void moviing(cliente *clin, viatura *obj,int k);
void gravacao_de_arquivo_viatura( viatura *obj );// tem como funcao gravar dados no arquivo referente a viaturas... 
void leitura_de_arquivo_viatura ( viatura *obj);//conta  o numero de dados que no arquivo-para alem de passar os dadospara forma logica..
void cadastrar_viatura(viatura *obj);     //processo de cadastro de viaturas...
void gravar_dados_apagados_da_estrutura_viatura(int p,viatura *obj);//tem como funcao gravar dados que serao apagados no metodo "apagar_viatura", para a posterior conseguir recuperar..
void apagar_viatura(int c,viatura *obj);
void adicionar_nova_viatura(viatura *obj);//funcao para adicionar nova viatura....
void recuperar_viatura_apagada();
void codificacao_de_usuario(usuarios *vet);
void menu_de_viaturas(viatura *obj, cliente *clin);
void visualizar_viaturas(viatura *obj);
void cadastrar_cliente(cliente *clin, viatura *obj, int i);
void visualizar_cliente_pendente(cliente *clin, viatura *obj);
 void visualizar_client_grafic(cliente *clin, viatura *obj, int b);
 //void menu_de_viaturas();
 void visualizar_cliente_movendo(cliente *clin, viatura *obj);
 void opcoes_para_cliente_pendente(cliente *clin, viatura *obj, int k);
void visualizar_viatura_graph(viatura *obj, int k); 
void opcoes_para_cliente_movimentacao(cliente *clin, viatura *obj, int k);
int escrita(); 
void visualizar_todos_clientes(cliente *clin, viatura *obj);
 void opcoes_para_listar(cliente *clin, viatura *obj, int k);
 void visualizar_cliente_em_alerta(cliente *clin, viatura *obj);
 void ler_usuarios(struct usuarios *vet);
 void moviiing(usuarios *vet, int k);
 void apagar_usuario(struct usuarios *vet, int k);
 int manipulacao_sim_nao();
 void regravar_usuarios(struct usuarios *vet);
 void para_agenda();
 void blecao();
 void xxxt();
  void leitura_de_arquivo_de_apagados(viatura *obj2);
  void recuperar_viatura_apagada(viatura *obj2, int h);
  void sensatio();
  void leitura_de_arquivo_agenda(struct agenda *agen);
void regravar_agenda(struct agenda *agen);
  
 int validacao_para_codico(){
//char *stringg=NULL;
char digitos[50];
char  teste;
int i=0,soma;
for (i=0;i<50;i++){
	digitos[i]='\0';
}	
i=0;
	do{
	
	
	//scanf("%c",&teste);
	teste=getch();
	   if (isdigit(teste)!=0 || teste==32){
	   //	teste=toupper(teste);
	   	digitos[i]=teste;
	   	digitos[i]=toupper(digitos[i]);
	   	printf("*");
		   i+=1;
	   	
	   }
	   else if (teste==8 && i!=0){
	   	digitos[i]='\0';
	   	printf("\b\b");
	   	i--;
	   	//printf("\b");
	   }
}while(teste!=13);
	//stringg=digitos;
	//i=0;
	i=atoi(digitos);
	return(i); 	
 }
 
 
int validacao_inteiro(){
//char *stringg=NULL;
char digitos[50];
char  teste;
int i=0,soma;
for (i=0;i<50;i++){
	digitos[i]='\0';
}	
i=0;
	do{
	
	
	//scanf("%c",&teste);
	teste=getch();
	   if (isdigit(teste)!=0 || teste==32){
	   //	teste=toupper(teste);
	   	digitos[i]=teste;
	   	digitos[i]=toupper(digitos[i]);
	   	printf("%c",digitos[i]);
		   i+=1;
	   	
	   }
	   else if (teste==8 && i!=0){
	   	digitos[i]='\0';
	   	printf("\b\b");
	   	i--;
	   	//printf("\b");
	   }
}while(teste!=13);
	//stringg=digitos;
	//i=0;
	i=atoi(digitos);
	return(i);
}
 
 


char *validacao_string(){
char *stringg=NULL;
char digitos[50];
char  teste;
int i=0,soma;
for (i=0;i<20;i++){
	digitos[i]='\0';
}	
i=0;
	do{
	
	
	//scanf("%c",&teste);
	teste=getch();
	   if (isalpha(teste)!=0 || teste==32){
	   //	teste=toupper(teste);
	   	digitos[i]=teste;
	   	digitos[i]=toupper(digitos[i]);
	   	printf("%c",digitos[i]);
		   i+=1;
	   	
	   }
	   else if (teste==8 && i!=0){
	   	digitos[i]='\0';
	   	printf("\b\b");
	   	i--;
	   	//printf("\b");
	   }
}while(teste!=13);
	stringg=digitos;
	i=0;
}

 
 void data_dia(){
 	_strdate(datestr);
 	 _strtime(timestr);
		vett[0]=datestr[0];
		vett[1]=datestr[1];
		mes=atoi(vett);
		
		vett[0]=datestr[3];
		vett[1]=datestr[4];
		dia=atoi(vett);
		

		vett[0]=datestr[6];
		vett[1]=datestr[7];
		ano=atoi(vett);
	//	printf("dia=%d        mes=%d    ano=%d",dia,mes,ano);
		
		
		vett[0]=timestr[0];
		vett[1]=timestr[1];
		hora=atoi(vett);


		vett[0]=timestr[3];
		vett[1]=timestr[4];
		minuto=atoi(vett);     
             
   //printf("hora=%d               minuto=%d",hora,minuto);
	
}

  void testo(){
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
  	gotoxy(13,12);
  	printf(" M A R C A :");
  	gotoxy(13,14);
  	printf(" M O D E L O:");
  	gotoxy(13,16);
  	printf(" M A T R I C U L A:");
  	gotoxy(13,18);
  	printf(" E S T A D O:");
  	
	gotoxy(33,12);
	printf("            ");
	gotoxy(33,14);
	printf("            ");
  	gotoxy(33,16);
	printf("            ");
	gotoxy(33,18);
	printf("            ");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x7C);
	gotoxy(31,12);
	printf("<-");
	gotoxy(45,12);
	printf("->");
  }
  void ver_viaturas_apagadas(viatura *obj2,int i){
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	  gotoxy(35,12);
  	printf("%s",obj2[i].marca);
  	gotoxy(35,14);
  	printf("%s",obj2[i].modelo);
  	gotoxy(35,16);
  	printf("%s",obj2[i].matricula);
  	gotoxy(35,18);
  	printf("%s",obj2[i].estado);
  }
   void barrra(){
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x55);
 for (i=0;i<3;i++){
 	gotoxy(12,23+i);
	 printf("                ");
 }
  for (i=0;i<3;i++){
 	gotoxy(29,23+i);
	 printf("                ");
 }
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x5F);
 gotoxy(13,24);
 printf("P A Q U E A R");
 gotoxy(30,24);
 printf("V O L T A R");
  }
  void barra_junior(int x,int y){
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
 for (i=0;i<3;i++){
 	gotoxy(12+x,23+i+y);
	 printf("                ");
 }
 
  	
  }
 int confirm(){
 	barrra();
 	
 	int x=0;
 	int y=0;
 	//barra_junior(x,y);
 	char c='\0';
 	while (c!=13){
 		c=getch();
 		   if (c==77){
 		   	x=x+17;
			}else if(c==75){
				x=x-17;
			} if (x==0){
			barrra();
			barra_junior(x,y);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
 gotoxy(13,24);
 printf("P A R Q U E A R");	
			}else if(x==17){
				
			barrra();
			barra_junior(x,y);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
			gotoxy(30,24);
 printf("V O L T A R");
			}
			
	 }
	 return(x);
 } 
 
  
  void para_viatura(viatura *obj){
  	begin:
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
  		leitura_de_arquivo_de_apagados( obj);
bool est=false;
  	char c='\0';
  	int x=0;
  	int bb=4;
  	system("COLOR F0");
  	system("cls");
  	xxxt();
  	blecao();
  	testo();
  	 	
  	while (c!=13){
  		c=getch();
  		 if (c==77){
  		 	x=x+1;
  		 	testo();
  		 	ver_viaturas_apagadas(obj,x);
		   }else if (c==75){
		   	x=x-1;
		   	testo();
		   	ver_viaturas_apagadas(obj,x);
		   }if (x<0){
		   	x=tamanho_2-1;
		   	testo();
		   	ver_viaturas_apagadas(obj,x);
		   }else if (x==tamanho_2){
		   	x=0;
		   	testo();
		   	ver_viaturas_apagadas(obj,x);
		   }if (c==32){
		   	c=13;
		   	est=true;
		   }
		gotoxy(1,1);
//		printf("====%d==%d",tamanho_2,x);  
	  }
	int ui=x;
	  if (est==true){
	   //	bb=22;
	   	
	  }else {
	  
	    bb=confirm();
	  if  (bb==0){
	 //codico de recuperar viatura...
	recuperar_viatura_apagada(obj,ui);  
	system("cls");
	  	goto begin;	
	  }else if (bb==17){
	  	system("cls");
	  	goto begin;
	  }
  }
  }


void xxxt(){
		 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x11);
	for(i=0;i<4;i++){
		gotoxy(45,0+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(54,0+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(63,0+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(72,0+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(81,0+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(90,0+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(99,0+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(108,0+i);
		printf("        ");
	//	printf("\n");
	}
	
	//linha  2
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xDD);
	for(i=0;i<4;i++){
		gotoxy(54,5+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(63,5+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(72,5+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(81,5+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(90,5+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(99,5+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(108,5+i);
		printf("        ");
	//	printf("\n");
	}
	
	//linha  3
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xCC);
	for(i=0;i<4;i++){
		gotoxy(63,10+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(72,10+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(81,10+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(90,10+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(99,10+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(108,10+i);
		printf("        ");
	//	printf("\n");
	}
	
	//linha 4
	
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xEE);
	for(i=0;i<4;i++){
		gotoxy(72,15+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(81,15+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(90,15+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(99,15+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(108,15+i);
		printf("        ");
	//	printf("\n");
	}
	
	
	//linha 5
	
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x33);
	for(i=0;i<4;i++){
		gotoxy(81,20+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(90,20+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(99,20+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(108,20+i);
		printf("        ");
	//	printf("\n");
	}
	
	//linha 6
	
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
	for(i=0;i<4;i++){
		gotoxy(90,25+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(99,25+i);
		printf("        ");
	//	printf("\n");
	}
	for(i=0;i<4;i++){
		gotoxy(108,25+i);
		printf("        ");
	//	printf("\n");
	}
	
	
	
	
	
//getch();	
}
void lite(){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x55);
	for (i=0;i<4;i++){
		gotoxy(12,11+i);
		printf("                ");
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x22);
	for (i=0;i<4;i++){
		gotoxy(29,11+i);
		printf("                ");
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
		for (i=0;i<4;i++){
		gotoxy(29,16+i);
		printf("                ");
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x33);
		for (i=0;i<4;i++){
		gotoxy(12,16+i);
		printf("                ");
	}
		
	
}
void actioo(int x, int y){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xCC);
		for (i=0;i<4;i++){
		gotoxy(12+x,11+i+y);
		printf("                ");
	}
	
}
void caracteris(){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x50);
	gotoxy(14,13);
	printf("R E M V D");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x20);
	gotoxy(33,13);
	printf("I N F O");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
	gotoxy(33,18);
	printf("E X I T");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x30);
	gotoxy(14,18);
	printf("A G E N D A");
}

void blecao(){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
		for (i=0;i<13;i++){
		gotoxy(9,9+i);
		printf("                                       ");
	}
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x77);
	for (i=0;i<11;i++){
		gotoxy(10,10+i);
		printf("                                     ");
	}
}
void pontos(int y){
  	
  		gotoxy(1,10+y);
  		printf("         ");
  	  
  }
  void actividade_caixa(){
   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x33);
   for (i=0;i<9;i++){
   	gotoxy(13,10+i*2);
   	printf("                                            ");
   }
   }

  void agenda_layout(){
  	
	  system("cls");
  	system("COLOR F0");
	  xxxt();
  	
  	int io=0;
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
         for (i=0;i<3;i++){
         	gotoxy(9,6+i);
         	printf("                                          ");
		 }
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		 	gotoxy(11,7);
	
		 	printf(" B L O C O  D E  A C T I V I D A D E S");
		 		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
   	     for (i=0;i<18;i++){
         	gotoxy(11,10+i);
         	printf("                                                ");
		 }
  	 actividade_caixa();
	  getch();
  	
  }
  void ver_agenda(agenda *agen){
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x30);
  	leitura_de_arquivo_agenda(agen);
  	  for (i=0;i<tam_agenda;i++){
  	  	gotoxy(15,10+i*2);
  	  	printf("%s",agen[i].actividade);
		}
  } 
   
void andador(agenda *agen,int k){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	gotoxy(2,10+k*2);
	printf("%d/%d/%d",agen[k].dia,agen[k].mes,agen[k].ano);
}

void gravarr(agenda *agen,int k){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x33);
	gotoxy(13,10+k*2);
   	printf("                                            ");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x30);
	agn=fopen("agend.txt","a+");
    gotoxy(15,10+k*2);
    	setbuf(stdin,NULL);
    gets(agen[k].actividade);
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
    gotoxy(2,10+k*2);
    printf("dd/mm/aa");
    gotoxy(2,10+k*2);
    scanf("%d",&agen[k].dia);
    gotoxy(5,10+k*2);
	scanf("%d",&agen[k].mes);
	gotoxy(8,10+k*2);
	scanf("%d",&agen[k].ano);
	fprintf(agn,"%s\t%d\t%d\t%d\n",agen[k].actividade,agen[k].ano,agen[k].dia,agen[k].mes);
	fclose(agn);	
}

   void novie(agenda *agen){
 begin:
 	bool est=false;
   	agenda_layout();
   	ver_agenda(agen);
leitura_de_arquivo_agenda(agen);
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x30);


//void regravar_agenda(struct agenda *agen);	
   	char c='\0';
   	int y=0;
   	while(c!=13){
   		c=getch();
   		if (c==80){
   			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
   			pontos(y);
   			y=y+2;
   			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
   			pontos(y);
   			andador(agen,y/2);
		   }else if (c==72){
		   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
   			pontos(y);
		   	y=y-2;
		   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
   			pontos(y);
   			andador(agen,y/2);
		   }if (c==32){
		   	est=true;
		   	c=13;
		   }
   		
	   }
	   if (est==true){
	   
	  
}else {
	 gravarr(agen,y/2);
	 goto begin;
}
   }
  

  void moveri(viatura *obj,cliente *clin, usuarios *vet,agenda *agen){
begin:

bool est=false;	
blecao();
xxxt();	
lite();
  	
  	caracteris();
  	char c='\0';
  	int x=0;
  	int y=0;
  	while(c!=13){
  		c=getch();
  		if (c==32){
		  	c=13;
		  	est=true;
		  }
  		 if (c==80){
  		 	y=y+5;
		   }else if (c==72){
		   	y=y-5;
		   }else if (c==77){
		   	x=x+17;
		   }else if (c==75){
		   	x=x-17;
		   }
  		if (y==0 && x==0){
  			lite();
  			actioo(x, y);
  			caracteris();
  			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
	gotoxy(14,13);
	printf("R E M V D");
	
		  }else if (y==0 && x==17){
		  lite();
		  	actioo(x, y);
  			caracteris();
  			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
	gotoxy(33,13);
	printf("I N F O");
	
  			
		  }else if (y==5 && x==0){
		  	lite();
			  actioo(x, y);
  			caracteris();
  			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
	gotoxy(14,18);
	printf("A G E N D A");
		  }else if (y==5 && x==17){
		  lite();
		  	actioo(x, y);
  			caracteris();
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
	gotoxy(33,18);
	printf("E X I T");
			
  			
		  }
	  }
	  if (est==true){
	  	
	  }
  	else if  (y==0 && x==0){
  		para_viatura(obj);
  	goto begin;	
	  }else if (y==0 && x==17){
	  	//para info....
	  	system("cls");
	  	system("COLOR 0F");
	  	sensatio();
	  	getch();
	  	system("COLOR F0");
	  	goto begin;
	  }else if (x==0 && y==5){
	  
	  novie(agen);
	  system("cls");
	  system("COLOR F0");
	  	goto begin;
	  //para agenda.....	
	  }
  	
  }
  
  void para_agenda(){
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
  	for(i=0;i<3;i++){
  		gotoxy(7,27+i);
  		printf("                                                              ");
	  }
	  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	  gotoxy(10,28);
	  printf(" E S C R E V E R : ");
  }


void macrate(){
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
     
     for (i=0;i<18;i++){
     gotoxy(29,6+i);
	 printf("                                                                 ");	
     	
     	
     	
	 }

SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
}
  void sensatio(){
  	int ioi=48;
  	int a=1,b=1,c=1,d=1,e=1,f=1,g=0,h=0,k=0,m=0,n=0,o=0,A=0,B=0,C=0,D=0,E=0,F=0;
  	macrate();
	  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
  for (j=0;j<ioi;j++){
  	
	  //system("COLOR 0F");
  	macrate();
  	if (j>-1 && j<=17){ 
	  gotoxy(50,23-j);
	  	  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
  	printf("P  R  O  D  U  C  A  O:");
	    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);}
  	   if (j>2 && j<=19){
  	   
  	   	gotoxy(43,23-a);
  	   	printf("E D W I N  F E R N A N D O  M A R R I M A");
  	   	a++;
		 }if (j>3 && j<=20){
		 	gotoxy(37,23-b);
		 	printf(" H E L E N A  M A N D L A T E / D E L S O  J O A O");
		 	b++;
		 }if (j>4 && j<=21){
		 	gotoxy(45,23-c);
		 	printf("J A C I N T O / J O A O  S A N T O S");
		 	c++;
		 }if (j>5 && j<=22){
		 	gotoxy(51,23-d);
		 	printf(" J A I M E  M A T I N E");
		 	d++;
		 }
		 if (j>9 && j<=26){
		 	gotoxy(40,23-e);
		 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		 	printf("A  M  B  I  T  O   D E   P  R  O  D  U  C  A  O:");
		 	e++;
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		 }if  (j>11 && j<=28){
		 	gotoxy(45,23-f);
		 	printf("P  R  O  G  R  A  M  A  C  A  O  'C'");
		 	f++;
		 } if (j>12 && j<=30){
		 	gotoxy(39,23-g);
		 	printf(" F  I  N  S   A  V  A  L  I  A  T  I  V  O  S");
		 	g++;
		 }if (j>15 && j<=33){
		 	gotoxy(51,23-h);
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		 	printf(" V E R S A O:");
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		 	gotoxy(70,23-h);
		 	printf("V1.233");
			 h++;
		 }if (j>16 && j<=34){
		 	gotoxy(51,23-k);
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		 	printf(" M E M O R Y :");
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		 	gotoxy(70,23-k);
		 	printf("167.5 KB");
			 k++;	
		 }if (j>17 && j<=35){
		 	gotoxy(51,23-m);
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		 	printf(" S L I M D :");
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		 	gotoxy(70,23-m);
		 	printf("I M P E R A D O R");
			 m++;	
		 }if (j>18 && j<=36){
		 	gotoxy(51,23-n);
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		 	printf(" A C T U A L Z C :");
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			gotoxy(70,23-n);
		 	printf("19.11.2017");
			 n++;
		 }if (j>19 && j<=37){
		 	gotoxy(46,23-o);
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		 	printf(" E M A I L :");
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF9);
			gotoxy(65,23-o);
		 	printf("edwinmarrima@gmail.com");
			 o++;
		 }if (j>20 && j<=38){
		 	gotoxy(51,23-A);
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		 	printf(" C O N T A C T O :");
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			gotoxy(70,23-A);
		 	printf("84-85-64-695");
			 A++;
		 }if (j>23 && j<=41){
		 	gotoxy(46,23-B);
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
		 	printf(" A G R A D E C I M E N T O S");
		 
			 B++;
		 }if (j>24 && j<=42){
		 		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			gotoxy(38,23-C);
		 	printf("UP- U N I V E R S I D A D E  P E D A G O G I C A");
		 	C++;
		 }if (j>25 && j<=43){
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			gotoxy(38,23-D);
		 	printf("DOCENTE: J A I M E  M A T I N E / J A C I N T O");
		 	D++;
		 }if (j>28 && j<=46){
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
			gotoxy(58,23-E);
		 	printf("2 0 1 7");
		 	E++;
		 }
     sleep(1);
  	
  }	
  }



void designeee(){
	system("COLOR F0");
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x37);
	for (i=0;i<19;i++){
		gotoxy(27,5+i);
	
printf("                                                                 "); 
	
	}

	
}

void quadross(){
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xDD);
for (i=0;i<4;i++){
	gotoxy(6,9+i);
	printf("              ");
}
for (i=0;i<4;i++){
	gotoxy(6,16+i);
	printf("              ");
}
for (i=0;i<4;i++){
	gotoxy(98,16+i);
	printf("              ");
}		
for (i=0;i<4;i++){
	gotoxy(98,9+i);
	printf("              ");
}		
		
}
void wordss(){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xD0);
	gotoxy(7,10);
	printf(" R E M O V E");
	gotoxy(101,10);
	printf(" N E W");
	gotoxy(8,17);
	printf(" E D I T");
	gotoxy(101,17);
	printf("E X I T");
	
}
void estamppp(int xx, int yy){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xDF);
for (i=0;i<6;i++){
	gotoxy(5+xx,8+i+yy);
	if (i==0 || i==5){
	for (j=1;j<17;j++){
		printf("%c",219);
	}}else {
		
	printf("%c              %c",219,219);}
	}		
}
void cenaa(int xx,int yy){
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xD8);
for (i=0;i<6;i++){
	gotoxy(5+xx,8+i+yy);
	if (i==0 || i==5){
	for (j=1;j<17;j++){
		printf("%c",219);
	}}else {
		
	printf("%c              %c",219,219);}
	}
	
}	
   char *estado_ajust(){
   	char *estado=NULL;
	   char c='\0';
	   int y=1;
	   while (c!=13){
	   	c=getch();
	   	 if (c==77){
	   	 	y=y+1;
			}else if (c==75){
				y=y-1;
			}if (y==1){
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
				gotoxy(58,19);
				printf("                         ");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
				gotoxy(62,19);
				printf("A C T I V O");
			}else if (y==2){
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
				gotoxy(58,19);
				printf("                         ");
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
				gotoxy(62,19);
				printf("I N A C T I V O");
			}if (y<0){
				y=2;
			}else if (y>2){
				y=1;
			}
	   } 
	   if (y==1){
	   	char ACTIVO[10];
	   	strcpy(ACTIVO,"ACTIVO");
	   	estado=ACTIVO;
	   }else if (y==2){
	   	char ACTIVOO[10];
	   	strcpy(ACTIVOO,"INACTIVO");
	   	estado=ACTIVOO;
	   }
	   
	     }
 
void letranas(){
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x30);
gotoxy(57,11);
printf("<");
gotoxy(83,11);
printf(">");


gotoxy (38,11);
printf("  N O M E :");	

gotoxy(38,13);
printf("  U S E R_N A M E :");
gotoxy(38,15);
printf("  C O D E :");
gotoxy(38,17);
printf("  C O N F I A B L :");
gotoxy(38,19);
printf("  E S T A D O :");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(58,11);
printf("                         ");
gotoxy(58,13);
printf("                         ");
gotoxy(58,15);
printf("                         ");
 gotoxy(58,17);
printf("                         ");
gotoxy(58,19);
printf("                         "); 
 }
void ver_usuarios(usuarios *vet,int k){
	//k=0;
	if (confiabilidade==100){
	
	gotoxy(62,11);
	printf("%s",vet[k].nome);
	gotoxy(62,13);
	printf("%s",vet[k].user_name);
	gotoxy(62,15);
	printf("%d",vet[k].codigo);
	gotoxy(62,17);
	printf("%d",vet[k].confiabilidade);
	gotoxy(62,19);
	printf("%s",vet[k].estado);}
	else if (strcmp(activo,vet[k].nome)==0 && confiabilidade!=100){
			gotoxy(62,11);
	printf("%s",vet[k].nome);
	gotoxy(62,13);
	printf("%s",vet[k].user_name);
	gotoxy(62,15);
	printf("%d",vet[k].codigo);
	gotoxy(62,17);
	printf("%d",vet[k].confiabilidade);
	gotoxy(62,19);
	printf("%s",vet[k].estado);
	}
	
	
}
void action(usuarios *vet){
	begin:
	ler_usuarios(vet);
//getch();
//	printf("-----%da------",numero_de_usuarios);
	char c='\0';
	//
	int vv=0;
	int m=0;
	designeee();
		letranas();
	while(c!=13){
		c=getch();
		  if (c==75){
		  	m=m-1;
		  		letranas();
		  	//ver_usuarios;
		  	ver_usuarios(vet,m);
		  }else if (c==77){
		  	m=m+1;
		  		letranas();
		  	//ver_usuarios;
		  	ver_usuarios(vet,m);
		  }else if (c==32){
		  	c=13;
		  	vv=4;
		  }if (m<0){
		  	m=numero_de_usuarios;
		  		letranas();
		  	//ver_usuarios;
		  	ver_usuarios(vet,m);
		  	
		  }else if (m>numero_de_usuarios){
		  	m=0;
		  			letranas();
		  	//ver_usuarios;
		  	ver_usuarios(vet,m);
		  
		  }
	}
if(vv==4){
	
}else if (vv==0){

	moviiing(vet,m);
	system("cls");
	goto begin;}
}

 
void moviiing(usuarios *vet, int k){
int	yy=0;
int	 xx=0;
cenaa(xx,yy);
gotoxy(0,0);
int l=0;
	// printf("-------%da------",k);
	//designeee();
	quadross();
	char c='\0';
	//letranas();
	while(c!=13){
		c=getch();
		if (c==80){
			estamppp(xx,yy);
			yy=yy+7;
			cenaa(xx,yy);
			wordss();
		}else if (c==72){
			estamppp(xx,yy);
			yy=yy-7;
			cenaa(xx,yy);
			wordss();
		}else if (c==75){
			estamppp(xx,yy);
			xx=xx-92;
			cenaa(xx,yy);
			wordss();
		}else if (c==77){
			estamppp(xx,yy);
			xx=xx+92;
			cenaa(xx,yy);
			wordss();
		}
		
		
	}
	//printf("===%d====%d==%d====",k,xx,yy);
	//getch();
	if (xx==0 && yy==0){
		//remover
		  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		gotoxy(15,28);
   		printf(" C O N F I R M A R   R E M O C A O :");
		int l=0;
l=manipulacao_sim_nao();
  if (l==0){

		 apagar_usuario(vet,k);
	}else if (l==1){
		
	}
	gotoxy(14,28);
	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                     ");	
	}else if (xx==0 && yy==7){
		//editar
	  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		gotoxy(15,28);
   		printf(" A L T E R A R   U S E R_N A M E :");	
		l=manipulacao_sim_nao();
		if (l==0){
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		gotoxy(58,13);
        printf("                         ");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		gotoxy(62,13);
		strcpy(vet[k].user_name,validacao_string());
		}else if (l==1){
			
		}
			gotoxy(14,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                     ");	
	
		
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		gotoxy(15,28);
   		printf(" A L T E R A R   C O D I C O :");	
		l=manipulacao_sim_nao();
        if (l==0){
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF); 
        gotoxy(58,15);
        printf("                         ");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		gotoxy(62,15);
		vet[k].codigo=validacao_inteiro();
		}	 else if (l==1){
			
		}
			gotoxy(14,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                     ");	
	
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		gotoxy(15,28);
   		printf(" A L T E R A R   G R A U  E X P L O R A T O R I O:");	
		l=manipulacao_sim_nao();
        if (l==0){
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		gotoxy(58,17);
        printf("                         ");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	    gotoxy(62,17);
		vet[k].confiabilidade=validacao_inteiro();
		 
		}else if (l==1){
			
		}
	
	gotoxy(14,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                     ");	
	
	
	
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		gotoxy(15,28);
   		printf(" A L T E R A R   E S T A D O :");	
		l=manipulacao_sim_nao();
        if (l==0){
        	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
        gotoxy(58,19);
printf("                         "); 
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	strcpy(vet[k].estado,estado_ajust());
		}
	gotoxy(14,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                     ");	
	
	
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		gotoxy(15,28);
   		printf(" D E S E J A  G R A V A R  A L T E R A C O E S :?");	
		l=manipulacao_sim_nao();
		if (l==0){
		regravar_usuarios(vet);
		}else if (l==1){
			//nothing..
		}
	gotoxy(14,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                     ");	
		
		
	}else if (xx==92 && yy==0){
		letranas();
		int cc=k;
		k=100;
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		arq=fopen("usuarios.txt","a+");
		gotoxy(62,11);
		strcpy(vet[k].nome,validacao_string());
		gotoxy(62,13);
		strcpy(vet[k].user_name,validacao_string());
		gotoxy(62,15);
		vet[k].codigo=validacao_inteiro();
		gotoxy(62,17);
		vet[k].confiabilidade=validacao_inteiro();
		strcpy(vet[k].estado,estado_ajust());
		
		fprintf(arq,"%s\t%s\t%d\t%d\t%s\n",vet[k].nome,vet[k].user_name,vet[k].codigo,vet[k].confiabilidade,vet[k].estado);
		fclose(arq);
		ler_usuarios(vet);
		k=cc;
		system("cls");
		//goto begin;
	}else if (xx==92 && yy==7){
		//sair
	}
     
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
void words_cliente(cliente *clin, viatura *obj){
	begin:
		int vv=0;
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
		  }else if(c==32){
		  	c=13;
		  	vv=2;
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
	   if (vv==2){
	  	
	  }
	  else if (y==1){
	  	//pendente....
	  degi();text_cliente();caixinha_2();moviing(clin,obj,y);
	  goto begin;	
	  }else if (y==2){
	  	degi();text_cliente();caixinha_2();moviing(clin,obj,y);
	  goto begin;
	  	//movmentacao...
	  }else if (y==3){
	  	degi();text_cliente();caixinha_2();moviing(clin,obj,y);
	  	goto begin;
		  //lstar
	  }else if (y==4){
	  	degi();text_cliente();caixinha_2();moviing(clin,obj,y);
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
	gotoxy(34,21);
	printf("  E S T A D O:                    ");
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
  void barra_retardadaa(){
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
  void moviing(cliente *clin, viatura *obj, int k){
  	begin:
  		int vv=0;
  			 gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
			//degi();text_cliente();caixinha_2();
	  char c='\0';
  	
  	if (k==1){
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
  	 //pendente....
	   visualizar_cliente_pendente(clin, obj);
	   	
	  }else if (k==2){
	   
	   visualizar_cliente_movendo(clin, obj);
	  }else if (k==3){
	   
	   visualizar_todos_clientes(clin, obj);
	  }else if (k==4){
	  	//alerta,
	  	visualizar_cliente_em_alerta(clin, obj);
	  }
  	
  	y=0;
  	while(c!=13){
  		c=getch();
  		if (c==80){
  			barra_retardadaa();
  			y=y+2;
  			moving_barra();
  			text_cliente();
  	//		printf("-------%d----",y/2);
		  	visualizar_client_grafic(clin,obj,y/2);
  		
		  }else if (c==72){
		  	barra_retardadaa();
		  	y=y-2;
		  	moving_barra();
		  	text_cliente();
	//	  		printf("-------%d----",y/2);
		  	visualizar_client_grafic(clin,obj,y/2);
		  }else if (c==32){
		  	vv=2;
		  	c=13;
		  }
		  
	  }if (vv==2){
	  	
	  }
	   else if (k==1){
	   	opcoes_para_cliente_pendente(clin,obj,y/2);
	   //	system("cls");
	   caixinha_2();
	   visualizar_cliente_pendente(clin,obj);
		   goto begin;
	   }else if (k==2){
	    opcoes_para_cliente_movimentacao(clin,obj,y/2);
		caixinha_2();
	   visualizar_cliente_movendo(clin, obj);
	   goto begin;	
	   }else if (k==3){
	   	 opcoes_para_listar(clin, obj,y/2);
	   	caixinha_2();
	   visualizar_cliente_movendo(clin, obj);
	   goto begin;	
	   }else if (k==4){
	   	
	   }
  }
 void moviing_2(cliente *clin, viatura *obj){
  	char c='\0';
  	y=0;
  	while(c!=13){
  		c=getch();
  		if (c==80){
  			barra_retardadaa();
  			y=y+2;
  			moving_barra();
		  }else if (c==72){
		  	barra_retardadaa();
		  	y=y-2;
		  	moving_barra();
		  	
		  }
		  
	  }
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
   void menu_principal(viatura *obj,cliente *clin, usuarios *vet,agenda *agen){
   	begin:
   		system("cls");
   		system("color FF");
//   		xxx();
	   char c='\0';
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
	   printf("  %d       %d",x,y);
	 if (x==0 && y==0){
	 	system("cls");
 menu_de_viaturas(obj,clin);
	 	//menu de viaturas.
	 	goto begin;
	 }else if (x==0 &&y==7){
	 	system("cls");
	 	words_cliente(clin,obj);
	 	//menu de clinetes
	 goto begin;
	 }else if (x==21 && y==0){
	 	 system("cls");
		  action(vet);
	 	 	goto begin;
	 	 	//menu usuarios.
	 }else if  (x==21 && y==7){
	 	   system("cls");
		   moveri(obj,clin,vet,agen);
	 	 
	 	  goto begin;
	 	  //menu +++mais++
	 }
   	
   }
 void viatura_layout(){
 	
 	
 		    for (i=0;i<25;i++){
 		    		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
 		    	gotoxy(0,0+i);
 		    	 if (i<3){
printf("                                                                                                                         ");
				  }else if (i==4){
				  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);	
				  printf("                                    ");
				  }else{
				  
 		    		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
 		    		printf("                                    ");
			}
			 }
			 	
			 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
				for (i=0;i<22;i++){
   		gotoxy(42,5+i);
   		printf("                                             ");
	   }	 
				 
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		gotoxy(80,1);
		printf("                         ");	
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xC0);
		gotoxy(0,27);
			printf("                                    ");
		gotoxy(0,28);
		
		printf("        + SPACE FOR MORE +          ");		 
		gotoxy(0,29);
			printf("                                    ");		
			
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		gotoxy(0,0);
			printf("                                    ");
		gotoxy(0,1);
		
		printf("                                    ");		 
		gotoxy(0,2);
			printf("                                    ");		 
			
 }
   void estampa(){
   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xAA);
   	for (i=0;i<22;i++){
   		gotoxy(41,4+i);
   		printf("                                             ");
	   }

	     
   }  
   void barra_retardada(){
   	 	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
			 	gotoxy(0+x,3+y);
			 	printf("                                    ");
			 	gotoxy(0+x,4+y);
			 		printf("                                    ");
			 			gotoxy(0+x,5+y);
			 		printf("                                    ");
   }
   int manipulacao_sim_nao(){
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	char c='\0';
   	int ch=0;
	   while(c!=13){
   		c=getch();
   		if (c==77){
   			ch=ch+1;
		   }else if (c==75){
		   	ch=ch-1;
		   }if (ch==0){
		   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   		gotoxy(80,28);
   		printf(" S I M ");
   		gotoxy(97,28);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		printf(" N A O ");}
   		else if (ch==1){
   			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   			gotoxy(80,28);
   		printf(" S I M ");
   		gotoxy(97,28);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   		printf(" N A O ");
		   }else if (ch==3){
		   	ch=0;
		   }else if (ch==-1){
		   	ch=1;
		   }
	   }
   	return(ch);
   }
   int manipulacao_categoria(){
   	char c='\0';
   	int ch=0;
	   while(c!=13){
   		c=getch();
   		if (c==77){
   			ch=ch+1;
		   }else if (c==75){
		   	ch=ch-1;
		   }if (ch==0){
		   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   		gotoxy(70,28);
   		printf(" L I G E I R O ");
   		gotoxy(97,28);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		printf(" P E S A D O ");}
   		else if (ch==1){
   			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   			gotoxy(70,28);
   		printf(" L I G E I R O ");
   		gotoxy(97,28);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   			printf(" P E S A D O ");
		   }else if (ch==3){
		   	ch=0;
		   }else if (ch==-1){
		   	ch=1;
		   }
	   }
   	return(ch);
   	
   }
   
   
   int manipulacao_situacao(){
   	char c='\0';
   	int ch=0;
	   while(c!=13){
   		c=getch();
   		if (c==77){
   			ch=ch+1;
		   }else if (c==75){
		   	ch=ch-1;
		   }if (ch==0){
		   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   		gotoxy(70,28);
   		printf(" E M  M A N U N T E C A O ");
   		gotoxy(97,28);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		printf(" P A R Q U E A D O ");}
   		else if (ch==1){
   			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   			gotoxy(70,28);
   		printf(" E M  M A N U N T E C A O ");
   		gotoxy(97,28);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   			printf(" P A R Q U E A D O ");
		   }else if (ch==3){
		   	ch=0;
		   }else if (ch==-1){
		   	ch=1;
		   }
	   }
   	return(ch);
   	
   }
   
   int mostrar_estados(){
   	char c='\0';
   	int up=1;;
   	//printf("ffffffffffffffff");
   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   		while(c!=13){
   	     		c=getch();
   	     		if (c==77){
   	     			up=up+1;
					}
					else if (c==75){
						up=up-1;
					}
					   if (up==1){
					   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
					   	gotoxy(57,28);
					   	printf(" P E S S I M O ");
					   	gotoxy(78,28);
					   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
					   	printf(" R A Z O A V E L ");
					   	gotoxy(104,28);
					   	printf(" B O M ");
					   }else if (up==2){
					   	
					   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
					   	gotoxy(57,28);
					   	printf(" P E S S I M O ");
					   	gotoxy(78,28);
					   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
					   	printf(" R A Z O A V E L ");
					   	gotoxy(104,28);
					   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
					   	printf(" B O M ");
					   	
					   }else if (up==3){
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
					   	gotoxy(57,28);
					   	printf(" P E S S I M O ");
					   	gotoxy(78,28);
					   	 
					   	printf(" R A Z O A V E L ");
					   	gotoxy(104,28);
					   	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
					   	printf(" B O M ");
					   	
					   	
					   	
					   }else if (up<1 || up<3){
					   	up=1;
					   }
				}
						 
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");			 
			
				return(up);
   }
   int manipulacao_add_voltar(){
  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	char c='\0';
   	int ch=0;
	   while(c!=13){
   		c=getch();
   		if (c==77){
   			ch=ch+1;
		   }else if (c==75){
		   	ch=ch-1;
		   }if (ch==0){
		   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   		gotoxy(37,28);
   		printf(" N O V A  A Q U I S I C A O ");
   		gotoxy(103,28);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   		printf(" V O L T A R ");}
   		else if (ch==1){
   			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   			gotoxy(37,28);
   		printf(" N O V A  A Q U I S I C A O ");
   		gotoxy(103,28);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
   		printf(" V O L T A R ");
		   }else if (ch==3){
		   	ch=0;
		   }else if (ch==-1){
		   	ch=1;
		   }
	   }
   	return(ch);
   }
   void editar_dados_de_viatura(int cc, viatura *obj){
   	char c='\0';
   	int bb;
   	int up=0;
   	gotoxy(37,28);
   	printf("                                                                               ");
   	gotoxy(37,28);
   	printf("A L T E R A R   E S T A D O:?");
   	  bb=manipulacao_sim_nao();
   	     if (bb==0){
   	     	gotoxy(37,28);
   	     	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
   	     	  	printf("                                                                               ");
   	     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	     gotoxy(37,28);
   	     printf(" E S T A D O: ?");
			up=mostrar_estados();
   	     if (up==1){
   	     	strcpy(obj[cc].estado,"PESSIMO");
   	     	visualizar_viatura_graph(obj,cc);
   	     	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
			}else if (up==2){
				strcpy(obj[cc].estado,"RAZOAVEL");
				visualizar_viatura_graph(obj,cc);
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
			}else if (up==3){
				strcpy(obj[cc].estado,"OPTIMO");
				visualizar_viatura_graph(obj,cc);
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
			}
			}else if (bb==1){
				  		gotoxy(37,28);
   	     	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
   	     	  	printf("                                                                               "); 
			}
			if (strcmp(obj[cc].situacao,"ALUGADO")!=0){
				gotoxy(37,28);
   	printf("                                                                               ");
   	gotoxy(37,28);
   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	printf("A L T E R A R   S I T U A C A O:?");
				 bb=manipulacao_sim_nao();
				 if (bb==0){
			gotoxy(37,28);
   	     	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	     	  	printf("                                                                               "); 		 
   	     gotoxy(37,28);
   	     printf(" S I T U A C A O: ?");
      up=manipulacao_situacao();   	 
	     if (up==0){
	     	strcpy(obj[cc].situacao,"MANUTENCAO");
	     	visualizar_viatura_graph(obj,cc);
	     	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		 } else if (up==1){
		 	strcpy(obj[cc].situacao,"PARQUEADO");
		 	visualizar_viatura_graph(obj,cc);
		 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
		 }   
			
		}
		else if (bb==1){
			//nao tem instrucao pois no e' para alterar a situacao
		}
			
			
			}
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");
   	gotoxy(37,28);
   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	printf("A L T E R A R   P R E C O  DE  A L G:?");
   	
				 bb=manipulacao_sim_nao();
				     if (bb==0){
				     	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xAA);
			gotoxy(65,22);
				     	printf("         ");
			gotoxy(65,22);
				     		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
				     	scanf("%d",&obj[cc].preco_aluguel);
				     	
					 }
					 else if (bb==1){
					 	//nao tem instrucao pois no e' para alterar a price
					 }
					 
gravacao_de_arquivo_viatura(obj);					 
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");			 
			
			
   }
   void barra(){
   	 	 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
			 	gotoxy(0+x,3+y);
			 	printf("                                    ");
			 	gotoxy(0+x,4+y);
			 		printf(" ");
			 		gotoxy(35,4+y);
			 		printf(" ");
			 			gotoxy(0+x,5+y);
			 		printf("                                    ");
   }
    void menu_de_viaturas(viatura *obj,cliente *clin){
   
   
   begin:
   	system("color F0");
	   // SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
   	int h=0,l=0;
   	char nu='\0';
   		char c='\0';
   		 y=0;
    	viatura_layout();
    	estampa();
    	barra();
    	 visualizar_viaturas(obj);
    	 visualizar_viatura_graph(obj,y);
    	while(c!=13 ){
    		c=getch();
    		if (c==80){
    			barra_retardada();
    			estampa();
    			y=y+2;
    			barra();
    			 visualizar_viatura_graph(obj,y/2);
    			 visualizar_viaturas(obj);
			}else if(c==72){
				barra_retardada();
				estampa();
				y=y-2;
				barra();
				visualizar_viatura_graph(obj,y/2);
				 visualizar_viaturas(obj);
			} else if (c==32){
				
				c=13;
				nu=12;
			}
		}
//printf("===%d===",y/2);

			 if (nu==12){
			 	l=manipulacao_add_voltar();
			 if (l==0){
			 estampa();
			 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
			 adicionar_nova_viatura(obj);
			 system("cls");
		    	goto begin;
			 }else if (l==1){
			 	//printf("dddddd");
			 }
			 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			 	//adicionar novas viaturas..
			 }	else{
			 
		h=escrita();
		    if (h==1){
		    			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");
   	gotoxy(37,28);
   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	printf(" C O N F I R M A R  R E M O C A O:?");
		    	getch();
		    	l=manipulacao_sim_nao();
		    	if (l==0){
		    	apagar_viatura(y/2, obj);	
				}else if (l==1){
					
				}
		    	
		    
		    	system("cls");
		    	goto begin;
			}else if (h==4){//voltar
				system("cls");
		    	goto begin;
			}else if (h==2){//editar
			 editar_dados_de_viatura(y/2,obj);
			getch();
				system("cls");
		    	goto begin;	
			}else if (h==3){
				estampa();
				cadastrar_cliente(clin,obj,y/2);
				system("cls");
		    	goto begin;	
				//alugar.........
			}
			
		}
	}

int escrita(){
	char c;
	int b=1;;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" R E M O V E ");
	gotoxy(53,28);
	printf(" E D I T ");
		gotoxy(63,28);
		printf(" A L U G A R ");
		gotoxy(78,28);
		printf(" V O L T A R ");
		while(c!=13){
			c=getch();
		     	if (c==77){
		  b=b+1;   		
				 }else if (c==75){
				b=b-1; 	
				 }
				 if (b==1){
				 	
				 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	gotoxy(37,28);
	printf(" R E M O V E ");
	gotoxy(53,28);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	printf(" E D I T ");
		gotoxy(63,28);
		printf(" A L U G A R ");
		gotoxy(78,28);
		printf(" V O L T A R ");
		
				 }else if (b==2){
		
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" R E M O V E ");
	gotoxy(53,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	printf(" E D I T ");
		gotoxy(63,28);
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		printf(" A L U G A R ");
		gotoxy(78,28);
		printf(" V O L T A R ");
				 }else if (b==3){
	
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" R E M O V E ");
	gotoxy(53,28);
	printf(" E D I T ");
		gotoxy(63,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf(" A L U G A R ");
		gotoxy(78,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		printf(" V O L T A R ");


				 }else if (b==4){
		
				 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" R E M O V E ");
	gotoxy(53,28);
	printf(" E D I T ");
		gotoxy(63,28);
		printf(" A L U G A R ");
		gotoxy(78,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf(" V O L T A R ");
		
				 	
				 }
			 }
			 return(b);
	//getch();
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
}	
gotoxy(45,6);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	printf("W E L C O M E  B A C K");
gotoxy(43,12);
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x8F);
printf("USER:");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(48,12);
printf("                       ");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x8F);
gotoxy(42,15);
printf("SENHA:");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(48,15);
printf("                       ");

	
}
   void escrita_do_inicio(usuarios *vet){
   	begin:
   	layout();	
	   char c='\0';
   	int x=0;
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
   	codificacao_de_usuario(vet);
   		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   }else if(x==2){
   	system("cls");
   	system("COLOR 0F");
   		sensatio();
   		getch();
   	system("COLOR F0");
   	system("cls");
   	goto begin;
   }else if (x==3){
   	
   }else if (x==4){
   	
   	
   }
   }


void gravacao_de_arquivo_viatura( viatura *obj ){// tem como funcao gravar dados no arquivo referente a viaturas... 
p=fopen("arquivo.txt","w");
   for (i=0;i<tamanho;i++){
   fprintf(p,"%s\t%s\t%s\t%s\t%d\t%d\t%s\t%s\t%d\n",obj[i].marca,obj[i].modelo,obj[i].matricula,obj[i].categoria,obj[i].lotacao,obj[i].preco_aquisicao,obj[i].estado,obj[i].situacao,obj[i].preco_aluguel);	
   }
fclose(p);	
}

void leitura_de_arquivo_viatura ( viatura *obj){//conta  o numero de dados que no arquivo-para alem de passar os dadospara forma logica..
	tamanho=0;i=0;
	p=fopen("arquivo.txt","r");
	while(!feof(p)){
fscanf(p,"%s%s%s%s%d%d%s%s%d",&obj[i].marca,&obj[i].modelo,&obj[i].matricula,&obj[i].categoria,&obj[i].lotacao,&obj[i].preco_aquisicao,&obj[i].estado,&obj[i].situacao,&obj[i].preco_aluguel);			
i++;	
}
tamanho=i-1;
fclose(p);
}

void cadastrar_viatura(viatura *obj){     //processo de cadastro de viaturas...
printf("Numero de viaturas");
	scanf("%d",&v);
	for (i=0;i<v;i++){
		printf("MARCA\n");
		setbuf(stdin,NULL);       //  tem como funcao nao permitir que um dado nao seja lido....
		gets(obj[i].marca);
		printf("MODELO\n");
		gets(obj[i].modelo);
		printf("MATRICULA\n");
		gets(obj[i].matricula);
		printf("CATEGORIA\n");
		scanf("%s",&obj[i].categoria);
		printf("LOTACAO\n");
		scanf("%d",&obj[i].lotacao);
		printf("PRECO\n");
		scanf("%d",&obj[i].preco_aquisicao);
		printf("Estado\n");
		setbuf(stdin,NULL);
		gets(obj[i].estado);
	strcpy(obj[i].situacao,"DESPONIVEL");
		//printf()
		tamanho=v;
}
gravacao_de_arquivo_viatura(obj);
}
 
 void gravar_dados_apagados_da_estrutura_viatura(int p,viatura *obj){//tem como funcao gravar dados que serao apagados no metodo "apagar_viatura", para a posterior conseguir recuperar..
 	aux_recuperar=fopen("apagados.txt","a+");
fprintf(aux_recuperar,"%s\t%s\t%s\t%s\t%d\t%d\t%s\t%s\t%d\n",obj[p].marca,obj[p].modelo,obj[p].matricula,obj[p].categoria,obj[p].lotacao,obj[p].preco_aquisicao,obj[p].estado,obj[p].situacao,obj[p].preco_aluguel);	       		
 fclose(aux_recuperar);
 }
  void regravar_dados_apagados_da_estrutura_viatura(viatura *obj2){//tem como funcao gravar dados que serao apagados no metodo "apagar_viatura", para a posterior conseguir recuperar..
 	int p;
	 aux_recuperar=fopen("apagados.txt","w");
 	for (p=0;p<tamanho_2;p++){
	 
fprintf(aux_recuperar,"%s\t%s\t%s\t%s\t%d\t%d\t%s\t%s\t%d\n",obj2[p].marca,obj2[p].modelo,obj2[p].matricula,obj2[p].categoria,obj2[p].lotacao,obj2[p].preco_aquisicao,obj2[p].estado,obj2[p].situacao,obj2[p].preco_aluguel);	       		
 }
 fclose(aux_recuperar);
 }
 
 void apagar_viatura(int c, viatura *obj){
 			 gravar_dados_apagados_da_estrutura_viatura(c, obj);  		
	
	 
	 		for (i=c;i<tamanho;i++){
		obj[i]=obj[i+1];
	}
	 
	 tamanho=tamanho-1;//incremento do tamanho do dadosque estao na estutura...
	 gravacao_de_arquivo_viatura(obj);
 }
  
  
  void adicionar_nova_viatura(viatura *obj){//funcao para adicionar nova viatura....
	p=fopen("arquivo.txt","a+");
 int z=0;
 int est=0;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		gotoxy(3,tamanho*2+4);
		printf("V I A T U R A:");
		setbuf(stdin,NULL);   
		gotoxy(20, tamanho*2+4);   //  tem como funcao nao permitir que um dado nao seja lido....
		strcpy(obj[z].marca,validacao_string());
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
		gotoxy(47,8);
		printf("M O D E L O:");
		gotoxy(69,8);
		strcpy(obj[z].modelo,validacao_string());
		
		gotoxy(47,10);
		printf("M A T R I C U L A:");
		gotoxy(69,10);
		gets(obj[z].matricula);
		
		gotoxy(47,12);
		printf("C A T E G O R I A:");
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");			 
	 
		gotoxy(37,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		printf("C A T E G O R I A:");
	
		est=manipulacao_categoria();
		 if (est==0){
		 	strcpy(obj[z].categoria,"LIGEIRO");
		 }else if (est==1){
		 	strcpy(obj[z].categoria,"PESADO");
		 }
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");			 
	 
		gotoxy(69,12);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
		printf("%s",obj[z].categoria);
		//strcpy(obj[z].marca,validacao_string());
		
		gotoxy(47,14);
		printf("L O T A C A O:");
		gotoxy(69,14);
		scanf("%d",&obj[z].lotacao);
		
	    gotoxy(47,16);
		printf("E S T A D O:");
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");			 

		;
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		gotoxy(37,28);
		printf("E S T A D O:");
		est=mostrar_estados();
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");			 

		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
		
		  if (est==1){
		  	strcpy(obj[z].estado,"PESSIMO");
		  }else if (est==2){
		  	strcpy(obj[z].estado,"RAZOAVEL");
		  }else if (est==3){
		  	strcpy(obj[z].estado,"OPTIMO");
		  }
		gotoxy(69,16);
		printf("%s",obj[z].estado);		
		
		gotoxy(47,18);
		printf("S I T U A C A O:");
		gotoxy(69,18);
		strcpy(obj[z].situacao,"PARQUEADO");
		printf("%s",obj[z].situacao);
		
		gotoxy(47,20);
		printf("Q U I L O M E T R A G:");
		gotoxy(69,20);
		scanf("%d",&obj[z].preco_aquisicao);
	//	printf("  KM");
		
		gotoxy(47,22);
		printf("P R E C O  A L G:");
		gotoxy(69,22);
		scanf("%d",&obj[z].preco_aluguel);
		
gotoxy(37,28);
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
printf("C O N F I R M A R  A Q U I S I C A O: ");
		est=manipulacao_sim_nao();
					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");			 
		if (est==0){
			
		
		fprintf(p,"%s\t%s\t%s\t%s\t%d\t%d\t%s\t%s\t%d\n",obj[z].marca,obj[z].modelo,obj[z].matricula,obj[z].categoria,obj[z].lotacao,obj[z].preco_aquisicao,obj[z].estado,obj[z].situacao,obj[z].preco_aluguel);	
}else {
	
	
}

  	
  	
  	fclose(p);
  }
  
  void leitura_de_arquivo_de_apagados(viatura *obj2){//le' o numerode dados inscritos o arquivo de apagados..
  		tamanho_2=0;i=0;
		aux_recuperar=fopen("apagados.txt","r");
	while(!feof(aux_recuperar)){
fscanf(aux_recuperar,"%s%s%s%s%d%d%s%s%d",&obj2[i].marca,&obj2[i].modelo,&obj2[i].matricula,&obj2[i].categoria,&obj2[i].lotacao,&obj2[i].preco_aquisicao,&obj2[i].estado,&obj2[i].situacao,&obj2[i].preco_aluguel);			
i++;	
}
tamanho_2=i-1;
fclose(aux_recuperar);
  }
  
  
   void recuperar_viatura_apagada(viatura *obj2, int h){// tem como funcao recuperar viaturas que anteriormente foram apagadas do arquivo das viaturas..
   	
   	
   	
   		p=fopen("arquivo.txt","a+");
 	p=fopen("arquivo.txt","a+");//escrevendo dados no arquivo viatura
 fprintf(p,"%s\t%s\t%s\t%s\t%d\t%d\t%s\t%s\t%d\n",obj2[h].marca,obj2[h].modelo,obj2[h].matricula,obj2[h].categoria,obj2[h].lotacao,obj2[h].preco_aquisicao,obj2[h].estado,obj2[h].situacao,obj2[h].preco_aluguel);	       	  
  	fclose(p);
   	
for (i=h;i<tamanho_2;i++){
	obj2[i]=obj2[i+1];  //tem como funcao apagar o carro recuperado.. 
}   	
   	tamanho_2=tamanho_2-1;
   	regravar_dados_apagados_da_estrutura_viatura(obj2);

 
   }
  void visualizar_viatura_graph(viatura *obj, int k){
  	
	  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0); 
	 gotoxy(47,8);
	 printf ("M O D E L O:");
	 gotoxy(69,8);
	 printf("%s",obj[k].modelo);
	 
	 gotoxy(47,10);
	 printf("M A T R I C U l A:");
 gotoxy(69,10);
 printf("%s",obj[k].matricula);
	 
	 gotoxy(47,12);
	 printf("C A T E G O R I A:");
	gotoxy(69,12);
	 printf("%s",obj[k].categoria);
	 
	 gotoxy(47,14);
	 printf("L O T A C A O:");
gotoxy(69,14);
printf("%d",obj[k].lotacao);
	 
	 gotoxy(47,16);
	 printf("E S T A D O:");
	 gotoxy(69,16);
	 printf("%s",obj[k].estado);
	 
	 gotoxy(47,18);
	 printf("S I T U A C A O: ");
	 gotoxy(69,18);
	 printf("%s",obj[k].situacao);
	 
	 gotoxy(47,20);
	printf("Q U I L O M E T R A G:");
	 	gotoxy(69,20);
	 	printf("%d KM",obj[k].preco_aquisicao);
	
	 gotoxy(47,22);
	 printf("P R E C O  A L G:");
	 if (obj[k].preco_aluguel==0){
	 	gotoxy(69,22);
	 	printf("I N X T");
	 }else{
	 
	 gotoxy(69,22);
	 printf("%d",obj[k].preco_aluguel);
}
  }

 void visualizar_viaturas(viatura *obj){///tem como funcao imprimir os dados guardados no arquivo de viaturas.. 
  
 	leitura_de_arquivo_viatura(obj);
 	int io=0;
 	 for (i=0;i<tamanho;i++){
 	 	io=io+2;
 	 gotoxy(3,2+io);
	  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);	
 	printf("V I A T U R A:");
 	gotoxy(20,2+io);
	 printf("%s",obj[i].marca);
	
	 printf("\n");
	  }
	
 	
 }
 
 void actualizar_estado_de_viatura(viatura *obj){
 	char temporal[20];
 	bool est=false;
 	int k;
 	
 	leitura_de_arquivo_viatura(obj);
 	//printf("--%d--",tamanho);
 	printf("MODELO");
 	gets(temporal);
 	
 	for (i=0;i<tamanho;i++){
 		if (strcmp(temporal,obj[i].modelo)==0){
 			est=true;
 			k=i;
 	        break;	
		 }
	 }
 	  if (est==true){
 	  	printf("PRECO DE ALUGUEL:");
 	  	scanf("%d",&obj[k].preco_aluguel);
        gravacao_de_arquivo_viatura(obj);
        printf("ALTERACAO FEITA COM EXITO");
	   }
 	
 }
 void cadastrar_usuario(struct usuarios *vet){//metodo criado com o intuito de fazer o cadastro de usuarios.
 	i=1;
	 arq=fopen("usuarios.txt","a+");
 	printf("USER_NAME");
 	gets(vet[i].user_name);
 	printf("Codigo");
 	scanf("%d",&vet[i].codigo);
 	printf("Confiabilidade");//
 	scanf("%d",&vet[i].confiabilidade);
 	printf("ESTADO:");
 	scanf("%s",&vet[i].estado);
 	fprintf(arq,"%s\t%s\t%d\t%d\t%s\n",vet[i].nome,vet[i].user_name,vet[i].codigo,vet[i].confiabilidade,vet[i].estado);
 	
fclose(arq); }
void ler_usuarios(struct usuarios *vet){
	arq=fopen("usuarios.txt","r");
	i=0;
	numero_de_usuarios=0;
	while(!feof(arq)){
		fscanf(arq,"%s%s%d%d%s",&vet[i].nome,&vet[i].user_name,&vet[i].codigo,&vet[i].confiabilidade,&vet[i].estado);
		numero_de_usuarios=numero_de_usuarios+1;
		i++;
	}
	numero_de_usuarios=numero_de_usuarios-1;
//  printf("----=+%d------",numero_de_usuarios);
//return(numero_de_usuarios);
fclose(arq);
}
void regravar_usuarios(struct usuarios *vet){
	arq=fopen("usuarios.txt","w");
	for(i=0;i<numero_de_usuarios;i++){
		fprintf(arq,"%s\t%s\t%d\t%d\t%s\n",vet[i].nome,vet[i].user_name,vet[i].codigo,vet[i].confiabilidade,vet[i].estado);
	}
	fclose(arq);
}
void apagar_usuario(struct usuarios *vet, int k){
		
		
			
 for(i=k;i<numero_de_usuarios;i++){
		vet[i]=vet[i+1];	 
		}
	numero_de_usuarios=numero_de_usuarios-1;
	regravar_usuarios(vet);
	
}
  void codificacao_de_usuario(usuarios *vet){//way de malta leitura de codico para acessar o prog 
  	bool est=false;
  	char c='\0';
  	int z=0,codico,nu=0;
	  char temporal1[20];
	  vida:
	  	est=false;
	  	gotoxy(48,23);
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
  	printf("                                           ");
	  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(48,15);
printf("                       ");
	  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(48,12);
printf("                       ");
	  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xC0);
 gotoxy(53,17);
 printf(" LOGIN ");
	  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(48,12);
 setbuf(stdin,NULL);
  	strcpy(temporal1,validacao_string());

SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
gotoxy(48,15);
codico=validacao_para_codico();
  	//scanf("%d",&codico);
  	
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
 gotoxy(53,17);
 printf(" LOGIN ");
  	ler_usuarios(vet);
  	//printf("----%d---",numero_de_usuarios);
  	   for (i=0;i<numero_de_usuarios;i++){
  	   //	printf("xx");
  	   	       if (codico==vet[i].codigo){
  	   	       	est=true;
  	   	       	break;
					}}
					
if(z==3){
	
	for (i=0;i<31;i++){
		sleep(1);
	gotoxy(49,23);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	printf("HANG ON %d OF 30",i);
	if (i==21){
		i=27;
	}
		
	}
	z=0;
	goto vida;
}					
  if (est==true){
  	if (strcmp(vet[i].user_name,temporal1)==0 && strcmp(vet[i].estado,"ACTIVO")==0){
  			nu=i;
			  gotoxy(39,23);
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
  		printf("L E I T U R A  B E M  S U C E D I D A");
	  }else{;
	  	z=z+1;
	  		gotoxy(52,23);
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
  	printf("E R R O R");
  	getch();
	  	goto vida;
	  	
	  }
  }else if (est==false){
  	z=z+1;
  	gotoxy(52,23);
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
  	printf("E R R O R");
  	getch();
  	goto vida;
  }
  confiabilidade=vet[nu].confiabilidade;
  strcpy(activo,vet[nu].nome);
  }
  void regravacao_de_dados_de_estrutura_cliente(struct cliente *clin){
  arq1=fopen("cliente.txt","w");
  for (i=0;i<tamanho_de_vector_cliente;i++){
  	
  fprintf(arq1,"%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",clin[i].marca,clin[i].modelo,clin[i].matricula,clin[i].nome,clin[i].endereco,clin[i].idade,clin[i].telefone,clin[i].telefone2,clin[i].documento,clin[i].estado_entrega,clin[i].estado_leva,clin[i].destino,clin[i].distancia,clin[i].dia_entrega,clin[i].mes_entrega,clin[i].ano_entrega,clin[i].preco_pago,clin[i].mes_leva,clin[i].ano_leva,clin[i].dia_leva,clin[i].hora_leva);
  }
  fclose(arq1);
  }
  
  
  
  
  void leitura_de_arquivo_cliente(struct cliente *clin){
  	i=0;
  	arq1=fopen("cliente.txt","r");
  	while(!feof(arq1)){
  		fscanf(arq1,"%s%s%s%s%s%d%d%d%d%s%s%s%d%d%d%d%d%d%d%d%d",&clin[i].marca,&clin[i].modelo,&clin[i].matricula,&clin[i].nome,&clin[i].endereco,&clin[i].idade,&clin[i].telefone,&clin[i].telefone2,&clin[i].documento,&clin[i].estado_entrega,&clin[i].estado_leva,&clin[i].destino,&clin[i].distancia,&clin[i].dia_entrega,&clin[i].mes_entrega,&clin[i].ano_entrega,&clin[i].preco_pago,&clin[i].mes_leva,&clin[i].ano_leva,&clin[i].dia_leva,&clin[i].hora_leva);	
        i++;	  
	  }
  	tamanho_de_vector_cliente=i-1;
  //	printf("--%d-b--",tamanho_de_vector_cliente);
  	
  	fclose(arq1);
  }
   
void cadastrar_cliente(cliente *clin, viatura *obj, int i){// funcao feita com objectivo de cadastrar dados dos clientes da empresA...
  if (strcmp(obj[i].situacao,"PARQUEADO")!=0){
  					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");
   	gotoxy(37,28);
   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	printf("I M P O S S I V E L  A L U G A R  V I A T U R A  E M   %s",obj[i].situacao);
   	getch();
  }else{
  
   int l=0;
   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xA0);
	 //leitura_de_arquivo_viatura(obj);
 //i=1;	 
	  //printf("%s",obj[i].marca);
	 strcpy(clin[i].marca,obj[i].marca);
     strcpy(clin[i].modelo,obj[i].modelo);
     strcpy(clin[i].matricula,obj[i].matricula);
     gotoxy(47,6);
     printf("M O D E L O:");
     gotoxy(69,6);
     printf("%s",clin[i].modelo);
     
     gotoxy(47,8);
	printf("N O M E:");
	gotoxy(69,8);
	strcpy(clin[i].nome,validacao_string());
	
	gotoxy(47,10);
	printf("E N D E R E C O:");
	gotoxy(69,10);
	strcpy(clin[i].endereco,validacao_string());
	
	gotoxy(47,12);
	printf("I D A D E:");
	gotoxy(69,12);
	 clin[i].idade=validacao_inteiro();
	 
	 
	gotoxy(47,14); 
	printf("T E L E F O N E:");
	
	gotoxy(69,14);
	clin[i].telefone=validacao_inteiro();
	
	gotoxy(47,16);
	printf("T E L E F O N   O P S:");
	
	gotoxy(69,16);
	clin[i].telefone2=validacao_inteiro();
	
	gotoxy(47,18);
	printf("I D E N T F  NR:");
	
	gotoxy(69,18);
	clin[i].documento=validacao_inteiro();
	
	gotoxy(47,20);
	printf("D A T A  DE  A Q S:");
	gotoxy(67,20);
	printf("dd/mm/nn");
		gotoxy(67,20);
scanf("%d",&clin[i].dia_leva);
gotoxy(70,20);
scanf("%d",&clin[i].mes_leva);
gotoxy(73,20);
scanf("%d",&clin[i].ano_leva);
clin[i].hora_leva=0;

    strcpy(clin[i].estado_entrega,"INDESPONIVEL");
	strcpy(clin[i].estado_leva,obj[i].estado);
	gotoxy(47,22);
	printf("D E S T I N / D I S T:");
	gotoxy(69,22);
	strcpy(clin[i].destino,validacao_string());
	printf(" / ");
	clin[i].distancia=validacao_inteiro();
	printf(" KM");
	gotoxy(47,24);
	printf("D A T A  D E V:");
		gotoxy(67,24);
	printf("dd/mm/nn");
	   gotoxy(67,24);
    clin[i].dia_entrega=validacao_inteiro();
gotoxy(70,24);    
    clin[i].mes_entrega=validacao_inteiro();
    gotoxy(73,24);
    clin[i].ano_entrega=validacao_inteiro();
	
clin[i].preco_pago=3200;//obj[i].preco_aluguel*(clin[i].dia_entrega-clin[i].dia_leva);
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
					gotoxy(37,28);
   	printf("                                                                               ");
   	gotoxy(37,28);
   	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
   	printf(" C O N F I R M A R   A L U G U E L:?");
		    	getch();
		    	l=manipulacao_sim_nao();
		    	if (l==0){
strcpy(obj[i].situacao,"PENDENTE");
	arq1=fopen("cliente.txt","a+");
	fprintf(arq1,"%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",clin[i].marca,clin[i].modelo,clin[i].matricula,clin[i].nome,clin[i].endereco,clin[i].idade,clin[i].telefone,clin[i].telefone2,clin[i].documento,clin[i].estado_entrega,clin[i].estado_leva,clin[i].destino,clin[i].distancia,clin[i].dia_entrega,clin[i].mes_entrega,clin[i].ano_entrega,clin[i].preco_pago,clin[i].mes_leva,clin[i].ano_leva,clin[i].dia_leva,clin[i].hora_leva);	
	fclose(arq1);
	gravacao_de_arquivo_viatura(obj);
		    						
				}else if (l==1){
					system("cls");
				}
}
	
}
void visualizar_cliente_pendente(cliente *clin, viatura *obj){
	
	leitura_de_arquivo_cliente(clin);
	int lu=tamanho_de_vector_cliente;
	int io=0;
	int j=0;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
	   for (i=0;i<tamanho_de_vector_cliente;i++){
	   	 for (j=i+1;j<tamanho_de_vector_cliente;j++){
	   	 	if (clin[i].hora_leva>clin[j].hora_leva){
//				
	   	 	temp2=clin[i];
	   	 	clin[i]=clin[j];
	   		clin[j]=temp2;
			}}		   }
//printf("-------%dm----------",clin[0].hora_leva);
	   	
	          for (i=0;i<tamanho_de_vector_cliente;i++){
	          	if (clin[i].hora_leva==0){
	          		io=io+2;
	          		gotoxy(7,9+io);
	          		printf("N O M E:");
	          		gotoxy(17,9+io);
	          		printf("%s",clin[i].nome);
				  }
	          	
			  }
}
void visualizar_cliente_em_alerta(cliente *clin, viatura *obj){
	leitura_de_arquivo_cliente(clin);
	int io=0;
void data_dia();
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
	          for (i=0;i<tamanho_de_vector_cliente;i++){
if (clin[i].hora_leva==1 && clin[i].mes_entrega-mes<=0 && clin[i].ano_entrega-ano<=0 && clin[i].dia_entrega-dia<=1){
	          		io=io+2;
	          		gotoxy(7,9+io);
	          		printf("dia('%d'):",-1*(clin[i].dia_entrega-dia));
	          		gotoxy(17,9+io);
	          		printf("%s",clin[i].nome);
				  }
	          	
			  }




}
void visualizar_cliente_movendo(cliente *clin, viatura *obj){
	leitura_de_arquivo_cliente(clin);
	int io=0;
	for (i=0;i<tamanho_de_vector_cliente;i++){
	   	 for (j=i+1;j<tamanho_de_vector_cliente;j++){
	   	 	if (clin[i].hora_leva!=1 && clin[j].hora_leva==1){
				
				//if (clin[i].hora_leva<clin[j].hora_leva && clin[j].hora_leva!=2 && clin[j].hora_leva!=0){
				
	   	 	temp2=clin[i];
	   	 	clin[i]=clin[j];
	   		clin[j]=temp2;
			}}	
	   }
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
	          for (i=0;i<tamanho_de_vector_cliente;i++){
	          	if (clin[i].hora_leva==1){
	          		io=io+2;
	          		gotoxy(7,9+io);
	          		printf("N O M E:");
	          		gotoxy(17,9+io);
	          		printf("%s",clin[i].nome);
				  }
	          	
			  }
}

void visualizar_todos_clientes(cliente *clin, viatura *obj){
	leitura_de_arquivo_cliente(clin);
	int io=0;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
	          for (i=0;i<tamanho_de_vector_cliente;i++){
	          	
	          		io=io+2;
	          		gotoxy(7,9+io);
	          		printf("N O M E:");
	          		gotoxy(17,9+io);
	          		printf("%s",clin[i].nome);
				  
	          	
			  }
}


void opcoes_para_cliente_movimentacao(cliente *clin, viatura *obj, int k){
	begin:
	leitura_de_arquivo_viatura(obj);
	char c='\0';
	int b=1,l=0,est=0;

SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(12,28);
	printf(" S E L E C I O N E: ");
	gotoxy(37,28);
	
	printf(" P R E C O ");
	gotoxy(53,28);
	printf(" P A R Q U E A R  C N F R M ");
	
		gotoxy(82,28);
		printf(" V O L T A R ");
		while(c!=13){
			c=getch();
		     	if (c==77){
		  b=b+1;   		
				 }else if (c==75){
				b=b-1; 	
				 }
				 if (b==1){
				 	
				 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	gotoxy(37,28);
	printf(" P R E C O ");
	gotoxy(53,28);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	printf(" P A R Q U E A R  C N F R M ");
	
		gotoxy(82,28);
		printf(" V O L T A R ");
		
				 }else if (b==2){
		
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" P R E C O ");
	gotoxy(53,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	printf(" P A R Q U E A R  C N F R M ");
		
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		
		gotoxy(82,28);
		printf(" V O L T A R ");
				 }else if (b==3){
		
				 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" P R E C O ");
	gotoxy(53,28);
	printf(" P A R Q U E A R  C N F R M ");
	
		gotoxy(82,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf(" V O L T A R ");
		
				 	
				 }
			 }if (b==1){
			 	//ajustar preco
gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
			 				 
			 	gotoxy(59,23);
			 	printf("         ");
			 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			 	gotoxy(59,23);
			 	scanf("%d",&clin[k].preco_pago);
			 	regravacao_de_dados_de_estrutura_cliente(clin);
			 	//ajustar  preco
			 }else if (b==2){
gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
					 	
			 	//parquear.........
	data_dia();	
	int pos=0;	 	
			 	for (i=0;i<tamanho;i++){
			if (strcmp(clin[k].matricula,obj[i].matricula)==0){
				strcpy(obj[i].situacao,"PARQUEADO");
				pos=i;
				break;
			}
		}
		clin[k].hora_leva=2;
		clin[k].dia_entrega=dia;
		clin[k].ano_entrega=ano;
		clin[k].mes_entrega=mes;
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		gotoxy(93,23);
	printf("%d/%d/%d",clin[k].dia_entrega,clin[k].mes_entrega,clin[k].ano_entrega);
		
			 		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
			 	gotoxy(56,15);
			 	printf("         ");
			 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			 	gotoxy(56,15);
			 	scanf("%d",&clin[k].distancia);
			 	obj[pos].preco_aquisicao=obj[pos].preco_aquisicao+clin[k].distancia;
			 	
				 
				 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
			 	gotoxy(93,19);
			 	printf("         ");
			 	gotoxy(93,19);
			  SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);	
	printf("%s/%d KM",clin[k].destino,clin[k].distancia);
			 	
gotoxy(12,28);
printf(" E S T A D O  D E  D E V O L U C A O:?");
est=mostrar_estados();			 	
			 	if (est==1){
			 		strcpy(obj[pos].estado,"PESSIMO");
				 }else if (est==2){
				 	strcpy(obj[pos].estado,"RAZOAVEL");
				 }else if (est==3){
				 	strcpy(obj[pos].estado,"OPTIMO");
				 }
				strcpy(clin[k].estado_entrega,obj[pos].estado); 
			 		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
			 	gotoxy(56,19);
			 	printf("            ");
			 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			 	gotoxy(56,19);
			 	printf("%s",clin[k].estado_entrega);
gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
			 	
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(12,28);
	printf(" D E S E J A   P A R Q U E A R:? ");
			 l=manipulacao_sim_nao();
			 if (l==0){
			 gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(12,28);
	printf(" O S  D A D O S  E S T A O  B E M   P R E E N C H I D O S:? ");
			 l=manipulacao_sim_nao();
			if (l==0){
				gravacao_de_arquivo_viatura(obj);
        regravacao_de_dados_de_estrutura_cliente(clin);
			}
			else if (l==1){
			 gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
goto begin;				
			} 
		
			 }
			 else if (l==1){
			 
			 //alugar
			 }
			 gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
			 	
			 	
			 	
			 	
			 	//parquear.....
			 }else if (b==3){
			 	
			 	
			 }
			 	
}
void opcoes_para_listar(cliente *clin, viatura *obj, int k){
	char c='\0';
	int b=1,l=0;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(12,28);
	printf(" S E L E C I O N E: ");
	gotoxy(37,28);
	
	printf(" O R D E N A R -> ");
	gotoxy(57,28);
	printf(" O R D E N A R <- ");
	
		gotoxy(82,28);
		printf(" V O L T A R ");
		while(c!=13){
			c=getch();
		     	if (c==77){
		  b=b+1;   		
				 }else if (c==75){
				b=b-1; 	
				 }
				 if (b==1){
				 	
				 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	gotoxy(37,28);
	printf(" O R D E N A R -> ");
	gotoxy(57,28);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	printf(" O R D E N A R <- ");
	
		gotoxy(82,28);
		printf(" V O L T A R ");
		
				 }else if (b==2){
		
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" O R D E N A R -> ");
	gotoxy(57,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	printf(" O R D E N A R <- ");
		
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		
		gotoxy(82,28);
		printf(" V O L T A R ");
				 }else if (b==3){
		
				 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" O R D E N A R -> ");
	gotoxy(57,28);
	printf(" O R D E N A R <- ");
	
		gotoxy(82,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf(" V O L T A R ");
		
				 	
				 }
			 }
			 if(b==1){
			 	for (i=0;i<tamanho_de_vector_cliente;i++){
			 		for (j=i;j<tamanho_de_vector_cliente;j++){
			 			if (strcmp(clin[i].nome,clin[j].nome)>0){
			 				temp2=clin[i];
			 				clin[i]=clin[j];
			 				clin[j]=temp2;
						 }
					 }
				 }
				 regravacao_de_dados_de_estrutura_cliente(clin);
			 }else if (b==2){
			 	for (i=0;i<tamanho_de_vector_cliente;i++){
			 		for (j=i;j<tamanho_de_vector_cliente;j++){
			 			if (strcmp(clin[i].nome,clin[j].nome)<0){
			 				temp2=clin[i];
			 				clin[i]=clin[j];
			 				clin[j]=temp2;
						 }
					 }
				 }
				 regravacao_de_dados_de_estrutura_cliente(clin);
			 }else if (b==3){
			 	
			 }
	
}

void opcoes_para_cliente_pendente(cliente *clin, viatura *obj, int k){
	leitura_de_arquivo_viatura(obj);
	char c='\0';
	int b=1,l=0;
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(12,28);
	printf(" S E L E C I O N E: ");
	gotoxy(37,28);
	
	printf(" R E M O V E ");
	gotoxy(53,28);
	printf(" A L U G A R  C N F R M ");
	
		gotoxy(82,28);
		printf(" V O L T A R ");
		while(c!=13){
			c=getch();
		     	if (c==77){
		  b=b+1;   		
				 }else if (c==75){
				b=b-1; 	
				 }
				 if (b==1){
				 	
				 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	gotoxy(37,28);
	printf(" R E M O V E ");
	gotoxy(53,28);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	printf(" A L U G A R   C N F R M ");
	
		gotoxy(82,28);
		printf(" V O L T A R ");
		
				 }else if (b==2){
		
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" R E M O V E ");
	gotoxy(53,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
	printf(" A L U G A R  C N F R M ");
		
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
		
		gotoxy(82,28);
		printf(" V O L T A R ");
				 }else if (b==3){
		
				 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(37,28);
	printf(" R E M O V E ");
	gotoxy(53,28);
	printf(" A L U G A R  C N F R M ");
	
		gotoxy(82,28);
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf(" V O L T A R ");
		
				 	
				 }
			 }
			 
			 if (b==1){
			 //remove;	
			 gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(12,28);
	printf(" D E S E J A   A P A G A R:? ");
			 l=manipulacao_sim_nao();
			   if (l==0){
			 	for (i=k;i<tamanho_de_vector_cliente;i++){
			 		clin[i]=clin[i+1];
				 }
				 tamanho_de_vector_cliente=tamanho_de_vector_cliente-1;
				 regravacao_de_dados_de_estrutura_cliente(clin);
				 }else if (l==1){
				 	
				 }
			 	
			 //remove;
			 }else if (b==2){
			 	//alugar
			 	data_dia();
gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
		
		
   clin[k].dia_leva=dia;
   clin[k].ano_leva=ano;
   clin[k].mes_leva=mes;
   gotoxy(93,21);
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
   printf("     ");
gotoxy(57,23);
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
   printf("         ");
      
        gotoxy(93,21);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);

	    printf("%d/%d/%d",clin[k].dia_leva,clin[k].mes_leva,clin[k].ano_leva);
        gotoxy(57,23);
        scanf("%d",&clin[k].preco_pago);
       // printf("-------%d---------",tamanho);
		for (i=0;i<tamanho;i++){
			if (strcmp(clin[k].matricula,obj[i].matricula)==0){
				strcpy(obj[i].situacao,"ALUGADO");
				//printf("ddddddddd");
				break;
			}
		}
		clin[k].hora_leva=1;
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
	gotoxy(12,28);
	printf(" D E S E J A   A L U G A R:? ");
			 l=manipulacao_sim_nao();
			 if (l==0){
			 
		gravacao_de_arquivo_viatura(obj);
        regravacao_de_dados_de_estrutura_cliente(clin);
			 }
			 else if (l==1){
			 
			 //alugar
			 }
			 gotoxy(12,28);
			 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFF);
printf("                                                                                                           ");			 
		
			 
			 }else if (b==3){
			 	//voltar
			 	
			 	
			//voltar 
			}
}


void visualizar_client_grafic(cliente *clin, viatura *obj, int b){

	i=b;


	 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
	
	gotoxy(56,9);
	printf("%s",clin[i].marca);
	gotoxy(56,11);
	printf("%s",clin[i].modelo);
	gotoxy(56,13);
	printf("%s",clin[i].matricula);
	gotoxy(56,15);
	printf("%d KM",clin[i].distancia);
	gotoxy(56,17);
	printf("%s",clin[i].estado_leva);
	gotoxy(56,19);
	printf("%s",clin[i].estado_entrega);
	if (clin[i].hora_leva==0){
		gotoxy(56,21);
		printf("PENDENTE");
	}else if(clin[i].hora_leva==1){
		gotoxy(56,21);
		printf("TRAFEGANDO");
	}else if (clin[i].hora_leva==2){
		gotoxy(56,21);
		printf("DESCONECTADO");
	}
	gotoxy(59,23);
	printf("%d",clin[i].preco_pago);
	
	gotoxy(93,9);
	printf("%s",clin[i].endereco);
	gotoxy(93,11);
	printf("%d",clin[i].idade);
	gotoxy(93,13);
	printf("%d",clin[i].telefone);
	gotoxy(93,15);
	printf("%d",clin[i].telefone2);
	gotoxy(93,17);
	printf("%d",clin[i].documento);
	gotoxy(93,19);
	printf("%s/%d",clin[i].destino,clin[i].distancia);
	gotoxy(93,21);
	printf("%d/%d/%d",clin[i].dia_leva,clin[i].mes_leva,clin[i].ano_leva);
	gotoxy(93,23);
	printf("%d/%d/%d",clin[i].dia_entrega,clin[i].mes_entrega,clin[i].ano_entrega);
	
	
	
	
}
void actualizar_dados_de_estrutura_cliente_na_entrega(cliente *clin, viatura *obj){
		 char temporal[30];
		 leitura_de_arquivo_viatura(obj);
		 leitura_de_arquivo_cliente(clin);
		 printf("nome do cliente");
		 gets(temporal);
	
	printf("ESTADO DE ENTREGA");
	gets(clin[i].estado_entrega);
	strcpy(obj[i].estado,clin[i].estado_entrega);
	strcpy(obj[i].situacao,"DESPONIVEL");
	
	
	
	gravacao_de_arquivo_viatura(obj);
	regravacao_de_dados_de_estrutura_cliente(clin);
	
}

void procura_rapida(viatura *obj){
	
}
void regravar_agenda(struct agenda *agen){
	agn=fopen("agend.txt","w");
	for(i=0;i<tam_agenda;i++){
		fprintf(agn,"%s\t%d\t%d\t%d\n",agen[i].actividade,agen[i].ano,agen[i].dia,agen[i].mes);
	}
	fclose(agn);
}

void leitura_de_arquivo_agenda(struct agenda *agen){
int bc=0;
	agn=fopen("agend.txt","r");
	while(!feof(agn)){
		fscanf(agn,"%s%d%d%d",&agen[bc].actividade,&agen[bc].ano,&agen[bc].dia,&agen[bc].mes);
	bc++;
	}
	tam_agenda=bc;
	tam_agenda=tam_agenda-1;
	//printf("mmmm%d",bc);
	fclose(agn);
}

int main() {
begin:
data_dia();
system("title                      S.G.A-  S I S T E M A    D E    G E S T Ã O    D E    A L U G U E L   D E   V I A T U R A S ");
    struct agenda agen[20];
	struct viatura obj[50],obj2[50];
	struct usuarios vet[5];
	struct cliente clin[30];
	//regravar_agenda(agen);
	//ler_usuarios(vet);
	escrita_do_inicio(vet);
//xcc(agen);
//leitura_de_arquivo_agenda(agen);


	getch();
	if (confiabilidade!=0){
	
		menu_principal(obj,clin,vet,agen);
		system("cls");
		goto begin;
		}
	//layout();escrita_do_inicio(vet); //estao sempre juntos..
//	actualizar_dados_de_estrutura_cliente_na_entrega(clin,obj);
	//leitura_de_arquivo_cliente(clin);
	//regravacao_de_dados_de_estrutura_cliente(clin);
	//cadastrar_cliente(clin,obj);
    //   codificacao_de_usuario(vet);
//ler_usuarios(vet);
               //apagar_usuario(vet);
	//cadastrar_usuario(vet);
//	actualizar_estado_de_viatura(obj);
	//visualizar_viaturas(obj);
 //recuperar_viatura_apagada(obj2);leitura_de_arquivo_viatura (obj);
 //leitura_de_arquivo_viatura (obj);
//	adicionar_nova_viatura(obj);
//	apagar_viatura(obj);
//leitura_de_arquivo_viatura(obj);
//printf("%d",tamanho);
//	cadastrar_viatura(obj);
	
}


