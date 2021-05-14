#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EContribuyente_H_
#define EContribuyente_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct {
	int idContribuyente;
	char nombre[MAX_CHARS_CADENAS];
	char apellido[MAX_CHARS_CADENAS];
	char cuil[MAX_CHARS_CADENAS];
	char estado[MAX_CHARS_CADENAS];
	int isEmpty;
} eContribuyente;
//***

/** INICIO CABECERAS DE FUNCION*/
void eContribuyente_Inicializar(eContribuyente array[], int TAM);
int eContribuyente_ObtenerID(int* Contribuyente_idIncremental);
int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int TAM);
int eContribuyente_BuscarPorID(eContribuyente array[], int TAM, int ID);
void eContribuyente_MostrarUno(eContribuyente Contribuyente);
int eContribuyente_MostrarTodos(eContribuyente array[], int TAM);
int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eContribuyente_Sort(eContribuyente array[], int TAM, int criterio);

//ABM
eContribuyente eContribuyente_CargarDatos(void);
eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente);
int eContribuyente_Alta(eContribuyente array[], int TAM,int* id);
int eContribuyente_Baja(eContribuyente array[], int TAM);
int eContribuyente_Modificacion(eContribuyente array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
