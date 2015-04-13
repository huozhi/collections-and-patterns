struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() { }
    TreeNode(int value):
        val(value),
        left(nullptr),
        right(nullptr) { }
};

class BinaryTree {
private:
    TreeNode *root;
public:

    BinaryTree(): root(nullptr) { }
    TreeNode *tree_root() const {
        return root;
    }

    void insert(int value) {
        TreeNode *curr = root, *parent = nullptr;
        if (curr == nullptr) {
            root = new TreeNode(value);
            return;
        }
        while (curr) {
            if (curr->val == value)
                return;
            else if (curr->val < value) {
                parent = curr;
                curr = curr->right;
            }
            else {
                parent = curr;
                curr = curr->left;
            }
        }
        if (parent) {
            if (parent->val > value)
                parent->left = new TreeNode(value);
            else
                parent->right = new TreeNode(value);
        }
    }

    void erase(int value) {
        TreeNode *curr = root, *parent = nullptr;
        int position = 0;
        while (curr && curr->val != value) {
            parent = curr;
            if (curr->val > value) {
                curr = curr->right;
                position = 1;
            }
            else {
                curr = curr->left;
                position = 2;
            }
        }
        if (!curr) return;
        if (curr->left && curr->right) {
            // has two children, get most left child of right subtree
            TreeNode *rtree = curr->right,
                     *prev = nullptr;
            while (rtree->left) {
                prev = rtree;
                rtree = rtree->left;
            }
            if (prev) prev->left = nullptr;
            rtree->left = curr->left;
            rtree->right = curr->right;

            if (position == 0) {
                root = rtree;
            }
            else if (position == 1) {
                parent->left = rtree;
            }
            else if (position == 2) {
                parent->right = rtree;
            }
            curr->left = curr->right = nullptr;
        }
        else if (curr->left || curr->right) {
            TreeNode *child;
            if (curr->left) {
                child = curr->left;
                curr->left = nullptr;
            }
            else {
                child = curr->right;
                curr->right = nullptr;
            }
            if (position == 0) {
                root = child;
            }
            else if (position == 1) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
        else {
            if (position == 0) {
                root = nullptr;
            }
            if (position == 1) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
            curr->left = curr->right = nullptr;
        }
    }
};