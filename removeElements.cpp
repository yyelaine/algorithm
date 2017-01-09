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
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        while (head!=NULL && head->val==val)
        {
            head=head->next;
        }
        if(head==NULL)
        return NULL;
        ListNode *p=head;
        ListNode *q=head->next;
        while(q!=NULL)
        {
                if(q->val==val)
            {
                p->next=q->next;
                q=q->next;
            }
            else
            {
                p=q;
                q=q->next;
            }
        }
        
        return head;
    }
};