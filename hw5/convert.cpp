#include<iostream>
#include<fstream>
using namespace std;

int main()
{
   fstream in;
   in.open("data.txt",ios::in); //ÅªÀÉ
   fstream in2;
   in2.open("data.txt",ios::in);

    fstream out;
    out.open("new_data.txt",ios::out); //¼gÀÉ

    char a;
    for(int i=0;i<4;i++)
    {
        in.get(a);
        out<<a;
    }
    while(in.get(a))
    {
        if(a=='\n')
        {
            if(in.get(a))
            {
              out<<a;
              for(int i=0;i<3;i++)
              {
                in.get(a);
                out<<a;
              }
            }
        }
    }
    while(in2.get(a))
    out<<a;


}
