# Easy Collection

#### Array

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
        int slow = 0;							//快慢指针
        for(int fast = 1; fast < nums.size(); ++fast){
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

