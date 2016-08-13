/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "console.h"
#include "AnalizadorLexico.h"
#include <stdio.h>
#include <stdlib.h>

void console() {
    printf("1. ingrasar linea\n");
    printf("2. salir\n");


}

void menu() {
    char comando[500];
    int opcion;
    do {
        console();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                fflush(stdin);
                printf("probar\n");
                scanf(" %[^\n]s", comando);

                analizar(comando);
                break;
            case 2:

                break;

        }

    } while (opcion != 2);

}

void prueba(char*caracter) {
    printf("hola %s", caracter);
    //analizar();
}
