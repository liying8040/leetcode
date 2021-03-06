#### (Day-28) First Unique Number

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the `FirstUnique` class:

- `FirstUnique(int[] nums)` Initializes the object with the numbers in the queue.
- `int showFirstUnique()` returns the value of **the first unique** integer of the queue, and returns **-1** if there is no such integer.
- `void add(int value)` insert value to the queue.

```C++
class FirstUnique {
    unordered_set<int> unique,nonunique;
    vector<int> vec;
public:
    FirstUnique(vector<int>& nums) {
        for(auto num:nums)
            add(num);
    }
    
    int showFirstUnique() {
        for(int i = 0; i < vec.size(); i++){
            if(unique.count(vec[i]))
                return vec[i];
        }
        return -1;
    }
    
    void add(int value) {
        if(nonunique.count(value))
            return;
        else if(unique.count(value)){
            unique.erase(value);
            nonunique.insert(value);
            return;
        }
        unique.insert(value);
        vec.push_back(value);
    }
};
```

#### (Day-26) Longest Common Subsequence

最长公共子序列问题一般都是用二维动态规划来解，因为动态规划的做法相当于是“穷举+剪枝”。【[参考至这里](https://leetcode-cn.com/problems/longest-common-subsequence/solution/dong-tai-gui-hua-zhi-zui-chang-gong-gong-zi-xu-lie/)】

### 一、动态规划思路

**第一步，一定要明确 `dp` 数组的含义**。

**第二步，定义 base case。**

**第三步，找状态转移方程。**

```C++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<int> temp(len2+1,0);
        vector<vector<int>> dp(len1+1,temp);
        for(int i = 1; i < len1 + 1; i++){
            for(int j = 1; j  < len2 + 1; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
```



#### (Day-23) Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

The hardest part of this problem is to find the regular pattern.
For example, for number `26 to 30`
Their binary form are:
`11010`
`11011`
`11100`　　
`11101`　　
`11110`

Because we are trying to find bitwise AND, so if any bit there are at least one `0` , it always `0`. In this case, it is `11000`.
So we are go to cut all these bit that they are different. In this case we cut the right `3` bit.

I think after understand this, the code is trivial:

```C++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int zeros = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            zeros ++;
        }
        return m << zeros;
    }
};
```

#### (Day-22) Sub-array Sum Equals K

Given an array of integers and an integer **k**, you need to find the total number of continuous subarrays whose sum equals to **k**.

```C++
Input:nums = [1,1,1], k = 2
Output: 2
```

```C++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums(nums.size()+1,0);
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            sums[i+1] = sums[i] + nums[i];
        }
        for(int i = 0; i < sums.size(); i++){
            for(int j = i+1; j < sums.size(); j++){
                if(sums[j]-sums[i] == k)
                    res++;
            }
        }
        return res;
    }
};
```



#### (Day-21) Leftmost Column with at Least a One

```C++
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int i = 0, j = dim[1]-1;
        int res = -1;
        while(i < dim[0] && j >= 0){
            if(binaryMatrix.get(i,j) == 0)
                i += 1;
            else if(binaryMatrix.get(i,j) == 1){
                res = j;
                j -= 1;
            }
        }
        return res;
    }
};
```



#### (Day-20) Construct Binary Search Tree from Preorder Traversal

Return the root node of a binary **search** tree that matches the given `preorder` traversal.

*(Recall that a binary search tree is a binary tree where for every node, any descendant of `node.left` has a value `<` `node.val`, and any descendant of `node.right` has a value `>` `node.val`. Also recall that a preorder traversal displays the value of the `node` first, then traverses `node.left`, then traverses `node.right`.)*

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
    
    TreeNode* helper(int low, int high, vector<int>& preorder){
        if (low > high) return NULL;
        int i;
        for (i = low + 1; i <= high; ++i) {     //这部分效率太低，应该改成二分查找，或者hash查找 
            if (preorder[i] > preorder[low]) {
                break;
            }
        }
        TreeNode *root = new TreeNode(preorder[low]);
        root -> left = helper(low+1, i-1, preorder);
        root -> right = helper(i, high, preorder);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder){
        return helper(0, preorder.size()-1, preorder);
    }
};
```

#### (Day-18) Minimum Path Sum

Given a *m* x *n* grid filled with non-negative numbers, find a path from top left to bottom right which *minimizes* the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

```c++
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
```

```C++
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < m; i++)
            grid[i][0] += grid[i-1][0];
            
        for(int j = 1; j < n; j++)
            grid[0][j] += grid[0][j-1];
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
```



#### (Day-17) Number of Islands

Given a 2d grid map of `'1'`s (land) and `'0'`s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

```C++
Input:
11110
11010
11000
00000

Output: 1
```

```C++
class Solution {
public:
    
