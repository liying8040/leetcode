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

