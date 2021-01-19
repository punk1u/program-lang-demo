//
// Created by punk1u on 2020/10/25.
//
/**
 * 这个程序从标准输入中读取输入行并在标准输出中打印这些输入行
 * 每个输入行的后面一行是该行内容的一部分
 *
 * 输入的第一行是一串列标号，串的最后以一个负数结尾
 * 这些列标号成对出现，说明需要打印的输入行的列的范围
 * 例如，0 3 10 12 -1表示第0列到第三列，第10列到第12列的内容将被打印
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**  所能处理的最大列号 **/
#define MAX_COLS 20
/** 每个输入行的最大长度 **/
#define MAX_INPUT 1000

int read_column_numbers(int columns[],int max);
void rearrange(char *output,char const *input,int n_columns,int const columns[]);

int main(void){
    /** 进行处理的列标号 **/
    int n_columns;
    /** 需要处理的列数 **/
    int columns[MAX_COLS];
    /** 容纳输入行的数组 **/
    char input[MAX_INPUT];
    /** 容纳输出行的数组 **/
    char output[MAX_INPUT];

    /**
     * 读取该串列标号
     */
    n_columns = read_column_numbers(columns,MAX_COLS);

    /**
     * 读取、处理和打印剩余的输入行
     * gets函数从标准输入读取一行文本并把它存储于作为参数传递给它的数组中。
     * 一行输入由一串字符组成，以一个换行符结尾。gets函数丢弃换行符，
     * 并在该行的末尾存储一个NUL字节（一个NUL字节是指字节模式为全0的字节，类似'\0'这样的字符常量）。
     * 然后，gets函数返回一个非NULL值，表示该行已被成功读取，当gets函数被调用但事实上不存在输入行时，它就返回NULL值，
     * 表示它到达了输入的末尾（文件尾）
     */
     while (gets(input) != NULL){
         printf("Original input : %s\n",input);
         rearrange(output,input,n_columns,columns);
         printf("Rearranged line : %s\n",output);
     }
    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[],int max){
    int num = 0;
    int ch;

    /**
     * 取得列标号，如果所读取的数小于0则停止
     * scanf函数从标准输入读取字符并根据格式字符串对它们进行转换。
     * scanf函数结束几个参数，其中第一个参数是一个格式字符串，用于描述期望的输入类型。
     * 剩下几个参数都是变量，用于存储函数所读取的输入数据。scanf函数的返回值是函数成功转换并存储于参数中的值的个数
     *
     * 格式码%d表示需要读取一个整型值。
     */
     while (num < max && scanf("%d",&columns[num]) == 1 && columns[num] >= 0){
         num += 1;
     }

     /**
      * 确认已经读取的标号为偶数个，因为它们是以对的形式出现的
      */
      if (num % 2 != 0){
          puts("Last column number is not paired.");
          exit(EXIT_FAILURE);
      }

      /**
       * 丢弃该行中包含最后一个数字的那部分内容
       * getchar函数从标准输入读取一个字符并返回它的值。
       * 如果输入中不存在任何字符，函数就会返回常量EOF（在stdio.h中定义），用于提示文件的结尾
       *
       * 字符只是小整型数而已，所以用一个整型变量容纳字符值不会引起任何问题
       */
       while ((ch= getchar()) != EOF && ch != '\n')
           ;

        return num;
}

/**
 * 处理输入行，将指定列的字符连接在一起，输出行以NULL结尾
 */
 void rearrange(char *output,char const *input,int n_columns,int const columns[]){
     /**
      * columns数组的下标
      */
     int col;

     /**
      * 输出列计算器
      */
     int output_col;

     /**
      * 输入行的长度
      */
     int len;

     len = strlen(input);
     output_col = 0;

     /**
      * 处理每对列标号
      */
    for (col = 0; col < n_columns; col+=2) {
        int nchars = columns[col + 1] - columns[col] + 1;

        /**
         * 如果输入行结束或输出行数组已满，就结束任务
         */
         if (columns[col] >= len || output_col == MAX_INPUT - 1)
             break;

         /**
          * 如果输出行数据空间不够，只复制可以容纳的数据
          */
          if (output_col + nchars > MAX_INPUT - 1)
              nchars = MAX_INPUT - output_col - 1;

          /**
           * 复制相关的数据
           * strncpy函数的第一个参数是目标字符串的地址，第二个参数是源字符串的地址，第三个参数是要复制的字符数量
           * strcpy函数与strncpy函数类似，但它并没有限制需要复制的字符数量。它接受两个参数：第2个字符串参数将被复制到第1个字符串参数，
           * 第1个字符串原有的字符将被覆盖。
           *
           * strcat函数也接受两个参数，但它把第2个字符串参数添加到第1个字符串参数的末尾。在这两个函数中，
           * 它们的第1个字符串参数不能是字符串常量。而且，确保目标字符串有足够的空间是程序员的责任，函数并不对其进行检查。
           *
           * 在字符串内进行搜索的函数是strchr，它接受两个参数，第1个参数是字符串，第2个参数是一个字符。这个函数在字符串参数内搜索字符参数第一次
           * 出现的位置，如果搜索成功就返回指向这个位置的指针，如果搜索失败就返回一个NULL指针。
           * strstr的功能类似，但它的第二个参数也是一个字符串，它搜索第二个字符串在第一个字符串中第一次出现的位置
           */
          strncpy(output + output_col,input + columns[col],nchars);
          output_col += nchars;
    }
    output[output_col] = '\0';
 }
