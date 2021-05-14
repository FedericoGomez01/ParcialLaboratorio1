#include "Recaudacion.h"
#include "Biblioteca.h"
/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL


void eRecaudacion_Inicializar(eRecaudacion array[], int TAM) {
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

int eRecaudacion_ObtenerID(int* Recaudacion_idIncremental) {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return *Recaudacion_idIncremental + 1;
}

int eRecaudacion_ObtenerIndexLibre(eRecaudacion array[], int TAM) {
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

int eRecaudacion_BuscarPorID(eRecaudacion array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idRecaudacion == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eRecaudacion_MostrarUno(eRecaudacion Recaudacion) {
	//PRINTF DE UN SOLO Recaudacion
	printf("%5d  %10d  %10d  %10f\n", Recaudacion.idRecaudacion, Recaudacion.mes , Recaudacion.tipo, Recaudacion.importe);
}

int eRecaudacion_MostrarTodos(eRecaudacion array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO RecaudacionS");
	printf("%5s  %10s  %10s  %10s\n\n", "ID", "NOMBRE", "APELLIDO", "CUIL"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Recaudacion
				eRecaudacion_MostrarUno(array[i]);
				//CONTADOR DE Recaudacion
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Recaudacion PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eRecaudacion_MostrarDadosDeBaja(eRecaudacion array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> RECAUDACION\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Recaudacion
				eRecaudacion_MostrarUno(array[i]);
				//CONTADOR DE Recaudacion
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Recaudacion PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eRecaudacion eRecaudacion_CargarDatos(void) {
	eRecaudacion auxiliar;

	auxiliar.mes = Get_IntRange("INGRESE EL MES: ", "ERROR. REINGRESE: ", 1, 31);
	auxiliar. importe = Get_Int("INGRESE UN IMPORTE: ", "ERROR. REINGRESE: ");

	printf("\nSELECCIONE TIPO DE RECAUDACION\n\t[1]- ARBA\n\t[2]- IIBB\n\t[3]- GANANCIAS\n\n");
	switch (auxiliar.tipo =Get_IntRange("INGRESE EL TIPO DE RECAUDACION: ", "ERROR. REINGRESE:", 1, 3)){

	case ARBA:
		auxiliar.tipo = ARBA;
		break;

	case IIBB:
		auxiliar.tipo = IIBB;
		break;

	case GANANCIAS:
		auxiliar.tipo = GANANCIAS;
		break;

	}



	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eRecaudacion eRecaudacion_ModificarUno(eRecaudacion Recaudacion) {
	eRecaudacion auxiliar = Recaudacion;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	auxiliar = eRecaudacion_CargarDatos();
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eRecaudacion_Alta(eRecaudacion array[], int TAM,int* id) {
	int rtn = 0;
	eRecaudacion auxRecaudacion;

	//BUSCO ESPACIO EN ARRAY
	int index = eRecaudacion_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Recaudacion AUXILIAR
		auxRecaudacion = eRecaudacion_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxRecaudacion.idRecaudacion = eRecaudacion_ObtenerID(id);
		//CAMBIO SU ESTADO A "OCUPADO"
		auxRecaudacion.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxRecaudacion;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eRecaudacion_Baja(eRecaudacion array[], int TAM) {
	int rtn = 0;
	int idRecaudacion;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Recaudacion
	if (eRecaudacion_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Recaudacion DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Recaudacion PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idRecaudacion);

		//BUSCO INDEX POR ID EN ARRAY
		while (eRecaudacion_BuscarPorID(array, TAM, idRecaudacion) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idRecaudacion);
		}

		//OBTENGO INDEX DEL ARRAY DE Recaudacion A DAR DE BAJA
		index = eRecaudacion_BuscarPorID(array, TAM, idRecaudacion);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eRecaudacion_Modificacion(eRecaudacion array[], int TAM) {
	int rtn = 0;
	int idRecaudacion;
	int index;
	int flag = 0;
	eRecaudacion auxiliar;

	//LISTO TODOS LOS Recaudacion
	if (eRecaudacion_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Recaudacion DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Recaudacion PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idRecaudacion = Get_Int("INGRESA EL ID DEL RECAUDACION:", "ERROR. REINGRESE");

		//BUSCO INDEX POR ID EN ARRAY
		while (eRecaudacion_BuscarPorID(array, TAM, idRecaudacion) == -1) {
			puts("NO EXISTE ID.\n");
			idRecaudacion = Get_Int("INGRESA EL ID DEL RECAUDACION:", "ERROR. REINGRESE");
		}

		//OBTENGO INDEX DEL ARRAY DE Recaudacion A MODIFICAR
		index = eRecaudacion_BuscarPorID(array, TAM, idRecaudacion);

		//LLAMO A FUNCION QUE MODIFICA Recaudacion
		auxiliar = eRecaudacion_ModificarUno(array[index]);


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

int eRecaudacion_Sort(eRecaudacion array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eRecaudacion aux;

	/** EJEMPLO DE SORT CON ID DE Recaudacion
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
						if (array[i].idRecaudacion > array[j].idRecaudacion) {
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
						if (array[i].idRecaudacion < array[j].idRecaudacion) {
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

