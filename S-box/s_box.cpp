#include <bits/stdc++.h>
using namespace std;

int E[] = {
					32, 1 , 2 , 3 , 4 , 5 ,
					4 , 5 , 6 , 7 , 8 , 9 ,
					8 , 9 , 10, 11, 12, 13,
					12, 13, 14, 15, 16, 17,
					16, 17, 18, 19, 20, 21,
					20, 21, 22, 23, 24, 25,
					24, 25, 26, 27, 28, 29,
					28, 29, 30, 31, 32, 1 };
					
string expansionPermute(string input)
{
	string res = "";
	for(int i=0; i<48; i++)
	{
		res += input[E[i]-1];
	}
	return res;
}

string XOR(string input1, string input2)
{
	string res = "";
	for(int i=0; i<input1.length(); i++)
	{
		res += (input1[i] == input2[i]) ? "0" : "1";
	}
	return res;
}

int main()
{
	int i;
	unsigned long long hexInput;
	string Ki;
	ifstream fin;
	
	cout << "\nEnter Round number (i) : ";
	cin >> i;
	
	cout << "Enter 64-bit (i-1)th round output in hex: " ;
	cin >> hex >> hexInput;
	string input = bitset<64>(hexInput).to_string();
	
	fin.open("keygen.txt");
	for(int j=1; j<=i; j++)
	{
		fin >> Ki;
	}
	
	if(Ki.length() == 0)
	{
		cout << "\nkeygen.txt not found !!! \n" << endl;
		exit(1);
	}
	
	cout << "\n64-bit Binary Input = " << input << endl ;
	cout << "key for ith round (Ki) = " << Ki << endl ;
	
	string Ri_1 = input.substr(32,32); // 32 bit Right half of input R[i-1]
	cout << "\nRight half of 64-bit input, Ri_1 = " << Ri_1 << endl;
	
	string R48 = expansionPermute(Ri_1);
	cout << "Ri_1 after expansion permutation = " << R48 << endl;
	
	string sBoxInput = XOR(R48, Ki);
	cout << "\nInput to s-box : " << sBoxInput << endl << endl;
	
	return 0;
}

/******************************* Output-1 ******************************************
Enter Round number (i) : 1
Enter 64-bit (i-1)th round output in hex: cc00ccfff0aaf0aa
64-bit Binary Input = 1100110000000000110011001111111111110000101010101111000010101010
key for ith round (Ki) = 000110110000001011101111111111000111000001110010
Right half of 64-bit input, Ri_1 = 11110000101010101111000010101010
Ri_1 after expansion permutation = 011110100001010101010101011110100001010101010101
Input to s-box : 011000010001011110111010100001100110010100100111

O/P:

000110110000001011101111111111000111000001110010
011110011010111011011001110110111100100111100101
010101011111110010001010010000101100111110011001
011100101010110111010110110110110011010100011101
011111001110110000000111111010110101001110101000
011000111010010100111110010100000111101100101111
111011001000010010110111111101100001100010111100
111101111000101000111010110000010011101111111011
111000001101101111101011111011011110011110000001
101100011111001101000111101110100100011001001111
001000010101111111010011110111101101001110000110
011101010111000111110101100101000110011111101001
100101111100010111010001111110101011101001000001
010111110100001110110111111100101110011100111010
101111111001000110001101001111010011111100001010
110010110011110110001011000011100001011111110101


************************************************************************************/



