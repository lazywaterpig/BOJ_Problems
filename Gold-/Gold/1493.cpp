#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll l, w, h; cin >> l >> w >> h;
    
    ll arr[22]={0};
    ll n; cin >> n;
    for(ll i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        arr[a]=b;
    }

    ll tflag=0, cnt=0;
    for(ll i=0; i<20; i++){
        ll flag=0;
        ll cur = (1<<(i+1));
        ll cl, cw, ch;
        cl=l%cur; cw=w%cur; ch=h%cur;
        if(l<cur || w<cur || h<cur){
        	cl=l; cw=w; ch=h;
        }

        ll need = h*w*cl+w*l*ch+l*h*cw-h*cw*cl-w*cl*ch-l*ch*cw+ch*cw*cl;
		//cout << "need: " << i << " " << need << endl;
        //  ll piv=i, sz=(1<<i); sz=sz*sz*sz;
        ll piv=i, sz=(1<<i)*(1<<i)*(1<<i);
        //cout << sz << endl;
        while(sz){
        	//cout << i << ' ' << need/sz << ' ' << arr[piv] << endl;
            if(need/sz<=arr[piv]){
                arr[piv]-=need/sz;
                //cout << piv << ' ' << need/sz << endl;
                cnt+=need/sz;
                flag=1;
                break;
            }

            need-=sz*arr[piv];
            //cout << piv << ' ' << arr[piv] << endl;
            cnt+=arr[piv];
            arr[piv]=0;
            sz/=8;
            piv--;
        }

        if(!flag){
        	//cout << "???? " << i << endl;
            tflag=1;
            break;
        }
        
        l=l-l%cur; w=w-w%cur; h=h-h%cur;
        if(!l || !w || !h) break;
    }

    if(!tflag) cout << cnt;
    else cout << "-1";

    return 0;
}