#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e4 + 5;
const int INF = 1e9;
int adj[maxN][maxN]; // -1 if there is no road
int dp[maxN][maxN];
int n;

int tsp(int pos = 0, int vis = 1)
{
    if(vis == ((1 << n) - 1))
        return adj[pos][0];
    if(dp[pos][vis] != INF)
        return dp[pos][vis];

    int res = INF;
    for(int i = 0;i < n;++i){
        if(i == pos || (vis & (1 << i)) || adj[pos][i] == -1)
            continue;
        int dist = adj[pos][i] + tsp(i, vis | (1 << i));
        res = min(res, dist);
    }
    return dp[pos][vis] = res;
}

int main()
{
    for(int i = 0;i < maxN;++i){
        for(int j = 0;j < maxN;++j)
            dp[i][j] = INF;
    }

    scanf("%d", &n);
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j)
            scanf("%d", &adj[i][j]);
    }

    int ans = tsp();
    printf("%d\n", ans);
}
