#include <bits/stdc++.h>
using namespace std;

int arr[502][502];
int mp[502][502];
int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
vector <pair <int,int>> v;

bool cmp(pair <int, int> a, pair <int, int> b){
    return a.first>b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, n, m;
    cin >> n >> m;
    i=n*m+1;
    v.resize(i);
    memset(arr, 0, sizeof(arr));
    memset(mp, 0, sizeof(arr));

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cin >> arr[i][j];
            v[(i-1)*m+j].first=arr[i][j];
            v[(i-1)*m+j].second=i*1000+j;
        }
    }

    sort(v.begin(), v.end(), cmp);
    mp[1][1]=1;
    int minh=arr[n][m], tx, ty;
    i=0;
    while(v[i].first>minh){
        for(j=0; j<4; j++){
            tx=v[i].second/1000;
            ty=v[i].second%1000;
            if((tx+dx[j]>0 && ty+dy[j]>0) && (tx+dx[j]<=n && ty+dy[j]<=m)){
                if(arr[tx][ty]>arr[tx+dx[j]][ty+dy[j]]) mp[tx+dx[j]][ty+dy[j]]+=mp[tx][ty];
            }
        }
        i++;
    }
    cout << mp[n][m] << endl;
    return 0;
}