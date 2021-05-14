#ifndef Informes_H_
#define Informes_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "Contribuyente.h"
#include "Recaudacion.h"
#include "Biblioteca.h"



void eContribuyenteRecaudacion_MostrarTodos(eContribuyente Contribuyente[], int TAM_ESTRUCTURA,eRecaudacion Recaudacion[]);


int eContribuyenteRecaudacion_Alta(eContribuyente Contribuyente[], int TAM_ESTRUCTURA, eRecaudacion Recaudacion[], int * id);

#endif
