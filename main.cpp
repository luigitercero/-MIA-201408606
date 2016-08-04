/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luigitercero
 *
 * Created on 2 de agosto de 2016, 01:11 PM
 */

#include <cstdlib>
#include "AnalizadorLexico.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char comando[500];
   
    scanf("%[^\n\r]", comando);
    fflush(stdin);
    //"mdisk -size::100 +unit::k -path::\"luis\" -name::"disco.dsk""
    analizar(comando);
    char entrada[500];
    return 0;

}

