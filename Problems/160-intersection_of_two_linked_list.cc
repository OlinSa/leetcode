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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    /**
     *       a1 a2
     *           \
     *            c1  c2  c3  c4
     *           /
     *   b1 b2 b3
     *                    p2  p1
     *
     * 1. 同时遍历p1, p2. 计算长度差off1
     * 2. p2提前走off1, 至此len(p1) = len(p2)
     * 3. 同时遍历p1, p2. 同时比较p1,p2 遍历的节点
     */
    ListNode *p1 = headA, *p2 = headB;
    while (p1 != nullptr && p2 != nullptr) {
      p1 = p1->next;
      p2 = p2->next;
    }

    if (p1 == nullptr) {
      while (p2 != nullptr) {
        p2 = p2->next;
        headB = headB->next;
      }

    } else {
      while (p1 != nullptr) {
        p1 = p1->next;
        headA = headA->next;
      }
    }
    p1 = headA, p2 = headB;
    while (p1 != nullptr && p2 != nullptr) {
      if (p1 == p2) {
        return p1;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    return nullptr;
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
  ListNode *pub1 = general_test_data(std::vector<int>{8, 4, 5});
  ListNode *node1 = general_test_data(std::vector<int>{4, 1});
  ListNode *node2 = general_test_data(std::vector<int>{5, 6, 1});
  ListNode *tmp = node1;
  while (tmp != nullptr) {
    if (tmp->next == nullptr) {
      tmp->next = pub1;
      break;
    }
    tmp = tmp->next;
  }
  tmp = node2;
  while (tmp != nullptr) {
    if (tmp->next == nullptr) {
      tmp->next = pub1;
      break;
    }
    tmp = tmp->next;
  }

  ListNode *point1 = s.getIntersectionNode(node1, node2);
  std::cout << (point1 != nullptr ? std::to_string(point1->val) : " null ")
            << std::endl;
  return 0;
}