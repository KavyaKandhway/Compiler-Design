#include<bits/stdc++.h>

using namespace std;

string str;

int i,n;
bool match(char ch)
{
    if(i<n && str[i]==ch)
    {

        i+=1;
        return true;
    }
    else
    {
        return false;
    }

}

bool AP()
{
    int save = i;
    if(i<n)
    {
        if(match('c'))
        {
            if(AP())
            return true;
        }
        else if(match('a') && match('d'))
        {
            if(AP())
            return true;    
        }
        else
        {
            i = save;
            return true;
        }
    }
    else
    return true;

}
bool A()
{
    int save = i;
    if(i<n)
    {
        if(match('b') && match('d'))
        {
            if(AP())
            return true;
        }
        else if(match('f'))
        {
            if(AP())
            return true;
        }
        else
        {
            i = save;
            return true;
        }
    }
    else
    return true;

}
bool S()
{
    if(i<n)
    {
        if(i==n-1 && match('b'))
        return true;
        else
        {
            if(A())
            {
                if(match('a'))
                return true;
                else
                return false;
            }
            else
            return false;
        }
    }
    else
    return true;
    return false;
}
int main()
{
    cout<<"Enter the string\n";
    cin>>str;
    i = 0;
    n = str.length();
    if(S() && i==n)
    cout<<"String Parsed"<<endl;
    else
    cout<<"String not parsed"<<endl;
    return 0;

}