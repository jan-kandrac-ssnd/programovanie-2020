#include <iostream>

using namespace std;

/*
 * Napíšte program, ktorý vypíše 8 prvých bitov vašej premennej v bitovom zápise.
 * Premennú môžete načítať zo štandardného vstupu, alebo ju môžete mať
 * pevne definovanú (odporúčam pevne definovať)
 */
int uloha1() {
    int nasecislo;
    cin >> nasecislo;
    int mask = 0b10000000;

    for (int i = 0; i < 8; i++) {
        // postupne robime bitovy sucin s maskou (10000000) posunutou o i bitov vpravo
        // nasecislo & 10000000
        // nasecislo & 01000000
        // nasecislo & 00100000
        // ...
        bool bitAt = nasecislo & (mask >> i);
        cout << (bitAt > 0);
    }
    cout << endl;
    return 0;
}

/*
 * Napíšte program, ktorý nastaví jeden bit vo vašej premennej na hodnotu 1.
 * Premennú aj číslo bitu môžete načítať zo štandardného vstupu, alebo ju môžete mať
 * pevne definovanú (odporúčam pevne definovať)
 */
int uloha2() {
    int nasecislo;
    cin >> nasecislo;
    // nastavovat budeme stvrty bit
    int mask = 0b00001000;

    // pouzijeme bitovy or napriklad:
    // 00100 | 01000 = 01100
    int result = nasecislo | mask;

    cout << result << endl;
    return 0;
}

/*
 * Napíšte program, ktorý nastaví jeden bit vo vašej premennej na hodnotu 0.
 * Premennú aj číslo bitu môžete načítať zo štandardného vstupu, alebo ju môžete mať
 * pevne definovanú (odporúčam pevne definovať)
 */
int uloha3() {
    int nasecislo;
    cin >> nasecislo;
    // nastavovat budeme stvrty bit
    // pouzijeme negaciu cisla, teda dostaneme masku, kde je jeden bit nulovy
    int mask = ~0b00001000;

    // pouzijeme bitovy and napriklad:
    // 11110 & 10111 = 10110
    int result = nasecislo & mask;

    cout << result << endl;
    return 0;
}

/*
 * Napíšte program, ktorý skontroluje bit na konkrétnej pozícii v premennej.
 * Premennú aj číslo bitu môžete načítať zo štandardného vstupu, alebo ju môžete mať
 * pevne definovanú (odporúčam pevne definovať)
 */
int uloha4() {
    int nasecislo;
    cin >> nasecislo;
    int mask = 0b00001000;

    // Ak nase cislo po bitovom sucine bude nenulove, potom je tento bit nastaveny napr:
    // 00101010 & 00001000 = 00001000
    // vysledok je 8, to znamena, ze 4ty bit je nastaveny
    bool result = (nasecislo & mask) > 0;

    cout << "4th bit is set = " << result << endl;
    return 0;
}

/*
 * Na prvých 4 bitoch držíme skóre hráča č. 1, na ďalších 4 bitoch držíme skóre hráča č. 2.
 * Vypíšte na štandardný výstup skóre hráča č. 1. Použite aplikovanie bitovej masky.
 *
 * Napríklad skóre 1011 0111 znamená, že hráč 2 má 1011 bodov = 11 a hráč 1 má 0111 = 7 bodov.
 */
int uloha5() {
    int nasecislo;
    cin >> nasecislo;
    int maskPlayer1 = 0b00001111;
    int maskPlayer2 = 0b11110000;

    // bitovym sucinom s maskPlayer1 vymazeme bity pre druheho hraca
    int scorePlayer1 = nasecislo & maskPlayer1;

    cout << scorePlayer1 << endl;
    return 0;
}

/*
 * Na prvých 4 bitoch držíme skóre hráča č. 1, na ďalších 4 bitoch držíme skóre hráča č. 2.
 * Vypíšte na štandardný výstup skóre hráča č. 2. Použite aplikovanie bitového posunu a bitovej masky
 *
 * Napríklad skóre 1011 0111 znamená, že hráč 2 má 1011 bodov = 11 a hráč 1 má 0111 = 7 bodov.
 */
int uloha6() {
    int nasecislo;
    cin >> nasecislo;
    int maskPlayer1 = 0b00001111;
    int maskPlayer2 = 0b11110000;

    // bitovym sucinom s maskPlayer2 vymazeme bity pre prveho hraca
    // 10011010 & 11110000 = 10010000
    int help = nasecislo & maskPlayer2;

    // vysledne cislo este musime posunut o 4 bity doprava
    // 10010000 >> 4 = 00001001
    int scorePlayer2 = help >> 4;

    cout << scorePlayer2 << endl;
    return 0;
}

int main() {

    uloha6();

    // maska byva pevne dana (celociselna konstanta)
    // nad maskou sa aplikuju bitove operacie

    return 0;
}
