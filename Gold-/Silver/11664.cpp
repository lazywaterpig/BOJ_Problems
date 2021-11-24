#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main(){
    double ax, ay, az, bx, by, bz, cx, cy, cz;
    cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;
    double mid1, mid2;

    for(int i=0; i<10000; i++){
        double x1=ax*2/3+bx/3;
        double x2=ax/3+bx*2/3;
        double y1=ay*2/3+by/3;
        double y2=ay/3+by*2/3;
        double z1=az*2/3+bz/3;
        double z2=az/3+bz*2/3;

        mid1=(x1-cx)*(x1-cx)+(y1-cy)*(y1-cy)+(z1-cz)*(z1-cz);
        mid2=(x2-cx)*(x2-cx)+(y2-cy)*(y2-cy)+(z2-cz)*(z2-cz);

        if(mid1<mid2){
            bx=x2;
            by=y2;
            bz=z2;
        }
        else{
            ax=x1;
            ay=y1;
            az=z1;
        }
    }

    cout << fixed;
    cout.precision(7);
    cout << min(sqrt(mid1), sqrt(mid2));
    return 0;
}