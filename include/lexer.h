// lexer.h

#ifndef _LEXER_H
#define _LEXER_H

#define array_size(arr) ((sizeof(arr)) / (sizeof(arr[0])))

enum TokenTypes {
  T_UNKNOWN = 0,

  T_ADD,
  T_SUB,
  T_MULT,
  T_DIV,
  T_LT,   // '<'
  T_GT,   // '>'
  T_EQ,   // '=='
  T_LEQ,  // '<='
  T_GEQ,  // '>='
  T_NEQ,  // '!='
  T_NOOP,

  T_ASSIGN,
  T_SEMICOLON,
  T_NEWLINE,
  T_LEFTPAREN,    // '('
  T_RIGHTPAREN,   // ')'
  T_BLOCKBEGIN,   // '{'
  T_BLOCKEND,     // '}'
  T_IF,

  T_STRING,
  T_IDENTIFIER,
  T_NUMBER,
  T_EMPTYVAR,
  T_SCOPE,   // { ... }

  T_PUSH,
  T_POP,

  T_EOF,
};

struct Token {
  int type;
  int length;
  char* string;
};

struct Interpreter;

struct Lexer {
  struct Interpreter* vm;
  char* index;
  int line;
  int count;
  struct Token token;
};

struct Token lexerNextToken(struct Lexer* lexer);

void lexerGetTokenValue(char* buffer, struct Token token);

int lexerTokenEquals(struct Token token, const char* toMatch);

bool lexerExpectToken(struct Token token, int type);

bool lexerTokenIs(struct Lexer* lexer, int type);

void lexerPrintToken(struct Token token);

#endif