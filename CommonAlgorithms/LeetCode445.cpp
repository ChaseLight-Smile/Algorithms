/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //解法一：错误解法,每个链表的长度远远超过int或者long能表达的范围，小整数下面代码能通过测试
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* current = head;
        long sum1 = 0 ;
        while(current != nullptr){
            sum1 = sum1 * 10 + current->val;
            current = current->next;
        }
        head = l2;
        current = head;
        long sum2 = 0;
         while(current != nullptr){
            sum2 = sum2 * 10 + current->val;
            current = current->next;
        }
        
        long sum = sum1 + sum2;
        if(sum == 0){
            return new ListNode(0);
        }
        vector<int> ans;
        while(sum > 0){
            ans.push_back(sum % 10);
            sum = sum / 10;
        }
        
        int len = ans.size();
        ListNode* head_ans = new ListNode(0);
        current = head_ans;
        for(int i = len-1; i >=0; i--){
            current->next = new ListNode(ans[i]);
            current = current->next;
        }
        
        return head_ans->next;
    }
};