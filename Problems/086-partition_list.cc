
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
  ListNode *partition(ListNode *head, int x) {
    if (head == nullptr) return head;
    ListNode *small_head = new ListNode(0, head);
    ListNode *large_head = new ListNode(0, head);

    ListNode *small = small_head, *large = large_head;

    while (head != nullptr) {
      if (head->val < x) {
        small->next = head;
        small = small->next;
      } else {
        large->next = head;
        large = large->next;
      }
      head = head->next;
    }
    large->next = nullptr;
    small->next = large_head->next;

    return small_head->next;
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
  dumpList(
      s.partition(general_test_data(std::vector<int>{1, 4, 3, 2, 5, 2}), 3));
  dumpList(s.partition(general_test_data(std::vector<int>{2, 1}), 2));
  return 0;
}