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
        ListNode* current = head;
        int len = 0;
        while(current != NULL){
            len++;
            current = current->next;
        }
        
        if (n >= len){
            head = head -> next;
            return head;
        }
        
        if(n == 0){
            return head;
        }
        
        int i = 0;
        current = head;
        while(i != len-n-1 && current != NULL){
            i++;
            current = current->next;
        }
        if (current->next->next != NULL)
            current-> next = current->next->next;
        else
            current->next = NULL;
        return head;        
    }
};