/*
+-----------------------------------------------------------------------+
| C++ Code K-way-merge                                                  |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

#define SIZE   4
#define N      (SIZE * SIZE)


template <class Type>
class K_merge {

typedef pair<Type, int>       _pair;
typedef priority_queue< _pair, vector<_pair>, less<_pair> > _heap;
typedef vector<Type>          _ctnr;
typedef vector< queue<Type> > _list;

private:
    _ctnr   ans;
    _heap   pq;
    _list   data;

public:
    K_merge(const _list& __data): data(__data) { }

    void merge() {
        create_heap();
        adjust_heap();
    }

    _ctnr get_result() {
        return ans;
    }

private:
    void create_heap() {
        for (unsigned int i = 0; i < data.size(); i++) {
            _pair result(data[i].front(), i);
            pq.push(result);
            data[i].pop();
        }
    }

    void adjust_heap() {
        unsigned n = data.size() * (data[0].size() + 1);
        while (!pq.empty() && ans.size() < n) {
            _pair result = pq.top();
            pq.pop();
            ans.push_back(result.first);
            int i = result.second;
            if (!data[i].empty()) {
                _pair temp(data[i].front(), i);
                data[i].pop();
                pq.push(temp);
            }
        }
    }
};





// int main() {
//     vector< queue<int> > data(4);
//    // initialize
//     data[0].push(77), data[0].push(31), data[0].push(1);

//     data[1].push(69), data[1].push(25), data[1].push(14);

//     data[2].push(38), data[2].push(16), data[2].push(2);

//     data[3].push(41), data[3].push(12), data[3].push(0);

//     K_merge<int> kmerge(data);
//     kmerge.merge();
//     vector<int> ans = kmerge.get_result();
//     for (int i = 0; i < (int)ans.size(); i++)
//         cout << ans[i] << " ";
//     return 0;
// }
