//
// Created by punklu on 2020/12/8.
//

#include <string.h>
#include <stdio.h>

int main () {
    char str[80] = "This is - a - message";
    const char s[2] = "-";
    char *token;

    /* 获取第一个子字符串 */
    token = strtok(str, s);

    /* 继续获取其他的子字符串 */
    while( token != NULL ) {
        printf( "%s\n", token );
        token = strtok(NULL, s);
    }
    printf("\n%s\n",str);
    return 0;
}