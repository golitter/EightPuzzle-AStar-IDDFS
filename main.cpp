#include <iostream>
#include "include/cantor_expansion.h"
#include "include/A_star.h"
#include "include/input_processor.h"
#include "include/test_cases.h"
void test_Cantor() {
    std::cout<<Cantor::get_fact(3, 4)<<std::endl;
    
}
void test_Ev() {
    std::cout<<EvaluationFunctions::mhd_single(1, 3)<<std::endl;
    std::cout<<Direction::d4::get_x(3)<<std::endl;
}
void test_Eight() {
    
    IDDFS(3, {1,2,3, 0, 4, 6, 7,5, 8});
    // IDDFS(9, {1,2,3,4,5,6,7,8,0});
    // IDDFS(2, {1,2,0,3,4,5,6,7,8});
}
void test_TEST() {
    EP_TEST::test_all_case();
}
int main(int, char**){
    std::cout << "Hello, from EightPuzzle-AStar-IDDFS!\n";
    // test_Cantor();
    // test_Ev();
    // EightPuzzleInput::start();
    test_Eight();
    // test_TEST();
}
