#include <iostream>
#include <string.h>
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
    TokenType   type;
    string      name;
    int         val;

    Token(TokenType type)
        :
        type(type), name(""), val(0) {}

    Token(TokenType type, string name)
        :
        type(type), name(name), val(0) {}

    Token(TokenType type, int val)
        :
        type(type), name(""), val(val) {}

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
    enum ExpType
    {
        IdentifierExp,
        IntegerExp,
        UnaryExp,
        BinaryExp,
        EqualExp,
        StopExp
    };
    ExpType     type;
    string      name    = " ";
    int         val     = 0;
    Token*      op      = nullptr;
    Expression* left    = nullptr;
    Expression* right   = nullptr;

    static map<string, int> varieties;

    Expression(ExpType type)
        :
        type(type) {}

    Expression(ExpType type, string name)
        :
        type(type), name(name) {}

    Expression(ExpType type, int val)
        :
        type(type), val(val) {}

    Expression(ExpType type, Token* op, Expression* right)
        :
        type(type), op(op), right(right) {}

    Expression(ExpType type, Token* op, Expression* left, Expression* right)
        :
        type(type), op(op), left(left), right(right) {}

    virtual ~Expression()
    {
        delete op;
        delete left;
        delete right;
    }

    virtual int calculate() = 0;
};
map<string, int> Expression::varieties;

class IdentifierExp : public Expression
{
public:
    IdentifierExp(ExpType type, string name)
        :
        Expression(type, name)
    {
        if (Expression::varieties.count(name) == 0) Expression::varieties[name] = 0;
    }

    int calculate()
    {
        return Expression::varieties[name];
    }
};

class IntegerExp : public Expression
{
public:
    IntegerExp(ExpType type, int val)
        :
        Expression(type, val)
    {}

    int calculate()
    {
        return val;
    }
};

class UnaryExp : public Expression
{
public:
    UnaryExp(ExpType type, Token* op, Expression* right)
        :
        Expression(type, op, right)
    {}
    int calculate()
    {
        switch (op->type)
        {
        case    Token::TokenType::Output:
            cout << right->calculate() << endl;
            break;

        default:
            cout << "wrong in unaryexp!" << endl;
            return -1;
        }
        return right->calculate();
    }
};

class BinaryExp : public Expression
{
public:
    BinaryExp(ExpType type, Token* op, Expression* left, Expression* right)
        :
        Expression(type, op, left, right)
    {}

    int calculate()
    {
        switch (op->type)
        {
        case    Token::TokenType::Plus:
            return left->calculate() + right->calculate();
            break;

        case    Token::TokenType::Minus:
            return left->calculate() - right->calculate();
            break;

        case    Token::TokenType::Multiple:
            return left->calculate() * right->calculate();
            break;

        case    Token::TokenType::Divide:
            return left->calculate() / right->calculate();
            break;

        default:
            cout << "wrong in binaryexp!" << endl;
            return -1;
            break;
        }
    }
};

class EqualExp : public Expression
{
public:
    EqualExp(ExpType type, Token* op, Expression* left, Expression* right)
        :
        Expression(type, op, left, right)
    {}

    int calculate()
    {
        if (op->type == Token::TokenType::Equal)
        {
            Expression::varieties[left->name] = right->calculate();
            return val;
        }
        else
        {
            cout << "wrong in equalexp" << endl;
            return -1;
        }
    }
};

