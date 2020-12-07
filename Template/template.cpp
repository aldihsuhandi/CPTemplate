#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

template<class T> using pqueue = priority_queue<T>;
template<class T> using rpqueue = priority_queue<T, vector<T>, greater<T> >;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

ll power(ll a, ll b);
int gcd(int a, int b);
void fileopen();
const int INF = INT_MAX;

void solve()
{
    ;
}

int main()
{
    // fileopen();

    int t = 1;
    // scanf("%d", &t);
    for(int tc = 1; tc <= t;++tc){
        // printf("Case #%d: ", tc);
        solve();
    }
}

void fileopen()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

ll power(ll a, ll b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    if(b % 2 == 0)
    {
        ll ret = power(a, b / 2);
        return ret * ret;
    }
    return power(a, b - 1) * a;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
