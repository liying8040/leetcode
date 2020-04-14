# Array and Strings

(1) 3 Sum

Given an array `nums` of *n* integers, are there elements *a*, *b*, *c* in `nums` such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.

**Note:**

The solution set must not contain duplicate triplets.

```C++
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return vector<vector<int>>();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());        //先排序
        for(int i = 0; i < nums.size(); i++){      
            if(i!=0 && nums[i] == nums[i-1])   //跳过相同元素的值，去res重复值。
                continue;
            int low = i+1, high = nums.size() - 1;
            while(low < high){
                if(nums[low] + nums[high] == -nums[i]){
                    res.push_back({nums[i], nums[low], nums[high]});
                    int temp_low = low, temp_high = high;
                    while(nums[temp_low] == nums[low] && (low < high)) 
                        low++;	//跳过相同元素的值，去res重复值。
                    while(nums[temp_high] == nums[high] && (low < high))
                        high--;	//跳过相同元素的值，去res重复值。
                }else if(nums[low] + nums[high] > -nums[i])
                    high--;
                else
                    low++;
            }            
        }
        return res;
    }
};
```

(2) Set Matrix Zeros

Given a *m* x *n* matrix, if an element is 0, set its entire row and column to 0. Do it [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm).

```C++
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
```

```C++
/*
Runtime: 60 ms
Memory Usage: 9.2 MB
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(rows.count(i) || cols.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }        
    }
};
```

```C++
/*
Runtime: 48 ms
Memory Usage: 9.1 MB
无须用额外的空间存储需要置零的行和列，而是利用矩阵的matrix[0,:]和matrix[:,0]来指示哪些行和列需要置零。
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag_row = 0, flag_col = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                    if(i == 0) 
                        flag_row = 1;
                    if(j == 0)
                        flag_col = 1;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }
        if(flag_row == 1){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }
        if(flag_col == 1){
            for(int j = 0; j < matrix.size(); j++){
                matrix[j][0] = 0;
            }
        }       
    }
};
```

(3) Group Anagrams

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

```C++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> maps;
        int pos = 0;
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(maps.count(temp)){
                res[maps[temp]].push_back(strs[i]);
            }else{
                res.push_back({strs[i]});
                maps.insert({temp, pos});
                pos++;
            }
        }
        return res;
    }
};
```



(4) Longest Substring Without Repeating Characters

Given a string, find the length of the **longest substring** without repeating characters.

```C++
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```

```C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int first = 0;
        for(int end = 0; end < s.size(); end++){
            string sub = s.substr(first,end-first);
            int pos = sub.find(s[end]);  //这是sub的pos           
            if(pos != string::npos){     //找到了重复的
                max = (end - first) > max ? (end - first) : max;
                first = first+pos+1;
            }else{                       //没找到重复的
                max = (end - first + 1) > max ? (end - first + 1) : max;
            }
        }
        return max;
    }
};
```

(5) Longest Palindromic Substring

Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

```C++
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```

```C++
class Solution {
public:
    string longestPalindrome(string s) { //扩展中心法
        if(s.size() == 0) return "";
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if(len > (end-start)){
                start = i - (len - 1)/2;  //当前最大len的首尾下标
                end = i + len/2;
            }
        }
        return s.substr(start, end-start+1);
    }
    int expandAroundCenter(string &s, int L, int R){
        while(L >=0 && R < s.length() && s[L] == s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
};
```

(6) Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

> Return true if there exists *i, j, k*
> such that *arr[i]* < *arr[j]* < *arr[k]* given 0 ≤ *i* < *j* < *k* ≤ *n*-1 else return false.

**Note:** Your algorithm should run in O(*n*) time complexity and O(*1*) space complexity.

```
Input: [1,2,3,4,5]
Output: true
```

```C++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int small = INT_MAX, mid = INT_MAX;
        for(auto i:nums){
            if(i <= small)
                small = i;
            else if(i <= mid)
                mid = i;
            else
                return true;
        }
        return false;
        
    }
};  //神仙解法
```

