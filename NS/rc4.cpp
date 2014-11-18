#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void ustrcpy(int* dest, int* src){
  while( *src != -1 ){
  *dest++ = *src++;
  }
}
int ustrlen(int* st){
  int len = 0;
  while(*st++ != -1)
    ++len;
  return len;
}
class Rc4{
  public:
    int cipher[1000],decMsg[1000],input[1000],key[1000];
    int S[256];

    Rc4(){
    }
    Rc4(char in[1000],char k[1000]){
      int i;
      strtoint(in,input);
      strtoint(k,key);
      //ustrcpy(input,in);
      //ustrcpy(key,k);
      //cout << "input :" << input << " "<< key;
      initArray();
      KSA();	
      PRGA();
    }
 Rc4(int in[1000],int k[1000]){
      int i;
    for(i = 0; in[i] != -1; ++i)
      input[i] = in[i];
    input[i] = -1;
    for(i =0; k[i] != -1; ++i)
      key[i] = k[i];  
  key[i] = -1;
      //ustrcpy(input,in);
      //ustrcpy(key,k);
     // cout << "input :" << input << " "<< key;
      initArray();
      KSA();	
      PRGA();
    }
    void initArray(){
      for(int i = 0; i < 256; ++i){
        S[i] = i;
      }
    }	
    void strtoint(char in[1000],int out[1000]){
     int j = 0;
      for(int i = strlen(in)-1; i >=0; --i){
        out[j++] = in[i] - 48;
      } 
      out[j] = -1;
    }
    void KSA(){
      int i,j;
      int len = ustrlen(key);
      int temp;
      for( i = 0; i < 256; ++i){
        j = ( j + S[i] + key[i%len]) % 256;
        //swap(S[i],S[j]);
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
      }
    }
    void PRGA(){
      int i,j,m,temp,keystream;
      i = j = m = 0;

      while(m < ustrlen(input)){
       // cout << "\n" << i << "  " << j ;
        i = (i+1) % 256;
        j = (j+S[i]) % 256;
        temp = S[i];
        S[j] = S[i];
        S[i] = temp;
        keystream = S[ (S[i] + S[j]) % 256 ];
        cipher[m] = input[m] ^ keystream;
        ++m;

      }
    cipher[m] = -1;      
    }
    void printCipher(){
      cout << "\n";
      for(int i = ustrlen(cipher) - 1; i >= 0; --i){
        printf("%d",cipher[i]);
      }
    }

};
int main(){
  char encMsg[1000],decMsg[1000],input[1000],key[1000];
  char t[100];
  cout << "Enter PlainText: ";
  scanf("%s",input);
  cout << "Enter Key: ";
  scanf("%s",key);
  Rc4 rc4 = Rc4(input,key);
  cout<<"Encrypted Message:";
  rc4.printCipher();	
  cout <<"\nDecoded Message:";
  Rc4 dec = Rc4(rc4.cipher,rc4.key);
  dec.printCipher();
  cout<<"\n";
}
