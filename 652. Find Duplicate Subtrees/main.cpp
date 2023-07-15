#include <iostream>
#include <vector>
#include <unordered_map>

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
    vector<TreeNode*> out;
    unordered_map<string, vector<TreeNode*>> map;

    string dfs(TreeNode *root){
        if(!root) return "N";
        string s = to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);
        if(map[s].size() == 1) out.push_back(root);
        map[s].push_back(root);
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return out;
    }
};

int main()
{
    cout << "I was too lazy to write tests (I just drank 3 beers) :P";
    return 0;
}