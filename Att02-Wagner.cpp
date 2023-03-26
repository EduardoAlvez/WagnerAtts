// Advinhe meu Número
// O jogo classico de advinha numeros

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {

    srand(static_cast<unsigned int>(time(0))); //Gerado de numero aleatório

    int secretNumber = rand() % 100 + 1; //Número aleatório entre 1 e 100
    int tries = 0;
    int guess;

    cout << "\tBem-vindo a Advinhe meu Numero\n\n";

    do{

        cout << "Digite um palpite: ";
        cin >> guess;
        ++tries;

        if (guess > secretNumber){
            cout << "Muito Alto!\n\n";
        }
        else if (guess < secretNumber){
            cout << "Muito Baixo!\n\n";
        }
        else{
            cout << "\nÉ isso! você conseguiu" << tries << " Palpites!\n";
        }
    }while (guess != secretNumber);
    
    return 0;
}