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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int depthL = 1 + maxDepth(root->left);
        int depthR = 1 + maxDepth(root->right);

        int deeper = (depthL > depthR) ? depthL : depthR;

        return deeper;
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
    // vector<int> a = {3,9,20,NULL,NULL,15,7};
    vector<int> a = {1,NULL,2};
    TreeNode *tree = createTree(a);
    

    Solution s = Solution();
    auto res = s.maxDepth(tree);
    cout << res;
    return 0;
}