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
  void flatten(TreeNode *root) {
    if (root == nullptr) return;
    std::queue<TreeNode *> preorder_queue;
    preOrder(root, preorder_queue);
    if (!preorder_queue.empty()) preorder_queue.pop();
    TreeNode *cur = root;
    while (!preorder_queue.empty()) {
      cur->left = nullptr;
      cur->right = preorder_queue.front();
      cur = cur->right;
      preorder_queue.pop();
    }
  }
  void preOrder(TreeNode *node, std::queue<TreeNode *> &preorder_queue) {
    if (node == nullptr) {
      return;
    }
    preorder_queue.push(node);
    preOrder(node->left, preorder_queue);
    preOrder(node->right, preorder_queue);
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

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *root1 =
      general_test_data_prorder(std::vector<int>{1, 2, 5, 3, 4, -1, 6});
  s.flatten(root1);
  DumpTreeNode(root1);
  // TreeNode *root2 = general_test_data_prorder(std::vector<int>{});
  // s.flatten(root2);
  // DumpTreeNode(root2);
  // TreeNode *root3 = general_test_data_prorder(std::vector<int>{0});
  // s.flatten(root3);
  // DumpTreeNode(root3);
  return 0;
}