class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;           // first node (odd)
        ListNode* even = head->next;    // second node (even)
        ListNode* evenHead = even;      // store start of even list

        while (even && even->next) {
            odd->next = even->next;     // link next odd
            odd = odd->next;

            even->next = odd->next;     // link next even
            even = even->next;
        }

        odd->next = evenHead;           // connect odd list with even list

        return head;
    }
};