#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 250000
using namespace std;
typedef long long ll;


void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}

ll n,a[MAXN],mx,sum; 

// Function to return gcd of a and b 
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array of 
// numbers 
ll findGCD(ll arr[]) 
{ 
    ll result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        if(arr[i] != 0)
            result = gcd(arr[i], result); 
  
        if(result == 1) 
           return 1; 
    } 
    return result; 
}

int main()
{
	setIO();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx,a[i]);
    }

    for(int i = 0; i < n; i++)
    {
        a[i] = mx - a[i];
        sum += a[i];
    }

    ll z = findGCD(a);
    cout << (sum / z) << " " << z << endl;
    return 0;
}