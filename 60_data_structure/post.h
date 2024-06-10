#ifndef POSTFIX_X
#define POSTFIX_X
#define ID              257
#define NUM             258
#define EQ              259
#define NE              260
#define GE              261
#define LE              262
#define AND             263
#define OR              264
#define UMINUS          265
#define MAXLEN          80
#include <cstring>
struct Token {
  bool operator==(char);
  bool operator!=(char);
  Token();
  Token(char);
  Token(char, char, int);
  Token(char*, int, int);
  bool IsOperand();
  int type;
  char*str;
  int len;
  float val;
};

struct Expression {
  Expression(char* linebuf, bool inf =false)
          :buf(linebuf), pos(0), len(strlen(buf)), infix(inf) {}
  char* buf;
  int pos;
  int len;
  bool infix;
};

bool IsAlpha(char c);
bool IsDigit(char c);
bool GetID(Expression& e, Token& tok);
bool GetNUM(Expression& e, Token& tok);
void SkipBlanks(Expression& e);
bool TwoCharOp(Expression&  e, Token& tok);
bool OneCharOp(Expression& e, Token& tok);
Token NextToken(Expression&);
int icp(Token& t);
int isp(Token& t);
void Postfix(Expression e);
float GetVal(Token& opnd);
Token UnaryOp(int op, Token& x);
Token BinaryOp(int op, Token& left, Token& right);
void Eval(Expression);

#endif