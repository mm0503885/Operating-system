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

    char* argv[1000]={NULL};  //1000個 cstring 預設NULL

    int a=0;  //program或argument name的長度
    int aa=0;  //program或argument 放到argv內的位置
    int start=0; //program或argument name的起始點
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ') a++;
        else  //遇空白 做切割
        {
           string s1=s.substr(start,a);
           char* cstr = new char [s1.length()+1];
           strcpy (cstr, s1.c_str()); //string轉換成cstring
           argv[aa]=cstr;
           aa++;
           a=0;
           start=i+1;
        }

    }
    //最後的空白之後還有一個argument 再做一次切割
    string s1=s.substr(start,a);
           char* cstr = new char [s1.length()+1];
           strcpy (cstr, s1.c_str());
           argv[aa]=cstr;
    int flag=0;  //用來判斷是否blocked on a child process
    char* AND="&";
    // 最後一個argument是& 則不用blocked arugment變回NULL flag設1
    if(strcmp(argv[aa],AND)==0)
    {
       argv[aa]=NULL;
       flag=1;
    }
    // 有blocked parent process需wait
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
    else  //flag==1 無blocked parent process不需wait
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
        signal(SIGCHLD, SIG_IGN); //明確指出parent process不需要知道child process的結束狀態
      }
    }

  }
}
