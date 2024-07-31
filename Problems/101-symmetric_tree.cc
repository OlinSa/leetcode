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

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;
    return isSample(root->left, root->right);
  }
  bool isSample(TreeNode *p1, TreeNode *p2) {
    if (p1 == nullptr && p2 == nullptr) return true;
    if (p1 == nullptr || p2 == nullptr) return false;
    if (p1->val != p2->val) return false;
    return isSample(p1->left, p2->right) && isSample(p1->right, p2->left);
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
  std::cout << s.isSymmetric(general_test_data_prorder(
                   std::vector<int>{1, 2, 2, 3, 4, 4, 3}))
            << std::endl;
  std::cout << s.isSymmetric(general_test_data_prorder(
                   std::vector<int>{1, 2, 2, -1, 3, -1, 3}))
            << std::endl;
}