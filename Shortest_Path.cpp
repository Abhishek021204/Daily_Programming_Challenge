#include <ios>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int shortestPath(int V, int start, int end,
                 const vector<vector<int>> &edgeList) {
  if (start == end)
    return 0;
  vector<vector<int>> AL(V);
  for (auto &e : edgeList) {
    AL[e[0]].push_back(e[1]);
    AL[e[1]].push_back(e[0]);
  }
  queue<int> BFS;
  vector<bool> visited(V, false);
  visited[start] = true;
  BFS.push(start);
  int result = 0;
  while (!BFS.empty()) {
    int currLevel = BFS.size();
    result++;
    for (int i = 0; i < currLevel; i++) {
      int curr = BFS.front();
      BFS.pop();
      for (int adj : AL[curr]) {
        if (adj == end)
          return result;
        if (visited[adj])
          continue;
        visited[adj] = true;
        BFS.push(adj);
      }
    }
  }
  return -1;
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
  int V = 5, start = 0, end = 4;
  string input = "[[0, 1], [0, 2], [1, 3], [2, 3], [3, 4]]";
  cout << shortestPath(V, start, end, stringtoEdgeList(input));
}
