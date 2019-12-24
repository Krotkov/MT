%{
#include <bits/stdc++.h>
#include "../Tree.h"
%}

%start`S

%type`Tree`S`AS`AS2`VS`VS2`A`SIGNAT

%attribute`std::string`type

%%
S`:
|`FUNCTION`NAME`SIGNAT`COLON`TYPE`SEMICOLON`{
$1$2$3$4$5$6
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
children.emplace_back($4);
children.emplace_back($5);
children.emplace_back($6);
$$ = Tree("S", children);
}
|`PROCEDURE`NAME`SIGNAT`SEMICOLON`{
$1$2$3$4
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
children.emplace_back($4);
$$ = Tree("S", children);
}
;
SIGNAT`:
|`LBR`AS`RBR`{
$1$2$3
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("SIGNAT", children);
}
|`{
$$ = Tree("SIGNAT");
}
;
AS`:
|`A`AS2`{
$1$2
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
$$ = Tree("AS", children);
}
|`{
$$  = Tree("AS");
}
;
AS2`:
|`SEMICOLON`A`AS2`{
$1$2$3
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("AS2", children);
}
|`{
$$ = Tree("AS2");
}
;
A`:
|`VS`COLON`TYPE`{
$1$2$3
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("A", children);
}
;
VS`:
|`NAME`VS2`{
$1$2
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
$$ = Tree("VS", children);
}
;
VS2`:
|`COMMA`NAME`VS2`{
$1$2$3
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("VS2", children);
}
|`{
$$ = Tree("VS2");
}
;
%%