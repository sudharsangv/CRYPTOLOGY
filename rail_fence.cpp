#include<iostream>
using namespace std;
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
class rail
{
  char a[50],a1[3][20],a2[3][20],b[50];
  int w;
  static int z;
public:
  void encipher();
  void decipher();
}d;
int rail::z=0;
void rail::encipher()
{
  cout<<"Enter a string to encipher: ";
  cin>>a;
  for(int i=0;a[i]!='\0';++i)
  {
    for(int j=0;j<3;++j)
    {
      a1[j][i]=a[z];
      ++z;
    }
  }
  cout<<"The enciphered string: ";
  cout<<a1[0]<<"_"<<a1[1]<<"_"<<a1[2];
}
void rail::decipher()
{
  cout<<"Enter a string to decipher: ";
  cout<<"\n1st Part: ";
  cin>>a2[0];
  cout<<"2nd Part: ";
  cin>>a2[1];
  cout<<"3rd Part: ";
  cin>>a2[2];
  if(strlen(a2[0])==strlen(a2[1])&&strlen(a2[1])==strlen(a2[2]))
  {
     for(int i=0;i<strlen(a2[0]);++i)
    {
      for(int j=0;j<3;++j)
      {
        a[z]=a2[j][i];
        ++z;
      }
    }
    cout<<"The enciphered string is: "<<a;
  }
  else
    cout<<"Deciphering not possible";

}
int main()
{
  d.encipher();
  d.decipher();
  getch();
  return 0;
}
