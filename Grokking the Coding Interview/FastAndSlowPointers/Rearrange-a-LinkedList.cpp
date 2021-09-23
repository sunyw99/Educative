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

class RearrangeList {
   public:
    static void reorder(ListNode* head) {
        // TODO: Write your code here
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = reverse(slow);
        while (head != nullptr && tail != nullptr) {
            ListNode* headnext = head->next;
            ListNode* tailnext = tail->next;
            head->next = tail;
            head = headnext;
            tail->next = head;
            tail = tailnext;
        }
        if (head != nullptr) {
            head->next = nullptr;
        }
    }

   private:
    static ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next = new ListNode(12);
    RearrangeList::reorder(head);
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
}
