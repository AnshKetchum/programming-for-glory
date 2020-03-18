//https://codeforces.com/group/bO58xxnmVp/contest/254442/problem/D
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 450
using namespace std;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

int n, a[MAXN];

void bubbleSort()
{
	int temp = 0; 
	bool keepOnGoing = false;
	while(!keepOnGoing)
	{
		keepOnGoing = true;
		for(int i = 0; i < n - 1; i++)
			if(a[i] > a[i + 1])
			{
				keepOnGoing = false;
				swap(a[i], a[i + 1]);
				cout << i + 1 << " " << i + 2 << endl;
			}
	}
}


int main()
{
	setIO();
    cin >> n;
    for(int i = 0; i < n; i++)
		cin >> a[i];

	bubbleSort();	
    return 0;
}