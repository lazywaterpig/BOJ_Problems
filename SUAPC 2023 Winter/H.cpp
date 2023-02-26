#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define MAX 100100
#define INF 1000000007
#define piii pair<pair<int,int>,int>
#define fi first
#define se second
using namespace std;

pii bt(ll x, ll y){
    return {-y,x};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    vector<pii> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;

    int min[2]={INF,INF}, max[2]={-INF,-INF};
    for(int i=0; i<n; i++){
        if(arr[i].fi<min[0]) min[0]=arr[i].fi;//x
        if(arr[i].fi>max[0]) max[0]=arr[i].fi;
        if(arr[i].se<min[1]) min[1]=arr[i].se;//y
        if(arr[i].se>max[1]) max[1]=arr[i].se;
    }

    cout << 2*(max[0]+max[1]-min[0]-min[1])+4 << ' ';

    if(n==1) cout << "1";
    else if(n==2) cout << max[0]+max[1]-min[0]-min[1]+1;
    else{
        ll ans = (max[0]-min[0]+1)*(max[1]-min[1]+1);

        for(int _=0; _<4; _++){
            ll tmp=0;
            //make ans
            sort(arr.begin(), arr.end());

            pii lu={INF,-INF}, ul={-INF, -INF};
            for(int i=0; i<n; i++){
                if(lu.fi>arr[i].fi){
                    lu=arr[i];
                }
                else if(lu.fi==arr[i].fi && lu.se<arr[i].se){
                    lu=arr[i];
                }

                if(ul.se<arr[i].se){
                    ul=arr[i];
                }
                else if(ul.se==arr[i].se && ul.fi>arr[i].fi){
                    ul=arr[i];
                }
            }

            ll maxv=lu.se, piv=lu.fi;
            for(int i=0; i<n; i++){
                if(i<n-1){
                    while(i<n-1 && arr[i].fi==arr[i+1].fi && arr[i].se<arr[i+1].se) i++;
                }
                if(arr[i].fi==ul.fi && arr[i].se==ul.se){
                    tmp+=abs(ul.se-maxv)*abs(ul.fi-piv);

                    break;
                }
                if(piv<arr[i].fi && arr[i].se>maxv){
                    tmp+=abs(ul.se-maxv)*abs(arr[i].fi-piv);
                    piv=arr[i].fi;
                    maxv=arr[i].se;
                }
            }

            ans-=tmp;

            //board turn
            for(int i=0; i<n; i++){
            	arr[i]=bt(arr[i].fi, arr[i].se);
            }
        }
        cout << ans;
    }
    
    return 0;
}