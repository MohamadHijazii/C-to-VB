#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *getVariablename(char *s,char **val){
    char *it = s;
    for(;*it != '\0';it++){
        if(*it == '='){
            *it = '\0';
            *val = it+1;
        }
    }
    return s;
}