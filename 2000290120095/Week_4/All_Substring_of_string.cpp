#include<iostream>
#include<string.h>

using namespace std;

void substring(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=str[0];
    string ros=str.substr(1);
    substring(ros,ans);
    substring(ros,ans+ch);
}

int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    cout<<"Substrings are: "<<endl;
    substring(str,"");
}