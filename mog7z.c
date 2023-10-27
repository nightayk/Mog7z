#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <Windows.h>

int changeExtension(char *arg){
    char *dot;
    dot = strchr(arg,'.');

    int len;
    if (dot!=NULL){
        len = dot - arg;
    }else{
        len = strlen(arg);
    }

    char *newName;
    newName = malloc(len+4);

    strncpy(newName,arg,len);
    strcpy(newName+len,".7z");

    if (rename(arg,newName)==0){
        return 0;
    }else{
        return -1;
    }
}

int main(int argc,char *argv[]){
    SetConsoleOutputCP(65001);

    if (argc<2){
        return -1;
    }

    for(int i=1;i<argc;i++){
        changeExtension(argv[i]);
    }

    return 0;
}