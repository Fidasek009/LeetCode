#include <iostream>
#include <vector>

#define null NULL

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createTree(vector<int> arr, int i = 0) {
    if (i+1 > arr.size() || arr[i] == NULL) return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);
    return root;
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // end of branch
        if(!root) return false;
        // check sum
        int sum = targetSum - root->val;
        if(sum == 0 && !root->left && !root->right) return true;
        // top-down recursion
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

int main()
{
    // vector<int> a = {5,4,8,11,null,13,4,7,2,null,null,null,1}; // true
    // int b = 22;
    // vector<int> a = {};  // false
    // int b = 0;
    vector<int> a = {-2,null,-3};   // true
    int b = -5;
    TreeNode* root = createTree(a);
    

    Solution s = Solution();
    auto res = s.hasPathSum(root, b);
    cout << res;
    return 0;
}