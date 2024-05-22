#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* h = head;
    ListNode* p = head;
    while (n-- > 0) {
      h = h->next;
    }
    if (!h) return head->next;
    while (h->next != nullptr) {
      h = h->next;
      p = p->next;
    }
    std::cout << p->val << "->>>>>>";
    p->next = p->next->next;
    return head;
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
  dumpList(s.removeNthFromEnd(createNode(vector<int>{1, 2, 3, 4, 5}), 2));
  dumpList(s.removeNthFromEnd(createNode(vector<int>{1}), 1));
  dumpList(s.removeNthFromEnd(createNode(vector<int>{1, 2}), 1));
  dumpList(s.removeNthFromEnd(createNode(vector<int>{1, 2}), 2));
  return 0;
}