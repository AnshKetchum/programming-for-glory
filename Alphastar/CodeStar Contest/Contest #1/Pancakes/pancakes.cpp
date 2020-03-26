
//NOTE: NOTE MY CODE: I WAS TRYING TO ANALYZE how this genius's (nathan.r.wang) logic worked. (Source: https://www.hackerearth.com/challenges/competitive/CodeStar1/algorithm/pancakes-1/submission/32981860/)
#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000
 
int n, k, A[100000];
 
int st[400000];
void build(int p, int i, int j) {
    if (i == j) st[p] = A[i];
    else {
        build(p << 1, i, (i+j)/2);
        build((p << 1) + 1, (i+j)/2+1, j);
        st[p] = min(st[p << 1], st[(p << 1) + 1]);
    }
}
int qry(int p, int i, int j, int L, int R) {
    if (i > R || j < L) return INF;
    if (i >= L && j <= R) return st[p];
    return min(qry(p << 1, i, (i+j)/2, L, R), qry((p << 1) + 1, (i+j)/2+1, j, L, R));
}
 
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> A[i];
    build(1, 0, n-1);
    
    vector<int> removed;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int minNum = qry(1, 0, n-1, i, i+k);
        ans.push_back(minNum);
        while (A[i] != minNum) {
            removed.push_back(A[i++]);
            k--;
        }
    }
    vector<int> finalAns;
    sort(removed.begin(), removed.end());
    int j = 0;
    for (int i = 0; i < ans.size(); i++) {
        while (j < removed.size() && removed[j] < ans[i]) {
            finalAns.push_back(removed[j++]);
        }
        finalAns.push_back(ans[i]);
    }
    while (j < removed.size()) finalAns.push_back(removed[j++]);
    for (int i = 0; i < n; i++) {
        cout << finalAns[i] << " ";
    }
    cout << endl;
}