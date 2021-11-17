#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll ans=0;
int cnt256[1<<8], sum[1<<8], cnt[1<<16], idx, val;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    int tmp;
    
    memset(cnt, 0, sizeof(cnt));
    
    queue<int> q;
    for(int i=0; i<n; i++){
        cin >> tmp;
        q.push(tmp);
        cnt[tmp]++;
        cnt256[tmp>>8]++;

        if(i>k-2){
            val=0;
            for(idx=0; idx<256; idx++){
                if(val+cnt256[idx]>=(k+1)/2) break;
                val+=cnt256[idx];
            }
            
            idx<<=8;

            sum[0]=cnt[idx];
            
            for(int i=0; i<=256; i++){
                if(val+cnt[idx+i]>=(k+1)/2){
                    ans+=idx+i;
                    break;
                }
                val+=cnt[idx+i];
            }

            cnt[q.front()]--;
            cnt256[q.front()>>8]--;
            q.pop();
        }
    }

    cout << ans;
    return 0;
}