#include "npi.hpp"

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const &s)
{
    for (char c : s)
    {
        if (!std::isdigit(c) && c != '.')
        {
            return false;
        }
    }
    return true;
}

// Exercice 1
float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::stack<float> stack;
    for (std::string token : tokens)
    {
        if (is_floating(token))
        {
            stack.push(std::stof(token));
        }
        else
        {
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            if (token == "+")
            {
                stack.push(a + b);
            }
            else if (token == "-")
            {
                stack.push(a - b);
            }
            else if (token == "*")
            {
                stack.push(a * b);
            }
            else if (token == "/")
            {
                stack.push(a / b);
            }
            else if (token == "^")
            {
                stack.push(std::pow(a, b));
            }
            else
            {
                throw std::runtime_error("Erreur avec le caractère suivant : " + token);
            }
        }
    }
    return stack.top();
    return 0.f;
}

// Exercice 2
Token make_token(float value)
{
    Token token;
    token.type = TokenType::OPERAND;
    token.value = value;
    return token;
}

Token make_token(Operator op)
{
    Token token;
    token.type = TokenType::OPERATOR;
    token.op = op;
    return token;
}

std::vector<Token> tokenize(std::vector<std::string> const &words)
{
    std::vector<Token> tokens;

    for (const std::string &word : words)
    {
        if (is_floating(word))
        {

            tokens.push_back(make_token(std::stof(word)));
        }
        else
        {
            if (word == "+")
            {
                tokens.push_back(make_token(Operator::ADD));
            }
            else if (word == "-")
            {
                tokens.push_back(make_token(Operator::SUB));
            }
            else if (word == "/")
            {
                tokens.push_back(make_token(Operator::DIV));
            }
            else if (word == "*")
            {
                tokens.push_back(make_token(Operator::MUL));
            }

            else if (word == "^")
            {
                tokens.push_back(make_token(Operator::POW));
            }
            else
            {
                throw std::runtime_error("Erreur, le caractère suivant n'est pas pris en compte : " + word);
            }
        }
    }

    return tokens;
}

float npi_evaluate(std::vector<Token> const &tokens)
{
    std::stack<float> stack;

    for (const Token &token : tokens)
    {
        if (token.type == TokenType::OPERAND)
        {
            stack.push(token.value);
        }
        else
        {
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();

            if (token.op == Operator::ADD)
            {
                stack.push(a + b);
            }
            else if (token.op == Operator::SUB)
            {
                stack.push(a - b);
            }
            else if (token.op == Operator::DIV)
            {
                stack.push(a / b);
            }
            else if (token.op == Operator::MUL)
            {
                stack.push(a * b);
            }
            else if (token.op == Operator::POW)
            {
                stack.push(std::pow(a, b));
            }
        }
    }
    return stack.top();
}
