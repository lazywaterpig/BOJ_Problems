#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
	int n, m;
    scanf("%d %d", &n, &m);
    n+=m-1;
    m-=1;

    int arr[401];
    for(int i=1; i<=n-m; i++) arr[i]=1;
    for(int i=n-m+1; i<=n; i++) arr[i]=i;
    for(int i=1; i<=m; i++){
        int tmp=i;
        for(int j=n; j>n-m; j--){
            if(tmp==1) break;
            if(__gcd(arr[j], tmp)!=1){
                int val=__gcd(arr[j], tmp);
                arr[j]/=val;
                tmp/=val;
            }
        }
    }

    ll ans=1;
    for(int i=1; i<=n; i++) ans=(ans*arr[i])%1000000000;
    printf("%lld\n", ans);

    return 0;
}

/* 더 좋은 코드 by hansc0320
#include <stdio.h>

int N, K, D[201];

int main(void)
{
	scanf("%d %d", &N, &K);

	D[0] = 1;

	for (int i = 1; i <= K; i++)
		for (int j = 1; j <= N; j++)
			D[j] = (D[j] + D[j - 1]) % (int)1e9;

	printf("%d\n", D[N]);

	return 0;
}
*/