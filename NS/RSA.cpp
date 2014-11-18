#include <iostream>
using namespace std;
int fn,PlainText,CipherText,d,e,n;

bool isPrime(int n){
int i;
for(i = 2; i <= n/2; ++i){
    if(n % i == 0)
        return false;
}
return true;
}

int GCD(int a,int b){
	int temp;
	while(b)
	{
		temp = a%b;
		a=b;
		b=temp;
	}
	return a;
}
void encrypt()
{
	int i;
	CipherText = 1;
	for(i=0;i< e;i++)
		CipherText=CipherText*PlainText%n;
	CipherText = CipherText%n;
	cout << "\nEncrypted text is : "<<CipherText;
}

void decrypt()
{
	int i;
	PlainText = 1;
	for(i=0;i<d;i++)
		PlainText=PlainText*CipherText%n;
	PlainText = PlainText%n;
	cout<<"\nPlain text is : " << PlainText << "\n";
}
int main(){
int p,q,val,s;
do{
cout<< "Enter Prime No. P and Q : ";
cin >> p >> q;
}while( !isPrime(p) && !isPrime(q) );

n = p * q;
fn = (p-1) * (q-1);

do{
cout << "Enter e :";
cin >> e;
val = GCD(fn,e);
}while(val != 1);

d = 1;
do
{
	s = (d*e)%fn;
	d++;
}while(s!=1);
d = d-1;

cout << "Enter Plain Text";
cin >> PlainText;
encrypt();
decrypt();

}
