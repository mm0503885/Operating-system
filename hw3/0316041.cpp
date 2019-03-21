#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>
#include <pthread.h>
#include<semaphore.h>
#include<sys/time.h>
#include <stdio.h>
#include<cstring>
#include <stdlib.h>

using namespace std;

sem_t sem1;
sem_t sem2;
sem_t sem3;
sem_t sem4;
sem_t sem5;
sem_t sem6;
sem_t sem7;
sem_t sem8;
sem_t sem9;
sem_t sem10;
sem_t sem11;
sem_t sem12;
sem_t sem13;
sem_t sem14;
sem_t sem15;
sem_t sem8_1;
sem_t sem9_1;
sem_t sem10_1;
sem_t sem11_1;
sem_t sem12_1;
sem_t sem13_1;
sem_t sem14_1;
sem_t sem15_1;

 pthread_t T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15;

int element_num=0;

int Array[1000000];

int Array_1[1000000];

int pivot1,pivot2,pivot3,pivot4,pivot5,pivot6,pivot7;


void bubble_sort(int arr[], int left,int right) {
	int i, j;
	for (i = 0; i < right-left; i++)
		for (j = left; j < right - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);

}

int quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      return j;
}



void* fun_1(void* ptr)
{
   sem_wait(&sem1);

   pivot1=quickSort(Array,0,element_num-1);

   sem_post(&sem2);
   sem_post(&sem3);
}

void* fun_2(void* ptr)
{
   sem_wait(&sem2);

   pivot2=quickSort(Array,0,pivot1);

   sem_post(&sem4);
   sem_post(&sem5);
}

void* fun_3(void* ptr)
{
   sem_wait(&sem3);

   pivot3=quickSort(Array,pivot1+1,element_num-1);

   sem_post(&sem6);
   sem_post(&sem7);
}

void* fun_4(void* ptr)
{
   sem_wait(&sem4);

   pivot4=quickSort(Array,0,pivot2);

   sem_post(&sem8);
   sem_post(&sem9);
}


void* fun_5(void* ptr)
{
   sem_wait(&sem5);

   pivot5=quickSort(Array,pivot2+1,pivot1);

   sem_post(&sem10);
   sem_post(&sem11);
}

void* fun_6(void* ptr)
{
   sem_wait(&sem6);

   pivot6=quickSort(Array,pivot1+1,pivot3);

   sem_post(&sem12);
   sem_post(&sem13);
}

void* fun_7(void* ptr)
{
   sem_wait(&sem7);

   pivot7=quickSort(Array,pivot3+1,element_num-1);

   sem_post(&sem14);
   sem_post(&sem15);
}

void* fun_8(void* ptr)
{
   sem_wait(&sem8);

   bubble_sort(Array,0,pivot4);

   sem_post(&sem8_1);

}

void* fun_9(void* ptr)
{
   sem_wait(&sem9);

   bubble_sort(Array,pivot4+1,pivot2);

   sem_post(&sem9_1);

}

void* fun_10(void* ptr)
{
   sem_wait(&sem10);

   bubble_sort(Array,pivot2+1,pivot5);

   sem_post(&sem10_1);

}

void* fun_11(void* ptr)
{
   sem_wait(&sem11);

   bubble_sort(Array,pivot5+1,pivot1);

   sem_post(&sem11_1);

}

void* fun_12(void* ptr)
{
   sem_wait(&sem12);

   bubble_sort(Array,pivot1+1,pivot6);

   sem_post(&sem12_1);

}

void* fun_13(void* ptr)
{
   sem_wait(&sem13);

   bubble_sort(Array,pivot6+1,pivot3);

   sem_post(&sem13_1);
}

void* fun_14(void* ptr)
{
   sem_wait(&sem14);

   bubble_sort(Array,pivot3+1,pivot7);

   sem_post(&sem14_1);

}

void* fun_15(void* ptr)
{
   sem_wait(&sem15);

   bubble_sort(Array,pivot7+1,element_num-1);

   sem_post(&sem15_1);

}





