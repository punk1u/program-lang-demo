//
// Created by punklu on 2020/12/4.
//

/**
* 判断参数是否与一个关键字列表中的任何单词匹配，并返回匹配的索引值。
 * 如果未找到匹配，函数返回-1
*/

#include <string.h>

int lookup_keyword(char const * const desired_word,
        char const *keyword_table[],int const size){
    char const **kwp;

    /**
     * 对于表中的每个单词
     */
     for(kwp = keyword_table;kwp < keyword_table + size;kwp++){
         /**
          * 如果这个单词与所查找的单词匹配，返回它在表中的位置。
          */
          if (strcmp(desired_word,*kwp) == 0){
              return kwp - keyword_table;
          }
     }
     /**
      * 没有找到
      */
      return -1;
}