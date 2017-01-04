# Cvičení 13

## Zadání

Cílem programu je správně dekódovat tajnou zprávu uloženou v 
souboru. Na prvním bajtu v souboru je uložen první znak zprávy. 
Další je uložen až po určitém počtu mezilehlých znaků, tento 
počet odpovídá decimální ASCII hodnotě posledního čteného znaku 
zprávy. Za posledním znakem zprávy následuje libovolný počet 
znaků až do konce souboru.

### Příklad
Předpokládejme zprávu "abc"

Obsah souboru:
```text
a< 97 (ascii a) mezilehlých znaků >b< 98 (ascii b) mezilehlých 
znaků >c< libovolný počet znaků >EOF
```

Ne všechny zprávy jsou však validní. Validní zpráva se pozná tak, 
že je ukončena podpisem "Welcome to 2017". Pokud váš program, 
kdykoliv během čtení souboru narazí na situaci, kdy doposud 
dekódovaná zpráva končí tímto podpisem, tak považujte zprávu za 
ukončenou a načtenou. Zprávy s chybějícím podpisem nejsou 
validní.

```C
#define SIGNATURE "Welcome to 2017"
```

### Rozhraní vašeho programu:

Vstupní soubor dostane váš program jako parametr z přikazové 
řádky na 1. pozici (`argv[1]`). Na 2. pozici (`argv[2]`) se 
nachází jméno výstupního souboru, kam váš program vypíše celou 
zprávu, bez podpisu (a bez zbytečného odřádkování, pouze zprávu). 
Program tedy musí jak správně načítat soubor, tak i správně 
vypsat zprávu do souboru.

```bash
$ ./reader 
Usage: ./reader <input file name> <output file name>
```

### Příklad vstupu
K dispozici v 
[/var/tmp/tester/input/0100_in.txt](https://github.com/tulinkry/teaching-sources/blob/master/13/input/0100_in.txt) 
obsahující zprávu "test".

Příklad výstupu v cílovém souboru pro daný vstup:
```text
test
```
(žádné odřádkování navíc, zpráva je bez podpisu)

### Chybný vstup

Váš program musí detekovat nesprávný vstup. Za nesprávný vstup 
považujte:
- neexistující vstupní soubor
- nečitelný vstupní soubor
- chyba při čtení vstupního souboru
- zpráva bez podpisu
- neočekávaný konec zprávy
- chyba při zapisování do výstupního souboru

Program toto detekuje a vypíše na standardní výstup větu 
"Nespravny vstup." spolu s odřádkováním. A chybu signalizuje 
**také** nenulovým návratovým kódem funkce `main()`.

```C
printf ( "Nespravny vstup.\n" );
```

## Bonus

V bonusových testech je zpráva v souboru zakódována dle schématu 
výše, nicméně pro větší zmatení nepřítele byla před kódováním 
abecedně posunuta. 

Příklad posunu je vidět na příkladu zprávy "abc", která tak má z 
definice posun 0. Pro posun 1 se ze zprávy "abc" stává "bcd", pro 
posun 2 "cde" atd. 
Tento posun je praktikovaný na každém znaku zprávy v rozsahu 
jednoho bajtu (tedy až 256 hodnot). Pro větší posuny mohou znaky 
v abecedě přetéct mimo abecední znaky (např. 'z' + posun 2 = 
'|'). Na konci zprávy se opět nachází podpis, také posunutý. 
Cílem je nalézt takový posun, pokud existuje, a vypsat původní 
zprávu dle pravidel základního zadání.

Nezapomeňte, že zprávu před výpisem do souboru je třeba převést 
na její původní podobu (bez posunu).

### Nápověda

Základní řešení je nutné obohatit o test všech možných posunů a 
implementovat porovnávání řetězců, kde se u jednoho řetězce 
předpokládá, že je posunutý.

## Odevzdání

1. Vytvořte váš program, přeložte ho do binární podoby
2. Zjistěte, jestli máte přístup k `/var/tmp/tester/test`
3. Spusťte testy
```bash
$ alias tester='/var/tmp/tester/test' # vytvoří dočasný alias
$ tester # vypíše zprávu o používání
$ tester a.out # otestuje vaší binárku "a.out"
$ tester ../../main # otestuje vaší binárku "main" v jiné 
adresářové struktuře
$ tester --with-output a.out # otestuje vaší binárku "a.out" a 
zobrazí všechny vámi generované výstupy
```
Alternativa pokud vám nejde sekce "Odevzdávání":
```bash
git clone https://github.com/tulinkry/teaching-sources
cd teaching-sources/13
./test
```

### Nápověda

Vstupní soubory naleznete v adresáři 
`/home/users/t/tulinkry/tester/input`

```bash
$ ls -l /var/tmp/tester/input
```
