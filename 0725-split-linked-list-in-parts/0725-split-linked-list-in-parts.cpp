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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temphead = head;
        int count = 0;
        while(temphead != NULL){
            temphead = temphead->next;
            count++;
        }
        vector<ListNode*> ans;
        temphead = head;
        if(count < k){
            for(int i=0; i<count; i++){
                ans.push_back(temphead);
                ListNode* temp = temphead;
                temphead = temphead->next;
                temp->next = NULL;
            }
            for(int i=0; i<k-count; i++){
                ans.push_back(NULL);
            }
        }
        else{
            int rem = count%k;
            int c = count/k;
            for(int i=0; i<k; i++){
                ans.push_back(temphead);
                int p=0;
                ListNode *temp = NULL;
                if(rem != 0){
                    rem -= 1;
                    p=1;
                }
                for(int j=0; j<c+p-1; j++){
                    temphead = temphead->next;
                }
                temp = temphead;
                temphead = temphead->next;
                temp->next = NULL;
            }
        }
        return ans;
    }
};