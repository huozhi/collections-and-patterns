/*
+-----------------------------------------------------------------------+
| C++ Code hastable                                                     |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014 , CILAB. All rights reserved.               |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
*/

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;


template <class Key, class Value>
struct _node {
    _node(Key k, Value v) : _key(k), _val(v),
    _next(NULL) {}

    Key      _key;
    Value    _val;
    _node*   _next;
};

template <class Key, class Value>
class _hash_table {
private:
    typedef _node<Key, Value>  node;
private:
    vector<node *>  bkt_arr;
    size_t          bkt_size;
    size_t          ele_num;
private:
    node *make_node(Key k, Value v) {
        return new node(k, v);
    }

    size_t get_hash_pos(Key _key) {
        return _hash_method(_key) % bkt_size;
    }

    int _hash_method(Key _key) {
        return (unsigned int)_key;
        // not implement the string or char * type hash
    }
public:
    _hash_table(size_t __size) : bkt_size(__size), ele_num(0) {
        bkt_arr.resize(bkt_size);
        for (node*& head : bkt_arr) head = NULL;
    }

    bool insert_unique(const node& element) {
        size_t bkt_idx = get_hash_pos(element._key);
        node *pos = bkt_arr[bkt_idx];
        for (node *cur = pos; cur;) {
            if (element._key == cur->_key)
                return false;
            cur = cur->_next;
        }

        // construct new node
        node *tmp = make_node(element._key, element._val);

        // insert
        tmp->_next = pos;
        bkt_arr[bkt_idx] = tmp;
        ++ele_num;
        return true;
    }

    int get_ele_num() const {
        return ele_num;
    }

    Value getVal(Key _key) {
        size_t bkt_idx = get_hash_pos(_key);
        node *pos = bkt_arr[bkt_idx];
        for (node *cur = pos; cur;) {
            if (_key == cur->_key)
                return cur->_val;
            cur = cur->_next;
        }
        throw;
    }
};
