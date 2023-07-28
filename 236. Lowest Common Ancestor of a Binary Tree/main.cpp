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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // found node or reached end of branch
        if(!root || root == p || root == q) return root;
        // bottom-up recursion
        TreeNode *l=lowestCommonAncestor(root->left, p, q), *r=lowestCommonAncestor(root->right, p, q);
        return (l) ? ((r) ? root : l) : r;
    }
};

int main()
{
    vector<int> a = {1,2};
    TreeNode *root=createTree(a), *b=root, *c=root->left;
   

    Solution s = Solution();
    auto res = s.lowestCommonAncestor(root, b, c);
    cout << res;
    return 0;
}