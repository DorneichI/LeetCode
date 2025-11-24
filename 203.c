/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    while (prev->next) {
        if (prev->next->val == val) {
            prev->next = prev->next->next;
        } else {
            prev = prev->next;
        }
    }
    return dummy.next;
}