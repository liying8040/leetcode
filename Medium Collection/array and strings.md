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

(2) 