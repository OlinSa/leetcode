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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || k == 0 || head->next == nullptr) return head;
    int size = 1;
    ListNode *iter = head;
    while (iter->next != nullptr) {
      iter = iter->next;
      size++;
    }

    int offset = size - k % size;
    if (offset == size) return head;
    iter->next = head;
    while (offset--) {
      iter = iter->next;
    }
    head = iter->next;
    iter->next = nullptr;
    return head;
  }
};

ListNode *general_test_data(std::vector<int> s) {
  ListNode *head = nullptr, *tail = nullptr;
  for (unsigned i = 0; i < s.size(); ++i) {
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

  dumpList(
      s.rotateRight(general_test_data(std::vector<int>{1, 2, 3, 4, 5}), 2));
  dumpList(s.rotateRight(general_test_data(std::vector<int>{0, 1, 2}), 4));
  return 0;
}