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

(2) Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the *zigzag level order* traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

```
[
  [3],
  [20,9],
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
    void zigzag(TreeNode* root, vector<vector<int>> &res, int depth) {
        if(root){
            if(depth >= res.size()){
               res.push_back( vector<int>(1,root -> val));
            }else{
                res[depth].push_back(root -> val);
            }    
            if(root -> left)
                zigzag(root -> left, res, depth+1);
            if(root -> right)
                zigzag(root -> right, res, depth+1);
        }      
    }    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzag(root,res,0);
        for(int i = 1; i < res.size(); i+=2){
            reverse(res[i].begin(), res[i].end());  // 需要再进行reverse操作
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    
    void zigzag(TreeNode* root, vector<vector<int>> &res, int depth) {
        if(root){
            if(depth >= res.size()){
               res.push_back( vector<int>(1,root -> val));
            }else if(depth % 2 == 0){
                res[depth].push_back(root -> val);
            }else{
                res[depth].insert(res[depth].begin(), root -> val); //直接插在前面
            }    
            if(root -> left)
                zigzag(root -> left, res, depth+1);
            if(root -> right)
                zigzag(root -> right, res, depth+1);
        }      
    }    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzag(root,res,0);
        return res;
    }
}; //这种方法更好
```

(3) Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

**Note:**
You may assume that duplicates do not exist in the tree.

For example, given

```
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
```

```
    3
   / \
  9  20
    /  \
   15   7
```

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if(len(inorder)==0):
            return None
        root = TreeNode(preorder[0])
        mid = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:mid+1], inorder[:mid])
        root.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])
        return root
```

