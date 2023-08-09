#include <iostream>
#include<vector>

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
private:
    bool validateL(TreeNode *root, int rootVal){
        if(!root) return true;

        // leafs need to be smaller than the root
        if(root->val >= rootVal) return false;

        // recursive DFS
        return validateL(root->left, rootVal) && validateL(root->right, rootVal);
    }

    bool validateR(TreeNode *root, int rootVal){
        if(!root) return true;

        // leafs need to be bigger than the root
        if(root->val <= rootVal) return false;

        // recursive DFS
        return validateR(root->left, rootVal) && validateR(root->right, rootVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        // check if all nodes on left are smaller and all nodes on the right are bigger
        if(!(validateL(root->left, root->val) && validateR(root->right, root->val))) return false;

        // check if left node is smaller and right node is bigger
        bool l, r;
        if(!root->left || root->left->val < root->val) l = isValidBST(root->left);
        if(!root->right || root->right->val > root->val) r = isValidBST(root->right);
        
        return l && r;
    }
};


int main()
{
    // vector<int> a = {2,1,3};
    // vector<int> a = {5,1,4,null,null,3,6};
    vector<int> a = {5,4,6,null,null,3,7};
    TreeNode* root = createTree(a);

    Solution s = Solution();
    auto res = s.isValidBST(root);
    cout << res;
    return 0;
}