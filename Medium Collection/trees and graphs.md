# trees

广度优先遍历BFS：一般用queue实现。

深度优先遍历DFS：一般用stack实现。

(1) Binary Tree Inorder Traversal

Given a binary tree, return the *inorder* traversal of its nodes' values.

```C++
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    void inorder(TreeNode* root, vector<int> &res) {
        if(root!=NULL){
            if(root -> left != NULL)
                inorder(root -> left, res);            
            res.push_back(root -> val);
            if(root -> right != NULL)
                inorder(root -> right, res);
        }
    }  
    vector<int> inorderTraversal(TreeNode* root) {        
        vector<int> res;
        inorder(root, res);
        return res;
    }
}; //递归
```

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stacks;
        
        while(!stacks.empty() || root != NULL){
            while(root != NULL){
                stacks.push(root);
                root = root -> left;
            }
            root = stacks.top();
            res.push_back(root -> val);
            stacks.pop();         
            root = root -> right;   //无需判断root->right是否空
        }
        return res;
    }
}; //iteration
```

