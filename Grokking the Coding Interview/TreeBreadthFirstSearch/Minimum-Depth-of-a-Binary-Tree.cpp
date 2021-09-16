using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
   public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class MinimumBinaryTreeDepth {
   public:
    static int findDepth(TreeNode* root) {
        int minimumTreeDepth = 0;
        // TODO: Write your code here
        if (root == nullptr)
            return minimumTreeDepth;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            minimumTreeDepth++;
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = queue.front();
                if (currentNode->left != nullptr)
                    queue.push(currentNode->left);
                if (currentNode->right != nullptr)
                    queue.push(currentNode->right);
                if (currentNode->left == nullptr && currentNode->right == nullptr) {
                    return minimumTreeDepth;
                }
                queue.pop();
            }
        }
        return minimumTreeDepth;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
    root->left->left = new TreeNode(9);
    root->right->left->left = new TreeNode(11);
    cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}
