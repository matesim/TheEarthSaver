# TheEarthSaver
Toto je můj první projek na progamování v C++ s pomocí knihovny SFML. Je to 2D hra na styl jedné z miniher z mobilní aplikace/hry [Pou](https://play.google.com/store/apps/details?id=me.pou.app&pli=1). Je to tvořeno za účelem odevzdat ročníkovou práci na předmět mikropočítačové systémy s libovolným tématem, které nějak souviví s mým studiem. 

## O čem je a jak funguje gameplay

## Tvorba hry
Jelikož jsem neměl žádné dřívější zkušenosti s jakoukoli tvorbou her v programovacím jazyce C++, můj první krok byl zjistit, jak je možné udělat otevírací okno, aby hra nebyla tvořena v konzoli. Našel jsem SFML knihovnu [[5]](#Literatura-a-čerpání-informací) která toto umožňuje. Našel jsem si tutorial na tuto knihovnu jak se pomocí ní tvoří hry, je to playlist několika videí [[1]](#Literatura-a-čerpání-informací), kde je vytvářenoo více her. Já si vybral tu první [[2]](#Literatura-a-čerpání-informací) na které jsem postavil tento projekt. Celý tento tutorial jsem zhlédl, postupoval jsem podle něho a vytvořil kopii této [hry](https://github.com/matesim/SimplFirstGame) za účelem prakticky zkusit a použít způsob kódování jak v C++ tak i v SFML knihovně. Hru kterou jsem udělal pro projekt je zásadně odlišná, ale použil jsem zde základ jeho strukturování. Poté jsem jeho kód používal pro zjištění kam co patří nebo jeho způsoby řešení problémů. Jelikož v tutoriálu nebyly použity celkově textury, které ale já zahrnout chtěl, zhlédl jsem na toto téma video [[4]](#Literatura-a-čerpání-informací) a doplňkové informace jsem hledal na oficiálních stránkách [[7]](#Literatura-a-čerpání-informací). Největší problém jsem měl když jsem se snažil, aby bylo možné v pozdějším vývoji pozměnit velikosti okna, což jsem následně zjistil že mám špatně posunutý řádek kódu. Rád bych zmínil že mi velmi pomohla dokumentace k texturám [[6]](#Literatura-a-čerpání-informací), kde jsem potřeboval zjistit jak dostanu na return velikost v pixelech té textury. Ten největší problém byl s mazáním srdíček při dopadnutí bomb na zem (z okna), to se mi podařilo vyřešit pomocí dokumentace ke knihovně vector [[8]](#Literatura-a-čerpání-informací).

## Instalace Visual Studio 2022

## Instalace knihovny SFML do projektu

## Literatura a čerpání informací
[1] SHARMA, Suraj. C++ SFML Simple Apps and Games: YouTube Playlist. Online. In: . Dostupné z: https://www.youtube.com/playlist?list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up. [cit. 2024-12-17].

[2] SHARMA, Suraj. SFML_C-_Simple_Games: GitHub Repository. Online. In: . Dostupné z: https://github.com/SurajSharma90/SFML_C-_Simple_Games/tree/master/SFML_C%2B%2B_Simple_Games/SFML_C%2B%2B_Simple_Games/Game%201. [cit. 2024-12-17].

[3] GORDAN, Victor. SFML Tutorial - Install: YouTube Video. Online. In: . 2021. Dostupné z: https://www.youtube.com/watch?v=WoVoIhgutMU. [cit. 2024-12-17].

[4] SHAH, Mike. SFML Introduction to Sprites and Textures: YouTube Video. Online. In: . 2022. Dostupné z: https://www.youtube.com/watch?v=7QBUqLdCV1g. [cit. 2024-12-17].

[5] GOMILA, Laurent. Simple and Fast Multimedia Library. Online. Dostupné z: https://www.sfml-dev.org/index.php. [cit. 2024-12-17].

[6] GOMILA, Laurent. Documentation of SFML 2.6.2 - sf::Texture Class Reference. Online. Dostupné z: https://www.sfml-dev.org/documentation/2.6.2/classsf_1_1Texture.php. [cit. 2024-12-17].

[7] GOMILA, Laurent. SFML 2.6 Tutorials - Sprites and textures. Online. Dostupné z: https://www.sfml-dev.org/tutorials/2.6/graphics-sprite.php. [cit. 2024-12-17].

[8] CPLUSPLUS.COM. Reference <vector> vector - std::vector. Online. Dostupné z: https://cplusplus.com/reference/vector/vector/. [cit. 2024-12-17].
