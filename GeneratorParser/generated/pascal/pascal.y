%{
#include <bits/stdc++.h>
#include "../Tree.h"
%}

%start`S

%type`Tree

%%
S`:
|`FUNCTION`NAME`LBR`AS`RBR`COLON`TYPE`SEMICOLON`{
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
children.emplace_back($4);
children.emplace_back($5);
children.emplace_back($6);
children.emplace_back($7);
children.emplace_back($8);
$$ = Tree("S", children);
}
|`PROCEDURE`NAME`LBR`AS`RBR`SEMICOLON`{
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
children.emplace_back($4);
children.emplace_back($5);
children.emplace_back($6);
$$ = Tree("S", children);
}
;
AS`:
|`A`AS2`{
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
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("A", children);
}
;
VS`:
|`NAME`VS2`{
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
$$ = Tree("VS", children);
}
;
VS2`:
|`COMMA`NAME`VS2`{
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