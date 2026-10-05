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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next;
        ListNode* curr = head;

        while (curr){ // loop until current because we need to include the last element in the reverse list
            next = curr->next; // offload the direction related information as it need to change its direction 
            curr->next = prev; // change the direction
            prev = curr; // update the loop state
            curr = next; // update the loop state
        }
        return prev; // return prev because curr ends up in the nullptr at the end
    }
};
