%{
    #include <bits/stdc++.h>

    int yylex(void);
    void yyerror(const char*);

    std::string* result = nullptr;
    std::vector<std::string> varNames, varTypes;
    int myIndex = 0;
    std::string curVar() {
        return "var" + std::to_string(myIndex);
    }
    std::set<std::string> funcVars;
    std::string nextVar() {
        myIndex++;
        return curVar();
    }
%}

%union {
    std::pair<std::string, std::string>* exprRet;
    std::pair<std::string, std::vector<std::string> >* varRet;
    std::vector<std::string>* ret;
    std::string* str;
}

%type <ret> FUNCTYPES FUNCVARS
%type <str> Input PROGRAM FUNCTYPE MAINFUNC FUNCTIONS FUNCTION
%type <exprRet> EXPR EXPR1 EXPR2 EXPR3 EXPR4 EXPR5 EXPR6 EXPR7 EXPR8
%type <varRet> VARS
%token <str> NAME NUMBER TRUE FALSE MAIN AND OR NOT DIV MOD COMP
%token <str> INT FLOAT BOOL
%token LBRACKET RBRACKET IMPL CAR PLUS MINUS EQUAL READINT WRITEINT SEMICOLON COLONS IF THEN ELSE COMMA MUL LET DOLLAR

%start Input

%%

Input:
    PROGRAM { result = new std::string(std::string("#include<bits/stdc++.h>\n\n") + *($1)); }
;

PROGRAM:
    FUNCTIONS MAINFUNC {
    	auto ans = new std::string(*$1);
    	*ans += *$2;
    	$$ = ans;
    }
;

FUNCTIONS:
    FUNCTIONS FUNCTION {
    	auto ans = new std::string();
    	*ans += *$1;
    	*ans += *$2;
    	$$ = ans;
    }
    | {
    	$$ = new std::string();
    }
;

FUNCTION:
    LET NAME FUNCVARS EQUAL EXPR SEMICOLON {
        auto ret = new std::string("int " + (*$2) + "(");
        auto vectV = ($3);
        for (int i = 0; i < vectV->size(); i++) {
            *ret += "int " + (*vectV)[i];
            if (i+1 != vectV->size()) *ret += ", ";
        }
        *ret +=  ") {\n";
        *ret += $5->first;
        *ret += "return " + $5->second + ";\n";
        for (int i = 0; i < vectV->size(); i++) {
            funcVars.erase((*vectV)[i]);
        }
        *ret += "}\n";
        $$ = ret;
    }
;

MAINFUNC:
    LET MAIN EQUAL EXPR SEMICOLON {
        auto ret = new std::string("int " + (*$2) + "(");
        *ret +=  ") {\n";
        *ret += $4->first;
        *ret += "return " + $4->second + ";\n";
        *ret += "}\n";
        $$ = ret;
    }
;

FUNCVARS:
    FUNCVARS NAME {
        auto ret = ($1);
        funcVars.insert(*$2);
        ret->push_back(*($2));
        $$ = ret;
    }
    | NAME {
        auto ret = new std::vector<std::string>();
        funcVars.insert(*$1);
        ret->push_back(*$1);
        $$ = ret;
    }
    | {
        auto ret = new std::vector<std::string>();
        $$ = ret;
    }
;

FUNCTYPES:
    FUNCTYPES IMPL FUNCTYPE {
        auto ret = ($1);
        ret->push_back(*($3));
        $$ = ret;
    }
    | FUNCTYPE {
        auto ret = new std::vector<std::string>();
        ret->push_back(*($1));
        $$ =  ret;
    }
;

FUNCTYPE:
    INT {
        $$ = $1;
    }
    | BOOL {
        $$ = $1;
    }
    | FLOAT {
        $$ = $1;
    }

;

