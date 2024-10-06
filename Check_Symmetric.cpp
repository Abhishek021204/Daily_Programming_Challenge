#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>

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

bool helper(TreeNode *left, TreeNode *right) {
  if (!left && !right)
    return true;
  if (!left || !right || left->val != right->val)
    return false;
  return helper(left->left, right->right) && helper(left->right, right->left);
}
bool checkSymmetry(TreeNode *root) {
  if (!root)
    return true;
  stack<TreeNode *> Left, Right;
  Left.push(root->left), Right.push(root->right);
  while (!Left.empty() || !Right.empty()) {
    TreeNode *leftNode = Left.top(), *rightNode = Right.top();
    Left.pop(), Right.pop();
    if (!leftNode && !rightNode)
      continue;
    if (!leftNode || !rightNode || leftNode->val != rightNode->val)
      return false;
    Left.push(leftNode->right), Left.push(leftNode->left);
    Right.push(rightNode->left), Right.push(rightNode->right);
  }
  return true;
}

TreeNode *generateTree(string &input) {
  if (input.size() == 2)
    return nullptr;

  stringstream ss(input.substr(1, input.size() - 1));
  string s;
  getline(ss, s, ',');
  TreeNode *root = new TreeNode(stoi(s));
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);
  while (ss) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();
    if (getline(ss, s, ',') && none_of(s.begin(), s.end(), ::isalpha)) {
      int leftNumber = stoi(s);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }
    if (getline(ss, s, ',') && none_of(s.begin(), s.end(), ::isalpha)) {
      int rightNumber = stoi(s);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

int main() {
  string input = "[1, 2, 2, 3, 4, 4, 3]";
  boolalpha(cout);
  cout << checkSymmetry(generateTree(input));
}
