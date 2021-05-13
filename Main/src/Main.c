#include "Contribuyente.h"
#include "Biblioteca.h"
#define TAM_ESTRUCTURA 10000

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int criterioDeOrdenamiento;
	int Contribuyente_idIncremental = 99;
	//CREO ARRAY DE ESTRUCTURA
	eContribuyente Contribuyente[TAM_ESTRUCTURA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eContribuyente_Inicializar(Contribuyente, TAM_ESTRUCTURA);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		Menu("[0] - SALIR\n"
			"[1] - ALTA CONTRIBUYENTE\n"
			"[2] - MODIFICAR CONTRIBUYENTE\n"
			"[3] - BAJA CONTRIBUYENTE\n");
		printf("INGRESE OPCION: ");
		scanf("%d", &opc);

		//MENU SWITCH
		switch (opc)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opc = 0;
			break;
		case 1:
			//ALTA
			if (eContribuyente_Alta(Contribuyente, TAM_ESTRUCTURA, &Contribuyente_idIncremental)) {
				puts(" * CONTRIBUYENTE DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS CONTRIBUYENTE");
			}
			system("pause");
			break;
		case 2:
			//MODIFICACION
			if (eContribuyente_Modificacion(Contribuyente, TAM_ESTRUCTURA)) {
				puts("\n * MODIFICACION DE CONTRIBUYENTE EXITOSA\n");
			} else {
				puts("\n * MODIFICACION DE CONTRIBUYENTE CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//BAJA
			if (eContribuyente_Baja(Contribuyente, TAM_ESTRUCTURA)) {
				puts("\n * BAJA DE CONTRIBUYENTE EXITOSA");
				eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
			} else {
				puts("\n * BAJA DE CONTRIBUYENTE CANCELADA");
			}
			system("pause");
			break;

		case 4:
			//LISTADO Contribuyente
			if(eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA)){
				system("pause");
			}else{
				puts("No hay nada para mostrar");
			}

			break;
		case 5:
			//ORDENAR Contribuyente
			criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
			eContribuyente_Sort(Contribuyente, TAM_ESTRUCTURA, criterioDeOrdenamiento);
			system("pause");
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
