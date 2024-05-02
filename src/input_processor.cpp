#include "../include/input_processor.h"
#include <cstdio>

namespace EightPuzzleInput {

// 初始读入八数码
std::vector<int> init_stat;
// 目标状态
std::vector<int> target_stat;
// 开始
void start() {
    while(true) {
        std::cout<<"退出还是开始八数码，退出输入q"<<std::endl;
        std::string op; getline(std::cin, op);
        if(op.find("q") != std::string::npos) {
            break;
        } else {
            display_menu();
            getchar();
            // system("clear");
        }
    }
    std::cout<<"程序结束"<<std::endl;
}

bool check_init_stat(std::vector<int> vec) {
    std::vector<int> vis(10);
    for(auto &t: vec) {
        vis[t]++;
    }
    for(int i = 0; i < 9; ++i) {
        if(vis[i] == 1) continue;
        return false;
    }
    return true;
}

void printBoard(std::vector<int> vec) {
    int cnt = 0;
    for(int i = 0; i < 9; ++i) {
        std::cout<<vec[i]<<" ";
        cnt++;
        if(cnt == 3) {
            cnt = 0;
            std::cout<<std::endl;
        }
    }
}

void input_init_stat() {
    init_stat.clear();
    std::cout<<"请输入初始八数码"<<std::endl;
    int x;
    while(init_stat.size() < 9) {
        std::cin>>x;
        if(x < 0 || x >= 9) {
            std::cout<<"输入值 [ "<<x<<" ] 不合法，重新输 or 直接结束 (n/q)"<<std::endl;
            std::string op; getline(std::cin, op);
            if(op.find("n") != std::string::npos) {
                continue;
            } else {
                return ;
            }
        }
        init_stat.push_back(x);
    }
    if( !check_init_stat(init_stat)) {
        std::cout<<"初始状态不合法："<<std::endl;
        printBoard(init_stat);
        return ;
    }
    std::cout<<"初始状态为："<<std::endl;
    printBoard(init_stat);
    std::cout<<std::endl;
}

void input_target_stat() {
    target_stat.clear();
    // 撤销前一个getline残留的回车键
    std::cin.ignore();

    std::cout<<"是否为默认状态：[12345678-] (i)"<<std::endl;
    std::string op; getline(std::cin, op);
    if(op.find("i") != std::string::npos) {
        for(int i = 1; i < 9; ++i) target_stat.push_back(i);
        target_stat.push_back(0);
    } else {
        std::cout<<"请输入初始八数码"<<std::endl;
        int x;
        while(target_stat.size() < 9) {
            std::cin>>x;
            if(x < 0 || x >= 9) {
                std::cout<<"输入值 [ "<<x<<" ] 不合法，重新输 or 直接结束 (n/q)"<<std::endl;
                getline(std::cin, op);
                if(op.find("n") != std::string::npos) {
                    continue;
                } else {
                    return ;
                }
            }
            target_stat.push_back(x);
        }
        if( !check_init_stat(target_stat)) {
            std::cout<<"目标状态不合法："<<std::endl;
            printBoard(init_stat);
            return ;
        }
    }
    std::cout<<"目标状态为："<<std::endl;
    printBoard(init_stat);
    std::cout<<std::endl;
}


// 主界面
void display_menu() {
    input_init_stat();
    // input_target_stat();
}

}