#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int n, m, l; 
char board[301][301];
long long sum[301][301], ans[301][301];
int sp[5]={-2, 2, 2, -2, -2};

bool oob(int x, int y){
    if(0<=x && x<n && 0<=y && y<m) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> l;
    string word; cin >> word;
    
    for(int i=0; i<n; i++){
        string ord; cin >> ord;
        for(int j=0; j<m; j++){
            board[i][j]=ord[j];
            if(word[0]==board[i][j]) ans[i][j]=1;
            else ans[i][j]=0;
        }
    }

    for(int cur=1; cur<word.size(); cur++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[cur-1]!=board[i][j]) sum[i][j]=0;
                else sum[i][j]=ans[i][j]%MOD;
                ans[i][j]=0;
            }
        }

        for(int i=1; i<n; i++) sum[i][0]+=sum[i-1][0];
        for(int j=1; j<m; j++) sum[0][j]+=sum[0][j-1];
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++) sum[i][j]+=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[cur]==board[i][j]){
                    ans[i][j]+=sum[n-1][m-1];
                    ans[i][j]-=sum[min(n-1, i+1)][m-1];
                    if(i-2>-1) ans[i][j]+=sum[i-2][m-1];
                    ans[i][j]-=sum[n-1][min(m-1, j+1)];
                    if(j-2>-1) ans[i][j]+=sum[n-1][j-2];
                    ans[i][j]+=sum[min(n-1, i+1)][min(m-1, j+1)];
                    if(i-2>-1) ans[i][j]-=sum[i-2][min(m-1, j+1)];
                    if(j-2>-1) ans[i][j]-=sum[min(n-1, i+1)][j-2];
                    if(i-2>-1 && j-2>-1) ans[i][j]+=sum[i-2][j-2];
                    for(int k=0; k<4; k++){
                        if(!oob(i+sp[k], j+sp[k+1])){
                        	ans[i][j]-=sum[i+sp[k]][j+sp[k+1]];
                        	if(!oob(i+sp[k]-1, j+sp[k+1])) ans[i][j]+=sum[i+sp[k]-1][j+sp[k+1]];
                        	if(!oob(i+sp[k], j+sp[k+1]-1)) ans[i][j]+=sum[i+sp[k]][j+sp[k+1]-1];
                        	if(!oob(i+sp[k]-1, j+sp[k+1]-1)) ans[i][j]-=sum[i+sp[k]-1][j+sp[k+1]-1];
                        }
                    }
                }
            }
        }
    }

    long long cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(word[word.size()-1]==board[i][j]) cnt+=ans[i][j];
        }
    }

    cout << cnt%MOD << endl;
    return 0;
}