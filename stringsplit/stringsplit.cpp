#include"stringsplit.h"
#include "iostream"

vector<string> split(string src, string pattern)
{
    string::size_type pos;
    vector<string> result;
    src+=pattern;
    int size = src.size();

    for(int i=0; i < size; ){
        pos = src.find(pattern, i);
        cout << "pos:" << pos << endl;
        if (pos != string::npos)
        {
            string s = src.substr(i, pos-i);
            if (! s.empty()){
                result.push_back(s);
            }
            i = pos+ pattern.size();
        } else{
            i = pos +pattern.size();
        }

    }

    return result;
}
