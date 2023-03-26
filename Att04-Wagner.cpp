// Forca
// O clássico jogo da forca

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main() {

    // set-up
    const int MAX_WRONG = 8; // número máximo de palpites incorretos permitidos

    vector<string> words; // seleção de possíveis palavras de adivinhação
    words.push_back("ADVINHE");
    words.push_back("FORCA");
    words.push_back("DIFICIL");
    words.push_back("POESIA");
    words.push_back("HISTORIA");
    words.push_back("JAVA");
    words.push_back("SUPERIOR");
    words.push_back("LULA");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];           // palavra para adivinhar
    int wrong = 0;                              // número de palpites incorretos
    string soFar(THE_WORD.size(), '-');         // palavra adivinhada até agora
    string used = "";                           // Palavras já adivinhadas

    cout << "Bem-vindo ao Hangman. Boa sorte\n";
    
    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)){

        cout << "\n\nVoce Tem " << (MAX_WRONG - wrong);
        cout << " palpites incorretos restante.\n";
        cout << "\nVocê usou as seguintes letras: \n" << used << endl;
        cout << "\nAté agora, a palavra é:\n" << soFar << endl;

        char guess;
        cout << "\n\nDigite seu palpite: ";
        cin >> guess;
        guess = toupper(guess); //make uppercase since secret word in uppercase
        while (used.find(guess) != string::npos){

            cout << "\nVocê já adivinhou " << guess << endl;
            cout << "Digite seu palpite: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos){

            cout << "Isso mesmo! " << guess << " está na palavra.\n";

            //update soFar to include newly guessed letter
            for (unsigned int i = 0; i < THE_WORD.length(); i++){

                if(THE_WORD[i] == guess){
                    
                    soFar[i] = guess;
                }
            }
        }
        else{
            cout << "Desculpa, " << guess << " não está na palavra.\n";
            ++wrong;
        }
    }

    // shut down
    if (wrong == MAX_WRONG){
        cout << "\nVocê foi enforcado!";
    }
    else{
        cout << "\nVocê adivinhou!";
    }
    cout << "\nA palavra era " << THE_WORD << endl;

    return 0;
}