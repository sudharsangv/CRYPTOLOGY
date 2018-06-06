#include<iostream>
using namespace std;
#include<conio.h>
#include<unistd.h>
#include<process.h>
#include<string.h>
#include<fstream>
#include<Windows.h>
class atbash
{
  char a[90],b[90];
public:
  void cipher();
  void decipher();
}a1;
void atbash::cipher()
{
  fstream f1;
  f1.open("Caesar.txt",ios::app);
  cout<<"Enter a string to cipher: ";
  f1<<"Encipher: "<<endl<<"Plain text: ";
  cin>>a;
  f1<<a<<endl;
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
  f1<<"Cipher text: "<<a<<endl;
  f1.close();
}
void atbash::decipher()
{
  fstream f1;
  f1.open("Atbash.txt",ios::app);
  cout<<"Enter a string to decipher: ";
  f1<<"Decipher:"<<endl<<"Cipher text: ";
  cin>>b;
  f1<<b<<endl;
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
  f1<<"Plain text: "<<b<<endl;
  f1.close();
}
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
  fstream f2;
  f2.open("Polybius.txt",ios::app);
  cout<<"Enter a string : ";
  cin>>e;
  f2<<"Encipher: "<<endl<<"Plain text: "<<e<<endl;
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
  f2<<"Cipher text: ";
  for(int w=0;w<i;++w)
  {
    cout<<b[0][w]<<b[1][w];
    f2<<b[0][w]<<b[1][w];
  }
  f2<<endl;
  f2.close();
}
void polybius::decipher()
{
  fstream f2;
  f2.open("Polybius.txt",ios::app);
  cout<<"Enter a message to decipher: ";
  cin>>a;
  f2<<"Decipher:"<<endl<<"Cipher text:"<<a<<endl;
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
  f2<<"Plain text: "<<d<<endl;

  f2.close();
}
char polybius::poly1[5][5]={'a','b','c','d','e',
                            'f','g','h','i','k',
                            'l','m','n','o','p',
                            'q','r','s','t','u',
                            'v','w','x','y','z'};
class caesar
{
  char a[90],b[90];
public:
  void cipher();
  void decipher();
}a3;
void caesar::cipher()
{
  fstream f3;
  f3.open("Caesar.txt",ios::app);
  cout<<"Enter the string you want to cipher: ";
  cin>>a;
  f3<<"Encipher: "<<endl<<"Plain text: "<<a<<endl;
  cout<<"The enciphered string: ";
  f3<<"Cipher text: ";
  for(int i=0;a[i]!='\0';++i)
  {
    if(a[i]>=100&&a[i]<=122)
    {
      cout<<(char)(a[i]-3);
      f3<<(char)(a[i]-3);
    }
    else if(a[i]=='a')
    {
      cout<<'x';
      f3<<'x';
    }
    else if(a[i]=='b')
    {
      cout<<'y';
      f3<<'y';
    }
    else if(a[i]=='c')
    {
      cout<<'z';
      f3<<'z';
    }
    else
    {
      cout<<a[i];
      f3<<a[i];
    }
  }
  f3<<endl;
  f3.close();
}
void caesar::decipher()
{
  fstream f3;
  f3.open("Caesar.txt",ios::app);
  f3<<"Decipher: "<<endl;
  f3<<"Cipher text: ";
  cout<<"Enter the string that you want to decipher: ";
  cin>>b;
  f3<<b<<endl;
  cout<<"The deciphered string is: ";
  f3<<"Plain text: ";
  for(int i=0;b[i]!='\0';++i)
  {
   if(b[i]>=97&&b[i]<=119)
    {
      cout<<(char)(b[i]+3);
      f3<<(char)(b[i]+3);
    }
    else if(b[i]=='x')
    {
      cout<<'a';
      f3<<'a';
    }
    else if(b[i]=='y')
    {
      cout<<'b';
      f3<<'b';
    }
    else if(b[i]=='z')
    {
      cout<<'c';
      f3<<'c';
    }
    else
    {
      cout<<b[i];
      f3<<b[i];
    }
  }
  f3<<endl;
  f3.close();
}
class rail
{
  char a[50],a1[3][20],a2[3][20],b[50];
  int w;
public:
  void cipher();
  void decipher();
}a4;
void rail::cipher()
{
  fstream f4;
  f4.open("Rail fence.txt",ios::app);
  cout<<"Enter a string to encipher: ";
  cin>>a;
  int z=0;
  f4<<"Encipher: "<<endl<<"Plain text: "<<a<<endl;
  int c=strlen(a);
  if((c%3)==0)
  {
    for(int i=0;a[i]!='\0';++i)
    {
      for(int j=0;j<3;++j)
      {
        a1[j][i]=a[z];
        ++z;
      }
    }
    cout<<"The enciphered string: ";
    f4<<"Cipher text: ";
    cout<<a1[0]<<"_"<<a1[1]<<"_"<<a1[2];
    f4<<a1[0]<<"_"<<a1[1]<<"_"<<a1[2]<<endl;

  }
  else
  {
    cout<<"Enciphering not possible";
    f4<<"Cipher text: "<<"Ciphering terminated"<<endl;
  }
  f4.close();
}
void rail::decipher()
{
  fstream f4;
  f4.open("Rail fence.txt",ios::app);
  cout<<"Enter a string to decipher: ";
  f4<<"Decipher: "<<endl;
  cout<<"\n1st Part: ";
  cin>>a2[0];
  cout<<"2nd Part: ";
  cin>>a2[1];
  cout<<"3rd Part: ";
  cin>>a2[2];
  f4<<"Cipher text: "<<a2[0]<<"_"<<a2[1]<<"_"<<a2[2]<<endl;
  char c[50];
  int z=0;
  if(strlen(a2[0])==strlen(a2[1])&&strlen(a2[1])==strlen(a2[2]))
  {
     for(int i=0;i<strlen(a2[0]);++i)
    {
      for(int j=0;j<3;++j)
      {
        c[z]=a2[j][i];
        ++z;
      }
    }
    c[z]='\0';
    f4<<"Plain text: "<<c;
    cout<<"The deciphered string is: "<<c;

  }
  else
  {
    cout<<"Deciphering not possible";
    f4<<"Plain text: "<<"Deciphering terminated"<<endl;
  }
  f4.close();
}
class trifid
{
  char str[30];
  char str1[30];
  static char l1[3][3],l2[3][3],l3[3][3];
public:
  void cipher();
  void decipher();
}a5;
char trifid::l1[3][3]={'a','b','c'
                      ,'d','e','f'
                      ,'g','h','i'};
