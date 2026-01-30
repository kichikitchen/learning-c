#include <stdio.h>
#include <string.h>

//学習記録の要素数
#define N 5

typedef struct {
    char date[11];      // "2026-01-30" 形式
    int minutes;        // 学習時間（分）
    char topic[50];     // 学習内容
} StudyRecord;

//レコード入力用関数
void input_record(StudyRecord *rec){
    if(rec == NULL){
        printf("メモリ参照エラー\n");
        return;
    }
    strcpy(rec->date, "2026-01-01");
    rec->minutes = 30;
    strcpy(rec->topic, "メタ倫理学入門");
}

//総学習時間を返す関数
int calc_total(const StudyRecord *records, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=records[i].minutes;
    }
    return sum;
}

//最長学習記録を返す関数
int find_max_index(const StudyRecord *records, int n){
    int index = 0;
    for(int i=0;i<n;i++){
        index = records[i].minutes > records[index].minutes ? i : index;
    }
    return index;
}

//統計表示用関数
void print_summary(const StudyRecord *records, int n){
    if(records == NULL){
        printf("メモリ参照エラー\n");
        return;
    }
    printf("=== 学習記録統計 ===\n");
    int SumTotalRecords = calc_total(records,n);
    printf("合計時間: %d分\n",SumTotalRecords);
    printf("平均時間: %.1f分\n",(double)SumTotalRecords/n);

    int index = find_max_index(records,n);
    printf("最長記録: %s(%s) %d分",records[index].date,records[index].topic,records[index].minutes);
}

int main(void) {

    StudyRecord logs[N];

    // 5件のデータを固定値で初期化
    for(int i=0;i<N;i++){
        input_record(&logs[i]);
    }
    
    // 統計を表示
    print_summary(logs, N);
    
    return 0;
}
