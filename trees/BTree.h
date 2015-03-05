#ifndef __BTREE_H__
#define __BTREE_H__

#define KEY_NUM 256
typedef int type_t;


class btree {
private:
    struct bt_node {
        bt_node(bool _isleaf=true):leaf(_isleaf) {}
        int n;
        bool leaf;
        type_t key[KEY_NUM];
        bt_node *child[KEY_NUM + 1];
        bt_node *parent;
    };

    
public:
    btree() {

    }
};

#endif