char trifid::l2[3][3]={'j','k','l'
                      ,'m','n','o'
                      ,'p','q','r'};
char trifid::l3[3][3]={'s','t','u'
                      ,'v','w','x'
                      ,'y','z','.'};
void trifid::cipher()
{
  fstream f5;
  f5.open("Trifid.txt",ios::app);
  int x,y,z;
  int a[30],b[30],c[30];
  int h[90];
  int f=0,g=0;
  cout<<"Enter a message to encipher: ";
  cin>>str;
  f5<<"Encipher:"<<endl<<"Plain text: "<<str<<endl;
  for(int i=0;i<strlen(str);++i)
  {
    for(int j=0;j<3;++j)
      for(int k=0;k<3;++k)
      {
        if(str[i]==l1[j][k])
        {
          a[i]=0;
          b[i]=k;
          c[i]=j;
        }
        else if(str[i]==l2[j][k])
        {
          a[i]=1;
          b[i]=k;
          c[i]=j;
        }
        else if(str[i]==l3[j][k])
        {
          a[i]=2;
          b[i]=k;
          c[i]=j;
        }
      }
  }
  for(int i=0;i<strlen(str);++i)
  {
    h[i]=a[i];
  }
  for(int i=strlen(str);i<2*strlen(str);++i)
  {
    h[i]=b[f];
    ++f;
  }
  for(int j=2*strlen(str);j<3*strlen(str);++j)
  {
    h[j]=c[g];
    ++g;
  }
  cout<<"The enciphered string: ";
  f5<<"Ciphered text: ";
  for(int w=0;w<3*strlen(str);w+=3)
  {
    x=h[w+2];
    y=h[w+1];
    if(h[w]==0)
    {
      cout<<l1[x][y];
      f5<<l1[x][y];
    }
    else if(h[w]==1)
    {
      cout<<l2[x][y];
      f5<<l2[x][y];
    }
    else if(h[w]==2)
    {
      cout<<l3[x][y];
      f5<<l3[x][y];
    }
  }
  f5<<endl;
  f5.close();
}
void trifid::decipher()
{
  fstream f5;
  f5.open("Trifid.txt",ios::app);
  int w,z=0;
  cout<<"Enter a string to decipher: ";
  cin>>str1;
  f5<<"Decipher: "<<endl<<"Cipher text: "<<str1<<endl;
  short a[30],b[30],c[30],h[90];
  for(int i=0;i<strlen(str1);++i)
  {
    for(int j=0;j<3;++j)
      for(int k=0;k<3;++k)
      {
        if(str1[i]==l1[j][k])
        {
          h[z]=0;
          h[z+1]=k;
          h[z+2]=j;
          z+=3;
        }
        else if(str1[i]==l2[j][k])
        {
          h[z]=1;
          h[z+1]=k;
          h[z+2]=j;
          z+=3;
        }
        else if(str1[i]==l3[j][k])
        {
          h[z]=2;
          h[z+1]=k;
          h[z+2]=j;
          z+=3;
        }
      }

  }
  for(int i=0;i<strlen(str1);++i)
  {
    a[i]=h[i];
  }
  int f=0;
  for(int i=strlen(str1);i<2*strlen(str1);++i)
  {
    b[f]=h[i];
    cout<<b[f];
    ++f;
  }
  int g=0;
  for(int i=2*strlen(str1);i<3*strlen(str1);++i)
  {
    c[g]=h[i];
    cout<<c[g];
    ++g;
  }
  int x,y;
  cout<<"The decihered string: ";
  f5<<"Plain text: ";
  for(int i=0;i<z/3;++i)
  {
    x=b[i];
    y=c[i];
    if(a[i]==0)
    {
      cout<<l1[y][x];
      f5<<l1[y][x];
    }
    else if(a[i]==1)
    {
      cout<<l2[y][x];
      f5<<l2[y][x];
    }
    else if(a[i]==2)
    {
      cout<<l3[y][x];
      f5<<l3[y][x];
    }
    f5<<endl;
    f5.close();
  }
}
class bifid: private polybius
{
  char str[30],str1[30];
public:
  void cipher();
  void decipher();
}a6;
void bifid::cipher()
{
  fstream f6;
  f6.open("Bifid.txt",ios::app);
  int a[30],b[30];
  cout<<"Enter a string to encipher: ";
  cin>>str;
  f6<<"Encipher: "<<endl;
  f6<<"Plain text: "<<str<<endl;
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
  f6<<"Cipher text: ";
  int y,x;
  for(int i=0;i<2*strlen(str);i+=2)
  {
    x=h[i];
    y=h[i+1];
    cout<<poly1[x][y];
    f6<<poly1[x][y];
  }
  f6<<endl;
  f6.close();
}
void bifid::decipher()
{
  fstream f6;
  f6.open("Bifid.txt",ios::app);
  int a[30],b[30],c[30],d[30],x,y;
  cout<<"Enter a string to decipher: ";
  cin>>str1;
  f6<<"Decipher: "<<endl;
  f6<<"Cipher text: "<<str1<<endl;
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
  f6<<"Plain text: ";
  for(int i=0;i<strlen(str1);++i)
  {
    x=a[i];
    y=b[i];
    cout<<poly1[x][y];
    f6<<poly1[x][y];
  }
  f6<<endl;
  f6.close();
}
int main()
{
  int n1,n2,n3;
  char ch;
  void atbash();
  void caesar();
  void poly();
  void rail();
  void bifid();
  void trifid();
  //HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
  //SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
  for(int i=0;i<50;++i)
  {
    cout<<"CRYPTOLOGY";
    usleep(60000);
    cout<<"\b\b\b\b\b\b\b\b\b\b ";
  }
  cout<<"          ";
  cout<<"\n\t\tCRYPTOLOGY";
  do
  {
    cout<<"\nMenu: "
        <<"\n\t1.Encipher"
        <<"\n\t2.Decipher"
        <<"\n\t3.Previous enciphers and deciphers"
        <<"\n\t4.Exit"
        <<"\nPlease choose an option: ";
    cin>>n1;
    switch(n1)
    {
      case 1:cout<<"\tENCIPHERING\n";
            cout<<"Menu: "
                <<"\n\t1.Atbash encipher"
                <<"\n\t2.Caesar encipher"
                <<"\n\t3.Polybius square encipher"
                <<"\n\t4.Rail fence encipher"
                <<"\n\t5.Trifid encipher"
                <<"\n\t6.Bifid encipher"
                <<"\n\t7.Exit"
                <<"\nPlease choose an option: ";
            cin>>n2;
            switch(n2)
            {
              case 1:cout<<"\tAtbash cipher\n";
                    a1.cipher();
                    break;
              case 2:cout<<"\tCaesar encipher\n";
                    a3.cipher();
                    break;
              case 3:cout<<"\tPolybius square encipher\n";
                    a2.cipher();
                    break;
              case 4:cout<<"\tRail fence encipher\n";
                    a4.cipher();
                    break;
              case 5:cout<<"\tTrifid encipher\n";
                    a5.cipher();
                    break;
              case 6:cout<<"\tBifid encipher\n";
                    a6.cipher();
                    break;
              case 7:break;
            }
            break;
      case 2:cout<<"\tDECIPHERING\n";
            cout<<"Menu: "
                <<"\n\t1.Atbash decipher"
                <<"\n\t2.Caesar decipher"
                <<"\n\t3.Polybius square decipher"
                <<"\n\t4.Rail fence decipher"
                <<"\n\t5.Trifid decipher"
                <<"\n\t6.Bifid decipher"
                <<"\n\t7.Exit"
                <<"\nPlease choose an option: ";
            cin>>n2;
            switch(n2)
            {
              case 1:cout<<"\tAtbash decipher\n";
                    a1.decipher();
                    break;
              case 2:cout<<"\tCaesar decipher\n";
                    a3.decipher();
                    break;
              case 3:cout<<"\tPolybius square decipher\n";
                    a2.decipher();
                    break;
              case 4:cout<<"\tRail fence decipher\n";
                    a4.decipher();
                    break;
              case 5:cout<<"\tTrifid decipher\n";
                    a5.decipher();
                    break;
              case 6:cout<<"\tBifid decipher\n";
                    a6.decipher();
                    break;
              case 7:break;
            }
            break;
      case 3:cout<<"\tHISTORY\n";
             cout<<"Menu: "
                 <<"\n\t1.Atbash cipher"
                 <<"\n\t2.Caesar cipher"
                 <<"\n\t3.Polybius square cipher"
                 <<"\n\t4.Rail fence cipher"
                 <<"\n\t5.Trifid cipher"
                 <<"\n\t6.Bifid cipher"
                 <<"\n\t7.Exit"
                 <<"\nPlease choose an option: ";
             cin>>n3;
             switch(n3)
             {
               case 1:cout<<"\tAtbash cipher history\n";
                      atbash();
                      break;
               case 2:cout<<"\tCaesar cipher history\n";
                      caesar();
                      break;
               case 3:cout<<"\tPolybius square history\n";
                      poly();
                      break;
               case 4:cout<<"\tRail fence history\n";
                      rail();
                      break;
               case 5:cout<<"\tTrifid cipher history\n";
                      trifid();
                      break;
               case 6:cout<<"\tBifid cipher history\n";
                      bifid();
                      break;
               case 7:break;
             }
             break;
      case 4: for(int i=0;i<50;++i)
             {
               cout<<"THANKYOU";
               usleep(60000);
               cout<<"\b\b\b\b\b\b\b\b ";
             }
            cout<<"          ";
            cout<<"\n\t\tTHANKYOU\n";
            usleep(60000);
            exit(0);
    }
    cout<<"\nDo you want to continue?";
    cin>>ch;
    if(ch!='y')
    {
      for(int i=0;i<50;++i)
      {
        cout<<"THANKYOU";
        usleep(60000);
        cout<<"\b\b\b\b\b\b\b\b ";
      }
      cout<<"          ";
      cout<<"\n\t\tTHANKYOU\n";
      usleep(60000);
      exit(0);
    }
  }while(ch=='y');
  getch();
  return 0;
}
void atbash()
{
  fstream a;
  char t[60];
  a.open("Atbash.txt",ios::in);
  while(a.getline(t,60))
  {
    cout<<t<<endl;
  }
  a.close();
}
void caesar()
{
  fstream b;
  char u[60];
  b.open("Caesar.txt",ios::in);
  while(b.getline(u,60))
  {
    cout<<u<<endl;
  }
  b.close();
}
void poly()
{
  fstream c;
  char v[80];
  c.open("Polybius.txt",ios::in);
  while(c.getline(v,80))
  {
    cout<<v<<endl;
  }
  c.close();
}
void rail()
{
  fstream d;
  char w[60];
  d.open("Rail fence.txt",ios::in);
  while(d.getline(w,60))
  {
    cout<<w<<endl;
  }
  d.close();
}
void trifid()
{
  fstream e;
  char x[60];
  e.open("Trifid.txt",ios::in);
  while(e.getline(x,60))
  {
    cout<<x<<endl;
  }
  e.close();
}
void bifid()
{
  fstream f;
  char y[60];
  f.open("Bifid.txt",ios::in);
  while(f.getline(y,60))
  {
    cout<<y<<endl;
  }
  f.close();
}
//8610441516
