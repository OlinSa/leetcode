#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        int l1_val, l2_val = 0;

        do {
            if (l1 != nullptr) {
                l1_val = l1->val;
                l1 = l1->next;
            } else {
                l1_val = 0;
            }
            if (l2 != nullptr) {
                l2_val = l2->val;
                l2 = l2->next;
            } else {
                l2_val = 0;
            }
            int v = (l1_val + l2_val + carry) % 10;
            carry = (l1_val + l2_val + carry) / 10;

            if (head == nullptr) {
                head = tail = new ListNode(v);
            } else {
                tail->next = new ListNode(v);
                tail = tail->next;
            }
        } while (l1 != nullptr || l2 != nullptr);
        if (carry != 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

void casesuit(ListNode *l1, ListNode *l2) {
    Solution solution;
    ListNode *r = solution.addTwoNumbers(l1, l2);
    while (r != nullptr) {
        std::cout << r->val << " ";
        r = r->next;
    }
    std::cout << std::endl;
}

ListNode *general_test_data(std::vector<int> s) {
    ListNode *head = nullptr, *tail = nullptr;
    for (int i = 0; i < s.size(); ++i) {
        if (head == nullptr) {
            head = tail = new ListNode(s[i]);
        } else {
            tail->next = new ListNode(s[i]);
            tail = tail->next;
        }
    }
    return head;
}

int main(int argc, char *argv[]) {
    casesuit(general_test_data(std::vector<int>{2, 4, 3}), general_test_data(std::vector<int>{5, 6, 4}));
    casesuit(general_test_data(std::vector<int>{0}), general_test_data(std::vector<int>{0}));
    casesuit(general_test_data(std::vector<int>{9,9,9,9,9,9,9}), general_test_data(std::vector<int>{9,9,9,9}));
    return 0;
}