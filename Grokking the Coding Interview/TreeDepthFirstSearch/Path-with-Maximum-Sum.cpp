#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class MaximumPathSum {
   public:
    static int findMaximumPathSum(TreeNode* root) {
        // TODO: Write your code here
        int maxPathSum = numeric_limits<int>::min();
        calculateCurrentHeightMaxSum(root, maxPathSum);
        return maxPathSum;
    }

   private:
    static int calculateCurrentHeightMaxSum(TreeNode* root, int& maxPathSum) {
        if (root == nullptr)
            return 0;
        int leftMaxSum = max(calculateCurrentHeightMaxSum(root->left, maxPathSum), 0);
        int rightMaxSum = max(calculateCurrentHeightMaxSum(root->right, maxPathSum), 0);
        maxPathSum = max(maxPathSum, leftMaxSum + rightMaxSum + root->val);
        return max(leftMaxSum, rightMaxSum) + root->val;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;

    root = new TreeNode(-1);
    root->left = new TreeNode(-3);
    cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}
