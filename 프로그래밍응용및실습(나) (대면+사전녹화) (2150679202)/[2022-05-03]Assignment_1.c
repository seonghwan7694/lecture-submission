#include <stdio.h>

int main(){
	int n;
	printf("-128부터 127까지의 십진수 정수 하나를 입력하세요 : ");
	scanf("%d", &n);
	printf("%d의 이진수는 ", n);
	if(n<0){
		n += 128;
		printf("1");
	}else{
		printf("0");
	}
	int a = 128;
	int r = 2;
	for(int i = 6; i >= 0; i--){
		if(i == 3) printf(" ");
		a = (int) (a/r);
		if(n/a >= 1){
			printf("1");
			n -= a;
		}else{
			printf("0");
		}
	}
	printf(" 입니다.\n");
	return 0;
}
