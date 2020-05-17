//link: https://leetcode.com/problems/odd-even-linked-list/

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

/*
Result:
Runtime: 20 ms, faster than 58.38% of C++ online submissions for Odd Even Linked List.
Memory Usage: 9.8 MB, less than 42.86% of C++ online submissions for Odd Even Linked List.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *tail = head;
        if(!head || !head -> next){
            return head;
        }
        
        int count = 1;
        while(tail -> next){
            tail = tail -> next;
            count ++;
        }
        
        count /= 2;
        
        ListNode *t = head;
        
        while(count){
            tail -> next = new ListNode(t -> next -> val);
            tail = tail -> next;
            t -> next = t -> next -> next;
            t = t -> next;
            count --;
        }
        return head;
    }
};