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
	ePersona* auxPersona;
	int tamListaPersonas;
	int tamListaEmpleados;
	LinkedList *listaPersonas = ll_newLinkedList();
	LinkedList* listaEmpleados = ll_newLinkedList();

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
	persona3->edad = 55;
	persona3->sexo = 'm';
	ll_add(listaPersonas, persona3);

	ePersona *persona4 = new_Persona();

		strcpy(persona4->nombre, "Pepito Garcia");
		persona4->edad = 40;
		persona4->sexo = 'm';
		ll_add(listaPersonas, persona4);

	mostrarPersonas(listaPersonas);

	//--------------set----------------------------------------------------------
	puts("\n\nPor ej: ll_set:");
	puts("Se setea cualquier tipo de dato de la estructura\n");
	strcpy(persona4->nombre, "Jose Belucci");
	persona4->edad = 41;
	persona4->sexo = 'm';
	ll_set(listaPersonas, 3, persona4);
	mostrarPersona(persona4);

	//----------------index-----------------------------------------------------
	puts("\n\nPor ej: ll_indexOf:");
	puts(
			"Se manda el puntero a la persona y nos devuelve el indice en el que esta\n");

	indicePersona = ll_indexOf(listaPersonas, persona4);
	if (indicePersona != -1) {
		printf("Se encontro el indice %d de esta persona", indicePersona);
	} else {
		puts("No se encontro el indice de la persona");
	}

	//----------------------isEmpty--------------------------------------------

	puts("\n\nPor ej: ll_isEmpty:\n");

	if(!ll_isEmpty(listaPersonas)) // si la lista NO esta vacia, o sea != 1
	{
		puts("La lista de personas NO está vacía\n");
	}else
	{
		puts("La lista de personas está vacía\n");
	}

	//-------------------------------POP-----------------------------------------

	puts("Ejemplo de ll_pop: ");

	auxPersona = ll_pop(listaPersonas, 3);
	if(auxPersona != NULL)
	{
		puts("Se eliminó a la persona de la lista con pop\n");
		mostrarPersonas(listaPersonas);
	}else
	{
		puts("Hubo un error al elmininar a la persona\n");
	}

	//--------------------------contains--------------------------------------------

	puts("\nEjemplo de ll_contains: ");

	if(ll_contains(listaPersonas, persona4))
	{
		puts("Se encontro a la persona en la lista");
	}else
	{
		puts("Esta persona no se encuentra en la lista");
	}
	//-------------------clone---------------------------------------------------

	puts("\nEjemplo de ll_clone: ");
	listaEmpleados = ll_clone(listaPersonas);
	if(listaEmpleados != NULL)
	{
		puts("Se clono la lista de personas correctamente para hacer la de empleados\n");
	}else
	{
		puts("No fue posible crear la lista de empleados\n");
	}

	//-------------------contains all---------------------------------------------

	puts("\nEjemplo de ll_containsAll: ");
	if(ll_containsAll(listaPersonas, listaEmpleados))
	{
		puts("Ambas listas contienen todos los mismos elementos");
		tamListaPersonas = ll_len(listaPersonas);
		tamListaEmpleados = ll_len(listaEmpleados);

		printf("La lista de personas tiene un tamaño de: %d\nLa lista de empleados tiene un tamaño de: %d\n", tamListaPersonas, tamListaEmpleados);
	}else
	{
		puts("Faltan elementos en la lista");
	}
	//--------------------------clear----------------------------------------

	puts("\nEjemplo de ll_clear: ");
	if(!ll_clear(listaEmpleados))
	{
		puts("Se limpio la lista de empleados correctamente");

	}else
	{
		puts("No se pudieron limpiar los elementos de la lista");
	}

	//---------------------sublist------------------------------------------------
	puts("\nEjemplo de ll_sublist: ");
	listaEmpleados = ll_subList(listaPersonas, 0, 3);
	if(listaEmpleados != NULL)
	{
		puts("Se creo la lista correctamente\n");
		mostrarPersonas(listaEmpleados);

	}else
	{
		puts("No fue posible crear la lista\n");
	}

	//--------------------------push-------------------------------------------

	puts("\nEjemplo de ll_push: ");
	if(!ll_push(listaEmpleados, 3, auxPersona))
	{
		puts("Se agrego a la persona correctamente\n");

		mostrarPersonas(listaEmpleados);
	}else
	{
		puts("No fue posible agregar a la persona\n");
	}
	//--------------------------------------sort-----------------------------------







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
