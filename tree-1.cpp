#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

//tree nodes
class TreeNodes {

public:
char info;
//lefts and rights - branches of the bst 
TreeNodes *leftBranch, *rightBranch;

//class constructors
TreeNodes(char info)

{

//pointers
this->info = info;

//set to null
this->leftBranch = NULL;

this->rightBranch = NULL;

}
};

//new class
class NodesStack

{

public:

TreeNodes *treeNode;

NodesStack *next;

//Constructor

NodesStack(TreeNodes *treeNode)

{

this->treeNode = treeNode;

next = NULL;

}

};

//Class to create the expression tree

class treeType

{

private:

NodesStack *top;

public:

//Constructor

treeType()
{
top = NULL;
}

//tree clearing

void Clearing(){
top = NULL;
}

//push operation of the stack

void push(TreeNodes *ptr) {

if (top == NULL)

top = new NodesStack(ptr);
else
{
  //pointer
NodesStack *newPointer = new NodesStack(ptr);
  //next
newPointer->next = top;
top = newPointer;
}
}

//popping off stack

TreeNodes *pop() {

if (top == NULL) {

cout << "Incorrect." << endl;
}
else {

}


TreeNodes *ptr = top->treeNode;

top = top->next;

return ptr;


}

//Get the top node of the stack

TreeNodes *peekLocation()

{ return top->treeNode;}

//method to insert character

void insert(char valOperand)

{

//Checking val greater than 0 or less than 9
if (valOperand >= '0' && valOperand <= '9')
{

TreeNodes *newPointer = new TreeNodes(valOperand);
//push new pointer on stack
push(newPointer);
}

//else if operator
else if (valOperand == '+' || valOperand == '-' || valOperand == '*' || valOperand == '/')
{

TreeNodes *newPointer = new TreeNodes(valOperand);
newPointer->leftBranch = pop(); //left branch pointer
newPointer->rightBranch = pop(); //right branch pointer 
push(newPointer);

}
else
{

cout << "Invalid." << endl;

return;

}

}

//input, build tree
void buildTree(string equation)

{

for (int x = equation.length() - 1; x >= 0; x--)

insert(equation[x]);

}

//evaluate tree

double expEvaluate()

{

return expEvaluate(peekLocation());

}

//find answer of expression

double expEvaluate(TreeNodes *ptr)

{

if (ptr->leftBranch == NULL && ptr->rightBranch == NULL)

return ptr->info-'0';

else

{

double finalAnswer = 0.0;

double leftBranch = expEvaluate(ptr->leftBranch);

double rightBranch = expEvaluate(ptr->rightBranch);

char operands = ptr->info;

switch (operands)

{

case '+':

finalAnswer = leftBranch + rightBranch;

break;

case '-':

finalAnswer = leftBranch - rightBranch;

break;

case '*':

finalAnswer = leftBranch * rightBranch;

break;

case '/':

finalAnswer = leftBranch / rightBranch;

break;

default:

finalAnswer = leftBranch + rightBranch;

break;

}

return finalAnswer;

}

}

//method to get postfix expression

void postfix()

{

ordering(peekLocation());

}

//traversals 
void ordering(TreeNodes *ptr)

{

if (ptr != NULL)

{

ordering(ptr->leftBranch);

ordering(ptr->rightBranch);

cout << ptr->info;

}

}

};

int main() {

string str;
//print tree
cout << "Prefix to tree form: " << endl;

treeType preForm;

cout << "\nEnter an equation in Prefix form: ";

cin >> str;

preForm.buildTree(str);

cout << "\nPostfix : ";

preForm.postfix();

//Result/answer

cout << "\n Answer: " << preForm.expEvaluate();
return 0;

}