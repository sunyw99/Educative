using namespace std;

#include <iostream>
#include <queue>
#include <vector>

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

class ZigzagTraversal {
   public:
    static vector<vector<int>> traverse(TreeNode* root) {
        vector<vector<int>> result;
        // TODO: Write your code here
        if (root == nullptr)
            return result;
        bool left2right = true;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> currentLevel(levelSize);
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = queue.front();
                if (left2right) {
                    currentLevel[i] = currentNode->val;
                } else {
                    currentLevel[levelSize - i - 1] = currentNode->val;
                }
                queue.pop();
                if (currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
            result.push_back(currentLevel);
            left2right = !left2right;
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(20);
    root->right->left->right = new TreeNode(17);
    vector<vector<int>> result = ZigzagTraversal::traverse(root);
    cout << "Zigzag traversal: ";
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
    }
}
