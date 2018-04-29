#include<iostream>
#include<vector>
#include<thread>

#include "easylogging++.h"
#include "test.h"

void exception_demo(){
	try{
		std::string("abc").substr(10);
	}catch(const std::exception& e){
		std::cout << e.what() << std::endl;
		//throw;
	}
}


void for_range_demo(){
    std::vector<int> ivec{0,1,2,3,4,5};
    for(auto n : ivec){
        std::cout << n << " " ;        
    }
}



void rollLog(){
    std::thread logRotatorThread([](){
        const std::chrono::seconds wakeupDelta = std::chrono::seconds(20);
        auto nextWakeUp = std::chrono::system_clock::now() + wakeupDelta;
        
        while(true){
            std::this_thread::sleep_until(nextWakeUp);
            nextWakeUp += wakeupDelta;
            LOG(INFO) << "About to rotate log file!" ;
            auto L = el::Loggers::getLogger("default");
            if(L== nullptr) LOG(ERROR) << "Oops, it is not called default!";
            else L->reconfigure();
        }
    }); 
    
    logRotatorThread.detach();
}

extern void jsontest();
INITIALIZE_EASYLOGGINGPP

int main(){
    jsontest();
    el::Configurations cfg("../cfg/easylogging.cfg");
    el::Loggers::reconfigureAllLoggers(cfg);
    std::string tmp  = "ee";
    std::string str = "abc"  "123";
    std::cout << str << std::endl;
    std::cout << MYTEST << std::endl;
    
    for_range_demo();
    exception_demo();
    
    rollLog();
    for (int n= 0; n < 1000; ++n){
        LOG(INFO) << "My firt info log using default logger";
        LOG(DEBUG)<< "My firt debug log using default logger";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    LOG(INFO) << "Shutting down.";
    return 0;
}
