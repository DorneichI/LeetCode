/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* tmp = &dummy;
    while (tmp->next && tmp->next->next) {
        if (tmp->next->val == tmp->next->next->val) {
            int v = tmp->next->val;
            while (tmp->next && tmp->next->val == v) {
                tmp->next = tmp->next->next;
            }
        } else {
            tmp = tmp->next;
        }
    }
    return dummy.next;
}