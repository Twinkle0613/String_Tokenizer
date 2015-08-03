#ifndef OperatorChecker_H
#define OperatorChecker_H

#define isSingleOperator(x) (isSingle(operatorAtrributes[x]))
#define isOperator(x) (isValidOperator(operatorAtrributes[x]))
#define isTwinOperator(x) (isTwin(operatorAtrributes[x]))
#define isAssignOperator(x) (isAssign(operatorAtrributes[x]))
#define isTwinassign(x) (isTwinAssign(operatorAtrributes[x]))
#define SINGLE (1<<0)
#define TWIN (1<<1)
#define ASSIGNMENT (1<<2)
#define TWIN_ASSIGNMENT (1<<3)

extern int operatorAtrributes[];
int isSingle(int symbol);
int isTwin(int symbol);
int isAssign(int symbol);
int isTwinAssign(int symbol);
int isValidOperator(int symbol);

#endif // OperatorChecker_H
