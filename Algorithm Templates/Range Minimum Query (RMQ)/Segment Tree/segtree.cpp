#include <bits/stdc++.h>
using namespace std;
#define UNWANTED LLONG_MAX
#define MAX_ARRAY_SIZE 400000 //Increase this based on your array size -> Should be 4 * array size
typedef long long ll;
ll segmentTree [MAX_ARRAY_SIZE],lazyProp[MAX_ARRAY_SIZE], values [MAX_ARRAY_SIZE],n,segtreeLen,a,b,updateVal;

void buildSegmentTree(ll lo, ll hi, ll cur)
{
    if(lo == hi) 
    {
      //  cout << "Range: [" << lo << "," << hi << "]" << " Value: " << values[lo] << endl; 
        segmentTree[cur] = values[lo];
        return;
    }

    ll mid = (lo + hi) / 2,child1 = cur * 2 + 1,child2 = cur * 2 + 2;
    buildSegmentTree(lo,mid,child1);
    buildSegmentTree(mid + 1,hi,child2);
    segmentTree[cur] = min(segmentTree[child1],segmentTree[child2]);
     //   cout << "Range: [" << lo << "," << hi << "]" << " Value: " << segmentTree[cur] << endl; 

}

ll getQuery(int l, int r, int cur)
{
    if(a <= l && b >= r)
    {
        cout << "Range Q: [" << l << "," << r << "]" << " Value: " << segmentTree[cur] << endl; 
        return segmentTree[cur];
    }
    if(a > r || b < l)
    {
        // cout << "Range: [" << l << "," << r << "]" << " Value: UNWANTED"  << endl; 
        return UNWANTED;
    }
    int mid = (l + r) / 2;

    int ret = min( getQuery(l,mid,2 * cur + 1),
        getQuery(mid + 1, r,2 * cur + 2)
    );

    //cout << "Range: [" << l << "," << r << "]" << " Value: " << ret  << endl; 
    return ret; 
}

void updateRange(int l, int r, int cur)
{
    ll child1 = cur * 2 + 1, child2 = cur * 2 + 2;

    if(l > r)
        return;

    if(lazyProp[cur])
    {
        segmentTree[cur] += lazyProp[cur];
        cout << "Range: [" << l << "," << r << "]" << " After adding Lazy: " << segmentTree[cur] << endl; 
        if(l != r) //Not a leaf node
        {
            lazyProp[child1] += lazyProp[cur];
            lazyProp[child2] += lazyProp[cur];
        }
        lazyProp[cur] = 0;
    }

    if(a > r || b < l) //No Overlap
        return;
    
    if(a <= l && b >= r)
    {   
        segmentTree[cur] += updateVal;
        if(l != r)
        {
            lazyProp[child1] += updateVal;
            lazyProp[child2] += updateVal;
        }
        return;
    }

    cout << "Range: [" << l << "," << r << "]" << " Partial Case: " << endl; 
    int mid = (l + r) / 2;
    updateRange(l,mid,child1);
    updateRange(mid + 1,r,child2);
    segmentTree[cur] = min(segmentTree[child1],segmentTree[child2]);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    segtreeLen = 4 * n;

    for(int i = 0; i < n; i++)
        cin >> values[i];

    buildSegmentTree(0, n - 1,0);



    cout << "Update Range: " << endl;
    cin >> a >> b >> updateVal;
    a--; b--;
    updateRange(0,n - 1,0);

    cout << endl << "Enter # of Queries" << endl;
    ll q; cin >> q;
    updateVal  = 0;

    for(int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--; b--;
        updateRange(0,n - 1,0);
        cout << "Answer: " << getQuery(0,n - 1,0) << endl;
    }

    cout << endl;
}