#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A[101]={0}, B[101]={0};
    int tA[101], tB[101];

    int n; cin >> n;

    int ai, bi;
    int apiv, bpiv, cnt, maxv, tmp;
    for(int i=0; i<n; i++){
        cin >> ai >> bi;
        A[ai]++; B[bi]++;

        for(int j=1; j<=100; j++){
            tA[j]=A[j];
            tB[j]=B[j];
        }

        maxv=0; cnt=0; apiv=1; bpiv=100;
        while(cnt<i+1){
            while(tA[apiv]==0) apiv++;
            while(tB[bpiv]==0) bpiv--;
            if(maxv<apiv+bpiv) maxv=apiv+bpiv;
            tmp=min(tA[apiv], tB[bpiv]);
            cnt+=tmp;
            tA[apiv]-=tmp;
            tB[bpiv]-=tmp;
        }

        cout << maxv << endl;
    }
    return 0;
}