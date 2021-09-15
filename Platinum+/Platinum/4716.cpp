#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
#define piii pair<pii,int>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(1){
        int n, a, b; cin >> n >> a >> b;
        if(n==0 && a==0 && b==0) break;

        int k, da, db, acnt, bcnt;
        vector<pii> av, bv;
        int ans;
        for(int i=0; i<n; i++){
            cin >> k >> da >> db;
            if(da>db){
                ans+=k*db;
                bcnt+=k;
                av.push_back({da-db,k});
            }
            else{
                ans+=k*da;
                acnt+=k;
                bv.push_back({db-da,k});
            }
        }

        sort(av.begin(), av.end());
        sort(bv.begin(), bv.end());
        int avpiv=0, bvpiv=0;
        while(a<acnt || b<bcnt){
            if(a<acnt){
                if(bv[bvpiv].second>=acnt-a){
                    ans+=bv[bvpiv].first*(acnt-a);
                    bcnt+=acnt-a;
                    acnt=a;
                }
                else{
                    ans+=bv[bvpiv].first*bv[bvpiv].second;
                    bcnt+=bv[bvpiv].second;
                    acnt-=bv[bvpiv].second;
                    bvpiv++;
                }
            }
            else{
                if(av[avpiv].second>=bcnt-b){
                    ans+=av[avpiv].first*(bcnt-b);
                    acnt+=bcnt-b;
                    bcnt=b;
                }
                else{
                    ans+=av[avpiv].first*av[avpiv].second;
                    acnt+=av[avpiv].second;
                    bcnt-=av[avpiv].second;
                    avpiv++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}