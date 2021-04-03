# Pažymių vidurkio skaičiuoklė

Programa yra skirta apskaičiuoti pažymių vidurkį arba medianą. Taip pat galima pasirinkti sugeneruoti duomenų failą bei surušiuoti studentus į "kietus" ir "minkštus" pagal jų galutinį balą. Be to yra galimybė duomenis saugoti į skirtingus konteinerių tipus.

## Veikimo principas

Paleidus programą komandinėje eilutėje yra prašoma atlikti keletą veiksmų:

- Pasirinkti ar norima, kad duomenų failai būtų sugeneruoti
- Pasirinkti ar skaityti duomenis iš failo (jei taip, tai nurodyti failą ir keliauti į paskutinį žingsnį)
- Pasirinkti ar balus generuoti atsitiktinai
- Įrašyti studento vardą ir pavardę
- Jei balai negeneruojami atsitiktinai, tai juos įrašyti
- Pasirinkti ar pridėti naują studentą (jei taip, tai viskas kartojasi nuo 2 žingsnio)
- Pasirinkti ar skaičiuoti vidurkį ar medianą

Programa suteikia galimybę generuoti atsitiktinius namų darbų rezultatus bei egzamino balą suvesti daugiau nei vieno studento duomenis bei generuoti duomenų failus.

Paleidus programą, prašome sekti komandinėje eilutėje nurodytus instrukcijas.

Vienas iš galimymų programos eigos variantų yra toks:

```shell
-> Ar norite sukurti duomenų failą[y/n]:
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
Vardenis    Pavardenis      5.25
```

Galutinis vidurkis yra apskaičiuojamas pagal formulę `galutinis = 0.4 * vidurkis + 0.6 * egzaminas`.
### Duomenų generavimo laikai
| Studentų sk.       | 1000    | 10,000  | 100,000   | 1,000,000  | 10,000,000 |
| :----------    | :------ | :------ | :-------- | :--------- | :--------- |
| Laikas (s)  | 0.0165 | 0.0505 | 0.47   | 4.8615    | 39.259    |
### Duomenų skaitymo laikai
| Studentų sk.       | 1000    | 10,000  | 100,000   | 1,000,000  | 10,000,000 |
| :----------    | :------ | :------ | :-------- | :--------- | :--------- |
| Laikas (s)  | 0.003 | 0.023 | 0.2235   | 2.207    | 12.2178    |
### Studentų rūšiavimo laikai
| Studentų sk.       | 1000    | 10,000  | 100,000   | 1,000,000  | 10,000,000 |
| :----------    | :------ | :------ | :-------- | :--------- | :--------- |
| Laikas (s)  | 0.0005 | 0.0043 | 0.0585   | 0.520   | 2.758    |
### Studentų išvedimo laikai
| Studentų sk.       | 1000    | 10,000  | 100,000   | 1,000,000  | 10,000,000 |
| :----------    | :------ | :------ | :-------- | :--------- | :--------- |
| Laikas (s)  | 0.02 | 0.0516 | 0.4146   | 3.766    |37.2427   |

---
Spartos tikrinimas naudojant skirtingus konteinerių tipus.

# Duomenų skaitymo laikai
| Container   | 1.000   | 10.000  | 100.000   | 1.000.000  | 10.000.000 |
| :---------- | :------ | :------ | :-------- | :--------  | :--------  | 
| std::deque  | 0.12392 | 0.08896 | 0.67161   | 6.80709    | 66.5387    |
| std::list   | 0.11495 | 0.09494 | 0.67161   | 6.55124    | 69.6191    |
| std::vector | 0.11393 | 0.07797 | 0.68260   | 6.57023    | 69.2707    |

# Duomenų rūšiavimo laikai

| Container   | 1.000   | 10.000  | 100.000   | 1.000.000  | 10.000.000 |
| :---------- | :------ | :------ | :-------- | :--------  | :--------  | 
| std::deque  | 0.00800 | 0.00599 | 0.06597   | 0.68760    | 10.8864    |
| std::list   | 0.00900 | 0.00899 | 0.08095   | 0.778534   | 8.70099    |
| std::vector | 0.00899 | 0.00699 | 0.08095   | 0.883492   | 8.30024    |

Spartos tikrinimas atliktas su Processor	Intel(R) Core(TM) i5-4210U CPU @ 1.70GHz, 2401 Mhz, 2 Core(s), 6 GB, 


## Programos diegimas ir paleidimas

- Atsisiųskite programos versiją iš github'o,
- Programą sukompiliuokite.


### Changelog

- [v0.1](https://github.com/PovilasRandis/2laboratorinis/releases/tag/v0.1) - Pradinė programos versija
- [v0.1](https://github.com/PovilasRandis/2laboratorinis/releases/tag/v0.2) - Antroji programos versija. Papildyta, jog būtų galima skaityti duomenis iš failų ir išvesti rezultatus į failą.
- [v0.3](https://github.com/PovilasRandis/2laboratorinis/releases/tag/v0.3) Šioje versijoje main.cpp buvęs kodas išskirstytas į kelis skirtingus failus(pvz. funkcijos yra funkcijos.cpp faile, struktūra header faile ir t.t.). Taip pat, kodas buvo patobulintas realizuojant išimčių (Exception) valdymą.
- [v0.4](https://github.com/PovilasRandis/2laboratorinis/releases/tag/v0.4) Šioje versijoje buvo pridėta galimybė generuoti duomenų failus, studentai pagal savo galutinį balą skirstomi į 2 grupes("Kietus" ir "Minkštus"). Taip pat matuojamas tam tikrų operacijų atlikimo laikas.
- [v0.5](https://github.com/PovilasRandis/2laboratorinis/releases/tag/v0.5) Šioje versijoje buvo pridėta galimybė duomenis saugoti į skirtingus konteinerių tipus.
