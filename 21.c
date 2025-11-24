/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode tmp;
    struct ListNode* worker = &tmp;
    tmp.next = NULL;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            worker->next = list1;
            list1 = list1->next;
        } else {
            worker->next = list2;
            list2 = list2->next;
        }
        worker = worker->next;
    }
    
    worker->next = list1 ? list1 : list2;

    return tmp.next;
}