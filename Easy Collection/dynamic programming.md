# dynamic programming

(1) Climbing Stairs

You are climbing a stair case. It takes *n* steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Note:** Given *n* will be a positive integer.

```
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

```C++
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int a = 1, b = 2, c = 0;
        int i = 3;
        while(i <= n){
            c = a + b;
            a = b;
            b = c;
            i++;
        }
        return c;
        
    }
};
```

```C++
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2)   //递归会超时
};
```

(2) Best Time to Buy and Sell Stock

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

```
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int min_price = prices[0];
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < min_price)
                min_price = prices[i];
            else if((prices[i] - min_price) > max_profit){
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};
```

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int> gain;
        gain.push_back(0);
        int res = 0;
        for(int i = 1; i < prices.size(); i++){
            int temp = prices[i] - prices[i-1] + gain[i-1];
            if(temp > 0)
                gain.push_back(temp);
            else
                 gain.push_back(0);
            res = gain[i] > res ? gain[i] : res;
        }
        return res;
    }
};
```

(3) Maximum Sub-array

Given an integer array `nums`, find the contiguous sub-array (containing at least one number) which has the largest sum and return its sum.

```
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> sum(nums.size(),0);
        sum[0] = nums[0];
        for(size_t i = 1; i < nums.size(); ++i)
        {
            sum[i] = max(sum[i-1] + nums[i], nums[i]);
        }
        return *max_element(sum.begin(), sum.end());
    }
};
```

```C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> res;
        res.push_back(nums[0]);
        int max = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int temp = res[i-1] + nums[i];
            if(temp > nums[i])
                res.push_back(temp);
            else
                res.push_back(nums[i]);
            max = res[i] > max ? res[i] : max;
        }
        return max;
    }
};
```

(4) House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police**.

```
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
```

```C++
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> DP(nums);
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        DP[0] = nums[0];
        DP[1] = max(nums[0], nums[1]);
        int i = 2;
        while(i < nums.size())
        {
            DP[i] = max(nums[i] + DP[i-2], DP[i-1]);
            i++;
        }
        return DP[nums.size()-1];
        
    }
};
```

```C++
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> res(nums.begin(), nums.end());
        int max = res[0];
        for(int i = 2; i < res.size(); i++){
            max = max > res[i-2] ? max : res[i-2];
            res[i] = nums[i] + max;
        }
        return res[res.size()-1] > res[res.size()-2] ? res[res.size()-1] : res[res.size()-2];
        
    }
};  //res[i] = max(res[i-2]) + nums[i]
```

