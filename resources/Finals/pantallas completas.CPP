#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
#include <time.h>
#include "C:\Users\Tungueshon\Desktop\proyecto cientifica\figuras.h"
#include "C:\Users\Tungueshon\Desktop\proyecto cientifica\teclado.h"
#include "C:\Users\Tungueshon\Desktop\proyecto cientifica\controles.h"
#include "C:\Users\Tungueshon\Desktop\proyecto cientifica\listapacientes.h"
#define USER "nestor" //este es nombre de usuario
#define PASS "oliva"  //la contrasena
#define L 80



void Pacientes();
void interfaz();
void interfazCon();
void citas();
void interfazcitas();
void consultas();
void medicos();
void interfazMed();
void seguridad();
void interfazseg();
void MarcarItem(ptrnodolista ptrActual, int fila);
void VerLista(ptrnodolista ptrInicio, ptrnodolista ptrActual);
void DesmarcarItem(ptrnodolista ptrActual, int fila);
void MostrarDatos(ptrnodolista ptrActual);

int main(){

char usuario[L + 1];
	char password[L + 1];
	int contador = 0 ;
	char ingresa = 0;
	int i = 0;	// Indica la posición del caracter leído en la cadena
	char caracter; // Guarda el caracter leído mediante la función getch

	do {
		system("cls");
      fxrectangulo(4,4,55,18,BLUE);
      fxrectangulo(56,1,73,4,RED);
		gotoxy(35,3);printf("\t\t\tINICIO DE SESION\n");

		printf("\n\tUsuario: ");
		gets(usuario);

		printf("\tPassword: ");

		/* Lectura del password */
		i = 0;	/* Indica la posición del caracter leído en la cadena */

		caracter = getch();
		while (i < L && caracter != 13) {
			printf("*");
			password[i] = caracter;
			i++;
			caracter = getch();
		}
		password[i] = '\0';

		if (strcmp(usuario, USER) == 0 && strcmp(password, PASS) == 0) {
			ingresa = 1;
		} else {
			printf("\n\n\tEl usuario y/o password son incorrectos\n");
			getchar();
			contador++;
		}

	} while (ingresa == 0 && contador < 3);

	if (ingresa == 0) {
      printf("\n\tVerifique su Usuario y Password\n");
   } else {
   	printf("\n\n\tBienvenido al sistema\n");
   }
    getchar();
   system("cls");


int op;

do{
      system("cls");
      gotoxy(25,4);  printf("SISTEMA DE ADMINISTRACION DE CLINICA SAN LUCAS");
      gotoxy(25,5);  printf("______________________________________________");
      gotoxy(19,8);  printf("1-Seguridad");
		gotoxy(33,8);  printf("2-Pacientes");
		gotoxy(47,8);  printf("3-Medicos");
		gotoxy(58,8);  printf("4-Consultas");
		gotoxy(71,8); printf("5-Citas");
		gotoxy(38,13);	printf("INGRESE LA OPCION: ");
      fxrectangulo(1,18,35,18,YELLOW);

   //fxrectangulo(2,19,35,25,BLUE);
   //gotoxy(4,21);  printf("medicos");
   //fxrectangulo(38,19,73,25,BLUE);
   //gotoxy(40,21);  printf("pacientes");



      op = fxtecla();

switch(op){

	case '1':
            seguridad();
	         break;

	case '2':
            Pacientes();
	         break;

	case '3':
            medicos();
	         break;

	case '4':
            consultas();
	         break;
	case '5':
            citas();
         	break;








}

}while(op != ESC);
return 0;








}

