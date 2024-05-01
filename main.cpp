#include <iostream>
#include "include/cantor_expansion.h"
#include "include/A_star.h"
void test_Cantor() {
    std::cout<<Cantor::get_fact(3, 4)<<std::endl;
    
}
void test_Ev() {
    std::cout<<EvaluationFunctions::mhd_single(1, 3)<<std::endl;
    std::cout<<Direction::d4::get_x(3)<<std::endl;
}
void test_Eight() {
    IDDFS(4);
}
int main(int, char**){
    std::cout << "Hello, from EightPuzzle-AStar-IDDFS!\n";
    test_Cantor();
    test_Ev();
    test_Eight();
}
