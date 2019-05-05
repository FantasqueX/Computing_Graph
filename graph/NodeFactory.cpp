#include "node.h"
#include "Operand.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"
#include "TernaryOperation.h"
#include "NodeFactory.h"

#include <string>

using std::string;

 Node* NodeFactory::createNode(string placeholderName, string type)
{
    if ((type == "P")||(type == "Placeholder"))
        return new Placeholder(placeholderName);
}

 Node* NodeFactory::createNode(string Name, string type, float value)
{
    if ((type == "C")||(type == "Constant"))
        return new Constant(Name, value);
    if ((type == "V")||(type == "Variable"))
        return new Variable(Name, value);
}

 Node* NodeFactory::createNode(string Name, string type, Node* parent1)
{
    if ((type == "PRINT")||(type == "Print"))
        return new Print(Name, parent1);
    if ((type == "SIN")||(type == "Sin"))
        return new Sin(Name, parent1);
    if ((type == "EXP")||(type == "Exp"))
        return new Exp(Name, parent1);
    if ((type == "LOG")||(type == "Log"))
        return new Log(Name, parent1);
    if ((type == "TANH")||(type == "Tanh"))
        return new Tanh(Name, parent1);
    if ((type == "SIGMOID")||(type == "Sigmoid"))
        return new Sigmoid(Name, parent1);
}

 Node* NodeFactory::createNode(string Name, string type, Node* parent1, Node* parent2)
{
    if ((type == "+")||(type == "ADD")||(type == "PLUS"))
        return new Sum(Name, parent1, parent2);
    if ((type == "-")||(type == "MINUS")||(type == "Subtraction"))
        return new Subtraction(Name, parent1, parent2);
    if ((type == "*")||(type == "Multiply"))
        return new Multiply(Name, parent1, parent2);
    if ((type == "/"))
        return new Division(Name, parent1, parent2);
    if ((type == ">"))
        return new GTR(Name, parent1, parent2);
    if ((type == "<"))
        return new LSS(Name, parent1, parent2);
    if ((type == ">="))
        return new GEQ(Name, parent1, parent2);
    if ((type == "<="))
        return new LEQ(Name, parent1, parent2);
    if ((type == "=="))
        return new EQU(Name, parent1, parent2);
    
}

 Node* NodeFactory::createNode(string Name, string type, Node* parent1, Node* parent2, Node* parent3)
{
    if ((type == "COND")||(type=="Cond"))
        return new Cond(Name, parent1, parent2, parent3);
}