int main(void)
{
    struct timeval start;
    struct timeval end;

    struct timeval start_1;
    struct timeval end_1;

    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    sem_init(&sem4, 0, 0);
    sem_init(&sem5, 0, 0);
    sem_init(&sem6, 0, 0);
    sem_init(&sem7, 0, 0);
    sem_init(&sem8, 0, 0);
    sem_init(&sem9, 0, 0);
    sem_init(&sem10, 0, 0);
    sem_init(&sem11, 0, 0);
    sem_init(&sem12, 0, 0);
    sem_init(&sem13, 0, 0);
    sem_init(&sem14, 0, 0);
    sem_init(&sem15, 0, 0);
    sem_init(&sem8_1, 0, 0);
    sem_init(&sem9_1, 0, 0);
    sem_init(&sem10_1, 0, 0);
    sem_init(&sem11_1, 0, 0);
    sem_init(&sem12_1, 0, 0);
    sem_init(&sem13_1, 0, 0);
    sem_init(&sem14_1, 0, 0);
    sem_init(&sem15_1, 0, 0);

    pthread_create(&T1, NULL,fun_1, NULL);
    pthread_create(&T2, NULL,fun_2, NULL);
    pthread_create(&T3, NULL,fun_3, NULL);
    pthread_create(&T4, NULL,fun_4, NULL);
    pthread_create(&T5, NULL,fun_5, NULL);
    pthread_create(&T6, NULL,fun_6, NULL);
    pthread_create(&T7, NULL,fun_7, NULL);
    pthread_create(&T8, NULL,fun_8, NULL);
    pthread_create(&T9, NULL,fun_9, NULL);
    pthread_create(&T10, NULL,fun_10, NULL);
    pthread_create(&T11, NULL,fun_11, NULL);
    pthread_create(&T12, NULL,fun_12, NULL);
    pthread_create(&T13, NULL,fun_13, NULL);
    pthread_create(&T14, NULL,fun_14, NULL);
    pthread_create(&T15, NULL,fun_15, NULL);


     string file_name;

    cout<<"Please enter the file name: ";
    cin>>file_name;

    char * File_name = new char [file_name.length()+1];
    strcpy (File_name,file_name.c_str());


    FILE *in;
    in = fopen(File_name, "r");

    fscanf(in,"%d",&element_num);

    for(int i=0;i<element_num;i++)
    {
       fscanf(in,"%d",&Array[i]);
    }


    for(int i=0;i<element_num;i++)
    {
        Array_1[i]=Array[i];
    }

    gettimeofday(&start, 0);

    sem_post(&sem1);


    sem_wait(&sem8_1);
    sem_wait(&sem9_1);
    sem_wait(&sem10_1);
    sem_wait(&sem11_1);
    sem_wait(&sem12_1);
    sem_wait(&sem13_1);
    sem_wait(&sem14_1);
    sem_wait(&sem15_1);

    gettimeofday(&end, 0);


    gettimeofday(&start_1, 0);

    bubble_sort(Array_1,0,element_num-1);

    gettimeofday(&end_1, 0);


    float sec= end.tv_sec-start.tv_sec;
    float usec = end.tv_usec-start.tv_usec;
    float sec_1= end_1.tv_sec-start_1.tv_sec;
    float usec_1 = end_1.tv_usec-start_1.tv_usec;

    cout<<"multi‐thread sorting elapsed "<<sec*1000+(usec/1000.0)<<" ms"<<endl;

    cout<<"single‐thread sorting elapsed "<<sec_1*1000+(usec_1/1000.0)<<" ms"<<endl;


    fstream out1,out2;
    out1.open("output1.txt",ios::out);

    out2.open("output2.txt",ios::out);

    for(int i=0;i<element_num;i++)
    {
        if(i==element_num-1) out1<<Array[i];
        else
        out1<<Array[i]<<' ';
    }

    for(int i=0;i<element_num;i++)
    {
        if(i==element_num-1) out2<<Array_1[i];
        else
        out2<<Array_1[i]<<' ';
    }








}
