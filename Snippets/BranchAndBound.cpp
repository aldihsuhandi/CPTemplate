#include<bits/stdc++.h>
using namespace std;

const int max_n = 4;
vector<int> final_path(max_n + 1);
vector<bool> vis(max_n, false);
int res = INT_MAX;
int adj[max_n][max_n] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}}; 

void ctf(vector<int> &curr_path)
{
    for(int i = 0;i < max_n;++i)
        final_path[i] = curr_path[i];
    final_path[max_n] = curr_path[0];
}

int firstMin(int idx)
{
    int mini = INT_MAX;
    for(int i = 0;i < max_n;++i){
        if(adj[idx][i] < mini && idx != i)
            mini = adj[idx][i];
    }
    return mini;
}

int secondMin(int idx)
{
    int fi = INT_MAX, se = INT_MAX;
    for(int i = 0;i < max_n;++i){
        if(i == idx)
            continue;
        if(adj[idx][i] <= fi)
        {
            se = fi;
            fi = adj[idx][i];
        }
        else if(adj[idx][i] <= se && adj[idx][i] != fi)
            se = adj[idx][i];
    }
    return se;
}

void rec(vector<int> curr_path, int curr_bound, int curr_weight = 0, int level = 1)
{
    if(level == max_n)
    {
        if(adj[curr_path[level - 1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];
            if(curr_res < res)
            {
                ctf(curr_path);
                res = curr_res;
            }
        }
        return;
    }
    for(int i = 0;i < max_n;++i){
        if(adj[curr_path[level-1]][i] != 0 && vis[i] == false)
        {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level-1]][i];
            if(level == 1)
                curr_bound -= (firstMin(curr_path[level - 1]) + firstMin(i)) / 2; 
            else
                curr_bound -= (secondMin(curr_path[level - 1]) + firstMin(i)) / 2; 

            if(curr_bound + curr_weight < res)
            {
                curr_path[level] = i;
                vis[i] = true;
                rec(curr_path, curr_bound, curr_weight, level + 1);
            }

            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;
            vis.assign(vis.size(), false);
            for(int j = 0;j < level;++j)
                vis[curr_path[j]] = true;
        }
    }
}

void TSP()
{
    vector<int> curr_path(max_n + 1, -1);
    int curr_bound = 0;
    for(int i = 0;i < max_n;++i)
        curr_bound += firstMin(i) + secondMin(i);
    curr_bound = (curr_bound & 1) ? curr_bound / 2 + 1 : curr_bound / 2;
    vis[0] = true;
    curr_path[0] = 0;
    rec(curr_path, curr_bound);
}

int main()
{
    TSP();
    printf("%d\n", res);
    for(int it: final_path)
        printf("%d ", it);
    putchar('\n');
}
