#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "C:\Users\Tungueshon\Desktop\proyecto cientifica\controles.h"


void encripto(char contrase[15]);
int menu();
int verificar(char usuar[10]);
void verusuarios();

void crearusuario();
		
void cambiarcontrasenia();

int texto;
char encript [10] = "MURCIELAGO";
char contrnuev[100];
char encript2 [10] = "0123456789";
char usuario[10];
char contrase[15];
char contrasec[15];
char nombre[20];

int main(){
   int i, verifica=1, inicio, tecla,ll=0;
	do{
		system("cls");
		i=0;
		i = menu();
		switch(i){
			case 1:   
			   do{
				system("cls");
					gotoxy(5,1);
					printf("Inicio de Sesion");
					gotoxy(1,3);
					printf("Usuario:");
					gotoxy(1,4);
					printf("Contrase%ca:",164);
					textbox(11, 3, 10, "Usuario" );
					textbox(11, 4, 15, "Contraseña" );
					textbackground(YELLOW);
					gotoxy(12,3); cscanf("%9s", &usuario);
					gotoxy(12,4); gets(contrase);
					verifica = verificar(usuario);
					if(verifica == 0){
						gotoxy(10,10);
						printf("inicio de sesion correcto\n");
						
						printf("presione cualquier tecla para avanzar");
						getch();
						}
						else{
						gotoxy(10,10);
						printf("inicio de sesion incorrecto");
						gotoxy(5,12);
						printf("presione ENTER para salir al menu o cualquier tecla para volver a intentar");
						inicio = 1;
						tecla = fxtecla();
						}
					tecla = fxtecla();
				}while(inicio != 1 || tecla != ENTER);
			break;
			case 2:
				verusuarios();
			break;
			case 3:
				crearusuario();
			break;
			case 4:
				cambiarcontrasenia();
			break;
			case 5:
				exit(0);
			break;
		}
	}while( ll==0 );
}


void encripto(char contrase[15]){
    char letra;

char temp[31];
int tmp;
int i;

do{

tmp = strlen(contrase);

for(i=0; i<tmp; i++){

switch(contrase[i]){

case 'a ': contrase[i] = '7'; break;
case 'c': contrase[i] = '3'; break;
case 'e': contrase[i] = '5'; break;
case 'g': contrase[i] = '8'; break;
case 'h': contrase[i] = '4'; break;
case 'l': contrase[i] = '6'; break;
case 'm': contrase[i] = '0'; break;
case 'o': contrase[i] = '9'; break;
case 'r': contrase[i] = '2'; break;
case 'u': contrase[i] = '1'; break;


}

}



}while(strcmp(contrase, "")!=0);

}


int verificar(char usuario[10]){


}

int menu(){
	int i=0, tecla;
	gotoxy(15,2); printf("Menu");
	gotoxy(13,5); printf("1.- Iniciar Sesion (F1)");
	gotoxy(13,6); printf("2.- Ver Usuarios (F2)");
	gotoxy(13,7); printf("3.- Crear Usuarios (F3)");
	gotoxy(13,8); printf("4.- Cambiar Contrase%ca (F4)",164);
	gotoxy(13,9); printf("5.- Salir (ESC)");
	do{
		tecla = fxtecla();
		switch(tecla){
			case F1:
				i = 1;
			break;
			case F2:
				i = 2;
			break;
			case F3:
				i = 3;
			break;
			case F4:
				i = 4;
			break;
			case ESC:
				i = 5;
			break;
		}
	}while(i == 0);
	
	return i;
}

void verusuarios(){
	system("cls");
	printf("Usuario");
	gotoxy(21,1);
	printf("Nombre");
	
	getch();
}

void crearusuario(){
	system("cls");
	printf("    Crear nuevo usuario\n\n\nUsuario:\nNombre completo:\nContrase%ca:\nConfirmar contrase%ca:",164,164);
	textbox(10, 4, 10, "Usuario" );
	textbox(17, 5, 20, "Nombre Completo" );
	textbox(12, 6, 15, "Contraseña" );
	textbox(20, 7, 15, "Confirmar contraseña" );
	textbackground(YELLOW);
	gotoxy(11,4); cscanf("%9s", &usuario);
	gotoxy(18,5); cscanf("%20s", &nombre);
	gotoxy(13,6); cscanf("%15s", &contrase);
	gotoxy(21,7); cscanf("%15s", &contrasec);
	getch();

}
		
void cambiarcontrasenia(){
	system("cls");
	printf("    Cambiar contrase%ca\n\n\nIngrese usuario:\nNueva contrase%ca:\nConfirmar contrase%ca:",164,164,164);
	textbox(17, 4, 10, "Ingrese Usuario" );
	textbox(18, 5, 15, "Nueva contraseña" );
	textbox(22, 6, 15, "Confirmar contraseña" );
	textbackground(YELLOW);
	gotoxy(11,4); cscanf("%9s", &usuario);
	gotoxy(18,5); cscanf("%15s", &contrase);
	gotoxy(13,6); cscanf("%15s", &contrasec);
	getch();


}
