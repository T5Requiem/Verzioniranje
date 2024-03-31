#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
    ofstream output("out.txt");

	for (int i = 0; i<velikost; i++)
		output << polje[i] << ' ';
}

void countingSort(unsigned char arr[], int size, int exp) {
}

void radixSort(unsigned char arr[], int size) {
}

int main(int argc, const char* argv[]) {
}
