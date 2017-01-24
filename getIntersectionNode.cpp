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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        ListNode* tmpb = headB;
        ListNode* tmpa = headA;
        while (tmpa!=NULL){
            tmpb = headB;
            while (tmpb!=NULL){
                if (tmpa->val!=tmpb->val){
                    tmpb = tmpb->next;;
                }
                else{
                    return tmpa;
                }
            }
            tmpa = tmpa->next;
        }
        return NULL;
    }
};