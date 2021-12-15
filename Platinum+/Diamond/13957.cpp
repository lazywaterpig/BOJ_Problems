#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fixed;
    cout.precision(6);

    int n, tmp, sum=0; cin >> n;
    int arr[21];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    double x, y; cin >> x >> y;
    if(x==0) x=0.000001;
    if(y==0) y=0.000001;

    if(x*x+y*y>=sum*sum){
        double theta=(x>=0?atan(y/x):M_PI-atan(y/x));
        double curx=0, cury=0;
        for(int i=0; i<n; i++){
            curx+=(double)arr[i]*cos(theta);
            cury+=(double)arr[i]*sin(theta);
            cout << curx << ' ' << (x>=0?cury:-cury) << endl;
        }
    }
    else{
        int mind=sum, minv, cur, sz=(1<<n), cnt;
        for(int i=1; i<sz; i++){
            tmp=i;
            cur=0, cnt=0;
            while(tmp){
                if(tmp%2) cur+=arr[cnt];
                tmp>>=1;
                cnt++;
            }
            if(abs(cur-(sum/2))<abs(mind-(sum/2))){
                mind=cur;
                minv=i;
            }
        }
        
        if(x==0 && y==0){
            double curx=0;
            for(int i=0; i<n; i++){
                curx+=arr[i]*((double)(minv%2)-0.5)*2;
                cout << curx << ' ' << 0 << endl;
                minv>>=1;
            }
        }
        
	    double r1=mind, r2=sum-mind;
	    
		if(x*x+y*y<=(r1-r2)*(r1-r2)){
			double t[2]={(x>=0?atan(y/x):M_PI-atan(y/x)), (x>=0?atan(y/x):M_PI-atan(y/x))+M_PI};
			if(r1>r2) swap(t[0], t[1]);
	        double curx=0, cury=0;
	        for(int i=0; i<n; i++){
	            curx+=(double)arr[i]*cos(t[minv%2]);
	            cury+=(double)arr[i]*sin(t[minv%2]);
	            cout << curx << ' ' << (x>=0?cury:-cury) << endl;
	            minv>>=1;
	        }
	    }
        else{
	        double a=(r1*r1-r2*r2+x*x+y*y)/(2*sqrt(x*x+y*y));
	        double b=(-r1*r1+r2*r2+x*x+y*y)/(2*sqrt(x*x+y*y));
	        double theta1=acos(a/r1);
	        double theta2=acos(b/r2);
	        double theta3=(x>=0?atan(y/x):M_PI-atan(y/x));
	        double t[2]={2*M_PI-theta2+theta3, theta1+theta3};
	        
	        //cout << sum << ' ' << r1 << ' ' << r2 << ' ' << a << ' ' << b << endl;
	        //cout << theta1 << ' ' << theta2 << ' ' << theta3 << endl;
	        //cout << t[0] << ' ' << t[1] << endl;

	        double curx=0, cury=0;
	        for(int i=0; i<n; i++){
	        	curx+=(double)arr[i]*cos(t[minv%2]);
	            cury+=(double)arr[i]*sin(t[minv%2]);
	            cout << curx << ' ' << (x>=0?cury:-cury) << endl;
	            minv>>=1;
	        }
        }
    }

    return 0;
}