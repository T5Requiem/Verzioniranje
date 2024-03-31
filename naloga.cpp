#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<unsigned char> &A, const char s[]) {
    ifstream input(s);
	unsigned int st;

	if (!input.is_open()) {
		return false;
	}

	while (input >> st) {
		A.push_back(static_cast<unsigned char>(st));
		while (isspace(input.peek())) input.get();
	}

	input.close();
	return true;
}

void Izpis_Stevil(const vector<unsigned char> &A) {
    ofstream output("out.txt");

	for (unsigned char ch : A) {
        output << static_cast<unsigned int>(ch) << ' ';
    }
}

void countingSort(vector<unsigned char> &A, int eksponent) {
    vector<unsigned char> output(A.size());
    vector<int> count(256, 0);

    for (int i = 0; i < A.size(); i++) {
        count[(A[i] >> eksponent) & 1]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (int i = A.size() - 1; i >= 0; i--) {
        output[count[(A[i] >> eksponent) & 1] - 1] = A[i];
        count[(A[i] >> eksponent) & 1]--;
    }

    for (int i = 0; i < A.size(); i++) {
        A[i] = output[i];
    }
}

void radixSort(vector<unsigned char> &A) {
    for (int eksponent = 0; eksponent < 8; eksponent++) {
        countingSort(A, eksponent);
    }
}

int main(int argc, const char* argv[]) {
    vector<unsigned char> A;

    if (argc < 2) return 0;
    if (!Branje_Stevil(A, argv[1])) return 0;

    radixSort(A);

    Izpis_Stevil(A);

	return 0;
}
