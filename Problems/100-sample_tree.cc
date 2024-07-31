#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

TreeNode *general_test_data_prorder(std::vector<int> list) {
  if (list.empty() || list[0] == -1)  // Edge case: empty list or root is null
    return nullptr;

  TreeNode *root = new TreeNode(list[0]);
  std::queue<TreeNode *> q;
  q.push(root);
  size_t index = 1;  // Start from the second element in the list

  while (!q.empty() && index < list.size()) {
    TreeNode *current = q.front();
    q.pop();

    // Create left child
    if (list[index] != -1) {
      current->left = new TreeNode(list[index]);
      q.push(current->left);
    }
    index++;

    // Create right child
    if (index < list.size() && list[index] != -1) {
      current->right = new TreeNode(list[index]);
      q.push(current->right);
    }
    index++;
  }

  return root;
}

void DumpTreeNode(TreeNode *node) {
  if (node == nullptr) {
    std::cout << "null->";
    return;
  }
  std::cout << node->val << "->";
  DumpTreeNode(node->left);
  DumpTreeNode(node->right);
}
void DumpTreeNodes(vector<TreeNode *> nodes) {
  std::cout << "[";
  for (auto it1 : nodes) {
    std::cout << "[";
    DumpTreeNode(it1);
    std::cout << "]";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.isSameTree(
                   general_test_data_prorder(std::vector<int>{1, 2, 3}),
                   general_test_data_prorder(std::vector<int>{1, 2, 3}))
            << std::endl;
  std::cout << s.isSameTree(
                   general_test_data_prorder(std::vector<int>{1, 2}),
                   general_test_data_prorder(std::vector<int>{1, -1, 2}))
            << std::endl;
  return 0;
}