#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, val; cin >> n >> val;
    vector<int> v; v.resize(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> small;
    priority_queue<int> large;

    int sz=(1<<(n+1)/2)-1, cnt=0, piv;
    bool check[40]={0};
    small.push(0); large.push(0);
    while(sz--){
        piv=0;
        check[piv]^=1;
        while(!check[piv]){
        	cnt-=v[piv];
            piv++;
            check[piv]^=1;
        }
        cnt+=v[piv];
        small.push(cnt);
    }

	cnt=0;
	for(int i=0; i<40; i++) check[i]=false;
    sz=(1<<(n-(n+1)/2))-1;
    while(sz--){
        piv=0;
        check[piv]^=1;
        while(!check[piv]){
        	cnt-=v[piv+(n+1)/2];
            piv++;
            check[piv]^=1;
        }
        cnt+=v[piv+(n+1)/2];
        large.push(cnt);
    }

    vector<pii> l, s;
    int tmp=0, lastval=large.top();
    while(!large.empty()){
        if(large.top()==lastval) tmp++;
        else{
            l.push_back({lastval,tmp});
            tmp=1;
            lastval=large.top();
        }
        large.pop();
    }
    l.push_back({lastval,tmp});

    tmp=0, lastval=small.top();
    while(!small.empty()){
        if(small.top()==lastval) tmp++;
        else{
            s.push_back({lastval,tmp});
            tmp=1;
            lastval=small.top();
        }
        small.pop();
    }
    s.push_back({lastval,tmp});

    int lpiv=0, spiv=0;
    long long ans=0;
    while(lpiv<l.size() && spiv<s.size()){
        if(l[lpiv].x+s[spiv].x==val){
            ans+=1LL*l[lpiv].y*s[spiv].y;
            lpiv++;
        }
        else if(l[lpiv].x+s[spiv].x>val) lpiv++;
        else spiv++;
    }

    if(!val) ans--;
    cout << ans;
    return 0;
}