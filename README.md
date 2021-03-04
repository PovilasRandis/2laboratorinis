# Pažymių vidurkio skaičiuoklė

Programa yra skirta apskaičiuoti pažymių vidurkį arba medianą.

## Veikimo principas

Paleidus programą komandinėje eilutėje yra prašoma atlikti keletą veiksmų:

- Prašoma pasirinkti ar norite, jog duomenys būtų nuskaityti iš failo.
- Arba
- Suvesti duomenis (t.y. vardas, pavardė, namu darbu pažymiai, egzamino įvertinimas)
- Po duomenų suvedimo yra apskaičiuojamas galutinis pažymis įvertinimų vidurkiu arba mediana.

Programa suteikia galimybę generuoti atsitiktinius namų darbų rezultatus bei egzamino balą, bei suvesti daugiau nei vieno studento duomenis.

Paleidus programą, prašome sekti komandinėje eilutėje nurodytus instrukcijas.

Vienas iš galimymų programos eigos variantų yra toks:

```shell
-> Ar norite skaityti duomenis iš tekstinio failo[y/n]: 
-> Įveskite 1 studento vardą: Vardenis
-> Įveskite 1 studento pavardę: Pavardenis
-> 1 studento 1 namu darbo ivertinimas [0-10], (Jei norite gauti atsitiktini skaiciu, iveskite y): 
-> 1 studento 2 namu darbo ivertinimas [0-10], (Jei norite gauti atsitiktini skaiciu, iveskite y):
-> Ar prideti dar viena studenta? [Y/N]: 
-> Rodyti vidurki ar mediana? [V/M]:
```

Po sėkmingo duomenų suvedimo į rezultatų failą išvedami rezultatai panašia forma:

```shell
Vardas      Pavarde         Galutinis Vid. Galutinis Med.
----------------------------------------------------------
Vardenis    Pavardenis      5
```

Galutinis vidurkis yra apskaičiuojamas pagal formulę `galutinis = 0.4 * vidurkis(mediana) + 0.6 * egzaminas`.

## Programos diegimas ir paleidimas

- Atsisiųskite programos versiją iš github'o,
- Programą sukompiliuokite.


### Changelog

- [v0.1](https://github.com/PovilasRandis/2laboratorinis/releases/tag/v0.1) - Pradinė programos versija
- [v0.2](https://github.com/PovilasRandis/2laboratorinis/releases/tag/v0.2) - Antroji programos versija. Papildyta, jog būtų galima skaityti duomenis iš failų ir išvesti rezultatus į failą.
