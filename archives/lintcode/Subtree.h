/**

有两个不同大小的二叉树： T1 有上百万的节点； T2 有好几百的节点。请设计一种算法，判定 T2 是否为 T1的子树。

样例
下面的例子中 T2 是 T1 的子树：

       1                3
      / \              / 
T1 = 2   3      T2 =  4
        /
       4
下面的例子中 T2 不是 T1 的子树：

       1               3
      / \               \
T1 = 2   3       T2 =    4
        /
       4
注意
若 T1 中存在从节点 n 开始的子树与 T2 相同，我们称 T2 是 T1 的子树。也就是说，如果在 T1 节点 n 处将树砍断，砍断的部分将与 T2 完全相同。

Solution:

brute force

*/

class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (!T2) return true;
        if (!T1) return false;
        return search(T1, T2);
    }

    bool compare(TreeNode *a, TreeNode *b) {
        if (!a && !b)
            return true;
        if (a && b) {
            if (a->val != b->val) return false;
            bool lcp = compare(a->left, b->left);
            bool rcp = compare(a->right, b->right);
            return lcp && rcp;
        }
        return false;
    }

    bool search(TreeNode *root, TreeNode *target) {
        if (!root) return false;
        if (compare(root, target))
            return true;    
        
        bool lcp = search(root->left, target);
        bool rcp = search(root->right, target);
        return lcp || rcp;
    
    }
};
