/**  单调栈
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> e;
        while(head){
            e.push_back(head->val);
            head = head->next;
        }
        vector<int>ans(e.size());
        stack<int>st;   //栈中推入某个数的位置即可
        for(int i = 0; i < e.size(); i++){
            while(!st.empty() && e[st.top()] < e[i]){
                ans[st.top()] = e[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};