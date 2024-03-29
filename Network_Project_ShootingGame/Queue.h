#pragma once

#include <stdio.h>

#include <stdlib.h>



#define NEXT(index,QSIZE)   ((index+1)%QSIZE)  //원형 큐에서 인덱스를 변경하는 매크로 함수


typedef struct pos {
    int x;
    int y;
} pos;


typedef struct Queue //Queue 구조체 정의

{

    pos * buf;//저장소

    int qsize;

    int front; //꺼낼 인덱스(가장 오래전에 보관한 데이터가 있는 인덱스)

    int rear;//보관할 인덱스

    int count;//보관 개수



}Queue;



void InitQueue(Queue* queue, int qsize);//큐 초기화

int IsFull(Queue* queue); //큐가 꽉 찼는지 확인

int IsEmpty(Queue* queue); //큐가 비었는지 확인

void Enqueue(Queue* queue, pos data); //큐에 보관

pos Dequeue(Queue* queue); //큐에서 꺼냄

void DisposeQueue(Queue* queue);//큐 해제화





void InitQueue(Queue* queue, int qsize)

{

    queue->buf = (pos*)malloc(sizeof(pos) * qsize);

    queue->qsize = qsize;

    queue->front = queue->rear = 0; //front와 rear를 0으로 설정

    queue->count = 0;//보관 개수를 0으로 설정

}

int IsFull(Queue* queue)

{

    return queue->count == queue->qsize;//보관 개수가 qsize와 같으면 꽉 찬 상태

}

int IsEmpty(Queue* queue)

{

    return queue->count == 0;    //보관 개수가 0이면 빈 상태

}

void Enqueue(Queue* queue, pos data)

{

    if (IsFull(queue))//큐가 꽉 찼을 때

    {

        printf("큐가 꽉 찼음\n");

        return;

    }

    queue->buf[queue->rear] = data;//rear 인덱스에 데이터 보관

    queue->rear = NEXT(queue->rear, queue->qsize); //rear를 다음 위치로 설정

    queue->count++;//보관 개수를 1 증가

}

pos Dequeue(Queue* queue)

{

    pos re = { 0, 0 };

    if (IsEmpty(queue))//큐가 비었을 때

    {

        printf("큐가 비었음\n");

        return re;

    }

    re = queue->buf[queue->front];//front 인덱스에 보관한 값을 re에 설정

    queue->front = NEXT(queue->front, queue->qsize);//front를 다음 위치로 설정

    queue->count--;//보관 개수를 1 감소

    return re;

}

void DisposeQueue(Queue* queue)

{

    free(queue->buf);

}