#include <fstream>
#include <vector>
using namespace std;

// Funkcija za branje števil iz datoteke in shranjevanje v vektor
// Parameter A: Referenca na vektor, kamor bodo shranjena prebrana števila
// Parameter s: Ime datoteke, iz katere se berejo števila
// Vrne: True, če je branje uspešno, sicer False
bool Branje_Stevil(vector<unsigned char> &A, const char s[]) {
    ifstream input(s); // Ustvarjanje objekta za branje iz datoteke
    unsigned int st; // Spremenljivka za shranjevanje prebranega števila

    if (!input.is_open()) { // Preveri, ali se je datoteka uspešno odprla
        return false; // V primeru neuspeha vrne False
    }

    while (input >> st) { // Bere števila iz datoteke
        A.push_back(static_cast<unsigned char>(st)); // Pretvori in doda število v vektor
        while (isspace(input.peek())) input.get(); // Preskoči presledke in nove vrstice
    }

    input.close(); // Zapre datoteko
    return true; // Vrne True, če je branje uspešno
}

// Funkcija za izpis števil iz vektorja v datoteko
// Parameter A: Konstantna referenca na vektor, iz katerega se berejo števila
void Izpis_Stevil(const vector<unsigned char> &A) {
    ofstream output("out.txt"); // Ustvari objekt za pisanje v datoteko

    for (unsigned char ch : A) { // Iterira skozi vektor števil
        output << static_cast<unsigned int>(ch) << ' '; // Pretvori in zapiše število v datoteko
    }
}

// Funkcija za izvajanje Counting Sort algoritma
// Parameter A: Vektor, ki vsebuje števila, ki jih je treba urediti
// Parameter eksponent: Eksponent, ki se uporablja pri izvajanju Counting Sort
void countingSort(vector<unsigned char> &A, int eksponent) {
    vector<unsigned char> output(A.size()); // Ustvari vektor za izhodne podatke
    vector<int> count(256, 0); // Ustvari vektor za štetje števil v določenem bitu

    for (int i = 0; i < A.size(); i++) { // Izvaja prvo fazo Counting Sort algoritma
        count[(A[i] >> eksponent) & 1]++; // Šteje števila na določenem bitu
    }

    for (int i = 1; i < 256; i++) { // Izvaja drugo fazo Counting Sort algoritma
        count[i] += count[i - 1]; // Sešteva števila iz prejšnjega koraka
    }

    for (int i = A.size() - 1; i >= 0; i--) { // Izvaja tretjo fazo Counting Sort algoritma
        output[count[(A[i] >> eksponent) & 1] - 1] = A[i]; // Razporedi števila v izhodni vektor
        count[(A[i] >> eksponent) & 1]--; // Zmanjša število v določenem bitu
    }

    for (int i = 0; i < A.size(); i++) { // Kopira urejen vektor nazaj v originalni vektor
        A[i] = output[i];
    }
}

// Funkcija za izvajanje Radix Sort algoritma
// Parameter A: Vektor, ki vsebuje števila, ki jih je treba urediti
void radixSort(vector<unsigned char> &A) {
    for (int eksponent = 0; eksponent < 8; eksponent++) { // Izvaja Radix Sort algoritem po bitih
        countingSort(A, eksponent); // Kliče funkcijo za izvajanje Counting Sort algoritma
    }
}

int main(int argc, const char* argv[]) {
    vector<unsigned char> A; // Ustvari vektor za shranjevanje števil

    if (argc < 2) return 0; // Preveri, ali je bilo podano ime datoteke
    if (!Branje_Stevil(A, argv[1])) return 0; // Prebere števila iz datoteke in jih shrani v vektor

    radixSort(A); // Izvede Radix Sort algoritem za urejanje števil v vektorju

    Izpis_Stevil(A); // Izpiše urejena števila v datoteko

    return 0;
}