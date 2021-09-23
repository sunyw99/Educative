using namespace std;

#include <iostream>

class ListNode {
   public:
    int value = 0;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedListCycleStart {
   public:
    static ListNode* findCycleStart(ListNode* head) {
        // TODO: Write your code here
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = fast->next;
                count = 1;
                while (fast != slow) {
                    fast = fast->next;
                    count++;
                }
                break;
            }
        }
        slow = head;
        fast = head;
        for (int i = 0; i < count; i++) {
            fast = fast->next;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    head->next->next->next->next->next->next = head->next->next;
    cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

    head->next->next->next->next->next->next = head->next->next->next;
    cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

    head->next->next->next->next->next->next = head;
    cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
}
