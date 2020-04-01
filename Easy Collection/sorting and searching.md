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

(2) First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

```
Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
```

```C++
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long first = 1, end = n;
        long mid = (first + end) / 2;     //不能这样写，因为如果n是(2^31-1)的话，int会溢出。
        while(first < end){
            if (isBadVersion(mid)){
                end = mid;
            }else{
                first = mid + 1;
            }
            mid = (first + end) / 2;    //不能这样写，因为如果n是(2^31-1)的话，int会溢出。
        }
        return mid;
    }
};
```

```C++
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {  
        int first = 1;
        int end = n;
        int mid = 0;
        while(first <= end){
            mid = first + (end - first)/2;         //正确的写法
            if(isBadVersion(mid)){
                end = mid;
                if(first == end) return mid;
            }else
                first = mid + 1;             
        }
        return 0;        
    }
};
```

