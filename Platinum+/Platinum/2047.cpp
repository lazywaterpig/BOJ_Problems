#include <bits/stdc++.h>
using namespace std;

char arr[100][100];
bool visited[100][100];
int d[5]={-1,0,1,0,-1};

int main(){
    int t;
    cin >> t;
    while(t--){
        char tmp;
        int i, j, h, w, cnt=0, tx, ty;
        memset(arr, '0', sizeof(arr));
        memset(visited, false, sizeof(arr));
        
        cin >> h >> w;
        for(i=1; i<=h; i++){
            for(j=1; j<=w; j++){
                cin >> arr[i][j];
                if(arr[i][j]=='s'){
                    tx=i;
                    ty=j;
                }
            }
        }
        queue <int> qx, qy;
        qx.push(tx);
        qy.push(ty);
        while(!qx.empty()){
            tx=qx.front();
            ty=qy.front();
            qx.pop();
            qy.pop();
            for(i=0; i<4; i++){
                if(arr[tx+d[i]][ty+d[i+1]]=='.' && !visited[tx+d[i]][ty+d[i+1]]){
                    visited[tx+d[i]][ty+d[i+1]]=true;
                    qx.push(tx+d[i]);
                    qy.push(ty+d[i+1]);
                    cnt++;
                }
            }
        }

        cout << cnt+1 << ".00" << endl;
    }
    return 0;
}