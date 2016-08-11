/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: luigitercero
 *
 * Created on 8 de agosto de 2016, 07:26 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "-MIA-201408606/AnalizadorLexico.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char comando[500];
   
    scanf("%[^\n\r]", comando);
    fflush(stdin);
    //"mdisk -size::100 +unit::k -path::"" -name::"disco.dsk""
    analizar(comando);
   
   
    return (EXIT_SUCCESS);
}

