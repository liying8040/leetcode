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

<img src=".\img\link_list(2).jpg" alt="link_list(2)" style="zoom:80%;" />

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

(3) Reverse Linked List

```
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *h = new ListNode(0);
        ListNode *cur = head;
        while(head != NULL){
            head = head -> next;
            cur -> next = h -> next;
            h -> next = cur;
            cur = head;            
        }
        return h -> next;
    }
};
```

(4)  Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

```c++
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *l3 = new ListNode(0);
        ListNode *q = l3;
        while(l1 != NULL && l2 != NULL){              
                if (l1 -> val < l2 -> val){
                    q -> next = l1;
                    l1 = l1 -> next;
                }else{
                    q -> next = l2;
                    l2 = l2 -> next;
                }
                q = q -> next;
        }
        if(l1 == NULL)
            q -> next = l2; 
        else if(l2 == NULL)
            q -> next = l1; 
        return l3->next;
    }
};
```

```C++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *l3, *q;
        if(l1 -> val < l2 -> val){
            l3 = l1;
            q = l3;
            l1 = l1 ->next;
        }else{
            l3 = l2;
            q = l3;
            l2 = l2 ->next;
        }   
        while(l1 != NULL && l2 != NULL){              
                if (l1 -> val < l2 -> val){
                    q -> next = l1;
                    l1 = l1 -> next;
                }else{
                    q -> next = l2;
                    l2 = l2 -> next;
                }
                q = q -> next;
        }
        if(l1 == NULL)
            q -> next = l2; 
        else if(l2 == NULL)
            q -> next = l1;
        return l3;
    }
};
```

```C++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head1 = NULL, *head2 = NULL;
        
        if(l1 -> val <= l2 -> val){
            head1 = l1, head2 = l2;
        }else{
            head1 = l2, head2 = l1;
        }
        ListNode *cur1 = head1, *cur2 = head2;
        ListNode *pre1 = NULL, *pre2 = NULL;
        
        while(cur1 != NULL || cur2 != NULL){
            if(cur1 == NULL){
                pre1 -> next = cur2;
                return head1;
            }else if(cur2 == NULL){
                return head1;
            }else{
                if(cur1 -> val <= cur2 -> val){
                    pre1 = cur1;
                    cur1 = cur1 -> next;
                }else{
                    pre2 = cur2;
                    cur2 = cur2 -> next;
                    pre2 -> next = cur1;
                    pre1 -> next = pre2;
                    pre1 = pre1 -> next;
                }
            }  
        }
        return head1;
    }
};
```

(5) Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

```
Input: 1->2
Output: false
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
    ListNode *reverse(ListNode *head){
        ListNode *pre, *cur;
        cur = head -> next;
        head -> next = NULL;
        while(cur != NULL){
            pre = cur;
            cur = cur -> next;
            pre -> next = head -> next;
            head -> next = pre;
        }
        return head;
    }
    
    bool compare(ListNode *head1, ListNode *head2){
        while(head2 != NULL){
            if (head1 -> val != head2 -> val)
                return false;
            else{
                head1 = head1 -> next;
                head2 = head2 -> next;
            }
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        ListNode *fast = head, *slow = head;   //让快指针走2步，慢指针走1步，来找中心位置。
        while(fast -> next != NULL){
            fast = fast -> next;
            if(fast -> next != NULL)
                fast = fast -> next;
            else
                break;
            slow = slow -> next;
        }
        ListNode * re_slow = reverse(slow);   // 多一个head节点，相当于C中的指向指针的指针。
        return compare(head, re_slow-> next);  //取 head -> next。
    }
};  
```

```C++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        
        while(head != NULL){
            vec.push_back(head -> val);
            head = head -> next;
        }
        for(int i = 0; i < vec.size()/2; i++){
            if(vec[i] != vec[vec.size() - i - 1])
                return false;
        }
        return true;
    }
}; // 不推荐该方法。
```

(6) Linked List Cycle

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer `pos` which represents the position (0-indexed) in the linked list where tail connects to. If `pos` is `-1`, then there is no cycle in the linked list.

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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        set<ListNode *> node;
        while(head != NULL)
        {
            if(node.find(head) == node.end())
                node.insert(head);             
            else
                return true;  
            head = head->next;
        }
        return false;
    }
};
```

```C++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *fast = head, *slow = head;  //快慢指针，快指针走2步，慢指针1步，找循环。
        while(fast -> next != NULL){
            fast = fast -> next;
            if(fast -> next != NULL)
                fast = fast -> next;
            else
                return false;
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
```

