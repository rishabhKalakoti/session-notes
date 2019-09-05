#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define sc(a) scanf("%lli",&a)

double modulous(double a,double b,double c){return sqrt(a*a+b*b+c*c);}
double min_d(double a,double b){if(a<b) return a;return b;}
int main() {
    ll T;
    sc(T);
    while(T--)
    {
        // input
        ll Px,Py,Pz;
        sc(Px);sc(Py);sc(Pz);
        ll Qx,Qy,Qz;
        sc(Qx);sc(Qy);sc(Qz);
        ll dx,dy,dz;
        sc(dx);sc(dy);sc(dz);
        ll cx,cy,cz,R;
        sc(cx);sc(cy);sc(cz);sc(R);
        // binary search
        double t=1000000000.0,low=0.0,high=1000000000.0;
        double mid=(low+high)/2.0;
        while(high-low>=0.0000001)
        {
            mid=(low+high)/2.0;
            double Qtx,Qty,Qtz;
            Qtx=Qx+mid*dx; Qty=Qy+mid*dy; Qtz=Qz+mid*dz;
            double dis=modulous(
                ((cy-Py)*1.0)*(Qtz-Pz*1.0)-((cz-Pz)*1.0)*(Qty-Py*1.0),
                ((cz-Pz)*1.0)*(Qtx-Px*1.0)-((cx-Px)*1.0)*(Qtz-Pz*1.0),
                ((cx-Px)*1.0)*(Qty-Py*1.0)-((cy-Py)*1.0)*(Qtx-Px*1.0));
            dis=dis/modulous(Qtx-Px*1.0,Qty-Py*1.0,Qtz-Pz*1.0);
            if(dis>=R)
            {
                t=min_d(t,mid);
                high=mid;
            }
            else
            {
                low=mid;
            }
        }
        printf("%.8lf\n",t);
    }
   return 0;
}
