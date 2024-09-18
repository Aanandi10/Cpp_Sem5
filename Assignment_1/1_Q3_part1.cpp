#include <iostream>
using namespace std;

int main() {
    char vowel1='a',vowel2='e',vowel3='i',vowel4='o',vowel5='u';
    char capVowel1='A',capVowel2='E',capVowel3='I',capVowel4='O',capVowel5='U';
    int v21 = vowel2-vowel1, v52 = vowel5-vowel2, cv21 = capVowel2-capVowel1;
    cout << "vowel2-vowel1 : " << v21 << endl;
    cout << "vowel5-vowel2 : " << v52 << endl;
    cout << "capVowel2-capVowel1 : " << cv21 << endl;
    return 0;
}
