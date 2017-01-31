#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int count = 0;
 int n;

bool isSafe(vector<signed long>& q, int col) {
  for (int i = 0; i < col; i++) {
    if ((q[i] == q[col]) || (abs(q[col] - q[i]) == (col - i))) {
      return false;
    }
  }
  return true;
}

void Print(const vector<signed long>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

void clearCell(int c,vector<signed long>& q){

for(int i = c; i < q.size(); i++){
	q[i] = -1;
}
}

 void solveQueen(vector<signed long>& q,int c,int n){
 for(int i = 0 ; i< n;i++){
	if(isSafe(q,i)){
        q[c] = i; 
	 if (c==n) { 
	 	Print(q);
	 }else{ 
	 	solveQueen(q,c+1,n); 
	 }
	}
}
}


int main() {
 
  cout << "Enter the number of Queens for the solution: ";
  cin >> n;
  cout << endl;
  vector<signed long> q(n);
  int c = 0;

  solveQueen(q,c,n);
}