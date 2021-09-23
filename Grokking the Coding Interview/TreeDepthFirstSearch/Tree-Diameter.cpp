using namespace std;

#include <algorithm>
#include <iostream>
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

class TreeDiameter {
   public:
    static int findDiameter(TreeNode* root) {
        int treeDiameter = 0;
        // TODO: Write your code here
        currentHeight(root, treeDiameter);
        return treeDiameter;
    }

   private:
    static int currentHeight(TreeNode* root, int& treeDiameter) {
        if (root == nullptr)
            return 0;
        int leftHeight = currentHeight(root->left, treeDiameter);
        int rightHeight = currentHeight(root->right, treeDiameter);
        if (leftHeight != 0 && rightHeight != 0) {
            treeDiameter = max(treeDiameter, leftHeight + rightHeight + 1);
        }
        return max(leftHeight, rightHeight) + 1;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
    root->left->left = nullptr;
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->left->right->left = new TreeNode(10);
    root->right->right->left->left = new TreeNode(11);
    cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
}
