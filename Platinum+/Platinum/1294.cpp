#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<string> v;
    string ord;
    int cnt=0;
    for(int i=0; i<n; i++){
        cin >> ord;
        v.push_back(ord);
        cnt+=ord.size();
    }
/*
    int bound[21]={0}, piv[21]={0};
    int len_res=0, mini, minv, lastv, min_size;

    while(len_res<cnt){
        for(int i=0; i<n; i++) piv[i]=bound[i];
        minv='Z'+1;
        lastv='Z'+1;
        min_size=1001;
        for(int i=0; i<n; i++){
            if(piv[i]<v[i].size()){
                if(minv>v[i][piv[i]]){
                    minv=v[i][piv[i]];
                    while(piv[i]<v[i].size() && piv[i] v[i][piv[i]]==minv) piv[i]++;

                    
                }
            }
        }
    }*/

    cout << ans;
    return 0;
}