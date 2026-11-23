#include "headers/block.h"
#include "headers/sector_number.h"

typedef struct { 
    union block sectors[100]; 
    SectorNumber freeSectors[99]; 
    SectorNumber *currentSector;
    union block *currentDirectory;
    union block *openFile; 
} Disk;

static void initialize_root_directory(Disk *disk) {
    union block root = create_directory(-1, -1);
    
    disk->sectors[0] = root;

    disk->currentDirectory = &disk->sectors[0];
}

static void initialize_free_sectors(Disk *disk) { 

    for (int i = 0; i < 99; i++) {
        disk->freeSectors[i].number = i + 1; 
    }

    for (int i = 0; i < 98; i++) {
        disk->freeSectors[i].link = &disk->freeSectors[i + 1];
    }

    disk->freeSectors[98].link = NULL;

    disk->currentSector = &disk->freeSectors[0];
}

void set_open_file(Disk *disk, union block *file) {
    disk->openFile = file;
}

void set_current_directory(Disk *disk, union block *directory) {
    disk->currentDirectory = directory;
}

void initialize_disk(Disk *disk) {
    initialize_root_directory(disk); 
    initialize_free_sectors(disk);

    disk->openFile = NULL;
}





