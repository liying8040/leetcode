#### (Day-1) Single Number

Given a **non-empty** array of integers, every element appears *twice* except for one. Find that single one.

```
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



#### (Day-2) Happy Number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

```
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

#### (Day-3) Maximum Sub-array

Given an integer array `nums`, find the contiguous sub-array (containing at least one number) which has the largest sum and return its sum.

```
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





#### (Day-5)

#### (Day-6)

#### (Day-7)