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
int unit;
char **path;
char **name;
char type;
int size;
char **fit;
char **delete_;
char **add_;
char **id_;


#ifdef __cplusplus


extern "C" {


#endif

    int analizar(char comando [300]);

    //void analizar();
    void error(int numError);

    void S0_size();
    void S1_unit();
    void S2_path();
    void S3_name();
    void S4_path();
    void analizarmDisk();

    void S5_Fdisksize();
    void S6_FdiskUnit();
    void S7_FdiskPaht();
    void S8_FdiskType();
    void S9_FdiskFit();
    void S10_FdiskDelete();
    void S11_FdiskName();
    void S12_FdiskAdd();
    void analizarFdisk();

    void analizarMount();
    void S13_MountPath();
    void S14_MountName();

    void S15_Uid();

    void S16_Exect();
    
    void analizarRep();
    void S17_RepName();
    void S18_RepPath();
    void S19_id();
    void S20_Ruta();


#ifdef __cplusplus
}
#endif

#endif /* ANALIZADORLEXICO_H */

