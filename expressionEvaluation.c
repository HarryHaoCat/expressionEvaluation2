/*************************************************************************
	> File Name: expressionEvaluation.c
	> Author: HaoJie
	> Mail: 954487858@qq.com 
	> Created Time: 2018年07月16日 星期一 16时22分53秒
 ************************************************************************/

#include <stdio.h>
#include "SequentialStack.h"
#include <math.h>
#include <ctype.h>

//操作符优先级计算函数
int getNumOfExpression(char* postfixExpression, double numberArray[]);
int Isproper(char *postfixExpression,  double numberArray[]); 
int Priority(char c)
{
	switch(c)
	{
		case '(': return 0; 
		case '+':           
		case '-': return 1; 
		case '*':           
		case '/': return 2; 
		default:  return 0;
	}
}

//中缀转后缀
int infixToPostfix(char* infixExpression, char postfixExpression[])
{
	charStack* s = charCreateStack();
	int index = 0;
	int numIndex = 0;
	int proper = 0;
	while(infixExpression[index] != '\0')
	{
		//如果是操作数
		if(infixExpression[index] != '+' && infixExpression[index] != '-' && infixExpression[index] != '*' && infixExpression[index] != '/' && infixExpression[index] != '(' && infixExpression[index] != ')')
		{
			postfixExpression[numIndex++] = infixExpression[index];
		}
		//如果是左括号
		else if(infixExpression[index] == '(')
		{
			charPush(s, infixExpression[index]);
		}
		//如果是运算符
		else if(infixExpression[index] == '+' || infixExpression[index] == '-'|| infixExpression[index] == '*' || infixExpression[index] == '/' || infixExpression[index] == ')')
		{

			//若栈为空,直接将运算符进栈
			if(charIsEmpty(s))
			{
				postfixExpression[numIndex++] = ' ';
				charPush(s, infixExpression[index]);
			}
			//否则栈不为空的话
			else 
			{
                //若为右括号,将栈中左括号之前的符号全部弹出
				if(infixExpression[index] == ')')
				{
					postfixExpression[numIndex++] = ' ';
					
					while(charGetTop(s) != '(')
					{
						postfixExpression[numIndex++] = charPop(s);
					}
					charPop(s);  //弹出左括号
				}
				//如果不为左括号,判断符号的优先级
				else
				{
					//优先级较大的运算符直接进栈
					if(Priority(infixExpression[index]) > Priority(charGetTop(s)))
					{
						postfixExpression[numIndex++] = ' ';
						charPush(s, infixExpression[index]);
					}
					//否则将栈顶元素打出,这个元素入栈
					else if(Priority(infixExpression[index]) <= Priority(charGetTop(s)))
					{
						postfixExpression[numIndex++] = charPop(s);
						charPush(s, infixExpression[index]);
						index++;
						continue;   //重新开始一次循环
					}
				}
			}

		}
		index++;
	}
    while(!charIsEmpty(s))
    {
    	postfixExpression[numIndex++] = charPop(s);
    }
	postfixExpression[numIndex++] = ' ';   //在后缀表达式的最后加一个空格
	double numberArray[100] = {0.0};    
    int number = getNumOfExpression(postfixExpression, numberArray);
	proper = Isproper(postfixExpression, numberArray); 
    return proper;

}

//计算后缀表达式
int computeValueFromPostfix(char* postfixExpression, double *value)
{
	double numberArray[100] = {0.0};
	int numIndex = 0;
	int number = getNumOfExpression(postfixExpression, numberArray);
	doubleStack* ds = doubleCreateStack(); 
	int i = 0; 
	while(numIndex <= number)
	{
		double num1,num2 = 0.0;
		
		if(numberArray[numIndex] == -1.0 || numberArray[numIndex] == -2.0 || numberArray[numIndex] == -3.0 || numberArray[numIndex] == -4.0)
		{
			num1 = doublePop(ds);
			num2 = doublePop(ds);

			switch((int)numberArray[numIndex])
			{
				case -1:
						doublePush(ds,  num2 + num1); 
						break;
				case -2: 
						doublePush(ds,  num2 - num1);  
						break;
				case -3: 
						doublePush(ds,  num2 * num1); 
						break;
				case -4: 
						doublePush(ds,  (double)num2 / num1);  
						break;
				default: break;
 			}
		}
		else
		{
			doublePush(ds, numberArray[numIndex]);
		}
		numIndex++;

	}
	//将数组重新清空
	for(int i = 0; i < 100; i++)
        postfixExpression[i] = '\0';
    *value = (double)(doublePop(ds)/1.0);
    //printf("sizeof value: %d\n", sizeof(*value));
    return 1;
}

