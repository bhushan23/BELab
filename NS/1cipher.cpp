#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char encrypt(char c,int k){
		char temp;	
		if(c >= 'a' && c <= 'z'){
				temp = c + k;
				if( temp > 'z' ){
						temp = 'a' + temp - 'z' - 1;
				}	
		}else if (c >= 'A' && c <='Z'){
				temp = c + k;
				if( temp > 'Z' ){
						temp = 'A' + temp - 'Z' - 1;
				}	
		}else{
				temp = c + k;
		}
		return temp;
}
void encrpt_st(char *data, char  *enc , int key){
		int	i,len = strlen(data);
		key = key % 26;
		for( i = 0; i < len; ++i){
				enc[i] =  ( data[i] == ' ' ? data[i] :encrypt(data[i],key) );	
		}	
		enc[i]='\0';
}
int main(){
		int key,i;
		char data[1000],enc[1000];
		cin.getline( data,1000,'\n');
		cin >> key;
		
		encrpt_st(data,enc,key);
		cout << enc;
		i = 0;
		int test = 0;
		while( enc[i] == ' '){
				test++;
				i++;
		}
		for( i = 0; i < 26; ++i){
				if( enc[test] == encrypt( data[test] , i) ){
						cout << "\nKEY FOUND: " << i << "\n";
						break;
				}	
		}
		return 0;
}
