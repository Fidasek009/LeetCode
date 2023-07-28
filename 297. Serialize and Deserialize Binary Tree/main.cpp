#include <iostream>
#include <vector>

#include <sstream>

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
private:
    void encode(TreeNode *root, ostringstream &out){
        if(!root) out << "# ";
        else {
            out << root->val << ' ';
            encode(root->left, out);
            encode(root->right, out);
        }
    }
    
    TreeNode* decode(istringstream& in){
        string val;
        in >> val;
        if(val == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = decode(in);
        root->right = decode(in);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
};

int main()
{
    vector<int> a = {1,2,3,null,null,4,5};
    TreeNode* root = createTree(a);
    Codec s = Codec();
    // string res = s.serialize(root);
    TreeNode* res = s.deserialize(s.serialize(root));
    cout << res;
    return 0;
}