#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mapa1();
void mapa2();
struct TUsuario{
	int identificador;
	char usuario[50];
	float saldo;
	int telefono;
	char clave[50];
	char nombre[50];

};
struct clientes{

	float saldoGastado;
	char ubicacion[50];
};

int main() {
	FILE *fichero;
	struct TUsuario vector[100];
	struct clientes cliente[100];
	int i,j, ruta,verifica=0,x,nUsuarios=0;
	char salir;
	
	int menu;
	char comprobador_nombre[50];
	char claverepetida[50],usuarioRegistrado[50],claveRegistrada[50];
	int esIgual=1,existe; 
	char ncuenta[50];
	int seleccionRuta1;

	do{
printf("			 _______    _____    ______   ______   ______  _____   ______   \n");
printf("			|          |     |  |      |     |    |       |     |     |     \n");
printf("			|          |_____|  |      |     |    |_____  |_____|     |     \n");
printf("			|          |     |  |-----<      |    |       |     |     |     \n");
printf("			|          |     |  |      |     |    |       |     |     |     \n");
printf("			|_______   |     |  |______|  ___|___ |       |     |  ___|___  \n\n\n\n");







	system("color F1");

	printf("\t\tBIENVENIDO A CABIFAI,PARA PODER ELEJIR UNA RUTA,PRIMERO DEBE CREAR O INCIAR SESION\n\n");

	printf("         ____________                           MENU PRINCIPAL:                  \t        ____________\n");
	printf("        / ___   __  |                           --------------                   \t       / ___   __  | \n");
	printf("  _____/ /___| /__| |__                 1.Iniciar sesion.                        \t _____/ /___| /__| |__ \n");
	printf(" |         -    -     |                                                          \t|         -    -     | \n");
	printf(" |____   ______   ____|                 2.Crear cuenta.                          \t|____   ______   ____| \n");
	printf("     |__|      |__|                                                              \t    |__|      |__| \n");
	printf("                                        3.Ver usuarios.\n\n");
	printf("                                        4.Elija su ruta.\n\n");
	printf("                                        5.Salir de la aplicacion.\n\n");
	scanf("%i",&menu);
	fflush(stdin);
	
	switch(menu){
case 1:
		system("cls");
		fichero = fopen("ficheropen.txt", "r");
		
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1; 
	}
		i=0;
		while (fscanf(fichero, "%d %s %f %i", &vector[i].identificador, vector[i].usuario, &vector[i].saldo, &vector[i].telefono)!=EOF) {
		i++;
	}
	for(x=0;x<i;x++){
		fscanf(fichero, "%d %s %f %i", &vector[x].identificador, vector[x].usuario, &vector[x].saldo, &vector[x].telefono);
	}
	
	
	fclose(fichero);
	
	fichero = fopen("password.txt", "r");
	
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1; 
	}
	
	i=0;
		while (fscanf(fichero, "%s", vector[i].clave)!=EOF) {
		i++;
	}
	
	for(x=0;x<i;x++){
		fscanf(fichero, "%s", vector[x].clave);
	}
	fclose(fichero);
	
		existe=1;
				do{
				printf("Introduzca su usuario:\n");
				gets(usuarioRegistrado);
				
					for(j=0;j<i;j++){
					
						if(strcmp(usuarioRegistrado,vector[j].usuario)==0){
							existe=0;
							x=j;
						}
						
					}
						if(existe!=0){
							printf("Su usuario no ha sido registrado aun.\n");
						}
				
				}while(existe!=0);
					fflush(stdin);
				
				existe=1;
				do{
					printf("Introduzca su clave de acceso:\n");
					gets(claveRegistrada);	
					
					if(strcmp(vector[x].clave,claveRegistrada)==0){
						existe=0;
					}
					
					if(existe!=0){
							printf("Clave incorrecta.\n");
						}
				}while(existe!=0);
				fflush(stdin);
			
			printf("\nHa iniciado sesion con exito.\n");
				
			
		
			printf("\n\n");
			system("pause");
			system("cls");
			break;
	case 2:
	system("cls");
	fichero = fopen("ficheropen.txt", "r");
	i=0;
	while (fscanf(fichero, "%d %s %f %i", &vector[i].identificador, vector[i].usuario, &vector[i].saldo, &vector[i].telefono)!=EOF) {
		i++;
	}
	fclose(fichero);
	do{
		printf("\n");
		printf("-->Introduzca su nombre de usuario para crear su cuenta\n",i);
		vector[i].identificador=i;
		scanf("%s",vector[i].usuario);
		fflush(stdin);
					printf("Introduzca su clave secreta:\n");
				gets(vector[i].clave);					
				
			do{
			
				printf("Repita su clave:\n");
				gets(claverepetida);
				
			if(strcmp(vector[i].clave,claverepetida)!=0){
		
				esIgual=1;  
				printf("Las claves introducidas no son las mismas.\n");
			}
			else{
				esIgual=0;
				
			}
		
			}while(esIgual!=0);
				
			fflush(stdin);
		printf("Introduzca el saldo inicial \n", i);
		scanf("%f", &vector[i].saldo);
		fflush(stdin);
		printf("Introduzca su numero de cuenta \n");
		gets(ncuenta);
		fflush(stdin);
		printf("Introduzca su telefono \n", i);
		scanf("%i", &vector[i].telefono);
		printf("Usuario creado correctamente pulse s para salir, o enter para crear otro usuario\n",i);
		fflush(stdin);
		scanf("%c",&salir);
		i++;
		system("cls");
		if(salir=='s')
			break;

		
	}while (i<=100);
	if(i==100)
		printf("Revise el codigo, ha alcanzado el limite de memoria\n");
	
	
	fichero = fopen("ficheropen.txt", "w");
	
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1;
		}
		
	
	for(j=0;j<i;j++){
		fprintf(fichero,"%d\t%s\t%f\t%i\n", vector[j].identificador, vector[j].usuario,vector[j].saldo, vector[j].telefono);
		}
		
	fclose(fichero); 
	
	fichero = fopen("password.txt", "w");
	
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1;
		}
		
	
	for(j=0;j<i;j++){
		fprintf(fichero,"%s\n", vector[j].clave);
		}
		
	fclose(fichero); 
			
	break;
	
	case 3:
		system("cls");
	fichero = fopen("ficheropen.txt", "r");
	
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1; 
	}
	i=0;
	printf("Usuario existentes:\n");
	while (fscanf(fichero, "%d %s %f %i", &vector[i].identificador, vector[i].usuario, &vector[i].saldo, &vector[i].telefono)!=EOF) {
		printf("%d Nombre:%s \tSaldo actual:%.2f$\t Tlfno:%d\n", vector[i].identificador, vector[i].usuario, vector[i].saldo, vector[i].telefono);
		i++;
	}
	fclose(fichero);	
	system("pause");
		system("cls");
		break;
	
	
	case 4: 
	system("cls");
			printf("ELIJA UNA RUTA:\n");
			printf("\t1.BARAJAS---->EMBAJADORES.\n");
			printf("\t2.ATOCHA------>MAJADAHONDA.\n");
			printf("\t3.ATOCHA------>PLAZA CASTILLA.\n");
			printf("\t4.RIOS ROSAS------>DELICIAS.\n");
			printf("\t5.SAN SEBASTIAN------>MAJADAHONDA.\n");
			scanf("%i",&ruta);
			fflush(stdin);
			switch(ruta){
			
				
			case 1: 
			system("cls");
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(cliente[nUsuarios].ubicacion);
					mapa2();
				printf("\nElija una ruta,siendo la uno la mas larga.\n");
				scanf("%d",&seleccionRuta1);
				if(seleccionRuta1==1){
					printf("\t\tEn breves estara el conductor en su ubicacion.\n");
					printf("\t\tEl precio sera: 24$\n");
				}else{
					printf("\t\tEn breves estara el conductor en su ubicacion.\n");
					printf("\t\tEl precio sera: 39.7$\n");
				}
			
					system("pause");
				system("cls");
				break;
			
		
			case 2:
					system("cls");
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n\n");
				gets(cliente[nUsuarios].ubicacion);
				mapa1();
				printf("\nElija una ruta,siendo la uno la mas larga.\n");
				scanf("%d",&seleccionRuta1);
				if(seleccionRuta1==1){
					printf("\t\tEn breves estara el conductor en su ubicacion.\n");
					printf("\t\tEl precio sera: 21$\n");
				}else{
					printf("\t\tEn breves estara el conductor en su ubicacion.\n");
					printf("\t\tEl precio sera: 27.54$\n");
				}
				
					system("pause");
				system("cls");
				break;
			
			case 3:
					system("cls");
			
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(cliente[nUsuarios].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion\n");
				printf("\t\tEl precio sera: 16$\n");
					system("pause");
				system("cls");
				break;
			
			case 4:
					system("cls");
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(cliente[nUsuarios].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion:\n");
				printf("\t\tEl precio sera: 9$\n");
					system("pause");
				system("cls");
				break;
			
			case 5:
					system("cls");
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(cliente[nUsuarios].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion:\n");
				printf("\t\tEl precio sera: 50$\n");
				system("pause");
				system("cls");
				break;

				
		}
		break;

		case 5:
			system("cls");
			printf("Esta usted seguro que desea salir de la aplicacion?\n");
			
			printf("1.SI \n");
					printf("2.NO \n");
						do{
							scanf("%i",&salir);	
							if(salir<1 || salir>2){
								printf("Opcion no valida\n");
							}
						}while(salir<1 || salir>2);
							if(salir==1){
								printf("Hasta la proxima.");
								return 0;
							}else{
								system("cls");
							}
							break;
		
		default: printf("Opcion no valida\n");
		system("pause");
		system("cls");
}
}while(menu!='5');
}

