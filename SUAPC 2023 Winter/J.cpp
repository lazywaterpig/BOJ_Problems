#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100100
#define INF 1e9+7
#define piii pair<pair<int,int>,int>
#define fi first
#define se second
using namespace std;

int vis[200200]={0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vector<piii> arr(n);
    for(int i=0; i<n; i++){
        int a, b, p; cin >> a >> b >> p;
        if(a>b) swap(a,b);
        a--; b--;
        arr[i].fi.fi=a;
        arr[i].fi.se=b;
        arr[i].se=p;
    }

    sort(arr.begin(), arr.end());

    int ans=0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            queue<int> q, q2;
            q.push(i);
            q2.push(i);
            vis[i]=1;

            int piv=arr[piv].fi.se;
            while(!vis[piv]){
                q.push(piv);
                q2.push(piv);
                vis[piv]=1;
                piv=arr[piv].fi.se;
            }
            
            if(q.size()==1) ans+=arr[i].se;
            else{
                int pk, npk, pk2, npk2;
                int tpk, tnpk, tpk2, tnpk2;
                auto cur = q.front();
                q.pop();

                pk=arr[cur].se;
                cur=q.front();
                q.pop();

                pk+=arr[cur].se;
                npk=arr[cur].se;
                while(!q.empty()){
                    cur = q.front();
                    q.pop();
                    tpk=min(pk+arr[cur].se,npk+arr[cur].se);
                    tnpk=pk;

                    pk=tpk;
                    npk=tnpk;
                }

                cur = q2.front();
                q2.pop();

                pk2=0;
                npk2=0;
                cur=q2.front();
                q2.pop();

                pk2=arr[cur].se;
                npk2=0;

                if(!q2.empty()){
                    cur=q2.front();
                    q2.pop();
                    
                    pk2+=arr[cur].se;
                    npk2=arr[cur].se;
                        
                    while(!q2.empty()){
                        cur = q2.front();
                        q2.pop();
                        tpk2=min(pk2+arr[cur].se,npk2+arr[cur].se);
                        tnpk2=pk2;
    
                        pk2=tpk2;
                        npk2=tnpk2;
                    }
                }

                ans+=min(min(pk,npk),pk2);
            }
        }
    }
    
    cout << ans;
    return 0;
}