EXPR:
    LBRACKET EXPR RBRACKET {
        $$ = $2;
    }
    | IF EXPR THEN EXPR ELSE EXPR {
        std::string ans = "";
        ans += $2->first;
        ans += "int " + nextVar() + ";\n";
        ans += "if (" + $2->second + ") {\n";
        ans += $4->first;
        ans += curVar() + " = " + $4->second + ";\n";
        ans += "} else {\n";
        ans += $6->first;
        ans += curVar() + " = " + $6->second + ";\n";
        ans += "}\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
    | EXPR1 {
        $$ = $1;
    }
;

EXPR1:
    LBRACKET EXPR1 RBRACKET {
        $$ = $2;
    }
    | EXPR2 {
        $$ = $1;
    }
    | EXPR1 COMP EXPR2 {
        std::string ans;
        ans += $1->first;
        ans += $3->first;
        ans += "bool " + nextVar() + " = " + $1->second + (*$2) + $3->second + ";\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
;

EXPR2:
    LBRACKET EXPR2 LBRACKET {
        $$ = $2;
    }
    | EXPR3 {
    	$$ = $1;
    }
    | EXPR3 COMP EXPR3 {
        std::string ans;
        ans += $1->first;
        ans += $3->first;
        ans += "int " + nextVar() + " = int(" + $1->second + " " + (*$2) + " " + $3->second + ");\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
;

EXPR3:
    LBRACKET EXPR3 RBRACKET {
        $$ = $2;
    }
    | EXPR3 OR EXPR4 {
        std::string ans = "";
        ans += $1->first;
        ans += $3->first;
        ans += "int " + nextVar() + "=" + $1->second + " " + (*$2) + " " + $3->second + ";\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
    | EXPR4 {
        $$ = $1;
    }
;

EXPR4:
    LBRACKET EXPR4 RBRACKET {
        $$ = $2;
    }
    | EXPR4 AND EXPR5 {
        std::string ans = "";
        ans += $1->first;
        ans += $3->first;
        ans += "int " + nextVar() + "=" + $1->second + " " + (*$2) + " " + $3->second + ";\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
    | EXPR5 {
        $$ = $1;
    }
;

EXPR5:
    LBRACKET EXPR5 RBRACKET {
        $$ = $2;
    }
    | NOT EXPR5 {
        std::string ans = "";
        ans = $2->first;
        ans += "int " + nextVar() + " = !" + $2->second + ";\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
    | EXPR6 {
        $$ = $1;
    }
;

EXPR6:
    LBRACKET EXPR6 RBRACKET {
        $$ = $2;
    }
    | TRUE {
        std::string ans;
        ans += "int " + nextVar() + " = 1;\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
    | FALSE {
        std::string ans;
        ans += "int " + nextVar() + " = 0;\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
    | EXPR7 {
    	$$ = $1;
    }
    | EXPR6 MUL EXPR7 {
    	std::string ans;
        ans += $1->first;
        ans += $3->first;
        ans += "int " + nextVar() + " = " + $1->second + " * " + $3->second + ";\n";
        auto ret = new std::pair<std::string, std::string>(ans, curVar());
        $$ = ret;
    }
    | EXPR6 DIV EXPR7 {
    	std::string ans;
    	ans += $1->first;
    	ans += $3->first;
    	ans += "int " + nextVar() + " = " + $1->second + " / " + $3->second + ";\n";
    	auto ret = new std::pair<std::string, std::string>(ans, curVar());
    	$$ = ret;
    }
    | EXPR6 MOD EXPR7 {
    	std::string ans;
    	ans += $1->first;
    	ans += $3->first;
    	ans += "int " + nextVar() + " = " + $1->second + " % " + $3->second + ";\n";
    	auto ret = new std::pair<std::string, std::string>(ans, curVar());
    	$$ = ret;
    }
;

EXPR7:
    LBRACKET EXPR7 RBRACKET {
    	$$ = $2;
    }
    | EXPR8 {
    	$$ = $1;
    }
    | EXPR7 PLUS EXPR8 {
    	std::string ans;
    	ans += $1->first;
    	ans += $3->first;
    	ans += "int " + nextVar() + " = " + $1->second + " + " + $3->second + ";\n";
    	auto ret = new std::pair<std::string, std::string>(ans, curVar());
    	$$ = ret;
    }
    | EXPR7 MINUS EXPR8 {
    	std::string ans;
    	ans += $1->first;
    	ans += $3->first;
    	ans += "int " + nextVar() + " = " + $1->second + " - " + $3->second + ";\n";
    	auto ret = new std::pair<std::string, std::string>(ans, curVar());
    	$$ = ret;
    }
;

EXPR8:
    LBRACKET EXPR8 RBRACKET {
    	$$ = $2;
    }
    | NUMBER {
    	std::string ans;
    	ans += "int " + nextVar() + " = " + *$1 + ";\n";
    	auto ret = new std::pair<std::string, std::string>(ans, curVar());
    	$$ = ret;
    }
    | NAME VARS {
    	std::string name = *($1);
    	std::string ans;
	if (funcVars.find(name) != funcVars.end()) {
	    ans += "int " + nextVar() + " = " + *$1 + ";\n";
	} else {
	    ans += $2->first;
	    auto vect = $2->second;
	    ans += "int " + nextVar() + " = " + *$1 + "(";
	    for (int i = 0; i+1 < vect.size(); i++) {
	    	ans += vect[i] + ", ";
	    }
	    ans += vect.back() + ");\n";
	}
	auto ret = new std::pair<std::string, std::string>(ans, curVar());
	$$ = ret;
    }
    | READINT {
    	std::string ans = "int " + nextVar() + ";\n";
    	ans += "std::cin >> " + curVar() + ";\n";
    	auto ret = new std::pair<std::string, std::string>(ans, curVar());
    	$$ = ret;
    }
    | WRITEINT VARS {
    	std::string ans = $2->first;
    	ans += "std::cout";
    	for (int i = 0; i < $2->second.size(); i++) {
    	    ans += " << " + $2->second[i];
    	}
    	ans += ";\n";
    	ans += "int " + nextVar() + " = 0;\n";
    	auto ret = new std::pair<std::string, std::string>(ans, curVar());
    	$$ = ret;
    }
;

VARS:
    VARS LBRACKET EXPR RBRACKET {
    	std::vector<std::string> vect = $1->second;
    	std::string ans = $1->first + $3->first;
    	vect.push_back($3->second);
    	auto ret = new std::pair<std::string, std::vector<std::string> >(ans, vect);
    	$$ = ret;
    }
    | VARS NAME {
    	std::vector<std::string> vect = $1->second;
    	std::string ans = $1->first;
    	vect.push_back(*$2);
    	auto ret = new std::pair<std::string, std::vector<std::string> >(ans, vect);
    	$$ = ret;
    }
    | VARS READINT {
    	std::vector<std::string> vect = $1->second;
    	std::string ans = $1->first;
    	ans += "int " + nextVar() + ";\n";
        ans += "std::cin >> " + curVar() + ";\n";
    	vect.push_back(curVar());
    	auto ret = new std::pair<std::string, std::vector<std::string> >(ans, vect);
    	$$ = ret;
    }
    | VARS DOLLAR EXPR {
    	std::vector<std::string> vect = $1->second;
        std::string ans = $1->first + $3->first;
        vect.push_back($3->second);
        auto ret = new std::pair<std::string, std::vector<std::string> >(ans, vect);
        $$ = ret;
    }
    | {
    	auto ret = new std::pair<std::string, std::vector<std::string> >();
    	$$ = ret;
    }
;
%%