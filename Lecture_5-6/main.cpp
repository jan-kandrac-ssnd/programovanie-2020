#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

/*
 * #1 Štandardný for cyklus
 *
 * Načítajte zo štandardného vstupu 2 hodnoty. Prvá premenná n, bude celočíselná,
 * druhá premenná text bude držať text. Na štandardný výstup následne vypíšte n riadkov
 * s načítaným textom z premennej text ukončený znakom konca riadku.
 */
int uloha1() {
    int n;
    string text;
    cin >> n >> text;

    for (int i = 0; i < n; i++) {
        cout << text << endl;
    }
    return 0;
}

/*
 * #2 Obrátený for cyklus
 *
 * Vytvorte jednoduchý časovač. Načítajte zo štandardného vstupu hodnotu do celočíselnej premennej n.
 * Na obrazovku vypíšte na samostatné riadky čísla od n po 1. V poslednom riadku vypíšte text Stop
 * ukončený znakom konca riadku. Prvé odprezentované riešenie, ktoré medzi výpismi do riadku počká
 * 1 sekundu bude ocenené 3 bonusovými bodmi.
 */
int uloha2() {

    int timer;

    cin >> timer;

    for (int i = timer; i > 0; i--) {
        cout << i << endl;
        // multiplatform sleep
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "Stop" << endl;
    return 0;

}

/*
 * #3 Cyklus while / do-while
 *
 * Načítajte zo štandardného vstupu číslo n > 10. Na štandardný vstup vypíšte všetky fibonnaciho čísla
 * menšie ako číslo n. Prvé 2 Fibonnaciho čísla sú 0 a 1. Každé ďalšie číslo sa získava súčtom dvoch
 * predchádzajúcich. Teda súčet prvého a druhého čísla je 0 + 1 = 1. Súčet druhého a tretieho čísla
 * je 1 + 1 = 2. Tretie + štvrté je 1 + 2 = 3…
 *
 * Ukážka prvých pár fibonnaciho čísel
 *
 * 0 1 1 2 3 5 8 13 21 34 55 ...
 *
 * Pre cyklenie použite cyklus while alebo do-while
 */
int uloha3() {

    int n;
    cin >> n;

    int previous = 0;
    int actual = 1;     // alebo "sum"

    cout << 0 << endl;

    // tento algoritmus spočíva vo vypočítaní aktuálnej a predchádzajúcej hodnoty.
    // Ak som teda mal predchádzajúce číslo 3 a aktuálne 5, potom v mojom cykle
    // chcem získať nové predchádzajúce = 5 a nové aktuálne = 8

    while (actual < n) {
        cout << actual << endl;
        int help = actual;
        actual += previous;     // aktuálne je súčtom dvoch predošlých
        previous = help;        // predchádzajúce číslo sa nastaví na hodnotu aktuálneho
    }

    return 0;
}

/*
 * #4 cyklus do-while
 *
 * Zadanie #3 upravte tak, aby sa program vždy po vykonaní opýtal používateľa, či chce
 * začať odznova a to textom “prajete si program zopakovat? (y/n)”. Pokial používateľ
 * zadá y program sa vykoná znova, ak zadá n, program sa ukončí.
 *
 * Použite cyklus do-while
 */
int uloha4() {

    char execute;

    do {
        int hranica;
        cin >> hranica;

        int previous = 0;
        int actual = 1;

        cout << 0 << endl;

        while (actual < hranica) {
            cout << actual << endl;
            int help = actual;
            actual += previous;
            previous = help;
        }

        cout << "prajete si program zopakovat? (y/n)" << endl;
        cin >> execute;

    } while (execute == 'y');

    return 0;
}

/*
 * #5 switch-case
 *
 * Napíšte program pre získanie hodnotenia predajcu. Vypíšte na štandardný
 * výstup: “How would you rate your experience on scale 1-5?” a do celočíselnej
 * premennej mood uložte číslo zo štandardného vstupu. V prípade, že číslo bude
 * 1 alebo 2 vypíšte “Thank you for your vote!”, ak bude číslo 3 - 5 vypíšte
 * "Hope we can do better next time!", ak číslo bude mimo intervalu 1-5 vypíšte
 * “Incorrect input!”
 */
int uloha5() {
    int mood;
    cout << "How would you rate your experience on scale 1-5?" << endl;
    cin >> mood;

    switch (mood) {
        case 1:
        case 2:
            cout << "Thank you for your vote!";
            break;
        case 3:
        case 4:
        case 5:
            cout << "Hope we can do better next time!";
            break;
        default:
            cout << "Incorrect input!";
            break;
    }

    return 0;
}

/*
 * #6 Komplexnejšie zadanie - viac cyklov
 *
 * Upravte riešenie z úlohy 5 tak, aby pri načítaní čisla mimo intervalu
 * 1-5 okrem vypísania “Incorrect input!” sa spustil program znova.
 */
int uloha6() {
    int mood;
    bool invalidInput = true;
    cout << "How would you rate your experience on scale 1-5?" << endl;

    do {
        cin >> mood;

        switch (mood) {
            case 1:
            case 2:
                cout << "Thank you for your vote!" << endl;
                invalidInput = false;
                break;
            case 3:
            case 4:
            case 5:
                cout << "Hope we can do better next time!" << endl;
                invalidInput = false;
                break;
            default:
                cout << "Incorrect input!" << endl;
                invalidInput = true;
                break;
        }
    } while (invalidInput);

    return 0;
}

int main() {
    return uloha6();
}
