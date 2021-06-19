#pragma once

#include <stdio.h>

#include <stdlib.h>



#define NEXT(index,QSIZE)   ((index+1)%QSIZE)  //���� ť���� �ε����� �����ϴ� ��ũ�� �Լ�


typedef struct pos {
    int x;
    int y;
} pos;


typedef struct Queue //Queue ����ü ����

{

    pos * buf;//�����

    int qsize;

    int front; //���� �ε���(���� �������� ������ �����Ͱ� �ִ� �ε���)

    int rear;//������ �ε���

    int count;//���� ����



}Queue;



void InitQueue(Queue* queue, int qsize);//ť �ʱ�ȭ

int IsFull(Queue* queue); //ť�� �� á���� Ȯ��

int IsEmpty(Queue* queue); //ť�� ������� Ȯ��

void Enqueue(Queue* queue, pos data); //ť�� ����

pos Dequeue(Queue* queue); //ť���� ����

void DisposeQueue(Queue* queue);//ť ����ȭ





void InitQueue(Queue* queue, int qsize)

{

    queue->buf = (pos*)malloc(sizeof(pos) * qsize);

    queue->qsize = qsize;

    queue->front = queue->rear = 0; //front�� rear�� 0���� ����

    queue->count = 0;//���� ������ 0���� ����

}

int IsFull(Queue* queue)

{

    return queue->count == queue->qsize;//���� ������ qsize�� ������ �� �� ����

}

int IsEmpty(Queue* queue)

{

    return queue->count == 0;    //���� ������ 0�̸� �� ����

}

void Enqueue(Queue* queue, pos data)

{

    if (IsFull(queue))//ť�� �� á�� ��

    {

        printf("ť�� �� á��\n");

        return;

    }

    queue->buf[queue->rear] = data;//rear �ε����� ������ ����

    queue->rear = NEXT(queue->rear, queue->qsize); //rear�� ���� ��ġ�� ����

    queue->count++;//���� ������ 1 ����

}

pos Dequeue(Queue* queue)

{

    pos re = { 0, 0 };

    if (IsEmpty(queue))//ť�� ����� ��

    {

        printf("ť�� �����\n");

        return re;

    }

    re = queue->buf[queue->front];//front �ε����� ������ ���� re�� ����

    queue->front = NEXT(queue->front, queue->qsize);//front�� ���� ��ġ�� ����

    queue->count--;//���� ������ 1 ����

    return re;

}

void DisposeQueue(Queue* queue)

{

    free(queue->buf);

}