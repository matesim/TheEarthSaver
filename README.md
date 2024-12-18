# TheEarthSaver
Můj první projek na progamování v C++ s pomocí knihovny SFML. Je to 2D hra na styl jedné z miniher z mobilní aplikace/hry [Pou](https://play.google.com/store/apps/details?id=me.pou.app&pli=1). Je to tvořeno za účelem odevzdat ročníkovou práci na předmět mikropočítačové systémy s libovolným tématem, které nějak souviví s mým studiem. 

## O čem je a jak funguje gameplay
Hra má zcela jednoduchý cíl a gameplay. Ovládáte nebo jestli chcete hrajete za postavu, která má za úkol chytit co největí počet bomb, aby nestihy spadnout na zem. Bomby se spawnují/objevují na vrchu okna hry, objevují se náhodně, na teoretické ose x, následně padají dolů. Váš cíl je pohnou postavou tak, aby se textura postavy a bomby v jakékoli části střetla, což bombu odstraní a vám přidá skóre. Cíl je primitivní a to získat co nejvíce bodů aniž by jste umřeli. Maximalní počet bomb co můžou spadnou na zem je 4. S pátou dopadnutou bombou je hra automaticky ukončena.
### Ovládání
A - pohyb postavy doleva <br/>
D - pohyb postavy doprava <br/>
ESC - okamžité ukončení okna se hrou <br/>

## Tvorba hry
Jelikož jsem neměl žádné dřívější zkušenosti s jakoukoli tvorbou her v programovacím jazyce C++, můj první krok byl zjistit, jak je možné udělat otevírací okno, aby hra nebyla tvořena v konzoli. Našel jsem SFML knihovnu [[5]](#Literatura-a-čerpání-informací) která toto umožňuje. Našel jsem si tutorial na tuto knihovnu jak se pomocí ní tvoří hry, je to playlist několika videí [[1]](#Literatura-a-čerpání-informací), kde je vytvářenoo více her. Já si vybral tu první [[2]](#Literatura-a-čerpání-informací) na které jsem postavil tento projekt. Celý tento tutorial jsem zhlédl, postupoval jsem podle něho a vytvořil [kopii této hry](https://github.com/matesim/SimplFirstGame) za účelem prakticky zkusit a použít způsob kódování jak v C++ tak i v SFML knihovně. Hru kterou jsem udělal pro projekt je zásadně odlišná, ale použil jsem zde základ jeho strukturování. Poté jsem jeho kód používal pro zjištění kam co patří nebo jeho způsoby řešení problémů. Jelikož v tutoriálu nebyly použity celkově textury, které ale já zahrnout chtěl, zhlédl jsem na toto téma video [[4]](#Literatura-a-čerpání-informací) a doplňkové informace jsem hledal na oficiálních stránkách [[7]](#Literatura-a-čerpání-informací). Největší problém jsem měl když jsem se snažil, aby bylo možné v pozdějším vývoji pozměnit velikosti okna, což jsem následně zjistil že mám špatně posunutý řádek kódu. Rád bych zmínil že mi velmi pomohla dokumentace k texturám [[6]](#Literatura-a-čerpání-informací), kde jsem potřeboval zjistit jak dostanu na return velikost v pixelech té textury. Ten největší problém byl s mazáním srdíček při dopadnutí bomb na zem (z okna), to se mi podařilo vyřešit pomocí dokumentace ke knihovně vector [[8]](#Literatura-a-čerpání-informací). Textury jsem si tvořil sám proto i tak vypadají tak jak vypadají. Byly vyhotoveny v Paint.NET [[9]](#Literatura-a-čerpání-informací).

## Jak si tuto hru stáhnou?
Pro spuštění této hry je potřeba Visual Studio 2022 nebo jiný IDE který potporuje spouštění C++ kódů. Jelikož je kód tvořen právě ve Visual Studio 2022 [[10]](#Literatura-a-čerpání-informací), tak je jistější, že i zde vám půjde spustit. Pokud nevíte jak tuto aplikaci stáhnout postup najdete [zde](#Instalace-Visual-Studio-2022). Po uspěšné instalaci je nutné vytvořit nový projekt pomocí naklonování repozitáře do aplikace. Přitom budete muset vložit url adresu tohoto repozitáře, kterou získáte na [hlavní stránce TheEarthSaver](https://github.com/matesim/TheEarthSaver), kliknutím na tlačítko code a zkopírování HTTPS adresy. To je vše a kód můžete spustit. Instalace SFML do projektu není nutné!

## Instalace Visual Studio 2022
Běžte na stránky [Visual Studio 2022](https://visualstudio.microsoft.com/vs/), kde kliknete na tlačítko Download Visual Studio --> Community 2022. Otevře se vám nová stránka a File Explorer s umístěním instalačního souboru. Ten poté otevřete, projedete základním nastavením a následně nainstalujete. Pro vizuální postup múžete využít jakékoli nebo například toto [video](https://www.youtube.com/watch?v=-B7GObvvems)

## Literatura a čerpání informací
[1] SHARMA, Suraj. C++ SFML Simple Apps and Games: YouTube Playlist. Online. In: . Dostupné z: https://www.youtube.com/playlist?list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up. [cit. 2024-12-17].

[2] SHARMA, Suraj. SFML_C-_Simple_Games: GitHub Repository. Online. In: . Dostupné z: https://github.com/SurajSharma90/SFML_C-_Simple_Games/tree/master/SFML_C%2B%2B_Simple_Games/SFML_C%2B%2B_Simple_Games/Game%201. [cit. 2024-12-17].

[3] GORDAN, Victor. SFML Tutorial - Install: YouTube Video. Online. In: . 2021. Dostupné z: https://www.youtube.com/watch?v=WoVoIhgutMU. [cit. 2024-12-17].

[4] SHAH, Mike. SFML Introduction to Sprites and Textures: YouTube Video. Online. In: . 2022. Dostupné z: https://www.youtube.com/watch?v=7QBUqLdCV1g. [cit. 2024-12-17].

[5] GOMILA, Laurent. Simple and Fast Multimedia Library. Online. Dostupné z: https://www.sfml-dev.org/index.php. [cit. 2024-12-17].

[6] GOMILA, Laurent. Documentation of SFML 2.6.2 - sf::Texture Class Reference. Online. Dostupné z: https://www.sfml-dev.org/documentation/2.6.2/classsf_1_1Texture.php. [cit. 2024-12-17].

[7] GOMILA, Laurent. SFML 2.6 Tutorials - Sprites and textures. Online. Dostupné z: https://www.sfml-dev.org/tutorials/2.6/graphics-sprite.php. [cit. 2024-12-17].

[8] CPLUSPLUS.COM. Reference <vector> vector - std::vector. Online. Dostupné z: https://cplusplus.com/reference/vector/vector/. [cit. 2024-12-17].

[9] BREWSTER, Rick. Paint.NET. Online. Dostupné z: https://www.getpaint.net/index.html. [cit. 2024-12-18].

[10] MICROSOFT CORPORATION. Visual Studio 2022. Online. Dostupné z: https://visualstudio.microsoft.com/vs/. [cit. 2024-12-18].
