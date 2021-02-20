#include <bits/stdc++.h>
using namespace std;

double dist(double dx, double dy){
	return dx*dx+dy*dy;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(6);

	int n, i, j;
	double point[101][2];
	double x=0, y=0;

    cin >> n;
	for(i=0; i<n; i++){
		cin >> point[i][0] >> point[i][1];
		x+=point[i][0];
		y+=point[i][1];
	}
	x/=n; y/=n;
	
	double GraD=0.1, maxg, tmp;
	for(i=0; i<100000; i++){
		int maxp=0;
		maxg=dist(x-point[0][0], y-point[0][1]);
		for(j=1; j<n; j++) {
			tmp=dist(x-point[j][0], y-point[j][1]);
			if(maxg<tmp) {
                maxg=tmp;
                maxp=j;
            }
		}
		x+=(point[maxp][0]-x)*GraD;
		y+=(point[maxp][1]-y)*GraD;
		GraD*=0.999;
	}
	cout << x << ' ' << y << ' ' << sqrt(maxg);
	return 0;
}