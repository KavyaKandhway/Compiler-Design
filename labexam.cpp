/*Kavya Kandhway
18JE0408
DDCSE*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;
    char c;
    int i=0;
    int state=0;
    /*
        state 1: a
        state 2: b+
        state 3: aa+(invalid)
        state 4: ab+
        state 5: abb
        state 6: invalid
    */
    while(i<s.size()){
        switch(state){
            case 0: c=s[i++];
            if(c=='a'){
                state=1;
            }
            else if(c=='b'){
                state=2;
            }
            else{
                state=6;
            }
            break;
            case 1: c=s[i++];
            if(c=='a'){
                state=3;
            }
            else if(c=='b'){
                state=4;
            }else{
                state=6;
            }
            break;
            case 2: c=s[i++];
            if(c=='a'){
                state=6;
            }
            else if(c=='b'){
                state=2;
            }else{
                state=6;
            }
            break;
            case 3: c=s[i++];
            if(c=='a'){
                state=3;
            }else if(c=='b'){
                state=2;
            }
            else{
                state=6;
            }
            break;
            case 4: c=s[i++];
            if(c=='a'){
                state=6;
            }else if(c=='b'){
                state=5;
            }
            else{
                state=6;

            }
            break;
            case 5: c=s[i++];
            if(c=='a'){
                state=6;
            }
            else if(c=='b'){
                state=2;
            }
            else{
                state=6;
            }
            break;
            case 6: c=s[i++];
            
            break;
        }
    }
    if(state==1){
        cout<<"rule of string is 'a'"<<endl;
    }else if(state==2||state==4){
        cout<<"rule of string is 'a*b+'"<<endl;
    }else if(state==5){
        cout<<"rule of string is 'abb'"<<endl;
    }
    else {
        cout<<"not valid"<<endl;
    }
}