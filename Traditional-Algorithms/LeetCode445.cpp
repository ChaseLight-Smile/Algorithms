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

//解法二：Success 
//Runtime: 36 ms, faster than 25.85% of C++ online submissions for Add Two Numbers II.
//Memory Usage: 10.9 MB, less than 62.96% of C++ online submissions for Add Two Numbers II.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> l1_nums;
        vector<int> l2_nums;
        vector<int> ans;
        
        ListNode* head = l1;
        ListNode* current = head;
        while(current != nullptr){
            l1_nums.push_back(current->val);
            current = current->next;
        }
        
        head = l2;
        current = head;
        while(current != nullptr){
            l2_nums.push_back(current->val);
            current = current->next;
        }
        
        int len_l1 = l1_nums.size();
        int len_l2 = l2_nums.size();
        int min = len_l1<len_l2?len_l1:len_l2;
        int flag = min;
        int i = len_l1-1;
        int j = len_l2-1;
        int ddd = 0;
        
        while(min > 0){
            int tmp = (l1_nums[i] + l2_nums[j] + ddd)%10;
            ans.push_back(tmp);
            ddd = (l1_nums[i] + l2_nums[j] + ddd) / 10;
            i--;
            j--;
            min--;
        }
        
        if (flag == len_l1 && flag == len_l2){
        }else{
            if (flag == len_l1){
            for(int k = j; k >= 0; k--){ 
                int tmp = (l2_nums[k] + ddd)%10;
                ans.push_back(tmp);
                ddd = (l2_nums[k] + ddd) / 10;
            }
        }else{
             for(int k = i; k >= 0; k--){
                int tmp = (l1_nums[k] + ddd)%10;
                ans.push_back(tmp);
                ddd = (l1_nums[k] + ddd) / 10;
            }
        }
        }
    
        if (ddd == 1){
            ans.push_back(ddd);
        }
        
        head = new ListNode(0);
        for(int i = 0 ; i < ans.size(); i++){
            ListNode* ans_tmp = new ListNode(ans[i]);
            ans_tmp->next= head->next;
            head->next = ans_tmp;
        }
        return head->next;    
    }
};