#include "Biblioteca.h"

//*** VALIDACIONES - INICIO
int Validate_OnlyNumberInt(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isdigit(pData[i]) == 0) {
				if (i == 0) {
					if (pData[0] != '-') {
						rtn = 0;
						break;
					}
				} else {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyNumberFloat(char *pData) {
	int countSigno = 0;
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {

			if (pData[i] == '.' || pData[i] == ',') {
				countSigno++;
			} else {
				if (isdigit(pData[i]) == 0) {
					if (i == 0) {
						if (pData[0] != '-') {
							rtn = 0;
							break;
						}
					} else {
						rtn = 0;
						break;
					}
				}
			}
		}

		if (countSigno > 1) {
			rtn = 0;
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabet(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				rtn = 0 ;
				break;
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabetWithSpaces(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				if (isspace(pData[i]) == 0) {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}
int Validate_Exit_SN(char* MSJ, char* MSJERROR){
	char respuesta;
	int rtn;

	printf(MSJ);
	fflush(stdin);
	scanf("%c", &respuesta);

	while(respuesta != 'n' && respuesta != 's')
	{
		printf(MSJERROR);
		fflush(stdin);
		scanf("%c", &respuesta);
	}

	if(respuesta > 0)
	{
		respuesta = tolower(respuesta);

		if(respuesta == 's')
		{
			rtn = 1;
		}
		else{
			rtn=0;
		}

	}


	return rtn;

}


//GETS
int Get_Int(char* MSJ, char* MSJERROR)
{
	char buffer [1000];
	int rtn;

	printf(MSJ);
	fflush(stdin);
	gets(buffer);

	while((Validate_OnlyNumberInt(buffer))==0)
	{
		printf(MSJERROR);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atoi(buffer);

	return rtn;
}
int Get_IntRange(char* MSJ, char*MSJERROR, int MIN, int MAX)
{
	int rtn = Get_Int(MSJ, MSJERROR);

	while((rtn < MIN) ||( rtn > MAX))
	{
		printf("ERROR. Fuera de rango: MINIMO = %d   MAXIMO = %d. \n", MIN, MAX);
		rtn = Get_Int(MSJ, MSJERROR);
	}

	return rtn;
}
float Get_Float(char* MSJ, char* MSJERROR)
{
	char buffer[1000];
	float rtn;


	printf(MSJ);
	fflush(stdin);
	gets(buffer);

	while((Validate_OnlyNumberFloat(buffer))== 1)
	{
		printf(MSJERROR);
		printf(MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn= atof(buffer);
	return rtn;
}
void Get_String(char* MSJ, char* MSJERROR, char* pArray, int MAX)
{
	char buffer[1000];

	printf(MSJ);
	fflush(stdin);
	gets(buffer);

	while((Validate_OnlyAlphabetWithSpaces(buffer)) == 0|| strlen(buffer) > MAX )
	{
		printf(MSJERROR);
		fflush(stdin);
		gets(buffer);

	}
	strcpy(pArray, buffer);
	atof(pArray);

}
void Get_OnlyAlphabetStringWithSpaces(char* MSJ, char* MSJERROR,  char* pArray, int MAX)
{
	char buffer[1000];


	printf(MSJ);
	fflush(stdin);
	gets(buffer);

	while(((Validate_OnlyAlphabetWithSpaces(buffer)) == 0) || (strlen(buffer) > MAX))
	{
		printf(MSJERROR);
		fflush(stdin);
		gets(buffer);

	}
	strcpy(pArray, buffer);
	atof(pArray);

}
int Get_IntPositive(char* MSJ, char* MSJERROR)
{
	int rtn = Get_Int(MSJ, MSJERROR);

	while(rtn <0)
	{
		puts(MSJERROR);
		rtn = Get_Int(MSJ, MSJERROR);
	}

	return rtn;
}

void Get_Cuit(char* MSJ, char* pArray)
{
    char buffer[1000];
    char auxUno[10];
    char auxDos[10];
    char auxTres[10];
    int bufferUno;
    int bufferDos;
    int bufferTres;

    puts(MSJ);
    puts("PRIMEROS DOS DIGITOS\n\n20, 23, 24 Y 27 PARA PESONAS FISICAS\n30, 33 Y 34 PARA EMPRESAS\n");
    puts("\n[XX]-XXXXXXXX-X\n");
    bufferUno=Get_Int("INGRESE DIGITOS: ", "ERROR. REINGRESE: ");

    while(bufferUno!=20&&bufferUno!=23&&bufferUno!=24&&bufferUno!=27&&bufferUno!=30&&bufferUno!=33&&bufferUno!=34)
    {
        puts(MSJ);
        puts("PRIMEROS DOS DIGITOS\n20, 23, 24 Y 27 PESONAS FISICAS\n30, 33 Y 34 EMPRESAS\n\n");
        puts("\n[XX]-XXXXXXXX-X\n");
        bufferUno=Get_Int("\nERROR. REINGRESE: ", "ERROR. REINGRESE: ");
    }

    puts(MSJ);
    puts("\nNUMERO DE SOCIEDAD PARA EMPRESAS O DNI PARA PESONAS FISICAS [7-8 DIGITOS] \n");
    printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
    bufferDos=Get_Int("INGRESE DIGITOS: ", "ERROR. REINGRESE");

    while(bufferDos<1000000||bufferDos>100000000)
    {
        puts(MSJ);
        puts("\nNUMERO DE SOCIEDAD PARA EMPRESAS O DNI PARA PESONAS FISICAS\n");
        printf("\n%d-[XXXXXXXX]-X\n", bufferUno);
        bufferDos=Get_Int("\nERROR. REINGRESE: ", "ERROR. REINGRESE: ");
    }

    puts(MSJ);
    puts("\nNUMERO VERIFICADOR\n");
    printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
    bufferTres=Get_Int("INGRESE DIGITOS: ", "ERROR. REINGRESE: ");

    while(bufferTres<0||bufferTres>9)
    {
        puts(MSJ);
        puts("\nNUMERO VERIFICADOR\n");
        printf("\n%d-%d-[X]\n", bufferUno, bufferDos);
        bufferTres=Get_Int("\nERROR. REINGRESE: ", "ERROR. REINGRESE");
    }

    if(Validate_Exit_SN("DESEA CONTINUAR?: S[SI]  N[NO]", "ERROR. REINGRESE"))
    {
        itoa(bufferUno,auxUno,10);
        itoa(bufferDos,auxDos,10);
        itoa(bufferTres,auxTres,10);

        strcpy(buffer, auxUno);
        strcat(buffer, "-");
        strcat(buffer, auxDos);
        strcat(buffer, "-");
        strcat(buffer, auxTres);

        strcpy(pArray, buffer);

        printf("\n[CARGA EXITOSA] CUIT: %s\n\n", pArray);
    }
    else
    {
    	  printf("\n[CARGA CANCELADA]\n");
    }

}


//FUNCIONES UTILES

void Menu(char* MSJ)
{
	puts(MSJ);
}

int toUpperString(char string[]){

	int rtn = -1;
	int len = strlen(string);

	if(len >0){
		for(int i=0; i< len-1; i++ )
		{
			string[i] = toupper(string[i]);
		}
		rtn = 0;
	}
	return rtn;
}

/*
void Format_NameLastname(char *pName, char *pLastname, char *pFormatName) {

	strcpy(pFormatName, pLastname);
	strcat(pFormatName, ", ");
	strcat(pFormatName, pName);

	strlwr(pFormatName);

	if (strlen(pName) > 0 && strlen(pLastname) > 0) {
		for (int i = 0; i < strlen(pFormatName); i++) {
			if (i == 0 && isspace(pFormatName[i]) == 0) {
				pFormatName[0] = toupper(pFormatName[0]);

			} else {
				if (isspace(pFormatName[i]) && i < strlen(pFormatName) - 1) {
					pFormatName[i + 1] = toupper(pFormatName[i + 1]);
				}
			}
		}
	}
}
*/
