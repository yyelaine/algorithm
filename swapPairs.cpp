/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    public ListNode swapPairs(ListNode head) {
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
}