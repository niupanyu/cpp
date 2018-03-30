#include<iostream>
#include<string>
#include<vector>

#include "stringsplit.h"

using namespace std;

int main(){
    string src = "123,3,3,3,3,";
    vector<string>  vgid;

    vgid = split(src, ",");
    for(auto &it:vgid)
    {
        cout << "==" << it << endl;
    }
    
    return 0;
}
