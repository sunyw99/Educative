using namespace std;

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

class SumOfPathNumbers {
   public:
    static int findSumOfPathNumbers(TreeNode* root) {
        int totalPathsSum = 0;
        // TODO: Write your code here
        return findSumOfPathNumbersHelper(root, 0);
    }

   private:
    static int findSumOfPathNumbersHelper(TreeNode* currentNode, int pathSum) {
        if (currentNode == nullptr) {
            return 0;
        }
        pathSum = 10 * pathSum + currentNode->val;
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            return pathSum;
        }
        return findSumOfPathNumbersHelper(currentNode->left, pathSum) + findSumOfPathNumbersHelper(currentNode->right, pathSum);
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}
