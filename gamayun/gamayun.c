// mityawastaken
// gamayun.c
// inital release | 4/23/22
// update v1.0.6  | 4/30/22

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// no1 : file not found
struct ERR {
    const char *err_msg;
};

void FileErr() {
    const char *errors = "ATTRIBUTE FILE DOES NOT EXIST";

    struct ERR err = (struct ERR) {
        .err_msg = errors,
    };

    printf("%s", err.err_msg);
}

void FileTypeError() {
    const char *errors = "FILE TYPE UNSUPPORTED";

    struct ERR err = (struct ERR) {
        errors = errors,
    };
    
    printf("%s", err.err_msg);
}

// function gets the amount of time it takes for a program to exectue
void getTime(const char *type, char *filename) {

    char command[100];
    switch(type){
        case "c":
            sprintf(command, "gcc %s -o main; ./main", filename);
            break;
        case "python":
            sprintf(command, "python3 %s", filename);
            break;
        case "java":
            sprintf(command, "java %s", filename);
            break;
        case "":
            FileTypeError();
    }

    time_t t = clock();

    system(command);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nTIME TAKEN\n%f\n---------------------\n", time_taken);
}


void getSize(char type[], const char *file) {
    char command[100];
    switch(type) {
        case "c":
            sprintf(command, "gcc %s -o main; ./main", file);
            break;
        case "python":
            sprintf(command, "python3 %s", file);
            break;
        case "java":
            sprintf(command, "java %s", file);
            break;
        case "":
            FileTypeError();
            break;

    }

    FILE* fp = fopen(file, "r");

    if(fp == NULL) {
        FileErr();
    }
    fseek(fp, 0L, SEEK_END);

    long int res = ftell(fp);

    fclose(fp);
    system(command);

    printf("\nSPACE CONSUMED\n%lu\n---------------------\n", res);

}
