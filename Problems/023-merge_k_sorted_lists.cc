#include <iostream>
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
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }
    if (list1->val < list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* h = nullptr;
    for (auto list : lists) {
      h = mergeTwoLists(h, list);
    }
    return h;
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
  vector<ListNode*> case1{createNode(std::vector<int>{1,4,5}), createNode(std::vector<int>{1,4,5}),createNode(std::vector<int>{2,6})};
  dumpList(s.mergeKLists(case1));

  return 0;
}