void seguridad(){

int opcion;//variable para capturar tecla

	ptrnodolista ptrInicio = NULL;
	ptrnodolista ptrActual = NULL;
	nodolista datosseguridad;
	FILE *ptrArchivo;

	int i=0;
   interfazseg();
	ptrArchivo = fopen("seguridad.dat", "rb");
	if(ptrArchivo != NULL){
		fread(&datosseguridad, sizeof(nodolista), 1, ptrArchivo);
		while(! feof(ptrArchivo)){
			insertar(&ptrInicio, &datosseguridad);
			fread(&datosseguridad, sizeof(nodolista), 1, ptrArchivo);
		}
		ptrActual = ptrInicio;
		VerLista(ptrInicio, ptrActual);
		if(ptrActual != NULL){
			MostrarDatos(ptrActual);
		}
		fclose(ptrArchivo);
	}


  do{
  MarcarItem(ptrActual, i);

  opcion = fxtecla();

  switch(opcion){
			case F1:
				gotoxy(11,17);	clreol();
                gotoxy(11,17);gets(datosseguridad.Nombre);
				flushall();
				gotoxy(17,24);	clreol();
				gotoxy(13,20);	gets(datosseguridad.apellido);
				flushall();
				gotoxy(44,20);	clreol();
				gotoxy(15,23);	gets(datosseguridad.genero);
				flushall();
				insertar(&ptrInicio, &datosseguridad);
				ptrActual = ptrInicio;
				VerLista(ptrInicio, ptrActual);
				i=0;
				break;
			case F2:			// Editar
				if(ptrActual != NULL){
					flushall();
					gotoxy(17,6); 	gets(ptrActual->Nombre);
                    gotoxy(17,29);
					gotoxy(17,29); 	gets(ptrActual->apellido);
                    gotoxy(44,20);
					gotoxy(67,20); 	gets(ptrActual->genero);
					gotoxy(46,22);
					flushall();
					VerLista(ptrInicio, ptrActual);
				}

				break;
			case F3:			// Eliminar
				gotoxy(37, 24);	printf("Ingrese el ID a eliminar: ");

				scanf("%d", &datosseguridad.Nombre);
				eliminar(&ptrInicio, &datosseguridad);
				ptrActual = ptrInicio;
				interfazseg();
				VerLista(ptrInicio, ptrActual);
				i=0;
				break;
			case FARR:			// Arriba
				if(i > 0){
					DesmarcarItem(ptrActual, i);
					i--;
					ptrActual = ptrActual->ptrAnterior;
					MostrarDatos(ptrActual);
				}
				break;
			case FABA:			// Abajo
				if(i < 15 && ptrActual->ptrSiguiente != NULL){
					DesmarcarItem(ptrActual, i);
					i++;
					ptrActual = ptrActual->ptrSiguiente;
					MostrarDatos(ptrActual);
				}
				break;
		}

  }while(opcion != ESC);
	ptrArchivo = fopen("seguridad.dat", "wb");
	if(ptrArchivo != NULL){
		ptrActual = ptrInicio;
		while(ptrActual != NULL){
			fwrite(ptrActual, sizeof(nodolista), 1, ptrArchivo);
			ptrActual = ptrActual->ptrSiguiente;
		}
		fclose(ptrArchivo);
	}
}


void interfazseg()
{
   system("cls");
   fxrectangulo(56,2,66,4,RED);
   fxrectangulo(33,5,65,15,GREEN);
   fxrectangulo(66,5,79,15,GREEN);
   fxrectangulo(4,5,32,15,GREEN);
   gotoxy(35,3);printf("\t\t\tSeguridad\n");
   gotoxy(5,6);printf("        Login");
   gotoxy(34,6);printf("       Nombre Completo");
   gotoxy(67,6);printf("    Nivel");
   fxrectangulo(4,16,65,18,WHITE);
   gotoxy(5,17); printf("Login:");
   fxrectangulo(4,19,65,21,WHITE);
   gotoxy(5,20); printf("Nombre:");
   fxrectangulo(4,22,65,24,RED);
   gotoxy(5,23); printf("Password:");
   gotoxy(7,27); printf("F1-Insertar   F2-Editar   F3-Eliminar   ESC-Salir");
}

void MarcarItemseg(ptrnodolista ptrActual, int fila)
{
	if(ptrActual != NULL){
		gotoxy(6,7+fila);
		textbackground(YELLOW);
		textcolor(WHITE);
		cprintf("%c %d %10s ", 16, ptrActual->ID,ptrActual->Nombre,
      ptrActual->genero);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
	}
}

void VerListaseg(ptrnodolista ptrInicio, ptrnodolista ptrActual)
{
	ptrnodolista ptrmover = ptrInicio;
	int fila = 0;
	ptrmover = ptrInicio;
	while(ptrmover != NULL){
		gotoxy(6,7+fila);
		if(ptrmover == ptrActual){
			textbackground(YELLOW);
			textcolor(WHITE);
			cprintf("%c %d %10s", 1, ptrmover->ID,
				ptrmover->Nombre,ptrmover->genero);
			textbackground(BLACK);
			textcolor(LIGHTGRAY);
		}
		else{
			gotoxy(3,4+fila);
			printf("%1d %-30s", ptrmover->ID,
				ptrmover->Nombre);
		}
		fila++;
		ptrmover = ptrmover->ptrSiguiente;
	}
}

