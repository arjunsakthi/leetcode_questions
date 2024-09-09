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

    int value(ListNode* node){
        if(node == NULL)    return -1;
        else return node->val;
    }
    ListNode* nxt(ListNode* node){
        if(node == NULL)    return node;
        else return node->next;
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        vector<vector<int>> ans(m,vector<int>(n,-1)); 
        while(left <= right && top <= bottom && head != NULL){
            for(int i=left; i<=right; i++){
                ans[top][i] = value(head);
                head = nxt(head);
            }
            top++;
            if(top > bottom)    break;
            if(head == NULL)    break;
            for(int i=top; i<=bottom; i++){
                ans[i][right] = value(head);
                head = nxt(head);
            }
            right--;
            if(left > right)    break;
            if(head == NULL)    break;
            for(int i=right; i>=left; i--){
                ans[bottom][i] = value(head);
                head = nxt(head);
            }
            bottom--;
            if(top > bottom)    break;
            if(head == NULL)    break;
            for(int i=bottom; i>=top; i--){
                ans[i][left] = value(head);
                head = nxt(head);
            }
            left++;
        }
        return ans;
    }
};