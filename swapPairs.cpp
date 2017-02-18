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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
         if(head==NULL) return head;
        ListNode* p = head;
        while(p != NULL && p->next != NULL){
            int tmp = p->val;
            p->val = p->next->val;
            p->next->val = tmp;
            p = p->next->next;
        }
        return head;
    }
};