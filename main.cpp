#include "global.hpp"

using namespace std;

ofstream outputStream;
bool inGlobalScope = true;
SymbolTable symbolTable;
extern int yydebug;

int main(int argc, char *argv[])
{
    yydebug = 0;
    FILE *inputFile;

    inputFile = fopen(argv[1], "r");

    if (!inputFile)
    {
        printf("Error: File not found\n");
        return -1;
    }

    yyin = inputFile;

    outputStream.open("output.asm", ofstream::trunc);
    if (!outputStream.is_open())
    {
        printf("Error: Cannot open output file");
        return -1;
    }


    yyparse();
    symbolTable.dump();

    outputStream.close();
    fclose(inputFile);
    yylex_destroy();

    return 0;
}