/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acciones.h
 * Author: luigitercero
 *
 * Created on 8 de agosto de 2016, 08:43 AM
 */

#ifndef ACCIONES_H
#define ACCIONES_H
#include "stdlib.h"
#include "time.h" 
#include "Reporte.h"
#ifdef __cplusplus
extern "C" {
#endif
    

    void crearDisco(char* nombre, char* ruta, int tamanio, int unidad);
    
    void borrarDisco(char* nombre, char* ruta);
    
//    part agragarParticion(int part_size,char part_status, char part_type, char part_fit, char part_name);
    
    void montarDisco(char* ruta);

    void desmontar();
    
    void elScript(char path[500]);
    
    void leerDico(char path[300]);
#ifdef __cplusplus
}
#endif

#endif /* ACCIONES_H */

