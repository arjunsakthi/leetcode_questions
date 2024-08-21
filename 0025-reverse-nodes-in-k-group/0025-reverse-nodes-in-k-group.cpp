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

// Function to reverse a linked list using the 3-pointer approach
ListNode* reverseLinkedList(ListNode *head) {
    ListNode* current = head;  
    ListNode* prev = nullptr;  
    
    while(current != nullptr) {  
        ListNode* nextNode = current->next;  
        current->next = prev;  
        prev = current;  
        current = nextNode; 
    }
    return prev;  
}

// Function to get the k-th node from the current node
ListNode* getKthNode(ListNode* current, int k) {
    k -= 1; 
    while(current != nullptr && k > 0) {
        k--; 
        current = current->next; 
    }
    return current; 
}

// Function to reverse every k nodes in the linked list
ListNode* kReverse(ListNode* head, int k) {
    ListNode* current = head; 
    ListNode* prevLast = nullptr; 
    while(current != nullptr) {
        ListNode* kThNode = getKthNode(current, k);
        if(kThNode == nullptr) {
            if(prevLast) {
                prevLast->next = current; 
            }
            break; 
        }
        ListNode* nextGroupHead = kThNode->next; 
        kThNode->next = nullptr; 
        reverseLinkedList(current);
        if(current == head) {
            head = kThNode;
        } else {
            prevLast->next = kThNode; 
        }
        prevLast = current; 
        current = nextGroupHead; 
    }

    return head; 
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return kReverse(head, k);
    }
};
