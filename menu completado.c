#include<stdio.h>
#include <string.h>

struct  TUsuario{
	char usuario[50];
	char clave[50];
	float saldo;
	char Ncuenta[50];
	int telefono;
	float saldoGastado;
	char ubicacion[50];
	
};


void main(){


printf("			 _______    _____    ______   ______   ______  _____   ______   \n");
printf("			|          |     |  |      |     |    |       |     |     |     \n");
printf("			|          |_____|  |      |     |    |_____  |_____|     |     \n");
printf("			|          |     |  |-----<      |    |       |     |     |     \n");
printf("			|          |     |  |      |     |    |       |     |     |     \n");
printf("			|_______   |     |  |______|  ___|___ |       |     |  ___|___  \n\n\n\n");

	

	float rutas[7], usuario[100];
	int i=0,j=0,contUsuarios=0;
	struct TUsuario clientes[100];
	char claverepetida[50],usuarioRegistrado[50],claveRegistrada[50];
	int menu,opcion,salir,ruta;//SWITCH
	int esIgual=1,existe; //do,while
	
	system("color F1");

do{
	
	printf("         ____________                           MENU PRINCIPAL:                  \t        ____________\n");
	printf("        / ___   __  |                           --------------                   \t       / ___   __  | \n");
	printf("  _____/ /___| /__| |__                 1.Crear usuario.                         \t _____/ /___| /__| |__ \n");
	printf(" |         -    -     |                                                          \t|         -    -     | \n");
	printf(" |____   ______   ____|                 2.Usuarios registrados y gastos.         \t|____   ______   ____| \n");
	printf("     |__|      |__|                                                              \t    |__|      |__| \n");
	printf("                                        3.Elija su ruta.\n\n");
	printf("                                        4.Salir de la aplicacion.\n\n");
	scanf("%i",&menu);
	fflush(stdin);
	
	
		switch(menu){
		
		case 1:
			printf("\t\t1.Crear un nuevo usuario.\n");
			printf("\t\t2.Iniciar sesion.\n");
			scanf("%i",&opcion);
			switch(opcion){
				
				case 1:
			
				printf("BIENVENIDO A CABIFAI\n\n");
				fflush(stdin);
				printf("Introduzca su nombre de usuario:\n");
				gets(clientes[contUsuarios].usuario);
				
				printf("Introduzca su clave secreta:\n");
				gets(clientes[contUsuarios].clave);
				
				
			do{
			
				printf("Repita su clave:\n");
				gets(claverepetida);
				
			if(strcmp(clientes[contUsuarios].clave,claverepetida)!=0){
		
				esIgual=1;  
				printf("Las claves introducidas no son las mismas.\n");
			}
			else{
				esIgual=0;
				
			}
		
			}while(esIgual!=0);
			
			
			printf("Introduzca su numero de telefono:\n");
			scanf("%i",&clientes[contUsuarios].telefono);
			fflush(stdin);
				
			printf("Introduzca su numero de cuenta:\n");
			gets(clientes[contUsuarios].Ncuenta);
				
				
			printf("Introduzca un minimo de saldo para su primer viaje:\n");
			scanf("%f",&clientes[contUsuarios].saldo);
			
			contUsuarios++;
			fflush(stdin);
			break;
			
			
			case 2:
				existe=1;
				do{
				printf("Introduzca su usuario:\n");
				gets(usuarioRegistrado);
				
					for(i=0;i<contUsuarios;i++){
					
						if(strcmp(usuarioRegistrado,clientes[i].usuario)==0){
							existe=0;
							j=i;
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
					
					if(strcmp(clientes[j].clave,claveRegistrada)==0){
						existe=0;
					}
					
					if(existe!=0){
							printf("Contraseña incorrecta.\n");
						}
				}while(existe!=0);
				fflush(stdin);
			
			printf("\tHa iniciado sesion con exito.\n");
				
			
			break;
		}
		break;
	/*
		case 2: una vez guardado los usuarios en un vector se muestran con x gastos ya pagados, y mostrando un determinada ruta 
		como ultima ruta.
		
	*/	
		case 3: 
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
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(clientes[i].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion.\n");
				printf("El precio sera: 36$\n");
				break;
			
		
			case 2:
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(clientes[i].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion.\n");
				printf("\t\tEl precio sera: 37$\n");
				break;
			
			case 3:
			
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(clientes[i].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion\n");
				printf("\t\tEl precio sera: 16$\n");
				break;
			
			case 4:
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(clientes[i].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion:\n");
				printf("\t\tEl precio sera: 9$\n");
				break;
			
			case 5:
				printf("\t\tIntroduzca su ubicacion(ciudad,calle):\n");
				gets(clientes[i].ubicacion);
				printf("\t\tEn breves estara el conductor en su ubicacion:\n");
				printf("\t\tEl precio sera: 50$\n");
				break;
				
		break;
		}
		/*1.Barajas - Embajadores con un determinado precio.
		...
		.....
		asi hasta siete rutas.
		
		en dos o tres de ellas ponemos dos alternativas de como llegar a traves de una matriz en la que en la pantalla muestra un camino con 
		asteriscos con un determinado precio,y otro camino con guiones que costrara otro precio.
		*/
		case 4:
			printf("¿Esta usted seguro que desea salir de la aplicacion?\n");
			
				switch(salir){
					
					printf("1.SI \n");
					printf("2.NO \n");	
					
					scanf("%i",&salir);
					
						case 1: //hacer el menu como una funcion y aqui pedirla.
					    	break;
						
						case 2:
							
							break;
				}
		default: printf("Opcion incorrecta\n");
			
		
}//system("cls");//BORRAR PANTALLA.

}while(menu!='4');

}


		
	




