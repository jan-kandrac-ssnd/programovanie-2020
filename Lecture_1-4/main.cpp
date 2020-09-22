#include <iostream>

using namespace std;

//
// Zadania na hodinu #1
// 1.1 -1.4 - vstup, výstup, podmienky a operátory
//
// https://docs.google.com/document/d/1GkzQLHn73lOul08Bq754SvTKeHJ9ouLrI1crmTh1RpU
//

/*
 * Načítajte zo štandardného vstupu meno a priezvisko.
 * Na štandardný výstup následne vypíšte text ukončený
 * znakom konca riadku vo formáte
 *
 * Ahoj, <meno> <priezvisko>!
 */
int assignment1() {
    string name, surname;
    cin >> name >> surname;

    // Vypis podla zadania + znak konca riadku:
    cout << "Ahoj, " << name << " " << surname << "!" << endl;

    return 0;
}

/**
 * Načítajte zo štandardného vstupu meno a priezvisko.
 * V načítaných hodnotách nastavte prvé písmeno na veľké.
 * Použite funkciu toupper. Na štandardný výstup následne
 * vypíšte text ukončený znakom konca riadku vo formáte:
 *
 * Ahoj, <meno> <priezvisko>!
 */
int assignment2() {
    string name, surname;
    cin >> name >> surname;
    name[0] = toupper(name[0]);
    surname[0] = toupper(surname[0]);
    cout << "Ahoj, " << name << " " << surname << "!" << endl;

    return 0;
}

/**
 * Načítajte zo štandardného vstupu meno a priezvisko.
 * Ak sa meno aj priezvisko začínajú veľkým písmenom,
 * tak na štandardný výstup vypíšte text ukončený znakom
 * konca riadku vo formáte:
 *
 * Ahoj, <meno> <priezvisko>!
 *
 * Pre zistenie, či je znak veľké písmeno použite funkciu
 * isupper.
 */
int assignment3() {
    string name, surname;
    cin >> name >> surname;
    if (isupper(name[0]) && isupper(surname[0])) {
        cout << "Ahoj, " << name << " " << surname << "!" << endl;
    }

    return 0;
}

/**
 * Načítajte zo štandardného vstupu meno a priezvisko.
 * Ak sa meno aj priezvisko začínajú veľkým písmenom,
 * tak na štandardný výstup vypíšte text ukončený znakom
 * konca riadku vo formáte:
 *
 * Ahoj, <meno> <priezvisko>!
 *
 * Ak sa meno alebo priezvisko nezačínajú veľkým písmenom,
 * tak na štandardný výstup vypíšte text ukončený znakom
 * konca riadku vo formáte:
 *
 * Meno aj priezvisko sa musia zacinat velkym pismenom!
 *
 * Pre zistenie, či je znak veľké písmeno použite funkciu
 * isupper.
 */
int assignment4() {
    string name, surname;
    cin >> name >> surname;
    if (isupper(name[0]) && isupper(surname[0])) {
        cout << "Ahoj, " << name << " " << surname << "!" << endl;
    } else {
        cout << "Meno aj priezvisko sa musia zacinat velkym pismenom!" << endl;
    }

    return 0;
}

/**
 * Načítajte zo štandardného vstupu 3 čísla. Na štandardný
 * výstup vypíšte 3 riadky vo formáte:
 *
 * Prve cislo je <najvacsie | najmensie | prostredne>
 * Druhe cislo je <najvacsie | najmensie | prostredne>
 * Tretie cislo je <najvacsie | najmensie | prostredne>
 *
 * Predpokladajme, že žiadna dvojica čísel nebude rovnaká,
 * na poradí riadkov výstupu nezáleží.
 */
