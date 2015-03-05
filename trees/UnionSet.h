#include <iostream>
using namespace std;


class u_set {
private:
    const int root = -1;
    int *_parent;
    int  _size;
public:
    u_set(int sz = 10):
        _size(sz), _parent(new int[_size]) { }
private:
    void init() {
        for (int i = 0; i < _size; ++i)
            _parent[i] = root;
    }

    int simple_find(int _i) {
        while (_parent[_i] != root)
            _i = _parent[_i];
        return _i;
    }

    void simple_merge(int _first, int _second) {
        if (_first != _second)
            _parent[_first] = _second;
    }

    void weight_merge(int _first, int _second) {
        int _temp = _parent[_first] + _parent[_second];
        if (_parent[_second] < _parent[_first]) {
        // first tree is under the second tree
            _parent[_first]  = _second;
            _parent[_second] = _temp;
        }
        else {
            _parent[_second] = _first;
            _parent[_first]  = _temp;
        }
    }

    int collapse_find(int _i) {
        int _r = _i; // root of tree i
        while (_parent[_r] != root) {
            int _p;
            while (_i != _r) {
                _p = _parent[_i];
                _parent[_i] = _r;
                _i = _p;
            }
        }
        return _r;
    }
};

