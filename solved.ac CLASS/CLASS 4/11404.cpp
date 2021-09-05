#include <bits/stdc++.h>
#define MAX 102
#define INF 1234567890
using namespace std;

int n, m;
int arr[MAX][MAX];

void Floyd(){
    for(int mid=1; mid<=n; mid++){
        for(int start=1; start<=n; start++){
            if(arr[start][mid]==INF) continue;

            for(int end=1; end<=n; end++){
                if(arr[mid][end]==INF || start==end) continue;

                if(arr[start][end]==INF || arr[start][end]>arr[start][mid]+arr[mid][end]) arr[start][end]=arr[start][mid]+arr[mid][end];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++) arr[i][j]=INF;
    }
    for(int i=0; i<=n; i++) arr[i][i]=0;

    for(int i=0; i<m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;

        if(arr[from][to]==INF) arr[from][to]=cost;
        else arr[from][to]=min(arr[from][to], cost);
    }

    Floyd();

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(arr[i][j]==INF) arr[i][j]=0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}