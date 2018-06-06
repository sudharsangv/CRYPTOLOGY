#include<iostream>
using namespace std;
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
void cipher(char* a)
{
  int l;
  for(int i=0;a[i]!='\0';++i)
  {
    if(islower(a[i]))
    {
      l=a[i]-97;
      a[i]=122-l;
    }
    else
    {
      l=a[i]-65;
      a[i]=90-l;
    }
  }
  cout<<"The ciphered string: "<<a;
}
void decipher(char* b)
{
  int l;
  for(int i=0;b[i]!='\0';++i)
  {
    if(islower(b[i]))
    {
      l=122-b[i];
      b[i]=97+l;
    }
    else
    {
      l=90-b[i];
      b[i]=65+l;
    }
  }
  cout<<"The deciphered string: "<<b;
}
int main()
{
  char ch;
  int n;
  do
  {
    char str[30];
    cout<<"Menu:"
        <<"\n\t1.Atbash cipher"
        <<"\n\t2.Atbash decipher"
        <<"\nPlease choose your option: ";
    cin>>n;
    switch(n)
    {
      case 1:cout<<"\tAtbash cipher\n";
            cout<<"Enter a string to cipher: ";
            cin>>str;
            cipher(str);
            break;
      case 2:cout<<"\tAtbash decipher\n";
            cout<<"Enter a string to decipher: ";
            cin>>str;
            decipher(str);
            break;
      default:cout<<"Wrong choice";
    }
    cout<<"\nDo you want to continue?";
    cin>>ch;
  } while(ch=='y');
  getch();
  return 0;
}
/*char change(char c,int d)
{
  char a[2][26],b;
  for(int i=0;i<26;++i)
    a[0][i]=tolower((char)65+i);
  for(int j=0;j<26;++j)
    a[1][j]=tolower((char)90-j);
  for(int i=0;i<26;++i)
    cout<<a[0][i]<<" ";
  cout<<endl;
  for(int j=0;j<26;++j)
    cout<<a[1][j]<<" ";
  if(d==1)
  {
    for(int i=0;i<26;++i)
    {
      if(c==a[0][i])
        return a[1][i];
      else if(tolower(c))
        return toupper(a[1][i]);
      else
        return '0';
    }
  }
  else
  {
    for(int i=0;i<26;++i)
    {
      if(c==a[1][i])
        return a[0][i];
      else if(tolower(c)==a[1][i])
        return toupper(a[0][i]);
      else
        return '0';
    }
  }
}*/
