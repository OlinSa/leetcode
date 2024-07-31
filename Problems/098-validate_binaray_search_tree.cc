
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
extern void DumpTreeNode(TreeNode *node);

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return isValidBSTInternal(root, INT64_MIN, INT64_MAX);
  }
  bool isValidBSTInternal(TreeNode *node, long long min, long long max) {
    if (node == nullptr) return true;
    if (node->val <= min || node->val >= max) return false;
    return isValidBSTInternal(node->left, min, node->val) &&
           isValidBSTInternal(node->right, node->val, max);
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
  std::cout << s.isValidBST(
                   general_test_data_prorder(std::vector<int>{2, 1, 3}))
            << std::endl;
  std::cout << s.isValidBST(general_test_data_prorder(
                   std::vector<int>{5, 1, 4, -1, -1, 3, 6}))
            << std::endl;
  std::cout << s.isValidBST(general_test_data_prorder(
                   std::vector<int>{5, 4, 6, -1, -1, 3, 7}))
            << std::endl;
  std::cout << s.isValidBST(general_test_data_prorder(
                   std::vector<int>{5, 4, 6, -1, -1, 3, 7}))
            << std::endl;
  std::cout << s.isValidBST(
                   general_test_data_prorder(std::vector<int>{2147483647}))
            << std::endl;

  return 0;
}