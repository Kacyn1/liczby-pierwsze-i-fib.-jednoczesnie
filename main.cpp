#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void primeNumbers(int n) {
    int  i, p, lp;
    bool t;

    lp = 0;
    p = 2;

    while (lp < n){
        t = true;
        for (i = 2; i < p; i++)
            if (p % i == 0){
                t = false;
                break;
            }

        if (t){
            cout<<"liczba pierwsza: " << p << " "<<endl;
            lp++;
        }
        p++;
    }

    cout << endl;


}

void fib(unsigned n) {
    unsigned long long i = 0, j = 1;
    cout << "Liczby fibbonnaciego" << endl;
    for (int k = 0; k < n; k++) {
        if (k == 0) {
            cout << "liczba fibbonacciego: " << i << " " << endl;

        }
        if (k == 1) {
            cout << "liczba fibbonacciego: " << j << " " << endl;
        }
        else {
            j += i;
            i = j - i;
            cout <<"liczba fibbonacciego: "<< j << " "<<endl;
        }
    }

}


int main()
{
    vector <thread> threads1;

    thread watek = new thread(fib, 100);
    threads1.push_back(watek);


    thread* watek2 = new thread(primeNumbers, 80000);
    threads1.push_back(watek2);

    for (vector<thread>::iterator it = threads1.begin(); it != threads1.end(); ++it) {
        (it)->join(); //tablica wskaźników na wątki, a it to wskaźnik na wskaźnik
        delete* it;
    }

    return 0;
}
