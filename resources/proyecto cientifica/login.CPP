#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define USER "nestor" //este es nombre de usuario
#define PASS "oliva"  //la contrasena
#define L 80
int main()
{
	char usuario[L + 1];
	char password[L + 1];
	int contador = 0 ;
	char ingresa = 0;
	int i = 0;	// Indica la posición del caracter leído en la cadena
	char caracter; // Guarda el caracter leído mediante la función getch

	do {
		system("cls");
      gotoxy(35,2);printf("\t\t\t----------------\n");
		gotoxy(35,3);printf("\t\t\tINICIO DE SESION\n");
		gotoxy(35,4);printf("\t\t\t----------------\n");
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
   getchar();
   return 0;
 }