    void func(vector<vector<char>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        grid[i][j] = '0';
        if(i+1 < row && grid[i+1][j] == '1') func(grid, i+1, j);
        if(i-1 >= 0 && grid[i-1][j] == '1') func(grid, i-1, j);
        if(j+1 < col && grid[i][j+1] == '1') func(grid, i, j+1);
        if(j-1 >= 0 && grid[i][j-1] == '1') func(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int res = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    res++;	
                    func(grid, i, j);
                }
            }
        }
        return res;
    }
};
```





#### (Day-16) Valid Parenthesis String [贪心算法]

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

1. Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4. `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string.
5. An empty string is also valid.

```C++
Input: "(*))"
Output: True
```

```C++
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; //贪心算法：记录左括号的最小数目和最大数目
        for(auto c:s){
            low  += c == '('? 1 : -1;
            high += c == ')'? -1 : 1;
            if(high < 0) return false;
            if(low < 0) low = 0;
        }
        return low==0;
    }
};
/*
'(': low++, high++ 
')': low--, high--
'*': low--, high++
*/
```



#### (Day-15) Product of Array Except Self

Given an array `nums` of *n* integers where *n* > 1,  return an array `output` such that `output[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

```C++
Input:  [1,2,3,4]
Output: [24,12,8,6]
```

```C++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> L(nums.size(),1), R(nums.size(),1);
        vector<int> res(nums.size(),0);
        int len = nums.size();
        for(int i = 1; i < len; i++){
            L[i] = L[i-1] * nums[i-1];
            R[len-i-1] = R[len-i] * nums[len-i];
        }
        for(int i = 0; i < nums.size(); i++){
            res[i] = L[i] * R[i];
        }
        return res;
    }
};
```

#### (Day-14) Perform String Shifts

You are given a string `s` containing lowercase English letters, and a matrix `shift`, where `shift[i] = [direction, amount]`:

- `direction` can be `0` (for left shift) or `1` (for right shift). 
- `amount` is the amount by which string `s` is to be shifted.
- A left shift by 1 means remove the first character of `s` and append it to the end.
- Similarly, a right shift by 1 means remove the last character of `s` and add it to the beginning.

Return the final string after all operations.

```C++
Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
```

```C++
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int k = 0;
        for(auto vec : shift){
            k += (2*vec[0]-1)*vec[1];    //{0:-1, 1:1}
        }
        int sym = k >= 0 ? 1 : -1;
        k = abs(k);
        k = k % s.size();
        
        if(k==0)
            return s;
        else if(sym == 1)
            return s.substr(s.size()-k,k) + s.substr(0,s.size()-k);
        else if(sym == -1)
            return s.substr(k,s.size()-k) + s.substr(0,k);
        return s;
    }
};
```

#### (Day-13) Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

```C++
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
```

```C++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> maps;
        int max_len = 0;
        int val = 0;
        for(int i = 0; i < nums.size(); i++){
            val += 2 * nums[i] - 1;   // {0:-1, 1:1}
            if(val == 0)
                max_len = i+1;
            else if(maps.count(val))
                max_len = max(max_len,i-maps[val]);
            else
                maps.insert({val,i});
        }
        return max_len;
    }
}; //runtime 无敌高
```

#### (Day-12) Last Stone Weight [Easy]

We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two **heaviest** stones and smash them together. Suppose the stones have weights `x` and `y` with `x <= y`. The result of this smash is:

- If `x == y`, both stones are totally destroyed;
- If `x != y`, the stone of weight `x` is totally destroyed, and the stone of weight `y` has new weight `y-x`.

At the end, there is at most 1 stone left. Return the weight of this stone (or 0 if there are no stones left.)

```C++
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
```

```C++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        
        int end = stones.size() - 1;
        sort(stones.begin(), stones.end());
        while(stones[end-1]){
            if(stones[end] == stones[end-1]){
                stones[end] = stones[end-1] = 0;
            }else{
                stones[end] = stones[end] - stones[end-1];
                stones[end-1] = 0;
            }
            sort(stones.begin(), stones.end());
        }
        return stones[end];
        
    }
};
```

#### (Day-11) Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the **longest** path between any two nodes in a tree. This path may or may not pass through the root.

```C++
          1
         / \
        2   3
       / \     
      4   5
      Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
      Note: The length of path between two nodes is represented by the number of edges between them.
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
    int res;                               //全局变量
    int depth(TreeNode *root){
        if(!root) return 0;
        int L = depth(root->left);
        int R = depth(root -> right);
        res = res > (L+R) ? res : L+R; //左子树的最大深度+右子数的最大深度 = 经过该根节点的路径长度
        return max(R,L)+1;                //计算最大深度    
    }    
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        depth(root);
        return res;
    }
};
```



#### (Day-10) Min Stack

#### (Day-9) Backspace String Compare

Given two strings `S` and `T`, return if they are equal when both are typed into empty text editors. `#` means a backspace character.