int assignment5() {
    int first, second, third;
    cin >> first >> second >> third;

    // efektne, ale menej efektivne riesenie - zakazdym sa zavola 12 ifov

    if (first > second && first > third) cout << "Prve cislo je najvacsie" << endl;
    if (first > second && first < third) cout << "Prve cislo je prostredne" << endl;
    if (first < second && first > third) cout << "Prve cislo je prostredne" << endl;
    if (first < second && first < third) cout << "Prve cislo je najmensie" << endl;

    if (second > first && second > third) cout << "Druhe cislo je najvacsie" << endl;
    if (second > first && second < third) cout << "Druhe cislo je prostredne" << endl;
    if (second < first && second > third) cout << "Druhe cislo je prostredne" << endl;
    if (second < first && second < third) cout << "Druhe cislo je najmensie" << endl;

    if (third > first && third > second) cout << "Tretie cislo je najvacsie" << endl;
    if (third > first && third < second) cout << "Tretie cislo je prostredne" << endl;
    if (third < first && third > second) cout << "Tretie cislo je prostredne" << endl;
    if (third < first && third < second) cout << "Tretie cislo je najmensie" << endl;

    return 0;
}

// alternativa k assignment5
int assignment5alternative1() {

    int first, second, third;
    cin >> first >> second >> third;

    // najefektivnejsie riesenie - vykonaju sa maximalne 3 ify
    // ale je uplne neprehladne a nie je vhodne na prezentaciu
    if (first > second) {
        if (first > third) {
            if (second > third) {
                // first > second > third
                cout << "Prve cislo je najvacsie" << endl;
                cout << "Druhe cislo je prostredne" << endl;
                cout << "Tretie cislo je najmensie" << endl;
            } else {
                // first > third > second
                cout << "Prve cislo je najvacsie" << endl;
                cout << "Druhe cislo je najmensie" << endl;
                cout << "Tretie cislo je prostredne" << endl;
            }
        } else {
            // third > first > second
            cout << "Prve cislo je prostredne" << endl;
            cout << "Druhe cislo je najmensie" << endl;
            cout << "Tretie cislo je najvacsie" << endl;
        }
    } else {
        if (first > third) {
            // second > first > third
            cout << "Prve cislo je prostredne" << endl;
            cout << "Druhe cislo je najvacsie" << endl;
            cout << "Tretie cislo je najmensie" << endl;
        } else {
            if (second > third) {
                // second > third > first
                cout << "Prve cislo je najmensie" << endl;
                cout << "Druhe cislo je najvacsie" << endl;
                cout << "Tretie cislo je prostredne" << endl;
            } else {
                // third > second > first
                cout << "Prve cislo je najmensie" << endl;
                cout << "Druhe cislo je prostredne" << endl;
                cout << "Tretie cislo je najvacsie" << endl;
            }
        }
    }

    return 0;
}

/*
 * Do poľa veľkosti 5 načítajte zo štandardného vstupu 5 celých čísel.
 * Tieto čísla sú body, ktoré hráč získal v kartovej hre (žolík),
 * pričom prvá položka v poli reprezentuje prvé kolo, druhá druhé atď.
 * Upravte hodnoty v poli tak, aby číslo v danom kole nereprezentovalo
 * body v aktuálnom kole, ale súčet všetkých nahratých bodov.
 * Výpis položiek poľa na štandardný výstup je dobrovoľný.
 */
int assignment6() {
    int roundScores[5];
    // for cyklus este "nevieme"
    cin >> roundScores[0] >> roundScores[1] >> roundScores[2] >> roundScores[3] >> roundScores[4];

    roundScores[1] += roundScores[0];
    roundScores[2] += roundScores[1];
    roundScores[3] += roundScores[2];
    roundScores[4] += roundScores[3];

    cout << roundScores[0] << ", " << roundScores[1] << ", " << roundScores[2];
    cout << ", " << roundScores[3] << ", " << roundScores[4] << endl;

    return 0;
}

int assignment6alternative() {
    int roundScores[5];
    for(int i = 0; i < 5; i++) {
        cin >> roundScores[i];
    }

    for(int i = 1; i < 5; i++) {
        roundScores[i] += roundScores[i - 1];
    }

    for(int i = 0; i < 4; i++) {
        cout << roundScores[i] << ", ";
    }
    cout << roundScores[4] << endl;

    return 0;
}

int main() {
    return 0;
}
