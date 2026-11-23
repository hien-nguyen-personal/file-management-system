union block {
    struct { 
        int back; 
        int frwd; 
        int free; 

        struct { 
            char type; 
            char name[9]; 
            int link;
            short size; 
        } dir[25]; 
    } directory; 

    struct {
        int backf; 
        int frwdf; 
        char userdata[504]; 
    } data;
};

union block create_directory(int back, int frwd) {
    union block b; 

    b.directory.back = back; 
    b.directory.frwd = frwd; 
    b.directory.free = 25;

    for (int i = 0; i < 25; i++) {
        b.directory.dir[i].type = 'F'; 
        b.directory.dir[i].name[0] = '\0'; 
        b.directory.dir[i].link = 0; 
        b.directory.dir[i].size = 0;
    }

    return b;
}

union block create_file(int backf, int frwdf) {
    union block d; 

    d.data.backf = backf; 
    d.data.frwdf = frwdf; 
    d.data.userdata = NULL;

    return d;
}