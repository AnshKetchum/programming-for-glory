//https://codeforces.com/contest/1216/problem/E1
#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
using namespace std;
#define x first
#define y second
typedef pair<int,int> pii;

void setIO() //Borrowed from USACO Legend Mr. Benjamin Qi (Benq)
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);
}


pii whitesht[2], bs1[2],bs2[2],nr1[2],nr2[2];

bool covers(pii coords[2], pii whitesht[2])
{
    return (coords[0].x <= whitesht[0].x && coords[1].x >= whitesht[1].x && coords[0].y <= whitesht[0].y && coords[1].y >= whitesht[1].y);
}

int main()
{
	setIO();
    cin >> whitesht[0].x >> whitesht[0].y >> whitesht[1].x >> whitesht[1].y; 
    cin >> bs1[0].x >> bs1[0].y >> bs1[1].x >> bs1[1].y; 
    cin >> bs2[0].x >> bs2[0].y >> bs2[1].x >> bs2[1].y; 

    if(covers(bs1,whitesht) || covers(bs2,whitesht))
        cout << "NO" << endl;
    else
    {
        pii xrange = pii(bs1[0].x,bs1[1].x);
        if( (xrange.first <= bs2[0].x && xrange.second >= bs2[0].x) || (xrange.first <= bs2[1].x && xrange.second >= bs2[1].x))
        {
            xrange.first = min(xrange.first, bs2[0].x);
            xrange.second = max(xrange.second, bs2[1].x);
        }

        pii yrange = pii(bs1[0].y,bs1[1].y);
        if( (yrange.first <= bs2[0].y && yrange.second >= bs2[0].y) || (yrange.first <= bs2[1].y && yrange.second >= bs2[1].y))
        {
            yrange.first = min(yrange.first, bs2[0].y);
            yrange.second = max(yrange.second, bs2[1].y);
        }

        pii nrect[2]; 
        nrect[0].x = xrange.first;
        nrect[1].x = xrange.second;
        nrect[0].y = yrange.first;
        nrect[1].y = yrange.second;

        cout << nrect[0].x << " " << nrect[0].y << " " << nrect[1].x << " " << nrect[1].y << endl;
        if(covers(nrect,whitesht))
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;
    }
    
    return 0;
}