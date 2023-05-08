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

    void analyzeTokens()
    {
        stack<Token *> analyzer;
        while (getNextToken())
        {
            analyzer.push(myTokens.back());

            if (analyzer.top()->type == Token::TokenType::Plus)
            {
                analyzer.pop();
                Token right = *analyzer.top();
                analyzer.pop();
                Token left = *analyzer.top();
                analyzer.pop();
                analyzer.push(new Token(Token::TokenType::Integer, left.val + right.val));
            }

            if (analyzer.top()->type == Token::TokenType::Minus)
            {
                analyzer.pop();
                Token right = *analyzer.top();
                analyzer.pop();
                Token left = *analyzer.top();
                analyzer.pop();
                analyzer.push(new Token(Token::TokenType::Integer, left.val - right.val));
            }

            if (analyzer.top()->type == Token::TokenType::Multiple)
            {
                analyzer.pop();
                Token right = *analyzer.top();
                analyzer.pop();
                Token left = *analyzer.top();
                analyzer.pop();
                analyzer.push(new Token(Token::TokenType::Integer, left.val * right.val));
            }

            if (analyzer.top()->type == Token::TokenType::Divide)
            {
                analyzer.pop();
                Token right = *analyzer.top();
                analyzer.pop();
                Token left = *analyzer.top();
                analyzer.pop();
                analyzer.push(new Token(Token::TokenType::Integer, left.val / right.val));
            }
        }
        Token res = *analyzer.top();
        analyzer.pop();
        cout << res.val << endl;
        return;
    }
};

signed main()
{
    Lexer mylex;
    mylex.analyzeTokens();
    return 0;
}