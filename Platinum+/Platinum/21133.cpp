#include <bits/stdc++.h>
using namespace std;

#define SMALL 10

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    if(n<SMALL){
        if(n==4) cout << "2\n4\n1\n3\n";
        if(n==5) cout << "1\n3\n5\n2\n4\n";
        if(n==6) cout << "2\n4\n6\n1\n3\n5\n";
        if(n==7) cout << "1\n3\n5\n7\n2\n4\n6\n";
        if(n==8) cout << "4\n6\n8\n2\n7\n1\n3\n5\n";
        if(n==9) cout << "4\n7\n9\n2\n5\n8\n1\n3\n6\n";
    }
    else{
        if(n%2==0){
            if(n%3<2){
                for(int i=0; i<n/2; i++) cout << 2*i+2 << '\n';
                for(int i=0; i<n/2; i++) cout << 2*i+1 << '\n';
            }
            else{
            	if(n==14){
                	for(int i=0; i<n/2-3; i++) cout << 2*i+3 << '\n';
                	cout << "4\n" << n-1 << "\n1\n" << n << "\n2\n" << n-3 << '\n';
                	for(int i=0; i<n/2-3; i++) cout << 2*i+6 << '\n';
            	}
            	else if(n==20){
            		for(int i=0; i<n/2; i++) cout << 2*i+2 << '\n';
                    cout << "3\n1\n7\n9\n11\n13\n15\n17\n19\n5\n";
            	}
            	else{
            		cout << "1\n4\n6\n8\n10\n" << n-1 << '\n';
                	for(int i=0; i<n/2-6; i++) cout << 2*i+14 << '\n';
                	for(int i=0; i<n/2-2; i++) cout << 2*i+3 << '\n';
            		cout << "12\n2\n";
            	}
            }
        }
        else{
            if(n%3!=0){
                for(int i=0; i<n/2+1; i++) cout << 2*i+1 << '\n';
                for(int i=0; i<n/2; i++) cout << 2*i+2 << '\n';
            }
            else{
                cout << "2\n4\n6\n" << n << '\n';
                for(int i=0; i<n/2-4; i++) cout << 2*i+10 << '\n';
                for(int i=0; i<n/2-1; i++) cout << 2*i+3 << '\n';
                cout << "8\n1\n";
            }
        }
    }
    return 0;
}