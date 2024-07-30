
#include <algorithm>
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;

    int i = left;
    while (--i > 0) {
      prev = prev->next;
    }
    ListNode *cur = prev->next;
    ListNode *next = nullptr;

    for (int i = 0; i < right - left; i++) {
      next = cur->next;
      cur->next = next->next;
      next->next = prev->next;
      prev->next = next;
    }

    return dummy->next;
  }
};

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

void dumpList(ListNode *p) {
  while (p != nullptr) {
    std::cout << p->val << "->";
    p = p->next;
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  Solution s;

  dumpList(s.reverseBetween(general_test_data(std::vector<int>{1, 2, 3, 4, 5}),
                            2, 4));
  dumpList(s.reverseBetween(general_test_data(std::vector<int>{5}), 1, 1));
  return 0;
}