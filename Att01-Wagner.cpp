#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    const int GOLD_PIECES = 900;
    int adventurers, killed, survivors;
    string leader;

    //pega a informação
    cout << "Bem-vindo a fortuna Perdida\n\n";
    cout << "Por favor, informe o sequinte para sua aventura personalizada\n";

    cout << "Digite um Número: ";
    cin >> adventurers;

    cout << "Digite Ooutro Numero, menor que o primeiro: ";
    cin >> killed;

    survivors = adventurers - killed;

    cout << "Digite seu Sobrenome: ";
    cin >> leader;

    //Começo da estoria
    cout << "\nUm grupo corajoso de " << adventurers << " sairam em uma jornada ";
    cout << "-- em busca o tesouro perdido dos Antigos Anões. ";
    cout << "O grupo era liderado pelos famoso ladino, " << leader << ".\n";

    cout << "\nDurante o trajeto, um bandi de Ogros Saqueadores emboscaram o grupo. ";
    cout << "Todos lutaram bravamente sob o comando de " << leader;
    cout << ", e os ogros foram derrotados, mas a um custo. ";
    cout << "Dos aventureiros, " << killed << "foram derrotados, ";
    cout << "deixando apenas " << survivors << " no grupo.\n";

    cout << "\n O bando estava preste a abandonar todas as esperanças. ";
    cout << "Mas enquanto escavavam os túmulos para os amigos, ";
    cout << "eles encontraram um tesouro enterrado. ";
    cout << "Entao os aventureiro dividiram " << GOLD_PIECES << " Moedas de Ouro. ";
    cout << leader << " ficou com a sobra de " << (GOLD_PIECES % survivors);
    cout << " moedas para manter tudo justo.\n";

    return 0;

}
