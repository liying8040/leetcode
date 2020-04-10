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

