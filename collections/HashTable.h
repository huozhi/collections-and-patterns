/*
+-----------------------------------------------------------------------+
| C++ Code hastable                                                     |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014 , CILAB. All rights reserved.               |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

enum { num_primes = 28 };

static const unsigned long prime_list[num_primes] = {
  53ul,         97ul,         193ul,       389ul,       769ul,
  1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
  49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
  1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
  50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
  1610612741ul, 3221225473ul, 4294967291ul
};

template <class Key, class Value>
class HashTable {
    typedef pair<Key, Value> node_type;
    vector<list<node_type > > bukets;
    hash<Key> hasher;
    int num_elements;

public:
    HashTable(int n = 100): num_elements(0) { initlize(n); }

    void initlize(int n) {
        bukets.resize(n, list<node_type >());
        num_elements = 0;
    }

    size_t size() const { return num_elements; }

    inline unsigned long next_size(unsigned long n) const {
      const unsigned long* first = prime_list;
      const unsigned long* last = prime_list + (int)num_primes;
      const unsigned long* pos = lower_bound(first, last, n);
      return pos == last ? *(last - 1) : *pos;
    }

    size_t bkt_id_key(const Key& key) {
        return bkt_id_key(key, bukets.size());
    }

    size_t bkt_id(const Value& value) {
        return bkt_id(value, bukets.size());
    }

    size_t bkt_id_key(const Key &key, int n) {
        return hasher(key) % n;
    }

    size_t bkt_id(const Value& value, int n) {
        return hasher(get_key(value)) % n;
    }

    size_t bukets_num() const {
        return bukets.size();
    }

    Key get_key(const node_type& node) const {
        return node.first;
    }

    void resize(size_t new_num) {
        size_t old_n = bukets.size();
        if (new_num <= old_n) return;
        size_t next_num = next_size();
        if (next_num <= old_n) return;
        vector<list<node_type> > tmp(next_num, list<node_type>()); // new bukets
        for (size_t i = 0; i < bukets.size(); i++) {
            list<node_type> &buket = bukets[i];
            // j is list<node_type>::iterator type
            for (auto j = buket.begin(); j != buket.end(); j++) {
                size_t new_bkt_i = buket_index(*j);
                tmp[new_bkt_i].push_front(*j);
            }
        }
        bukets.swap(tmp);
    }

    vector<list<node_type> >& get_bukets() {
        return bukets;
    }


    node_type* insert_unique(const node_type& node) {
        Key key = node.first;
        Value val = node.second;
        size_t bkt_i = bkt_id_key(key);
        list<node_type> &buket = bukets[bkt_i];
        for (auto i = buket.begin(); i != buket.end(); i++) {
            if (i->second == val) {
                return &(*i);
            }
        }
        buket.push_front(pair<Key, Value>(key, val));
        ++num_elements;
        return &(*buket.begin());
    }

    node_type* find_node(const Key& key) {
        size_t bkt_i = bkt_id_key(key);
        list<node_type> &buket = bukets[bkt_i];
        for (auto i = buket.begin(); i != buket.end(); i++) {
            if (i->first == key) {
                return &(*i);
            }
        }
        return nullptr;
    }
};

/**

int main() {
    HashTable<int, int> ht;
    ht.insert_unique(pair<int, int>(1,3));
    ht.insert_unique(pair<int, int>(2,4));
    ht.insert_unique(pair<int, int>(3,5));
    ht.insert_unique(pair<int, int>(108,6));
    ht.insert_unique(pair<int, int>(104,7));
    ht.insert_unique(pair<int, int>(8,16));
    cout << "size: " << ht.size() << endl;
    vector<list<pair<int, int> > > b = ht.get_bukets();
    for(int i = 0; i < b.size(); i++) {
        list<pair<int, int> > ll = b[i];
        bool f = false;
        for (auto j = ll.begin(); j != ll.end(); j++) {
            cout << "[ " << j->first << " : " << j->second << " ], ";
            f = true;
        }
        if(f) cout << endl;
    }

    pair<int, int> *found;
    found = ht.find_node(8);
    if (found) {
        cout << "found: " << "[ " << found->first << " : " << found->second "] " << endl;
    }
    else {
        cout << "not found" << endl;
    }

    return 0;
}
*/