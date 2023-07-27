#include <iostream>
#include <vector>

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
    bool walk(TreeNode* l, TreeNode* r){
        // end of branch
        if(!l && !r) return true;
        // avoid nullptr
        if(!l || !r) return false;
        // nodes aren't eqial
        if(l->val != r->val) return false;
        // top-down recursion
        return walk(l->left, r->right) && walk(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return walk(root->left, root->right);
    }
};

int main()
{
    vector<int> a = {1,2,2,3,4,4,3};
    TreeNode* root = createTree(a);

    Solution s = Solution();
    auto res = s.isSymmetric(root);
    cout << res;
    return 0;
}