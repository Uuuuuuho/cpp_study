%{
#include <iostream>
#include <string>
using namespace std;

int yylex();
void yyerror(const char*);
%}

%token CHAR
%token OR
%token STAR

%%
expr : term
     | expr OR term
     ;

term : factor
     | term factor
     ;

factor : CHAR
       | CHAR STAR
       | '(' expr ')'
       ;

%%

int main() {
    string input;
    cout << "Enter a regular expression: ";
    getline(cin, input);
    yyparse();
    return 0;
}

int yylex() {
    static string::const_iterator it = input.begin();
    static string::const_iterator end = input.end();
    while (it != end) {
        switch (*it++) {
            case '|': return OR;
            case '*': return STAR;
            case '(': return '(';
            case ')': return ')';
            default: return CHAR;
        }
    }
    return 0;
}

void yyerror(const char* msg) {
    cerr << "Error: " << msg << endl;
}

/*  
    In this example, the Yacc grammar defines a regular expression as a sequence of terms separated by | operators, and a term as a sequence of factors concatenated together. A factor can be a single character, a character followed by a * operator, or a parenthesized regular expression.

    The yylex function implements a simple lexer that returns tokens for the regular expression input. The main function prompts the user to enter a regular expression, reads the input using getline, and then calls the yyparse function to parse the regular expression.

    This is a very basic example of using Yacc to parse regular expressions. In practice, you would typically want to generate code to process the parsed regular expression, such as by generating a finite automaton or a syntax tree for the expression.
*/