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
	printf("1. ������ ��ȯ��    2. ������ ������    3. ������ ������\n");
	printf("��ȣ�� �����ϼ��� : ");
	int number, n0, n1, n2, r1, r2, R3; scanf("%d", &number);
	switch(number){
		case 1:
			printf("8��Ʈ �������� �Է��ϼ��� : ");
			scanf("%d", &n0);
			printf("�������� %d�Դϴ�.\n", make_decimal(n0));
			break;
		case 2:
			printf("ù ��° 8��Ʈ �������� �Է��ϼ��� : ");
			scanf("%d", &n1);
			printf("�� ��° 8��Ʈ �������� �Է��ϼ��� : ");
			scanf("%d", &n2);
			r1 = make_decimal(n1);
			r2 = make_decimal(n2);
			printf("�� �������� ���� ");
			// �����۾�
			if(r1 + r2 > 127){
				R3 = r1 + r2 - 256;
			}else if(r1 + r2 < -128){
				R3 = r1 + r2 + 256;
			}else{
				R3 = r1 + r2;
			}
			// ��
			make_binary(R3);
			printf(" �̰�, �������� %d�Դϴ�.\n", R3);
			break;
		case 3:
			printf("ù ��° 8��Ʈ �������� �Է��ϼ��� : ");
			scanf("%d", &n1);
			printf("�� ��° 8��Ʈ �������� �Է��ϼ��� : ");
			scanf("%d", &n2);
			r1 = make_decimal(n1);
			r2 = make_decimal(n2);
			printf("�� �������� ���� ");
			// �����۾�
			if(r1 - r2 > 127){
				R3 = r1 - r2 - 256;
			}else if(r1 - r2 < -128){
				R3 = r1 - r2 + 256;
			}else{
				R3 = r1 - r2;
			}
			make_binary(R3);
			printf(" �̰�, �������� %d�Դϴ�.\n", R3);
			break;
		}
	return 0;
}
			

