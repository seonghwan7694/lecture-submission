#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char eng[16];
    char kor[22];
    struct node* next;
}node;

long m, n; int val;

char buffer[30];
bool flag = false;

node** node_arr;
char kor[22], eng[16];

void printf_score(){
    printf("당신의 점수는 %.2lf점 입니다.", n/(double)m * 100);
    while(getchar() != '\n');
    system("clear");
    flag = true;
    return;
}

void printf_node(node* u){
    if(flag) return;
    printf("%s -> ", u->kor);
    scanf("%s", buffer); getchar();

    if(strcmp(buffer, ".quit") == 0){
        return printf_score();
    }

    if(strcmp(buffer, u->eng) == 0){
        printf("correct!\n");
        n++;
    }
    else{
        printf("incorrect!\n");
    }

    if(u->next == NULL){
        return printf_score();
    }else{
        return printf_node(u->next);
    }
    return;
}

node* func(FILE *fp, node* cur){
    if(fscanf(fp, "%s %s", eng, kor) != EOF){
        cur = (node *) malloc(sizeof(node));
        strcpy(cur->eng, eng);
        strcpy(cur->kor, kor);
        m++;
        cur->next = func(fp, cur->next);
        node_arr[n--] = cur;
        return cur;
    }
    n = m - 1;
    node_arr = (node **) malloc(sizeof(node*)*m);
    return NULL;
}

void swap_str(char* s1, char *s2){
    char tmp[30];
    strcpy(tmp, s1);
    strcpy(s1, s2);
    strcpy(s2, tmp);
    return;
}

void swap_node(node* u, node* v){
    swap_str(u->eng, v->eng);
    swap_str(u->kor, v->kor);
    return;
}

void bubble_sort(){
    for(int i = 0; i < m - 1; i++){
        for(int j = i; j < m; j++){
            if(strcmp(node_arr[i]->eng, node_arr[j]->eng) > 0) swap_node(node_arr[i], node_arr[j]);
        }
    }
}

void free_node(node* cur){
    if(cur->next != NULL) free_node(cur->next);
    return free(cur);
}

void temp(node* v){
    printf("%s\n", v->eng);
    if(v->next != NULL)temp(v->next);
    return;
}
int main(){

    FILE *fp;
    fp = fopen("dic.txt", "r");
    node* v = func(fp, v);
    fclose(fp);
    system("clear");
    bubble_sort();
    free(node_arr);
    // temp(v);
    while(1){
        printf(">> 영어 단어 맞추기 프로그램 <<\n");
        printf("%-36s %-36s\n\n", "1. 영어 단어 맞추기", "2. 프로그램 종료");
        printf("번호를 선택하세요: ");
        scanf("%d", &val);
        if(val == 1){
            n = 0;
            flag = false;
            system("clear");
            printf(">> 영어 단어 맞추기 프로그램 <<\n");
            printf_node(v);
        }else{
            system("clear");
            break;
        }
    }

    free_node(v);
    return 0;
}