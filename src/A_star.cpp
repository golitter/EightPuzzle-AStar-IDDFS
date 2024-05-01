#include "../include/A_star.h"

namespace Direction {
namespace d4 { // 四个方向
std::vector<int> fx({0, 0, -1, 1});
std::vector<int> fy({1, -1, 0, 0});
int get_x(int idx) {
    return fx[idx];
}
int get_y(int idx) {
    return fy[idx];
}
}
}

// 记录状态是否存在
std::map<LL,bool> vis;
int max_depth = 0x3f3f3f3f;

// 移动数组
// std::vector<int> arr({1,2,3,0,4,6,7,5,8});
std::vector<int> arr({0, 1, 2, 3, 4, 5, 6, 7, 8});
// 目标状态数组
std::vector<int> target({0, 1, 2, 3, 4, 5, 6, 7, 8});

namespace EvaluationFunctions {
void d1_2_d2(int pos) {
    int x = pos / 3, y = pos % 3;
    std::cout<<pos<<" --> "<<"( "<<x<<", "<<y<<")\n";
}
int mhd_single(int target_pos, int current_pos) {
    // d1_2_d2(target_pos); d1_2_d2(current_pos);
    return std::abs(target_pos / 3 - (current_pos - 1) / 3) + std::abs(target_pos % 3 - (current_pos - 1) % 3);
}

int mhd(std::vector<int> vec) {
    int len = vec.size();
    int sum = 0;
    for(int i = 0; i < len; ++i) {
        if(vec[i] == 0) continue;
        sum += mhd_single(i, vec[i]);
    }
    return sum;
}
}

bool dfs(int zero_pos, int cur_depth) {
    int mhd = EvaluationFunctions::mhd(arr);
    if(mhd == 0) {
        // 找到目标
        return true;
    }
    if(cur_depth + mhd > max_depth) return false;
    int row = zero_pos / 3, col = zero_pos % 3;
    for(int i = 0; i < 4; ++i) {
        int x = row + Direction::d4::get_x(i);
        int y = col + Direction::d4::get_y(i);
        int new_pos = x * 3 + y; // 移动后的新位置

        // 越界
        if(x < 0 || x > 2 || y < 0 || y > 2) continue;
        std::swap(arr[zero_pos], arr[new_pos]);

        LL cantor = Cantor::cantor_value(arr);
        if(vis.find(cantor) != vis.end()) {
            // 状态已存在映射关系
            std::swap(arr[zero_pos], arr[new_pos]);
            continue;
        } 
        // 记录状态的映射
        vis[cantor] = true;
        if(dfs(new_pos, cur_depth + 1)) return 1;
        // 回溯
        std::swap(arr[zero_pos], arr[new_pos]);

    }
    return false;
}

void IDDFS(int zero_pos) {

    int mhd = EvaluationFunctions::mhd(arr);
    if(mhd == 0) { // 对0特判
        std::cout<<0<<std::endl;
        return ;
    }
    std::cout<<mhd<<std::endl;
    max_depth = 0;
    // #@NOTICE: 每次都改动 ******************************************************************************************************
    while(++max_depth) {
        vis = std::map<LL,bool>();
        if(dfs(zero_pos, 0)) break;
    } 
    std::cout<<max_depth<<std::endl;
}

// void dispose()