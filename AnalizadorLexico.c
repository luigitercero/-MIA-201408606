#include <string.h>
#include "string.h"
#include "AnalizadorLexico.h"

int analizar(char comando[300]) {
    printf("hoal");

    split = strtok(comando, " ");

    printf("(%s)", split);
    printf("\n");


    if (strcasecmp(split, "mdisk")) {// primer token

        if (strcasecmp(split, "rmdisk")) {// segundo token

            if (strcasecmp(split, "fdisk")) {// tercer token
                error(0);

            } else {
                printf("Son iguales\n");
            }
        } else {
            printf("Son iguales\n");
        }
    } else {

        split = strtok(NULL, "::");
        printf("siguiente token (%s) \n", split);
        S0_Size();
    }


}

void error(int numError) {


    switch (numError) {
        case 0:
            printf("el sistema no encuentra la orden");
            break;
        case 1:
            printf("el sistema no reconoce la funcion del tamanio \"-size::cualquier numero positivo\"");
            break;
        case 2:
            printf("el numero no coincide en el rango admitido");
            break;
        case 3:
            printf("no se define la unidad k y m");
            break;
        case 4:
            printf("el nombre del disco no se ha definido");
    }


}

void S0_Size() {

    int num;

    split;

    if (strcasecmp(split, "-size")) {
        error(1);
    } else {

        split = strtok(NULL, " ");
        split++;

        int num = 0;

        num = (int) strtol(split, (char**) NULL, 10);

        if (num > 0) {
            printf("num s0 (%s) \n", split);
            S1_unit();

        } else {
            error(2);
        }
    }

}

void S1_unit() {
    char* s1;
    split = strtok(NULL, "::");
    printf("siguiente token s1 (%s) \n", split);

    if (strcasecmp(split, "+Unit")) {
        //no vine +unit
        printf("S1  +unit (%s)", split);
        S2_path();

    } else {
        split = strtok(NULL, " ");
        split++;
        if (strcasecmp(split, "k")) {


            if (strcasecmp(split, "m")) {
                error(3);
            } else {
                alpath();
            }

        } else {
            alpath();
        }
    }

}

void alpath() {
    printf(" k o m (%s)\n", split);
    split = strtok(NULL, "::");
    printf("S1 al path (%s) \n", split);
    S2_path();

}

void S2_path() {
    if (strcasecmp(split, "-path")) {
        error(3);
    } else {
        split = strtok(NULL, " ");
        split++;

        printf("S2 el path es (%s) \n", split);
        S3_name();

    }
}

void S3_name() {
    split = strtok(NULL, "::");
    printf("S3  -name: (%s) \n", split);
    if (strcasecmp(split, "-name")) {
        error(4);
    } else {
        split = strtok(NULL, ".");
        
        split++;

        printf("S3 name es (%s) \n", split);
        split = strtok(NULL, "\"");
        
        
        printf("S3 el . dse es (%s) \n", split);
        
        if (strcasecmp(split, "")) {

        } else {
            split = strtok(NULL, ".");
            split++;
            split = strtok(NULL, " ");

        }

    }

}

