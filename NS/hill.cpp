#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#define DECAPLHA(X) (X-65)
#define INCALPHA(X) (X+65)
using namespace std;
void matrix_mul(int k[2][2],int p[1][2],int mul[1][2]){
    int ans;
    for (int j = 0; j < 2; ++j){
        ans = 0;
        for(int i = 0; i < 2; ++i){
            ans += p[0][i] * k[i][j];
        }
        mul[0][j] = ans % 26;
    }    
}
void print_ar(int ar[1][2], int row, int col){
    for(int i = 0; i < row; ++i){
        for( int j = 0;  j < col; ++j){
            cout << ar[i][j] <<" ";
        }
        cout <<"\n";
    }
}
pair<int, pair<int, int> > extendedEuclid(int a, int b) {
    if(a == 0) return make_pair(b, make_pair(0, 1));
    pair<int, pair<int, int> > p;
    p = extendedEuclid(b % a, a);
    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}
int modInverse(int a, int m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}
void computeKIn(int kIn[2][2],int k[2][2]){
    int isNeg = 1;
    int multiIn = k[0][0]*k[1][1] - k[0][1]*k[1][0];
    if( multiIn < 0 ){
        isNeg = -1;
        multiIn *= -1;
    }
    kIn[0][0] = k[1][1];
    kIn[0][1] = -k[0][1];
    kIn[1][0] = -k[1][0];
    kIn[1][1] = k[0][0];

    multiIn = modInverse(multiIn,26);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j){
		    kIn[i][j] = (kIn[i][j]*multiIn*isNeg) % 26;	
		    if(kIn[i][j] < 0)
		        kIn[i][j] = 26 + kIn[i][j];
		}		
	}
}
void hill_encry(int k[2][2],int p[1][2],int enc[1][2]){
    matrix_mul(k,p,enc);    
}
void hill_decry(int k[2][2],int c[1][2],int dec[1][2]){
    int kIn[2][2]; 
    computeKIn(kIn,k);         
    matrix_mul(kIn,c,dec);
}
int main(){
    int k[2][2] = { 3 , 7 , 15 ,12 };
    int p[1][2],enc[1][2],dec[1][2];
    char encMsg[1000],decMsg[1000],input[1000];
    scanf("%[^\n]s",input);
    cout<<"Enter Key Matrix: \n";
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            cin >> k[i][j];    
        }
    }
    if(strlen(input)%2 != 0)
        strcat(input,"X");
    int j = 0; 
    for(int i = 0; i < strlen(input); ++i){
        while(input[i]==' ')
            ++i;
        p[0][0] = DECAPLHA(input[i++]);
        while(input[i]==' ')
            ++i;
        p[0][1] = DECAPLHA(input[i]);
            
        hill_encry(k,p,enc);
        encMsg[j++] = INCALPHA(enc[0][0]);
        encMsg[j++] = INCALPHA(enc[0][1]);
    }
    encMsg[j]='\0';
    cout<<"Encrypted Msg: "<<encMsg;
    int i,len = j;
      for(i = 0; i < len; ++i){
        p[0][0] = DECAPLHA(encMsg[i]);
        p[0][1] = DECAPLHA(encMsg[i+1]);
            
        hill_decry(k,p,dec);
        decMsg[i++] = INCALPHA(dec[0][0]);
        decMsg[i] = INCALPHA(dec[0][1]);
    }
    decMsg[i]='\0';
    cout<<"\nDecrypted Msg: "<< decMsg <<"\n";
 
}
