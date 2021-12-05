/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void encrypt(string plain,int key[],int keySize)
{
    int n=plain.length();
    int m=ceil(n/(float)keySize);
    char mat[m][keySize];
    int k=0;
    cout<<"Encryption Matrix"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<keySize;j++)
        {
            if(k<n)
            {
                mat[i][j]=plain[k++];
            }
            else
            {
                mat[i][j]='X';
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<keySize;j++)
        cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<"After Decryption"<<endl;
    string cipher=" ";
    char cipher_mat[keySize][m];
    for(int i=0;i<keySize;i++)
    {
        for(int j=0;j<m;j++)
        {
            cipher_mat[key[i]-1][j]=mat[j][i];
        }
    }
    for(int i=0;i<keySize;i++)
    {
        for(int j=0;j<m;j++)
        {
            cipher+=cipher_mat[i][j];
        }
    }
    //Decryption
    cout<<"cipher Text :"<<cipher<<endl;
    string res="";
    for(int j=0;j<m;j++)
    for(int i=0;i<keySize;i++)
    res=res+cipher_mat[key[i]-1][j];
    cout<<" decrypted text is "<<res<<endl;
}
int main()
{
    int keySize;
    cout<<"Enter key size \t";
    cin>>keySize;
    int keyMat[keySize];
    cout<<"Enter Key Elements \t"<<endl;
    for(int i=0;i<keySize;i++)
    cin>>keyMat[i];
    string plain;
    cout<<"Enter plain text \n";
    cin>>plain;
    cout<<"Key Matrix is"<<endl;
    for(int i=0;i<keySize;i++)
    cout<<keyMat[i]<<" ";
    cout<<endl;
    encrypt(plain,keyMat,keySize);
    return 0;
}