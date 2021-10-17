#include <bits/stdc++.h>
using namespace std;

int arr[101][1001]={0}, piv[101]={0}, cnt[1001]={0}, sum[1001]={0};

int main(){
    queue<int> q;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int sz; cin >> sz;
        for(int j=0; j<sz; j++){
            cin >> arr[i][j];
            cnt[arr[i][j]]++;
        }
    }

    for(int i=0; i<m; i++){
        sum[arr[i][0]]++;
    }

    int flag=0;
    for(int i=0; i<n; i++){
        int idx=-1;
        for(int j=1; j<=n; j++){
            if(sum[j]==cnt[j]){ idx=j; break; }
        }
        if(idx==-1){
            flag=1;
            break;
        }
        q.push(idx);
        for(int j=0; j<m; j++){
            if(arr[j][piv[j]]==idx){
                sum[idx]--;
                piv[j]++;
                sum[arr[j][piv[j]]]++;
            }
        }
    }
    if(flag) cout << "0" << endl;
    else{
        while(!q.empty()){
            cout << q.front() << endl;
            q.pop();
        }
    }

    return 0;
}