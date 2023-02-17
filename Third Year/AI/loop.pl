count_to(10) :- write(10),nl.
count_to(I) :-
	write(I),nl,
	J is I + 1,
	count_to(J).