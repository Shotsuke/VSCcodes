#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
signed main()
{
    // vector重新实现了数组，同一类型的元素构成的有序集
    // 集合中的每个元素都有一个特定的位置，即索引（index）
    // 一个vector中的所有元素必须是同一类型的
    // 当作一个更高级的数组来用，存储的元素数量是可以变化的
    // 可以方便地从其中删除或添加元素，自身维护大小
    // 可以通过查询来知道一个vector中当前包含多少元素
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(15);
    vec.push_back(22);
    //或者：vector<int>={4,8,15}
    // value: 4  8  15 22
    // index: 0  1  2  3

    printf("vec[1]=%d\n", vec[1]);
    //访问元素用法相同于数组

    vector<int> copi(vec); //创建一个拷贝
    printf("copivec[1]=%d\n", copi[1]);

    vector<int> all(5, 8);
    for (int i = 0; i < 5; i++)
        printf("all[%d]=%d\n", i, all[i]);

    vector<int> allzero(5);
    for (int i = 0; i < 5; i++)
        printf("allzero[%d]=%d\n", i, allzero[i]);
    //圆括号（5）全部初始化为0，第二个参数表示为初始化的数（5，8）

    vector<int> counts = vector<int>(9, 0); //完成了一次函数调用

    // vector自带的一些函数
    vec.front() = 123;                             //修改首个元素
    vec.back() = 999;                              //修改尾部元素
    printf("vec.size()=%d\n", vec.size());         //访问元素个数
    printf("vec.capacity()=%d\n", vec.capacity()); //同为元素个数

    //遍历vector(c++11以上) range-based for 循环
    for (auto num : vec) // for(<type可以写auto>var : seq) statment
    {
        cout << num << endl;
    }

    return 0;
}