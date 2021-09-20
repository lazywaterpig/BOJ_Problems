#include <bits/stdc++.h>
using namespace std;

int arr[100002][3];
bool res[100002][2];
vector<int> v[100002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        int cnt; cin >> cnt;
        for(int j=0; j<cnt; j++){
            cin >> arr[i][j];
            v[i].push_back(arr[i][j]);
        }
    }
    for(int i=1; i<=n; i++){
        res[i][0]=1;
        res[i][1]=0;
    }
    for(int _=0; _<sqrt(n)+1; _++){
        for(int i=1; i<=n; i++){
            int cnt=0;
            int flag;
            if(res[i][0]==1) flag=0;
            else flag=1;
            for(auto a : v[i]){
                if(res[a][flag]==1) cnt++;
            }
            if(cnt>=2){
                res[i][flag]=0;
                res[i][flag^1]=1;
            }
        }
    }

	int cnt=0;
    for(int i=1; i<=n; i++) if(res[i][0]==1) cnt++;
    cout << cnt << ' ';
    for(int i=1; i<=n; i++) if(res[i][0]==1) cout << i << ' ';
    cout << endl;
    cout << n-cnt << ' ';
    for(int i=1; i<=n; i++) if(res[i][1]==1) cout << i << ' ';
    cout << endl;
    return 0;
}