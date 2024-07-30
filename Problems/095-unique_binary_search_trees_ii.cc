
#include <algorithm>
#include <iostream>
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
  vector<TreeNode *> generateTrees(int n) { return generateTrees(1, n); }

  vector<TreeNode *> generateTrees(int start, int end) {
    if (start > end) {
      return {nullptr};
    }
    vector<TreeNode *> alltree;
    for (int i = start; i <= end; ++i) {
      vector<TreeNode *> lefttress = generateTrees(start, i - 1);
      vector<TreeNode *> righttrees = generateTrees(i + 1, end);

      for (auto &left : lefttress) {
        for (auto &right : righttrees) {
          TreeNode *cur = new TreeNode(i);
          cur->left = left;
          cur->right = right;
          alltree.push_back(cur);
        }
      }
    }
    return alltree;
  }
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

int main(int argc, char *argv[]) {
  Solution s;

  DumpTreeNodes(s.generateTrees(3));
  DumpTreeNodes(s.generateTrees(1));

  return 0;
}
