//
// 在数组中寻找某个特定整型值的存储位置，并返回一个指向该位置的指针
// Created by punk1u on 2020/11/12.
//
#include <stdio.h>

int * find_int(int key,int array[],int array_len){
    int i;

    /**
     * 对于数组中的每个位置
     */
    for (int i = 0; i < array_len; i+=1) {
        if (array[i] == key)
            return &array[i];
    }
    return NULL;
}

