#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

bool vis[1000010];
int par[1000010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    q.push({n,0});
    vis[n]=true;
    par[n]=-1;

    pair<int,int> cur;
    while(1){
        cur=q.front();
        q.pop();
        if(cur.x==1){
            cout << 0 << endl;
            break;
        }
        if(cur.x==2 || cur.x==3){
            cout << cur.y+1 << endl;
            par[1]=cur.x;
            break;
        }

        if(cur.x%3==0 && !vis[cur.x/3]){
            vis[cur.x/3]=true;
            par[cur.x/3]=cur.x;
            q.push({cur.x/3,cur.y+1});
        }
        if(cur.x%2==0 && !vis[cur.x/2]){
            vis[cur.x/2]=true;
            par[cur.x/2]=cur.x;
            q.push({cur.x/2,cur.y+1});
        }
        if(!vis[cur.x-1]){
            vis[cur.x-1]=true;
            par[cur.x-1]=cur.x;
            q.push({cur.x-1,cur.y+1});
        }
    }

    stack<int> s;
    int piv=1;
    s.push(1);
    while(par[piv]!=-1){
        piv=par[piv];
        s.push(piv);
    }

    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}