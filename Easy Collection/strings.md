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

(3)  First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

```
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```

```C++
class Solution {
public:
    int firstUniqChar(string s) {
        int letter[26] = {0};
        for(int i = 0; i < s.size(); i++)
            letter[s[i] - 'a']++;
        
        for(int i = 0; i < s.size(); i++){
            if(letter[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
            
    }
};
```

(4) Valid Anagram

Given two strings *s* and *t* , write a function to determine if *t* is an anagram of *s*.

```
Input: s = "anagram", t = "nagaram"
Output: true
```

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());      
        return s==t;
    }
}; //Runtime: 60 ms
```

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int letter[26] = {0};
        for(int i = 0; i < s.size(); i++){
            letter[s[i] - 'a'] ++;
            letter[t[i] - 'a'] --;
        }
        for(int i = 0 ; i < 26; i++){
            if(letter[i] != 0)
                return false;
        }
        return true;
    }
}; //Runtime: 8 ms
```

