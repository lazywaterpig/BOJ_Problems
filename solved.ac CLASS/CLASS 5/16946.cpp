#include <bits/stdc++.h>
using namespace std;

int n, m, piv, cnt; 
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int mp[1001][1001], piv_cnt[500001];

bool OOB(int a, int b){
    return !(a>=0 && b>=0 && a<n && b<m);
}

void dfs(int x, int y){
    mp[x][y]=piv;
    cnt++;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!OOB(nx, ny) && mp[nx][ny]==0) dfs(nx, ny);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string ord; cin >> ord;
        for(int j=0; j<m; j++) mp[i][j]=ord[j]-48;
    }

    memset(piv_cnt, 0, sizeof(piv_cnt));
    piv=2;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mp[i][j]==0){
                cnt=0;
                dfs(i, j);
                piv_cnt[piv]=cnt;
                piv++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mp[i][j]!=1) cout << '0';
            else{
                cnt=0;
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    int flag=0;
                    for(int l=0; l<k; l++){
                    	int tx=i+dx[l];
                    	int ty=j+dy[l];
                    	if(OOB(nx, ny) || (mp[nx][ny]!=1 && mp[tx][ty]!=1 && mp[nx][ny]==mp[tx][ty])){
                    		flag=1;
                    		break;
                    	}
                    }
                    if(!OOB(nx, ny) && flag!=1) cnt+=piv_cnt[mp[nx][ny]];
                }
                cout << (cnt+1)%10;
            }
        }
        cout << endl;
    }

    return 0;
}