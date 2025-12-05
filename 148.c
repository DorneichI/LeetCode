/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void merge(struct ListNode* head, int mid, int length) {
    int* leftList = malloc(mid * sizeof(int));
    int* rightList = malloc((length - mid) * sizeof(int));

    struct ListNode* cpy = head;
    int i;
    for (i = 0; i < mid; i++) {
        leftList[i] = cpy->val;
        cpy = cpy->next;
    }
    for (; i < length; i++) {
        rightList[i - mid] = cpy->val;
        cpy = cpy->next;
    }

    cpy = head;
    i = 0;
    int j = 0;
    while (i < mid && j < length - mid) {
        if (leftList[i] < rightList[j]) cpy->val = leftList[i++];
        else cpy->val = rightList[j++];
        cpy = cpy->next;
    }
    while (i < mid) {
        cpy->val = leftList[i++];
        cpy = cpy->next;
    }
    while (j < length - mid) {
        cpy->val = rightList[j++];
        cpy = cpy->next;
    }
    free(leftList);
    free(rightList);
}

void mergeSort(struct ListNode* head, int length) {
    if (length > 1) {
        int mid = length / 2;
        struct ListNode* rightHead = head;
        for (int i = 0; i < mid; i++) {
            rightHead = rightHead->next;
        }
        
        mergeSort(head, mid);
        mergeSort(rightHead, length - mid);
        merge(head, mid, length);
    }
}

struct ListNode* sortList(struct ListNode* head) {
    int length;
    struct ListNode* cpy = head;
    for (length = 0; cpy; length++) cpy = cpy->next;
    mergeSort(head, length);
    return head;
}