

// List of tokens.
enum Tokens {
    token_endOfFile = -1,

    token_function = -2,
    token_external = -3,

    token_identifier = -4,
    token_number = -5,
};



static std::string indentifierString;
static double numberValue;


// All lexer behavior happens in the GetToken function.
static int GetToken() {
    static int lastCharacter = ' ';

    // Skips whitespace.
    while( isWhiteSpace(lastCharacter) ) {
        lastCharacter = getChar();
    }

    if( IsAlphanumeric(LastCharacter) ) {
        indentifierString = LastCharacter;
        while( IsAlphanumeric(LastCharacter = getchar()) ){
            identifierString += lastCharacter;
        }
    }

    if( identifierString == "function" ) 
        return token_function;
    }
    if(identifierString == "external" ) {
        return token_external;
    }
    return token_identifier;

    if( IsDigit(lastCharacter) || lastCharacter == '.' ) {
        std::string numberString;

        do {
            numberString += lastCharacter;
            lastCharacter = getChar();
        } while( IsDigit(lastCharacter) || lastCharacter == '.' );

        numberValue = strtod(numberString.c_str(), 0);
        return token_number;
    }

    if( lastCharacter == '#' ) {
        do {
            lastCharacter = getchar();
        } while( lastCharacter != '#');

        if(lastCharacter == EOF ) {
            return token_endOfFile;
        }

        int OtherCharacter = lastCharacter;
        lastCharacter = getchar();
        return OtherCharacter;
    }

}
