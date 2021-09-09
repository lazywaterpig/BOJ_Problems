#include <bits/stdc++.h>
#define MAX 151
#define endl "\n"
using namespace std;

typedef pair<int,int> pii;
typedef pair<pair<int,pair<int,int>>,pair<int,int>> ppp;

int r, c, k;
char arr[MAX][MAX];
char mov[10]={'U','R','D','L','U','R','D','L','U','R'}; // 3~6 에서 시작
vector<pii> depth[MAX][MAX];

pii d(char c){
    if(c=='U') return {-1, 0};
    else if(c=='R') return {0, 1};
    else if(c=='D') return {1, 0};
    else return {0, -1};
}

bool OOB(int x, int y){
    if(x>=0 && y>=0 && x<r && y<c) return false;
    return true;
}

bool OOK(int myx, int myy, int x, int y){
    if(x>=myx && y>=myy) return true;
    if(x+(y-myy)/3>=myx && y-((y-myy)/3)*3>=myy) return true; //myy>y
    if(y+(x-myx)/3>=myy && x-((x-myx)/3)*3>=myx) return true; //myx>x
    return false;
}

void dijkstra(){
    priority_queue <ppp> pq;
    pq.push({{k+k,{k,k}},{0,0}});
    depth[0][0].push_back({k,k});
    int flag=0, inflag=0, idx;
    while(!pq.empty()){
        int nowsum=pq.top().first.first;
        int nowL=pq.top().first.second.first;
        int nowR=pq.top().first.second.second;
        int nowx=pq.top().second.first;
        int nowy=pq.top().second.second;
        pq.pop();
        flag=0;
        for(int i=0; i<depth[nowx][nowy].size(); i++){
            if(OOK(nowL, nowR, depth[nowx][nowy][i].first, depth[nowx][nowy][i].second)){
                flag=1; break;
            }
            if(OOK(depth[nowx][nowy][i].first, depth[nowx][nowy][i].second, nowL, nowR)){
                depth[nowx][nowy].erase(depth[nowx][nowy].begin()+i);
                i--;
            }
        }
        if(flag==1) continue;
        idx=3;
        while(idx<7){
            if(mov[idx]==arr[nowx][nowy]) break;
        }

        for(int i=-3; i<4; i++){
            pii next=d(mov[idx+i]);
            next.first+=nowx;
            next.second+=nowy;
            if(OOB(next.first, next.second)) continue;

            int nextL=nowL, nextR=nowR;
            if(i<0) nextL+=i;
            else nextR-=i;
            int inflag=0;
            for(int j=0; j<depth[next.first][next.second].size(); j++){
                if(OOK(nextL, nextR, depth[next.first][next.second][j].first, depth[next.first][next.second][j].second)){
                    inflag=1; break;
                }
            }
            if(inflag==1) continue;

            pq.push({{nextL+nextR, {nextL, nextR}},{next.first, next.second}});
            depth[next.first][next.second].push_back({nextL, nextR});
            for(int j=0; j<depth[next.first][next.second].size()-1; j++){
                if(OOK(depth[next.first][next.second][j].first, depth[nowx][nowy][j].second, nextL, nextR)){
                    depth[next.first][next.second].erase(depth[next.first][next.second].begin()+j);
                    j--;
                }
            }
        }

    }

    if(depth[r-1][c-1].size()!=0) cout << "Yes";
    else cout << "No";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;

    for(int i=0; i<r; i++){
        string ord; cin >> ord;
        for(int j=0; j<c; j++) arr[i][j]=ord[j];
    }

    dijkstra();

    return 0;
}