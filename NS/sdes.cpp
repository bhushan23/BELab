#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void printArray(int* ar){
    cout <<"\n";
    while(*ar != -1)
        cout << *ar++;
    cout << "\n";     
}
void strtoint(char* in,int* out){
 int j = 0;
  for(int i = strlen(in)-1; i >=0; --i){
    out[j++] = in[i] - 48;
  } 
  out[j] = -1;
}
void copyPattern(int* from,int* pat,int* to){
    int i=0;
    while(pat[i] != -1){
        to[i] = from[pat[i]-1];
        ++i;    
    }
    to[i] = -1;
}


void lShift(int* inpr,int b,int t,int v){
int i;
int temp[v];
for(i = 0; i < v; ++i){
    temp[i] = inpr[i+b];
} 
for(i = b; i < t-v; ++i){ 
    inpr[i] = inpr[i+v] ;  
}
int j =0;
for(; j < v ; ++j ,++i){
    inpr[i] = temp[j];
 } 
}

void LS(int* inpr,int ver){
int len=0,half;
lShift(inpr,0,5,ver);
lShift(inpr,5,10,ver);
}


void generateKey(int* key,int* p10,int* p8,int* key1,int* key2){
    int inpr[11],inpr1[11],i;
    //P10
    printArray(p10);
    printArray(p8);
    copyPattern(key,p10,inpr);
    cout<<"CP";
    printArray(inpr);
    //LS 1
    LS(inpr,1);
    cout<<"LS ";
    printArray(inpr);
    copyPattern(inpr,p8,key1); 
    //LS 2 
    LS(inpr,2);
    copyPattern(inpr,p8,key2); 
    cout << "KEY 1 ";
    printArray(key1);
    cout << "KEY 2 ";
    printArray(key2);        
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
void getNib(int t1,int t2,int* nib){
    switch(t1){
    case 0:
        nib[0] = 0;nib[1] =0;
        break;
     case 1:
        nib[0] = 0;nib[1] =1;
        break;
     case 2:
        nib[0] = 1;nib[1] =0;
        break;
     case 3:
        nib[0] = 1;nib[1] =1;
        break;   
    }
    
    switch(t2){
    case 0:
        nib[2] = 0;nib[3] =0;
        break;
     case 1:
        nib[2] = 0;nib[3] =1;
        break;
     case 2:
        nib[2] = 1;nib[3] =0;
        break;
     case 3:
        nib[2] = 1;nib[3] =1;
        break;   
    }
}
void substi(int s0[4][4],int s1[4][4],int* inptr, int* nib2){
    int i,j,t1,t2;
    i = getIndex(inptr[0],inptr[3]);
    j = getIndex(inptr[1],inptr[2]);
    t1 = s0[i][j];
   
    i = getIndex(inptr[4],inptr[7]);
    j = getIndex(inptr[5],inptr[6]);
    t2 = s1[i][j];
   
    getNib(t1,t2,nib2);    
}
void FK(int* data,int* ep,int s0[4][4],int s1[4][4],int* p4,int* nib1,int* nib2,int* key){
    int inptr[9],i,j;
    inptr[8]=-1;
    int changed[4],nib2a[5];
    nib2a[4] = -1;
    for(i = 4,j=0; i < 8; ++i,++j){
        nib1[j] = data[i];    
        changed[j] = data[i-4];
    }
    copyPattern(nib1,ep,inptr);
    cout<<"After EP:";
    printArray(inptr);
    XOR(inptr,key);
    cout<<"After XOR:";
    printArray(inptr);
    //Substitution
   substi(s0,s1,inptr,nib2a);
    copyPattern(nib2a,p4,nib2);

    XOR(data,nib2);
    for(i = 0 , j =4; j < 8; ++i,++j)
        data[j] = nib1[i];
}

void Swap(int* data){
    int t,i,j=7;
    for(i = 0; i < 4; ++i){
        t = data[i];
        data[i] = data[i+4];
        data[i+4] = t;
    }
}
void encrypt(int* data,int* ip,int* ipin,int* ep,int s0[4][4],int s1[4][4],int* p4,int* cipher,int* key1,int* key2){
    int inpr[9];
    int nib1[5],nib2[5];
    nib2[4] = nib1[4] = inpr[8] = -1;
    copyPattern(data,ip,inpr);
    cout<<"After IP:";
    printArray(inpr);
    FK(inpr,ep,s0,s1,p4,nib1,nib2,key1);
    cout << "After FK:";
    printArray(inpr);
    Swap(inpr);
  
    FK(inpr,ep,s0,s1,p4,nib1,nib2,key2);
    copyPattern(inpr,ipin,cipher);
 
}
int main(){
    int key[11],p10[11],p8[9];
    int key1[9],key2[9],i;
    int ip[9],ipin[9],ep[9],p4[5];
    int s0[4][4]={ {1,0,3,2} ,{3,2,1,0} ,{0,2,1,3} ,{3,1,3,2}};
    int s1[4][4]={ {0,1,2,3} ,{2,0,1,3} ,{3,0,1,0} ,{2,1,0,3}};
    int data[1000],cipher[1000];
    cout << "Enter Plaintext 8 bit\n";
    for(i = 0;i <8; ++i)
        scanf("%d",&data[i]);
    data[i] = -1;  
    cout << "Enter 10 bit KEY\n";
    for(i = 0;i <10; ++i)
        scanf("%d",&key[i]);
    key[i] = -1;  
    
    cout << "Enter IP 8 bit\n";
    for(i = 0;i <8; ++i)
        scanf("%d",&ip[i]);
    ip[i] = -1; 
    
    cout << "Enter IP Inverse 8 bit\n";
    for(i = 0;i <8; ++i)
        scanf("%d",&ipin[i]);
    ipin[i] = -1; 
    
    cout << "Enter EP 8 bit\n";
    for(i = 0;i <8; ++i)
        scanf("%d",&ep[i]);
    ep[i] = -1;
    
    cout << "Enter P4\n";
    for(i = 0;i < 4; ++i)
        scanf("%d",&p4[i]);
    p4[i] = -1;
    
    cout << "Enter P10\n";
    for(i = 0;i <10; ++i)
        scanf("%d",&p10[i]);
    p10[i] = -1;    
    cout << "Enter P8\n";
    for(i = 0;i < 8; ++i)
        scanf("%d",&p8[i]);
    p8[i] = -1;
  
    generateKey(key,p10,p8,key1,key2);
    encrypt(data,ip,ipin,ep,s0,s1,p4,cipher,key1,key2);
    cout << "\nCIPHER :";
    printArray(cipher);   
    cout<<"DECRYPTING..........\n";
    encrypt(cipher,ip,ipin,ep,s0,s1,p4,data,key2,key1);
       cout << "DECRYPTED :";
    printArray(data);
    return 0;
}
