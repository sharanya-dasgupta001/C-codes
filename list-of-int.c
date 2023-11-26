#include "common.h"

typedef struct{
    int size;
    int *list;
}LIST;

LIST* initialize(){
    printf("199");
    LIST* L;
    printf("170");
    (*L).size = 0;
    printf("180");
    (*L).list = NULL;
    printf("190");
    return L;
}
void print_list(LIST *L){
    printf("1");
    for (int i = 0; i < (L->size); i++)
    {
        printf("%d ",L->list[i]);
    }
    return;
    
}
void append(LIST* L,int a){
    printf("2");
    L->list = (int*)realloc(L->list,((L->size)+1)*sizeof(int));
    L->list[L->size]=a;
    L->size = L->size + 1;
    return;
}
void prepend(LIST *L,int b){
    printf("3");
    L->list = (int*)realloc(L->list,((L->size)+1)*sizeof(int));
    for (int i = (L->size); i > 0 ; i--)
    {
        L->list[i] = L->list[i-1];
    }
    L->list[0]=b;
    L->size = L->size + 1;
    return;
}
void deleteend(LIST* L){
    printf("4");
    L->size = L->size - 1;
    return;
}
void deletefront(LIST* L){
    printf("5");
    for (int i = 0; i < (L->size) ; i++)
    {
        L->list[i] = L->list[i+1];
    }
     L->size = L->size - 1;
    return;
}
void emptylist(LIST *L){
    printf("6");
    L->size=0;
    free(L);
    return;
}

int main()
{
    LIST *L;
    printf("10");
    L = initialize();
    printf("11");
    append(L, 9);
    print_list(L);
    append(L, 1);
    print_list(L);
    append(L, 3);
    print_list(L);
    append(L, 6);
    print_list(L);
    append(L, 2);
    print_list(L);
    append(L, 7);
    print_list(L);
    append(L, 8);
    print_list(L);
    append(L, 4);
    print_list(L);
    append(L, 2);
    print_list(L);
    append(L, 3);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    printf("13");
    prepend(L, 9);
    print_list(L);
    prepend(L, 9);
    print_list(L);
    deleteend(L);
    print_list(L);
    deletefront(L);
    print_list(L);
    emptylist(L);
    printf("14");
    
}

