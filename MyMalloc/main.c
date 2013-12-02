//
//  main.c
//  MyMalloc
//
//  Created by Paulina Rubio Tarriba on 12/2/13.
//  Copyright (c) 2013 Paulina Rubio Tarriba. All rights reserved.
//

#include <stdio.h>


char memory[100];


void initMemory(){
    int i=0;
    for(i=0; i<100; i++){
        
        memory[i]='?';
    }
}

void* malloc_p(int size){
    
    int i=0;
    int crtSize=0;
    for(i=0; i<100; i++){
        if (memory[i]=='?'){
            if(crtSize==size){
                return &memory[i-size];
                
            }
            crtSize++;
        } else {
            crtSize=0;}
        
    }
}



int main(void){
    
    initMemory();
    char *string =(char*)malloc_p(5 * sizeof(char));
    strcpy(string,"test\0");
    printf("string: %s\n", string);
    
    int i=0;
    for(; i < 100; ++i){
        printf("char: %c\n", memory[i]);
    }
    return 0;
    
    
}





