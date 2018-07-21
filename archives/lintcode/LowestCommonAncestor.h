/**

给定一棵二叉树，找到两个节点的最近公共父节点(LCA)。

最近公共祖先是两个节点的公共的祖先节点且具有最大深度。

样例
给出如下二叉树：

       4

    /     \

  3         7

          /     \

        5         6

节点3和5，它们的LCA是4

节点5和6，它们的LCA是7

节点6和7，它们的LCA是7

*/

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        father.clear();
        if (!root) return NULL;
        make_rel(root);
        return trace(root, A, B);
    }

private:
    unordered_map<TreeNode *, TreeNode *> father;

    void make_rel(TreeNode *root) {
        if (!root) return;
        if (root->left) {
            father[root->left] = root;
            make_rel(root->left);
        }
        if (root->right) {
            father[root->right] = root;
            make_rel(root->right);
        }
    }

    TreeNode *trace(TreeNode *root, TreeNode *child, TreeNode *check) {
        vector<TreeNode *> v;
        v.push_back(child);
        while (father.find(child) != father.end()) {
            TreeNode *f = father[child];
            v.push_back(f);
            child = f;
        }
        while (father.find(check) != father.end()) {
            TreeNode *f = father[check];
            for (auto it = v.begin(); it != v.end(); it++) {
                if (*it == check) return check;
            }
            check = f;
        }
        return check;
    }
};
