/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode smaller;
    struct ListNode* smallerTmp = &smaller;
    struct ListNode larger;
    struct ListNode* largerTmp = &larger;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* tmp = &dummy;

    while (tmp->next) {
        if (tmp->next->val < x) {
            smallerTmp->next = tmp->next;
            smallerTmp = smallerTmp->next;
        } else {
            largerTmp->next = tmp->next;
            largerTmp = largerTmp->next;
        }
        tmp = tmp->next;
    }
    largerTmp->next = NULL;
    smallerTmp->next = larger.next;
    return smaller.next;
}