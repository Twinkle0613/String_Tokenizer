#ifndef OperatorChecker_H
#define OperatorChecker_H

#define issingleOperator(x) (isSingle(operatorAtrributes[x]))
#define isoperator(x) (isOperator(operatorAtrributes[x]))
#define istwinOperator(x) (isTwin(operatorAtrributes[x]))
#define isassignOperator(x) (isAssign(operatorAtrributes[x]))
#define istwinassign(x) (isTwinAssign(operatorAtrributes[x]))
#define SINGLE (1<<0)
#define TWIN (1<<1)
#define ASSIGNMENT (1<<2)
#define TWIN_ASSIGNMENT (1<<3)

extern int operatorAtrributes[];
int isSingle(int symbol);
int isTwin(int symbol);
int isAssign(int symbol);
int isTwinAssign(int symbol);
int isOperator(int symbol);

#endif // OperatorChecker_H
