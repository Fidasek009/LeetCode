#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(val < root->val) return searchBST(root->left, val);
        if(val > root->val) return searchBST(root->right, val);
        return root;
    }
};

// create a tree from array
TreeNode* createTree(vector<int> arr, int i = 0) {
    // Base case for recursion
    if (i+1 > arr.size()) return nullptr;

    // Create node
    TreeNode* root = new TreeNode(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);

    return root;
}

int main()
{
    vector<int> a = {4,2,7,1,3};
    int b = 2;
    TreeNode* root = createTree(a);

    Solution s = Solution();
    auto res = s.searchBST(root, 2);
    cout << res->val;
    return 0;
}