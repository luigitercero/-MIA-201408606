
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
   
    strcpy(mbr.mbrPart1.part_status, "0");
    strcpy(mbr.mbrPart2.part_status, "0");
    strcpy(mbr.mbrPart3.part_status, "0");
    strcpy(mbr.mbrPart4.part_status, "0");
    
    printf("\nnombre: %s", nombre);
    printf("\nruta: %s", ruta);
    //printf("leer mbr %i \n", mbr.mbr_tamanio);
   
    FILE * file;

    strcat(ruta, nombre);
    printf("\nrutanombre %s", ruta);

    //strcat(rutanombre, nombre);

    file = fopen(ruta, "wb+");
    int i;
    char byte[1];

    for (i = 0; i < tamanio; i++) {

        fwrite(byte, sizeof (byte), unidad, file);

    }

    rewind(file);
    fwrite(&mbr, sizeof (mbr), 1, file);
    fclose(file);

    leerDico(ruta);

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

void leerDico(char path[300]) {
    mBR mbr;
    FILE *file;
    file = fopen(path, "rb+");

    if (file == NULL) {
        printf("no existe");
        return;

    }

    fread(&mbr, sizeof (mbr), 1, file);
    printf("leer mbr %i \n", mbr.mbr_tamanio);
    printf("nombre mbre %i \n", mbr.mbre_disk_signature);


}
