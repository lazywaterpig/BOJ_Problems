#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int visited[2][1001][1001];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++) arr[i][j]=s[j]-48;
    }

    memset(visited, 0, sizeof(visited));
    bool flag=1;
    queue <int> x, y, f, c;
    int tx,ty,tf,tc;
    x.push(0);
    y.push(0);
    f.push(0);
    c.push(0);
    visited[0][0][0]=1;
    while(!x.empty()){
        tx=x.front();
        ty=y.front();
        tf=f.front();
        tc=c.front();

        if(tx==n-1 && ty==m-1){
            cout << tc+1 << endl;
            flag=0;
            break;
        }
        
        x.pop();
        y.pop();
        f.pop();
        c.pop();

        if(tf==0){
            for(int i=0; i<2; i++){
                for(int j=0; j<4; j++){
                    if(((tx+dx[j]>=0 && ty+dy[j]>=0) && (tx+dx[j]<n && ty+dy[j]<m)) && (arr[tx+dx[j]][ty+dy[j]]==i && !visited[i][tx+dx[j]][ty+dy[j]])){
                        visited[i][tx+dx[j]][ty+dy[j]]=1;
                        x.push(tx+dx[j]);
                        y.push(ty+dy[j]);
                        f.push(i);
                        c.push(tc+1);
                    }
                }
            }
        }
        else{
            for(int j=0; j<4; j++){
                if(tx+dx[j]>=0 && ty+dy[j]>=0 && tx+dx[j]<n && ty+dy[j]<m && arr[tx+dx[j]][ty+dy[j]]==0 && !visited[1][tx+dx[j]][ty+dy[j]]){
                    visited[1][tx+dx[j]][ty+dy[j]]=1;
                    x.push(tx+dx[j]);
                    y.push(ty+dy[j]);
                    f.push(1);
                    c.push(tc+1);
                }
            }
        }
    }
    if(flag==1) cout << "-1" << endl;
    return 0;
}