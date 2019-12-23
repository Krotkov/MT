%{
#include <bits/stdc++.h>
%}

%start`E

%type`int

%%
E`:
|`T`E2`{`}
;
E2`:
|`PLUS`T`E2`{`}
|`{`}
;
T`:
|`F`T2`{`}
;
T2`:
|`MUL`F`T2`{`}
|`{`}
;
F`:
|`NUM`{`}
|`LBR`E`RBR`{`}
;
%%