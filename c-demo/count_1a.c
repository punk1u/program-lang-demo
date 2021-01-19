//
// Created by punk1u on 2020/11/3.
//
// 使用右移位操作来计数一个值中值为1的个数，接受一个无符号参数，并使用%操作符判断最右边的一位是否为0
// 返回参数的二进制表示值中值为1的个数
int count_one_bits(unsigned value){
    int ones;

    for (ones = 0;value != 0;value = value >> 1) {
        if (value % 2 != 0){
            ones = ones + 1;
        }
    }
    return ones;
}


