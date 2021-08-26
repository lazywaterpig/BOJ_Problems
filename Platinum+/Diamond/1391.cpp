#include <bits/stdc++.h>
using namespace std;

//#define swap(a, b, tmp) {tmp=a; a=b; b=tmp;}

bool isCross(int x, int y, int boundx, int boundy){
    /*int tmp; 
    if(x>y) swap(x, y, tmp);
    if(boundx>boundy) swap(boundx, boundy, tmp); */
    if(x>boundx){
        if(boundy>x && boundy<y) return true;
    }
    else{
        if(y>boundx && y<boundy) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int i, arr[2001], buf1, buf2, flag=0;
        for(i=1; i<n+1; i++) cin >> arr[i];

        vector <pair<int,int>> border[2];
        int updown=0; //up=0 down=1

        for(i=1; i<n; i++){
            buf1=min(arr[i], arr[i+1]);
            buf2=max(arr[i], arr[i+1]);
            for(int j=0; j<border[updown].size(); j++){
                if(isCross(buf1, buf2, border[updown][j].first, border[updown][j].second)){ flag=1; break; }
            }
            if(flag==1) break;
            border[updown].push_back({buf1, buf2});
            updown^=1;
        }

        if(flag==1) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}