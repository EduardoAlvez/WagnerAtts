// Mistura de palavras
// O clássico jogo de palavras cruzadas onde o jogador pode pedir uma dica

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORLDS = 5;
    const string WORDS [NUM_WORLDS] [NUM_FIELDS] = {

        {"parede", "Você sentiu que está batendo a cabeça em alguma coisa?"},
        {"óculos", "Estes podem ajudá-lo a ver a resposta."},
        {"trabalhou", "Indo devagar, não é?"},
        {"persistente", "Mantenha-se firme."},
        {"confusão", "É disso que se trata o jogo."}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORLDS);
    string theWord = WORDS[choice][WORD]; // palavra para adivinhar
    string theHint = WORDS[choice][HINT]; // dica para palavra

    string jumble = theWord; //versão confusa da palavra
    int length = jumble.size();
    for (int i = 0; i < length; i++){
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "\t\tBem-vindo ao Word Jumble!\n\n";
    cout << "Desembaralhe as letras para formar uma palavra.\n";
    cout << "Digite 'hint' para uma dica.\n";
    cout << "Digite 'quit' para sair do jogo.\n\n";
    cout << "A bagunça é: " << jumble;

    string guess;
    cout << "\n\nSeu palpite: ";
    cin >> guess;

    while ((guess != theWord) && (guess != "quit")){
        
        if (guess == "hint"){
            cout << theHint;
        }
        else{
            cout << "Desculpe, não é isso.";
        }
        cout << "\n\nSeu palpite: ";
        cin >> guess;
    }
    
    if (guess == theWord){
        cout << "\nÉ isso! Você adivinhou!\n";
    }
    cout << "\nObrigado por jogar.\n";

    return 0 ;
}