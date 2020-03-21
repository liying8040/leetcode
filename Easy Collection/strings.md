# strings

(1) Reverse String

Write a function that reverses a string. The input string is given as an array of characters `char[]`.

```
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

```C++
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        for(int i = 0; i < s.size()/2; i++){
            swap(s[i],s[s.size()-i-1]);
        }
    }
};
```

(2) Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

```
Input: 120
Output: 21
Input: -123
Output: -321
```

```C++
class Solution {
public:
    int reverse(int x) {
        int xa = abs(x);
        int sign = x >= 0 ? 1 : -1;
        int res = 0;
        while(xa != 0){
            if(res < -pow(2,31) / 10 || res > (pow(2,31) - 1) / 10)
                return 0;
            res = res * 10 + xa % 10;
            xa = xa / 10;
        }
        return sign*res;
    }
};
```

