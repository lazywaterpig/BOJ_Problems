#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){ // index 1~n 사용
        int t_dat[1002];
        int b_cnt[1002];
        int ans[1002];
        vector<int> v[1002];
        vector<int> b[1002];
        memset(t_dat, 0, sizeof(t_dat));
        memset(b_cnt, 0, sizeof(b_cnt));
        memset(ans, 0, sizeof(ans));

        int n, k; cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> t_dat[i];

        int x, y, w;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            v[x].push_back(y);
            b[y].push_back(x);
            b_cnt[y]++;
        }
        cin >> w;

        queue<int> q;
        for(int i=1; i<=n; i++){
            if(b_cnt[i]==0) q.push(i);
        }

        while(!q.empty()){
            int now=q.front();
            q.pop();
            int maxv=0;
            for(int i=0; i<b[now].size(); i++){
                if(maxv<ans[b[now][i]]) maxv=ans[b[now][i]];
            }
            ans[now]=maxv+t_dat[now];
            for(int i=0; i<v[now].size(); i++){
                b_cnt[v[now][i]]--;
                if(b_cnt[v[now][i]]==0) q.push(v[now][i]);
            }
            if(now==w){
                cout << ans[w] << endl;
                break;
            }
        }
    }

    return 0;
}