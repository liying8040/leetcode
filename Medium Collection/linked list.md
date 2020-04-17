# Linked List

(1) Add Two Numbers

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

```C++
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3, *node, *end, *p, *q;
    int i, tag = 0, res = 0;
    l3 = (struct ListNode *) malloc (sizeof(struct ListNode));   // head
    l3 -> val =  (l1 -> val + l2 -> val) % 10;
    res = ((l1 -> val + l2 -> val) < 10) ? 0 : 1;
    l1 = l1 -> next;
    l2 = l2 -> next;
    end = l3;
    
    while(l1 != NULL || l2 != NULL){
        node = (struct ListNode *) malloc (sizeof(struct ListNode));
        if(l1 == NULL){
            node -> val = (l2 -> val + res) % 10;
            res = ((l2 -> val + res) < 10) ? 0 : 1;
            l2 = l2 -> next;
            end -> next = node;
            end = node;
        }
        else if (l2 == NULL){
            node -> val = (l1 -> val + res) % 10;
            res = ((l1 -> val + res) < 10) ? 0 : 1;
            l1 = l1 -> next;
            end -> next = node;
            end = node;
        }
        else{
            node -> val = (l1 -> val + l2 -> val + res) % 10;
            res = ((l1 -> val + l2 -> val + res) < 10) ? 0 : 1;
            l1 = l1 -> next;
            l2 = l2 -> next;
            end -> next = node;
            end = node;            
        }
    }
    
    if(res != 0){
        node = (struct ListNode *) malloc (sizeof(struct ListNode));
        node -> val = res;
        end -> next = node;
        end = node;  
        
    }
    end -> next = NULL;
    return l3;
}


```

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        int carry = 0;
        while(l1 || l2){
            if(l1 && l2){
                int temp = l1 -> val + l2 -> val + carry;
                carry = temp / 10;
                l1 -> val = temp % 10;
            }else if(l1){
                int temp = l1 -> val + carry;
                carry = temp / 10;
                l1 -> val = temp % 10;
            }
            if(!l1->next && l2){  //如果l1->next == NULL && l2 = NULL，把l1连接到l2上去。
                l1->next = l2->next;
                l1 = l1 -> next;
                l2 = NULL;
            }else if(l1 && l2){
                l1 = l1 -> next;
                l2 = l2 -> next;              
            }else{
                l1 = l1 -> next;
            }
        }
        if(carry){
            ListNode *p = new ListNode(carry);
            ListNode *m = p1;
            while(m -> next != NULL)
                m = m -> next;
            m -> next = p;
        }      
        return p1;
    }
};
```

(2) Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

```C++
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
```

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        if(head -> next == NULL) return head;
       
        ListNode *Odd = head, *Even = head->next;
        ListNode *a = Odd, *b = Even;
        while(b != NULL && b -> next != NULL){
            a -> next = b -> next;
            a = a -> next;
            b -> next = a -> next;
            b = b -> next;
        }
        a -> next = Even;
        return Odd;
    }
};
```

(3) Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

[![img](https://assets.leetcode.com/uploads/2018/12/13/160_statement.png)](https://assets.leetcode.com/uploads/2018/12/13/160_statement.png)

begin to intersect at node c1.

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *p1 = headA, *p2 = headB;
        while(p1 != NULL || p2 != NULL)
        {   
            if(p1 == p2)
                return p1;
            p1 = p1 -> next;
            p2 = p2 -> next;
            if(p1 == NULL && p2 == NULL)
                return NULL;
            if(p1 == NULL)
                p1 = headB;
            if(p2 == NULL)
                p2 = headA;
        }
        return NULL;
    }
};
```

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *p1 = headA, *p2 = headB;
        int FirstA = 1, FirstB = 1;
        while(p1 != NULL){
            if(p1 == p2)
                return p1;
            if(p1 -> next == NULL && FirstA == 1){
                p1 = headB;
                FirstA = 0;
            }else{
                p1 = p1 -> next;
            }
            if(p2 -> next == NULL && FirstB == 1){
                p2 = headA;
                FirstB = 0;
            }else
                p2 = p2 -> next;
        }
        return NULL;
    }
}; // A+C+B+C = B+C+A+C
```

