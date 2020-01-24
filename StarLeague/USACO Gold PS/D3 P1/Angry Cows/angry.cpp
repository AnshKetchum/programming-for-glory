#include <bits/stdc++.h>
using namespace std;
#define MAXN 55000
#define INF 100000000.0
int N,pos[MAXN];
double ans = INF;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> pos[i];
    sort(pos, pos + N);

    int beg=0; int rad = 0; int end = N-1; int rad1 = 0;

    double best = INF;
    while(true){
        double val = max((double)max(rad,rad1)+1,(double)(pos[end] - pos[beg]) / 2);
        if (val<best){best=val;}
        int pot = max(rad+1,pos[beg + 1] - pos[beg]);
        int pot1 = max(rad1+1, pos[end] - pos[end - 1]);
        if(pot<pot1)
        {
            rad=pot; int index = beg;
            while(index<N-1 && pos[beg] + pot >= pos[index + 1])
                index++; 
            beg=index;
        } 
        else
        {
            rad1=pot1; int index = end;
            while(index>0 && pos[end] - pot1 <= pos[index - 1])
                index--;
            end=index;
        }
        if(end<=beg)
        {
            best= min(best,(double)max(rad,rad1));
            break;
        }
    }

    printf("%.1f\n",best);
    return 0;
}