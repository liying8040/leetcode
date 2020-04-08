# others

(1) Number of 1 Bits

Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the [Hamming weight](http://en.wikipedia.org/wiki/Hamming_weight)).

```
Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
```

```C++
class Solution {
public:
    
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int result = 0;
        for(int i = 0 ; i < 32; i++)
        {
            if((n & mask) != 0) 
                result ++;
            mask = (mask << 1);
        }
        return result;
        
    }
}; // Runtime: 4 ms  Memory Usage: 6.2 MB
```

```C++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n > 0)
        {
            result = result + n % 2;
            n = n/2;
        }
        return result;
        
    }
}; // Runtime: 4 ms  Memory Usage: 6 MB
```

```C++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n > 0){
            sum++;
            n = n&(n-1);
        }
        return sum;
    }
};//这个方法最好 Runtime: 0 ms  Memory Usage: 6.1 MB
```



(2) Hamming Distance

The [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) between two integers is the number of positions at which the corresponding bits are different.

Given two integers `x` and `y`, calculate the Hamming distance.

**Note:**
0 ≤ `x`, `y` < 231.

```
Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
```

```C++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int sum = 0;
        while(n > 0){
            sum++;
            n = n&(n-1);
        }
        return sum;
    }
};
```



(3) Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

```C++
Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
```

```C++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        if (n == 0) return 0;
        uint32_t result = 0;
        int i = 0;
        while(n != 0)
        {
            result = result * 2 + n % 2;
            n = n / 2;
            i ++;
        }
        return result << (32-i);
    }
};
```

```C++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++){
            res = res * 2 + n % 2;
            n = n / 2;
        }
        return res;
    }
}; //比上述方法好
```

```C++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t pos = 31;
        uint32_t res = 0;
        while(n > 0){
            res = res + ((n&1) << pos); //2个小括号都是必须的，注意优先级
            n = n >> 1;
            pos--;
        }
        return res;
    }
};
```



(4) Pascal's Triangle

Given a non-negative integer *numRows*, generate the first *numRows* of Pascal's triangle.

```C++
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       if(numRows==0) return vector<vector<int> >();
        vector<vector<int>> result(numRows, vector<int>{});
        result[0].push_back(1);
        for(int row = 1; row < numRows; row++)
        {
            result[row].push_back(1);
            for(int i = 0; i < row-1; i++)
            {
                result[row].push_back(result[row-1][i]+result[row-1][i+1]);    
            }
            result[row].push_back(1);
        }
        return result;
        
    }
};
```

```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++){
            vector<int> subres(1,1);
            for(int j = 1; j < i; j++){
                subres.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            if(i > 0)
                subres.push_back(1);
            
            res.push_back(subres); 
        }
        return res;
    }
};
```



(5) Valid Parentheses

Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

```C++
Input: "{[]}"
Output: true
```

```C++
Input: "([)]"
Output: false
```

```C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> stacks;
        for(auto i : s){
            if(i == '(' || i == '[' || i == '{')
                stacks.push(i);
            else if(i == ')' && !stacks.empty() && stacks.top() == '(' )
                stacks.pop();
            else if(i == ']' && !stacks.empty() && stacks.top() == '[' )
                stacks.pop();
            else if(i == '}' && !stacks.empty() && stacks.top() == '{' )
                stacks.pop();
            else
                return false;
        }
        return stacks.empty();
        
    }
};
```



(6) Missing Number

Given an array containing *n* distinct numbers taken from `0, 1, 2, ..., n`, find the one that is missing from the array.

```C++
Input: [3,0,1]
Output: 2
```

```C++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end(),[](const int &i, const int &j){return i > j;});
        int sum = accumulate(nums.begin(),nums.end(),0);
        int leave = *nums.begin() * (*nums.begin()+1)/2 - sum;
        if(leave == 0)
            if(*(nums.end()-1) == 0)
                return *nums.begin()+1;
            else
                return 0;
        else
            return leave;
    }
}; // 垃圾。。
```

```C++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        auto iter = max_element(nums.begin(), nums.end());
        if (nums.size() != *iter)
            return nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return nums.size() * (nums.size() + 1) / 2 - sum ;
        
    }
};
```

