#include <bits/stdc++.h>
using namespace std;

int main(){
    double ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    double mid1, mid2;

    for(int i=0; i<10000; i++){
        double m1x=ax*2/3+bx/3;
        double m1y=ay*2/3+by/3;
        double m2x=ax/3+bx*2/3;
        double m2y=ay/3+by*2/3;
        double k1x=cx*2/3+dx/3;
        double k1y=cy*2/3+dy/3;
        double k2x=cx/3+dx*2/3;
        double k2y=cy/3+dy*2/3;

        mid1=(m1x-k1x)*(m1x-k1x)+(m1y-k1y)*(m1y-k1y);
        mid2=(m2x-k2x)*(m2x-k2x)+(m2y-k2y)*(m2y-k2y);
        
        if(mid1<mid2){
            bx=m2x;
            by=m2y;
            dx=k2x;
            dy=k2y;
        }
        else{
            ax=m1x;
            ay=m1y;
            cx=k1x;
            cy=k1y;
        }
    }
    cout << fixed;
    cout.precision(7);
    cout << min(sqrt(mid1), sqrt(mid2));
    return 0;
}