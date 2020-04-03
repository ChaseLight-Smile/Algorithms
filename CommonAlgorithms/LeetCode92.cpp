/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//解法一： Space complexity O(n)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        vector<int> tmp;
        ListNode* current = head;
        while(current != NULL){
            tmp.push_back(current->val);
            current = current->next;
        }
        
        int first_index = m - 1;
        int last_index = n - 1;
        if((m-n+1)%2 == 0){
            for(int i = first_index ; i <= (first_index + (last_index - first_index)/2); i++){
                int ddd = tmp[i];
                tmp[i] = tmp[last_index+first_index-i];
                tmp[last_index+first_index-i] = ddd;
            }
        }else{
            for(int i = first_index ; i < (first_index + (last_index - first_index)/2); i++){
                int ddd = tmp[i];
                tmp[i] = tmp[last_index+first_index-i];
                tmp[last_index+first_index-i] = ddd;
            }
        }
        
        ListNode* ans_head = new ListNode(0);
        current = ans_head;
        for(int i = 0 ; i < tmp.size(); i++){
            current->next = new ListNode(tmp[i]);
            current = current->next;
        }
        
        return ans_head->next;
    }
};

//解法二：原地翻转 O(1)