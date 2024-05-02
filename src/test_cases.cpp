#include "../include/test_cases.h"

namespace EP_TEST {
// 搜索用时
std::map<std::vector<int>,double> case_times;
// 无解
std::map<std::vector<int>, bool> no_answer;

int n = 9;
int cnt = 0;
double tms = 0;
std::vector<int> vis(n), p(n);
void dfs(int stp) {
        if(stp == n) {
            int pos = 0;
            for(int i = 0; i < n; ++i) if(p[i] == 0) {pos = i; break; }
            EightPuzzleInput::printBoard(p);
            auto start = std::chrono::high_resolution_clock::now();
            IDDFS(pos, p);
            // 获取结束时间点
            auto end = std::chrono::high_resolution_clock::now();

            // 计算函数运行时间
            std::chrono::duration<double> duration = end - start;

            // 输出运行时间（以秒为单位）
            case_times[p] = duration.count();
            cnt++; tms += duration.count();
        }
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            vis[i] = 1;
            p[stp] = i;
            dfs(stp + 1);
            vis[i] = 0;
        }
    };
void test_all_case() {
    dfs(0);
    std::cout<<"平均 "<<tms / cnt<<std::endl;
}

}