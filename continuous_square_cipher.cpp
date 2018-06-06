#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;
class continuous
{
  static char square[5][5];
  char e[90],d[90];
  unsigned long a;
public:
  void cipher();
  void decipher();
}a7;
char continuous::square[5][5]={'a','b','c','d','e',
                               'k','i','h','g','f',
                               'l','m','n','o','p',
                               'u','t','s','r','q',
                               'v','w','x','y','z'};
void continuous::cipher()
{
  fstream f7;
  f7.open("Continuous.txt",ios::app);
  cout<<"Enter a string : ";
  cin>>e;
  f7<<"Encipher: "<<endl<<"Plain text: "<<e<<endl;
  int b[2][40];
  int i;
  for(i=0;e[i]!='\0';++i)
  {
    for(int j=0;j<5;++j)
      for(int k=0;k<5;++k)
        if(square[j][k]==e[i])
        {
          b[0][i]=j+1;
          b[1][i]=k+1;
        }
  }
  cout<<"The enciphered string: ";
  f7<<"Cipher text: ";
  for(int w=0;w<i;++w)
  {
    cout<<b[0][w]<<b[1][w];
    f7<<b[0][w]<<b[1][w];
  }
  f7<<endl;
  f7.close();
}
void continuous::decipher()
{
  fstream f7;
  f7.open("Continuous.txt",ios::app);
  cout<<"Enter a message to decipher: ";
  cin>>a;
  f7<<"Decipher:"<<endl<<"Cipher text:"<<a<<endl;
  int b=0,c,w=0;
  for(int k=0;a!=0;++k)
  {
    if(k%2==0&&k!=0)
    {
      d[w]=square[c-1][b-1];
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
  d[w]=square[c-1][b-1];
  strrev(d);
  cout<<"The deciphered string is: "<<d;
  f7<<"Plain text: "<<d<<endl;
}
int main()
{
  a7.cipher();
  a7.decipher();
  return 0;
}
