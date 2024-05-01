#pragma once

#include <iostream>
#include <vector>

namespace Cantor {

typedef long long LL;

const int MaxSize = 12;
// ***** 由于八数码问题是小于等于9个元素的，因此这里固定了n的大小
const int n = 10; // 0~9 共十个数字

/**
* @idx: 元素在数组中的下标
* @count: 在数组后面有多少个比当前元素小的元素个数
*/
LL get_fact(int idx, int count);

/**
* @vec: vec数组
*/
LL cantor_value(std::vector<int> vec);
}