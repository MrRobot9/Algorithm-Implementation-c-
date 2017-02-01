#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<signed long> t;
int n;
int sol = 1;

void printsol()
{
	int i,j;
	char crossboard[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			crossboard[i][j]='_';
		}
	}
	for(i=0;i<n;i++)
	{
			crossboard[i][t[i]]='q';
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c ",crossboard[i][j]);
		}
		printf("\n");
	}  
}
int empty(int i)
{
	int j=0;
	while((t[i]!=t[j])&&(abs(t[i]-t[j])!=(i-j))&&j<n)j++;
	return i==j?1:0;
}

void queens(int i)
{
	for(t[i] = 0;t[i]<n;t[i]++)
	{
		if(empty(i))
		{
			if(i==n-1){
				printsol();
				printf("\n solution %d\n",sol++);
			}
			else
			queens(i+1);
		}
	}
}

	

int main()
{
	cin >> n;
    t.reserve(n);
    fill(t.begin(), t.end(), -1);
	queens(0);
	return 0;
}