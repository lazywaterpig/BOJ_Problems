#include <bits/stdc++.h>
#define MAX 1000010
using namespace std;

typedef long long ll;

ll n, b, c, tmp;
ll arr[MAX][3], cnt[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> b >> c;
    for(int i=0; i<n; i++){ cin >> arr[i][0]; cnt[0]+=arr[i][0]; }

    if(b>c){
        tmp=min(arr[0][0], arr[1][0]);
        arr[0][1]=tmp;
        arr[0][0]-=tmp;
        arr[1][0]-=tmp;
        cnt[1]+=tmp;
        cnt[0]-=tmp*2;
        
        for(int i=1; i<n-1; i++){
	        tmp=min(arr[i][0], arr[i+1][0]);
	        arr[i][1]+=tmp;
	        arr[i][0]-=tmp;
	        arr[i+1][0]-=tmp;
	        cnt[1]+=tmp;
	        cnt[0]-=tmp*2;
	        tmp=min(arr[i-1][1], arr[i+1][0]);
	        arr[i][2]+=tmp;
	        arr[i-1][1]-=tmp;
	        arr[i+1][0]-=tmp;
	        cnt[2]+=tmp;
	        cnt[1]-=tmp;
	        cnt[0]-=tmp;
        }
        cout << (cnt[0]+cnt[1]+cnt[2])*b + (cnt[1]+(cnt[2]*2))*c;
    }
    else cout << cnt[0]*b;

    return 0;
}