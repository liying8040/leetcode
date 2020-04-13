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

