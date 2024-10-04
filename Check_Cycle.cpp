#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

bool checkCycle(int V, int E, const vector<vector<int>> &edgeList) {
  vector<int> indegree(V, 0);
  vector<vector<int>> AL(V);
  for (auto &e : edgeList) {
    indegree[e[0]]++, indegree[e[1]]++;
    AL[e[0]].push_back(e[1]);
    AL[e[1]].push_back(e[0]);
  }
  queue<int> isolated;
  for (int i = 0; i < V; i++)
    if (indegree[i] <= 1)
      isolated.push(i);
  while (!isolated.empty()) {
    int curr = isolated.front();
    isolated.pop();
    V--;
    for (int adj : AL[curr]) {
      indegree[adj]--;
      if (indegree[adj] == 1)
        isolated.push(adj);
    }
  }
  return V != 0;
}

vector<vector<int>> stringtoEdgeList(string &input) {
  vector<vector<int>> result;
  stringstream ss(input);
  char discard;
  ss >> discard;
  while (ss.peek() != ']') {
    vector<int> inner;
    int num;
    ss >> discard;
    while (ss.peek() != ']') {
      if (ss >> num)
        inner.push_back(num);
      if (ss.peek() == ',')
        ss >> discard;
    }
    ss >> discard;
    if (ss.peek() == ',')
      ss >> discard;
    result.push_back(inner);
  }
  return result;
}
int main() {
  int V = 5, E = 5;
  string input = " [[0, 1], [1, 2], [2, 3], [3, 4], [4, 0]]";
  boolalpha(cout);
  cout << checkCycle(V, E, stringtoEdgeList(input));
}
