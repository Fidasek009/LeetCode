#include <iostream>
#include <vector>
#include <math.h>
#include <string>

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





class Codec {
public:
    vector<TreeNode*> encode(TreeNode *root){
        vector<TreeNode*> nodes = {root};
        int row = 1;

        bool done = false;

        while(!done){
            // the ammount of elements on the row
            int n = pow(2, row);
            int m = nodes.size();
            done = true;

            // loops current row
            for(int i = 0; i < n; i++){
                TreeNode *parent = nodes[(m+i-1)/2];

                // node above doesn't exist
                if(!parent){
                    nodes.push_back(nullptr);
                    continue;
                }

                // push back child node
                if(i%2 == 0) nodes.push_back(parent->left);
                else nodes.push_back(parent->right);

                // check if row below has any more nodes
                if(done && nodes.back() && (nodes.back()->left || nodes.back()->right)) done = false;
            }
            row++;
        }

        return nodes;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";

        for(TreeNode* x : encode(root)){
            if(x != nullptr) s += to_string(x->val);
            s.push_back(',');
        }
        s.pop_back();

        return s;
    }


    TreeNode* createTree(vector<string> arr, int i = 0) {
        if (i+1 > arr.size() || arr[i] == "") return nullptr;
        TreeNode* root = new TreeNode(stoi(arr[i]));
        root->left = createTree(arr, 2 * i + 1);
        root->right = createTree(arr, 2 * i + 2);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // tokenize string
        vector<string> tokens;
        string temp = "";
        for(int i = 0; i < data.length(); i++){
            if(data[i] == ','){
                tokens.push_back(temp);
                temp = "";
            }
            else temp += data[i];           
        }
        tokens.push_back(temp);


        return createTree(tokens);
    }
};

int main()
{
    vector<int> a = {1,2,3,null,null,4,5};
    TreeNode* root = createTree(a);
    Codec s = Codec();
    TreeNode* res = s.deserialize(s.serialize(root));
    cout << res;
    return 0;
}