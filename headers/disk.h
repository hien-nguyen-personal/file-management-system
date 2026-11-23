#ifndef DISK_H
#define DISK_H

#include "block.h"
#include "sector_number.h"

typedef struct { 
    union block sectors[100]; 
    SectorNumber freeSectors[99]; 
    SectorNumber *currentSector;
    union block *currentDirectory;
} Disk;

void initialize_disk(struct Disk *disk);