void DesmarcarItemseg(ptrnodolista ptrActual, int fila)
{
	if(ptrActual != NULL){
		gotoxy(3,4+fila);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
		cprintf("  %d %10s ", ptrActual->ID, ptrActual->Nombre);
	}
}
void MostrarDatosseg(ptrnodolista ptrActual)
{
	gotoxy(34,6);	printf("%s", ptrActual->Nombre); clreol();
	gotoxy(34,6);	printf("%s", ptrActual->apellido); clreol();
	gotoxy(44,6);	printf("%s", ptrActual->genero); clreol();
	gotoxy(46,6);	printf("d", ptrActual->telefono);	 clreol();

   }

///////////////////////////////////////////////////////////////////////////////
/******************************Pacientes**************************************/
///////////////////////////////////////////////////////////////////////////////

void Pacientes(){

int opcion;//variable para capturar tecla

	ptrnodolista ptrInicio = NULL;
	ptrnodolista ptrActual = NULL;
	nodolista datospacientes;
	FILE *ptrArchivo;

	int i=0;
   interfaz();
	ptrArchivo = fopen("pacientes.dat", "rb");
	if(ptrArchivo != NULL){
		fread(&datospacientes, sizeof(nodolista), 1, ptrArchivo);
		while(! feof(ptrArchivo)){
			insertar(&ptrInicio, &datospacientes);
			fread(&datospacientes, sizeof(nodolista), 1, ptrArchivo);
		}
		ptrActual = ptrInicio;
		VerLista(ptrInicio, ptrActual);
		if(ptrActual != NULL){
			MostrarDatos(ptrActual);
		}
		fclose(ptrArchivo);
	}


  do{
  MarcarItem(ptrActual, i);

  opcion = fxtecla();

  switch(opcion){
			case F1:// Insertar
                gotoxy(11,20);	printf("[                ]");
				gotoxy(11,20);	scanf("%d", &datospacientes.ID);
				flushall();
				gotoxy(15,22);	clreol();
				gotoxy(15,22);	gets(datospacientes.Nombre);
				flushall();
				gotoxy(17,24);	clreol();
				gotoxy(17,24);	gets(datospacientes.apellido);
				flushall();
				gotoxy(44,20);	clreol();
				gotoxy(44,20);	gets(datospacientes.genero);
				flushall();
				gotoxy(46,22);	clreol();
				gotoxy(46,22);	scanf("%d", &datospacientes.telefono);
				flushall();
				insertar(&ptrInicio, &datospacientes);
				ptrActual = ptrInicio;
				VerLista(ptrInicio, ptrActual);
				i=0;
				break;
			case F2:			// Editar
				if(ptrActual != NULL){
					flushall();
					gotoxy(11,20);	clreol();
					gotoxy(11,20);	scanf("%d", &ptrActual->ID);
					flushall();
					gotoxy(15,22);	clreol();
					gotoxy(15,22); 	gets(ptrActual->Nombre);
                    gotoxy(17,24);	clreol();
					gotoxy(17,24); 	gets(ptrActual->apellido);
                    gotoxy(44,20);	clreol();
					gotoxy(44,20); 	gets(ptrActual->genero);
					gotoxy(46,22);	clreol();
					gotoxy(46,22);	scanf("%f", &ptrActual->telefono);
					flushall();
					VerLista(ptrInicio, ptrActual);
				}

				break;
			case F3:			// Eliminar
				gotoxy(37, 24);	printf("Ingrese el ID a eliminar: ");

				scanf("%d", &datospacientes.ID);
				eliminar(&ptrInicio, &datospacientes);
				ptrActual = ptrInicio;
				interfaz();
				VerLista(ptrInicio, ptrActual);
				i=0;
				break;
			case FARR:			// Arriba
				if(i > 0){
					DesmarcarItem(ptrActual, i);
					i--;
					ptrActual = ptrActual->ptrAnterior;
					MostrarDatos(ptrActual);
				}
				break;
			case FABA:			// Abajo
				if(i < 15 && ptrActual->ptrSiguiente != NULL){
					DesmarcarItem(ptrActual, i);
					i++;
					ptrActual = ptrActual->ptrSiguiente;
					MostrarDatos(ptrActual);
				}
				break;
		}

  }while(opcion != ESC);
	ptrArchivo = fopen("pacientes.dat", "wb");
	if(ptrArchivo != NULL){
		ptrActual = ptrInicio;
		while(ptrActual != NULL){
			fwrite(ptrActual, sizeof(nodolista), 1, ptrArchivo);
			ptrActual = ptrActual->ptrSiguiente;
		}
		fclose(ptrArchivo);
	}
}

