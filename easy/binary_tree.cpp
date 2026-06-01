#include <iostream>
#include <vector>
#include <queue>

class BinaryTree {
public:
    struct TreeNode {
        int val{0};
        TreeNode *left{nullptr};
        TreeNode *right{nullptr};
        explicit TreeNode() {}
        TreeNode(int x) : val(x) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    void dfs(TreeNode* root, std::vector<int>& traversal) {
        if (root == nullptr) {
            return;
        }
        // pre-order
        traversal.emplace_back(root->val);
        // in-order
        dfs(root->left, traversal);
        // post-order
        dfs(root->right, traversal);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        auto traversal = std::vector<int>();
        dfs(root, traversal);
        return traversal;
    }

    // bfs using queue/fifo
    void bfs(TreeNode* root, std::vector<int>& traversal) {
        if (root == nullptr) {
            return;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            traversal.emplace_back(cur->val);
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }

    void bfs2(TreeNode* root, std::vector<int>& traversal) {
        if (root == nullptr) {
            return;
        }

        std::queue<TreeNode*> q;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            traversal.emplace_back(cur->val);
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }

    std::vector<int> levelOrderTraverse(TreeNode* root) {
        auto traversal = std::vector<int>();
        bfs(root, traversal);
        return traversal;
    }
};

int main() {
    BinaryTree bt;
    
    // 创建简单的树：
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    BinaryTree::TreeNode* root = new BinaryTree::TreeNode(1);
    root->left = new BinaryTree::TreeNode(2);
    root->right = new BinaryTree::TreeNode(3);
    root->left->left = new BinaryTree::TreeNode(4);
    root->left->right = new BinaryTree::TreeNode(5);

    std::vector<int> preorder = bt.preorderTraversal(root);
    std::cout << "Pre-order traversal: ";
    for (int val : preorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> levelOrder = bt.levelOrderTraverse(root);
    std::cout << "Level order traversal: ";
    for (int val : levelOrder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 清理内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
