/*
 ============================================================================
 Name        : test_linkedList.c
 Author      : Sofia Belucci
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define TAM_NOM 30

typedef struct {
	char nombre[TAM_NOM];
	int edad;
	char sexo;
} ePersona;

//-----------------FUNCIONES-----------------------------
void mostrarPersona(ePersona *e);
void mostrarPersonas(LinkedList *pArrayListaPersonas);
ePersona* new_Persona();
//-------------------------------------------------------

int main(void) {
	setbuf(stdout, NULL);

	int indicePersona;
	LinkedList *listaPersonas = ll_newLinkedList();

	ePersona *persona1 = new_Persona();

	strcpy(persona1->nombre, "Sofia Belucci");
	persona1->edad = 21;
	persona1->sexo = 'f';
	ll_add(listaPersonas, persona1);

	ePersona *persona2 = new_Persona();

	strcpy(persona2->nombre, "Silvia Garcia");
	persona2->edad = 59;
	persona2->sexo = 'f';
	ll_add(listaPersonas, persona2);

	ePersona *persona3 = new_Persona();

	strcpy(persona3->nombre, "Gustavo Belucci");
	persona3->edad = 57;
	persona3->sexo = 'm';
	ll_add(listaPersonas, persona3);

	mostrarPersonas(listaPersonas);

	puts("\n\nPor ej: ll_set:");
	puts("Se setea cualquier tipo de dato de la estructura\n");
	strcpy(persona1->nombre, "Pepita Belucci");
	persona1->edad = 21;
	persona1->sexo = 'f';
	ll_set(listaPersonas, 0, persona1);
	mostrarPersona(persona1);

	//----------------index-----------------------------------------------------
	puts("\n\nPor ej: ll_indexOf:");
	puts(
			"Se manda el puntero a la persona y nos devuelve el indice en el que esta\n");

	indicePersona = ll_indexOf(listaPersonas, persona2);
	if (indicePersona != -1) {
		printf("Se encontro el indice %d de esta persona", indicePersona);
	} else {
		puts("No se encontro el indice de la persona");
	}

	return 0;
}

//--------------------------------------------------------------------------
void mostrarPersona(ePersona *e) {

	printf("Nombre: %s\n Edad: %d\n Sexo: %c\n", e->nombre, e->edad, e->sexo);

}

void mostrarPersonas(LinkedList *pArrayListaPersonas) {
	int tam;
	ePersona *auxPersona = NULL;

	tam = ll_len(pArrayListaPersonas);
	for (int i = 0; i < tam; i++) {
		auxPersona = ll_get(pArrayListaPersonas, i);
		mostrarPersona(auxPersona);

	}

}

ePersona* new_Persona() {
	return (ePersona*) malloc(sizeof(ePersona));

}
