//
// Created by punklu on 2020/12/14.
//

#include <stdio.h>

#define malloc
#define MALLOC(num,type) (type *) alloc((num) *sizeof(type))
extern void (size_t size);
