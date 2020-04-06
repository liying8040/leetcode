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
};
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
};
```

