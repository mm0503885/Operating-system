#include<iostream>
#include<unistd.h>
#include<string>
#include <sys/types.h>
#include <cstring>
#include <sys/wait.h>


using namespace std;


int main()
{
  while(1){

    cout<<">";
    string s;
    getline(cin,s);

    char* argv[1000]={NULL};  //1000�� cstring �w�]NULL

    int a=0;  //program��argument name������
    int aa=0;  //program��argument ���argv������m
    int start=0; //program��argument name���_�l�I
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ') a++;
        else  //�J�ť� ������
        {
           string s1=s.substr(start,a);
           char* cstr = new char [s1.length()+1];
           strcpy (cstr, s1.c_str()); //string�ഫ��cstring
           argv[aa]=cstr;
           aa++;
           a=0;
           start=i+1;
        }

    }
    //�̫᪺�ťդ����٦��@��argument �A���@������
    string s1=s.substr(start,a);
           char* cstr = new char [s1.length()+1];
           strcpy (cstr, s1.c_str());
           argv[aa]=cstr;
    int flag=0;  //�ΨӧP�_�O�_blocked on a child process
    char* AND="&";
    // �̫�@��argument�O& �h����blocked arugment�ܦ^NULL flag�]1
    if(strcmp(argv[aa],AND)==0)
    {
       argv[aa]=NULL;
       flag=1;
    }
    // ��blocked parent process��wait
    if(flag==0)
    {
      pid_t pid;
    /* fork another process */
      pid= fork();
      if (pid< 0)
      { /* error occurred */
        exit(-1);
      }
      else if (pid== 0)
      { /* child process */
        execvp(argv[0],argv);
        exit(0);
      }
      else
      { /* parent process */
              /* parent will wait for the child to complete */
        wait (NULL);
      }
    }
    else  //flag==1 �Lblocked parent process����wait
    {
      pid_t pid;
    /* fork another process */
      pid= fork();
      if (pid< 0)
      { /* error occurred */
        exit(-1);
      }
      else if (pid== 0)
      { /* child process */
        execvp(argv[0],argv);
        exit(0);
      }
      else
      { /* parent process */
              /* parent will not wait for the child to complete */
        signal(SIGCHLD, SIG_IGN); //���T���Xparent process���ݭn���Dchild process���������A
      }
    }

  }
}
