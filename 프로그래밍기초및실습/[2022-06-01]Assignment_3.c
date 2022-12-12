#include <stdio.h>
#include <string.h>

void print_student_info(char student_info[][3][10]){
	printf("\n%-10s%-10s%-10s\n", "이름", "학번", "점수");
	for(int i = 0; i < 20; i++){
		for(int k = 0; k < 3; k++){
			printf("%-10s", student_info[i][k]);
		}
		printf("\n");
	}
	printf("\n");
}

void swap_student_info(char A_student[3][10], char B_student[3][10]){
	char tmp[10];
	for(int i = 0; i < 3; i++){
		strcpy(tmp, A_student[i]);
		strcpy(A_student[i], B_student[i]);
		strcpy(B_student[i], tmp);
	}
}

void sort_student_info(char student_info[][3][10], int cmd, int opt){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < i; j++){
			if(opt == -1){
				if(strcmp(student_info[i][cmd], student_info[j][cmd]) > 0){
					swap_student_info(student_info[i], student_info[j]);
				}
			}
			if(opt == 1){
				if(strcmp(student_info[i][cmd], student_info[j][cmd]) < 0){
					swap_student_info(student_info[i], student_info[j]);
				}
			}
		}
	}
}

int main(){
	char student_info[20][3][10] =
	{
		{"Sophia", "20220001", "98"},
		{"Olivia", "20220010", "96"},
		{"Riley", "20220002", "88"},
		{"Emma", "20220015", "77"},
		{"Ava", "20220009", "82"},

		{"Isabella", "20220014", "93"},
		{"Aria", "20220020", "84"},
		{"Amelia", "20220005", "79"},
		{"Mia", "20220016", "90"},
		{"Liam", "20220008", "80"},
		
		{"Noah", "20220012", "89"},
		{"Jackson", "20220004", "99"},
		{"Aiden", "20220018", "78"},
		{"Elijah", "20220017", "83"},
		{"Grayson", "20220003", "92"},

		{"Lucas", "20220013", "71"},
		{"Oliver", "20220007", "72"},
		{"Caden", "20220019", "68"},
		{"Mateo", "20220011", "96"},
		{"David", "20220006", "76"}
	};

	while("true"){
		printf("%-20s	%-20s\n%-20s	%-20s\n%-20s\n\n%-20s",
				"1. 이름 오름차순 출력", "2. 학번 오름차순 출력",
				"3. 점수 내림차순 출력", "4. 이름 검색",
				"5. 종료", "번호를 선택하세요 : ");
		int num; scanf("%d", &num);
		if(num == 1){
			sort_student_info(student_info, 0, 1);
			print_student_info(student_info);
		}else if(num == 2){
			sort_student_info(student_info, 1, 1);
			print_student_info(student_info);
		}else if(num == 3){
			sort_student_info(student_info, 2, -1);
			print_student_info(student_info);
		}else if(num == 4){
			char tmp[10]; printf("%s", "이름을 입력하세요 : "); scanf("%s", tmp);
			for(int i = 0; i < 20; i++){
				if(strcmp(student_info[i][0], tmp) == 0){
					printf("\n%-10s%-10s%-10s\n", "이름", "학번", "점수");
					for(int k = 0; k < 3; k++){
						printf("%-10s", student_info[i][k]);
					}
					printf("\n\n");
				}
			}
		}else if(num == 5){
			printf("\n$");
			break;
		}
	}
	return 0;
}	
