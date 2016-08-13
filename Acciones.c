
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
        printf("no se ha definido el nombre\n");
        return;

    } // primer token

    if (strcasecmp(ruta, "") == 0) {
        printf("no existe ruta\n");
        return;
    } // segundo token

    if (tamanio == NULL) {
        printf("no existe tamanio\n");
        return;
    } // tercer token

    if (unidad == NULL) {
        unidad = 1000;

    }

    mbr.mbr_tamanio = tamanio*unidad;
    time(&mbr.mbr_fecha_creacion);
    mbr.mbre_disk_signature = rand();

    mbr.mbrPart[0].part_status = '0';
    mbr.mbrPart[0].part_start = sizeof (mbr);
    mbr.mbrPart[1].part_status = '0';
    mbr.mbrPart[2].part_status = '0';
    mbr.mbrPart[3].part_status = '0';

    mbr.mbrPart[0].part_start = sizeof (mbr);
    mbr.mbrPart[1].part_start = -1;
    mbr.mbrPart[2].part_start = -1;
    mbr.mbrPart[3].part_start = -1;

    printf("\nstaus: %c\n", mbr.mbrPart[0].part_status);


    strcat(ruta, nombre);

    escribirArchivo(ruta, mbr);

}

void crearParticion(int size, int unit, char* path, char* type, char* fit, char* delete_, char *name, char *add_) {
    mBR mbr;

    if (strcasecmp(path, "0") == 0) {
        printf("no existe ruta\n");
        return;
    } // segundo token

    if (strcasecmp(name, "0") == 0) {
        printf("no existe el nombre\n");
        return;
    }

    mbr = leerDico(path);

    printf("leer mbr %i \n", mbr.mbr_tamanio);
    printf("nombre mbre %i \n", mbr.mbre_disk_signature);
    printf("1el mbr status  %c\n", mbr.mbrPart[0].part_status);
    printf("1el mbr status  %c\n", mbr.mbrPart[1].part_status);
    printf("1el mbr status  %c\n", mbr.mbrPart[2].part_status);
    printf("1el mbr status  %c\n", mbr.mbrPart[3].part_status);

    if (strcasecmp(delete_, "0") == 0) {

        if (strcasecmp(add_, "0") == 0) {

            mbr = trabajarDisco(mbr, size, unit, type, fit, name);
        } else {

        }
    } else {


    }

    printf("el mbr status  %c\n", mbr.mbrPart[0].part_status);
    printf("el mbr status  %c\n", mbr.mbrPart[1].part_status);
    printf("el mbr status  %c\n", mbr.mbrPart[2].part_status);
    printf("el mbr status  %c\n", mbr.mbrPart[3].part_status);

    escribirArchivo(path, mbr);
}

mBR trabajarDisco(mBR mbr, int size, int unit, char* type, char *fit, char* name) {

    if (mbr.mbr_tamanio > size * unit) {//hay una posibilidad de crear una particion

        if (existeNombre(mbr, name) == 0) { //se repite el nombre

            for (int n = 0; n < 4; n++) {

                if (mbr.mbrPart[n].part_status == '0') {
                    printf("este valor de particion se agregara %i\n", size * unit);

                    if (mbr.mbrPart[n].part_start == -1) {

                        mbr.mbrPart[n].part_start = ingresarByteInicio(mbr, n);
                    }

                    if (getTamanioMaximo(mbr, n) > size * unit) {
                        if (n == 0) {
                            mbr.mbrPart[0] = trabajarParticion(mbr.mbrPart[0], size, unit, type, fit, name, sizeof (mbr));
                        } else {
                            mbr.mbrPart[n] = trabajarParticion(mbr.mbrPart[n], size, unit, type, fit, name, ingresarByteInicio(mbr, n));
                        }
                        return mbr;

                    }
                }
            }
            printf("no es posible crear particion\n");

        }

    } else {
        printf("el tamnio del disco es muy pequenio para realizar operacion\n");

    }

    return mbr;
}

part trabajarParticion(part particion, int size, int unit, char* type, char *fit, char* name, int byteInicio) {
    particion.part_status = '1';
    strcpy(particion.part_fit, fit);
    strcpy(particion.part_name, name);
    particion.part_type = type;
    particion.part_size = size*unit;
    particion.part_start = byteInicio;
    return particion;
}

int existeNombre(mBR mbr, char *name) {

    for (int n; n < 4; n++) {

        if (strcasecmp(name, mbr.mbrPart[n].part_name) == 0) {
            printf("nombre de la particion es existente\n");
            return 1;
        }
    }
    return 0;
}

int ingresarByteInicio(mBR mbr, int actual) {
    return mbr.mbrPart[actual - 1].part_start + mbr.mbrPart[actual - 1].part_size;
}

int getTamanioMaximo(mBR mbr, int actual) {
    int tamanio;
    for (int n = actual + 1; n < 4; n++) {
        if (mbr.mbrPart[n].part_status == '1') {
            tamanio = -mbr.mbrPart[actual].part_start + mbr.mbrPart[n].part_start;
            return tamanio;
        }
    }

    tamanio = -mbr.mbrPart[actual].part_start + mbr.mbr_tamanio;
    printf("este el el tamnio maximo que se puede agregar %i\n", tamanio);
    return tamanio;
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

void desmontar() {
    // path = "";
}

void elScript(char path[500]) {

    char sentencia[500];
    FILE *file;
    file = fopen(path, "r");

    if (file == NULL) {

        printf("no existe el script\n");
        return;

    }
    while (fgets(sentencia, sizeof (sentencia), file)) {
        printf("\n\n\n");
        if (sentencia[0] == '#') {

            printf("%s", sentencia);

        } else {

            printf("%s\n\n\n  ", sentencia);
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
printf(" porawprasdfjadslkfjasdfasdfadsfasdfas%i ", mbr.mbr_tamanio);
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

void montarDisco(char *name, char *patha) {
    mBR mbr;
    printf("%s , %s", name, patha);
    montado[0].id = "vda1";
    //strcpy(montado[0].id, "vda1");
    montado[0].nombre = name;
    // strcpy(montado[0].nombre, name);
    montado[0].path = patha;
    //strcpy(montado[0].path, patha);
printf("pruba%s , %s\n",  montado[0].nombre, montado[0].path );

}

void crearGrafo(char* name, char* path, char* id) {
    mBR mbr;
    mbr = leerDico("discoDuro/disco.dsk");


    mostraMbr(mbr);
}

int getNombrepart(mBR mbr, char *name) {

    for (int n; n < 4; n++) {

        if (strcasecmp(name, mbr.mbrPart[n].part_name) == 0) {
            printf("nombre de la particion es existente\n");
            return n;
        }
    }
    return -1;
}
