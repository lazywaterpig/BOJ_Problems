#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
#define piii pair<pii,int>
using namespace std;

int t[500005]; //type
int cnt[500005]={0};
int arr[500005][2];

bool includes(pii a, pii b){ // ax<=bx<=by<=ay
    if(a.first<=b.first && b.second<=a.second) return true;
    return false;
}

bool cmp(piii a, piii b){
    if(a.first.first!=b.first.first) return a.first.first<b.first.first;
    else if(a.first.second!=b.first.second) return a.first.second>b.first.second;
    else return a.second<b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<piii> v;

    for(int i=1; i<=m; i++){
        cin >> arr[i][0] >> arr[i][1];
        if(arr[i][0]<arr[i][1]){
            v.push_back({{arr[i][0],arr[i][1]}, i});
            v.push_back({{arr[i][0]+1e9,arr[i][1]+1e9}, i});
            t[i]=2;
        }
        else{
            v.push_back({{arr[i][0],arr[i][1]+1e9}, i});
            t[i]=1;
        }
    }

    sort(v.begin(), v.end(), cmp);
    piii cur=v[0];
    for(int i=1; i<v.size(); i++){
        if(includes(cur.first,v[i].first)){
            continue;
        }
        else if(includes(v[i].first,cur.first)){
            cur=v[i];
        }
        else{
            cnt[cur.second]++;
            cur=v[i];
        }
    }
    cnt[cur.second]++;

    for(int i=1; i<=m; i++){
        if(cnt[i]==t[i]) cout << i << ' ';
    }
    return 0;
}