class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* a = &dummy;

        for (int i = 1; i < left; i++) {
            a = a->next;
        }

        ListNode* b = a->next;
        ListNode* c = b;

        for (int i = left; i < right; i++) {
            c = c->next;
        }

        ListNode* d = c->next;

        a->next = NULL;
        c->next = NULL;

        ListNode* newHead = reverse(b);

        a->next = newHead;
        b->next = d;

        return dummy.next;
    }
};