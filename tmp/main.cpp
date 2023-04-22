//
// Created by 17336 on 2023/4/6.
//

#include <stdio.h>

#define PERSON(x) #x

int var1;
int var2=1234;
extern int var3;

int main(){
    printf("hello,%s",PERSON(zhangle));
    var1=3;
    var2=3;
    var3=3;
    return 0;
}