/*

有一颗树，给定树中任意两个结点，计算出这两个结点的最近公共祖先

*/

struct TreeNode {
    TreeNode *parent;
};

TreeNode *getLCA(TreeNode *node1, TreeNode *node2) {
    if (!node1 || !node2) return NULL;
    TreeNode *p1 = node1, *p2 = node2;
    while (p1 && p2) {
        p1 = p1->parent; p2 = p2->parent;
    }
    int k = 0;
    bool flag = true;
    while (p1) {
        p1 = p1->parent; k++;
    }
    while (p2) {
        p2 = p2->parent; k++; flag = false;
    }

    p1 = node1; p2 = node2;
    if (flag) {
        while (k--) p1 = p1->parent;
    }
    else {
        while (k--) p2 = p2->parent;
    }
    while (p1 && p2 && p1!=p2) {
        p1 = p1->parent; p2 = p2->parent;
    }
    return p1;
}
