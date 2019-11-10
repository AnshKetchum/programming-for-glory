<<<<<<< HEAD
/*****
ID: INSERT_NAME_HERE
LANG: C++
PROG: fact4
**/
=======

>>>>>>> master
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

/*
Number Theory solution to problem:

Let D(N) be last digit to of a number N's factorial.

We can recurse based on the parity of the ten's digit 
NOTE that floor division is implied

    Case Even:
        D(N) = 6 * D(N / 5) * D(N % 10)

    Case Odd:
        D(N) = 4 * D(N / 5) * D(N % 10)
 
*/


int last[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int findLastDigit(int N)
{

    if(N < 10) //Don't waste time recomputing answers
        return last[N];
    
    int tens = (N / 10) % 10;
    return (tens % 2  == 0 ? 6: 4) * findLastDigit(N / 5) * findLastDigit(N % 10);
}


int n; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream cin("fact4.in"); 
    ofstream cout("fact4.out");

    cin >> n;

    cout << findLastDigit(n) % 10 << endl;//Number Theory Approach
    return 0;
}