void mapa1(){
printf(" ________________________________________________________________________________________\n");
printf("|SALIDA______                                                                            |\n");
printf("|     |     |                                                                            |\n");
printf("|     |     |_____________                                                               |\n");
printf("|     |                  |	                  RUTA 1:                                | \n");
printf("|     |__________________|_____________*<-----44 minutos(21$,se recojera a otro cliente) | \n");
printf("|                        |_____________|_______________                                  |  \n");
printf("|                                      |               |                                 |   \n");
printf("|                                      |               |_______                          | \n");
printf("|                                      |_______________________|______________           | \n");
printf("|                                                              |___          |           | \n");
printf("|                                                                 /          |           |  \n");
printf("|                            RUTA 2:32 minutos(27.58$) ------->  /_________ DESTINO      |\n");
printf("|________________________________________________________________________________________|\n");

}

void mapa2(){

printf(" ________________________________________________________________________________________\n");
printf("|                            ___________________________________________SALIDA ________  |\n");
printf("|                           /                                                         |  |\n");
printf("|                          / <-----RUTA 2:25 minutos(39.7$,peaje incluido)            |  |\n");
printf("|                         /                                                           |  | \n");
printf("|                        /                                                            |  | \n");
printf("|                       /                                                             |  |  \n");
printf("|                      /                                                             /   |   \n");
printf("|                     /                                                             /    | \n");
printf("|                    /                                                             /     | \n");
printf("|                   /                                                             /      | \n");
printf("|                  /                              RUTA 1:39 minutos(24$)-------> |       |  \n");
printf("|           DESTINO______________________________________________________________|       |  \n");
printf("|________________________________________________________________________________________|\n");


}


