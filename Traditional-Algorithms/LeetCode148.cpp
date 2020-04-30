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
    ListNode* sortList(ListNode* head) {
        vector<int> tmp;
        ListNode* current = head;
        while(current != NULL){
            tmp.push_back(current->val);
            current = current->next;
        }
        
        sort(tmp.begin(), tmp.end());
        
        ListNode* ans = new ListNode(0);
        current = ans;
        for(int i = 0 ; i < tmp.size(); i++){
            ListNode* a = new ListNode(tmp[i]);
            current->next = a;
            current = current->next;
        }
        
        return ans->next;
    }
};