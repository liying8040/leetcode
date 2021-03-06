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

(5) Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

```
Input: "race a car"
Output: false
```

```C++
class Solution {
public:
bool isPalindrome(string s) {
	if (s.size() == 0) return true;
	int i = 0;
	int j = s.size() - 1;
	while (i <= j)
	{
		if (!isalnum(s[i]))
			i++;
		if (!isalnum(s[j]))
			j--;
		if (isalnum(s[i]) && isalnum(s[j]))
		{
			if (tolower(s[i]) == tolower(s[j]))
			{
				i++;
				j--;
			}
			else {
				return false;
			}
		}
	}
	return true;
}
};
```

```C++
class Solution {
public:
bool isPalindrome(string s) {
    if(s.size() == 0) return true;
	int len = 0;
	for (auto i : s) {
		if (isalnum(i))
			len++;
	}
	stack<char> stacks;
	int n = 0;
	for (int i = 0; i < s.size(); i++) {
		if (n < len / 2 && isalnum(s[i])) {
			stacks.push(tolower(s[i]));
			n++;
		}
		else if (len % 2 == 1 && n == len / 2 && isalnum(s[i])) {
			n++;
		}else if (n >= len / 2 && isalnum(s[i])) {
			n++;
			if (stacks.top() != tolower(s[i]))
				return false;
			else
				stacks.pop();
		}
	}
	return true;
}
};
```

(6) String to Integer (atoi)

Implement `atoi` which converts a string to an integer.

- Only the space character `' '` is considered as whitespace character.
- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

```C++
class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int res = 0;
        int flag = 0;
        for(int i = 0; i < str.size(); i++){
            if(isspace(str[i]) && flag == 0){
                continue;
            }else if(str[i] == '-' && res == 0 && flag == 0){
                sign = -1;
                flag = 1;
            }else if(str[i] == '+' && res == 0 && flag == 0){
                sign = 1;
                flag = 1;
            }else if(isdigit(str[i])){
                if(res < INT_MIN/10 || (res == INT_MIN/10 && (str[i] - '0') > 8))
                    return INT_MIN;
                else if(res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > 7))
                    return INT_MAX;
                else{
                    res = res * 10 + sign * (str[i] - '0');
                    flag = 1; 
                }                    
            }else{
                return res;
            }
        }
        return res;
    }
}; //要用INT_MIN 和 INT_MAX，不能用pow(2,31)-1代替INT_MAX,因为int不能处理pow(2,31)这个溢出的值。
```



(7) Implement strStr()

Return the index of the first occurrence of needle in haystack, or **-1** if needle is not part of haystack.

```
Input: haystack = "hello", needle = "ll"
Output: 2
```

```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        return (haystack.find(needle) == string::npos) ? -1 :haystack.find(needle);
        
    }
};
```

```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int temp = haystack.size() - needle.size() + 1;   //注意:temp不能放在for循环中
        for(int i = 0; i < temp; i++){
            for(int j = 0; j < needle.size(); j++){
                if(haystack[i+j] != needle[j])
                    break;
                else if(j == needle.size() - 1 )
                    return i;
            }
        }
        return -1;
    }
};// .size()方法返回值是unsigned int（size_t）类型，如果haystack.size() - needle.size() + 1是负数的话，会变成正数。
```

(8) Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:

```
1.     1
2.     11
3.     21
4.     1211
5.     111221
```

```C++
class Solution {
public:
    string recursive(string s)
    {
        string result;
        char pre = s[0];
        int count = 0,i = 0;
        while(i < s.size())
        {
            if(pre == s[i])
            {
                count ++;
                pre = s[i];
                i ++;
            }else{
                result.push_back(count+'0');
                result.push_back(pre);
                count = 0;
                pre = s[i];                
            }
        }
        result.push_back(count+'0');
        result.push_back(pre);
        return result;
    }
    string countAndSay(int n) {
        if (n==1) 
            return "1";
        else
            return recursive(countAndSay(n-1));
    }    
};
```



```C++

class Solution {
public:
    string recursive(string s){
        int size = s.length();
        string result;
        int count = 0;
        char pre = s[0];
        for (int i = 0; i < size; i++){
            //cur = s[i];
            if(s[i] == pre){
                count++;
            }else{
                //result = result+to_string(count)+pre;
                result.push_back(count+'0');
                result.push_back(pre);
                count = 1;
            }
            pre = s[i];
        }
        //result = result + to_string(count) + cur;
        result.push_back(count+'0');
        result.push_back(pre);
        return result;
    }
    string countAndSay(int n) {
        if (n==1){
            return "1";
        }else{
            return recursive(countAndSay(n-1));
        }
    }
};
```

```C++
class Solution {
public:
    string count(string s) {
	    int n = 1;
	    string res = "";
	    for (int i = 1; i < s.size(); i++) {
		    if (s[i] != s[i - 1]) {
			    res += to_string(n);
			    res += to_string(s[i - 1] - '0');
			    n = 1;
		    }
		    else {
			    n++;
		    }
	    }
	    res += to_string(n);
	    res += to_string(s[s.size() - 1] - '0');
	    return res;
    }
    string countAndSay(int n) {
        int i = 1;
        string res = "1";   
        while(i < n){
            res = count(res);
            i++;
        }       
        return res;
    }
};
```



(9) Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

```
Input: ["flower","flow","flight"]
Output: "fl"
```

```C++
class Solution {
public:
    string LCP(string& s1, string& s2) {
	    string temp;
	    size_t n = (s1.size() > s2.size()) ? s2.size() : s1.size();
	    while (n) {
		    temp = s2.substr(0, n);
		    n--;
		    if (s1.find(temp)==0 && s1.find(temp)!= string::npos)
			    return temp;
	    }
	    return "";
    }
       
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string pre = strs[0];
        for(auto s: strs){
            pre = LCP(pre,s);    
        }
        return pre;
        
    }
};
```

```C++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];
        int max_size = 0;
        int i = 0;
        while(i < strs.size()){
            max_size = strs[i].size() > max_size ? strs[i].size() : max_size;
            i++;
        }
        
        int j = 0;
        string res = "";
        while(j < max_size){
            for(int i = 1; i < strs.size(); i++){
                if(strs[0][j] != strs[i][j])
                    return res;
            }
            res.push_back(strs[0][j]);
            j++;
        }
        return res;
    }
};
```

