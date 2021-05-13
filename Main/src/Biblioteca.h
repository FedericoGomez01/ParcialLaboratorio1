#ifndef UTNGET_AND_VALIDATIONS_H_
#define UTNGET_AND_VALIDATIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <String.h>

//VALIDATIONS
int Validation_OnlyInt(char* numero);//Validacion de numero, ingluye tanto los positivos como los negativos
int Validate_OnlyNumberInt(char *pData);
int Validate_OnlyNumberFloat(char *pData);
int Validate_OnlyAlphabet(char *pData);
int Validate_OnlyAlphabetWithSpaces(char *pData);
int Validate_Exit_SN(char* MSJ, char* MSJERROR);
//GET'S
int Get_Int(char* MSJ, char* MSJERROR); //Pide un numero y lo valida usando Validation_OnlyInt
float Get_Float(char* MSJ, char* MSJERROR);
int Get_IntRange(char* MSJ, char*MSJERROR, int MIN, int MAX);
void Get_String(char* MSJ, char* MSJERROR, char* pArray, int MAX);
void Get_OnlyAlphabetStringWithSpaces(char* MSJ, char* MSJERROR,  char* pArray, int MAX);
int Get_IntPositive(char* MSJ, char* MSJERROR);
void Get_Cuit(char* MSJ, char* pArray);

//FUNCIONES UTILES

void Menu(char* MSJ);
//int Calculate_Average(); HACER UNA FUNCION QUE CALCULE EL PROMEDIO
int toUpperString(char string[]);

#endif /* UTNGET_AND_VALIDATIONS_H_ */
