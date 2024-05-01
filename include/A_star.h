#pragma once
#include "cantor_expansion.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
/**
* @NOTICE:
*   规定数组下标从0开始
*/
typedef long long LL;

namespace Direction {
namespace d4 { // 四个方向
/**
* @idx: 上下移动
*/
int get_x(int idx);
/**
* @idx: 左右移动
*/
int get_y(int idx);
}
}


// 评估函数
namespace EvaluationFunctions {
/**
* @target_pos: 目标位置
* @current_pos: 当前位置元素
* @return: 这个位置对应目标状态的曼哈顿距离
* 目标是0-8
当前是1-9
*/
int mhd_single(int target_pos, int current_pos);

/**
* @vec: 一组八数码状态
* @return: 一组八数码对应目标八数组的总曼哈顿距离
*/
int mhd(std::vector<int> vec);

}

/**
* @zero_pos: 0的位置
* @cur_depth: 当前递归深度
*/
bool dfs(int zero_pos, int cur_depth);


/**
* @zero_pos:0的位置
*/
void IDDFS(int zero_pos);