#pragma once
#include "cantor_expansion.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
/**
* @NOTICE:
*   规定数组下标从0开始
*/


#define ENABLE_FLOW_INFO 1

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
* @zero_pos: 0的位置(下标从0开始计数)
* @cur_depth: 当前递归深度
* @stp: 当前步数
*/
bool dfs(int zero_pos, int cur_depth, int stp);


/**
* @zero_pos:0的位置
*/
void IDDFS(int zero_pos, std::vector<int> init_stat);


/**
* @vec: 状态矩阵
*/
void printBoard(std::vector<int> vec);

/**
* @now_depth: 当前深度
* @stp: 移动次数
* @vec: 状态矩阵
* 打印所有信息
*/
void printAllInfo(int now_depth, int stp,int ev_mhn, std::vector<int> vec);