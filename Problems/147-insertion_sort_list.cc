
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
  ListNode *insertionSortList(ListNode *head) {
    /**
     *         4          2   1   3
     *         ^          ^
     * dummy sorted_last  cur
     *
     * prev
     */

    if (head == nullptr || head->next == nullptr) return head;
    ListNode *dummy = new ListNode(-1, head);
    ListNode *sorted_last = head, *cur = head->next;

    while (cur != nullptr) {
      if (cur->val >= sorted_last->val) {
        sorted_last = sorted_last->next;
      } else {
        ListNode *prev = dummy;
        while (prev->next->val <= cur->val) {
          prev = prev->next;
        }
        sorted_last->next = cur->next;
        cur->next = prev->next;
        prev->next = cur;
      }
      cur = sorted_last->next;
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
  tail->next = nullptr;
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
  dumpList(
      s.insertionSortList(general_test_data(std::vector<int>{4, 2, 1, 3})));
  dumpList(
      s.insertionSortList(general_test_data(std::vector<int>{-1, 5, 3, 4, 0})));
  return 0;
}