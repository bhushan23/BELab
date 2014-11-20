#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int modInverse(int a,int b){
    int x0 = 0,x1 = 1;
    int b0 = b;
    int q,t;
    if(b==1)
        return 1;
    while(a>1){
        q = a/b;
        t = b;
        b = a%b;
        a = t;
        t = x0, x0 = x1 - q*x0, x1 = t;
    }
    if(x1 < 0)
        x1+=b0;
    return x1;    
}

/*
pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    if(a == 0) return make_pair(b, make_pair(0, 1));
    pair<int, pair<int, int> > p;
    p = extendedEuclid(b % a, a);
    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}
int modInverse(int a, int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}
*/

int computeMulti(int n,int* ar){
    int max;
    for(int i=0;i<15;++i){
        ar[i] = 0;
        if( (pow(2,i) - n ) > 0 ){
            max = i;
            break;
        }   
    }    
    ar[max] = -1;
    
    for(int i = max-1; i >= 0; --i){
        if( ( n - pow(2,i)) >= 0 ){
             ar[i] = 1;
             n = n - pow(2,i);
        }    
    }
return max;        
}   
int mod(int a,int b){
    int ans = a%b;
    if(ans < 0)
        ans = b + ans;
return ans;
}

int computeG(int x,int y,int x1,int y1,int a,int &x3, int &y3,int p){
      int lam;
       if(x==x1 && y == y1){
            lam = ((3*x*x+a)/2) * (modInverse(y,p));
       }else{
            lam = abs((y1-y))*modInverse(abs(x1-x),p);
       }
       x3 = lam*lam - x - x1 ;
       x3 = mod(x3,p);
       
       y3 = lam*(x - x3) - y; 
       y3 = mod(y3, p);
       
      // cout<<"\ninside " << x3 <<","<<y3;       
}

int computeGSame(int x,int y,int &x3,int &y3,int a,int max,int *ar,int p){
    int Gx[15],Gy[15];
    int ans = 0;
    int x1,y1,x2,y2;
    for(int i=0; i< 15;++i){
        Gx[i] = Gy[i] = -1;
    }
    Gx[0] = x;
    Gy[0] = y;
   // cout<<"\nCOmputing G:";
    for(int i=1; i < max; ++i){
          computeG(Gx[i-1],Gy[i-1],Gx[i-1],Gy[i-1],a,x3,y3,p);
          Gx[i] = x3;
          Gy[i] = y3;  
      //    cout<<"\n" << pow(2,i) <<"G "<<x3<<","<<y3; 
    }
    // cout<<"\nCOmputing G DONE:";
    int i = 0;
    while(!ar[i])
        ++i;
    x1 = Gx[i];
    y1 = Gy[i];
    ans = pow(2,i);
    ++i;
    
    for(; ar[i] != -1; ++i ){
       // cout << "\nAdding: "<<i<<"G and ";
        while(!ar[i])
            ++i;
        x2 = Gx[i];
        y2 = Gy[i];
        //cout<<i<<"G:";
        ans += pow(2,i);
        computeG(x1,y1,x2,y2,a,x3,y3,p);
        x1=x3;
        y1=y3;
        //cout << "\n "<<ans<<"G ("<< x1 <<","<<y1 <<")";    
    }
    
}
void clearAr(int* ar, int max){
    for(int i =0; i <= max; ++i)
        ar[i] = 0;
}
int main(){
    int na,nb,max;
    int ar[15],pax,pay,pbx,pby,pasx,pasy,pbsx,pbsy,a,p;
    na = 121;
    nb = 203;
    a=0;
    p =211;
    max=computeMulti(na,ar);   
    computeGSame(2,2,pax,pay,a,max,ar,p); 
    cout<<"\nPublic key PA: " << pax << " " << pay; 
    clearAr(ar,max);
    max=computeMulti(nb,ar);  
    computeGSame(2,2,pbx,pby,a,max,ar,p); 
    cout<<"\nPublic key PB: " << pbx << " " << pby;
    
     clearAr(ar,max);
    max=computeMulti(na,ar);  
    computeGSame(pbx,pby,pasx,pasy,a,max,ar,p); 
    cout<<"\nSecret key PA: " << pasx << " " << pasy;
    
   clearAr(ar,max);
    max=computeMulti(nb,ar);  
    computeGSame(pax,pay,pbsx,pbsy,a,max,ar,p); 
    cout<<"\nSecret key PB: " << pbsx << " " << pbsy;
    
    return 0;
}
