#include <stdio.h>
struct students{
    char *name;
    int num;
    int age;
    char group;
    float score;
}sut1,sut2 = {"login",19,20,'A',2.7};
/*
  注意：
  1.结尾分号
  2.成员变量不需要初始化
*/
//结构体考察点：所占内存大小（字节）
//内存连续存储，和数组相同
//从电脑中取出内存使用  原则：按照数据类型最大的取出，之后存放结构体中的数据类型。
int main()
{
/*
    结构体   枚举    共用体
    共用体：大端小端（底层C语言开发）/枚举型

    做对比：数组和结构体区别
    结构体：一些不同类型数据的集合
    struct XXX{};

*/
    sut1.name = "login";
    printf("%s",sut1.name);


    //实际应用：描述一类事物中有不同种数据类型的属性
    //与数组结合  与指针结合
    struct students arr[5] = {sut1,sut2};
    return 0;
    //结构体标准写法：typedef struct contact{}Contact,*Pcontact;
}
