#include<windows.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>




struct pessoa{
	char nome[20];
}
 int obj[max];

FILE *arq
int i=0;
void iniciar(){
	arq=fopen("txt","r+");
	if(arq==NULL)
	arq=fopen("txt","w+");}
	void cadastrar(struct pessoa, int tam);
	{
		int p=tam();
		if (tam<=max-tam) 
		{for(i=p; i<p=tam;i++){
			fflush(stdin);
			fseek(arq,    OL     ,seek_end);
		}
		}
		fwrite(&obj[i], sizeof(struct pessoa),1,arq);
	}
int tam(){
	i=0;
	while(!feof(arq)){
		fread(&obj[i],sizeof(struct pessoa),1,arq);
		i++;}
		return(i);}
		int main(){
			iniciar();
			cadastrar()
		}
		}
}

