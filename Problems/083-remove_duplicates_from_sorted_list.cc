
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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *n = head;
    while (n->next != nullptr) {
      if (n->val == n->next->val) {
        n->next = n->next->next;
      } else {
        n = n->next;
      }
    }
    return head;
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
  dumpList(s.deleteDuplicates(general_test_data(std::vector<int>{1, 1, 2})));
  dumpList(
      s.deleteDuplicates(general_test_data(std::vector<int>{1, 1, 2, 3, 3})));
  return 0;
}