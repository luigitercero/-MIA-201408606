
#include <string.h>
#include "string.h"
#include "AnalizadorLexico.h"
#include "Acciones.h"

int analizar(char comando[3000]) {

    split = strtok(comando, " ");

    printf("(%s)", split);
    printf("\n");

    if (strcasecmp(split, "mdisk")) {// primer token

        if (strcasecmp(split, "rmdisk")) {// segundo token

            if (strcasecmp(split, "fdisk")) {// tercer token

                if (strcasecmp(split, "mount")) {

                    if (strcasecmp(split, "umount")) {
                        error(0);

                    } else {
                        printf("umount");

                    }
                } else {
                    S13_MountPath();
                }


            } else {
                size = 0;
                unit = 1000;
                path = "0";
                type = 'p';
                fit = "wf";
                delete_ = "0";
                name = "0";
                add_ = "0";

                analizarFdisk();
                crearParticion(size, unit, path, type, fit, delete_, name, add_);

            }
        } else {
            S4_path();
        }
    } else {

        analizarmDisk();
        crearDisco(name, path, size, unit);
    }

}

void error(int numError) {


    switch (numError) {
        case 0:
            printf("el sistema no encuentra la orden\n");
            break;
        case 1:
            printf("el sistema no reconoce la funcion del tamanio \"-size::cualquier numero positivo\"\n");
            break;
        case 2:
            printf("el numero no coincide en el rango admitido\n");
            break;
        case 3:
            printf("no se define la unidad k y m\n");
            break;
        case 4:
            printf("el nombre del disco no se ha definido\n");
            break;
        case 5:
            printf("no se ha difinido el formato del disco\n");
            break;

    }
    return;

}

void analizarmDisk() {

    split = strtok(NULL, " ::");
    printf("(%s)", split);

    if (split == NULL)
        return;
    if (strcasecmp(split, "-size")) {// primer token

        if (strcasecmp(split, "+Unit")) {// segundo token

            if (strcasecmp(split, "-name")) {// tercer token

                if (strcasecmp(split, "-path")) {


                } else {
                    S2_path();
                }


            } else {
                S3_name();
            }
        } else {
            S1_unit();
        }
    } else {
        S0_Size();
    }

}

void S0_Size() {

    if (strcasecmp(split, "-size")) {
        error(1);
    } else {

        split = strtok(NULL, " ");
        split++;

        int num = 0;

        num = (int) strtol(split, (char**) NULL, 10);

        if (num > 0) {
            size = num;
            printf("num s0 (%s) \n", split);
            analizarmDisk();

        } else {
            error(2);
        }
    }

}

void S1_unit() {

    if (strcasecmp(split, "+Unit")) {
        //no vine +unit

        unit = 1024 * 2;
        analizarmDisk();

    } else {

        split = strtok(NULL, " ");
        split++;

        if (strcasecmp(split, "k")) {


            if (strcasecmp(split, "m")) {

                error(3);

            } else {

                unit = 1024 * 1024;

                analizarmDisk();

            }

        } else {

            unit = 1024;

            analizarmDisk();

        }
    }

}

void S2_path() {

    if (strcasecmp(split, "-path")) {
        error(3);
    } else {



        split = strtok(NULL, "\"");
        split = strtok(NULL, "\"");

        //split++;

        printf("S2 el path es (%s) \n", split);
        path = split;
        //split = strtok(NULL, "\"");

        printf("split++ (%s) \n", split);
        analizarmDisk();

    }
}

void S3_name() {

    if (strcasecmp(split, "-name")) {

        error(4);

    } else {

        printf("S3  -name: (%s) \n", split);
        split = strtok(NULL, ".");
        split++;
        split++;
        name = split;

        printf("s3 name (%s) \n", split);

        strcat(name, ".dsk");

        printf("S3 name es (%s) \n", split);

        split = strtok(NULL, "\"");
        printf("S3 el . ds es (%s) \n", split);

        if (strcasecmp(split, "dsk")) {

            error(5);

        } else {

            printf("termino de analizar cadena 1");
            printf("(%i, %i, %s,%s)", size, unit, path, name);
            analizarmDisk();


        }

    }

}

void S4_path() {
    if (strcasecmp(split, "-path")) {
        error(3);
    } else {



        split = strtok(NULL, "\"");
        split = strtok(NULL, "\"");

        //split++;

        printf("S2 el path es (%s) \n", split);
        path = split;
        //split = strtok(NULL, "\"");

        printf("split++ (%s) \n", split);
        analizarmDisk();
    }
}

void analizarFdisk() {
    split = strtok(NULL, " ::");
    printf("(%s)", split);

    if (split == NULL)
        return;
    if (strcasecmp(split, "-size")) {// primer token

        if (strcasecmp(split, "+unit")) {// segundo token

            if (strcasecmp(split, "-name")) {// tercer token

                if (strcasecmp(split, "-path")) {

                    if (strcasecmp(split, "+type")) {

                        if (strcasecmp(split, "+delete")) {

                            if (strcasecmp(split, "+add")) {

                                if (strcasecmp(split, "+fit")) {

                                } else {
                                    S9_FdiskFit();
                                }
                            } else {
                                S12_FdiskAdd();
                            }

                        } else {
                            S10_FdiskDelete();
                        }

                    } else {
                        S8_FdiskType();
                    }

                } else {
                    S7_FdiskPaht();
                }

            } else {
                S11_FdiskName();
            }

        } else {
            S6_FdiskUnit();
        }

    } else {
        S5_Fdisksize();
    }

}

