#include<stdio.h>

void freq(const char *f1name,int n);
void replace(const char *f1name,const char *f2name,int n);
void lengthred(const char *f1name,const char *f2name);
void main()
{
 const char *f1name="text1.txt";
 const char *f2name="text2.txt";
 printf("enter the length of the substring \n");
 int n;
 scanf("%d",&n);
 freq(f1name,n);
 replace(f1name,f2name,n);
 lengthred(f1name,f2name);
}
void freq(const char *f1name,int n)
{
 FILE *f;
 f=fopen(f1name,"r");
 char ch=fgetc(f);
 int len=0;
 
 int ar[n+2];
 for(int i=0;i<n+2;i++)
 ar[i]=0;
 while(ch!=EOF)
 {
 int count0=0,count1=0;
 
 while(count0<n&&count1<n&&(count1+count0)<n)
 {
 if(ch=='1')
 {
 count1++;
 ch=fgetc(f);
 if(ch=='0'||count0>0)
 break;
 }
 else
 {count0++; ch=fgetc(f);}
 }
 if(count1==n&&count0==0)
 ar[n+1]++;
 else
 {for(int i=0;i<n+1;i++)
 {
 if( count0==i && count1==(i+1) )
 ar[i]++;
 else if(count0==i)
 ar[i]++;
 }
 }
 
 }
 fclose(f);
 for(int i=0;i<n+2;i++)
 {
 int j=i;
 if(i<n)
{
 while(j>0)
 { printf("0");j--;}
 printf("1 appears %d times\n",ar[i]);
 }
 else if(i==n)
 {
 while(j>0)
 {printf("0");j--;}
 printf(" appears %d times\n",ar[i]);
 }
 else
 {
 while(j>=n)
 {printf("1");j--;}
 printf(" appears %d times\n",ar[i]);
 }
 }
}
void replace(const char *f1name,const char *f2name,int n)
{
 FILE *f1,*f2;
 f1=fopen(f1name,"r");
 f2=fopen(f2name,"w");
 char ch=fgetc(f1);
 while(ch!=EOF)
 {
 int count0=0,count1=0;
 while(count0<n&&count1<n&&(count0+count1)<n)
 {
 if(ch=='1')
 {
 count1++;
 ch=fgetc(f1);
 if(ch=='0'||count0>0)
 break;
 }
 else
 {count0++; ch=fgetc(f1);}
 }
 if(count0==0&&count1==n)
 fputc((char)(65+n+1),f2);
 for(int i=0;i<n+1;i++)
 {
 if(count0==i&&count1==1)
 {fputc((char)(i+65),f2);break;}
 else if(count0==i&&count1==0)
 fputc((char)(i+65),f2);
 }
 }
 fclose(f1);
 fclose(f2);
}
void lengthred(const char *f1name,const char *f2name)
{
 FILE* f1,*f2;
 f1=fopen(f1name,"r");
 f2=fopen(f2name,"r");
 char ch1=fgetc(f1);
 int c1=0;
 while(ch1!=EOF)
 {
 c1++;
 ch1=fgetc(f1);
 }
 printf("%d\n",c1);
 char ch2=fgetc(f2);
 int c2=0;
 while(ch2!=EOF)
 {
 c2++;
 ch2=fgetc(f2);
 }
 printf("%d\n",c2);
 float red= ((c1-c2)*100)/c1;
 printf("the reduction in length is %f \n",red);
}
