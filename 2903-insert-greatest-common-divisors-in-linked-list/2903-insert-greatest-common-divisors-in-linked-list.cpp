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

    int gcd(int a, int b){
        if(b==0)    return a;
         a = a%b;
        return gcd(b,a);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;
        ListNode* temp = head;
        while(temp->next != NULL){
            ListNode* after = temp->next;
            ListNode* nodee = new ListNode(gcd(temp->val,after->val),after);
            temp->next = nodee;
            temp = after;
        }
        return head;
    }
};