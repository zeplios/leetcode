/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int count = 0;
    struct ListNode* cur = head;
    struct ListNode* head1 = head;
    struct ListNode* head2;
    struct ListNode* tmp;
    while (cur) {
        count++;
        cur = cur->next;
    }
    if (count < 2) return true;
    
    // reverse
    int half = count / 2;
    while (half > 1) {
        tmp = head->next;
        head->next = head->next->next;
        tmp->next = head1;
        head1 = tmp;
        half--;
    }
    if (count & 1 == 1) {
        head2 = head->next->next;
    } else {
        head2 = head->next;
    }
    bool ret = true;
    while (head2 != NULL) {
        if (head1->val != head2->val) {
            ret = false;
            break;
        }
        tmp = head1;
        head1 = head1->next;
        if (tmp != head) {
            // reverse
            tmp->next = head->next;
            head->next = tmp;
        }
        head2 = head2->next;
    }
    return ret;
}