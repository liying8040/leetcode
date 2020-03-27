

# linked list

(1)  Delete Node in a Linked List

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
```

```C++
class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        ListNode *p = node -> next;
        node -> next = p -> next;
        delete(p);
    }
};
```

```C++
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
```

```C++
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node -> next;   
    }
};
```

(2) Remove Nth Node From End of List

Given a linked list, remove the *n*-th node from the end of list and return its head.

```
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
```

```
Given linked list: 1->2->3->4->5, and n = 5.

After removing the second node from the end, the linked list becomes 2->3->4->5.
```

<img src="E:\git\leetcode\img\link_list2.jpg" style="zoom:50%;" />

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        while(n--){
            fast = fast -> next;
        }
        if(fast == NULL) return head -> next;
        while(fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};
```

(3) 