#include<bits/stdc++.h>
using namespace std;

int main()
{
   int s[256],t[256];
   int keystream[256];
   string pstring,keystring,dtstring="";
   int pt[256],ct[256],dt[256];
   cout<<"enter message:";cin>>pstring;
   cout<<"enter key:";cin>>keystring;
   
   int n=pstring.length();
   cout<<"\n plain text\t:";
   for(int i=0;i<n;i++)
    { 
      pt[i]=pstring[i];
      cout<<pt[i]<<" ";
    }
    for(int i=0;i<256;i++)
     {
       s[i]=i;
       t[i]=(int)keystring[i%keystring.length()];
       cout<<endl<<t[i]<<"    ";
     }
     cout<<endl;
     int j; 
     for(int i=0;i<256;i++)
      {
        j=(j+s[i]+t[i])%256;
        
        cout<<i<<","<<j<<"   ";
        swap(s[i],s[j]);
        
      }
      
    cout<<"\n key stream\t:";
    j=0;
     for(int i=0;i<n;i++)
       {
         j=(j+s[i])%256;
         swap(s[i],s[j]);
         int t=(s[i]+s[j])%256;
         keystream[i]=s[t];
         cout<<keystream[i]<<" ";
       }
     cout<<"\n cipher text\t:";
      for(int i=0;i<n;i++)
       { 
         ct[i]=pt[i]^keystream[i];
         cout<<ct[i]<<" ";
       }
     cout<<"\n decrypted text\t:";
      for(int i=0;i<n;i++)
        {
          dt[i]=ct[i]^keystream[i];
          cout<<dt[i]<<" ";
          dtstring+=(char)dt[i];
        }
        
        
      cout<<"\n decryption text:"<<dtstring<<endl;
      return 0;
}             




         
