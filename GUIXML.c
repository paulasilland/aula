#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "xml.c/src/xml.h"
#include "GUIXML.h"

struct xml_node* root;

int readXml() {
    FILE * stream;
    stream = fopen("file.xml", "r");
    struct xml_document* document = xml_open_document(stream);
    if (!document) {
		printf("Could parse document\n");
		exit(-1);
	} else {
        printf("fichero leido con exito\n");
    }


   
	root = xml_document_root(document);
}

char* readNodeContent(int icon){
    struct xml_node* nodo0 = xml_node_child(root, icon);  

	struct xml_string* contenidoNodo0 = xml_node_content(nodo0);

    char* contenidoNodo0_S = calloc(xml_string_length(contenidoNodo0) + 1, sizeof(char));

    xml_string_copy(contenidoNodo0, contenidoNodo0_S, xml_string_length(contenidoNodo0));

    free(contenidoNodo0);

    return contenidoNodo0_S;

}

char* readNodeAtribute(int icon, int atributeIcon){
    struct xml_node* nodo0 = xml_node_child(root, icon);  

    struct xml_string* atributoContentNodo0 = xml_node_attribute_content(nodo0, atributeIcon);

    char* atributoContentNodo0_S = calloc(xml_string_length(atributoContentNodo0) + 1, sizeof(char));

    xml_string_copy(atributoContentNodo0, atributoContentNodo0_S, xml_string_length(atributoContentNodo0));

    free(atributoContentNodo0);

    return atributoContentNodo0_S;

}

int ReadTotalIcons(){
    return xml_node_children(root);
}

struct Icon ReadIcon(int Icon){
    struct Icon i;
    i.Image= readNodeContent(Icon);
    i.Text = readNodeAtribute(Icon, 2);
    i.x = atoi(readNodeAtribute(Icon, 0));
    i.y = atoi(readNodeAtribute(Icon, 1));

    return i;
}