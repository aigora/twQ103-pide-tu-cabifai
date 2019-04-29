#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct TUsuario{
	int identificador;
	char usuario[50];
	float saldo;
	int telefono;
	char ncuenta[20];
	char clave[50];
	char nombre[50];

};
struct clientes{

	float saldoGastado;
	char ubicacion[50];
};

int main() {
	FILE *puntero;
	struct TUsuario vector[100];
	struct clientes cliente[100];
	int i,j, ruta,verifica=0,nUsuarios=0;
	char salir;
	
	int menu;
	char comprobador_nombre[50];
	char claverepetida[50],usuarioRegistrado[50],claveRegistrada[50];
	int esIgual=1,existe; 
	do{
printf("			 _______    _____    ______   ______   ______  _____   ______   \n");
printf("			|          |     |  |      |     |    |       |     |     |     \n");
printf("			|          |_____|  |      |     |    |_____  |_____|     |     \n");
printf("			|          |     |  |-----<      |    |       |     |     |     \n");
printf("			|          |     |  |      |     |    |       |     |     |     \n");
printf("			|_______   |     |  |______|  ___|___ |       |     |  ___|___  \n\n\n\n");







	system("color F1");



	printf("         ____________                           MENU PRINCIPAL:                  \t        ____________\n");
	printf("        / ___   __  |                           --------------                   \t       / ___   __  | \n");
	printf("  _____/ /___| /__| |__                 1.Iniciar sesion                         \t _____/ /___| /__| |__ \n");
	printf(" |         -    -     |                                                          \t|         -    -     | \n");
	printf(" |____   ______   ____|                 2.Ver usuarios y Crear cuenta            \t|____   ______   ____| \n");
	printf("     |__|      |__|                                                              \t    |__|      |__| \n");
	printf("                                        3.Elija su ruta.\n\n");
	printf("                                        4.Salir de la aplicacion.\n\n");
	scanf("%i",&menu);
	fflush(stdin);
	
	switch(menu){
case 1:
		system("cls");
		printf("BIENVENIDO A CABIFAI\n\n");
				
				printf("Introduzca su nombre de usuario:\n");
				gets(vector[i].nombre);	
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
				nUsuarios++;
			fflush(stdin);
			printf("Sesion iniciada con exito");
			printf("\n\n");
			system("pause");
			system("cls");
			break;
	case 2:
	system("cls");
	puntero = fopen("ficheropen.txt", "r");
	
	if (puntero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1; 
	}
	i=0;
	printf("Usuario existes:\n");
	while (fscanf(puntero, "%d %s %f %s %i", &vector[i].identificador, vector[i].usuario, &vector[i].saldo,vector[i].ncuenta, &vector[i].telefono)!=EOF) {
		printf("%d Nombre:%s \tSaldo actual:%.2f$\t nCuenta:%s\t Tlfno:%d\n", vector[i].identificador, vector[i].usuario, vector[i].saldo, vector[i].ncuenta, vector[i].telefono);
		i++;
	}
	fclose(puntero);
	
	

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
				i++;
			fflush(stdin);
		printf("Introduzca el saldo inicial \n", i);
		scanf("%f", &vector[i].saldo);
		printf("Introduzca su numero de cuenta \n", i);
		scanf("%f", &vector[i].ncuenta);
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
	
	
	puntero = fopen("ficheropen.txt", "w");
	
	if (puntero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1;
		}
		
	
	for(j=0;j<i;j++){
		fprintf(puntero,"%d\t%s\t%f\t%s\t%i\n", vector[j].identificador, vector[j].usuario, vector[j].saldo,vector[j].ncuenta, vector[j].telefono);
		}
		
	fclose(puntero); 
			
	break;
	
	case 3: 
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
				printf("\t\tEn breves estara el conductor en su ubicacion.\n");
				printf("El precio sera: 36$\n");
					system("pause");
				system("cls");
				break;
			
		
			case 2:
					system("cls");
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(cliente[nUsuarios].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion.\n");
				printf("\t\tEl precio sera: 37$\n");
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

		case 4:
			system("cls");
			printf("Esta usted seguro que desea salir de la aplicacion?\n");
			
			printf("1.SI \n");
					printf("2.NO \n");
						scanf("%i",&salir);	
					switch(salir){
					
						case 1: 
						printf("Hasta la proxima!");
						return 0;
						system("pause");
					    	break;
						system("pause");
						case 2:
							system("cls");
							break;
				}
		default: printf("Opcion no valida\n");
		system("pause");
		system("cls");
}
}while(menu!='4');
}


