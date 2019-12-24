%{
#include <bits/stdc++.h>
#include "../Tree.h"
%}

%start`E

%type`Tree`E`E2`T`T2`F

%%
E`:
|`T`E2`{
$1$2
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
$$ = Tree("E", children);
}
|`MINUS`E`{
$1$2
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
$$ = Tree("E", children);
}
;
E2`:
|`PLUS`T`E2`{
$1$2$3
std::vector<Tree> children;
children.emplace_back("+");
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("E2", children);
}
|`MINUS`T`E2`{
$1$2$3
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("E2", children);
}
|`{
$$ = Tree("E2");
}
;
T`:
|`F`T2`{
$1$2
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
$$ = Tree("T", children);
}
;
T2`:
|`MUL`F`T2`{
$1$2$3
std::vector<Tree> children;
children.emplace_back("*");
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("T2", children);
}
|`DIV`F`T2`{
$1$2$3
std::vector<Tree> children;
children.emplace_back($1);
children.emplace_back($2);
children.emplace_back($3);
$$ = Tree("T2", children);
}
|`{
$$ = Tree("T2");
}
;
F`:
|`NUM`{
$1
std::vector<Tree> children;
children.emplace_back($1);
$$ = Tree("F", children);
}
|`LBR`E`RBR`{
$1$2$3
std::vector<Tree> children;
children.emplace_back("(");
children.emplace_back($2);
children.emplace_back(")");
$$ = Tree("F", children);
}
;
%%