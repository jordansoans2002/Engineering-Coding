parent(pam,bob).
parent(tom,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,pat).
parent(pat,jim).

gender(pam,f).
gender(tom,m).
gender(bob,m).
gender(liz,f).
gender(ann,f).
gender(pat,f).
gender(jim,m).

mother(X,Y) :- parent(X,Y), gender(X,f).
father(X,Y) :- parent(X,Y), gender(X,m).
haschild(X) :- parent(X,_).
sibling(X,Y) :- parent(Z,X),parent(Z,Y).
sister(X,Y) :- sibling(X,Y),gender(X,f),X\==Y.
brother(X,Y) :- sibling(X,Y),gender(X,m),X\==Y.

cousin(X,Y) :- parent(P,X),parent(Q,Y),sibling(P,Q),X\==Y.
uncle(X,Y) :- brother(X,Z),parent(Z,Y). 

grandparent(X,Y) :- parent(X,Z),parent(Z,Y).
grandmother(X,Y) :- grandparent(X,Y),gender(X,f).
grandfather(X,Y) :- grandparent(X,Y),gender(X,m).

predecessor(X,Z) :- parent(X,Z).
predecessor(X,Z) :- parent(X,Y),predecessor(Y,Z).