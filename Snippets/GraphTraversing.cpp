int n;
bool weighted;
vector<vector<pair<int, int> > > vert;

Graph(int nodes, bool _weighted = false)
{
    n = nodes;
    weighted = _weighted;
    vert.assign(n, vector<pair<int, int> >());
}

void addEdge(int u, int v, int w = 1, bool bidirectional = false)
{
    vert[u].push_back({v, w});
    if(bidirectional)
        vert[v].push_back({u, w});
}

void printAllNodes()
{
    for(int i = 0;i < n;++i){
        printf("Node %d:\n", i);
        for(pair<int, int> it: vert[i]){
            if(weighted)
                printf("Node %d: %d\n", it.first, it.second);
            else 
                printf("%d ", it.first);
        }
        if(!weighted)
            putchar('\n');
    }
}

vector<bool> DFS(int start = 0)
{
    vector<bool> vis(n, false);
    stack<int> st;
    vis[start] = 1;
    st.push(start);
    while(st.empty() == false){
        int from, to;
        from = st.top();
        st.pop();
        for(pair<int, int> it: vert[from]){
            to = it.second;
            if(vis[to] == false)
            {
                vis[to] = true;
                st.push(to);
            }
        }
    }

    return vis;
}

vector<int> BFS(int start = 0)
{
    vector<int> dist(n, -1);
    queue<pair<int, int> > q;
    dist[start] = 0;
    q.push({start, 0});
    while(q.empty() == false){
        pair<int, int> from;
        from = q.front();
        q.pop();
        for(pair<int, int> to: vert[from.first]){
            if(dist[to.first] == -1)
            {
                dist[to.first] = dist[from.first] + to.second;
                q.push(to);
            }
        }
    }

    return dist;
}

vector<int> Dijkstra(int start = 0)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    pq.push({0, start});
    dist[start] = 0;
    while(pq.empty() == false){
        pair<int, int> from;
        from = pq.top();
        pq.pop();
        for(pair<int, int> to: vert[from.second]){
            if(from.first + to.second < dist[to.first])
            {
                dist[to.first] = from.first + to.second;
                pq.push({from.first + to.second, to.first});
            }
        }
    }
    return dist;
}
