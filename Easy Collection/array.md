# array

(1) Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates **in-place** such that each element appear only once and return the new length. Do not allocate extra space for another array, you must do this by modifying the input array in-place with **O(1) extra memory**.

```markdown
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.
```

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == NULL) return 0;
        int slow = 0;							
        for(int fast = 1; fast < nums.size(); ++fast){     //快慢指针
            if(nums[fast] > nums[slow]){
                slow ++;
                if(slow != fast)
                    swap(nums[slow], nums[fast]);
            }
        }
      return slow+1;  
    }
};
```



(2) Best Time to Buy and Sell Stock II

Say you have an array for which the i-th element is the price of a given stock on day i.Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

```
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
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

(3) Rotate Array

Given an array, rotate the array to the right by k steps, where k is non-negative.

```
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

```c++
class Solution {
public:
    void rotate_all(vector<int> &nums, int start, int end){
        while(start < end)
            swap(nums[start++], nums[end--]);
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();                   // k要取模
        rotate_all(nums, 0, nums.size()-1);
        rotate_all(nums, 0, k-1);
        rotate_all(nums, k, nums.size()-1);
    }
};
```



(4) Contains Duplicate

Given an array of integers, find if the array contains any duplicates.

```
Input: [1,2,3,1]
Output: true
```

```C++
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        sort(nums.begin(), nums.end());
        for(size_t i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
        
    }
};
```

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> sets(nums.begin(), nums.end());   //set具有有序性，唯一性
        return nums.size() != sets.size();
    }
};//相较于上一种方法，该方法的runtime和memory都更大。
```

(5) Single Number

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

```
Input: [4,1,2,1,2]
Output: 4
```

```C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(size_t i = 1; i < nums.size(); ++i)
            res ^= nums[i]; //异或所有的值
        return res;
    }
};
```

(6) Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.

```
Input: nums1 = [4,9,4], nums2 = [9,4,9,8,4]
Output: [4,9,4]
```

```C++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(auto i : nums1){
            auto iter = find(nums2.begin(), nums2.end(), i); //依次寻找nums1中的每个值是否在nums2中出现
            if(iter != nums2.end()){
                res.push_back(i);
                nums2.erase(iter);
            }
        }
        return res;
    }
};

```

```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> maps; // key中存nums1的不重复值，value存每个值出现的次数。
        vector<int> res;
        for(size_t i = 0; i < nums1.size(); ++i){
            auto iter = maps.find(nums1[i]);
            if(iter == maps.end())
                maps.insert({nums1[i],1});
            else
                maps[nums1[i]]++;
        }
        for(size_t i = 0; i < nums2.size(); ++i){
            if(maps.find(nums2[i]) != maps.end()){
                if(maps[nums2[i]] > 0){
                    res.push_back(nums2[i]);
                    maps[nums2[i]] --;
                }
            }       
        }
        return res;
    }
};
```

(7) Plus One

Given a **non-empty** array of digits representing a non-negative integer, plus one to the integer.

```
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
```

```C++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == NULL) return digits;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i){
            int temp = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = temp;
        }
        if(carry > 0){
            digits.insert(digits.begin(),{1});
        }
        return digits;
    }
};
```

(8) Move Zeros

Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

```
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
```

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;			//快慢指针
        while(fast < nums.size()){
            if(nums[fast] != 0){
                if(slow != fast)
                    swap(nums[slow++], nums[fast++]);
                else{
                    slow++;
                    fast++;
                }
            }else
                fast++;
        } 
    }
};
```

```C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 1; fast < nums.size(); ++fast){   //快慢指针
            if(nums[slow] != 0)
                slow ++;
            if(nums[slow] == 0 && nums[fast] != 0 && slow != fast)
                swap(nums[slow], nums[fast]);
        }
    }
};
```

(9) Two Sum

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

```
Given nums = [3,3], target = 6.

return [0, 1].
```

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> maps;                     // 关键字可重复出现
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            maps.insert({nums[i], i});               //或 maps[nums[i]] = i;
        }
         for(auto beg = maps.begin(); beg != maps.end(); beg++){
            auto iter = maps.find(target - beg->first);
             if(iter != maps.end() && iter != beg){
                 res.push_back(beg->second);
                 res.push_back(iter->second);
                 return res;
             }
        }
        return res;
    }
};
// set, map: 有序，唯一 
// multiset, multimap: 有序，不唯一
// unordered_set, unordered_map: 无序，唯一
// unordered_multiset, unordered_multimap: 无序，不唯一
```

(10) Valid Sudoku

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the 9 `3x3` sub-boxes of the grid must contain the digits `1-9` without repetition.

```
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
```

```C++
class Solution { //wrong!!!
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> sets;
        for(int i = 0; i < 9; i++){
            sets.clear();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(sets.find(board[i][j]) == sets.end())
                        sets.insert(board[i][j]);
                    else
                        return false;
                }
            }
        }
        
        for(int j = 0; j < 9; j++){
            sets.clear();
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    if(sets.find(board[i][j]) == sets.end())
                        sets.insert(board[i][j]);
                    else
                        return false;
                }
            }
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                sets.clear();
                for(int m = 0; m < 3; m++){
                    for(int n = 0; n < 3; n++){
                        if(board[i][j] != '.'){
                            if(sets.find(board[i*3+m][j*3+n]) == sets.end())
                                sets.insert(board[i*3+m][j*3+n]);
                            else
                                return false;
                        }
                    }
                }

            }
        }
        return true;
        
    }
};
```

(11) Rotate Image

You are given an *n* x *n* 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).

```
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

```C++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};
```