class Lexer
{
public:
    vector<Token*> myTokens;

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
        while ((c = getchar()) == ' ' ||
            c == '\t' ||
            c == '\n' ||
            c == '\r')
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
            myTokens.push_back(new Token(
                Token::TokenType::EndOfInput
            ));
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
            myTokens.push_back(new Token(
                Token::TokenType::Integer, _num
            ));
            if (c == 26 || c == EOF)
            {
                myTokens.push_back(new Token(
                    Token::TokenType::EndOfInput
                ));
                return false;
            }
            else
                ungetc(c, stdin);
        }
        else if (isalpha(c))
        { // Deal with Identifier
            string temp;
            temp += c;
            while (isalnum(c = getchar()) || c == '_')
            {
                temp += c;
            }
            if (temp == "output")
                myTokens.push_back(new Token(
                    Token::TokenType::Output
                ));
            else
                myTokens.push_back(new Token(
                    Token::TokenType::Identifier, temp
                ));
            if (c == 26 || c == EOF)
            {
                myTokens.push_back(new Token(
                    Token::TokenType::EndOfInput
                ));
                return false;
            }
            else
                ungetc(c, stdin);
        }
        else
            switch (c)
            {
            case '+':
                myTokens.push_back(new Token(
                    Token::TokenType::Plus
                ));
                break;
            case '-':
                myTokens.push_back(new Token(
                    Token::TokenType::Minus
                ));
                break;
            case '*':
                myTokens.push_back(new Token(
                    Token::TokenType::Multiple
                ));
                break;
            case '/':
                myTokens.push_back(new Token(
                    Token::TokenType::Divide
                ));
                break;
            case '>':
                myTokens.push_back(new Token(
                    Token::TokenType::Bigger
                ));
                break;
            case '<':
                myTokens.push_back(new Token(
                    Token::TokenType::Smaller
                ));
                break;
            case '(':
                myTokens.push_back(new Token(
                    Token::TokenType::Lparen
                ));
                break;
            case ')':
                myTokens.push_back(new Token(
                    Token::TokenType::Rparen
                ));
                break;
            case ';':
                myTokens.push_back(new Token(
                    Token::TokenType::Semicolon
                ));
                break;
            case '=':
                if ((c = getchar()) == '=')
                {
                    myTokens.push_back(new Token(
                        Token::TokenType::DoubleEqual
                    ));
                    break;
                }
                else
                {
                    myTokens.push_back(new Token(
                        Token::TokenType::Equal
                    ));
                    ungetc(c, stdin);
                    break;
                }
            }
        return true;
    }

    Expression* treeBuild(int starting, int ending)
    {
        // treeBuild is used to build a lexer tree
        // We suppose the end token is a semicolon
        // Or an end of input

        if (starting == ending - 1)
        {
            // Deal with the base case
            switch (myTokens[starting]->type)
            {
            case    Token::TokenType::Integer:
            {
                Expression* res = new IntegerExp
                (
                    Expression::ExpType::IntegerExp,
                    myTokens[starting]->val
                );

                return res;
                break;
            };

            case    Token::TokenType::Identifier:
            {
                Expression* res = new IdentifierExp
                (
                    Expression::ExpType::IdentifierExp,
                    myTokens[starting]->name
                );

                return res;
                break;
            };

            default:
                cout << "wrong in treebuild-basecase" << endl;
                return nullptr;
                break;
            }
        }

        if (myTokens[starting]->type == Token::TokenType::Lparen &&
            myTokens[ending - 1]->type == Token::TokenType::Rparen)
        {
            return treeBuild(starting + 1, ending - 1);
        }

        int lparen = 0;

        //Deal with the output, also sum up the number of lparen
        //Prior 1
        for (int i = starting; i < ending; ++i)
        {
            if (myTokens[i]->type == Token::TokenType::Lparen)
            {
                lparen++;
            }
            else if (myTokens[i]->type == Token::TokenType::Rparen)
            {
                lparen--;
            }

            if (lparen == 0 && myTokens[i]->type == Token::TokenType::Output)
            {
                Expression* right =
                    treeBuild(i + 1, ending);

                Expression* res = new UnaryExp
                (
                    Expression::ExpType::UnaryExp,
                    myTokens[i],
                    right
                );

                return res;
            }
        }

        //Deal with the =
        //Prior 2
        lparen = 0;
        for (int i = starting; i < ending; ++i)
        {
            if (myTokens[i]->type == Token::TokenType::Lparen)
            {
                lparen++;
            }
            else if (myTokens[i]->type == Token::TokenType::Rparen)
            {
                lparen--;
            }

            if (lparen == 0 && myTokens[i]->type == Token::TokenType::Equal)
            {
                Expression* left = treeBuild(starting, i);
                Expression* right = treeBuild(i + 1, ending);
                Expression* res = new EqualExp
                (
                    Expression::ExpType::EqualExp,
                    myTokens[i],
                    left,
                    right
                );

                return res;
            }
        }

        //Deal with the +, -
        //Prior 3
        lparen = 0;
        for (int i = starting; i < ending; ++i)
        {
            if (myTokens[i]->type == Token::TokenType::Lparen)
            {
                lparen++;
            }
            else if (myTokens[i]->type == Token::TokenType::Rparen)
            {
                lparen--;
            }

            if (lparen == 0 && (
                myTokens[i]->type == Token::TokenType::Plus ||
                myTokens[i]->type == Token::TokenType::Minus))
            {
                Expression* left = treeBuild(starting, i);
                Expression* right = treeBuild(i + 1, ending);
                Expression* res = new BinaryExp
                (
                    Expression::ExpType::BinaryExp,
                    myTokens[i],
                    left,
                    right
                );

                return res;
            }
        }

        //Deal with the *, /
        //Prior 4
        lparen = 0;
        for (int i = starting; i < ending; ++i)
        {
            if (myTokens[i]->type == Token::TokenType::Lparen)
            {
                lparen++;
            }
            else if (myTokens[i]->type == Token::TokenType::Rparen)
            {
                lparen--;
            }

            if (lparen == 0 && (
                myTokens[i]->type == Token::TokenType::Multiple ||
                myTokens[i]->type == Token::TokenType::Divide))
            {
                Expression* left = treeBuild(starting, i);
                Expression* right = treeBuild(i + 1, ending);
                Expression* res = new BinaryExp
                (
                    Expression::ExpType::BinaryExp,
                    myTokens[i],
                    left,
                    right
                );

                return res;
            }
        }

        return nullptr;
    }

    int analyzeTree(Expression* root)
    {
        return root->calculate();
    }
};

signed main()
{
    Lexer   mylex;
    int     starting = 0;
    int     ending = -1;
    while (mylex.getNextToken() &&
        mylex.myTokens[++ending]->type != Token::TokenType::EndOfInput)
    {
        if (mylex.myTokens[ending]->type == Token::TokenType::Semicolon)
        {
            Expression* root = mylex.treeBuild(starting, ending);
            mylex.analyzeTree(root);
            starting = ending + 1;
        }
    }

    return 0;
}