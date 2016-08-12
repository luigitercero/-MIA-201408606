
#include <string.h>
#include <stdio.h>
#include <time.h>

#include <math.h>

#include "Acciones.h"
#include "Reporte.h"
#include "AnalizadorLexico.h"

void crearDisco(char* nombre, char* ruta, int tamanio, int unidad) {
    srand(time(NULL));
    mBR mbr;


    if (strcasecmp(nombre, "") == 0) {
        printf("no se ha definido el nombre");
        return;

    } // primer token

    if (strcasecmp(ruta, "") == 0) {
        printf("no existe ruta");
        return;
    } // segundo token

    if (tamanio == NULL) {
        printf("no existe tamanio");
        return;
    } // tercer token

    if (unidad == NULL) {
        unidad = 1000;

    }

    mbr.mbr_tamanio = tamanio*unidad;
    time(&mbr.mbr_fecha_creacion);
    mbr.mbre_disk_signature = rand();

    mbr.mbrPart1.part_status = '0';
    mbr.mbrPart2.part_status = '0';
    mbr.mbrPart3.part_status = '0';
    mbr.mbrPart4.part_status = '0';

    printf("\nstaus: %c", mbr.mbrPart1.part_status);
    printf("cannche gay");

    strcat(ruta, nombre);

    escribirArchivo(ruta, mbr);

}

void crearParticion(int size, int unit, char* path, char* type, char* fit, char* delete_, char *name, char *add_) {
    mBR mbr;

    if (strcasecmp(path, "0") == 0) {
        printf("no existe ruta");
        return;
    } // segundo token

    if (strcasecmp(name, "0") == 0) {
        printf("no existe el nombre");
        return;
    }

    mbr = leerDico(path);

    printf("leer mbr %i \n", mbr.mbr_tamanio);
    printf("nombre mbre %i \n", mbr.mbre_disk_signature);
    printf("1el mbr status  %c\n", mbr.mbrPart1.part_status);
    printf("1el mbr status  %c\n", mbr.mbrPart2.part_status);
    printf("1el mbr status  %c\n", mbr.mbrPart3.part_status);
    printf("1el mbr status  %c\n", mbr.mbrPart4.part_status);

    if (strcasecmp(delete_, "0") == 0) {

        if (strcasecmp(add_, "0") == 0) {

            mbr = trabajarDisco(mbr, size, unit, type, fit, name);
        } else {

        }
    } else {


    }

    printf("el mbr status  %c\n", mbr.mbrPart1.part_status);
    printf("el mbr status  %c\n", mbr.mbrPart2.part_status);
    printf("el mbr status  %c\n", mbr.mbrPart3.part_status);
    printf("el mbr status  %c\n", mbr.mbrPart4.part_status);
    
    escribirArchivo(path, mbr);
}

mBR trabajarDisco(mBR mbr, int size, int unit, char* type, char *fit, char* name) {

    if (mbr.mbr_tamanio > size * unit) {//hay una posibilidad de crear una particion

        if (existeNombre(mbr, name) == 0) { //se repite el nombre
            if (mbr.mbrPart1.part_status == '0') {

                mbr.mbrPart1 = trabajarParticion(mbr.mbrPart1, size, unit, type, fit, name, sizeof (mbr));
                return mbr;
            } else {
                if (mbr.mbrPart2.part_status == '0') {

                    mbr.mbrPart2 = trabajarParticion(mbr.mbrPart2, size, unit, type, fit, name, ingresarByteInicio(mbr.mbrPart1));
                    return mbr;
                } else {
                    if (mbr.mbrPart3.part_status == '0') {

                        mbr.mbrPart3 = trabajarParticion(mbr.mbrPart3, size, unit, type, fit, name, ingresarByteInicio(mbr.mbrPart2));
                        return mbr;
                    } else {
                        if (mbr.mbrPart4.part_status == '0') {

                            mbr.mbrPart4 = trabajarParticion(mbr.mbrPart4, size, unit, type, fit, name, ingresarByteInicio(mbr.mbrPart3));
                            return mbr;
                        } else {


                        }

                    }

                }

            }

        }

    }

}

part trabajarParticion(part particion, int size, int unit, char* type, char *fit, char* name, int byteInicio) {
    particion.part_status = '1';
    strcpy(particion.part_fit, fit);
    strcpy(particion.part_name, name);
    particion.part_type = type;
    particion.part_size = size;
    return particion;
}

int existeNombre(mBR mbr, char *name) {

    if (strcasecmp(name, mbr.mbrPart1.part_name)) {

        if (strcasecmp(name, mbr.mbrPart2.part_name)) {

            if (strcasecmp(name, mbr.mbrPart3.part_name)) {

                if (strcasecmp(name, mbr.mbrPart4.part_name)) {
                    return 0;
                }
            }
        }
    }
    printf("el valor nombre existe");
    return 1;

}

int ingresarByteInicio(part particionAnterior) {

    return particionAnterior.part_size + particionAnterior.part_size;

}


void borrarDisco(char* nombre, char* ruta) {


}

part agragarParticion(int part_size, char *part_status, char *part_type, char *part_fit, char *part_name) {

    part particion;

    strcpy(particion.part_fit, part_fit);
    strcpy(particion.part_name, part_name);
    particion.part_start = 0;
    strcpy(particion.part_type, part_type);
    strcpy(particion.part_status, part_status);
    particion.part_size = part_size;

    return particion;

}

void montarDisco(char *ruta) {
    //  path = ruta;

    mBR mbr;
    //File *file;
    //file = fopen (path, "rb+");

    /*
        if (file == NULL){
    
            printf("No existe archivo");
            return;
        
        }

        fread (&mbr, sizeof(mbr), 1, file);
     */


}

void desmontar() {
    // path = "";
}

void elScript(char path[500]) {

    char sentencia[500];
    FILE *file;
    file = fopen(path, "r");

    if (file == NULL) {

        printf("no existe el script");
        return;

    }
    while (fgets(sentencia, sizeof (sentencia), file)) {
        if (sentencia[0] == '#') {

            printf("comentario");

        } else {

            printf("script: %s", sentencia);
            analizar(sentencia);

        }
    }
}

mBR leerDico(char path[300]) {
    mBR mbr;
    FILE *file;
    file = fopen(path, "rb+");

    if (file == NULL) {
        printf("no existe el archivo \n");
        return;

    }

    fread(&mbr, sizeof (mbr), 1, file);

    return mbr;


}

void escribirArchivo(char* ruta, mBR mbr) {

    FILE * file;

    file = fopen(ruta, "wb+");
    int i;
    char byte[1];

    for (i = 0; i < mbr.mbr_tamanio; i++) {

        fwrite(byte, sizeof (byte), 1, file);

    }

    rewind(file);
    fwrite(&mbr, sizeof (mbr), 1, file);
    fclose(file);
}
