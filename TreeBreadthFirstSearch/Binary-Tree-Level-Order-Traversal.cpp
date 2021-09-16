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

class LevelOrderTraversal {
   public:
    static vector<vector<int>> traverse(TreeNode* root) {
        vector<vector<int>> result;
        // TODO: Write your code here
        if (root == nullptr)
            return result;
        queue<TreeNode*> queueBFS;
        queueBFS.push(root);
        while (!queueBFS.empty()) {
            int levelNodeCount = queueBFS.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelNodeCount; i++) {
                TreeNode* currentNode = queueBFS.front();
                currentLevel.push_back(currentNode->val);
                if (currentNode->left != nullptr)
                    queueBFS.push(currentNode->left);
                if (currentNode->right != nullptr)
                    queueBFS.push(currentNode->right);
                queueBFS.pop();
            }
            result.push_back(currentLevel);
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
    vector<vector<int>> result = LevelOrderTraversal::traverse(root);
    cout << "Level order traversal: ";
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}
