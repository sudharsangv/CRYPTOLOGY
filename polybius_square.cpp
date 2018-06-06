#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
/*char poly2[][5]={'A','B','C','D','E',
                'F','G','H','I','K',
                'L','M','N','O','P',
                'Q','R','S','T','U',
                'V','W','X','Y','Z'};*/
char poly1[][5]={'a','b','c','d','e',
                'f','g','h','i','k',
                'l','m','n','o','p',
                'q','r','s','t','u',
                'v','w','x','y','z'};
int main()
{
  char ch[40];
  long ch2;
  int n;
  void sqe(char []);
  void sqd(long);
  cout<<"Menu: "
      <<"\n\t1.Polybius square encipher"
      <<"\n\t2.Polybius square decipher"
      <<"\n\t3.Exit"
      <<"\nPlease choose an option: ";
  cin>>n;
  switch(n)
  {
    case 1:cout<<"Enter a string : ";
          cin>>ch;
          sqe(ch);
          break;
    case 2:cout<<"Enter a message to decipher: ";
          cin>>ch2;
          sqd(ch2);
          break;
    case 3:exit(0);

  }
}
void sqe(char a[])
{
  int b[2][40];
  int i;
  for(i=0;a[i]!='\0';++i)
  {
    for(int j=0;j<5;++j)
      for(int k=0;k<5;++k)
        if(poly1[j][k]==a[i])
        {
          b[0][i]=j+1;
          b[1][i]=k+1;
        }
       /*for(int j=0;j<5;++j)
      for(int k=0;k<5;++k)
        if(poly1[j][k]==a[i])
          {
            b[0][i]=j+1;
            b[1][i]=k+1;
          }*/
  }
  cout<<"The enciphered string: ";
  for(int w=0;w<i;++w)
  {
    cout<<b[0][w]<<b[1][w];
  }
  cout<<endl;
}
void sqd(long a)
{
  char d[20];
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
  cout<<endl;
}
