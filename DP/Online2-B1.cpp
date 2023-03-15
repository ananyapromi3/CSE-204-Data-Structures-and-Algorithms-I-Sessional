#include<bits/stdc++.h>
using namespace std;
int kthNear(int *dist, int p, int k)
{
    for(int i=p-1;i>=0;i--)
    {
        if(dist[p]-dist[i]>=k)
        {
            return i;
        }
    }
    return -1;
}
int maxProf(int *dist, int *pro, int m, int k)
{
    int *dp;
    dp = new int(m);
    dp[0] = pro[0];
    for(int i=1;i<m;i++)
    {
        if(kthNear(dist, i, k)>=0)
        {
            dp[i] = max(dp[i-1], (dp[kthNear(dist, i, k)] + pro[i]));
        }
        else
        {
            dp[i] = max(dp[i-1], pro[i]);
        }
    }
//    for(int  i=0; i<m;i++)
//    {
//        cout << dp[i]<<" ";
//    }
//    cout<<"\n";
    return dp[m-1];
}
int main()
{
    int m, k;
    cin>>m>>k;
    int *dist, *pro;
    dist = new int(m);
    pro = new int(m);
    for(int i=0;i<m;i++)
    {
        cin>>dist[i]>>pro[i];
    }
    cout << maxProf(dist, pro, m, k)<<"\n";
    return 0;
}

//5 3
//1 1
//2 3
//4 6
//6 5
//9 1

//5 3
//1 3
//2 3
//4 6
//6 5
//9 1
