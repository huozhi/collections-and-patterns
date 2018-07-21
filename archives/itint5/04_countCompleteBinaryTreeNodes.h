/*

给定一棵完全二叉树（查看定义）的根结点，统计该树的结点总数。

使用getLeftChildNode(TreeNode)获得左儿子结点
使用getRightChildNode(TreeNode)获得右儿子结点
使用isNullNode(TreeNode)判断结点是否为空

*/


int count_perfect_binary_tree_nodes(int height) {
    return (int)pow(2, height) - 1;
}

int get_height(TreeNode node) {
    int h = 0;
    while (!isNullNode(node)) {
        node = getLeftChildNode(node);
        ++h;
    }
    return h;
}

int count_complete_binary_tree_nodes(TreeNode root) {
    int cnt = 0;
    while (!isNullNode(root)) {
        int left_h  = get_height(getLeftChildNode(root)),
            right_h = get_height(getRightChildNode(root));
        // when left subtree is perfect binary tree
        if (left_h == right_h) {
            cnt += count_perfect_binary_tree_nodes(left_h) + 1;
            root = getRightChildNode(root);
        }
        // if not equal, left and right subtrees are in last second level
        else {
            cnt += count_perfect_binary_tree_nodes(right_h) + 1;
            root = getLeftChildNode(root);
        }
        
    }
    return cnt;
}