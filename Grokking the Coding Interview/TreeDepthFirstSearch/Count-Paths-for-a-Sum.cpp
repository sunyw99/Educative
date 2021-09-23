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

class CountAllPathSum {
   public:
    static int countPaths(TreeNode* root, int S) {
        // TODO: Write your code here
        vector<int> currentPath;
        return countPathsHelper(root, S, currentPath);
    }

   private:
    static int countPathsHelper(TreeNode* root, int S, vector<int>& currentPath) {
        if (root == nullptr)
            return 0;
        currentPath.push_back(root->val);
        int pathSum = 0, pathCount = 0;
        for (vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend(); itr++) {
            pathSum += *itr;
            if (pathSum == S)
                pathCount++;
        }
        pathCount += countPathsHelper(root->left, S, currentPath);
        pathCount += countPathsHelper(root->right, S, currentPath);
        currentPath.pop_back();
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}
