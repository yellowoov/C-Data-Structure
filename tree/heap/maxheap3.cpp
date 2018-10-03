#pragma warning (disable : 4996)
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "max_heap.h"

int main() {

    int    c, data;
    int     key;
    Element item;

    printf("************* Command ************ \n");
    printf("1: Insert data, 2: Delete max data \n");
    printf("3: Print heap, 4: Quit             \n");
    printf("********************************** \n");

    while (1) {
        printf("\nCommand> ");
        c = toupper(c);
        switch (c) {
        case '1':
            printf("\n key and data: ");
            scanf("%d %c", &key, &data);
            item.key = key;
            item.data = data;
            insert_max_heap(item);
            break;
        case '2':
            item = delete_max_heap();
            printf("\n Max: key %d, data %c \n", item.key, item.data);
            break;
        case '3':
            printf("\n");
            max_heap_show();
            break;
        case '4':
            printf("\n");
            exit(1);
        default: break;
        }
    }
}

void insert_max_heap(Element item) {
    int i;
    i = ++heap_size;
    while ((i != 1) && (item.key > heap[i / 2].key)) {// item의 키값이 더 크다면 위쪽으로 올라감
        heap[i] = heap[i / 2];
        i = i / 2;
    } // item의 키보다 더 큰 키값이 없어지면 heap에 item 저장
    heap[i] = item;
}

Element delete_max_heap() {
    Element max = heap[1];
    Element temp;
    int p = 1;
    int c = 2;
    if (is_heap_empty()) { // heap이 비어있다면 empty출력
        printf("\n Heap is empty\n");
        exit(EXIT_FAILURE);
    }
    temp = heap[heap_size--];
    while (c <= heap_size) {
        if ((c < heap_size) && (heap[c].key < heap[c + 1].key))// key가 더 큰 c를 찾음
            c++;
        if (temp.key >= heap[c].key)// temp 키가 c키보다 더 크면 반복문 종료
            break;
        heap[p] = heap[c]; // 큰 값을 위로 올림
        p = c;
        c = c * 2;
    }
    heap[p] = temp; // heap[p]에 temp값 저장
    return max; // 삭제된 값인 max 리턴
}
void max_heap_show() { // 출력
    for (int i = 1; i <= heap_size; i++)
        printf(" %d %c\n", heap[i].key, heap[i].data);
}
bool is_heap_empty() { // 비어있는지
    return (heap_size == 0);
}
