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
    ListNode* removeElements(ListNode* head, int val) { 
        if(head == nullptr){
            return NULL;
        }
        while(head->val == val){
            head = head->next;
            if(head == nullptr){
                return head;
            }
        }
        ListNode* current = head->next;
        ListNode* prev = head;
        while(current != nullptr){
            if(current->val == val){
                current = current->next;
                prev->next = current;
                continue;
            }
            prev = current;
            current = current->next;
        }
        return head;
    }
};