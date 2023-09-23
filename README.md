# Well-Parenthesized-Expressions
Evaluating a well parenthesized expression using C language

In an expression, several types of parentheses can be used ( ) or [ ]. An expression is said to be well "parenthesized" if any opening parenthesis is followed, further on, by a closing parenthesis of the same type. Furthermore, any closing parenthesis of a certain type must be preceded by an opening parenthesis of the of the same type that is not yet closed.

The postfixed notation of algebraic expressions makes it possible to do without parentheses. It is the result of a postfixed path of the tree representing the expression. For example, for the expression ((a+b)c) we obtain the postfixed expression ab+c.

Add a function to the program that evaluates the postfixed expression produced. This function uses a stack for the operands:

- in the presence of an operand (a to z) the user is asked for its value and it is stacked;
- in the presence of an operator, the corresponding operation is performed, with the two values located at the top of the stack (the top of the stack and the and the next element) and the result is stacked;
- at the end of the evaluation, the value located on the stack corresponds to the result.
