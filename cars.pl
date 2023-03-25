forsale(bmw).
forsale(m800).
forsale(ford).

like(ram,bmw).
like(sohan,bmw).
like(sita,ford).

canbuy(X,Y):-like(X,Y),forsale(Y).

willbuy(X):-canbuy(X,Y).
whowillbuy(Y):-like(X,Y).

/*
Will Sita buy a car?
willbuy(sita).
true.

Who will buy BMW?
?- like(X,bmw).
X = ram ;
X = sohan.

Which cars are there for cell?
?- forsale(X).
X = bmw ;
X = m800 ;
X = ford.

*/