//得到后缀表达式中double型的操作数
int getNumOfExpression(char* postfixExpression, double numberArray[])
{
	doubleStack* ds = doubleCreateStack(); 
	int postIndex = 0;
	int numArrayIndex = 0;
	while(postfixExpression[postIndex] != '\0')
	{
		if(postfixExpression[postIndex] == '+' || postfixExpression[postIndex] == '-' || postfixExpression[postIndex] == '*' || postfixExpression[postIndex] == '/' || postfixExpression[postIndex] == ' ')
		{
			if(!doubleIsEmpty(ds))
			{
				int len = ds->Top;
				for(int j = 0; j < len; j++)
					numberArray[numArrayIndex] += pow(10.0, j) * doublePop(ds);
				numArrayIndex++;
			}
			switch(postfixExpression[postIndex])
			{
				case '+': numberArray[numArrayIndex++] = -1.0; break;
				case '-': numberArray[numArrayIndex++] = -2.0; break;
			    case '*': numberArray[numArrayIndex++] = -3.0; break;
				case '/': numberArray[numArrayIndex++] = -4.0; break;
				case ' ': break;
			}
		}	
		else
		{
			doublePush(ds, (double)(postfixExpression[postIndex] - '0'));
		}

	    postIndex++;
	}
    return numArrayIndex-1;
}

//判断表达式是否合法
int Isproper(char *postfixExpression, double numberArray[])
{
	int index = 0;
	int i = 0;
	charStack* brace = charCreateStack();
	int operator = 0;
	int Digit = 0;
	int blank = 0;
    //开头是右括号直接返回0
	if(postfixExpression[1] == ')')
	{
		printf("There are improper braces in your expression!\n");
		return 0;
	}
	//进行一次遍历
	while(postfixExpression[index] != '\0')
	{
		if('a'<= postfixExpression[index] && postfixExpression[index]<= 'z')
        {
        	printf("There are illegal characters in your expression!\n");
			return 0;
        }
        //使用char栈进行括号合法性的判断,遇到左括号就进栈,遇到右括号若不为空就出栈
        else if(postfixExpression[index] == '(')
        	charPush(brace, postfixExpression[index]);
        else if(postfixExpression[index] == ')')
        {
        	if(!charIsEmpty)
            	charPop(brace);
            //遇到右括号,若此时栈为空,则说明之前没有左括号
            else{
            	printf("There are improper braces in your expression!\n");
            	return 0;

            }
        }
        //统计空格的个数
        else if(postfixExpression[index] == ' ')
       		blank++;
      
        index++;

	}

	//对括号栈的合法性进行判断
	if(!charIsEmpty(brace))
	{
		printf("There are improper braces in your expression!\n");
			return 0;
	}
	
	//对全空的判断
	if(blank == index)
	{
		printf("This is an empty expression!\n");
		blank = 0;
		return 0; 
	}

	while(numberArray[i] != '\0')
	{
		if(numberArray[i] == -1.0 || numberArray[i] == -2.0 || numberArray[i] == -3.0 || numberArray[i] == -4.0)
        	{
        		operator++;
        	}
        else if(numberArray[i] != ' ')
        {
        	Digit++;
        }
        i++;
	}
	//对运算符和运算数个数进行判断,正确的表达式操作数总比操作符多一个
	if(operator != Digit - 1)
	{
		if(operator == 0)
		{
			printf("There are illegal spaces in your expression!\n");
			return 0;
		}
		else
		{
			printf("There are insufficient operands in your expression!\n");
			return 0;
	    }
	    operator = Digit = 0;
	}
	//正常情况返回值1
	return 1;
}

