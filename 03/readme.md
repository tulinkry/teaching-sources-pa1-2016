# Vstup a výstup + výpočty

Následující kódy zobrazují jednoduché programy v jazyce C 
pracující se vstupem a výstupem a provádějící jednoduché výpočty.

## binary.c

Program načte celé číslo ze vstupu a vypíše jeho binární reprezentaci v počítači.

Stojí za povšimnutí, že pokud použijeme jiný typ pro proměnnou a a správnou
vstupní a výstupní konverzi, funguje toto řešení univerzálně.

## chess.c

Program načte ze vstupu dvě souřadnice ve formátu &lt;písmeno&gt;&lt;číslo&gt;,
kde písmeno je z intervalu a-h a číslo z intervalu 1-8 (jako v šachách).

Pro dané dvě souřadnice vypíše manhattanskou a euklidovu vzdálenost.

POZOR: kompilujeme s přepínačem -lm (kvůli math.h)

## month.c

Program načte ze vstupu datum ve formátu D/M/Y.

Program signalizuje jak chybný formát, tak nevalidní datum. Pro validní datum
spočítá kolik dní chybí do konce načteného měsíce.