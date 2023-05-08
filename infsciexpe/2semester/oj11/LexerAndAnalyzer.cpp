#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

class Token
{
public:
    enum TokenType
    {
        Identifier,
        Integer,
        Plus,
        Minus,
        Multiple,
        Divide,
        Equal,
        DoubleEqual,
        Lparen,
        Rparen,
        Bigger,
        Smaller,
        Semicolon,
        Output,
        Error,
        EndOfInput
    };
    TokenType type;
    string name;
    int val;
    Token(TokenType type)
        : type(type), name(""), val(0) {}
    Token(TokenType type, string name)
        : type(type), name(name), val(0) {}
    Token(TokenType type, int val)
        : type(type), name(""), val(val) {}
    void showMySelf()
    {
        cout << type << "\t";
        if (type == Identifier)
            cout << name;
        if (type == Integer)
            cout << val;
        cout << endl;
        return;
    }
};

class Expression
{
public:
    enum class ExpType
    {
        IdentifierExp,
        IntegerExp,
        UnaryExp,
        BinaryExp,
        Stop
    };
    ExpType type;
    string name;
    map<string, int> &varieties;
    virtual ~Expression() {}
    Expression(ExpType type, map<string, int> &varieties)
        : type(type), name(" "), varieties(varieties) {}
    Expression(ExpType type, string name, map<string, int> &varieties)
        : type(type), name(name), varieties(varieties) {}
    virtual int calculate() = 0;
};

class IdentifierExp : public Expression
{
public:
    IdentifierExp(ExpType type, string name, map<string, int> &varieties)
        : Expression(type, name, varieties) {}
    int calculate()
    {
        return varieties[name];
    }
};

class IntegerExp : public Expression
{
public:
    int val;
    IntegerExp(ExpType type, int val, map<string, int> &varieties)
        : Expression(type, varieties), val(val) {}
    int calculate()
    {
        return val;
    }
};

class UnaryExp : public Expression
{
public:
    Token *op;
    Expression *right;
    UnaryExp(ExpType type, Token *op, Expression *right, map<string, int> &varieties)
        : op(op), right(right), Expression(type, varieties) {}
    ~UnaryExp()
    {
        delete op;
        delete right;
    }
    int calculate()
    {
        switch (op->type)
        {
        case Token::TokenType::Output:
            cout << right->calculate() << endl;
            break;
        }
        return right->calculate();
    }
};

class BinaryExp : public Expression
{
public:
    Expression *left;
    Token *op;
    Expression *right;
    BinaryExp(ExpType type, Expression *left, Token *op, Expression *right, map<string, int> &varieties)
        : left(left), op(op), right(right), Expression(type, varieties) {}
    ~BinaryExp()
    {
        delete left;
        delete op;
        delete right;
    }
    int calculate()
    {
        switch (op->type)
        {
        case Token::TokenType::Plus:
            return left->calculate() + right->calculate();
            break;

        case Token::TokenType::Minus:
            return left->calculate() - right->calculate();
            break;

        case Token::TokenType::Multiple:
            return left->calculate() * right->calculate();
            break;

        case Token::TokenType::Divide:
            return left->calculate() / right->calculate();
            break;

        case Token::TokenType::Equal:

            break;
        }
    }
};

class Lexer
{
public:
    vector<Token *> myTokens;
    map<string, int> varieties;

    stack<Token *> analyzer;
    int lbracket = 0, rbracket = 0;
    void showMySelf()
    {
        for (auto iter : myTokens)
        {
            iter->showMySelf();
        }
        return;
    }
    // Skip: ' ', '\t', '\r', '\n'
    // If the input is valid, return true.
    // If it meets the end, return false.
    bool skipblank()
    {
        char c;
        while ((c = getchar()) == ' ' || c == '\t' ||
               c == '\n' || c == '\r')
        {
        }
        if (c == 26 || c == EOF)
            return false;
        else
        {
            ungetc(c, stdin);
            return true;
        }
    }

