# Intuition
The code basically explains itself.

# Approach
I just check if any of the nodes are null to exit recursion, then I check if the values are equal and run DFS recursion.

# Complexity
- Time complexity: ***O(n)***
- Space complexity: ***O(n)***

# Code
```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if one is null return if both are null
        if(!p || !q) return (!p && !q);

        // check equality and run DFS recursion
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```