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

class Solution {
public:
    vector<int> nodes;

    void walk(TreeNode* root){
        if(root) nodes.push_back(root->val);
        else return;

        if(root->left) walk(root->left);
        if(root->right) walk(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        walk(root);
        return nodes;
    }
};

TreeNode* createTree(vector<int> arr, int i = 0) {
    if (i+1 > arr.size() || arr[i] == NULL) return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);
    return root;
}

int main()
{
    vector<int> a = {1,null,2,null,null,3};
    TreeNode *root = createTree(a);
    Solution s = Solution();
    auto res = s.preorderTraversal(root);
    for(int x : res) cout << x << ", ";
    return 0;
}