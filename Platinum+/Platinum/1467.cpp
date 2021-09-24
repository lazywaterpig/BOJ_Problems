#include <bits/stdc++.h>
#define N(i) num[i]-48 // ascii -> numbers
using namespace std;

int dp[10][1002]; // 뒤에서부터 앞으로 prefix sum ---(1)

int main(){
    int cnt[10]={0}, tmp[10]={0}, sum, sz;
    string num, num_del, ans=""; cin >> num >> num_del;
    sz=num.size();
    for(auto i : num_del) cnt[i-48]++;
    memset(dp, 0, sizeof(dp)); // ---(1) start
    for(int i=0; i<sz; i++) dp[N(i)][i]=1;
    for(int t=0; t<10; t++){
        for(int i=sz-2; i>-1; i--) dp[t][i]+=dp[t][i+1];
    } // ---(1) end

    for(int i=0; i<sz; i++){
        int piv=i;
        int maxv=-1, maxi=i; // 가능한 가장 큰 값과 그 위치
        sum=0;
        for(int j=0; j<10; j++){
            tmp[j]=cnt[j];
            sum+=cnt[j];
        }
        if(sum==sz-i) break; // 더이상 남길 숫자가 없으면 break

        while(1){
            if(dp[N(piv)][piv]!=tmp[N(piv)] && N(piv)>maxv){
            // 현재 원소를 무조건 출력하지 않아야하는 경우가 아닌지 && 현재 원소가 지금까지의 가장 큰 값보다 큰지
                maxv=N(piv); // 가능한 가장 큰 값과 그 위치 update
                maxi=piv;
            }

            if(tmp[N(piv)]==0) break; // 더이상 원소를 출력하지 않을 수 없을 때 break ---(2)

            tmp[N(piv)]--; // ---(2)가 아닌 경우 원소를 지우는 현재 원소를 지운다 가정, 계속 진행
            piv++;
        }

        for(int j=i; j<maxi; j++) cnt[N(j)]--;
        ans+=num[maxi]; // 최종 결과를 최댓값으로 만들어줄 원소의 위치에 해당하는 원소 append
        i=maxi; // 현재까지 처리해준 곳으로 i 이동
    }

    cout << ans;
    return 0;
}