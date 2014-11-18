#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int key[] = {0,1,0,0,1,0,1,0,1,1,1,1,0,1,0,1};
int encMixCol[2][2] = { {4,1}, {1,4}};
int decMixCol[2][2] = { {9,2}, {2,9}};
int encSBox[4][4][4] = { {1,0,0,1, 0,1,0,0 ,1,0,1,0, 1,0,1,1},
                      {1,1,0,1, 0,0,0,1, 1,0,0,0, 0,1,0,1},
                      {0,1,1,0, 0,0,1,0, 0,0,0,0, 0,0,1,1},
                      {1,1,0,0, 1,1,1,0, 1,1,1,1, 0,1,1,1}                    
                     };
                     
int decSBox[4][4][4] = { {1,0,1,0, 0,1,0,1 ,1,0,0,1, 1,0,1,1},
                      {0,0,0,1, 0,1,1,1, 1,0,0,0, 1,1,1,1},
                      {0,1,1,0, 0,0,0,0, 0,0,1,0, 0,0,1,1},
                      {1,1,0,0, 0,1,0,0, 1,1,0,1, 1,1,1,0}                    
                     };                     
int k1[17],k2[17],k3[17];


void printArray(int* ar){
    cout <<"\n";
    while(*ar != -1)
        cout << *ar++;
    cout << "\n";     
}


int BlockLen(int *data){
int i=0;
while(data[i] != -1)
    ++i;
return i;    
}
void copyBlock(int* src,int* dest){
    int i = 0;
    while(src[i] != -1){
        dest[i] = src[i++];
    }
    dest[i] = -1;
}
void XOR(int* one,int* sec){
int i=0;
for(;one[i] != -1 && sec[i] != -1; ++i){
    if(one[i] != sec[i])
        one[i] = 1;
    else
        one[i] = 0;        
}
}

void Swap(int* data){
    int t,i,j=7;
    for(i = 0; i < 4; ++i){
        t = data[i];
        data[i] = data[i+4];
        data[i+4] = t;
    }
}

void Swap(int* data,int from){
    int t,i,j=7;
    for(i = from; i < 4; ++i){
        t = data[i];
        data[i] = data[i+4];
        data[i+4] = t;
    }
}
void RotNib(int* data){
    int i,len = BlockLen(data);
    for( i = 0; i < len; i += 7){
        Swap(data,i);
    }
}
int getIndex(int i,int j){
    switch(i){
    case 0:
        switch(j){
        case 1:
            return 1;
            break;
        case 0:
            return 0;
            break;
            
       }         
    break;
    
    case 1:
        switch(j){
        case 1:
            return 3;
            break;
        case 0:
            return 2;
            break;
        }    
    break;
    }
}
void subNib(int* inptr,int* output){
    int i,j,t1,t2;
    i = getIndex(inptr[0],inptr[1]);
    j = getIndex(inptr[2],inptr[3]);
    for(int k=0; k < 4; ++k){
        output[k] = encSBox[i][j][k];
    }
    i = getIndex(inptr[4],inptr[5]);
    j = getIndex(inptr[6],inptr[7]);
    
    for(int k=0; k < 4; ++k){
        output[k+4] = encSBox[i][j][k];
    }
}

