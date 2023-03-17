forsale(bmw).
forsale(m800).
forsale(ford).

like(ram,bmw).
like(sohan,bmw).
like(sita,ford).

canbuy(X,Y):-like(X,Y),forsale(Y).

willbuy(X):-canbuy(X,Y).
whowillbuy(Y):-like(X,Y).