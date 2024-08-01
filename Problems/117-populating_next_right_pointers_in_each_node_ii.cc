#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) return root;
    std::queue<Node*> node_queue;
    node_queue.push(root);
    while (!node_queue.empty()) {
      int size = node_queue.size();

      for (int i = 0; i < size; ++i) {
        Node* node = node_queue.front();
        node_queue.pop();

        if (i < size - 1) {
          node->next = node_queue.front();
        }

        if (node->left) {
          node_queue.push(node->left);
        }
        if (node->right) {
          node_queue.push(node->right);
        }
      }
    }
    return root;
  }
};

Node* general_test_data_prorder(std::vector<int> list) {
  if (list.empty() || list[0] == -1)  // Edge case: empty list or root is null
    return nullptr;

  Node* root = new Node(list[0]);
  std::queue<Node*> q;
  q.push(root);
  size_t index = 1;  // Start from the second element in the list

  while (!q.empty() && index < list.size()) {
    Node* current = q.front();
    q.pop();

    // Create left child
    if (list[index] != -1) {
      current->left = new Node(list[index]);
      q.push(current->left);
    }
    index++;

    // Create right child
    if (index < list.size() && list[index] != -1) {
      current->right = new Node(list[index]);
      q.push(current->right);
    }
    index++;
  }

  return root;
}

void DumpNode(Node* node) {
  if (node == nullptr) {
    std::cout << "null->";
    return;
  }
  std::cout << node->val << "->";
  DumpNode(node->left);
  DumpNode(node->right);
}

int main(int argc, char* argv[]) {
  Solution s;
  DumpNode(s.connect(
      general_test_data_prorder(std::vector<int>{1, 2, 3, 4, 5, 6, 7})));
  DumpNode(s.connect(general_test_data_prorder(std::vector<int>{})));
  return 0;
}