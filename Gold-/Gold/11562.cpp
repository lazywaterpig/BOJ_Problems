#include <bits/stdc++.h>
#define MAX 252
#define INF 1e8
#define endl "\n"
using namespace std;

int n, m;
int arr[MAX][MAX];

void floyd(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(arr[i][k]+arr[k][j]<arr[i][j]){
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) arr[i][j]=INF;
    }
    for(int i=0; i<n; i++) arr[i][i]=0;
    while(m--){
        int from, to, type;
        cin >> from >> to >> type;
        from--; to--;
        if(type==1){
            arr[from][to]=0;
            arr[to][from]=0;
        }
        else{
            arr[from][to]=0;
            arr[to][from]=1;
        }
    }
    floyd();

    int k; cin >> k;
    while(k--){
        int s, e; cin >> s >> e; s--; e--;
        cout << arr[s][e] << endl;
    }

    return 0;
}