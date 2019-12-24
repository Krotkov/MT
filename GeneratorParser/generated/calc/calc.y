%{
#include <bits/stdc++.h>
#include "../Tree.h"
%}

%start`E

%type`std::vector<int>`E`E2`T`T2`F`P`P2

%attribute`std::vector<int>`vect

%%
E`:
|`T`E2`{
$1
vect = $1;
$2
$$ = $2;
}
;
E2`:
|`PLUS`T`E2`{
$1
$2
int a = vect.back();
vect.pop_back();
vect.push_back(a + $2[0]);
$3
$$ = $3;
}
|`MINUS`T`E2`{
$1
$2
int a = vect.back();
vect.pop_back();
vect.push_back(a - $2[0]);
$3
$$ = $3;
}
|`{
$$ = std::vector<int>(vect);
}
;
T`:
|`P`T2`{
$1
vect = $1;
$2
$$ = $2;
}
;
T2`:
|`MUL`P`T2`{
$1
$2
int a = vect.back();
vect.pop_back();
vect.push_back(a * $2[0]);
$3
$$ = $3;
}
|`DIV`P`T2`{
$1
$2
int a = vect.back();
vect.pop_back();
vect.push_back(a / $2[0]);
$3
$$ = $3;
}
|`{
$$ = std::vector<int>(vect);
}
;
P`:
|`F`P2`{
$1
vect = $1;
$2
$$ = $2;
}
;
P2`:
|`POW`F`P2`{
$1
$2
auto vect1 = vect;
vect = $2;
$3
vect = vect1;
int a = vect.back();
vect.pop_back();
int v = 1;
for (int i = 0; i < $3[0]; i++) {v *= a;}
vect.push_back(v);
$$ = vect;
}
|`{
$$ = std::vector<int>(vect);
}
;
F`:
|`NUM`{
$1
std::vector<int> v;
v.push_back(std::atoi($1.data()));
$$ = v;
}
|`LBR`E`RBR`{
$1$2$3
$$ = std::vector<int>($2);
}
;
%%