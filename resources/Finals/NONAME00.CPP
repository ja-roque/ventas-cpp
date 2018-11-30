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
void consultas();
void medicos();
void interfazMed();
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
      gotoxy(35,2);printf("\t\t\t******************\n");
		gotoxy(35,3);printf("\t\t\t|INICIO DE SESION|\n");
		gotoxy(35,4);printf("\t\t\t******************\n");
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
      gotoxy(35,3);  printf("//////////////////////////////////////////////////");
      gotoxy(35,4);  printf("| SISTEMA DE ADMINISTRACION DE CLINICA SAN LUCAS |");
      gotoxy(35,5);  printf("//////////////////////////////////////////////////");
      gotoxy(29,7);  printf("1-Seguridad");
		gotoxy(43,7);  printf("2-Pacientes");
		gotoxy(57,7);  printf("3-Medicos");
		gotoxy(68,7);  printf("4-Consultas");
		gotoxy(81,7); printf("5-Citas");
		gotoxy(48,13);	printf("INGRESE LA OPCION: ");

op = fxtecla();

switch(op){

	case '1':
            Pacientes();
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
   gotoxy(5,2); printf("NOMBRE PARA BUSCAR EL PACIENTE:");
   fxrectangulo(4,4,73,18,WHITE);
   gotoxy(5,5); printf("ID:");
   gotoxy(20,5); printf("NOMBRE:");
   gotoxy(37,5); printf("GENERO:");
   gotoxy(8,20); printf("ID:");
   gotoxy(8,22); printf("NOMBRE:");
   gotoxy(8,24); printf("APELLIDO:");
   gotoxy(37,20); printf("GENERO:");
   gotoxy(37,22); printf("TELEFONO:");
 gotoxy(8,30); printf("F1-Insertar F2-Editar F3-Eliminar ESC-Regresar");
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
//Para medicos
//**********************************************************************

void medicos(){

int opcion;//variable para capturar tecla

	ptrnodolista ptrInicio = NULL;
	ptrnodolista ptrActual = NULL;
	nodolista datosconsultas;
	FILE *ptrArchivo;

	int i=0;
   interfazMed();
	ptrArchivo = fopen("medicos.dat", "rb");
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
				gotoxy(15,22);	clreol();
				gotoxy(15,22);	gets(datosconsultas.Nombre);
				flushall();
				gotoxy(17,24);	clreol();
				gotoxy(17,24);	gets(datosconsultas.apellido);
				flushall();
				gotoxy(44,20);	clreol();
				gotoxy(67,2);	gets(datosconsultas.genero);
				flushall();
				gotoxy(46,22);	clreol();
				gotoxy(46,22);	scanf("%d", &datosconsultas.telefono);
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

void interfazMed()
{
   system("cls");
   gotoxy(5,2); printf("NOMBRE DEL PACIENTE A SER ATENDIDO");
  // fxrectangulo(4,4,73,18,WHITE);
   gotoxy(5,10); printf("Historial Medico:");
   gotoxy(5,11); printf("Fecha:");
   gotoxy(20,11); printf("Diagnostico:");
   gotoxy(37,11); printf("Receta Medica:");
   gotoxy(8,20); printf("Diagnostico:");
   gotoxy(39,2); printf(":");
   //gotoxy(8,24); printf("APELLIDO:");
   gotoxy(60,2); printf("GENERO:");
   gotoxy(8,25); printf("Receta Medica:");

    gotoxy(8,30); printf("F1-Insertar F2-Editar F3-Eliminar ESC-Regresar");
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
void citas(){

int opcion;//variable para capturar tecla

	ptrnodolista ptrInicio = NULL;
	ptrnodolista ptrActual = NULL;
	nodolista datospacientes;
	FILE *ptrArchivo;

	int i=0;
   interfaz();
   gotoxy(8,30); printf("F1-Insertar F2-Editar F3-Eliminar ESC-Regresar");
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


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
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
				gotoxy(15,22);	clreol();
				gotoxy(15,22);	gets(datosconsultas.Nombre);
				flushall();
				gotoxy(17,24);	clreol();
				gotoxy(17,24);	gets(datosconsultas.apellido);
				flushall();
				gotoxy(44,20);	clreol();
				gotoxy(67,2);	gets(datosconsultas.genero);
				flushall();
				gotoxy(46,22);	clreol();
				gotoxy(46,22);	scanf("%d", &datosconsultas.telefono);
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
  // fxrectangulo(4,4,73,18,WHITE);
   gotoxy(5,10); printf("Historial Medico:");
   gotoxy(5,11); printf("Fecha:");
   gotoxy(20,11); printf("Diagnostico:");
   gotoxy(37,11); printf("Receta Medica:");
   gotoxy(8,20); printf("Diagnostico:");
   gotoxy(39,2); printf(":");
   //gotoxy(8,24); printf("APELLIDO:");
   gotoxy(60,2); printf("GENERO:");
   gotoxy(8,25); printf("Receta Medica:");

    gotoxy(8,30); printf("F1-Insertar F2-Editar F3-Eliminar ESC-Regresar");

}

