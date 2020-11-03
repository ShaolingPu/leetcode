/**
Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
**/

/**
Runtime: 48 ms, faster than 72.31% of C++ online submissions for Insertion Sort List.
Memory Usage: 10.1 MB, less than 6.04% of C++ online submissions for Insertion Sort List.
**/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        while(head){
            ListNode *p = dummy;
            while(p -> next && p -> next -> val < head -> val){
                p = p -> next;
            }
            ListNode *t = head;
            head = head -> next;
            t -> next = p -> next;
            p -> next = t;
        }
        return dummy -> next;
    }
};
