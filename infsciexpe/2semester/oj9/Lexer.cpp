#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, string> tpcorrepond =
    {
        {0, "identifier"},
        {1, "integer"},
        {2, "oprator"},
        {3, "endofinput"}};

class Token
{
private:
    int tpid;
    string tpname;
    string iden;
    int num;
    char op;
    bool ending;

public:
    Token(int _tpid, string _iden)
    {
        tpid = _tpid;
        tpname = tpcorrepond[tpid];
        iden = _iden;
    }
    Token(int _tpid, int _num)
    {
        tpid = _tpid;
        tpname = tpcorrepond[tpid];
        num = _num;
    }
    Token(int _tpid, char _op)
    {
        tpid = _tpid;
        tpname = tpcorrepond[tpid];
        op = _op;
    }
    Token(int _tpid)
    {
        tpid = _tpid;
        tpname = tpcorrepond[tpid];
        ending = true;
    }

    void showmyself()
    {
        switch (tpid)
        {
        case 0:
            cout << tpname << " ";
            cout << iden << endl;
            break;
        case 1:
            cout << tpname << " ";
            cout << num << endl;
            break;
        case 2:
            cout << op << endl;
            break;
        case 3:
            cout << "endofinput" << endl;
            break;
        }
    }
};

class Lexer
{
private:
    vector<Token> myTokens;
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

public:
    void showmyself()
    {
        for (auto iter : myTokens)
        {
            iter.showmyself();
        }
    }
    bool getToken()
    {
        if (!skipblank())
        {
            myTokens.push_back(Token(3));
            return false;
        }
        char c = getchar();
        if (c >= '0' && c <= '9')
        {
            int _num = c - '0';
            while ((c = getchar()) >= '0' && c <= '9')
            {
                _num = _num * 10 + c - '0';
            }
            myTokens.push_back(Token(1, _num));
            if (c == 26 || c == EOF)
            {
                myTokens.push_back(Token(3));
                return false;
            }
            else
                ungetc(c, stdin);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
        {
            myTokens.push_back(Token(2, c));
        }
        else
        {
            string temp;
            temp += c;
            while ((c = getchar()) != ' ' && c != '\t' &&
                   c != '\r' && c != '\n' && c != 26 &&
                   c != EOF)
            {
                temp += c;
            }
            myTokens.push_back(Token(0, temp));
            if (c == 26 || c == EOF)
            {
                myTokens.push_back(Token(3));
                return false;
            }
            else
                ungetc(c, stdin);
        }
        return true;
    }
};

signed main()
{
    Lexer myLex;
    while (myLex.getToken())
    {
    }
    myLex.showmyself();
    return 0;
}