    // Get the next Token, and put it into myTokens.
    bool getNextToken()
    {
        if (!skipblank())
        { // Deal with blanks.
            myTokens.push_back(new Token(Token::TokenType::EndOfInput));
            return false;
        }
        char c = getchar();
        if (isdigit(c))
        { // Deal with Integer
            int _num = c - '0';
            while (isdigit((c = getchar())))
            {
                _num = _num * 10 + c - '0';
            }
            myTokens.push_back(new Token(Token::TokenType::Integer, _num));
            if (c == 26 || c == EOF)
            {
                myTokens.push_back(new Token(Token::TokenType::EndOfInput));
                return false;
            }
            else
                ungetc(c, stdin);
        }
        else if (isalpha(c))
        { // Deal with Identifier
            string temp;
            temp += c;
            while (isalnum((c = getchar())) || c == '_')
            {
                temp += c;
            }
            if (temp == "output")
                myTokens.push_back(new Token(Token::TokenType::Output));
            else
                myTokens.push_back(new Token(Token::TokenType::Identifier, temp));
            if (c == 26 || c == EOF)
            {
                myTokens.push_back(new Token(Token::TokenType::EndOfInput));
                return false;
            }
            else
                ungetc(c, stdin);
        }
        else
            switch (c)
            {
            case '+':
                myTokens.push_back(new Token(Token::TokenType::Plus));
                break;
            case '-':
                myTokens.push_back(new Token(Token::TokenType::Minus));
                break;
            case '*':
                myTokens.push_back(new Token(Token::TokenType::Multiple));
                break;
            case '/':
                myTokens.push_back(new Token(Token::TokenType::Divide));
                break;
            case '>':
                myTokens.push_back(new Token(Token::TokenType::Bigger));
                break;
            case '<':
                myTokens.push_back(new Token(Token::TokenType::Smaller));
                break;
            case '(':
                myTokens.push_back(new Token(Token::TokenType::Lparen));
                break;
            case ')':
                myTokens.push_back(new Token(Token::TokenType::Rparen));
                break;
            case ';':
                myTokens.push_back(new Token(Token::TokenType::Semicolon));
                break;
            case '=':
                if ((c = getchar()) == '=')
                {
                    myTokens.push_back(new Token(Token::TokenType::DoubleEqual));
                    break;
                }
                else
                {
                    myTokens.push_back(new Token(Token::TokenType::Equal));
                    ungetc(c, stdin);
                    break;
                }
            }
        return true;
    }

    // Analyze Tokens.
    Token needAnInt()
    {
        stack<Token *> subanalyzer;
        while (getNextToken() &&
               myTokens.back()->type != Token::TokenType::Semicolon &&
               myTokens.back()->type != Token::TokenType::EndOfInput &&
               myTokens.back()->type != Token::TokenType::Rparen)
        {
            subanalyzer.push(myTokens.back());
            if (subanalyzer.top()->type == Token::TokenType::Lparen)
            {
                subanalyzer.pop();
                Token res = needAnInt();
                subanalyzer.push(&res);
            }
            if (subanalyzer.top()->type == Token::TokenType::Multiple ||
                subanalyzer.top()->type == Token::TokenType::Divide)
            {
                Token op = *subanalyzer.top();
                subanalyzer.pop();
                Token temp1 = *subanalyzer.top();
                subanalyzer.pop();
                getNextToken();
                subanalyzer.push(myTokens.back());
                if (subanalyzer.top()->type == Token::TokenType::Lparen)
                {
                    subanalyzer.pop();
                    Token res = needAnInt();
                    subanalyzer.push(&res);
                }

                if (subanalyzer.top()->type == Token::TokenType::Lparen)
                {
                    needAnInt();
                }
                Token temp2 = *subanalyzer.top();
                subanalyzer.pop();
                if (op.type == Token::TokenType::Multiple)
                {
                    subanalyzer.push(new Token(Token::TokenType::Integer,
                                               (temp1.type == Token::TokenType::Integer ? temp1.val : varieties[temp1.name]) *
                                                   (temp2.type == Token::TokenType::Integer ? temp2.val : varieties[temp2.name])));
                }
                else
                {
                    subanalyzer.push(new Token(Token::TokenType::Integer,
                                               ((temp1.type == Token::TokenType::Integer) ? temp1.val : varieties[temp1.name]) /
                                                   ((temp2.type == Token::TokenType::Integer) ? temp2.val : varieties[temp2.name])));
                }
            }
        }
        while (subanalyzer.size() != 1)
        {
            Token temp1 = *subanalyzer.top();
            subanalyzer.pop();
            Token op = *subanalyzer.top();
            subanalyzer.pop();
            Token temp2 = *subanalyzer.top();
            subanalyzer.pop();
            if (op.type == Token::TokenType::Plus)
            {
                subanalyzer.push(new Token(Token::TokenType::Integer,
                                           (temp1.type == Token::TokenType::Integer ? temp1.val : varieties[temp1.name]) +
                                               (temp2.type == Token::TokenType::Integer ? temp2.val : varieties[temp2.name])));
            }
            if (op.type == Token::TokenType::Minus)
            {
                subanalyzer.push(new Token(Token::TokenType::Integer,
                                           (temp1.type == Token::TokenType::Integer ? temp1.val : varieties[temp1.name]) -
                                               (temp2.type == Token::TokenType::Integer ? temp2.val : varieties[temp2.name])));
            }
        }
        Token result = *subanalyzer.top();
        subanalyzer.pop();
        return result;
    }
    void analyzeTokens()
    {
        while (getNextToken())
        {
            if (myTokens.back()->type == Token::TokenType::Output)
            {
                Token res = needAnInt();
                if (res.type == Token::TokenType::Integer)
                {
                    cout << res.val << endl;
                }
                else
                {
                    cout << varieties[res.name] << endl;
                }
            }

            if (myTokens.back()->type == Token::TokenType::Equal)
            {
                Token iden = *myTokens.at(myTokens.size() - 2);
                Token res = needAnInt();
                varieties[iden.name] = res.val;
            }
        }
    }
};

signed
main()
{
    Lexer mylex;
    mylex.analyzeTokens();
    return 0;
}