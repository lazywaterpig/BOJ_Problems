#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100100
#define INF 1e9+7
#define piii pair<int,pair<int,int>>
#define fi first
#define se second
using namespace std;

const ll sz=1<<17;
ll seg_min[2*sz], seg_max[2*sz];
ll minv, maxv;

void min_val(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return;
    if(start<=l && r<=end){
        minv=min(minv, seg_min[n]);
        return;
    }
    ll mid=(l+r)/2;
    min_val(n*2, l, mid, start, end);
    min_val(n*2+1, mid+1, r, start, end);
    return;
}

void max_val(ll n, ll l, ll r, ll start, ll end){
    if(r<start || end<l) return;
    if(start<=l && r<=end){
        maxv=max(maxv, seg_max[n]);
        return;
    }
    ll mid=(l+r)/2;
    max_val(n*2, l, mid, start, end);
    max_val(n*2+1, mid+1, r, start, end);
    return;
}

ll vis[100100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vector<ll> arr(n+1);
    
    for(ll i=0; i<n; i++){
        cin >> seg_min[sz+i+1];
        arr[i]=seg_min[sz+i+1];
        seg_max[sz+i+1]=seg_min[sz+i+1];
    }

    for(ll i=sz-1; i>0; i--){
        seg_min[i]=min(seg_min[i*2], seg_min[i*2+1]);
        seg_max[i]=max(seg_max[i*2], seg_max[i*2+1]);
    }

    memset(vis, 0, sizeof(vis));
    
    ll s=1, e=k, ans=1, cur;
    while(s<=e){
        cur=(s+e)/2;
        bool flag=0;

    	memset(vis, 0, sizeof(vis));
    	
        ll viscnt=0;
        for(ll i=0; i<cur; i++){
            vis[arr[i]]++;
            if(vis[arr[i]]==2) viscnt++;
        }
        
        minv=1e9+1, maxv=0;
        min_val(1, 0, sz-1, 1, cur);
        max_val(1, 0, sz-1, 1, cur);
        if(maxv-minv<cur && !viscnt){
            ans=max(ans,cur);
            s=cur+1;
            continue;
        }
        
        for(ll i=0; i<n-cur; i++){
            minv=1e9+1, maxv=0;
            min_val(1, 0, sz-1, i+2, i+cur+1);
            max_val(1, 0, sz-1, i+2, i+cur+1);
            vis[arr[i]]--;
            if(vis[arr[i]]==1) viscnt--;
            vis[arr[i+cur]]++;
            if(vis[arr[i+cur]]==2) viscnt++;

            if(maxv-minv<cur && !viscnt){
                flag=1;
            }
        }            

        if(flag){
            ans=max(ans,cur);
            s=cur+1;
        }
        else e=cur-1;
    }

    cout << k-ans;
    return 0;
}