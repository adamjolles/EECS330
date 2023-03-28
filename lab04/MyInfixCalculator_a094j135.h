#ifndef __MYINFIXCALCULATOR_H__
#define __MYINFIXCALCULATOR_H__

#include <algorithm>
#include <string>

#include "MyStack_a094j135.h"
#include "MyVector_a094j135.h"

class MyInfixCalculator
{

public:
    MyInfixCalculator()
    {
    }

    ~MyInfixCalculator()
    {
    }

    double calculate(const std::string &s)
    {
        // code begins
        MyVector<std::string> infix_tokens;
        tokenize(s, infix_tokens);
        MyVector<std::string> postfix_tokens;
        infixToPostfix(infix_tokens, postfix_tokens);

        return calPostfix(postfix_tokens);
        // code ends
    }

private:
    // returns operator precedance; the smaller the number the higher precedence
    // returns -1 if the operator is invalid
    // does not consider parenthesis
    int operatorPrec(const char c) const
    {
        switch (c)
        {
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 3;
        case '-':
            return 3;
        default:
            return -1;
        }
    }

    // checks if a character corresponds to a valid parenthesis
    bool isValidParenthesis(const char c) const
    {
        switch (c)
        {
        case '(':
            return true;
        case ')':
            return true;
        default:
            return false;
        }
    }

    // checks if a character corresponds to a valid digit
    bool isDigit(const char c) const
    {
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }

    // computes binary operation given the two operands and the operator in their string form
    double computeBinaryOperation(const std::string &ornd1, const std::string &ornd2, const std::string &opt) const
    {
        double o1 = std::stod(ornd1);
        double o2 = std::stod(ornd2);
        switch (opt[0])
        {
        case '+':
            return o1 + o2;
        case '-':
            return o1 - o2;
        case '*':
            return o1 * o2;
        case '/':
            return o1 / o2;
        default:
            std::cout << "Error: unrecognized operator: " << opt << std::endl;
            return 0.0;
        }
    }

    // tokenizes an infix string s into a set of tokens (operands or operators)
    void tokenize(const std::string &s, MyVector<std::string> &tokens)
    {
        // code begins
        for (size_t i = 0; i <= s.size() - 1; i++)
        {                         
            if (isDigit(s[i]) || (s[i] == '-' && isDigit(s[i + 1]) && (i == 0 || (!isDigit(s[i - 1]) && s[i - 1] != ')'))))
            {
                std::string tmp; 
                tmp += s[i];     
                i++;             
                while (i <= s.size() - 1 && (isDigit(s[i]) || s[i] == '.'))
                {                
                    tmp += s[i];
                    i++;         
                }
                if (i <= s.size() - 1 && isDigit(s[i]) == false)
                {        
                    i--; 
                }
                
                tokens.push_back(tmp); 
            }
            else if (isValidParenthesis(s[i]))
            {                            
                std::string par(1, s[i]); 
                tokens.push_back(par);   
            }
            else
            {                           
                std::string op(1, s[i]); 
                tokens.push_back(op);    
            }
        }
        // code ends
    }

    // converts a set of infix tokens to a set of postfix tokens
    void infixToPostfix(MyVector<std::string> &infix_tokens, MyVector<std::string> &postfix_tokens)
    {
        // code begins
        MyStack<std::string> operatorStack;
        for (const auto &token : infix_tokens)
        {
            if (isDigit(token[0]) || (token.length() >= 2 && isDigit(token[1])))
            {
                postfix_tokens.push_back(token);
            }
            else if (isValidParenthesis(token[0]))
            {
                if (token[0] == '(')
                {
                    operatorStack.push(token);
                }
                else
                {
                    while (!operatorStack.empty() && operatorStack.top() != "(")
                    {
                        postfix_tokens.push_back(operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                }
            }
            else if (operatorPrec(token[0]) >= 0)
            {
                while (!operatorStack.empty() && (operatorStack.top() != "(" && operatorPrec(token[0]) >= operatorPrec(operatorStack.top()[0])))
                {
                    postfix_tokens.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                operatorStack.push(token);
            }
        }
        while (!operatorStack.empty())
        {
            postfix_tokens.push_back(operatorStack.top());
            operatorStack.pop();
        }
        // code ends
    }

    // calculates the final result from postfix tokens
    double calPostfix(const MyVector<std::string> &postfix_tokens) const
    {
        // code begins
        MyStack<double> operand;
        for (const auto &token : postfix_tokens)
        {
            if (isDigit(token[0]) || (token.size() > 1 && token[0] == '-' && isDigit(token[1])))
            {
                operand.push(std::stod(token));
            }
            else if (operatorPrec(token[0]) >= 0)
            {
                double operand_2 = operand.top();
                operand.pop();
                double operand_1 = operand.top();
                operand.pop();
                double result = computeBinaryOperation(std::to_string(operand_1), std::to_string(operand_2), token);
                operand.push(result);
            }
        }
        return operand.top();
        // code ends
    }
};

#endif // __MYINFIXCALCULATOR_H__