```C++
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
```

```C++
class Solution {
public:
    string func(string S){
        int slow = -1, fast = 0;
        while(fast < S.size()){
            if(S[fast] == '#'){
                slow = slow == -1 ? -1 : slow-1;
            }else if(S[fast] == S[slow+1]){      
                slow++;
            }else{
                S[slow+1] = S[fast];
                slow++;
            }
            fast++;
        }
        return S.substr(0,slow+1);
    }
    
    bool backspaceCompare(string S, string T) {
        return func(S) == func(T);
    }
};
```

#### (Day-8) Middle of the Linked List

Given a non-empty, singly linked list with head node `head`, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

```C++
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
```

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next;
            if(fast->next != NULL)
                fast = fast -> next;            
        }
        return slow;        
    }
};
```

#### (Day-7) Counting Elements

Given an integer array `arr`, count element `x` such that `x + 1` is also in `arr`.

If there are duplicates in `arr`, count them separately.

```c++
Input: arr = [1,1,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
```

```C++
Input: arr = [1,2,2]
Output: 1
Explanation: One 1 is counted cause 2 is in arr.
```

```C++
class Solution {
public:
    int countElements(vector<int>& arr) {
        multiset<int> sets(arr.begin(), arr.end());
        multiset<int> sets2(arr.begin(), arr.end());
        int res = 0;
        for(int i = 0; i < arr.size(); i++){
            if(sets.count(arr[i]+1)){
                res += sets2.count(arr[i]);
                sets.erase(arr[i]+1);
            }
        }
        return res;
    }
};
```

#### (Day-6) Group Anagrams

Given an array of strings, group anagrams together.

```C++
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
```

**Note:**

- All inputs will be in lowercase.
- The order of your output does not matter.

```C++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        unordered_map<string, int> work;               // key保存的是排序的string，value保存的是下标。
        int sub = 0;                                   // value
        for(auto s : strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            if(work.count(temp)){       //用count，而不用find，因为找不到的话，count返回0，find返work.end()
                res[work[temp]].push_back(s);
            }else{
                vector<string> vec(1,s);            //vector的初始化
                res.push_back(vec);
                work.insert({temp, sub++});
            }
        }
        return res;
    }
};
```

#### (Day-5) Best Time to Buy and Sell Stock II

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

**Note:** You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

```
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
```

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if(prices.size() != 0){
            for(int d = 0; d < prices.size() - 1; ++d){
                if(prices[d+1] > prices[d])
                    res += prices[d+1] - prices[d];
            }
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        }
        return res;
    }
};
```

#### (Day-4) Move Zeros

Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

```C++
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```

**Note**:

1. You must do this **in-place** without making a copy of the array.
2. Minimize the total number of operations.

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 1; fast < nums.size(); ++fast){
            if(nums[slow] != 0)
                slow ++;
            if(nums[slow] == 0 && nums[fast] != 0 && slow != fast)
                swap(nums[slow], nums[fast]);
        }
    }
};
```

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        while(slow < nums.size() && nums[slow] != 0){
            slow ++;
        }
        int fast = slow + 1;
        while(fast < nums.size()){
            if(nums[fast] != 0){
                swap(nums[fast++], nums[slow++]);
            }else
                fast++;
        }
    }
};
```

#### (Day-3) Maximum Sub-array

Given an integer array `nums`, find the contiguous sub-array (containing at least one number) which has the largest sum and return its sum.

```C++
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> res(nums);
        int max = nums[0];
        for(int i = 1 ; i < res.size(); i++){
            res[i] = (res[i-1]+nums[i]) > nums[i] ? (res[i-1]+nums[i]) : nums[i];
            max = max > res[i] ? max : res[i];
        }
        return max;
    }
};
```

#### (Day-2) Happy Number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

```C++
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

<img src=".\img\30day_2.png" style="zoom:50%;" />

```C++
class Solution {
public:
    int one_step(int n){
        int result = 0;
        while(n != 0){
            result += (n % 10) * (n % 10);   
            n = n / 10;
        }
        return result;
    }
    
    bool isHappy(int n) {
        int fast = n, slow = n;           //快慢指针
        do{
            fast = one_step(fast);
            fast = one_step(fast);
            slow = one_step(slow);    
        }while(fast != slow);
        
        return fast == 1;
        
    }
};
```

#### (Day-1) Single Number

Given a **non-empty** array of integers, every element appears *twice* except for one. Find that single one.

```C++
Input: [4,1,2,1,2]
Output: 4
```

```C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[0] ^= nums[i];
        }
        return nums[0];
        
    }
};
```

