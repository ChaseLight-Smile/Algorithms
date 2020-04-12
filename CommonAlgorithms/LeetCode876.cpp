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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> ans;
        ListNode* current = head;
        while(current != nullptr){
            ans.push_back(current);
            current = current->next;
        }
        return ans[ans.size()/2];
    }
};