#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
#include <time.h>
#include "C:\Users\Luis Montalvan\Desktop\Proyectondfjbsdvfjb\includes\figuras.h"
#include "C:\Users\Luis Montalvan\Desktop\Proyectondfjbsdvfjb\includes\teclado.h"
#include "C:\Users\Luis Montalvan\Desktop\Proyectondfjbsdvfjb\includes\controles.h"
#include "C:\Users\Luis Montalvan\Desktop\Proyectondfjbsdvfjb\includes\listapacientes.h"

void Pacientes();
void interfaz();
void MarcarItem(ptrnodolista ptrActual, int fila);
void VerLista(ptrnodolista ptrInicio, ptrnodolista ptrActual);
void DesmarcarItem(ptrnodolista ptrActual, int fila);
void MostrarDatos(ptrnodolista ptrActual);

int main(){
	
int op;

do{
      system("cls");
      gotoxy(16,5);  printf("SISTEMA DE ADMINISTRACION DE CLINICA SAN LUCAS");
      gotoxy(27,6);  printf("1-Seguridad");
		gotoxy(27,7);  printf("2-Pacientes");
		gotoxy(27,8);  printf("3-Medicos");
		gotoxy(27,9);  printf("4-Consultas");
		gotoxy(27,10); printf("5-Citas");
		gotoxy(27,13);	printf("INGRESE LA OPCION: ");
		
op = fxtecla();

switch(op){

	case '1':
   Pacientes();
	break;

	case '2':
   Pacientes();
	break;
   /*
	case '3':		

	break;
	
	case '4':		
			
	break;
	case '5':		
			
	break;
  */
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

/**********************************************************************
Para medicos
**********************************************************************/

void medicos(){

int opcion;//variable para capturar tecla

	ptrnodolista2 ptrInicio2 = NULL;
	ptrnodolista2 ptrActual2 = NULL;
	nodolista2 datosmedicos;
	FILE *ptrArchivo;

	int i=0;
   interfaz2();
	ptrArchivo2 = fopen("pacientes.dat", "rb");
	if(ptrArchivo != NULL){
		fread(&datosmedicos, sizeof(nodolista2), 1, ptrArchivo);
		while(! feof(ptrArchivo)){
			insertar2(&ptrInicio2, &datosmedicos);
			fread(&datosmedicos, sizeof(nodolista2), 1, ptrArchivo);
		}
		ptrActual2 = ptrInicio2;
		VerLista2(ptrInicio2, ptrActual2);
		if(ptrActual2 != NULL){
			MostrarDatos2(ptrActual2);
		}
		fclose(ptrArchivo);
	}	
	

  do{
  MarcarItem2(ptrActual2, i);
	
  opcion = fxtecla();
  
  switch(opcion){
			case F1:// Insertar
                gotoxy(11,20);	printf("[                ]");
				gotoxy(11,20);	scanf("%d", &datosmedicos.ID);
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
				insertar(&ptrInicio2, &datosmedicos);
				ptrActual = ptrInicio;			
				VerLista2(ptrInicio2, ptrActual2);
				i=0;
				break;
			case F2:			// Editar
				if(ptrActual2 != NULL){
					flushall();
					gotoxy(11,20);	clreol();
					gotoxy(11,20);	scanf("%d", &ptrActual2->ID);
					flushall();
					gotoxy(15,22);	clreol();
					gotoxy(15,22); 	gets(ptrActual2->Nombre);
                    gotoxy(17,24);	clreol();
					gotoxy(17,24); 	gets(ptrActual2->apellido);
                    gotoxy(44,20);	clreol();
					gotoxy(44,20); 	gets(ptrActual2->genero);
					gotoxy(46,22);	clreol();
					gotoxy(46,22);	scanf("%f", &ptrActual2->telefono);
					flushall();
					VerLista2(ptrInicio2, ptrActual2);
				}
				
				break;
			case F3:			// Eliminar
				gotoxy(37, 24);	printf("Ingrese el ID a eliminar: ");
				
				scanf("%d", &datosmedicos.ID);
				eliminar2(&ptrInicio2, &datosmedicos);
				ptrActual2 = ptrInicio2;
				interfaz2();
				VerLista2(ptrInicio2, ptrActual2);
				i=0;
				break;
			case FARR:			// Arriba
				if(i > 0){
					DesmarcarItem2(ptrActual2, i);
					i--;
					ptrActual2 = ptrActual2->ptrAnterior2;
					MostrarDatos2(ptrActual2);
				}
				break;
			case FABA:			// Abajo
				if(i < 15 && ptrActual2->ptrSiguiente2 != NULL){
					DesmarcarItem2(ptrActual2, i);
					i++;
					ptrActual2 = ptrActual2->ptrSiguiente2;
					MostrarDatos2(ptrActual2);
				}
				break; 
		}
  
  }while(opcion != ESC);
	ptrArchivo = fopen("medicos.dat", "wb");
	if(ptrArchivo != NULL){
		ptrActual2 = ptrInicio2;
		while(ptrActual2 != NULL){
			fwrite(ptrActual2, sizeof(nodolista2), 1, ptrArchivo);
			ptrActual2 = ptrActual2->ptrSiguiente2;
		}
		fclose(ptrArchivo);
	}
}

void interfaz2()
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
   gotoxy(37,24); printf("ESPECIALIDAD:");

}

void MarcarItem2(ptrnodolista2 ptrActual2, int fila2)
{
	if(ptrActual2 != NULL){
		gotoxy(6,7+fila2);
		textbackground(YELLOW);
		textcolor(WHITE);
		cprintf("%c %d %10s ", 16, ptrActual2->ID,ptrActual2->Nombre,
      ptrActual2->genero);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
	}
}

void VerLista2ptrnodolista2 ptrInicio2, ptrnodolista2 ptrActual2)
{
	ptrnodolista2 ptrmover2 = ptrInicio2;
	int fila2 = 0;
	ptrmover2 = ptrInicio2;
	while(ptrmover2 != NULL){
		gotoxy(6,7+fila2);
		if(ptrmover2 == ptrActual2){
			textbackground(YELLOW);
			textcolor(WHITE);
			cprintf("%c %d %10s", 1, ptrmover2->ID,
				ptrmover2->Nombre,ptrmover2->genero);
			textbackground(BLACK);
			textcolor(LIGHTGRAY);
		}
		else{
			gotoxy(3,4+fila);
			printf("%1d %-30s", ptrmover->ID,
				ptrmover2->Nombre);
		}
		fila++;
		ptrmover2 = ptrmover2->ptrSiguiente2;
	}
}

void DesmarcarItem2(ptrnodolista2 ptrActual2, int fila2)
{
	if(ptrActual2 != NULL){
		gotoxy(3,4+fila2);
		textbackground(BLACK);
		textcolor(LIGHTGRAY);
		cprintf("  %d %10s ", ptrActual2->ID, ptrActual2->Nombre);
	}
}
void MostrarDatos2(ptrnodolista2 ptrActual2)
{
	gotoxy(11,20);	printf("%d", ptrActual2->ID);	 clreol();
	gotoxy(15,22);	printf("%s", ptrActual2->Nombre); clreol();
	gotoxy(17,24);	printf("%s", ptrActual2->apellido); clreol();
	gotoxy(44,20);	printf("%s", ptrActual2->genero); clreol();
	gotoxy(46,22);	printf("d", ptrActual2->telefono);	 clreol();
}
