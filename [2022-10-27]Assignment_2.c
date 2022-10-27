#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int n, m, k;

typedef struct{
  char eng[30];
  char kor[30];
}word;

word list[7][10] = {
  {{"elephant", "코끼리"}, {"date", "날짜"}, {"deer", "사슴"}, {"desk", "책상"}, {"diary", "일기"}, {"dish", "접시"}, {"contry", "지역"}, {"clock", "시계"}, {"city", "도시"}, {"church", "교회"}},
  {{"card", "카드"}, {"book", "책"}, {"tree", "나무"}, {"night", "밤"}, {"morning", "아침"}, {"fuel", "연료"}, {"bird", "새"}, {"chair", "의자"}, {"cow", "소"}, {"ceiling", "천장"}},
  {{"boy", "남자"}, {"purple", "보라색"}, {"cake", "케이크"}, {"noon", "낮"}, {"tail", "꼬리"}, {"history", "역사"}, {"shore", "항구"}, {"table", "테이블"}, {"cream", "크림"}, {"curtain", "커튼"}},
  {{"bridge", "다리"}, {"red", "빨간색"}, {"bread", "빵"}, {"winter", "겨울"}, {"head", "머리"}, {"math", "수학"}, {"sea", "바다"}, {"name", "이름"}, {"cup", "컵"}, {"chicken", "닭"}},
  {{"car", "차"}, {"green", "초록색"}, {"water", "겨울"}, {"spring", "봄"}, {"arm", "팔"}, {"english", "영어"}, {"fish", "물고기"}, {"space", "공간"}, {"church", "교회"}, {"result", "결과"}},
  {{"captain", "우두머리"}, {"blue", "파란색"}, {"meal", "식사"}, {"bow", "활"}, {"soil", "흙"}, {"korea", "한국"}, {"trash", "쓰레기"}, {"chance", "기회"}, {"bus", "버스"}, {"output", "출력"}},
  {{"cap", "모자"}, {"white", "흰색"}, {"summer", "여름"}, {"winter", "겨울"}, {"fire", "불"}, {"candy", "캔디"}, {"can", "캔"}, {"course", "코스"}, {"cousin", "사촌"}, {"input", "입력"}}
};

void clear_buffer(){
  while(getchar() != '\n');
}

void swap(word *x, word * y){
  word tmp;

  strcpy(tmp.eng, x->eng);
  strcpy(tmp.kor, x->kor);

  strcpy(x->eng, y->eng);
  strcpy(x->kor, y->kor);
  
  strcpy(y->eng, tmp.eng);
  strcpy(y->kor, tmp.kor);
}


void shuffle(){
  srand(time(NULL));
  for(int i = 0; i < 9; i++){
    int j = rand() % (10 - i) + i;
    swap(&list[m][i], &list[m][j]);
  }
}

void initialize_console(){
  system("clear");
  printf(">> 영어 단어 암기 프로그램 <<\n");
  printf("%-30s %-30s %-30s\n\n", "1. 플래쉬 카드", "2. 게임", "3. 프로그램 종료");
  printf("번호를 선택하세요 : ");
  scanf("%d", &n);
  if(n == 3){
    system("clear");
	return;
  }
  printf("학습 일차 : ");
  scanf("%d", &m); m--;
  if(n == 2) return;
  printf("출력 방식(수동모드 : 1, 자동모드 : 2) : ");
  scanf("%d", &k);
}

void flash_card(){
  shuffle();

  void init_console(){
    system("clear");
    printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n\n\n");
  }

  clear_buffer();

  if(k == 1){
    for(int i = 0; i < 10; i++){
      do{
        init_console();
        printf("%s\n", list[m][i].eng);
      }while(getchar() != '\n');   

      do{
        init_console();
        printf("%s\n", list[m][i].kor);
      }while(getchar() != '\n');
    }
  }else if(k == 2){
    for(int i = 0; i < 10; i++){
      init_console();
      printf("%s\n", list[m][i].eng);
      system("sleep 1");

      init_console();
      printf("%s\n", list[m][i].kor);
      system("sleep 1");
    }
  }
}

void game(){
  srand(time(NULL));

  char people[3][10] = {
    "         ",
    "         ",
    "         "
  };
  char eng_word[30] = "", c = '\0';
  int cnt = 1, idx = rand() % 10, p_cnt = 1;
  bool flag = false;

  void init_console(){
    system("clear");
    printf(">> 영어 단어 암기 프로그램 : 게임 <<\n");
    printf("(힌트) %s\n\n\n", list[m][idx].kor);

    for(int i = 0; i < 3; i++){
      printf("%50s\n", people[i]);
    }

    printf("\n\n\n");
    for(int i = 0; i < strlen(list[m][idx].eng); i++){
      if(eng_word[i] == '\0'){
        printf("_ ");
      }else{
        printf("%c ", eng_word[i]);
      }
    }
    printf("\n%d번째 시도 : ", p_cnt++);
  }

  clear_buffer();
  while(true){
    init_console();
    flag = false;

    c = getchar();
    getchar(); // erase '\n'
    for(int i = 0; i < strlen(list[m][idx].eng); i++){
      if(c == (list[m][idx].eng)[i]){
        eng_word[i] = (list[m][idx].eng)[i];
        flag = true;
      }
    }

    if(!flag){
      if(cnt == 1){
        people[0][2] = 'O';
      }else if(cnt == 2){
        people[1][0] = '/';
      }else if(cnt == 3){
        people[1][4] = '\\';
      }else if(cnt == 4){
        people[1][2] = '|';
      }else if(cnt == 5){
        people[2][1] = '/';
      }else if(cnt == 6){
        people[2][3] = '\\';
      }
      cnt++;
      if(cnt == 7){ // 출력처리 해줘야하는 듯
        system("clear");
        printf(">> 영어 단어 암기 프로그램 : 게임 <<\n");
        printf("(힌트) %s\n\n\n", list[m][idx].kor);

        for(int i = 0; i < 3; i++){
          printf("%50s\n", people[i]);
        }

        printf("\n\n\n");
        for(int i = 0; i < strlen(list[m][idx].eng); i++){
          if(eng_word[i] == '\0'){
            printf("_ ");
          }else{
            printf("%c ", eng_word[i]);
          }
        }
        printf("\n%d번째 시도 : \n", --p_cnt);
        system("sleep 2");
        break;
      }
    }

    if(strcmp(list[m][idx].eng, eng_word) == 0){
      { // 출력처리 해줘야함
        system("clear");
        printf(">> 영어 단어 암기 프로그램 : 게임 <<\n");
        printf("(힌트) %s\n\n\n", list[m][idx].kor);

        for(int i = 0; i < 3; i++){
          printf("%50s\n", people[i]);
        }

        printf("\n\n\n");
        for(int i = 0; i < strlen(list[m][idx].eng); i++){
          if(eng_word[i] == '\0'){
            printf("_ ");
          }else{
            printf("%c ", eng_word[i]);
          }
        }
        printf("\n%d번째 시도 : ", --p_cnt);
      }

      printf("\n");
      printf("      ##########################\n");
      printf("      ### Congratulations!!! ###\n");
      printf("      ##########################\n");
      system("sleep 2");
      return;
    }
  }
}

int main(){
  while(true){
    initialize_console();
    if(n == 1){
      flash_card();
    }else if(n == 2){
      game();
    }else break;
  }
  return 0;
}
