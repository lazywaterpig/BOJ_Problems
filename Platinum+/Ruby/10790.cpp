#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c; cin >> c;
    while(c--){
        ll l, v1, v2, t, s, m, cur=0, flag=0, maxv=0, piv;
        cin >> l >> v1 >> v2 >> t >> s;
        piv=l/v2;
        while(1){
            ll tmp=t, cnt=0;
            while(tmp<v2-v1){ tmp*=2; cnt++; }
            if((cnt+cur)*s*(v2-t)<=l){
                cur+=cnt;
                break;
            }
            while((cnt+cur)*s*(v2-t)>l){ tmp/=2; cnt--; }



            /*ll tmp=t, cnt=0;
            while(tmp<v2-v1){ tmp*=2; cnt++; }
            if((cnt+cur)*s*(v2-t)<=l){
                cur+=cnt;
                break;
            }
            while((cnt+cur)*s*(v2-t)>l){ tmp/=2; cnt--; }
            if(cnt==0){
                flag=1;
                break;
            }
 
            v2-=tmp/2;
            cur+=1;*/
        }
        if(flag==1) cout << "impossible\n";
        else cout << cur << "\n";
    }

    return 0;
}



/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c; cin >> c;
    while(c--){
        ll l, v1, v2, t, s, m, cur=0, flag=0, maxv=0;
        cin >> l >> v1 >> v2 >> t >> s;
        while(1){
            ll tmp=t, cnt=0, tmpv2=v2, tmpcnt;
            while(tmp<v2-v1 && (cnt+cur)*s*(v2-t)<=l){ tmp*=2; cnt++; }
            if(cnt==0 && v2-v1<=t) break;
            if(cnt==0){
            	flag=1; break;
            }
            if((cnt+cur)*s*(v2-t)<=l){
                cur+=cnt;
                break;
            }
            while((cnt+cur)*s*(v2-t)>l){ tmp/=2; cnt--; }
            tmpcnt=cnt;
            while(cnt>0){
            	tmpv2-=tmp/2;
            	cnt--;
            	tmp/=2;
            	if(tmpv2<=v1+t) break;
            	if((tmpcnt+cur+1)*s*(tmpv2-t)<=l){
            		tmpcnt++;
            		cnt++;
            		tmp*=2;
            	}
            }
            
            maxv=max(maxv,tmpcnt+cur);
            cur++;
            v2=tmpv2;
        }
        if(flag==1) cout << "impossible\n";
        else cout << max(cur,maxv) << "\n";
    }

    return 0;
}