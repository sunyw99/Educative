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

class LevelOrderSuccessor {
   public:
    static TreeNode* findSuccessor(TreeNode* root, int key) {
        // TODO: Write your code here
        if (root == nullptr)
            return root;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int levelNodeCount = queue.size();
            for (int i = 0; i < levelNodeCount; i++) {
                TreeNode* currentNode = queue.front();
                if (currentNode->left != nullptr)
                    queue.push(currentNode->left);
                if (currentNode->right != nullptr)
                    queue.push(currentNode->right);
                queue.pop();
                if (currentNode->val == key)
                    return queue.front();
            }
        }
        return nullptr;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    TreeNode* result = LevelOrderSuccessor::findSuccessor(root, 12);
    if (result != nullptr) {
        cout << result->val << " " << endl;
    }
    result = LevelOrderSuccessor::findSuccessor(root, 9);
    if (result != nullptr) {
        cout << result->val << " " << endl;
    }
}
