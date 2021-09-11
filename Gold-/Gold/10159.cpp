#include <bits/stdc++.h>
#define MAX 102
#define INF 1e9
#define endl "\n"
using namespace std;

int n, m;
int from, to;
int arr[MAX][MAX];
int dist[MAX][MAX];
vector <int> v;

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

void Floyd2(){
    for(int mid=1; mid<=n; mid++){
        for(int start=1; start<=n; start++){
            if(dist[start][mid]==INF) continue;

            for(int end=1; end<=n; end++){
                if(dist[mid][end]==INF || start==end) continue;

                if(dist[start][end]==INF || dist[start][end]>dist[start][mid]+dist[mid][end]) dist[start][end]=dist[start][mid]+dist[mid][end];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++) {arr[i][j]=INF; dist[i][j]=INF;}
    }
    for(int i=0; i<=n; i++) {arr[i][i]=0; dist[i][i]=0;}

    for(int i=0; i<m; i++){
        cin >> from >> to;
        arr[from][to]=0;
        dist[to][from]=0;
    }

    Floyd();
    Floyd2();

    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(i!=j && arr[i][j]==INF && dist[i][j]==INF) cnt++;
        }
        cout << cnt << endl;
    }
    
    return 0;
}