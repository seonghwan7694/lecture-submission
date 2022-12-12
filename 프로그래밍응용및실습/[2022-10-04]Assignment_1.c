#include <stdio.h>
int true = 1;
int false = 0;
int lottery[5][6] = {
  {1, 2, 3, 4, 5, 6},
  {10, 15, 25, 35, 40, 42},
  {1, 9, 11, 22, 23, 25},
  {9, 28, 31, 34, 35, 36},
  {1, 9, 23, 28, 33, 35}
};

int cnt = 0;
int bonus = 0;
int input[7];

int main(){
  
  printf("금주의 로또 번호를 입력하세요 -> ");
  for(int i = 0; i < 6; i++){
    scanf("%d", input + i);
  }
  printf("보너스 번호를 입력하세요 -> ");
  scanf("%d", input + 6);

  printf("\n홍길동님의 로또 당첨 결과는 다음과 같습니다.\n\n");
  for(int i = 0; i < 5; i++){
    printf("%d세트 번호<", i + 1);
    for(int j = 0; j < 6; j++){
      printf("%d", lottery[i][j]);
      if(j != 5) printf(" ");
    }
    printf("> -> ");

    cnt = 0, bonus = 0;
    int visited[7] = {false};

    for(int n = 0; n < 6; n++){
      for(int m = 0; m <= 6; m++){
        if(m == 6){
          // printf("X ");
	  visited[n] = false;
          break;
        }
        if(lottery[i][n] == input[m]){
          // printf("%d ", lottery[i][n]);
	  visited[n] = true;
          cnt++;
          break;
        }
      }
    }

    for(int n = 0; n < 6; n++){
	if(lottery[i][n] == input[6]){
		bonus = 1;
		break;
	}
    }

	
    if(cnt != 5){
	for(int n = 0; n < 6; n++){
		if(visited[n]) printf("%d ", lottery[i][n]);
		else printf("X ");
	}
    }else if(bonus == 0){
	for(int n = 0; n < 6; n++){
		if(visited[n]) printf("%d ", lottery[i][n]);
		else printf("X ");
	}
    }else{
	for(int n = 0; n < 6; n++){
		if(visited[n]) printf("%d ", lottery[i][n]);
	}
	printf("%d ", input[6]);
    }
    

    printf("<");

    if(cnt == 3) printf("5등");
    else if(cnt == 4) printf("4등");
    else if(cnt == 5 && bonus == 1) printf("2등");
    else if(cnt == 5) printf("3등");
    else if(cnt == 6) printf("1등");
    else printf("꽝");

    printf(">");
    printf("\n");
  }
  return 0;
}
