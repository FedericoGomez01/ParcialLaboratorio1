#include "Contribuyente.h"
#include "Biblioteca.h"
/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL


void eContribuyente_Inicializar(eContribuyente array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eContribuyente_ObtenerID(int* Contribuyente_idIncremental) {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return *Contribuyente_idIncremental + 1;
}

int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eContribuyente_BuscarPorID(eContribuyente array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idContribuyente == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eContribuyente_MostrarUno(eContribuyente Contribuyente) {
	//PRINTF DE UN SOLO Contribuyente
	printf("%5d  %10s  %10s  %10s\n", Contribuyente.idContribuyente, Contribuyente.nombre, Contribuyente.apellido, Contribuyente.cuil);
}

int eContribuyente_MostrarTodos(eContribuyente array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO CONTRIBUYENTES");
	printf("%5s  %10s  %10s  %10s\n\n", "ID", "NOMBRE", "APELLIDO", "CUIL"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Contribuyente
				eContribuyente_MostrarUno(array[i]);
				//CONTADOR DE Contribuyente
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Contribuyente PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Contribuyente\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Contribuyente
				eContribuyente_MostrarUno(array[i]);
				//CONTADOR DE Contribuyente
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Contribuyente PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eContribuyente eContribuyente_CargarDatos(void) {
	eContribuyente auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	Get_OnlyAlphabetStringWithSpaces("INGRESE NOMBRE: ", "ERROR. REINGRESE: ", auxiliar.nombre, MAX_CHARS_CADENAS);
	Get_OnlyAlphabetStringWithSpaces("INGRESE APELLIDO: ", "ERROR. REINGRESE: ", auxiliar.apellido, MAX_CHARS_CADENAS);
	Get_Cuit("INGRESE EL CUIL", auxiliar.cuil);

	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente) {
	eContribuyente auxiliar = Contribuyente;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	auxiliar = eContribuyente_CargarDatos();
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eContribuyente_Alta(eContribuyente array[], int TAM,int* id) {
	int rtn = 0;
	eContribuyente auxContribuyente;

	//BUSCO ESPACIO EN ARRAY
	int index = eContribuyente_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Contribuyente AUXILIAR
		auxContribuyente = eContribuyente_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxContribuyente.idContribuyente = eContribuyente_ObtenerID(id);
		//CAMBIO SU ESTADO A "OCUPADO"
		auxContribuyente.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxContribuyente;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eContribuyente_Baja(eContribuyente array[], int TAM) {
	int rtn = 0;
	int idContribuyente;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Contribuyente
	if (eContribuyente_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Contribuyente DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Contribuyente PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idContribuyente);

		//BUSCO INDEX POR ID EN ARRAY
		while (eContribuyente_BuscarPorID(array, TAM, idContribuyente) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idContribuyente);
		}

		//OBTENGO INDEX DEL ARRAY DE Contribuyente A DAR DE BAJA
		index = eContribuyente_BuscarPorID(array, TAM, idContribuyente);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eContribuyente_Modificacion(eContribuyente array[], int TAM) {
	int rtn = 0;
	int idContribuyente;
	int index;
	int flag = 0;
	eContribuyente auxiliar;

	//LISTO TODOS LOS Contribuyente
	if (eContribuyente_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Contribuyente DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Contribuyente PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idContribuyente = Get_Int("INGRESA EL ID DEL CONTRIBUYENTE:", "ERROR. REINGRESE");

		//BUSCO INDEX POR ID EN ARRAY
		while (eContribuyente_BuscarPorID(array, TAM, idContribuyente) == -1) {
			puts("NO EXISTE ID.\n");
			idContribuyente = Get_Int("INGRESA EL ID DEL CONTRIBUYENTE:", "ERROR. REINGRESE");
		}

		//OBTENGO INDEX DEL ARRAY DE Contribuyente A MODIFICAR
		index = eContribuyente_BuscarPorID(array, TAM, idContribuyente);

		//LLAMO A FUNCION QUE MODIFICA Contribuyente
		auxiliar = eContribuyente_ModificarUno(array[index]);


		if(Validate_Exit_SN("DESEA CONTINUAR? S-[SI] N-[NO]", "ERROR. REINGRESE:"))
		{
			//MODIFICACION ACEPTADA
			array[index] = auxiliar;
			//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
			rtn = 1;
			printf("\nMODIFICACION EXITOSA");

		}
		else
		{
			printf("\nMODIFICACION CANCELADA");
		}
	}

	return rtn;
}

int eContribuyente_Sort(eContribuyente array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eContribuyente aux;

	/** EJEMPLO DE SORT CON ID DE Contribuyente
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idContribuyente > array[j].idContribuyente) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idContribuyente < array[j].idContribuyente) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

