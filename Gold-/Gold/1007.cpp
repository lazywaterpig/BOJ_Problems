#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dist[2];
ll xsum, ysum;

ll d(){
    return (2*dist[0]-xsum)*(2*dist[0]-xsum)+(2*dist[1]-ysum)*(2*dist[1]-ysum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int piv[11], arr[21][2];
		dist[0]=0, dist[1]=0;
		xsum=0, ysum=0;
		
        for(int i=0; i<n; i++){
            if(i<n/2) piv[i]=i;
            cin >> arr[i][0] >> arr[i][1];
        }

        for(int i=0; i<n; i++){
            xsum+=arr[i][0];
            ysum+=arr[i][1];
        }
        for(int i=0; i<n/2; i++){
            dist[0]+=arr[i][0];
            dist[1]+=arr[i][1];
        }
        ll ans=d();
        while(piv[0]<n/2){
            int ppiv=n/2-1;
            while(piv[ppiv]==n/2+ppiv) ppiv--;
            
            if(ppiv==n/2-1){
                dist[0]-=arr[piv[ppiv]][0];
                dist[1]-=arr[piv[ppiv]][1];
                piv[ppiv]++;
                dist[0]+=arr[piv[ppiv]][0];
                dist[1]+=arr[piv[ppiv]][1];
                ans=min(ans, d());
            }
            else{
                for(int i=ppiv; i<n/2; i++){
                    dist[0]-=arr[piv[i]][0];
                    dist[1]-=arr[piv[i]][1];
                }

                piv[ppiv]++;
                for(int i=ppiv+1; i<n/2; i++) piv[i]=piv[i-1]+1;

                for(int i=ppiv; i<n/2; i++){
                    dist[0]+=arr[piv[i]][0];
                    dist[1]+=arr[piv[i]][1];
                }
                ans=min(ans, d());
            }
        }
        cout << fixed;
        cout.precision(12);
        cout << sqrt(double(ans)) << endl;
    }
}