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
    ListNode * findMiddle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    
    ListNode* Merge(ListNode * left , ListNode * right)
    {
        ListNode * dummy  = new ListNode();
        ListNode * ptr = dummy;
        while(left || right)
        {
            if(left == NULL)
            {
                ptr->next = right;
                break;
            }
            
            if(right == NULL)
            {
                ptr->next = left;
                break;
            }
            
            if(left->val > right->val)
            {
                ptr-> next = right;
                right = right->next;
            }
            else
            {
                ptr-> next = left;
                left = left->next;
                
            }
            ptr = ptr->next;
            
        }
        return dummy->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode * middle = findMiddle(head);
        ListNode* right = sortList(middle->next);
        middle->next = NULL;
        ListNode * left = sortList(head);
        
        return Merge(left,right);
        
    }
};