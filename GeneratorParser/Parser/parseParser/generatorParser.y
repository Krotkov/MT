%{
    #include <bits/stdc++.h>
    int parser_lex(void);
    void parser_error(const char*);


    std::string header;
    std::string startPoint;
    std::string commonType;
    std::unordered_map<std::string, std::vector<std::pair<std::vector<std::string>, std::string> > > neTermRules;
    std::set<std::string> neTerms;
    std::vector<std::pair<std::string, std::string>> attributes;
%}

%name-prefix "parser_"


%union {
    std::string* str;
    std::vector<std::string>* vect;
    std::pair<std::vector<std::string>, std::string>* pir;
    std::vector<std::pair<std::vector<std::string>, std::string> >* vectpir;
}

%type <str> INPUT MYTEXT RULES RULE ATTRS
%type <vect> TOKENS VARS
%type <pir> PATTERN
%type <vectpir> PATTERNS
%token <str> TEXT WHITE PROCLB PROCRB PROCPROC LBR RBR TYPE TOKEN START
%token CAR COMMA COLON SEMICOLON ATTRIBUTE

%%

    INPUT:
        PROCLB MYTEXT PROCRB START TEXT TYPE TEXT ATTRS PROCPROC RULES PROCPROC {
            header = *$2;
            startPoint = *$5;
            commonType = *$7;
        }
    ATTRS:
    	ATTRS ATTRIBUTE TEXT VARS {
    	    for (auto a: *$4) {
    	    	attributes.emplace_back(*$3, a);
    	    }
    	    $$ = new std::string(*$1);
    	}
    	| {
	    $$ = new std::string("");
    	}
    VARS:
    	VARS TEXT {
    	    $1->emplace_back(*$2);
	    $$ = $1;
    	}
    	| {
    	  $$ = new std::vector<std::string>();
    	}
    MYTEXT:
    	MYTEXT TEXT {
    	    $$ = new std::string(*$1 + *$2 + "\n");
    	}
    	| {
    	    $$ = new std::string("");
    	}

    RULES:
    	RULES RULE {
    	    $$ = new std::string(*$1 + *$2 + "\n");
    	}
    	| {
    	    $$ = new std::string("");
    	}

    RULE:
    	TEXT COLON PATTERNS SEMICOLON {
    	    neTerms.insert(*$1);
    	    neTermRules[*$1] = *$3;
    	    $$ = new std::string( *$1 + ":\n" + ";\n");
    	}

    PATTERNS:
    	PATTERNS PATTERN {
    	    $1->emplace_back(*$2);
    	    $$ = $1;
    	}
    	| {
    	    auto ret = new std::vector<std::pair<std::vector<std::string>, std::string> >();
    	    $$ = ret;
    	}

    PATTERN:
    	CAR TOKENS LBR MYTEXT RBR {
    	    $$ = new std::pair<std::vector<std::string>, std::string>(*$2, *$4);
    	}
    TOKENS:
    	TOKENS TEXT {
    	    $1->push_back(*$2);
    	    $$ = $1;
    	}
    	| {
    	    $$ = new std::vector<std::string>();
    	}

%%