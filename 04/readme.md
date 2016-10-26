# Vstup a výstup + výpočty

Následující kódy zobrazují jednoduché programy v jazyce C 
pracující se vstupem a výstupem a provádějící jednoduché výpočty.

## bottle.c

Program načte ze vstupu sekvenci identifikující položky v automatu na vratné lahve.

1. láhev je identifikována jako 'b'
2. přepravka je identifikována jako 'p'
		u přepravky je dodatečně nutné zadat, desetinné číslo, které popisuje, v jakém je stavu
3. sud je identifikován jako 'k'
		u sudu lze písmeny s, m, l určit jeho velikost

Na výstup vypíše, kolik dostane uživatel za zpracovaný seznam peněz. Program se přitom drží
základních pravidel:

1. láhev je za 3
2. přepravka je za 100 * koeficient kvality
3. sud velikosti
	- m stojí 1000
	- l stojí 2x tolik (tedy 2000)
	- s stojí polovinu (tedy 500)

## ratio.c

Program načte zlomky ve tvaru a/b ze vstupu a porovná, jestli jejich součet dohromady dává 1.

## sub.c

Program demonstruje porovnávání dvou čísel s plovoucí desetinnou čárkou.