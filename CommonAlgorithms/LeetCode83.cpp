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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* front = head;
        ListNode* current = head->next;
         
        while(current != nullptr){
            if(front->val == current->val){
                current = current->next;
                front->next = current;  
            }else{
                front = current;
                if(current != nullptr)
                    current = current->next;
                }
            
        }
        return head;
    }
};