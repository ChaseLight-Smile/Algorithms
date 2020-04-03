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
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* tmp;
        if (current == NULL){
            return NULL;
        }
        while(current->next != NULL){
            tmp = current->next;
            current->next = prev;
            prev = current;
            current = tmp;
        }
        current->next = prev;
        return current;
    }
};