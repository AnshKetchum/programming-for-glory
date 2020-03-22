#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#define MAXN 1150000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

void setIO() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
}


ll n,a[MAXN],minSum,maxSum,ans;
int minLeft[MAXN],minRight[MAXN],maxLeft[MAXN], maxRight[MAXN];
stack <ll> st;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];


    minLeft[0] = 0;
    st.push(0);
    for (int i = 1; i < n; i++) 
    {
        while ((st.size() > 0) && (a[st.top()] > a[i])) 
            st.pop();
        if (st.size() > 0) 
            minLeft[i] = st.top() + 1;
        else 
            minLeft[i] = 0;
        st.push(i);
    }

    while(!st.empty()) st.pop();
    minRight[n - 1] = n - 1;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--) 
    {
        while ((st.size() > 0) && (a[st.top()] >= a[i])) 
            st.pop();
        if (st.size() > 0) 
            minRight[i] = st.top() - 1;
         else 
            minRight[i] = n - 1;
        
        st.push(i);
    }

    while(!st.empty()) st.pop();
    maxLeft[0] = 0;
    st.push(0);
    for (int i = 1; i < n; i++) 
    {
        while ((st.size() > 0) && (a[st.top()] < a[i])) 
            st.pop();
        if (st.size() > 0) 
            maxLeft[i] = st.top() + 1;
         else 
            maxLeft[i] = 0;
        st.push(i);
    }

    while(!st.empty()) st.pop();
    maxRight[n - 1] = n - 1;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--) 
    {
        while ((st.size() > 0) && (a[st.top()] <= a[i])) st.pop();
        if (st.size() > 0) {
            maxRight[i] = st.top() - 1;
        } else {
            maxRight[i] = n - 1;
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) 
    {
        ll rng = (ll) (i - minLeft[i] + 1) * (minRight[i] - i + 1);
        minSum += rng * a[i];

        rng = (ll) (i - maxLeft[i] + 1) * (maxRight[i] - i + 1);
        maxSum += rng * a[i];
    }

    cout << (maxSum - minSum) << endl;
    return 0;
}
//Where I got idea from: https://github.com/wolfib/competitive-coding-solutions/blob/master/codeforces/817d-imbalanced-array/Main.java
