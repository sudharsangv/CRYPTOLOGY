#include<iostream>
using namespace std;
#include<conio.h>
int main()
{
  void cipher(char a[]);
  void decipher(char b[]);
  char a[90],b[90];
  int n;
  cout<<"Menu"
      <<"\n\t1.Caesar encipher"
      <<"\n\t2.Caesar decipher"
      <<"\nPlease choose an option: ";
  cin>>n;
  switch(n)
  {
    case 1:cout<<"\tCaesar Encipher\n";
          cout<<"Enter the string you want to cipher: ";
          cin>>a;
          cipher(a);
          break;
    case 2:cout<<"\tCaesar Decipher\n";
          cout<<"Enter the string that you want to decipher: ";
          cin>>b;
          decipher(b);
          break;
    default:cout<<"Wrong choice";
  }
  getch();
  return 0;
}
void cipher(char a[])
{
  cout<<"The enciphered string: ";
  for(int i=0;a[i]!='\0';++i)
  {
    if(a[i]>=100&&a[i]<=122)
      cout<<(char)(a[i]-3);
    else if(a[i]=='a')
      cout<<'x';
    else if(a[i]=='b')
      cout<<'y';
    else if(a[i]=='c')
      cout<<'z';
    else
      cout<<a[i];
  }
}
void decipher(char b[])
{
  cout<<"The deciphered string is: ";
  for(int i=0;b[i]!='\0';++i)
  {
   if(b[i]>=97&&b[i]<=119)
      cout<<(char)(b[i]+3);
    else if(b[i]=='x')
      cout<<'a';
    else if(b[i]=='y')
      cout<<'b';
    else if(b[i]=='z')
      cout<<'c';
    else
      cout<<b[i];
  }
}
