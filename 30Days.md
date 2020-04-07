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

