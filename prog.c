#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int sum;
void *runner(void *param);
int main(int argc,char *argv[])
{
  pthread_t t;
  pthread_attr_t attr;
  if(argc!=2)
    {
      fprintf(stderr,"usage:a.out<integer value>\n");
    }
  if(atoi(argv[1])<0)
    {
      printf("error\n");
    }
    pthread_attr_init(&attr);
    pthread_create(&t,&attr,runner,argv[1]);
    pthread_join(t,NULL);
    printf("sum=%d\n",sum);
  return -1;
}
void *runner(void *param)
{
  int i,upper=atoi(param);
  sum=0;
  for(i=0;i<upper;++i)
    sum+=i;
  pthread_exit(0);
}
