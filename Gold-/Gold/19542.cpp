#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int n, s, d;
bool vis[MAX];
int parent[MAX];
vector<int> tree[MAX];
queue<int> q;

void bfs(){
    while(!q.empty()){
    	int cur=q.front();
    	q.pop();
    	for(int i=0; i<tree[cur].size(); i++){
        	int next=tree[cur][i];
        	if(!vis[next]){
        		vis[next]=true;
            	q.push(next);
            	parent[next]=cur;
        	}
    	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, tmp, cnt=0;
    pair<int,int> buf1;

    cin >> n >> s >> d;
    for(i=0; i<n-1; i++){
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
	
	q.push(s);
	vis[s]=true;
    bfs();
    
    priority_queue <pair<int,int>> pq;
    for(i=1; i<n+1; i++){
        cnt=0; tmp=i;
        while(tmp!=s){
            tmp=parent[tmp];
            cnt++;
        }
        pq.push({cnt,i});
    }

    memset(vis, 0, sizeof(vis));
    tmp=pq.size();
    cnt=0;
    for(i=0; i<tmp; i++){
        buf1=pq.top();
        pq.pop();
        for(j=0; j<d; j++){
            if(buf1.second==s) break;
            if(vis[buf1.second]!=false) break;
            buf1.second=parent[buf1.second];
            buf1.first--;
        }
        while(buf1.second!=s && vis[buf1.second]==false){
            vis[buf1.second]=true;
            buf1.second=parent[buf1.second];
            buf1.first--;
        }
        vis[buf1.second]=true;
    }

    for(i=1; i<n+1; i++){
        if(vis[i]==true) cnt++;
    }
    cout << (cnt-1)*2 << "\n";
    return 0;
}