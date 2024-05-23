
#include <iostream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
  }
};

void dumpList(ListNode* p) {
  while (p != nullptr) {
    std::cout << p->val << "->";
    p = p->next;
  }
  std::cout << std::endl;
}

ListNode* createNode(std::vector<int> datas) {
  ListNode* head = nullptr;
  ListNode* p = nullptr;
  for (auto data : datas) {
    if (head == nullptr) {
      p = head = new ListNode(data);
    } else {
      p->next = new ListNode(data);
      p = p->next;
    }
  }
  return head;
}

int main(int argc, char* argv[]) {
  Solution s;
  dumpList(s.swapPairs(createNode(std::vector<int>{1, 2, 3, 4})));
  dumpList(s.swapPairs(createNode(std::vector<int>{})));
  dumpList(s.swapPairs(createNode(std::vector<int>{1})));
  return 0;
}