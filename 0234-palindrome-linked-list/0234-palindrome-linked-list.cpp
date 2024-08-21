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
    bool isPalindrome(ListNode* head) {
        string num = "";
        int count = 0;
        if(head == NULL && head->next == NULL){
            return true;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == NULL){
            slow = slow->next;
        }
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        while(slow != NULL){
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }
        while(prev != NULL && head != NULL){
            if(prev->val != head->val)  return false;
            prev = prev->next;
            head = head->next;
        }
        
        return true;
    }
};