#include <bits/stdc++.h>
using namespace std;

int normal[102][102], weak[102][102];
int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

int bfs(int arr[][102], int num){
    int cnt=0, val, tx, ty;
    queue <int> x, y;
    bool visit[102][102]={false, };

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(visit[i][j]==false){
                val=arr[i][j];
                visit[i][j]=true;
                x.push(i);
                y.push(j);

                while(!x.empty()){
                    tx=x.front();
                    ty=y.front();
                    x.pop();
                    y.pop();
                    for(int k=0; k<4; k++){
                        if(((tx+dx[k]>=0 && tx+dx[k]<num) && (ty+dy[k]>=0 && ty+dy[k]<num)) && (visit[tx+dx[k]][ty+dy[k]]==false && arr[tx+dx[k]][ty+dy[k]]==val)){
                            visit[tx+dx[k]][ty+dy[k]]=true;
                            x.push(tx+dx[k]);
                            y.push(ty+dy[k]);
                        }
                    }
                }

                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string color;

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> color;
        for(int j=0; j<n; j++){
            if(color[j]=='R'){
                normal[i][j]=1;
                weak[i][j]=1;
            }else if(color[j]=='G'){
                normal[i][j]=2;
                weak[i][j]=1;
            }else{
                normal[i][j]=3;
                weak[i][j]=2;
            }
        }
    }

    cout << bfs(normal, n) << ' ' << bfs(weak, n) << endl;
    return 0;
}