void S5_Fdisksize() {

    if (strcasecmp(split, "-size")) {

        error(1);

    } else {

        split = strtok(NULL, " ");
        split++;

        int num = 0;

        num = (int) strtol(split, (char**) NULL, 10);

        if (num > 0) {

            printf("num s0 (%s) \n", split);
            
            size = num;
            analizarFdisk();
        } else {

            error(2);

        }
    }
}

void S6_FdiskUnit() {

    if (strcasecmp(split, "+Unit")) {
        //no vine +unit


        analizarFdisk();

    } else {

        split = strtok(NULL, " ");
        split++;

        if (strcasecmp(split, "k")) {



            if (strcasecmp(split, "m")) {

                if (strcasecmp(split, "b")) {
                    error(3);

                } else {

                    unit = 1;

                }

            } else {

                unit = 1024 * 1024;

                analizarFdisk();

            }

        } else {

            unit = 1024;

            analizarFdisk();

        }
    }

}

void S7_FdiskPaht() {

    if (strcasecmp(split, "-path")) {

        error(3);

    } else {

        split = strtok(NULL, "\"");
        split = strtok(NULL, "\"");

        //split++;

        printf("S2 el path es (%s) \n", split);
        path = split;
        //split = strtok(NULL, "\"");

        printf("split++ (%s) \n", split);
        analizarFdisk();
    }
}

void S8_FdiskType() {

    printf("siguiente token s1 (%s) \n", split);

    if (strcasecmp(split, "+type")) {
        //no vine +unit  
        analizarFdisk();

    } else {
        split = strtok(NULL, " ");
        split++;
        if (strcasecmp(split, "e")) {

            if (strcasecmp(split, "p")) {

                if (strcasecmp(split, "l")) {
                    error(3);
                } else {
                    type = 'l';
                    analizarFdisk();

                }
            } else {
                type = 'p';
                analizarFdisk();
            }

        } else {
            type = 'e';
            analizarFdisk();
        }
    }

}

void S9_FdiskFit() {

    if (strcasecmp(split, "+fit")) {
        //no vine +unit

        analizarFdisk();

    } else {
        split = strtok(NULL, " ");
        split++;
        if (strcasecmp(split, "Bf")) {

            if (strcasecmp(split, "FF")) {

                if (strcasecmp(split, "wf")) {
                    error(3);
                } else {
                    fit = "wf";
                    analizarFdisk();
                }

            } else {
                fit = "ff";
                analizarFdisk();
            }

        } else {
            fit = "bf";
            analizarFdisk();
        }
    }

}

void S10_FdiskDelete() {

    if (strcasecmp(split, "+delete")) {
        //no vine +unit  
        analizarFdisk();

    } else {
        split = strtok(NULL, " ");
        split++;

        if (strcasecmp(split, "fast")) {


            if (strcasecmp(split, "full")) {
                error(3);

            } else {
                delete_ = "full";
                analizarFdisk();
            }

        } else {
            delete_ = "fast";
            analizarFdisk();
        }
    }

}

void S11_FdiskName() {
    if (strcasecmp(split, "-name")) {
        error(3);
    } else {

       
        
        split = strtok(NULL, "\"");
        split = strtok(NULL, "\"");
printf("el name es: %s", split);
        //split++;

        name = split;
        //split = strtok(NULL, "\"");

        analizarFdisk();
    }

}

void S12_FdiskAdd() {

    if (strcasecmp(split, "+add")) {
        error(1);
    } else {

        split = strtok(NULL, " ");
        split++;

        int num = 0;

        num = (int) strtol(split, (char**) NULL, 10);

        if (num > 0) {
            printf("num s0 (%s) \n", split);
            size = num;
            add_ = "1";
            analizarFdisk();

        } else {
            error(2);
        }
    }


}

void S13_MountPath() {
    split = strtok(NULL, "::");
    if (strcasecmp(split, "-path")) {
        error(3);
    } else {
        split = strtok(NULL, " ");
        split++;

        printf("S2 el path es (%s) \n", split);

    }
}

void S14_MountName() {
    split = strtok(NULL, "::");
    printf("S3  -name: (%s) \n", split);
    if (strcasecmp(split, "-name")) {
        error(4);
    } else {
        split = strtok(NULL, " ");

        split++;

        printf("S3 name es (%s) \n", split);
        S12_FdiskAdd();
    }

}

void S15_idn() {
    split = strtok(NULL, "::");

    if (strcasecmp(split, "-id")) {
        error(4);
    } else {
        split = strtok(NULL, " ");

        split++;

        printf("S3 name es (%s) \n", split);
        S12_FdiskAdd();
    }
}



