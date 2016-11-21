# Funkce a vstupně výstupní parametry

Následující kódy zobrazují jednoduché programy v jazyce C 

## date.c

Zadani programu bez vyplneneho reseni. Bez modifikace funkce main doplnte jednotlive funkce tak,
aby program v pořádku doběhl (neskončil na makru assert).

Program načte ze vstupu 4 celá čísla ve formátu:
```plain
n d/m/y
    d - den
    m - měsíc
    r - rok
    n - číslo dne v týdnu, kterým daný rok začíná (0 - 6 ~ pondělí - neděle)

Na výstup zobrazí pro dané datum např.
    patek 20. brezen 2016 (14)
    ^
    den v tydnu v textove reprezentaci (pro 20. 3. 2016)
    	  ^
	  den v mesici
		  	   ^
		  	   nazev mesice
		  	   		 ^
 		  	   		 rok
 		  	   		 	    ^
 		  	   		 	    poradove cislo tydne pro dane datum
```

## ref.date.c

Řešení úlohy date.c

## params.c

Program obsahuje funkci, která usnadňuje rozhodnutí o výsledku bitvy, jež se 
zúčastnily pozemní jednotky.

Ztráty na obou stranách počítá procentuelně podle zastoupení v celkové síle
všech jednotek v bitvě.

Zároveň opět demonstruje použítí assertu pro jednoduché testování.

