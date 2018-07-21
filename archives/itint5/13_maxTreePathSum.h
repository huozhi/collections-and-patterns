/*

给定一棵树的根结点，树中每个结点都包含一个整数值val。我们知道树中任意2个结点之间都存在唯一的一条路径，
路径值为路径上所有结点值之和。请计算最大的路径值（允许路径为空）。

样例：

      -10
     /  |  \
    2   3   4
       / \
      5  -1
         /
        6
       /
      -1
最大的路径值为13，相应的路径为5到6之间的路径。
扩展：此题算法也可用来解决另一个非常常见的面试题“树的直径”（求树中任意两结点路径的长度的最大值）。
可以认为树中每个结点的val值为1，那么求最长路径相当于求路径值最大的路径。

*/

int maxVal;

int findRecursively(TreeNode *root) {
    if (!root) return 0;
    int sz = root->children.size();
    int first = 0, second = 0;
    int rootVal = root->val;
    for (int i = 0; i < sz; i++) {
        int val = findRecursively(root->children[i]);
        if (val > first) {
            second = first;
            first = val;
        }
        else if (val > second) {
            second = val;
        }
    }
    maxVal = max(maxVal, rootVal + first + second);
    return max(rootVal + first, rootVal + second);
}

int maxTreePathSum(TreeNode *root) {
    if (!root) return 0;
    maxVal = 0;
    findRecursively(root);
    return maxVal;
}
