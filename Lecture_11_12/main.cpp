#include <iostream>

using namespace std;

int uloha1() {

    int tabulka[4][2] = {
            {0, 2},
            {1, 3},
            {2, 1},
            {3, 2}
    };

    return 0;
}


int uloha2() {

    int tabulka[4][2] = {
            {0, 2},
            {1, 3},
            {2, 1},
            {3, 2}
    };

    for (int row = 0; row < 4; row++) {
        // dostal som hodnotu {0, 2} - teda pole
        for (int col = 0; col < 2; col++) {
            // dostal som hodnotu 0 alebo 2 - konkretne cislo
            int value = tabulka[row][col];
            if (col != 0) {
                cout << "-";
            }
            cout << value;
        }
        cout << endl;
    }

    return 0;
}


int uloha3() {
    int tabulka[4][2];

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 2; col++) {
            cin >> tabulka[row][col];
        }
    }

    // copy paste uloha 2
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 2; col++) {
            if (col != 0) {
                cout << "-";
            }
            cout << tabulka[row][col];
        }
        cout << endl;
    }

    return 0;
}

int uloha4() {
    int W, H;
    cin >> W;
    cin >> H;
    char values[H][W];

    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++) {
            cin >> values[y][x];
        }
    }

    // copy paste uloha 2
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (col != 0) {
                cout << "-";
            }
            cout << values[row][col];
        }
        cout << endl;
    }

    return 0;
}


int uloha5() {

    char chessboard[8][8] = {
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    char fromX;
    int fromY;

    char toX;
    int toY;

    cin >> fromX >> fromY >> toX >> toY;

    int fx = fromX - 'A';
    int fy = 8 - fromY;
    int tx = toX - 'A';
    int ty = 8 - toY;

    chessboard[ty][tx] = chessboard[fy][fx];
    chessboard[fy][fx] = ' ';

    cout << fromX << " " << fromY << " " << toX << " " << toY << endl;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << chessboard[i][j];
        }
        cout << endl;
    }

    return 0;
}


int main() {

    uloha5();

    return 0;
}
