#pragma once
#include <iostream>
#include <string>
#include <vector>
namespace EightPuzzleInput {

// 开始
void start();

// 主界面
void display_menu();

// 检查初始状态是否合法
bool check_init_stat(std::vector<int> vec);

// 以棋盘格式打印八数码
void printBoard(std::vector<int> vec);

// 输入初始状态
void input_init_stat();
// 输入目标状态
void input_target_stat();

}