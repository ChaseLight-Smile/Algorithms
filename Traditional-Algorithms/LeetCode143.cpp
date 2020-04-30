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
    void reorderList(ListNode* head) {
        vector<int>ans;
        ListNode* current = head;
        if(head == nullptr){
            return;
        }
        while(current != nullptr){
            ans.push_back(current->val);
            current = current->next;
        }
        
        vector<int>result;
        int len = ans.size();
        if(len % 2 == 0){
            for(int i = 0 ; i <= (len-1)/2; i++){
                result.push_back(ans[i]);
                result.push_back(ans[len-1-i]);
            }
        }else{
            int i = 0;
            for(i = 0 ; i < (len-1)/2; i++){
                result.push_back(ans[i]);
                result.push_back(ans[len-1-i]);
            }
            result.push_back(ans[i]);
        }
        current = head;
        for(int i = 1; i < len; i++){
            current-> next = new ListNode(result[i]);
            current = current->next;
        }
        
    }
};