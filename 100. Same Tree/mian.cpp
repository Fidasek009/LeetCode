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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if one is null return if both are null
        if(!p || !q) return (!p && !q);

        // check equality and run DFS recursion
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    vector<int> a = {1,2};
    vector<int> b = {1,2,3};
    TreeNode *root1 = createTree(a);
    TreeNode *root2 = createTree(b);


    Solution s = Solution();
    auto res = s.isSameTree(root1, root2);
    cout << res;
    return 0;
}