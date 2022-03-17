#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "xml.c/src/xml.h"

int main() {
    FILE * stream;
    stream = fopen("file.xml", "r");
    struct xml_document* document = xml_open_document(stream);
    if (!document) {
		printf("Could parse document\n");
		exit(-1);
	} else {
        printf("fichero leido con exito\n");
    }

   
	struct xml_node* root = xml_document_root(document);
    int num_nodos=xml_node_children(root);
    printf("numero de nodos es %i\n",num_nodos);
    //aqui sucede el parseo
    struct xml_node* nodo0 = xml_node_child(root, 0);  //el segundo parametro (el numero) es el nodo que queremos leer, probar con 1, 2...
	struct xml_string* nombreNodo0 = xml_node_name(nodo0);
	struct xml_string* contenidoNodo0 = xml_node_content(nodo0);
    struct xml_string* atributoNombreNodo0 = xml_node_attribute_name(nodo0, 0); //el segundo parametro (numero) permite leer otro atributo
    struct xml_string* atributoContentNodo0 = xml_node_attribute_content(nodo0, 0);
    //convertir a cadena de texto normal
    char* nombreNodo0_S = calloc(xml_string_length(nombreNodo0) + 1, sizeof(char));
	char* contenidoNodo0_S = calloc(xml_string_length(contenidoNodo0) + 1, sizeof(char));
    char* atributoNombreNodo0_S = calloc(xml_string_length(atributoNombreNodo0) + 1, sizeof(char));
    char* atributoContentNodo0_S = calloc(xml_string_length(atributoContentNodo0) + 1, sizeof(char));
	xml_string_copy(nombreNodo0, nombreNodo0_S, xml_string_length(nombreNodo0));
	xml_string_copy(contenidoNodo0, contenidoNodo0_S, xml_string_length(contenidoNodo0));
    xml_string_copy(atributoNombreNodo0, atributoNombreNodo0_S, xml_string_length(atributoNombreNodo0));
    xml_string_copy(atributoContentNodo0, atributoContentNodo0_S, xml_string_length(atributoContentNodo0));
    

	printf("Nodo leido    N= %s *** C= %s\n", nombreNodo0_S, contenidoNodo0_S);
    printf("Atributo del nodo    N= %s *** C= %s\n", atributoNombreNodo0_S, atributoContentNodo0_S);

    //liberar memoria
	free(nombreNodo0);
	free(contenidoNodo0);
    free(atributoNombreNodo0);
    free(atributoContentNodo0);
    
}