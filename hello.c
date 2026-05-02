#include<stdio.h>
int mysum(int a,int b){
	if(a>b) return mysum(b,a);
	int res = 0;
	for(int i=a;i<=b;i++){
		res+=i;
	}
	return res;

}
int main(){
	int a = 123, b = 543;
	int c = mysum(a,b);
	printf("%d\n",c);
	printf("%d + %d = %d\n",a,b,a+b);
	printf("helloworld\n");
	return 0;
}
