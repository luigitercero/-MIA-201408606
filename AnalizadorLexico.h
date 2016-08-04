/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnalizadorLexico.h
 * Author: luigitercero
 *
 * Created on 2 de agosto de 2016, 01:13 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ANALIZADORLEXICO_H
#define ANALIZADORLEXICO_H
char* split;
#ifdef __cplusplus


extern "C" {
    

    
int analizar(char comando [300]);
void error(int numError);
char* splitear(char cadena[300], char delimitador[2]);
char * siguienteCaracter();
int concatenarnum(char* nume);
void S0_size();
void S1_unit();
void S2_path();
void S3_name();
    
    
#endif




#ifdef __cplusplus
}
#endif

#endif /* ANALIZADORLEXICO_H */

