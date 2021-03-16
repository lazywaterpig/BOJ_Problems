#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, t;
    cin >> n >> t;

    vector <pair<int,int>> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());
    int idx, minv, bound=v[0].first;
    bool vis[10001], flag=true;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++){
        idx=0;
        minv=1234567890;
        for(int j=0; j<n; j++){
            if(vis[j]==false && minv>v[j].second){
                minv=v[j].second;
                idx=j;
            }
        }
        if(bound+t>minv){
            flag=false;
            break;
        }
        bound=minv;
        vis[idx]=true;
    }
    if(flag==false) cout << "no" << endl;
    else cout << "yes" << endl;
    return 0;
}