//
// Created by punk1u on 2020/11/4.
//
#include <stdio.h>
int main(){
    int  var = 20;   //* 实际变量的声明 *//*
    int var2 = 21;
    int  *ip;        //* 指针变量的声明 *//*



    ip = &var;  //* 在指针变量中存储 var 的地址 *//*


    printf("var address: %p\n", &var  );

    // 在指针变量中存储的地址 *//*
    printf("ip address: %p\n", ip );

    //* 使用指针访问值 *//*
    printf("*ip value: %d\n", *ip );

    ip = &var2;

    printf("var2 address: %p\n", &var2  );

    //* 在指针变量中存储的地址 *//*
    printf("ip address: %p\n", ip );

    //* 使用指针访问值 *//*
    printf("*ip value: %d\n", *ip );

    int **pp = &ip;
    printf(pp);

    

    return 0;
}

