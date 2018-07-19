/*************************************************************************
	> File Name: expressionEvaluation.h
	> Author: HaoJie
	> Mail: 954487858@qq.com 
	> Created Time: 2018年07月16日 星期一 16时22分47秒
 ************************************************************************/
#ifndef _EXPRESSIONEVALUATION_H_
#define _EXPRESSIONEVALUATION_H_
#include<stdio.h>
int infixToPostfix(char* infoxExpression, char postfixExpression[]);      //中缀转后缀
int computeValueFromPostfix(char* postfixExpression, double *value);      //计算后缀表达式
int Priority(char c);                                                     //操作符优先级计算函数
int getNumOfExpression(char* postfixExpression, double numberArray[]);    //得到后缀表达式中double型的操作数
int Isproper(char *postfixExpression,  double numberArray[]);             //计算得到的后缀表达式的合法性
#endif

