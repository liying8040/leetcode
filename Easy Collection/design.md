# design

(1) Shuffle an Array

Shuffle a set of numbers without duplicates.

```C++
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
```



```C++
class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int end = copy.size() - 1;
        for(int i = end; i >= 0; i--){
            int pos = rand() % (i+1);
            swap(copy[i],copy[pos]);
        }
        return copy;
    }
private:
    vector<int> nums;
    vector<int> copy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```

(2) Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- getMin() -- Retrieve the minimum element in the stack.

```C++
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

```C++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { }
    void push(int x) {
        if(stack2.empty() || stack2.top() >= x)
            stack2.push(x);
        stack1.push(x);
    }
    void pop() {
        if(stack1.top() == stack2.top())
            stack2.pop();
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int getMin() {
        return stack2.top();
    }
private:
    stack<int> stack1, stack2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

```C++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { }
    
    void push(int x) {
        stacks.push(x);
        if(min.empty())
            min.push(x);
        else{
            int t = min.top() < x ? min.top() : x;
            min.push(t);
        }      
    }
    
    void pop() {
        stacks.pop();
        min.pop();
    }
    
    int top() {
        return stacks.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> stacks;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

