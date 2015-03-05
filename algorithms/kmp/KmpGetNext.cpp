#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int *GetNext(char *t){
	int tlen=strlen(t);
	int *next=new int[tlen];
	if(!next)  return 0;
	next[0]=-1;
	int i=0,j=next[i];
	while(i<tlen){
		if(j==-1 || t[i]==t[j]){
			i++;
			j++;
			next[i]=j;//next[i]=next[i-1]+1;这一步是书上的，但貌似不通用，下一个题目这样做wa了
		}
		else
			j=next[j];
	}
	for (int i = 0;i < tlen; ++i)
		cout << next[i] << " ";
	// cout << endl;
	return next;
}
int StrIndex_KMP(char *s,char *t,int pos){
	int *next=GetNext(t);
	int slen,tlen;
	slen=strlen(s);
	tlen=strlen(t);
	int i=pos,j=0;
	while(i<slen && j<tlen){
		if(j==-1 || s[i]==t[j]){
			i++;
			j++;
		}
		else
			j=next[j];
	}
	delete []next; //必须加这一步，否则无法释放内存导致程序异常终止
	next=NULL; //安全，哥是被指针搞怕了
	if(j==tlen)
		return i; //匹配成功返回子串的下一个字符的下标，下一匹配开始点
	else
		return -1;
}
int main(){
	char s[1005],t[1005];
	while(scanf("%s",s)==1 && s[0]!='#'){
		 scanf("%s",t);
		 int times=0,pos=0;
		 while(pos!=-1){
			 pos=StrIndex_KMP(s,t,pos);
			 if(pos!=-1)
				 times++;
		 }
		 printf("%d\n",times);
	}
  //  system("pause");
	return 0;
}