/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
bool operator()(ListNode* a, ListNode* b) const {
    return (a->val) > (b->val);
}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        int len = lists.size();
        for(int i = 0 ; i < len; i++){
            if(lists[i] != nullptr)
                q.push(lists[i]);
        }
    
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        
        while(!q.empty()){
            ListNode* tmp = q.top();
            q.pop();
            current->next = tmp;
            if(tmp->next != nullptr)
                q.push(tmp->next);
            current = current->next;
        }
        return dummy->next;
    }
};