#include <iostream>
#include <math.h>
using namespace std;
int main(){
int p,a,b,x,y,g,ka,kb;
cout << "Enter P and G: ";
cin >> p >> g;
cout << "Enter a and b: ";
cin >> a >> b;
x = (int) (pow(g,a)) % p;
y = (int) (pow(g,b)) % p;

ka = (int) (pow(y,a)) % p;
kb = (int) (pow(x,b)) % p;

cout << "Symmetric Key : " << ka << "\n" ; 

}
