
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
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *cur = dummyHead;
    while (cur->next != nullptr && cur->next->next) {
      if (cur->next->val == cur->next->next->val) {
        int x = cur->next->val;
        // This removes all nodes with duplicate values.
        while (cur->next && cur->next->val == x) {
          cur->next = cur->next->next;
        }
      } else {
        cur = cur->next;
      }
    }

    return dummyHead->next;
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
  dumpList(s.deleteDuplicates(
      general_test_data(std::vector<int>{1, 2, 3, 3, 4, 4, 5})));
  dumpList(
      s.deleteDuplicates(general_test_data(std::vector<int>{1, 1, 1, 2, 3})));

  return 0;
}