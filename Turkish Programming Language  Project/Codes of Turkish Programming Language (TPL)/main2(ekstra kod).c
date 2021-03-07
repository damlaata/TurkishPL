#include<stdio.h>
#include<ctype.h>
#include<string.h>
void keyw(char *p);
int i=0,id=0,kw=0,num=0,op=0;
char keys[32][10]={"kir","esitle","ekle","durum","karakter","sabit","artsin","yakala",
"yap","katli","yanlisise","basla","bitir","noktali","kosullarinda","artsin",
"eger","tam","uzun","register","don","kisa","katar",
"boyut","statik","yapi","sec","tiptani","tek",
"isaretsiz","sadece","dog","iken"};
main()
{
	char ch,str[25],seps[15]=" \t\n,|:;(){}[]#\"<>",oper[]="!%^&*-+=~<>/?";
	int j;
	char fname[50];
	FILE *f1;
	
//Eger.txt Calistiriliyor. Farkli bir metin dosyasi için eger.txt yerine metin.txt seklinde yazabilirsiniz.
f1 = fopen("eger.txt","r");

	if(f1==NULL)
	{
	 printf("dosya bulununamadi");
	 exit(0);
	}
printf("**************************************************************************\n");
	while((ch=fgetc(f1))!=EOF)
	{
for(j=0;j<=14;j++)
{
if(ch==oper[j])
{
printf("%c islem operatorudur.\n",ch);
op++;
str[i]='\0';
keyw(str);
}
}
for(j=0;j<=14;j++)
{
if(i==-1)
break;
if(ch==seps[j])
{

if(ch=='#')
{
while(ch!=')')
{
printf("%c",ch);
ch=fgetc(f1);
}
printf("%c is a ekle file\n",ch);
i=-1;
break;
}
if(ch=='"')
{
do
{
ch=fgetc(f1);
printf("%c",ch);
}while(ch!='"');
printf("\b degiskendir.\n");
i=-1;
break;
}
str[i]='\0';
keyw(str);
}
}
if(i!=-1)
{
str[i]=ch;
i++;
}
else
i=0;
	}
printf("**************************************************************************\n");
printf("anahtar kelime: %d\ntanimlayici: %d\nislem operatoru: %d\nsayi: %d\n",kw,id,op,num);
printf("**************************************************************************");
//getch();
}
void keyw(char *p)
{
int k,flag=0;
for(k=0;k<=31;k++)
{
if(strcmp(keys[k],p)==0)
{
printf("%s anahtar kelimedir.\n",p);
kw++;
flag=1;
break;
}
}
if(flag==0)
{
if(isdigit(p[0]))
{
printf("%s sayidir.\n",p);
num++;
}
else
{
//if(p[0]!=13&&p[0]!=10)
if(p[0]!='\0')
{
printf("%s tanimlayicidir.\n",p);
id++;
}
}
}
i=-1;
}
