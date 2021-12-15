#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

int d[5]={-1, 0, 1, 0, -1};

bool oob(int x, int y, int r, int c){
    if(r-1>x && x>0 && c-1>y && y>0) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    for(int _=1; _<=t; _++){
        cout << "Case #" << _ << ": ";
        int r, c, d; cin >> r >> c >> d;
        int sx, sy, fx, fy;
        vector<vector<char>> arr, vis;
        vector<char> v, v2;
        v.resize(c);
        v2.resize(c);
        memset(v2, 0, sizeof(v2));
        for(int i=0; i<r; i++){
            arr.push_back(v);
            vis.push_back(v2);
        }

        for(int i=0; i<r; i++){
            string s; cin >> s;
            for(int j=0; j<c; j++){
                arr[i][j]=s[j];
                if(s[j]=='S'){ sx=i, sy=j; }
                if(s[j]=='F'){ fx=i, fy=j; }
            }
        }

        if(abs(sx-fx)+abs(sy-fy)>d){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        queue<pii> q;
        q.push({sx, sy});
        vis[sx][sy]=1;
        while(!q.empty()){
            pii cur=q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nx=sx+d[i], ny=sy+d[i+1];
                if(!oob(nx, ny, r, c) && arr[nx][ny]!='#' $$ !vis[nx][ny]){
                    vis[nx][ny]=1;
                    if
                }
            }

        }

    }

    return 0;
}