class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* dummy = new Node(0);
        Node* copyTail = dummy;

        while (curr) {
            Node* copy = curr->next;

            copyTail->next = copy;
            copyTail = copy;

            curr->next = copy->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};