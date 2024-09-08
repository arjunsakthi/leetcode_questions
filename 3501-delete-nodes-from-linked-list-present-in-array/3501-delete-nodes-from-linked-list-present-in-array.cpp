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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *prev = new ListNode(0,head);
        ListNode *save = prev;
        ListNode *curr = head;
        unordered_map<int,int> ns;
        for(auto i:nums)ns[i]++;
        while(curr != NULL){
            if(ns.find(curr->val) != ns.end()){
                prev->next = curr->next;
                delete(curr);
            }
            else{
                prev = curr;
            }
            curr = prev->next;
        }
        return save->next;
    }
};