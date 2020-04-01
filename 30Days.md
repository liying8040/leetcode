#### (1) Single Number

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

