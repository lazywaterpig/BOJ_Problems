#include <bits/stdc++.h>
using namespace std;

double n, p, s, v, a, b, c, d;

double val(double cc){
    return (a*pow(b, cc*c))/1e9 + d*(cc+1)/cc;
}

int main(){
    cin >> n >> p >> s >> v;
    
    a=n/p;
    b=log2(n);
    c=sqrt(2);
    d=s/v;
    
    double minv=0, maxv=1e18;

    for(int i=0; i<10000; i++){
        double l=(2*minv+maxv)/3, r=(minv+2*maxv)/3;
        //cout << l << ' ' << r << endl;
		//cout << val(l) << ' ' << val(r) << endl; 
        if(val(l)>val(r)) minv=l;
        else maxv=r;
    }
    cout << fixed;
    cout.precision(10);
    cout << val(minv) << ' ' << minv << endl;
    return 0;
}