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
  int minDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    int min_depth = INT32_MAX;
    preOrder(root, 1, min_depth);

    return min_depth;
  }

  void preOrder(TreeNode *node, int depth, int &min_depth) {
    if (node == nullptr) {
      return;
    }
    if (node->left == nullptr && node->right == nullptr) {
      min_depth = std::min(depth, min_depth);
      return;
    }
    preOrder(node->left, depth + 1, min_depth);
    preOrder(node->right, depth + 1, min_depth);
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

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.minDepth(general_test_data_prorder(
                   std::vector<int>{3, 9, 20, -1, -1, 15, 7}))
            << std::endl;
  std::cout << s.minDepth(general_test_data_prorder(
                   std::vector<int>{2, -1, 3, -1, 4, -1, 5, -1, 6}))
            << std::endl;
  std::cout << s.minDepth(general_test_data_prorder(std::vector<int>{nullptr}))
            << std::endl;
  return 0;
}