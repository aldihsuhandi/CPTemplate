vector<int> S, visited;
int numSCC;
void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    for(int j = 0;j < (int)AdjList[u].size();++j){
        int v = AdjList[u][j];
        if (dfs_num[v] == -1)
            tarjanSCC(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u])
    {
        printf("SCC %d:", ++numSCC);
        while(1){
            int v = S.back(); 
            S.pop_back();
            visited[v] = 0;
            printf(" %d", v);
            if(u == v) 
                break;
        }
        printf("\n"); 
    }
}

int main() 
{
    dfs_num.assign(V, -1);
    dfs_low.assign(V, 0);
    visited.assign(V, 0);
    dfsNumberCounter = numSCC = 0;
    for (int i = 0; i < V; i++){
        if (dfs_num[i] == -1)
            tarjanSCC(i); 
    }
}
