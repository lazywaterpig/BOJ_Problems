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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<int> arr(n);
        string s; cin >> s;
        for(int i=0; i<n; i++) arr[i]=s[i]-48;

        if(n==1 || n==3) cout << "-1";
        else if(n==2){
            if(s[0]==s[1]) cout << "1";
            else cout << "0";
        }
        else{
            int cnt[2]={0};
            for(int i=0; i<n; i++) cnt[arr[i]]++;

            if(!cnt[0] || !cnt[1]) cout << "2";
            else{
                int max1=-1, min1=100000000, max0=-1, min0=10000000;
                for(int i=0; i<n; i++){
                    if(arr[i]){
                        if(max1<i) max1=i;
                        if(min1>i) min1=i;
                    }
                    else{
                        if(max0<i) max0=i;
                        if(min0>i) min0=i;
                    }
                }
                int mcnt=0;
                int max1_2=-100000000, min1_2=100000000, max0_2=-100000000, min0_2=10000000;

                for(int i=0; i<n; i++){
                    if(arr[i]) mcnt++;
                    if(mcnt==2){
                        min1_2=i;
                        break;
                    }
                }

                mcnt=0;
                for(int i=n; i>-1; i--){
                    if(arr[i]) mcnt++;
                    if(mcnt==2){
                        max1_2=i;
                        break;
                    }
                }

                mcnt=0;
                for(int i=0; i<n; i++){
                    if(!arr[i]) mcnt++;
                    if(mcnt==2){
                        min0_2=i;
                        break;
                    }
                }

                mcnt=0;
                for(int i=n; i>-1; i--){
                    if(!arr[i]) mcnt++;
                    if(mcnt==2){
                        max0_2=i;
                        break;
                    }
                }
                //cout << max1_2 << ' ' << min1_2 << ' ' << max0_2 << ' ' << min0_2 << endl;
                if(max1-min1==max0-min0) cout << "0";
                else{
                    int flag=0;
                    for(int i=0; i<n; i++){
                        int tmax1=max1, tmin1=min1, tmax0=max0, tmin0=min0;
                        if(arr[i]){
                            if(tmax0<i) tmax0=i;
                            if(tmin0>i) tmin0=i;
                            if(tmax1==i) tmax1=max1_2;
                            if(tmin1==i) tmin1=min1_2;

                            if(tmax0-tmin0==tmax1-tmin1){
                            	flag=1;
                            	//cout << i << '?' << endl;
                            	//cout << 
                            }
                        }
                        else{
                            if(tmax1<i) tmax1=i;
                            if(tmin1>i) tmin1=i;
                            if(tmax0==i) tmax0=max0_2;
                            if(tmin0==i) tmin0=min0_2;

                            if(tmax0-tmin0==tmax1-tmin1){
                            	flag=1;
                            	//cout << i << '?' << endl;
                            	//cout << 
                            }
                        }
                    }
                    if(flag) cout << "1";
                    else cout << "2";
                }
            }
        }
		cout << '\n';
    }
    
    return 0;
}