void subNib16(int* inptr,int* output,bool encFlag){
    int sBox[4][4][4];
    int i,j,k,t1,t2;
    
    
        for(i = 0; i < 4; ++i){
            for(j = 0; j < 4; ++j){
                for(k = 0; k < 4; ++k){
                sBox[i][j][k] = (encFlag == true ? encSBox[i][j][k] : decSBox[i][j][k]);
            }
         }
        }    
    
    i = getIndex(inptr[0],inptr[1]);
    j = getIndex(inptr[2],inptr[3]);
    for(int k=0; k < 4; ++k){
        output[k] = sBox[i][j][k];
    }
    i = getIndex(inptr[4],inptr[5]);
    j = getIndex(inptr[6],inptr[7]);
    
    for(int k=0; k < 4; ++k){
        output[k+4] = sBox[i][j][k];
    }
    
    i = getIndex(inptr[8],inptr[9]);
    j = getIndex(inptr[10],inptr[11]);
    for(int k=0; k < 4; ++k){
        output[k+8] = sBox[i][j][k];
    }
    i = getIndex(inptr[12],inptr[13]);
    j = getIndex(inptr[14],inptr[15]);
    
    for(int k=0; k < 4; ++k){
        output[k+12] = sBox[i][j][k];
    }
}
void generateKey(){
int w0[9],w1[9],w2[9],w3[9],w4[9],w5[9];
int i;
int t1[] = {1,0,0,0,0,0,0,0};
int t2[] = {0,0,1,1,0,0,0,0};
int inptr[9],temp[9];
    inptr[8] = temp[8] = -1;
    for(i = 0; i < 8; ++i){
        w0[i] = key[i];
        w1[i] = key[i+8];
    }
    w0[i] = w1[i] = -1;
    copyBlock(w1,w3);
    copyBlock(w0,w2);
    RotNib(w1);
    subNib(w1,inptr);
    XOR(inptr,t1);
    XOR(w2,inptr);
    XOR(w3,w2);
    copyBlock(w3,w4);
    RotNib(w4);
    subNib(w4,inptr);
    XOR(inptr,t2);
    XOR(inptr,w2);
    copyBlock(inptr,w4);
    copyBlock(w4,w5);
    XOR(w5,w3);
    for(i = 0; i < 8; ++i){
        k2[i] = w2[i];
        k3[i] = w4[i];
        k1[i] = key[i];
    }
    for(; i < 16; ++i){
        k2[i] = w3[i-8];
        k3[i] = w5[i-8];
        k1[i] = key[i];
    }
    k1[i]=k2[i]=k3[i]= -1;
    cout << "\nKey1: ";
    printArray(k1);
    cout << "\nKey2: ";
    printArray(k2);
    cout << "\nKey3: ";
    printArray(k3);
    
}
void shiftRow(int* data){
int t;
for(int i = 4; i < 8;++i){
        t = data[i];
        data[i] = data[i+8];
        data[i+8] = t;
}

}
int toDecimal(int* data,int lower,int upper){
int i=0;
int decval=0;
--upper;
for( ; upper >= lower; --upper,++i){
    decval += (pow(2,i) * data[upper]) ;
 }
return decval;
}
int findlen(int data){
int cnt = 0;
while(data>0){
data = data >> 1;
++cnt;    
}
return cnt;
}

int MultiPly(int a,int b){
    int ans = a*b,tolen;
    int bydiv = 19,temp;
    int dlen = findlen(bydiv);
    
    if( findlen(ans) > 4){
        tolen = findlen(ans);
        while(tolen >= dlen ){
            temp = (bydiv << (tolen-dlen));
            ans = ans ^ temp;
            tolen = findlen(ans);
             cout << "   bydiv "<< temp << "  " << findlen(temp) << "  " << ans << " " << findlen(ans);
        }
     }
    return ans;
}

void decToBinData(int* data,int val,int cur){
int nxt = cur + 3;
while(nxt >= cur){
    data[nxt] = val % 2;
    val = val / 2;
    --nxt;
}
}

struct Poly{
int data[100];
int MSB;    
};


void printPoly(struct Poly p1){
    cout << "\n";
    for(int i=0; i <= p1.MSB; ++i){
        if(p1.data[i]){
            cout<<" (" << p1.data[i] <<" )^" << i <<" ";         
        }
    }
}
struct Poly DecToPoly(int val){
int j,i=0,temp,data[100];
struct Poly p1;
for(i = 0; i < 100; ++i)
    p1.data[i] = 0;
    
int nxt = 0;
while(val){
    p1.data[nxt] = val % 2;
    val = val / 2;
    ++nxt;
}    
    
p1.MSB = --nxt;
return p1;
}

struct Poly MultiTwoPoly(struct Poly p1,struct Poly p2){
struct Poly pans = DecToPoly(0);
int i,j,temp;

for(i = 0; i <= p1.MSB; ++i){
    
    if(p1.data[i])
    for(j = 0; j <= p2.MSB; ++j){
        if(p2.data[j]){
            temp = i + j;
            if(pans.MSB < temp)
                pans.MSB = temp;
            pans.data[temp]++;
        }
    }
}    
return pans;
}

