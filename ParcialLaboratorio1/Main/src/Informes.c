#include "Informes.h"
#include "Contribuyente.h"
#include "Recaudacion.h"
#include "Biblioteca.h"

void eContribuyenteRecaudacion_MostrarTodos(eContribuyente Contribuyente[], int TAM_ESTRUCTURA,eRecaudacion Recaudacion[]){
	int i;
	int idRecaudacion;

	idRecaudacion = Get_Int("INGRESE EL ID DE LA RECAUDACION: ", "ERROR. REINGRESE: ");

	//CABECERA
	puts("\n\t> LISTADO CONTRIBUYENTES");
	printf("%5s  %10s  %10s  %10s\n\n", "ID", "NOMBRE", "APELLIDO", "CUIL"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (Contribuyente != NULL && TAM_ESTRUCTURA > 0) {
			//RECORRO TODO EL ARRAY
			for (i = 0; i < TAM_ESTRUCTURA; i++) {
				//PREGUNTO POR SU ESTADO "OCUPADO"
				if (Contribuyente[i].isEmpty == 1) {
					//MUESTRO UN SOLO Instrumento
					idRecaudacion =eRecaudacion_BuscarPorID(Recaudacion,TAM_ESTRUCTURA, i);
					if(idRecaudacion != -1)
					{
						eContribuyente_MostrarUno(Contribuyente[i]);
						if(Validate_Exit_SN("DESEA CAMBIAR DE ESTADO A REFINANCIAR?: S-[SI]  N-[NO]", "ERROR. REINGRESE:")){

							printf("\n\tESTADO ACTUALIZADO\n");
						}
					else
					{
						printf("\n\tPRIMERO DEBE CARGAR RECAUDACION\n");
					}

				}
			}


		}


}

int eContribuyenteRecaudacion_Alta(eContribuyente Contribuyente[], int TAM_ESTRUCTURA, eRecaudacion Recaudacion[], int * id) {


			int rtn = 0;

			eRecaudacion auxRecaudacion;
			int idRecaudacion;
			int indexContribuyente;

			int index = eRecaudacion_ObtenerIndexLibre(Recaudacion, TAM_ESTRUCTURA);

			if (index != -1) {
				auxRecaudacion = eRecaudacion_CargarDatos();

				//ID DE ORQUESTA
				eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
				idRecaudacion = Get_Int("SELECCIONE ID : ", "ERROR. REINGRESE: ");
				indexContribuyente = eContribuyente_BuscarPorID(Contribuyente, TAM_ESTRUCTURA, idRecaudacion);

				while (!indexContribuyente) {
					puts("ID NO EXISTE.");
					idRecaudacion = Get_Int("SELECCIONE ID DEL CONTRIBUYENTE: ", "ERROR. REINGRESE: ");
				}



				//TENGO TODO CARGADO
				if (Validate_Exit_SN("CONTINUAR SI[S] - NO[N]: ", "ERROR. REINGRESE: ")) {
					auxRecaudacion.idRecaudacion = eRecaudacion_ObtenerID(id);
					auxRecaudacion.isEmpty = OCUPADO;
					Recaudacion[index] = auxRecaudacion;
					Contribuyente[indexContribuyente].idContribuyente = idRecaudacion;
					rtn = 1;
				}
			}
			return rtn;
		}

void eRecaudacionContribuyente_MostrarUno(eContribuyente Contribuyente) {

	printf("%5d  %10s %15s  %15s\n", Contribuyente.idContribuyente, Contribuyente.nombre, Contribuyente.apellido ,Contribuyente.cuil );


	}

}
