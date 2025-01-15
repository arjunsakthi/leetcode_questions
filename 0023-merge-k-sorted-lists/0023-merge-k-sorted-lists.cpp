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
 struct compare{
    bool operator()(ListNode*& l1,ListNode*& l2){
        return l1->val < l2->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*, vector<ListNode*>, compare> pq;  
      for(int i =0; i<lists.size(); i++){
        ListNode* head = lists[i];
        while(head != NULL){
            pq.push(head);
            head = head->next;
        }
      }
      ListNode* head = NULL;
      while(!pq.empty()){
        ListNode* tope = pq.top();
        pq.pop();
        tope->next = head;
        head = tope;
      }
      return head;
    }
};