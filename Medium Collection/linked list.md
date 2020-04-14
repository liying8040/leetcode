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

