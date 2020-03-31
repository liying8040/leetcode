# trees

广度优先遍历BFS：一般用queue实现。

深度优先遍历DFS：一般用stack实现。

深度优先遍历的递归算法：

先序遍历：

```C++
void preorder(TreeNode *root, vector<int> &res){
    if(root){
        res.push_back(root -> val);
        if(root -> left)
            inorder(root -> left, res);            
        if(root -> right)
            inorder(root -> right, res);
    }
}
```
中序遍历：

```C++
void inorder(TreeNode *root, vector<int> &res){
    if(root){
        if(root -> left)
            inorder(root -> left, res);        
        res.push_back(root -> val);
        if(root -> right)
            inorder(root -> right, res);
    }
}
```
后序遍历：

```C++
    void inorder(TreeNode *root, vector<int> &res){
        if(root){
            if(root -> left)
                inorder(root -> left, res);        
            if(root -> right)
                inorder(root -> right, res);
            res.push_back(root -> val);
        }
    }
```



:triangular_flag_on_post:(1) Maximum Depth of Binary Tree

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

:triangular_flag_on_post:(2) Validate Binary Search Tree

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



:triangular_flag_on_post:(3)  Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

不能先用中序遍历存为一个vector，再判断vector是否对称。因为下图是不对称的。

```
    1
   / \
  2   2
 /   / 
2   2
```

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
    bool isMirror(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == NULL && t2 == NULL) return true;
        if (t1 == NULL || t2 == NULL) return false;
        return (t1->val)==(t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
        
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root) return true;
        return isMirror(root->left, root->right);
    }
};
```

:triangular_flag_on_post:(4) Binary Tree Level Order Traversal

Given a binary tree, return the *level order* traversal of its nodes' values. (ie, from left to right, level by level).

```
given:
    3
   / \
  9  20
    /  \
   15   7

return:
[
  [3],
  [9,20],
  [15,7]
]
```

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
    vector<vector<int>> res;
    
    void helper(TreeNode *root, int level){
        if(level == res.size())
            res.push_back({});                   //新增加一维空vector<int>
        res[level].push_back(root -> val);
        if(root -> left)
            helper(root->left, level+1);
        if(root -> right)
            helper(root->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return res;
        helper(root,0);
        return res;
        
    }
};
```

:triangular_flag_on_post:(5) Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

```
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```

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
    
    TreeNode *helper(int left, int right, vector<int>& nums){
        if(left > right)
            return NULL;
        int p = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[p]);
        root -> left = helper(left, p-1, nums);
        root -> right = helper(p+1,right, nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0,nums.size()-1, nums); 
    }
};
```

