#include "calc.h"

void ExprSolver::exprSolver(std::vector<std::string>& expr)
{
    while (expr.size() != 1)
    {
        std::vector<std::string>::iterator it = firstOperatorIndex(expr);
        makeCalc(expr, it);
    }
}

void ExprSolver::makeCalc(std::vector<std::string>& expr, std::vector<std::string>::iterator it)
{
    if (*it == "(")
    {
        if (*(it + 1) == ")")
        {
            expr = {"Error"};
        }

        else
        {
            expr.erase(it + 2);
            expr.erase(it);
        }
    }

    else
    {
        double num1 = stod(*(it - 1));
        double num2 = stod(*(it + 1));
        
        double result = 0;
        switch ((*it)[0])
        {
            case '+':
                result = num1 + num2;
                break;

            case '-':
                result = num1 - num2;
                break;

            case '*':
                result = num1 * num2;
                break;

            case '/':
                if (num2 == 0)
                {
                    expr = {"Error"};
                    return;
                }

                else
                {
                    result = num1 / num2;
                }

                break;
        }

        *(it - 1) = std::to_string(result);
        expr.erase(it, it + 2);
    }
}

std::vector<std::string>::iterator ExprSolver::firstOperatorIndex(std::vector<std::string>& expr)
{
    auto max_op = expr.end();
    for (auto it = expr.begin(); it != expr.end(); ++it)
    {
        if (*it == ")")
        {
            break;
        }

        if (isOperator(*it) && (max_op == expr.end() ||
            *max_op == "(" || m_op_presedence[*it] > m_op_presedence[*max_op]))
        {
            max_op = it;
        }
    }

    return max_op;
}

bool ExprSolver::isOperator(const std::string& op) const
{
    if (m_op_presedence.find(op) == m_op_presedence.end())
    {
        return false;
    }

    return true;
}