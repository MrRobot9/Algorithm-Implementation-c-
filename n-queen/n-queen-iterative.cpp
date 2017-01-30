#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<signed long> q, int col) {
  for (int i = 0; i < col; i++) {
    if ((q[i] == q[col]) || (abs(q[col] - q[i]) == (col - i))) {
      return false;
    }
  }
  return true;
}

void backtrack(int& col, int m, int n) {
  col--;

  if (col == -1) {
    cout << "There are " << m << " solutions of " << n << " queens problem."
         << endl;
    system("pause");
    exit(1);
  }
}

void Print(const vector<signed long>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cout << "Enter the number of Queens for the solution: ";
  cin >> n;
  cout << endl;
  vector<signed long> q(n);
  int c = 0, count = 0;

  bool isNewSet = false;

  while (1) {
    while (c < n) {
      if (!isNewSet) {
        q[c] = -1;
      }
      isNewSet = false;
      while (q[c] < n) {
        q[c]++;

        while (q[c] == n) {
          backtrack(c, count, n);
          q[c]++;
        }

        if (isSafe(q, c)) break;
      }
      c++;
    }
    Print(q);
    count++;

    backtrack(c, count, n);

    isNewSet = true;
  }
}
