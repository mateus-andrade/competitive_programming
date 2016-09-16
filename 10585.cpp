#define EPS 0.0001

#include <bits/stdc++.h>
#define ll long long

using namespace std;

typedef struct _Ponto{

    double x;
    double y;
} Ponto;

Ponto ponto_medio(Ponto a, Ponto b){
    Ponto m;
    m.x = (a.x + b.x)/2;
    m.y = (a.y + b.y)/2;
    return m;
}

bool equals(double a, double b){
    return fabs(a-b) < EPS;
}

bool operator==(const Ponto& a, const Ponto& b){
    return equals(a.x,b.x) && equals(a.y, b.y);
}

int main()
{

    int t,n,qp;
    double x,y,sumx,sumy;
    bool sym, resp;
    Ponto p, pm;
    vector<Ponto> ps;

    scanf("%d",&t);

    while(t--){
        qp = 0;
        resp = true;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%lf %lf",&x,&y);
            p.x = x; p.y = y;
            ps.push_back(p);
        }
       sumx = sumy = 0;
       for(int i=0; i<n; i++){
            sumx += ps[i].x; sumy += ps[i].y;
       }
       pm.x = sumx/(double)n; pm.y = sumy/(double)n;

       for(int i=0; i<n; i++){
        sym= false;
        for(int j=i+1; j<n; j++){
            if(ponto_medio(ps[i],ps[j]) == pm){
                qp++;
                sym = true;
                break;
            }
         }
         if(qp == n/2){
            resp = true;
            break;
         }
         if(!sym){
            resp = false;
            break;
         }
       }
       resp? printf("yes\n") : printf("no\n");
    }


    return 0;
}
