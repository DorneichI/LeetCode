/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    int length = 0;
    struct ListNode* tmp = head;
    while (tmp) {
        length++;
        tmp = tmp->next;
    }

    tmp = &dummy;
    for (int i = 0; i < length - n; i++) {
        tmp = tmp->next;
    }

    struct ListNode* toDelete = tmp->next;
    tmp->next = tmp->next->next;
    free(toDelete);

    return dummy.next;
}