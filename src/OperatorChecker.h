#ifndef OperatorChecker_H
#define OperatorChecker_H

#define issingle(x) (isSingle(operatorAtrributes[x]))
#define isoperator(x) (isOperator(operatorAtrributes[x]))
#define istwin(x) (isTwin(operatorAtrributes[x]))
#define isassign(x) (isAssign(operatorAtrributes[x]))
#define istwinassign(x) (isTwinAssign(operatorAtrributes[x]))
#define SINGLE (1<<0)
#define TWIN (1<<1)
#define ASSIGNMENT (1<<2)
#define TWIN_ASSIGNMENT (1<<3)

extern int operatorAtrributes[];
int isSingle(int Operator);
int isTwin(int Operator);
int isAssign(int Operator);
int isTwinAssign(int Operator);
int isOperator(int Operator);

#endif // OperatorChecker_H
