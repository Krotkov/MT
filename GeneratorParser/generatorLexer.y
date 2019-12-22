%{
	#include <bits/stdc++.h>
	#include <regex>
	int yylex(void);
	void yyerror(const char*);

	std::string* result = nullptr;
	std::string header;
	std::vector< std::pair<std::string, std::string> > regToCode;
	std::vector<std::string> tokens;
	std::unordered_set<std::string> skipp;
%}

%union {
    std::string* str;
}

%type <str> INPUT MYTEXT RULES RULE MYTOKENS SKIPTOKENS
%token <str> TEXT WHITE PROCLB PROCRB PROCPROC LBR RBR NAME
%token TOKENS COMMA SKIP

%start INPUT

%%
    INPUT:
	PROCLB MYTEXT PROCRB TOKENS MYTOKENS SKIP SKIPTOKENS PROCPROC RULES PROCPROC {
	    header = *$2;
	    result = new std::string(*$1 + "\n" + *$2 + *$3 + "\n%tokens " + *$5 + "\n%skip " + *$7 + "\n%%\n" + *$9 + "\n%%\n");
	}
    SKIPTOKENS:
        TEXT SKIPTOKENS {
            skipp.insert(*$1);
            $$ = new std::string(*$1 + " " + *$2);
        }
        | {
            $$ = new std::string("");
        }
    MYTOKENS:
    	TEXT MYTOKENS {
    	    tokens.emplace_back(*$1);
    	    $$ = new std::string(*$1 + " " + *$2);
    	}
    	| {
    	    $$ = new std::string("");
    	}
    RULES:
        RULES RULE {
            $$ = new std::string(*$1 + *$2);
        }
        | {
            $$ = new std::string("");
        }
    RULE:
	TEXT LBR MYTEXT RBR {
	    regToCode.emplace_back(*$1, *$3);
	    $$ = new std::string(*$1 + "\n{\n" + *$3 + "}\n");
	}
    MYTEXT:
    	MYTEXT TEXT{
    	    $$ = new std::string(*$1 + *$2 + "\n");
    	}
    	| {
    	    $$ = new std::string("");
    	}
%%