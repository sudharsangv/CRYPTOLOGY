#include<iostream>
#include<conio.h>
using namespace std;
#include<string.h>
class polybius
{
  char e[90],d[90];
  long a;
protected:
  static char poly1[5][5];
public:
  void cipher();
  void decipher();
}a2;
void polybius::cipher()
{
  cout<<"Enter a string : ";
  cin>>e;
  int b[2][40];
  int i;
  for(i=0;e[i]!='\0';++i)
  {
    for(int j=0;j<5;++j)
      for(int k=0;k<5;++k)
        if(poly1[j][k]==e[i])
        {
          b[0][i]=j+1;
          b[1][i]=k+1;
        }
  }
  cout<<"The enciphered string: ";
  for(int w=0;w<i;++w)
  {
    cout<<b[0][w]<<b[1][w];
  }
}
void polybius::decipher()
{
  cout<<"Enter a message to decipher: ";
  cin>>a;
  int b=0,c,w=0;
  for(int k=0;a!=0;++k)
  {
    if(k%2==0&&k!=0)
    {
      d[w]=poly1[c-1][b-1];
      ++w;
      b=0;
      c=0;
    }
    if(k%2==0)
      b=a%10;
    else
      c=a%10;
    a/=10;
  }
  d[w]=poly1[c-1][b-1];
  strrev(d);
  cout<<"The deciphered string is: "<<d;
}
char polybius::poly1[5][5]={'a','b','c','d','e',
                            'f','g','h','i','k',
                            'l','m','n','o','p',
                            'q','r','s','t','u',
                            'v','w','x','y','z'};
class bifid: private polybius
{
  char str[30],str1[30];
public:
  void cipher();
  void decipher();
}a6;
void bifid::cipher()
{
  int a[30],b[30];
  cout<<"Enter a string to encipher: ";
  cin>>str;
  for(int i=0;i<strlen(str);++i)
  {
    if(str[i]=='j')
    {
      str[i]='i';
    }
    for(int j=0;j<5;++j)
      for(int k=0;k<5;++k)
      {
        if(poly1[j][k]==str[i])
        {
          a[i]=j;
          b[i]=k;
        }
      }
  }
  short h[60];
  for(int i=0;i<strlen(str);++i)
  {
    h[i]=a[i];
  }
  int f=0;
  for(int i=strlen(str);i<2*strlen(str);++i)
  {
    h[i]=b[f];
    ++f;
  }
  cout<<"The enciphered string: ";
  int y,x;
  for(int i=0;i<2*strlen(str);i+=2)
  {
    x=h[i];
    y=h[i+1];
    cout<<poly1[x][y];
  }
}
void bifid::decipher()
{
  int a[30],b[30],c[30],d[30],x,y;
  cout<<"Enter a string to decipher: ";
  cin>>str1;
  short h[60];
  for(int i=0;i<strlen(str1);++i)
  {
    if(str1[i]=='j')
    {
      str1[i]='i';
    }
    for(int w=0;w<5;++w)
    {
      for(int q=0;q<5;++q)
      {
        if(poly1[w][q]==str1[i])
        {
          d[i]=q;
          c[i]=w;
        }
      }
    }
  }
  int f=0;
  for(int i=0;i<2*strlen(str1);++i)
  {
    if(i%2==0)
    {
      h[i]=c[f];
    }
    else
    {
      h[i]=d[f];
      ++f;
    }
  }
  for(int i=0;i<strlen(str1);++i)
  {
    a[i]=h[i];
  }
  f=0;
  for(int i=strlen(str1);i<2*strlen(str1);++i)
  {
    b[f]=h[i];
    ++f;
  }
  cout<<"The deciphered string: ";
  for(int i=0;i<strlen(str1);++i)
  {
    x=a[i];
    y=b[i];
    cout<<poly1[x][y];
  }
}
int main()
{
  a6.decipher();
  getch();
  return 0;
}
