#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ERecaudacion_H_
#define ERecaudacion_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define ARBA 1
#define IIBB 2
#define GANANCIAS 3


//*** ESTRUCTURA
typedef struct {
	int idRecaudacion;
	int mes;
	int tipo;
	float importe;
	int idContribuyente;
	int isEmpty;
} eRecaudacion;
//***

/** INICIO CABECERAS DE FUNCION*/
void eRecaudacion_Inicializar(eRecaudacion array[], int TAM);
int eRecaudacion_ObtenerID(int* Recaudacion_idIncremental);
int eRecaudacion_ObtenerIndexLibre(eRecaudacion array[], int TAM);
int eRecaudacion_BuscarPorID(eRecaudacion array[], int TAM, int ID);
void eRecaudacion_MostrarUno(eRecaudacion Recaudacion);
int eRecaudacion_MostrarTodos(eRecaudacion array[], int TAM);
int eRecaudacion_MostrarDadosDeBaja(eRecaudacion array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eRecaudacion_Sort(eRecaudacion array[], int TAM, int criterio);

//ABM
eRecaudacion eRecaudacion_CargarDatos(void);
eRecaudacion eRecaudacion_ModificarUno(eRecaudacion Recaudacion);
int eRecaudacion_Alta(eRecaudacion array[], int TAM,int* id);
int eRecaudacion_Baja(eRecaudacion array[], int TAM);
int eRecaudacion_Modificacion(eRecaudacion array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
