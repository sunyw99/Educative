#include <iostream>
#include <vector>

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

class PathWithGivenSequence {
   public:
    static bool findPath(TreeNode* root, const vector<int>& sequence) {
        // TODO: Write your code here
        if (root == nullptr) {
            return sequence.empty();
        }
        return findPathHelper(root, sequence, 0);
    }

   private:
    static bool findPathHelper(TreeNode* root, const vector<int>& sequence, int depth) {
        if (root == nullptr)
            return false;
        if (depth > sequence.size() - 1 || sequence[depth] != root->val)
            return false;
        if (root->left == nullptr && root->right == nullptr && sequence.size() == depth + 1) {
            return true;
        }
        return findPathHelper(root->left, sequence, depth + 1) || findPathHelper(root->right, sequence, depth + 1);
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);

    cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7})
         << endl;
    cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
         << endl;
}
