#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int parent[20001], dist[20001];

int find(int node){
	if(node==parent[node]) return node;
    int idx=find(parent[node]);
    dist[node]+=dist[parent[node]];
	return parent[node]=idx;
}

void merge(int s, int l){	
	parent[s]=l;
	dist[s]=abs(s-l)%1000;
}

int solve(int u){
	find(u);
	return dist[u];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i=1; i<=n; i++){
			parent[i]=i;
			dist[i]=0;
		}
		
		while(1){
			char ord; cin >> ord;
			if(ord=='O') break;
			else if(ord=='E'){
				int node; cin >> node; cout << solve(node) << endl;
			}
			else{
				int u, v; cin >> u >> v;
				merge(u, v);
			}
		}
	}
	return 0;
}