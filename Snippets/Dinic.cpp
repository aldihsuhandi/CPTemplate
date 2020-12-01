using ll = long long;
ll INF = 1e18;

struct Dinic
{
    struct Edge
    {
        int v;
        ll cap, flow;
        Edge(int _v, ll _cap)
        {
            v = _v;
            cap = _cap;
            flow = 0;
        }
    };

    int n;
    ll lim;
    vector<vector<int> > gr;
    vector<Edge> e;
    vector<int> idx, lv;

    bool has_path(int s, int t)
    {
        queue<int> q;
        q.push(s);
        lv.assign(n, -1);
        lv[s] = 0;
        while(q.empty() == false){
            int c = q.front();
            q.pop();
            if(c == t)
                break;
            for(auto i: gr[c]){
                ll cur_flow = e[i].cap - e[i].flow;
                if(lv[e[i].v] == -1 && cur_flow > 0 && cur_flow >= lim)
                {
                    lv[e[i].v] = lv[c] + 1;
                    q.push(e[i].v);
                }
            }
        }

        return lv[t] != -1;
    }

    ll get_flow(int s, int t, int left)
    {
        if(left == 0 || s == t)
            return left;
        while(idx[s] < (int)gr[s].size()){
            int i = gr[s][idx[s]];
            if(lv[e[i].v] == lv[s] + 1)
            {
                ll add = get_flow(e[i].v, t, min((ll)left, e[i].cap - e[i].flow));
                if(add)
                {
                    e[i].flow += add;
                    e[i ^ 1].flow -= add;
                    return add;
                }
            }
            ++idx[s];
        }

        return 0;
    }

    Dinic(int vert, bool scaling = 1)
    {
        n = vert;
        lim = scaling ? 1 << 30 : 1;
        gr = vector<vector<int> >(n, vector<int>());
    }

    ll get_max_flow(int s, int t)
    {
        ll res = 0;
        while(lim){
            while(has_path(s, t)){
                idx.assign(n, 0);
                while(ll add = get_flow(s, t, INF))
                    res += add;
            }
            lim >>= 1;
        }
        return res;
    }
};

