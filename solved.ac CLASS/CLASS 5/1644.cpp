#include <bits/stdc++.h>
using namespace std;

bool arr[4000010];
long long plist[200000], pcnt=1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    memset(arr, 0, sizeof(arr));
    memset(plist, 0, sizeof(plist));

    for(int i=2; i<4000000; i++){
        if(!arr[i]){
            plist[pcnt]=i;
            pcnt++;
            
            int tmp=i+i;
            while(tmp<4000001){
                arr[tmp]=1;
                tmp+=i;
            }
        }
    }

    plist[0]=0;
    for(int i=1; i<pcnt; i++) plist[i]+=plist[i-1];
    
    int l=1, r=1, ans=0;
    while(!(plist[l]-plist[l-1]>n) && r<pcnt){
        if(plist[r]-plist[l-1]==n){
            ans++;
            l++;
        }
        else if(plist[r]-plist[l-1]<n) r++;
        else l++;

        if(l>r) r++;
    }

    cout << ans;
    return 0;
}