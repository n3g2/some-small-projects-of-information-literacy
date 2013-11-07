/***
*ElemType.cpp - ElemType的实现
*	
****/

#include <stdio.h>
#include "ElemType.h"

int compare(ElemType x, ElemType y)
{
	return(x-y);
}

void visit(ElemType e)
{
	printf("%d\n", e);
}
