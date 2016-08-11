#include <stdio.h>
#include "Reporte.h"


void mostraMbr() {

    FILE* file;
    file = fopen("mbr.dot", "w");
    
    fprintf(file, "digraph \"hashtable\"{\n");
    fprintf(file, "node [shape = box];\n");
    fprintf(file, "a0 [label=<");
    fprintf(file, "<TABLE border=\"1\" cellspacing=\"1\" cellpadding=\"1\"  >\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >Nombre   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >Fechade_creacion   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");

    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >mbr_disk_signature   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");

    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_status_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");    
    
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_type_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");   
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_fit_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_start_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_start_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_size_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_name_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >variable   </TD>\n");
    fprintf(file, "</TR>\n");
    
  
    
    
    fprintf(file, "</TABLE>>];}\n");
    fclose(file);
    system("dot -Tpng mbr.dot -o mbr.png -Gcharset=latin1");
    system("xdg-open mbr.png");


}


/*
void mostraMbr() {

    FILE* file;
    file = fopen("mbr.dot", "w");
    
    fprintf(file, "digraph \"hashtable\"{\n");
    fprintf(file, "node [shape = box];\n");
    fprintf(file, "a0 [label=<");
    fprintf(file, "<TABLE border=\"1\" cellspacing=\"1\" cellpadding=\"1\"  >\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >Nombre   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >Fechade_creacion   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");

    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >mbr_disk_signature   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");

    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_status_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");    
    
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_type_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");   
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_fit_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_start_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_start_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_size_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >0   </TD>\n");
    fprintf(file, "</TR>\n");
    
    fprintf(file, "<TR>\n");
    fprintf(file, "<TD border=\"1\" >part_name_1   </TD>\n");
    fprintf(file, "<TD border=\"1\" >variable   </TD>\n");
    fprintf(file, "</TR>\n");
    
  
    
    
    fprintf(file, "</TABLE>>];}\n");
    fclose(file);
    system("dot -Tpng mbr.dot -o mbr.png -Gcharset=latin1");
    system("xdg-open mbr.png");


}
*/
