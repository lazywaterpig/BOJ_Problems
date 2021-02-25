#include <bits/stdc++.h>
using namespace std;

int arr[501][501];
int day[501][501];
int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
vector <pair <int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, n, maxd=1;
    cin >> n;
    i=n*n+1;
    v.resize(i);
    memset(day, 0, sizeof(day));

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin >> arr[i][j];
            v[n*i+j].first=arr[i][j];
            v[n*i+j].second=i*1000+j;
        }
    }

    sort(v.begin(), v.end());
    int tx, ty;

    for(i=0; i<n*n; i++){
        tx=v[i].second/1000;
        ty=v[i].second%1000;
        if(day[tx][ty]==0) day[tx][ty]++;

        for(j=0; j<4; j++){
            if((tx+dx[j]>=0 && ty+dy[j]>=0) && (tx+dx[j]<n && ty+dy[j]<n)){
                if(arr[tx][ty]<arr[tx+dx[j]][ty+dy[j]] && day[tx][ty]>=day[tx+dx[j]][ty+dy[j]]){
                    day[tx+dx[j]][ty+dy[j]]=day[tx][ty]+1;
                    if(day[tx+dx[j]][ty+dy[j]]>maxd) maxd=day[tx+dx[j]][ty+dy[j]];
                }
            }
        }
    }
    cout << maxd << endl;
    return 0;
}