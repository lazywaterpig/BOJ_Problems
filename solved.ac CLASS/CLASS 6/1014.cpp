#include <bits/stdc++.h>
using namespace std;

bool poss(int bit){
    int flag=0;
    while(bit!=0){
        if(flag==1 && bit%2==1) return false;

        flag=bit%2;
        bit/=2;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
    	int n, m;
    	int arr[11]={0};
    	char c;
    	cin >> n >> m;
    	for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
            	cin >> c;
            	if(c!='x') arr[j]++;
        	}
    	}
    	int bit, maxv=0, cnt;
		for(bit=1; bit<(1<<m); bit++){
    	    if(poss(bit)){
        	    cnt=0;
        	    int tbit=bit;
        	    for(int i=0; i<m; i++){
                	if(tbit%2!=0){
                		cnt+=arr[m-1-i];
                	}
                	tbit/=2;
            	}
        	    if(cnt>maxv){
        	    	maxv=cnt;
        	    }
    	    }
	    }
    	cout << maxv << endl;
    }
    return 0;
}