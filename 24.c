/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    while(head && head->next) {
        prev->next = head->next;
        head->next = prev->next->next;
        prev->next->next = head;
        prev = prev->next->next;
        head = prev->next;
    }

    return dummy.next;
}