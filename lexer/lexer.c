#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Token
typedef enum {
    TOKEN_EOF,       // End of file ("")
    TOKEN_NUMBER,    // Numeric literal
    TOKEN_IDENT,     // Identifier (x, count, ...)
    TOKEN_PLUS,      // +
    TOKEN_MINUS,     // -
    TOKEN_STAR,      // *
    TOKEN_SLASH,     // /
    TOKEN_LPAREN,    // (
    TOKEN_RPAREN,    // )
    TOKEN_LBRACE,    // {
    TOKEN_RBRACE,    // }
    TOKEN_SEMICOLON, // ;
    TOKEN_SEQUAL,    // =
} TokenType;

typedef struct {
    TokenType type;
    char lexem[32]; 
} Token;

Token getNextToken(const char **input){
    Token token;
    const char *pStart = *input;

    // ignore whitespace and move pointer
    while (isspace(*pStart)) pStart++;


    // handle end of input
    if (*pStart == '\0') {
        token.type = TOKEN_EOF;
        strcpy(token.lexem, "");
        *input = pStart;
        return token;
    }

    // handle numbers
    if (isdigit(*pStart)) {
        token.type = TOKEN_NUMBER;
        int i = 0;
        while (isdigit(*pStart)) {
            token.lexem[i++] = *pStart++;
        }
        token.lexem[i] = '\0';
        *input = pStart;
        return token;
    }

    // handle identifiers
    if (isalpha(*pStart)) {
        token.type = TOKEN_IDENT;
        int i = 0;
        while (isalnum(*pStart)) {
            token.lexem[i++] = *pStart++;
        }
        token.lexem[i] = '\0';
        *input = pStart;
        return token;
    }

    // handle single-character tokens
    switch (*pStart) {
        case '+': token.type = TOKEN_PLUS; break;
        case '-': token.type = TOKEN_MINUS; break;
        case '*': token.type = TOKEN_STAR; break;
        case '/': token.type = TOKEN_SLASH; break;
        case '(': token.type = TOKEN_LPAREN; break;
        case ')': token.type = TOKEN_RPAREN; break;
        case '{': token.type = TOKEN_LBRACE; break;
        case '}': token.type = TOKEN_RBRACE; break;
        case ';': token.type = TOKEN_SEMICOLON; break;
        case '=': token.type = TOKEN_SEQUAL; break;
        default:
            fprintf(stderr, "Unknown character: %c\n", *pStart);
            token.type = TOKEN_EOF;
            break;
    }

    token.lexem[0] = *pStart;
    token.lexem[1] = '\0';
    *input = pStart + 1;
    return token;
}

int main() {
    const char *input = "x = 32 + (3*y)";
    const char *cursor = input;

    printf("Tokenizing : %s\n", input);

    while(1) {
        Token token = getNextToken(&cursor);
        printf("Token: %d, Lexem: %s\n", token.type, token.lexem);

        if(token.type == TOKEN_EOF) break;
    }
    return 0;
}