void interfaz()
{
   system("cls");
   fxrectangulo(36,1,73,3,BLUE);
   gotoxy(5,2); printf("NOMBRE PARA BUSCAR EL PACIENTE:");
   fxrectangulo(4,4,73,18,GREEN);
   gotoxy(5,5); printf("ID:");
   gotoxy(20,5); printf("NOMBRE:");
   gotoxy(37,5); printf("GENERO:");
   gotoxy(8,20); printf("ID:");
   gotoxy(8,22); printf("NOMBRE:");
   gotoxy(8,24); printf("APELLIDO:");
   gotoxy(37,20); printf("GENERO:");
   gotoxy(37,22); printf("TELEFONO:");
 gotoxy(8,30); printf("F1-Insertar   F2-Editar    F3-Eliminar    ESC-Regresar");
}

void MarcarItem(ptrnodolista ptrActual, int fila)
{
	if(ptrActual != NULL){
		gotoxy(6,7+fila);
		textbackground(YELLOW);
		textcolor(WHITE);
		cprintf("%c %d %10s ", 16, ptrActual->ID,ptrActual->Nombre,
      ptrActual->genero);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
	}
}

void VerLista(ptrnodolista ptrInicio, ptrnodolista ptrActual)
{
	ptrnodolista ptrmover = ptrInicio;
	int fila = 0;
	ptrmover = ptrInicio;
	while(ptrmover != NULL){
		gotoxy(6,7+fila);
		if(ptrmover == ptrActual){
			textbackground(YELLOW);
			textcolor(WHITE);
			cprintf("%c %d %10s", 1, ptrmover->ID,
				ptrmover->Nombre,ptrmover->genero);
			textbackground(BLACK);
			textcolor(LIGHTGRAY);
		}
		else{
			gotoxy(3,4+fila);
			printf("%1d %-30s", ptrmover->ID,
				ptrmover->Nombre);
		}
		fila++;
		ptrmover = ptrmover->ptrSiguiente;
	}
}

void DesmarcarItem(ptrnodolista ptrActual, int fila)
{
	if(ptrActual != NULL){
		gotoxy(3,4+fila);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
		cprintf("  %d %10s ", ptrActual->ID, ptrActual->Nombre);
	}
}
void MostrarDatos(ptrnodolista ptrActual)
{
	gotoxy(11,20);	printf("%d", ptrActual->ID);	 clreol();
	gotoxy(15,22);	printf("%s", ptrActual->Nombre); clreol();
	gotoxy(17,24);	printf("%s", ptrActual->apellido); clreol();
	gotoxy(44,20);	printf("%s", ptrActual->genero); clreol();
	gotoxy(46,22);	printf("d", ptrActual->telefono);	 clreol();

   }


//*********************************************************************
//***************************Para medicos******************************
//*********************************************************************

