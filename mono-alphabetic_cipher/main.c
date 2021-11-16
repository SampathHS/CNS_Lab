/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#include<stdio.h>

#include<stdlib.h> 
#include<string.h>

#include<ctype.h>

void analysis(int cf2[26],float sf2[26])
{
    int i,index;
    char c;
    int ch1;
    int ch2;
    
    FILE *fp;
    fp=fopen("cipher.txt","r"); 
    while((c=fgetc(fp))!=EOF)
    {
        if(isalpha(c))
        cf2[tolower(c)-'a']++;
    
    }
    
    printf("\nFrequency\t Plaintext\t Ciphertext"); 
    for(i=0;i<26;i++)
    {
        ch1=max1(sf2)+'a';
        ch2=max2(cf2)+'a';
        index=max1();
        printf("\n%f\t\t%c\t\t%c",sf2[index],ch1,ch2); 
        sf2[index]=0;
    
    } 
    fclose(fp);
    printf("\n");


}

int max1 (float sf2[26]) 
{

    float max=0; 
    int i,index=0;
    max=sf2[0]; 
    for(i=0;i<26;i++) 
    {
    
        if(sf2[i]>max) 
        {
        
            index=i;
            
            max=sf2[i];
        
        }
    
    }
    
    return index;

}


int max2(int cf2[26])
{
    
    float max=0;
    
    int i,index=0;
    
    max=cf2[0];
    
    for(i=0;i<26;i++)
    {
    
        if(cf2[i]>max)
        {
        
            index=i;
            
            max=cf2[i];
        
        }
    } 
    
    cf2[index]=0; 
    return index;

}

int main()

{
    
    float sf2[28]={8.167,1.492,2.782,4.253,12.702,2.228,2.015,6.094,6.996,0.153,0.773,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9,056,2.75 ,8,0.978,2.360,0.150,1.974,0.074}; 
    char key[26]={'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f'};
    
    FILE *fp1, *fp2;
    
    int temp,cf2[26];
    
    char c1,c2; 
    
    fp1=fopen("plain.txt","r");
    
    fp2=fopen("cipher.txt","w"); 
    while((c1=fgetc(fp1))!=EOF)
    
    {
    
        if(isalpha(c1))
        
        {
            c2=key[tolower(c1)-'a'];
        }
        
        fputc(c2,fp2);
    }
    
    fclose(fp1);
    
    fclose(fp2);
    
    fp1=fopen("cipher.txt","r"); 
    fp2=fopen("result.txt","w"); 
    while((c1=fgetc(fp1))!=EOF)
    
    {
    
        if(isalpha(c1))
        
        {
        
            temp=((c1-6)>=97)?(c1-6):(c1-20);
            
            c2=temp;
        
        } 
        fputc(c2,fp2);
    
    }
    
    fclose(fp1);
    
    fclose(fp2);
    
    analysis(cf2,sf2); 
    return 0;
}
