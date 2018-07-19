#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "SequentialStack.h"

//int型栈的实现
intStack* intCreateStack() //建栈,第一个位置从0开始；
{
	intStack* p = (intStack*)malloc(sizeof(intStack));
	p->array = (int*)malloc(MAXSIZE*sizeof(int));
	p->Top = 0; 
	p->len = MAXSIZE;  
	return p;
}
void intPush(intStack* PtrS, int item) 
{
	if(PtrS->Top >= PtrS->len)
	{
		int *array =  (int*)malloc((PtrS->Top  + MAXSIZE)*sizeof(int));
		int L = PtrS->len;
		memcpy(array, PtrS->array, L * sizeof(int));
		free(PtrS->array);
		PtrS->array = array;
		PtrS->len = L + MAXSIZE;
		
	}
	PtrS->array[PtrS->Top++] = item;
	//printf("%d Push success!\n", PtrS->array[PtrS->Top - 1]);
	
}

int intPop(intStack * PtrS)  //出栈；
{
	if(PtrS->Top == 0)
	{
		printf("This is an empty stack!\n");
		return 0;
	}
	int data =  PtrS->array[PtrS->Top - 1];
	PtrS->Top = PtrS->Top - 1;
	return data;
}

int intIsEmpty(intStack* S)   //判断栈是否为空；
{
	if (S->Top == 0)
	{
		
		//printf("This is an empty stack!\n");
		return 1;
	}
	else
	{
		//printf("This is not an empty stack!\n");
		return 0;
	}
}

void intClearStack(intStack* PtrS) //清除栈
{
	free(PtrS);
	//printf("ClearStack success!\n");
}

int intGetTop(intStack* s)       //得到栈顶元素
{
	if(s->Top == 0)
	{
		//printf("This is an empty stack!");
		return 0;
	}
	int data =  s->array[s->Top - 1];
}

//char型栈的实现
charStack* charCreateStack() //建栈,第一个位置从0开始；
{
	charStack* p = (charStack*)malloc(sizeof(charStack));
	p->array = (char*)malloc(MAXSIZE*sizeof(char));
	p->Top = 0; 
	p->len = MAXSIZE;  
	return p;
}

void charPush(charStack* PtrS, char item) //入栈函数
{
	if(PtrS->Top >= PtrS->len)
	{
		char *array =  (char*)malloc((PtrS->Top  + MAXSIZE)*sizeof(char));
		char L = PtrS->len;
		memcpy(array, PtrS->array, L * sizeof(char));
		free(PtrS->array);
		PtrS->array = array;
		PtrS->len = L + MAXSIZE;
		
	}
	PtrS->array[PtrS->Top++] = item;
	//printf("%c Push success!\n", PtrS->array[PtrS->Top - 1]);
	
}

char charPop(charStack * PtrS)  //出栈；
{
	if(PtrS->Top == 0)
	{
		//printf("This is an empty stack!\n");
		return 0;
	}
	char data =  PtrS->array[PtrS->Top - 1];
	PtrS->Top = PtrS->Top - 1;
	return data;
}

int charIsEmpty(charStack* S)   //判断栈是否为空；
{
	if (S->Top == 0)
	{
		
		//printf("This is an empty stack!\n");
		return 1;
	}
	else
	{
		//printf("This is not an empty stack!\n");
		return 0;
	}
}

void charClearStack(charStack* PtrS)     //清除栈的函数
{
	free(PtrS);
	//printf("ClearStack success!\n");
}

char charGetTop(charStack* s)             //得到栈顶元素
{
	if(s->Top == 0)
	{
		//printf("This is an empty stack!");
		return 0;
	}
	char data =  s->array[s->Top - 1];
}

//double型栈的实现
doubleStack* doubleCreateStack() //建栈,第一个位置从0开始；
{
	doubleStack* p = (doubleStack*)malloc(sizeof(doubleStack));
	p->array = (double*)malloc(MAXSIZE*sizeof(double));
	/*for (double i = 0; i < MAXSIZE; i++)
	{
		p->array[i] = 0;
	}*/
	p->Top = 0; 
	p->len = MAXSIZE;  
	return p;
}

void doublePush(doubleStack* PtrS, double item)     //入栈函数
{
	if(PtrS->Top >= PtrS->len)
	{
		double *array =  (double*)malloc((PtrS->Top  + MAXSIZE)*sizeof(double));
		double L = PtrS->len;
		memcpy(array, PtrS->array, L * sizeof(double));
		free(PtrS->array);
		PtrS->array = array;
		PtrS->len = L + MAXSIZE;
		
	}
	PtrS->array[PtrS->Top++] = item;
	//printf("%f Push success!\n", PtrS->array[PtrS->Top - 1]);
	
}

double doublePop(doubleStack * PtrS)  //出栈；
{
	if(PtrS->Top == 0)
	{
		//printf("This is an empty stack!\n");
		return 0;
	}
	double data =  PtrS->array[PtrS->Top - 1];
	PtrS->Top = PtrS->Top - 1;
	return data;
}

int doubleIsEmpty(doubleStack* S)   //判断栈是否为空；
{
	if (S->Top == 0)
	{
		
		//printf("This is an empty stack!\n");
		return 1;
	}
	else
	{
		//printf("This is not an empty stack!\n");
		return 0;
	}
}

void doubleClearStack(doubleStack* PtrS)    //清除栈
{
	free(PtrS);
	//printf("ClearStack success!\n");
}

double doubleGetTop(doubleStack* s)        //得到栈顶元素
{
	if(s->Top == 0)
	{
		//printf("This is an empty stack!");
		return 0;
	}
	double data =  s->array[s->Top - 1];
}