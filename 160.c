/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* prevA;
    struct ListNode* prevB;

    prevA = headA;
    while (prevA) {
        prevB = headB;
        while (prevB) {
            if (prevB == prevA) {
                return prevB;
            }
            prevB = prevB->next;
        }
        prevA = prevA->next;
    }
    return NULL;
}
