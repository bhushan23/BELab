#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
struct alphaTable{
    int i;
    int j;
	char c;
}TPointer[26];

void computeTable(char keyTable[5][5],char* key){
    vector<bool> temp(26,true);
    int len = strlen(key);
    int ith,jth;
    ith = jth = 0;
    for(int i = 0; i < len; ++i){
        if( temp[key[i]%26] ){
            temp[key[i]%26] = false;
            keyTable[ith][jth] = key[i];
            TPointer[key[i]%26].i = ith;
            TPointer[key[i]%26].j = jth++;
            TPointer[key[i]%26].c = key[i];
            if(jth >= 5){
                jth = 0;
                ++ith;
            }
        }
    }
    char insert = 'A';
    for(int i = ith; i < 5; ++i){
        for(int j = jth; j < 5; ++j){
                while( !temp[insert%26] )
                    ++insert;
                keyTable[i][j] = insert;
                TPointer[insert%26].i = i;
                TPointer[insert%26].j = j;
 		TPointer[insert%26].c = insert;
                ++insert;
                if( insert == 'J' )
                    ++insert;   
        }
        jth = 0;
    }
}


void printKeyTable(char table[5][5]){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << table[i][j] << " "; 
        }
        cout << "\n";
    }
}

void prepareString(char* in,char* out){
    int len = strlen(in);
    char c;
    int i = 0;
    int o = 0;
    while( i < len ){
        while( in[i] == ' ' )
            ++i;
        in[i] = in[i] == 'J' ? 'I' : in[i];    
        out[o] = in[i];
        ++i;
        while( in[i] == ' ' )
            ++i;
        if( i < len)
             c = in[i] == 'J' ? 'I' : in[i];
        else
            c = 'X'; 
	if( out[o] == c ){
		c = 'X';	   
		--i;	
	}
        out[o+1] = c;
        ++i;
        out[o+2] = ' ';
        o+=3;
         
     }
     out[o] = '\0';
}
void encryptPlayFair(char* input,char* key,char* enc,char keyTable[5][5]){
int i,j,len,i0,j0,i1,j1;
len = strlen(input);      
for(i = 0; i < len; i+=3){
    i0 = TPointer[input[i]%26].i; 
    j0 = TPointer[input[i]%26].j;
     
    i1 = TPointer[input[i+1]%26].i; 
    j1 = TPointer[input[i+1]%26].j;
    if( i0 == i1 && j0 == j1 ){
        cout << "ERROR!\n";
        //break;
    }else if( i0 == i1 ){//same row
	enc[i] = keyTable[i0][(j0+1)%5];
    	enc[i+1] = keyTable[i0][(j1+1)%5];
    	
    }else if( j0 == j1){ //same column
    	enc[i] = keyTable[(i0+1)%5][j1];
    	enc[i+1] = keyTable[(i1+1)%5][j1];
    }else{ 
        enc[i] = keyTable[i0][j1]; 
        enc[i+1] = keyTable[i1][j0];    
    }       
}

}


void decryptPlayFair(char* input,char* key,char* enc,char keyTable[5][5]){
int i,j,len,i0,j0,i1,j1;
len = strlen(input);      
for(i = 0; i < len; i+=3){
    i0 = TPointer[input[i]%26].i; 
    j0 = TPointer[input[i]%26].j;
     
    i1 = TPointer[input[i+1]%26].i; 
    j1 = TPointer[input[i+1]%26].j;
    if( i0 == i1 && j0 == j1 ){
        cout << "ERROR!\n";
        //break;
    }else if( i0 == i1 ){//same row
		
	enc[i] = keyTable[i0][(j0-1 < 0?(5-j0-1):j0-1)];
    	enc[i+1] = keyTable[i0][(j1-1 < 0?(5-j1-1):j1-1)];
    	
    }else if( j0 == j1){ //same column
    	enc[i] = keyTable[(i0-1 < 0?(5-i0-1):i0-1)][j1];
    	enc[i+1] = keyTable[(i1-1 < 0?(5-i1-1):i1-1)][j1];
    }else{ 
        enc[i] = keyTable[i0][j1]; 
        enc[i+1] = keyTable[i1][j0];    
    }       
}
}

int main(){
char input[1000],key[1000],enc[1000];
char keyTable[5][5];

scanf("%[^\n]",input);
cin>>key;
computeTable(keyTable,key);
cout << "Computed Table\n";
printKeyTable(keyTable);
prepareString(input,enc);
cout<<"\n";
cout<<"Tokenizing String: "<<enc;
encryptPlayFair(enc,key,enc,keyTable);
cout<<"\nEncrypted String: "<<enc;
decryptPlayFair(enc,key,enc,keyTable);
cout << "\nDecrpted String: " <<enc;


return 0;
}
