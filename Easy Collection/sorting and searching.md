# sorting and searching

(1) Merge Sorted Array

Given two sorted integer arrays *nums1* and *nums2*, merge *nums2* into *nums1* as one sorted array.

**Note:**

- The number of elements initialized in *nums1* and *nums2* are *m* and *n* respectively.
- You may assume that *nums1* has enough space (size that is greater or equal to *m* + *n*) to hold additional elements from *nums2*.

```
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
```

```C++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m,nums1.end());
        nums1.insert(nums1.end(),nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
    }
};
```

```C++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        m = m - 1;
        n = n - 1;
        while(m >= 0 || n >= 0){
            if(m < 0){
                nums1[pos--] = nums2[n--];
            }else if(n < 0){
                nums1[pos--] = nums1[m--];            
            }else if(m >= 0 && n >= 0){
                if(nums1[m] >= nums2[n])
                    nums1[pos--] = nums1[m--];
                else
                    nums1[pos--] = nums2[n--];
            }
            
        }
    }
};
```

