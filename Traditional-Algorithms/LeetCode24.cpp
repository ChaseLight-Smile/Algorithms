//  答案正确但是不满足题目，题目要求节点的值不能被修改
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        while(current && current->next){
            int tmp = current->val;
            current->val = current->next->val;
            current->next->val = tmp;
            current = current->next->next;
        }
        return head;
    }
};

// 满足题目要求，没有修改每个节点的值，只是通过指针的交换完成
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        for(auto p = dummy; p->next && p->next->next;){
            auto a = p->next, b = a->next;
            p->next = b, a->next = b->next, b->next = a;
            p = a;
        }
        return dummy->next;
    }
};