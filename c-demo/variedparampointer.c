//
// Created by punk1u on 2020/11/18.
//
#include <stdio.h>

int main(){
    int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    int *a = matrix + 1;
    int *b = *(matrix + 1);
    printf(b);
    int c =  *(matrix[1] + 1);
    printf(c);




}
