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
  ListNode *removeElements(ListNode *head, int val) {
    /**
     * dummy -> head -> node1 -> node2 .. ->noden
     */
    if (!head) return head;

    ListNode *dummy = new ListNode(-1, head);
    ListNode *current = dummy;

    while (current->next != nullptr) {
      if (current->next->val == val) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }

    return dummy->next;
  }
};

void dumpList(ListNode *p) {
  while (p != nullptr) {
    std::cout << p->val << "->";
    p = p->next;
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
  if (tail != nullptr) {
    tail->next = nullptr;
  }

  return head;
}

int main(int argc, char *argv[]) {
  Solution s;
  dumpList(s.removeElements(
      general_test_data(std::vector<int>{1, 2, 6, 3, 4, 5, 6}), 6));
  dumpList(s.removeElements(general_test_data(std::vector<int>{}), 1));
  dumpList(
      s.removeElements(general_test_data(std::vector<int>{7, 7, 7, 7}), 7));

  return 0;
}