void medicos(){

int opcion;//variable para capturar tecla

	ptrnodolista ptrInicio = NULL;
	ptrnodolista ptrActual = NULL;
	nodolista datosmedicos;
	FILE *ptrArchivo;

	int i=0;
   interfazMed();
	ptrArchivo = fopen("medicos.dat", "rb");
	if(ptrArchivo != NULL){
		fread(&datosmedicos, sizeof(nodolista), 1, ptrArchivo);
		while(! feof(ptrArchivo)){
			insertar(&ptrInicio, &datosmedicos);
			fread(&datosmedicos, sizeof(nodolista), 1, ptrArchivo);
		}
		ptrActual = ptrInicio;
		VerLista(ptrInicio, ptrActual);
		if(ptrActual != NULL){
			MostrarDatos(ptrActual);
		}
		fclose(ptrArchivo);
	}


  do{
  MarcarItem(ptrActual, i);

  opcion = fxtecla();

  switch(opcion){
			case F1:// Insertar
                gotoxy(11,20);	printf("[                ]");
				gotoxy(11,20);	scanf("%d", &datosmedicos.Nombre);
				flushall();
				gotoxy(15,22);	clreol();
				gotoxy(15,22);	gets(datosmedicos.Nombre);
				flushall();
				gotoxy(17,24);	clreol();
				gotoxy(17,24);	gets(datosmedicos.apellido);
				flushall();
				gotoxy(44,20);	clreol();
				gotoxy(44,20);	gets(datosmedicos.genero);
				flushall();
				gotoxy(46,22);	clreol();
				gotoxy(46,22);	scanf("%d", &datosmedicos.telefono);
				flushall();
				insertar(&ptrInicio, &datosmedicos);
				ptrActual = ptrInicio;
				VerLista(ptrInicio, ptrActual);
				i=0;
				break;
			case F2:			// Editar
				if(ptrActual != NULL){
					flushall();
					gotoxy(11,20);
					gotoxy(11,20);	scanf("%d", &ptrActual->ID);
					flushall();
					gotoxy(15,22);
					gotoxy(15,22); 	gets(ptrActual->Nombre);
                    gotoxy(17,29);
					gotoxy(17,29); 	gets(ptrActual->apellido);
                    gotoxy(44,20);
					gotoxy(67,20); 	gets(ptrActual->genero);
					gotoxy(46,22);
					gotoxy(46,22);	scanf("%f", &ptrActual->telefono);
					flushall();
					VerLista(ptrInicio, ptrActual);
				}

				break;
			case F3:			// Eliminar
				gotoxy(37, 24);	printf("Ingrese el ID a eliminar: ");

				scanf("%d", &datosmedicos.ID);
				eliminar(&ptrInicio, &datosmedicos);
				ptrActual = ptrInicio;
				interfazMed();
				VerLista(ptrInicio, ptrActual);
				i=0;
				break;
			case FARR:			// Arriba
				if(i > 0){
					DesmarcarItem(ptrActual, i);
					i--;
					ptrActual = ptrActual->ptrAnterior;
					MostrarDatos(ptrActual);
				}
				break;
			case FABA:			// Abajo
				if(i < 15 && ptrActual->ptrSiguiente != NULL){
					DesmarcarItem(ptrActual, i);
					i++;
					ptrActual = ptrActual->ptrSiguiente;
					MostrarDatos(ptrActual);
				}
				break;
		}

  }while(opcion != ESC);
	ptrArchivo = fopen("medicos.dat", "wb");
	if(ptrArchivo != NULL){
		ptrActual = ptrInicio;
		while(ptrActual != NULL){
			fwrite(ptrActual, sizeof(nodolista), 1, ptrArchivo);
			ptrActual = ptrActual->ptrSiguiente;
		}
		fclose(ptrArchivo);
	}
}

void interfazMed()
{
   system("cls");
   fxrectangulo(31,1,73,3,BLUE);
   gotoxy(5,2); printf("NOMBRE PARA BUSCAR MEDICO:");
   fxrectangulo(4,4,73,18,YELLOW);
   gotoxy(5,5); printf("ID:");
   gotoxy(20,5); printf("NOMBRE:");
   gotoxy(37,5); printf("GENERO:");
   gotoxy(8,20); printf("ID:");
   gotoxy(8,22); printf("NOMBRE:");
   gotoxy(8,24); printf("APELLIDO:");
   gotoxy(37,20); printf("GENERO:");
   gotoxy(37,22); printf("TELEFONO:");
 gotoxy(8,30); printf("F1-Insertar   F2-Editar    F3-Eliminar    ESC-Regresar");
}

void MarcarItemMed(ptrnodolista ptrActual, int fila)
{
	if(ptrActual != NULL){
		gotoxy(6,7+fila);
		textbackground(YELLOW);
		textcolor(WHITE);
		cprintf("%c %d %10s ", 16, ptrActual->ID,ptrActual->Nombre,
      ptrActual->genero);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
	}
}

void VerListaMed(ptrnodolista ptrInicio, ptrnodolista ptrActual)
{
	ptrnodolista ptrmover = ptrInicio;
	int fila = 0;
	ptrmover = ptrInicio;
	while(ptrmover != NULL){
		gotoxy(6,7+fila);
		if(ptrmover == ptrActual){
			textbackground(YELLOW);
			textcolor(WHITE);
			cprintf("%c %d %10s", 1, ptrmover->ID,
				ptrmover->Nombre,ptrmover->genero);
			textbackground(BLACK);
			textcolor(LIGHTGRAY);
		}
		else{
			gotoxy(3,4+fila);
			printf("%1d %-30s", ptrmover->ID,
				ptrmover->Nombre);
		}
		fila++;
		ptrmover = ptrmover->ptrSiguiente;
	}
}

