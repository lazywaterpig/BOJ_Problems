#include <bits/stdc++.h>
using namespace std;

int arr[1050][1050], sum[1050][1050]={0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, k, n, m, x1, y1, x2, y2;
    cin >> n >> m;
    
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
	
	
    sum[1][1]=arr[1][1];
    for(i=2; i<=n; i++) sum[i][1]=arr[i][1]+sum[i-1][1];
    for(i=2; i<=n; i++) sum[1][i]=arr[1][i]+sum[1][i-1];

    for(i=2; i<=n; i++){
        for(j=2; j<=n; j++){
            sum[i][j]=arr[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    while(m--){
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        cout << sum[x2][y2]-sum[x1][y2]-sum[x2][y1]+sum[x1][y1] << "\n";
    }

    return 0;
}