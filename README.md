# Top Interview Questions

This is LeetCode's official curated list of Top classic interview questions to help you land your dream job.

1. Easy Collection
2. Medium Collection
3. Hard Collection

Remember: Deliberate practice does not mean looking for answers and memorizing it. You won't go very far with that approach. **The more you are able to solve a problem <u>yourself</u> without any reference to answers, the more you will improve.**

------

###  Easy Collection

#### 1. Array

1.1 Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length. Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

`class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        auto end_unique = unique(nums.begin(), nums.end());
        nums.erase(end_unique, nums.end());
        return nums.size();
    }
};`

#### 2. Strings

#### 3. Linked List

#### 4. Trees

#### 5. Sorting and Searching

#### 6. Dynamic Programming

#### 7. Design

#### 8. Math

#### 9. Others

------

### Medium Collection

------

### Hard Collection

------

