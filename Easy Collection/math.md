# math

(1) Fizz Buzz

Write a program that outputs the string representation of numbers from 1 to *n*.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

```
n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
```

```C++
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        string s;
        for(int i = 1; i <= n; i++){
            s = "";
            if(i % 3 == 0)
                s += "Fizz";
            if(i % 5 == 0)
                s += "Buzz";
            if(i % 3 != 0 && i % 5 != 0)
                s = to_string(i);
            res.push_back(s);
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++){
            if(i % 3 == 0 && i % 5 != 0)
                res.push_back("Fizz");
            else if(i % 3 != 0 && i % 5 == 0)
                res.push_back("Buzz");
            else if(i % 3 == 0 && i % 5 == 0)
                res.push_back("FizzBuzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};
```

**(2) Count Primes** 

Count the number of prime numbers less than a non-negative number, ***n\***.

```
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

```C++
class Solution {
public:
    int countPrimes(int n) {
        if (n==0) return 0;
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 0; i < sqrt(n); i++){               //
            if(prime[i]){
                for(int j = i * i; j < n; j = j + i){
                    prime[j] = false;
                }
            }
            
        }
        return count(prime.begin(), prime.end(), true);
        
    }
};
```

(3) Power of Three

Given an integer, write a function to determine if it is a power of three.

```
Input: 27
Output: true
```

```C++
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double rb = log10(n)/log10(3);
        int ri = log10(n)/log10(3);
        return rb-ri == 0;
    }
};
```

(4) Roman to Integer

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, two is written as `II` in Roman numeral, just two one's added together. Twelve is written as, `XII`, which is simply `X` + `II`. The number twenty seven is written as `XXVII`, which is `XX` + `V` + `II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

```
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

```C++
/*class Solution {
public:
    int romanToInt(string s) {
        map<char, int> maps = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int result = 0;
       for(size_t i = 0; i < s.size(); ++i){
           if(((maps.find(s[i])) -> second) < ((maps.find(s[i+1])) -> second))
                result -= (maps.find(s[i])) -> second;
           else
                result += (maps.find(s[i])) -> second;
       }
        return result;
    }
};*/


class Solution {
public:
    int romanToInt(string s) {
        map<char, int> maps = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int result = 0;
       for(size_t i = 0; i < s.size(); ++i){
           if(maps[s[i]] < maps[s[i+1]])
                result -= maps[s[i]];
           else
                result += maps[s[i]];
       }
        return result;
    }
};
```

```C++
class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0) return 0;
        map<char, int> maps = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = maps[s[s.size() - 1]];
        for(int i = s.size() - 2; i >= 0 ;i--){
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X'))
                res -= 1;
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C'))
                res -= 10;
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))
                res -= 100;
            else
                res += maps[s[i]];
        }
        return res;
    }
};
// 效率低
```

