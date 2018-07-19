#ifndef _STACK_H_
#define _STACK_H_
#define MAXSIZE 1000      //定义最大线性栈的存储空间

typedef struct {
	int* array;
	int Top;
	int len;
}intStack;

//int型的栈
intStack* intCreateStack();					
void intPush(intStack* PtrS, int item);	
int intPop(intStack* PtrS);				
int intIsEmpty(intStack* S);						
void intClearStack(intStack* PtrS);		
int intGetTop(intStack* s);		

//char型栈
typedef struct {
	char* array;
	int Top;
	int len;
}charStack;

charStack* charCreateStack();		
void charPush(charStack* PtrS, char item);	
char charPop(charStack* PtrS);				
int charIsEmpty(charStack* S);						
void charClearStack(charStack* PtrS);		
char charGetTop(charStack* s);		

//double型栈
typedef struct {
	double* array;
	int Top;
	int len;
}doubleStack;

doubleStack* doubleCreateStack();						
void doublePush(doubleStack* PtrS, double item);	
double doublePop(doubleStack* PtrS);				
int doubleIsEmpty(doubleStack* S);						
void doubleClearStack(doubleStack* PtrS);		
double doubleGetTop(doubleStack* s);		


#endif