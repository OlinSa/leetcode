
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    ListNode *fast = head->next, *slow = head;
    while (slow != fast) {
      if (fast == nullptr || fast->next == nullptr) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;
    }

    return true;
  }
};

ListNode *general_test_data(std::vector<int> s, int pos) {
  ListNode *head = nullptr, *tail = nullptr;
  ListNode *cycle_point = nullptr;
  for (int i = 0; i < s.size(); ++i) {
    if (head == nullptr) {
      head = tail = new ListNode(s[i]);
    } else {
      tail->next = new ListNode(s[i]);
      tail = tail->next;
    }
    if (i == pos) {
      cycle_point = tail;
    }
  }
  tail->next = cycle_point;
  return head;
}

int main(int argc, char *argv[]) {
  Solution s;
  // std::cout << s.hasCycle(general_test_data(std::vector<int>{3, 2, 0, -4},
  // 1))
  //           << std::endl;
  // std::cout << s.hasCycle(general_test_data(std::vector<int>{1, 2}, 0))
  //           << std::endl;
  // std::cout << s.hasCycle(general_test_data(std::vector<int>{1}, -1))
  //           << std::endl;
  std::cout << s.hasCycle(general_test_data(std::vector<int>{1, 2}, -1))
            << std::endl;
  return 0;
}