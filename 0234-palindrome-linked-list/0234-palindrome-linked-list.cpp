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
    ListNode* palind(ListNode* head, ListNode* current, int &ans){
        if(current == NULL) return head;
        ListNode* comp = palind(head,current->next,ans);
        if(comp->val != current->val) ans = 0;
        return comp->next;
    }
    bool isPalindrome(ListNode* head) {
        int ans=1;
        palind(head, head,ans);
        return ans;
    }
};