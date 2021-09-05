#include <bits/stdc++.h>
using namespace std;

int arr[100002][2];

bool cmpf(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

bool cmps(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int buf1, buf2;
    vector <pair<int,int>> f, s, v1, v2;
    for(int i=0; i<n; i++){
        cin >> buf1 >> buf2;
        f.push_back({buf1, buf2});
    }

    sort(f.begin(), f.end(), cmpf);
    for(int i=0; i<n; i++){
        s.push_back({i, f[i].second});
    }

    sort(s.begin(), s.end(), cmps);
    for(int i=0; i<n; i++){
        v1.push_back({s[i].first, i});
        v2.push_back({s[i].first, i});
    }

    sort(v1.begin(), v1.end(), cmpf);
    for(int i=0; i<n; i++){
        arr[i][0]=v1[i].second;
        arr[i][1]=v2[i].first;
    }

/*
    int maxv=-1, cnt;
    int i=0, piv, flag, bound[2];
    bound[0]=bound[1]=-1;
    while(i<n){
        cnt=1;
        flag=1;
        while(1){
            piv=arr[i][(flag+1)%2];
            while(piv>bound[flag]){
                if(arr[piv][flag]>i) break;
                piv--;
            }
            if(piv==bound[flag]) break;

            cnt++;
            flag=(flag+1)%2;
            bound[flag]=i;
            i=piv;
        }

        if(cnt>maxv) maxv=cnt;
        bound[0]=bound[1]=max(i, arr[i][(flag+1)%2]);
        i++;
    }*/

    int maxv=-1, cnt;
    int i=0, piv, flag, bound[2];
    int piv_tmp, bound_tmp[2];
    int inflag=0;
    while(i<n){
        while(i<n && arr[i][0]>arr[i][1]) i++;
        if(i==n) break;
        cnt=1;
        flag=1;
        bound[0]=i;
        bound[1]=arr[i][(flag+1)%2];
        while(1){
            piv=i;
            while(piv<bound[flag]){
                inflag=0;
                if(arr[piv][flag]>i){
                    piv_tmp=piv;
                    bound_tmp[flag]=piv;
                    bound_tmp[(flag+1)%2]=arr[piv][(flag+1)%2];
                    while(piv_tmp<bound_tmp[(flag+1)%2]){
                        if(arr[piv_tmp][(flag+1)%2]>piv) inflag=1;
                        piv_tmp++;
                    }
                }
                if(inflag==1) break;
                piv++;
            }

            if(inflag==0){
                while(piv<bound[flag]){
                    if(arr[piv][flag]>i){
                        cnt++;
                        flag=(flag+1)%2;
                        bound[flag]=i;
                        i=piv;
                        break;
                    }
                }

                break;
            }

            cnt++;
            flag=(flag+1)%2;
            bound[flag]=i;
            i=piv;
        }

        if(cnt>maxv) maxv=cnt;
        bound[0]=bound[1]=max(i, arr[i][(flag+1)%2]);
        i++;
    }

    cout << maxv;
    return 0;
}