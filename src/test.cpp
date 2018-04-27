#include<iostream>
#include<vector>

#include "test.h"

void for_range_demo(){
    std::vector<int> ivec{0,1,2,3,4,5};
    for(auto n : ivec){
        std::cout << n << " " ;        
    }
}


int main(){
    std::string tmp  = "ee";
    std::string str = "abc"  "123";
    std::cout << str << std::endl;
    std::cout << MYTEST << std::endl;
    
    for_range_demo();
}
