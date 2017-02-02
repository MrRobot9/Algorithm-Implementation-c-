#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> size,value;
int s,n;





void knapSack(){


vector< vector<int> > DP(n + 1, vector<int>(s + 1, 0));

	for (int i = 1; i <= n; i++) { 
		for (int w = 1; w <= s; w++) { 
			if (size[i] > w) {
				DP[i][w] = DP[i - 1][w];
			} else {
				DP[i][w] = max(DP[i - 1][w], value[i] + DP[i - 1][w - size[i]]);
			}
		}
	}

cout << DP[n][s];


}


int main()
{

	cin >> s;
	cin >> n;
	size.push_back(-1);
    value.push_back(-1);

	int st, vt;
    for(int i = 0;i < n;i ++){
    	cin >> st >> vt;
    	size.push_back(st);
    	value.push_back(vt);
    }

    knapSack();
	return 0;
}