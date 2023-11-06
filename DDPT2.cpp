#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;

    cout << "Masukkan Nilai Sisi: ";
    cin >> n;

    while (n < 0) {
        cout << "\Nilai tidak boleh kurang dari nol! Masukkan Nilai: ";
        cin >> n;
    }

    for (int i = 0; i <= (n*n); i++) {
        for (int j = 0; j <= (n*n); j++) {
            if (i == 0 || i % n == 0 || j == 0 || j % n == 0) {
                cout << setw(2) << "*";
            } else {
                cout << setw(2) << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
