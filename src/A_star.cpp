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
std::vector<int> arr({1, 2, 3, 4, 5, 6, 7, 8, 0});
// 目标状态数组
// std::vector<int> target({0,1, 2, 3, 4, 5, 6, 7, 8}); // 如需更改默认target，评估函数需要更改

namespace EvaluationFunctions {
void d1_2_d2(int pos) {
    int x = pos / 3, y = pos % 3;
    std::cout<<pos<<" --> "<<"( "<<x<<", "<<y<<")\n";
}
int mhd_single(int target_pos, int current_pos) {
    // d1_2_d2(target_pos); d1_2_d2(current_pos);
        return std::abs((target_pos ) / 3 - (current_pos - 1) / 3) + std::abs((target_pos ) % 3 - (current_pos - 1) % 3);

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
    // 得到当前状态的评估函数
    int mhd = EvaluationFunctions::mhd(arr);
    if(mhd == 0) {
        // 找到目标
        return true;
    }
    // 如果当前深度加上曼哈顿距离已经大于max_depth，直接返回。
    if(cur_depth + mhd > max_depth) return false;

    // 得到0在矩阵中的坐标 （行row，列col）
    int row = zero_pos / 3, col = zero_pos % 3;

    // 上下左右四个方向进行搜索
    for(int i = 0; i < 4; ++i) {
        int x = row + Direction::d4::get_x(i);
        int y = col + Direction::d4::get_y(i);

        // 得到下一个状态0的一维值
        int new_pos = x * 3 + y; // 移动后的新位置

        // 判断在二维是否越界
        if(x < 0 || x > 2 || y < 0 || y > 2) continue;
        // 没有越界，棋盘进行移动
        std::swap(arr[zero_pos], arr[new_pos]);
        
        // 得到康托展开的全排列序号
        LL cantor = Cantor::cantor_value(arr);
        // 如果在哈希表中找到，表示当前状态已存在于中间状态
        if(vis.find(cantor) != vis.end()) {
            // 状态已存在映射关系
            std::swap(arr[zero_pos], arr[new_pos]);
            continue;
        } 
        // 记录状态的映射
        vis[cantor] = true;
        if(dfs(new_pos, cur_depth + 1)) return 1;
        // 回溯：坐标回溯 + 状态剔除
        std::swap(arr[zero_pos], arr[new_pos]);
        vis.erase(cantor);

    }
    return false;
}

void IDDFS(int zero_pos, std::vector<int> init_stat) {
    arr = init_stat;
    int mhd = EvaluationFunctions::mhd(arr);
    if(mhd == 0) { // 对0特判
        std::cout<<0<<std::endl;
        return ;
    }
    std::cout<<mhd<<std::endl;
    max_depth = 0;
    // 无解情况考虑： 8！ https://www.luogu.com.cn/problem/solution/P1379
    // 状态只有 8!，8! = 40320，因此当 max_depth 大于40320时无解，退出迭代加深
    while(++max_depth <= 50000) {
        vis = std::map<LL,bool>();
        arr = init_stat;
        if(dfs(zero_pos, 0)) break;
    } 
    if(max_depth >= 50000) {
        std::cout<<"无解"<<std::endl;
    }
    std::cout<<max_depth<<std::endl;
    std::cout<<"结束"<<std::endl;
}

// void dispose()