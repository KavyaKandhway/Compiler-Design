#include <stdio.h>
void translate(const char *infix_expr);
void parse_expr(const char *expr, int *scan_idx);
void parse_rest(const char *rest, int *scan_idx);
void parse_term(const char *term, int *scan_idx);
int main(int argc, char *argv[])
{
    char infix_expr[20];
    scanf("%s", infix_expr);

    printf("infix expression: %s \n", infix_expr);
    printf("postfix expression: ");
    translate((const char*)&infix_expr);
    printf("\n");
}
void translate(const char *infix_expr)
{
    int scan_idx = 0;
    parse_expr(infix_expr, &scan_idx);
}
void parse_expr(const char *expr, int *scan_idx)
{
    parse_term(expr, scan_idx);
    parse_rest(expr, scan_idx);
}
void parse_rest(const char *rest, int *scan_idx)
{
    char op = rest[*scan_idx];
    *scan_idx += 1;
    parse_term(rest, scan_idx);
    printf("%c", op);
    if (rest[*scan_idx] != 0)
    {
        parse_rest(rest, scan_idx);
    }
}

void parse_term(const char *expr, int *scan_idx)
{
    char lookahead = expr[*scan_idx];
    if (lookahead >= '0' && lookahead <= '9')
    {
        *scan_idx += 1;
        printf("%c", lookahead);
    }
    else
    {
        printf("Syntax error. Expected a digit. \n");
    }
}