#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> rows;
        int row = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            // new row exits
            rows.push_back({});
            // the ammount of elements on the row
            int n = q.size();
            // loops current row
            for(int i = 0; i < n; i++){
                TreeNode *node = q.front();
                
                // push all nodes from row below to queue
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                // pop current row and append to output
                q.pop();
                rows[row].push_back(node->val);
            }
            row++;
        }

        return rows;
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
    vector<int> a = {3,9,20,null,null,15,7};
    TreeNode *root = createTree(a);
    Solution s = Solution();
    auto res = s.levelOrder(root);
    for(vector<int> row : res){
        for(int x : row) cout << x << ", ";
        cout << endl;
    }
     
    return 0;
}