/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if(head==NULL||n==0)
        return NULL;
         
        ListNode *p1=head;
        ListNode *p2=NULL;
        for(int i=0;i<n-1;i++)
        {
            if(p1->next!=NULL)
            {
                p1=p1->next;
            }
            else
            return NULL;
        }
        p2=head;
        while(p1->next!=NULL)
        {
            p1=p1->next;
            p2=p2->next;
        }
        return p2;
    }
};


