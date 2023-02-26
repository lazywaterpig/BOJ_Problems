#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<pii> v(n);
	
	for(int i=0; i<n; i++) cin >> v[i].fi >> v[i].se;
	sort(v.begin(), v.end());
	if(k==1){
		int t=v[0].fi;
		int ans=0;
		for(int i=0; i<n; i++){
			ans=max(ans, 30+(v[i].fi-t)*v[i].se);
		}
		cout << ans;
	}
	else if(k==2){
		int t1=v[0].fi;
		int ans=1e9+7;
		for(int t2=t1; t2<=100; t2++){
			int d1=30, d2=0;
			for(int i=1; i<n; i++){
                int val1=30+(v[i].fi-t1)*v[i].se;
                int val2=30+(v[i].fi-t2)*v[i].se;
                
				if((v[i].fi>=t1 && val1<=d1) || (v[i].fi>=t2 && val2<=d2)) continue;
				else if(v[i].fi<t2) d1=val1;
				else d2=val2;
			}
			ans=min(ans, d1+d2);
		}
		cout << ans;
	}
	else{
		int t1=v[0].fi;
		int ans=1e9+7;
		for(int t2=t1; t2<=100; t2++){
			for(int t3=t2; t3<=100; t3++){
				int d1=30, d2=0, d3=0;
				for(int i=1; i<n; i++){
                    int val1=30+(v[i].fi-t1)*v[i].se;
                    int val2=30+(v[i].fi-t2)*v[i].se;
                    int val3=30+(v[i].fi-t3)*v[i].se;
                    
					if((v[i].fi>=t1 && val1<=d1) || (v[i].fi>=t2 && val2<=d2) || (v[i].fi>=t3 && val3<= d3)) continue;
					else if(v[i].fi<t2) d1=val1;
                    else if(v[i].fi<t3) d2=val2;
					else d3=val3;
				}
				ans=min(ans, d1+d2+d3);
			}
		}
		cout << ans;
	}

    return 0;
}