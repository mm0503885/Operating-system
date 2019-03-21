#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void my_find(char* directory,int inode,char* name,float size_min,float size_max,int inode_condition,int name_condition,int size_min_condition,int size_max_condition)
{
    DIR *dir;
    DIR *dir2;

    struct dirent *ptr;

    dir=opendir(directory);

    while((ptr=readdir(dir))!=NULL)
    {
      char next_file[500];
      sprintf(next_file,"%s/%s",directory,ptr->d_name);

      struct stat buf;
      stat(next_file, &buf);

      if(S_ISDIR(buf.st_mode) && (strcmp(ptr->d_name,".")!=0) && (strcmp(ptr->d_name,"..")!=0) )
      {
         my_find(next_file,inode,name,size_min,size_max,inode_condition,name_condition,size_min_condition,size_max_condition);
      }

      if (inode_condition==0 || ptr->d_ino==inode)
      {
         if (name_condition==0 || strcmp(name,ptr->d_name)==0)
         {
             if (size_min_condition==0 || size_min <= ((float)buf.st_size/1048576))
             {
                 if (size_max_condition==0 || size_max >= ((float)buf.st_size/1048576))
                    printf("%s %llu %f MB\n",next_file,ptr->d_ino,((float)buf.st_size/1048576));
             }
         }
      }
    }
}

int main(int argc, const char * argv[])
{
    char inode_char[500];
    char name[500];
    char size_min_char[500];
    char size_max_char[500];
    char directory[500];

    strcpy(directory,argv[1]);

    int inode;
    float size_min;
    float size_max;

    int inode_condition=0;
    int name_condition=0;
    int size_min_condition=0;
    int size_max_condition=0;
    int i=2;

    while(i<argc)
    {
        if (strcmp(argv[i],"-inode")==0)
        {
            i++;
            strcpy(inode_char,argv[i]);
            inode=atoi(inode_char);
            inode_condition=1;
            i++;
        }
        else if (strcmp(argv[i],"-name")==0)
        {
            i++;
            strcpy(name,argv[i]);
            name_condition=1;
            i++;

        }
        else if (strcmp(argv[i],"-size_min")==0)
        {
            i++;
            strcpy(size_min_char,argv[i]);
            size_min=atof(size_min_char);
            size_min_condition=1;
            i++;

        }
        else if (strcmp(argv[i],"-size_max")==0)
        {
            i++;
            strcpy(size_max_char,argv[i]);
            size_max=atof(size_max_char);
            size_max_condition=1;
            i++;

        }
        else i++;
    }

    my_find(directory,inode,name,size_min,size_max,inode_condition,name_condition,size_min_condition,size_max_condition);




}

