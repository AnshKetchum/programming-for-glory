#include <bits/stdc++.h>
using namespace std;
#define MAX_NUMBERS 55000
typedef long long ll;

ll n,numbers[MAX_NUMBERS],lazy[MAX_NUMBERS],segTree[MAX_NUMBERS];

void updateRange(int l, int r, int node, int ql, int qr, int updateVal)
{
    int child1 = node * 2 + 1, child2 = node * 2 + 2;
    if(l > r)
        return;

    if(lazy[node]) //Lazy Prop
    {
        segTree[node] += lazy[node];
        if(l != r)
        {
            lazy[child1] += lazy[node];
            lazy[child2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(ql > r || qr < l) //Case No Overlap
    {
//        cout << "NO Overlap: [" << l << ","  << r << "], Output: " << 0 << endl; 
        return;
    }

    //Case Total Overlap
    if(ql <= l && qr >= r)
    {
        segTree[node] += (r - l + 1) * (updateVal);
        if(l != r)
        {
            lazy[child1] += updateVal;
            lazy[child2] += updateVal;
        }
//        cout << "Total Overlap: [" << l << ","  << r << "], Output: " << segTree[node] << endl; 
        return;
    }

    int mid = (l + r) /  2;

//    cout << "Partial Overlap: [" << l << ","  << r << "], Trying Children: " << child1 << " and " << child2 << endl; 
    updateRange(l,mid,child1,ql,qr,updateVal);
    updateRange(mid + 1,r,child2,ql,qr,updateVal);
    segTree[node] = segTree[child1] + segTree[child2];
//    cout << "Partial Overlap: [" << l << ","  << r << "], Output: " << segTree[node] << endl; 

}

int getQuery(int l, int r, int node, int a, int b)
{
    int child1 = node * 2 + 1, child2 = node * 2 + 2;

    if(a <= l && b >= r)        
        return segTree[node];
    if(a > r || b < l)
        return 0;

    int mid = (l + r) / 2;
    int ret = getQuery(l,mid,child1,a,b) + 
        getQuery(mid + 1, r,child2,a,b);

    return ret; 
}


void buildSegTree(int l, int r, int node)
{
    int child1 = node * 2 + 1, child2 = node * 2 + 2;
    
    if(l == r)
    {
        segTree[node] = numbers[l];
        return;
    }

    int mid = (l + r) / 2;
    buildSegTree(l,mid,child1);
    buildSegTree(mid + 1,r,child2);
    segTree[node] = segTree[child1] + segTree[child2];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << "Enter the numbers you would like to sum (< 45,000)" << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    buildSegTree(0, n - 1,0);

    cout << "Processing Requests. Type \'x\' to stop.\nU -> Update\nQ -> Query " << endl;
    char request = ' ';
    while (request != 'x')
    {
        cin >> request;
        if(request == 'U' || request == 'Q')
        {
            int a,b,update;
            cin >> a >> b;
            a--; b--;
            if(request == 'U')
                cin >> update;
            updateRange(0, n - 1,0,a,b,(request == 'U' ? update : 0));
            cout << "Answer: "  << getQuery(0, n - 1,0,a,b) << endl; 
       }

    }
    
    cout << "Program Terminated" << endl;
    return 0;
}