int PolyToDec(struct Poly p1){
    int ans = 0;
    for(int i = 0; i <= p1.MSB; ++i){
        if(p1.data[i]){
            ans += pow(2,i);
        }
    }
    return ans;
}
int MultiPlyPoly(int a,int b){
    int ans;
    int bydiv = 19,temp,div1,div2,i;
    int dlen = findlen(bydiv);
    struct Poly p1,p2,pans;
    p1 = DecToPoly(a);
    p2 = DecToPoly(b);
    pans = MultiTwoPoly(p1,p2);

    if( pans.MSB > 3){
        while(pans.MSB > 3 ){
            pans.data[pans.MSB]--;
            div1 = pans.MSB - 3;
            div2 = pans.MSB - 4;
            
            if(pans.data[div1]){
                pans.data[div1]--;
            }else
            pans.data[div1] = 1;
            
            if(pans.data[div2]){
                pans.data[div2]-- ;
            }else
            pans.data[div2] = 1;
            
            temp =0;
            for(i = pans.MSB-1; i >=0; --i){
                if(pans.data[i] > 0){
                    pans.MSB = i;
                    temp = 1;
                    break;  
                 }   
            }
            if(!temp)
                pans.MSB = 0;
        }
     }
   
    ans = PolyToDec(pans);
    return ans;
}

       

void MixColumn(int* data,bool encFlag){
int i,j,k,cur,MulAr[2][2],AnsAr[2][2];
int mixcol[2][2];
cur=0;
for(i = 0; i < 2; ++i){
    for(j = 0; j < 2; ++j){
        MulAr[j][i] = toDecimal(data,cur,cur+4);
        cur+=4;
    }
}

for(i= 0; i <2;++i){
    for(j= 0; j <2;++j){
        AnsAr[i][j] = 0;
        mixcol[i][j]= encFlag == true ? encMixCol[i][j] : decMixCol[i][j] ;
    }
}   

for(i = 0; i < 2; ++i){
    for(j =0; j < 2; ++j){
        for( k =0 ; k < 2; ++k){
        AnsAr[i][j] = AnsAr[i][j] ^ MultiPlyPoly( mixcol[i][k],MulAr[k][j] )  ; 
        }
    }    
}

cur = 0;
for(i= 0; i <2;++i){
    for(j= 0; j <2;++j){
       decToBinData(data,AnsAr[j][i],cur);
       cur+=4; 
    }
}
}

void encrypt(int* data){
int inptr[17],outptr[17];
inptr[16]=-1,outptr[16]=-1;
copyBlock(data,inptr);
XOR(inptr,k1);
subNib16(inptr,outptr,true);
cout<<"Sub nib:";
printArray(outptr);
shiftRow(outptr);
printArray(outptr);  
MixColumn(outptr,true);
printArray(outptr);  
XOR(outptr,k2);

subNib16(outptr,data,true);
shiftRow(data);
XOR(data,k3);
cout << "\nCipher: ";
printArray(data); 
}

void decrypt(int* data){
int inptr[17],outptr[17];
inptr[16]=-1,outptr[16]=-1;
copyBlock(data,inptr);
XOR(inptr,k3);
cout<<"\nRound 3 Key Added:"; 
printArray(inptr);
shiftRow(inptr);
cout<<"\nShift Row:";
 printArray(inptr);
subNib16(inptr,outptr,false);
cout<<"\nInverse Sub Nib:"; 
printArray(outptr);
XOR(outptr,k2);
cout<<"\nRound 2 Key Added:"; 
printArray(outptr);
MixColumn(outptr,false);
cout<<"\nInverse MIX COL:"; 
printArray(outptr);

shiftRow(outptr);
cout<<"\nShift Row:";
printArray(outptr);
subNib16(outptr,data,false);
cout<<"\nInverse Sub Nib:"; 
printArray(data);
XOR(data,k1);

cout << "\nPlain Text: ";
printArray(data);
}
int main(){
int data[]= {1,1,0,1,0,1,1,1,0,0,1,0,1,0,0,0,-1};
cout << "Plain Text:";
printArray(data);
generateKey();
encrypt(data);
decrypt(data);
}

