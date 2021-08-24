#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int n, m;
bool vis[MAX];
int parent[MAX];
int dist[MAX];
int lvl[MAX];
int tmp[MAX][3];
vector<int> tree[MAX];

void dfs(int node){
    vis[node]=true;
    for(int i=0; i<tree[node].size(); i++){
        int next=tree[node][i];
        if(!vis[next]){
            parent[next]=node;
            lvl[next]=lvl[node]+1;
            dfs(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n-1; i++){
        int node1, node2, dd;
        cin >> node1 >> node2 >> dd;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
        tmp[i][0]=node1;
        tmp[i][1]=node2;
        tmp[i][2]=dd;
    }
    lvl[1]=1;
    dfs(1);

    dist[1]=0;
    for(int i=0; i<n-1; i++){
        if(parent[tmp[i][0]]==tmp[i][1]){
            dist[tmp[i][0]]=tmp[i][2];
        }
        else{
            dist[tmp[i][1]]=tmp[i][2];
        }
    }
    
    for(int i=0; i<m; i++){
        int node1, node2, sum=0;
        cin >> node1 >> node2;
        while(lvl[node1]!=lvl[node2]){
            if(lvl[node1]>lvl[node2]){
                sum+=dist[node1];
                node1=parent[node1];
            }
            else{
                sum+=dist[node2];
                node2=parent[node2];
            }
        }
        while(node1!=node2){
            sum+=dist[node1];
            sum+=dist[node2];
            node1=parent[node1];
            node2=parent[node2];
        }
        cout << sum << "\n";
    }

    return 0;
}