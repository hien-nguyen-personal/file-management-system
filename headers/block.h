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


union block create_directory(int back, int frwd); 

union block create_file(int backf, int frwdf);
