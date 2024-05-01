#include "../include/cantor_expansion.h"

namespace Cantor {

LL fact[MaxSize] = {1,1,2,6,24,120,720,5040,40320,362880}; // 定义0~9的阶乘表

LL get_fact(int idx, int count) {
    if(n - idx - 1 < 0) {
        std::cerr<<"ERROR!!!"<<std::endl;
        exit(0);
    }
    return fact[n - idx - 1] * count;
}

LL cantor_value(std::vector<int> vec) {
    LL sum = 0; //记录总的在s之前数目
    int len = vec.size();
    for(int i = 0; i < len; ++i) {
        int cnt = 0;
        for(int j = i + 1; j < len; ++j) {
            if(vec[j] < vec[i]) ++cnt;
        }
        sum += get_fact(i, cnt);
    }
    return sum + 1;
}
}