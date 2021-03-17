#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10][10], tmp[10][10], ct[10][10];

void bulb(int a, int b){
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            tmp[a+i][b+j]+=1;
            tmp[a+i][b+j]%=2;
        }
    }
    ct[a][b]++;
}

bool checker(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(tmp[i][j]==0) return false;
        }
    }
    return true;
}

int sum(){
    int num=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(ct[i][j]==1) num++;
        }
    }
    return num;
}

int main(){
    cin >> n >> m;

    char c;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> c;
            if(c=='*') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }

    int cnt=0, b=0, btmp, ans=-1;
    int bound=(1<<(n+m-1));
    while(b<bound){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) tmp[i][j]=arr[i][j];
        }
        memset(ct, 0, sizeof(ct));
        btmp=b;
        cnt=0;
        while(btmp>0){
            if(btmp%2==1){
                if(cnt>=m) bulb(cnt-m+2, 1);
                else bulb(1, cnt+1);
            }
            cnt++;
            btmp/=2;
        }
        for(int i=2; i<=n; i++){
            for(int j=2; j<=m; j++){
                if(tmp[i-1][j-1]==0) bulb(i, j);
            }
        }

        cnt=sum();
        if(checker()){
            if(ans==-1 || ans>cnt) ans=cnt;
        }

        b++;
    }

    cout << ans << endl;

    return 0;
}