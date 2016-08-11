/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reporte.h
 * Author: luigitercero
 *
 * Created on 8 de agosto de 2016, 02:16 PM
 */

#ifndef REPORTE_H
#define REPORTE_H
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct particion{
    char part_status;
    char part_type;
    char part_fit[2];
    int part_start;
    int part_size;
    char part_name[16];
}part;


typedef struct MBR{
    int mbr_tamanio;
    time_t *mbr_fecha_creacion;
    int mbre_disk_signature;
     part mbrPart1;
     part mbrPart2;
     part mbrPart3;
     part mbrPart4;

}mBR;

typedef struct EBR{
    char part_status;
    char part_fit;
    char part_start;
    char part_size;
    int part_next;
    char part_name[32];
}eBR;

typedef struct SB{
   int s_filesystem_type;
   int s_inodes_count;
   int s_blocks_count;
   int s_free_blocks_count;
   int s_free_inodes_count;
   time_t s_mt_count;
   time_t s_umtime;
   int s_mnt_count;
   int s_magic;
   int s_inode_size;
   int s_blcks_size;
   int s_first_ino;
   int s_first_blo;
   int s_bm_inode_start;
   int s_bm_block_start;
   int s_inode_start;
   int s_block_start;
}sB;



#ifdef __cplusplus
}
#endif

#endif /* REPORTE_H */