void DesmarcarItemMed(ptrnodolista ptrActual, int fila)
{
	if(ptrActual != NULL){
		gotoxy(3,4+fila);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
		cprintf("  %d %10s ", ptrActual->ID, ptrActual->Nombre);
	}
}
void MostrarDatosMed(ptrnodolista ptrActual)
{
	gotoxy(11,20);	printf("%d", ptrActual->ID);
	gotoxy(15,22);	printf("%s", ptrActual->Nombre);
	gotoxy(17,24);	printf("%s", ptrActual->apellido);
	gotoxy(44,20);	printf("%s", ptrActual->genero);
	gotoxy(46,22);	printf("d", ptrActual->telefono);

   }
///////////////////////////////////////////////////////////////////////////////////////////
//******************************Citas******************************************************
///////////////////////////////////////////////////////////////////////////////////////////
void citas(){

int opcion;//variable para capturar tecla

	ptrnodolista ptrInicio = NULL;
	ptrnodolista ptrActual = NULL;
	nodolista datoscitas;
	FILE *ptrArchivo;

	int i=0;
   interfazcitas();
	ptrArchivo = fopen("citas.dat", "rb");
	if(ptrArchivo != NULL){
		fread(&datoscitas, sizeof(nodolista), 1, ptrArchivo);
		while(! feof(ptrArchivo)){
			insertar(&ptrInicio, &datoscitas);
			fread(&datoscitas, sizeof(nodolista), 1, ptrArchivo);
	 	}
		ptrActual = ptrInicio;
		if(ptrActual != NULL){
		 	MostrarDatos(ptrActual);
		}
		fclose(ptrArchivo);
  	}


  do{
  MarcarItem(ptrActual, i);

  opcion = fxtecla();

  switch(opcion){
			case F1:// Insertar
				gotoxy(15,22);	clreol();
				gotoxy(14,5);gets(datoscitas.Nombre);
				flushall();
				gotoxy(17,24);	clreol();
				gotoxy(30,8);gets(datoscitas.apellido);
				flushall();
				gotoxy(25,11);	gets(datoscitas.genero);
				flushall();
            gotoxy(46,14);	scanf("%d", &datoscitas.telefono);
				flushall();
				insertar(&ptrInicio, &datoscitas);
				ptrActual = ptrInicio;
				i=0;
				break;
			case F2:			// Editar
				if(ptrActual != NULL){
					gotoxy(14,5);
					gotoxy(14,5);gets(ptrActual->Nombre);
               gotoxy(30,8);
					gotoxy(30,8);gets(ptrActual->apellido);
               gotoxy(25,11);
					gotoxy(25,11);gets(ptrActual->genero);
					gotoxy(46,14);
					gotoxy(46,14);	scanf("%f", &ptrActual->telefono);
					flushall();
				}

		}

  }while(opcion != ESC);
	ptrArchivo = fopen("citas.dat", "wb");
	if(ptrArchivo != NULL){
		ptrActual = ptrInicio;
		while(ptrActual != NULL){
			fwrite(ptrActual, sizeof(nodolista), 1, ptrArchivo);
			ptrActual = ptrActual->ptrSiguiente;
		}
		fclose(ptrArchivo);
	}

   }

   void interfazcitas()
{
   system("cls");
   fxrectangulo(4,1,73,3,BLUE);
   gotoxy(5,2); printf("Citas");
   fxrectangulo(4,3,73,20,WHITE);
   fxrectangulo(13,4,55,6,WHITE);
   gotoxy(7,5); printf("Doctor");
   fxrectangulo(29,7,55,9,WHITE);
   gotoxy(7,8); printf("Identidad del Paciente");
   fxrectangulo(23,10,55,12,WHITE);
   gotoxy(7,11); printf("Fecha de la Cita");
   fxrectangulo(45,13,55,15,WHITE);
   gotoxy(7,14); printf("Su cita estara Programada para la hora");
   gotoxy(8,22); printf("F1-Insertar    F2-Editar    F3-Eliminar     ESC-Regresar");
}





////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Consultas//////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void consultas(){

