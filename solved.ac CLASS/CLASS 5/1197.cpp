#include <bits/stdc++.h>
#define piii pair<pair<int,int>,int>
#define x first
#define y second
using namespace std;

bool cmp(piii a, piii b){
    if(a.y==b.y){
        if(a.x.x==b.x.x) return a.x.y<b.x.y;
        return a.x.x<b.x.x;
    }
    return a.y<b.y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int v, e, ans=0;
    vector<int> vis, par;
    vector<piii> g;

    cin >> v >> e;
    vis.resize(v+1,0);
    par.resize(v+1,0);

    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g.push_back({{a,b},c});
    }

    sort(g.begin(), g.end(), cmp);

    for(int i=0; i<e; i++){
        if(!vis[g[i].x.x] || !vis[g[i].x.y]){
            ans+=g[i].y;
            if(vis[g[i].x.x]) par[g[i].x.y]=g[i].x.x;
            else par[g[i].x.x]=g[i].x.y;
            vis[g[i].x.x]=vis[g[i].x.y]=1;
        }
        else{
            int nx=g[i].x.x, ny=g[i].x.y;
            while(par[nx]) nx=par[nx];
            while(par[ny]) ny=par[ny];
            if(nx!=ny){
                par[nx]=ny;
                ans+=g[i].y;
            }
        }
    }

    cout << ans;
    return 0;
}