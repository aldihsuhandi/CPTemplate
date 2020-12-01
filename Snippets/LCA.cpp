const int max_n = 1e6 + 1;
const int level = 20;
vector<int> vert[max_n];
int parent[max_n][level];
int depth[max_n];

void dfs(int curr = 1, int bef = 0)
{
    depth[curr] = depth[bef] + 1;
    parent[curr][0] = bef;
    for(int i = 0;i < (int)vert[curr].size();++i){
        if(vert[curr][i] != bef)
            dfs(vert[curr][i], curr);
    }
}

void pre(int n)
{
    for(int i = 1;i < level;++i){
        for(int node = 1;node <= n;++node){
            if(parent[node][i - 1] != -1)
                parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
}

int lca(int u, int v)
{
    if(depth[v] < depth[u])
        swap(u, v);
    int diff = depth[v] - depth[u];
    for(int i = 0;i < level;++i){
        if((diff >> i) & 1)
            v = parent[v][i];
    }
    
    if(u == v)
        return u;

    for(int i = level - 1;i >= 0;--i){
        if(parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}
