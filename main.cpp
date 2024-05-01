#include <iostream>
#include "include/cantor_expansion.h"
void test_Cantor() {
    std::cout<<Cantor::get_fact(3, 4)<<std::endl;
}
int main(int, char**){
    std::cout << "Hello, from EightPuzzle-AStar-IDDFS!\n";
    test_Cantor();
}
