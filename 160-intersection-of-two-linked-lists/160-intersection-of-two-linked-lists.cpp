/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;
        ListNode *temp = headA;
        while(temp)
        {
            countA++;
            temp = temp->next;
        }
        temp = headB;
        while(temp)
        {
            countB++;
            temp = temp->next;
        }
        if(countA>countB)
        {
            for(int i = countA - countB ; i > 0 ; i--) headA = headA->next;
        }
        if(countB>countA)
        {
            for(int i = countB - countA ; i > 0 ; i--) headB = headB->next;
        }
        
        
        while(headA && headB && headA != headB)
        {
            headB = headB->next;
            headA = headA->next;
        }
        
        if(headA == headB)
            return headB;
        return NULL;
    }
};