#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode head;
    ListNode* h = &head;
    ListNode *p1 = list1, *p2 = list2;
    while (p1 || p2) {
      if (p1 == nullptr) {
        h->next = p2;
        break;
      } else if (p2 == nullptr) {
        h->next = p1;
        break;
      }
      if (p1->val < p2->val) {
        h->next = p1;
        h = p1;
        p1 = p1->next;
      } else {
        h->next = p2;
        h = p2;
        p2 = p2->next;
      }
    }
    return head.next;
  }
};

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

void dumpList(ListNode* p) {
  while (p != nullptr) {
    std::cout << p->val << "->";
    p = p->next;
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  dumpList(s.mergeTwoLists(createNode(std::vector<int>{1, 2, 4}),
                           createNode(std::vector<int>{1, 3, 4})));
  dumpList(s.mergeTwoLists(createNode(std::vector<int>{}),
                           createNode(std::vector<int>{})));
  dumpList(s.mergeTwoLists(createNode(std::vector<int>{}),
                           createNode(std::vector<int>{0})));
  return 0;
}