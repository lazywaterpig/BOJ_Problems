#include <bits/stdc++.h>
using namespace std;

int N;
bool vis[100001];
vector <pair<int,int>> node[100001];

int ans;
int res=0, res2;
int ep=0, ep2;
void dfs(int point, int length){
    if(vis[point]) return;

    vis[point]=true;
    if(res<length){
        res2=res;
        res=length;
        ep2=ep;
        ep=point;
    }
    else if(res2<length){
        res2=length;
        ep2=point;
    }

    for(int i=0; i<node[point].size(); i++){
        dfs(node[point][i].first, length+node[point][i].second);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int parent, child, length;
    for(int i=0; i<N-1; i++){
        cin >> parent;
        cin >> child;
        cin >> length;
        node[parent].push_back(make_pair(child, length));
        node[child].push_back(make_pair(parent, length));
    }

    memset(vis, false, sizeof(vis));
    dfs(1, 0);

    int tres=res2, tep=ep, tep2=ep2;

    res=0; res2=0; ep2=0;
    memset(vis, false, sizeof(vis));
    dfs(ep, 0);
    ans=res2;
	
	int tnode1=tep, tnode2=ep;
	
    res=0; res2=0; ep=0; ep2=0;
    memset(vis, false, sizeof(vis));
    dfs(tep2, 0);

    if((tnode1==tep2 && tnode2==ep) || (tnode1==ep && tnode2==tep2)){
    	if(res2>ans) ans=res2;
    }
    else{
    	if(res>ans) ans=res;
    }

    cout << ans << endl;
    return 0;
}