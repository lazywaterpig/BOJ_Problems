#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    int arr[101];
    bool in_use[101]={0};
    int tab[101]={0};
    vector<int> pos[101];
    int piv[101]={0};

    for(int i=0; i<m; i++){
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }
    
    int cnt=0, ans=0;
    int maxv, maxi;
    for(int i=0; i<m; i++){
        if(in_use[arr[i]]==1){
        	piv[arr[i]]++;
        	continue;
        }
        else if(cnt<n){
            cnt++;
            for(int j=0; j<n; j++){
                if(tab[j]==0){
                    tab[j]=arr[i];
                    in_use[arr[i]]=1;
                    piv[arr[i]]++;
                    break;
                }
            }
        }
        else{
            ans++;
            maxv=-1;
            for(int j=0; j<n; j++){
                if(piv[tab[j]]==pos[tab[j]].size()){
                    maxv=101;
                    maxi=j;
                    break;
                }
                if(maxv<pos[tab[j]][piv[tab[j]]]){
                    maxv=pos[tab[j]][piv[tab[j]]];
                    maxi=j;
                }
            }
            piv[arr[i]]++;
            in_use[tab[maxi]]=0;
            in_use[arr[i]]=1;
            tab[maxi]=arr[i];
        }
    }

    cout << ans;
    return 0;
}