int opcion;//variable para capturar tecla

	ptrnodolista ptrInicio = NULL;
	ptrnodolista ptrActual = NULL;
	nodolista datosconsultas;
	FILE *ptrArchivo;

	int i=0;
   interfazCon();
	ptrArchivo = fopen("consultas.dat", "rb");
	if(ptrArchivo != NULL){
		fread(&datosconsultas, sizeof(nodolista), 1, ptrArchivo);
		while(! feof(ptrArchivo)){
			insertar(&ptrInicio, &datosconsultas);
			fread(&datosconsultas, sizeof(nodolista), 1, ptrArchivo);
		}
		ptrActual = ptrInicio;
		VerLista(ptrInicio, ptrActual);
		if(ptrActual != NULL){
			MostrarDatos(ptrActual);
		}
		fclose(ptrArchivo);
	}


  do{
  MarcarItem(ptrActual, i);

  opcion = fxtecla();

  switch(opcion){
			case F1:// Insertar
                gotoxy(40,2);	printf("[                ]");
				gotoxy(41,2);	scanf("%d", &datosconsultas.Nombre);
				flushall();
				gotoxy(67,2);	gets(datosconsultas.genero);
				flushall();
				gotoxy(15,22);	clreol();
				gotoxy(18,14);	gets(datosconsultas.Nombre);
				flushall();
				gotoxy(24,19);	clreol();
				gotoxy(21,19);	gets(datosconsultas.apellido);
				flushall();
				insertar(&ptrInicio, &datosconsultas);
				ptrActual = ptrInicio;
				VerLista(ptrInicio, ptrActual);
				i=0;
				break;
			case F2:			// Editar
				if(ptrActual != NULL){
					flushall();
					gotoxy(11,20);	clreol();
					gotoxy(11,20);	scanf("%d", &ptrActual->ID);
					flushall();
					gotoxy(15,22);	clreol();
					gotoxy(15,22); 	gets(ptrActual->Nombre);
                    gotoxy(17,29);	clreol();
					gotoxy(17,29); 	gets(ptrActual->apellido);
                    gotoxy(44,20);	clreol();
					gotoxy(67,20); 	gets(ptrActual->genero);
					gotoxy(46,22);	clreol();
					gotoxy(46,22);	scanf("%f", &ptrActual->telefono);
					flushall();
					VerLista(ptrInicio, ptrActual);
				}

				break;
			case F3:			// Eliminar
				gotoxy(37, 24);	printf("Ingrese el ID a eliminar: ");

				scanf("%d", &datosconsultas.ID);
				eliminar(&ptrInicio, &datosconsultas);
				ptrActual = ptrInicio;
				interfazCon();
				VerLista(ptrInicio, ptrActual);
				i=0;
				break;
			case FARR:			// Arriba
				if(i > 0){
					DesmarcarItem(ptrActual, i);
					i--;
					ptrActual = ptrActual->ptrAnterior;
					MostrarDatos(ptrActual);
				}
				break;
			case FABA:			// Abajo
				if(i < 15 && ptrActual->ptrSiguiente != NULL){
					DesmarcarItem(ptrActual, i);
					i++;
					ptrActual = ptrActual->ptrSiguiente;
					MostrarDatos(ptrActual);
				}
				break;
		}

  }while(opcion != ESC);
	ptrArchivo = fopen("consultas.dat", "wb");
	if(ptrArchivo != NULL){
		ptrActual = ptrInicio;
		while(ptrActual != NULL){
			fwrite(ptrActual, sizeof(nodolista), 1, ptrArchivo);
			ptrActual = ptrActual->ptrSiguiente;
		}
		fclose(ptrArchivo);
	}
}

void interfazCon()
{
   system("cls");
   gotoxy(5,2); printf("NOMBRE DEL PACIENTE A SER ATENDIDO");
   fxrectangulo(4,4,73,12,WHITE);
   gotoxy(5,5); printf("Historial Medico:");
   gotoxy(5,6); printf("Fecha:");
   gotoxy(20,6); printf("Diagnostico:");
   gotoxy(38,6); printf("Receta Medica:");
   fxrectangulo(4,13,73,17,WHITE);
   gotoxy(5,14); printf("Diagnostico:");
   gotoxy(39,2); printf(":");
   //gotoxy(8,24); printf("APELLIDO:");
   gotoxy(60,2); printf("GENERO:");
   fxrectangulo(4,18,73,22,WHITE);
   gotoxy(5,19); printf("Receta Medica:");

    gotoxy(8,30); printf("F1-Insertar    F2-Editar    F3-Eliminar     ESC-Regresar");

}

