using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
   public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;

    TreeNode(int x) {
        val = x;
        left = right = next = nullptr;
    }

    // tree traversal using 'next' pointer
    virtual void printTree() {
        TreeNode* current = this;
        cout << "Traversal using 'next' pointer: ";
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
    }
};

class ConnectAllSiblings {
   public:
    static void connect(TreeNode* root) {
        // TODO: Write your code here
        if (root == nullptr)
            return;
        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* previousNode = nullptr;
        while (!queue.empty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = queue.front();
                if (previousNode != nullptr) {
                    previousNode->next = currentNode;
                }
                previousNode = currentNode;
                queue.pop();
                if (currentNode->left != nullptr)
                    queue.push(currentNode->left);
                if (currentNode->right != nullptr)
                    queue.push(currentNode->right);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    ConnectAllSiblings::connect(root);
    root->printTree();
}
