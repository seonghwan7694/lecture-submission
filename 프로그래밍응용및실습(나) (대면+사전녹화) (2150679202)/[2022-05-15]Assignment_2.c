#include <stdio.h>

int make_decimal(int n){
	int decimal = 0;
	int tmp = 1;
	int copy = n;
	if(copy >= 10000000) n -= 10000000;
	while(n!=0){
		if(n%10==1){
			decimal += tmp;
			tmp *= 2;
			n/=10;
		}else{
			tmp *= 2;
			n/=10;
		}
	}
	if(copy >= 10000000) return -128 + decimal;
	return decimal;
}

void make_binary(int n){
	if(n<0){
		n += 128;
		printf("1");
	}else{
		printf("0");
	}
	int a = 128;
	int r = 2;
	for(int i = 6; i >= 0; i--){
		a = (int) (a/r);
		if(n/a >= 1){
			printf("1");
			n -= a;
		}else{
			printf("0");
		}
	}
	return;
}

int main(){
	printf("1. 이진수 변환기    2. 이진수 덧셈기    3. 이진수 뺄셈기\n");
	printf("번호를 선택하세요 : ");
	int number, n0, n1, n2, r1, r2, R3; scanf("%d", &number);
	switch(number){
		case 1:
			printf("8비트 이진수를 입력하세요 : ");
			scanf("%d", &n0);
			printf("십진수로 %d입니다.\n", make_decimal(n0));
			break;
		case 2:
			printf("첫 번째 8비트 이진수를 입력하세요 : ");
			scanf("%d", &n1);
			printf("두 번째 8비트 이진수를 입력하세요 : ");
			scanf("%d", &n2);
			r1 = make_decimal(n1);
			r2 = make_decimal(n2);
			printf("두 이진수의 합은 ");
			// 보수작업
			if(r1 + r2 > 127){
				R3 = r1 + r2 - 256;
			}else if(r1 + r2 < -128){
				R3 = r1 + r2 + 256;
			}else{
				R3 = r1 + r2;
			}
			// 끝
			make_binary(R3);
			printf(" 이고, 십진수로 %d입니다.\n", R3);
			break;
		case 3:
			printf("첫 번째 8비트 이진수를 입력하세요 : ");
			scanf("%d", &n1);
			printf("두 번째 8비트 이진수를 입력하세요 : ");
			scanf("%d", &n2);
			r1 = make_decimal(n1);
			r2 = make_decimal(n2);
			printf("두 이진수의 차는 ");
			// 보수작업
			if(r1 - r2 > 127){
				R3 = r1 - r2 - 256;
			}else if(r1 - r2 < -128){
				R3 = r1 - r2 + 256;
			}else{
				R3 = r1 - r2;
			}
			make_binary(R3);
			printf(" 이고, 십진수로 %d입니다.\n", R3);
			break;
		}
	return 0;
}
			

