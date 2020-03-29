# trees

:one: Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its depth = 3.

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right)); 
    }
};
```

:two: ​Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

**Assume a BST is defined as follows:**​ :triangular_flag_on_post:

- **The left subtree of a node contains only nodes with keys less than the node's key.**
- **The right subtree of a node contains only nodes with keys greater than the node's key.**
- **Both the left and right subtrees must also be binary search trees.**

```
    2
   / \
  1   3

Input: [2,1,3]
Output: true
    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> stacks;
        long pre = LONG_MIN;                 //
        while(!stacks.empty() || root){
            while(root){
                stacks.push(root);
                root = root -> left;
            }
            root = stacks.top();
            stacks.pop();
            if(root -> val <= pre)
                return false;
            pre = root -> val;
            root = root -> right;
        }
        return true;
        
    }
};
```



:three: ​ 