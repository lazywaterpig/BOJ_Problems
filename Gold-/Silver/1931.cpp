#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> v;

bool cmp(pair <int,int> a, pair <int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    v.resize(n);

    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    int bound=0, cnt=0, piv=0;
    while(piv<n){
        if(v[piv].first>=bound){
            cnt++;
            bound=v[piv].second;
        }
        piv++;
    }
    cout << cnt << endl;
    return 0;
}

