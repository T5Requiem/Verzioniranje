#include <fstream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<unsigned char> &vec, const char s[]) {
    ifstream input(s);
	unsigned int st;

	if (!input.is_open()) {
		return false;
	}

	while (input >> st) {
		vec.push_back(static_cast<unsigned char>(st));
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(const vector<unsigned char> &vec) {
    ofstream output("out.txt");

	for (unsigned char ch : vec) {
        output << static_cast<unsigned int>(ch) << ' ';
    }
}

void countingSort(vector<unsigned char>& A, int eksponent) {
    
}

void radixSort(unsigned char A[], int velikost) {
}

int main(int argc, const char* argv[]) {
    
}
