//解法一：作弊解法，空间复杂度O(n)，时间复杂度O(nlogn)
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* current = head;
        vector<int> ans;
        while(current != nullptr){
            ans.push_back(current->val);
            current = current->next;
        }
        
        sort(ans.begin(), ans.end());
        
        int len = ans.size();
        head = new ListNode(0);
        current = head;
        for(int i = 0 ; i < len; i++){
            current->next = new ListNode(ans[i]);
            current = current->next;
        }
        return head->next;
    }
};
//解法二：
