/**
有一个长度为n的字符串str，有非常多的关键字query（长度不超过10），
需要判断每个关键字是否是str的子串。

注意：query是动态的输入进行查询的，预先并不知道所有的query。

请实现2个函数initWithString(str)和existSubString(query)。
我们会首先调用一次 initWithString(str)，你可以在这个函数中做一些预处理操作。
然后对于每一个query，函数existSubString(query)需要返回这个query是否为str的子串。

Solution:
subset + sort + binary search

*/

#include <string>
#include <vector>
using namespace std;


vector<string> ans;

void initWithString(char *str) {
    string src(str);
    set<string> strset;
    int len = (int)src.length();
    for (int i = 0; i < len; i++) {
        if (i + 10 >= len) {
            strset.insert(src.substr(i));
        }
        else {
            strset.insert(src.substr(i, 10));
        }
    }
    for (set<string>::iterator i=strset.begin(); i!=strset.end(); i++)
        ans.push_back(*i);
}

bool existSubString(char *query) {
    string pat(query);
    int low = 0, high = (int)ans.size()-1;

    while (low <= high) {
        bool found = true;
        int mid = (low + high) / 2;
        for (int i = 0; i < (int)pat.length(); i++) {
            if (ans[mid][i] < pat[i]) {
                low = mid + 1;
                found = false;
                break;
            }
            else if (ans[mid][i] > pat[i]) {
                high = mid - 1;
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }
    return false;
}