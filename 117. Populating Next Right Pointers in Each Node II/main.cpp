#include <iostream>
#include <vector>
#include <queue>

#define null NULL

using namespace std;

class Node {
public:
    int val;
    Node* left, *right, *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

Node* createTree(vector<int> arr, int i = 0) {
    if (i+1 > arr.size() || arr[i] == NULL) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);
    return root;
}

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            // the ammount of elements on the row
            int n = q.size();
            // loops current row
            for(int i = 0; i < n; i++){
                // pop current row and append to output
                Node *node = q.front();
                q.pop();

                node->next = (i+1 < n) ? q.front() : NULL;

                // push all nodes from row below to queue
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};

int main()
{
    vector<int> a = {1,2,3,4,5,null,7};
    Node *root = createTree(a);

    Solution s = Solution();
    auto res = s.connect(root);
    cout << res;
    return 0;
}