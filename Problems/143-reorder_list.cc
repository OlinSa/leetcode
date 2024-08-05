
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
  void reorderList(ListNode *head) {
    std::vector<ListNode *> nodes;
    while (head) {
      nodes.push_back(head);
      head = head->next;
    }

    int i = 0, j = nodes.size() - 1;
    while (i < j) {
      nodes[i]->next = nodes[j];
      i++;
      if (i == j) break;
      nodes[j]->next = nodes[i];
      j--;
    }
    nodes[i]->next = nullptr;
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
  ListNode *list1 = general_test_data(std::vector<int>{1, 2, 3, 4});
  s.reorderList(list1);
  dumpList(list1);

  ListNode *list2 = general_test_data(std::vector<int>{1, 2, 3, 4, 5});
  s.reorderList(list2);
  dumpList(list2);
  return 0;
}