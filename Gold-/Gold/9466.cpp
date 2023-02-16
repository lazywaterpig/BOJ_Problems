#include <bits/stdc++.h>
using namespace std;

int arr[100100], vis[100100];
void dfs(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt;; cin >> tt;
    while(tt--){
        int n; cin >> n;
        int cnt=0;
        for(int i=1; i<=n; i++){
            cin >> arr[i];
            vis[i]=0;
        }

        stack<int> s;

        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                vis[i]=1;
                s.push(i);
                int idx=i;
                while(1){
                    if(vis[arr[idx]]){
                        while(!s.empty() && s.top()!=arr[idx]) s.pop();
                        s.pop();
                        while(!s.empty()){
                            cnt++;
                            s.pop();
                        }
                        break;
                    }
                    else{
                        s.push(arr[idx]);
                        vis[arr[idx]]=1;
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}