# SREAL2

Zadatak 2:

Napisati program koji vodi evidenciju o trenutnom stanju bodova fudbalskih klubova u
ligi. Svaki klub koji se nalazi u ligi, predstavljen je preko svog imena, trenutnog broja bodova,
broja datih golova, broja primljenih golova i broja odigranih utakmica.
Prilikom pokretanja, program proverava da li postoji tekstualna datoteka u kojoj se nalazi
tabela klubova. (3p)
Program treba da podržava sledeće:

1) Unos novog tima u tabelu. Inicijalno su svi parametri kluba (broj bodova, broj datih
golova, broj primljenih golova i broj odigranih utakmica) na nuli. (3p)

2) Tabela se pretražuje unosom trenutnog broja bodova. Ukoliko korisnik unese string “x, <”
treba da se ispišu svi klubovi koji imaju manji ili jednak broj bodova u odnosu na
parametar ‘x’, dok unos stringa “x, >” treba da izbaci sve klubove koji imaju veći ili jednak
broj bodova u odnosu na parametar ‘x’. (3p)

3) Ispis trenutnog stanja na tabeli. Prilikom ispisivanja voditi računa da redosled klubova na
tabeli zavisi od osvojenih bodova. Ukoliko klubovi imaju isti broj bodova, gleda se razlika
broja postignutih i primljenih golova, klub koji ima pozitivniju razliku ima prednost na
tabeli (Npr klub1 ima odnos 14:3 postignutih i primljenih golova, a klub2 14:4, odavde
sledi da će “klub1” biti ispred “klub2” na tabeli ukoliko imaju isti broj bodova, jer “klub1”
ima razliku postignutih i primljenih golova 11 (14 - 3), a “klub2” 10 (14 - 4)). Ukoliko je i
ovaj parametar jednak, nasumično izabrati koji klub će imati prednost na tabeli. Tabela
treba da se ispiše u sledećem formatu (4p):
Poredak TIM OS  G   B
1.  AC MILAN    34  55:4    65
2.  INTER   33  42:15   50
...

4) Korigovanje parametara kluba (broja bodova, broja golova…). Korigovanje se vrši
unosom rezultata utakmice npr:
Unesi domaći tim: AC_MILAN
Unesi gostujući tim: INTER
Unesi rezultat utakmice: 3:2
Za prethodni primer, klub AC MILAN je je pobedio, postigao 3 gola i primio dva. Dok je
Inter izgubio, primio 3 gola i dao 2. Nakon ovog unosa tablica treba da se ažurira:
Poredak TIM OS  G   B
1.  AC MILAN    34  55:4    65
2.  INTER   33  42:15   50
…
Svaka pobeda donosi timu 3 boda, nerešen rezultat 1 bod i izgubljena utakmica 0
bodova. (4p)

5) Izlaz, pri čemu se trenutno stanje na tabeli sačavava u datoteci “tabela” (3p).

Implementirati Makefile koji kompajlira izvorne fajlove i generiše izvršni fajl.
