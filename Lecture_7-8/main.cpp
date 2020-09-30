#include <iostream>

/*
 * #1 Logické operácie - ekvivalencia
 *
 * Počas hodiny sme si spomínali, že popri negácii, súčinu, súčtu a XOR-u existuje
 * viacero ďalších logických operácií. Najznámejšie z nich sú implikácia a ekvivalencia.
 *
 * Ekvivalencia vracia true, ak je A rovnaké ako B. Teda výrok je pravdivý ak platí:
 * “A platí práve vtedy a len vtedy ak platí B”.
 *
 * Zapíšte ako by ste ekvivalenciu zapísali v jazyku C++ iba pomocou konjunkcie,
 * disjunkcie a negácie. Teda za riešenie nepokladám A == B Riešenie je zápis na jeden riadok.
 */
int uloha1() {
    bool A, B;
    // ekvivalencia plati, ak A a B sú pravdivé, alebo A ani B nie sú pravdivé
    bool result = ((A && B) || (!A && !B));
    return 0;
}

/*
 * #2 Logické operácie - implikácia
 *
 * Podobne ako v úlohe 1 na jeden riadok napíšte zápis implikácie. Implikácia je pravdivá
 * ak platí výrok: “Ak platí A potom platí B”. Napríklad: “Ak si rytier, tak nosíš brnenie”.
 */
int uloha2() {
    bool A, B;
    bool result = !(A && !B); // jediny pripad, kedy implikacia neplati je A==true a B==false - takze znegujeme A&!B
    return 0;
}

/*
 * #3 Logické operácie - negácia logického súčtu / disjunkcie
 *
 * Zapíšte ekvivalent (keďže už viete, čo ekvivalent znamená) tejto operácie:
 *
 * !(A || B)
 *
 * V matematickej logike je negácia disujnkcie aj negácia konkunkcie základným vzorcom.
 */
int uloha3() {
    bool A, B;
    bool result = !A && !B; // negacia vety - "plati A alebo B" je "neplati A ani B" == !A && !B
    return 0;
}

/*
 * #4 Bitové operácie - bitový posun 1
 *
 * Vypíšte na štandardný výstup mocniny čísla 2 za pomoci bitového posunu. Použite čím väčší číselný rozsah.
 */
int uloha4() {
    int actual = 1;

    // klasicky for (hodnota 8 nie je spravna, ale postaci)
    for(int i = 0; i < 8; i++) {
        std::cout << actual << std::endl;
        actual = actual << 1;
    }

    // for s dvoma vyrazmi v editacnej casti
    for(int i = 0; i < 8; i++, actual = actual << 1) {
        std::cout << actual << std::endl;
    }

    return 0;
}

/*
 * Idealne riesenie ulohy 4
 */
int uloha4alternative() {
    // funkcia sizeof vracia velkost datoveho typu v bytoch (x8 kvoli prevodu na pocet bitov)
    for(unsigned i = 0; i < 8 * sizeof(long); i++) {
        std::cout << (1ul << i) << std::endl;
    }
    return 0;
}

/*
 * #5 Bitové operácie - bitový posun 2
 *
 * Vypíšte na štandardný výstup mocniny čísla 4 za pomoci bitového posunu.
 * Použite čím väčší číselný rozsah.
 */
int uloha5() {

    // mocniny cisla 4 su 1, 4, 16, 64 v bitovom zapise
    // 00000001
    // 00000100
    // 00010000
    // 01000000
    // teda sa jedna o bitovy posun o 2 pozicie dolava
    int actual = 1;

    // klasicky for (hodnota 8 nie je spravna, ale postaci)
    for(int i = 0; i < 8; i++) {
        std::cout << actual << std::endl;
        actual = actual << 2;
    }

    // idealne riesenie
    for(unsigned i = 0; i < 8 * sizeof(long); i+=2) {
        std::cout << (1ul << i) << std::endl;
    }

    return 0;
}

/*
 * #6 Bitové operácie - počet nastavených bitov
 *
 * Vypíšte na štandardný výstup počet nastavených bitov v celočíselnej premennej
 * typu unsigned int. Celočíselná premenná môže byť inicializovaná zo štandardného
 * vstupu, náhodne, alebo akoukoľvek inou formou. (Nezaujíma ma, ako sa k číslu dostanete)
 */
int uloha6() {
    unsigned int n = 0b010100101011101011;  // 10x
    int sum = 0;

    while (n != 0) {
        // (n & 1) == (n % 2 == 1)
        // n & 1 nam vrati 1, ak sa bitovy zapis cisla konci 1tkou = je neparne
        if (n & 1) { sum++; }
        n = n >> 1;
    }

    std::cout << sum << std::endl;

    return 0;
}

/*
 * #7 Bitové operácie - výpis nastavených bitov
 *
 * Vypíšte na štandardný výstup pozície nastavených bitov v celočíselnej premennej typu
 * unsigned int. Celočíselná premenná môže byť inicializovaná zo štandardného vstupu,
 * náhodne, alebo akoukoľvek inou formou. (Nezaujíma ma, ako sa k číslu dostanete)
 */
int uloha7() {
    unsigned int n = 0b010100101011101011;

    for(int i = 0; n != 0; i++, n = n >> 1) {
        if (n & 1) {
            std::cout << "Nastaveny bit #" << i << std::endl;
        }
    }

    return 0;
}

/*
 * #8 Bitové operácie - otočenie bitov
 *
 * Vypíšte na štandardný výstup hodnotu s otočenými bitmi (nuly nahradené jednotkami
 * a jednotky nulami) premennej typu unsigned int. Celočíselná premenná môže byť
 * inicializovaná zo štandardného vstupu, náhodne, alebo akoukoľvek inou formou.
 * (Nezaujíma ma, ako sa k číslu dostanete)
 */
int uloha8() {
    unsigned int n = 0b010100101011101011;
    unsigned int mask = 0 - 1;              // toto mi vrati cislo s nastavenymi vsetkymi bitmi na 1
    unsigned int result = n ^ mask;         // operacia XOR otoci vsetky bity na opacnu hodnotu
    std::cout << result << std::endl;

    return 0;
}

int main() {
    return 0;
}
