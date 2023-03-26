#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    //VARIAVEIS
    const int MESES_CODE = 4;
    const int CODE = 2;
    int dia, mes, ano;
    bool loop = 1;
    
    cout << "Digite o dia: ";
    cin >> dia;
    cout << "\nDigite o mes: ";
    cin >> mes;
    
    do{
        cout << "\nDigite o ano: ";
        cin >> ano;
        if (ano >= 1700 && ano <= 2099){    //Condiçao de parada
            loop = 0;                       //Dado Boleano para o laço
        }
        else{
            cout << "\nAno Invalido." << endl;       //Laço continua
        }
        //Fim
    } while (loop);
    //Imprimir na tela
    cout << dia << "/" << mes << "/" << ano << endl; 
    //VARIAVEL
    int anoFinal, ultimoDigitosDoAno;
    string primeiraLetraDoMes, nomeDoMes;

    
    anoFinal = (ano%1000) %100;     // 1. Pega os ultimos 2 digitos;
    ultimoDigitosDoAno = anoFinal;  // Guarda os ultimos 2 digitos
    anoFinal = anoFinal/4;          // 2. Dividi por 4;
    anoFinal = anoFinal + dia;      // 3. Soma com o dia do mes; 
    
    
    //LISTA DE MESES
    vector<string> numMes;
    numMes.push_back("MESES");
    numMes.push_back("JANEIRO");
    numMes.push_back("FEVEREIRO");
    numMes.push_back("MARÇO");
    numMes.push_back("ABRIL");
    numMes.push_back("MAIO");
    numMes.push_back("JUNHO");
    numMes.push_back("JULHO");
    numMes.push_back("AGOSTO");
    numMes.push_back("SETEMBRO");
    numMes.push_back("OUTUBRO");
    numMes.push_back("NOVEMBRO");
    numMes.push_back("DEZEMBRO");
    primeiraLetraDoMes = numMes[mes];
    nomeDoMes = numMes[mes];
    for(auto m : numMes){
        primeiraLetraDoMes = toupper(primeiraLetraDoMes[0]);
    }

    enum meses {PADRAO, JANEIRO = 1, FEVEREIRO = 4, MARCO = 4, 
    ABRIL = 0, MAIO = 2, JUNHO = 5, JULHO = 0, AGOSTO = 3, 
    SETEMBRO = 6, OUTUBRO = 1, NOVEMBRO = 4, DEZEMBRO = 6}; 
    meses mesCalendario;
    //4. BUSCA CODE
    if (mes > 0 && mes <= 3){
        //CODE JFM
        if (mes == 1)
        {
            mesCalendario = JANEIRO;
        }
        if (mes == 2)
        {
            mesCalendario = FEVEREIRO;
        }
        else{
            mesCalendario = MARCO;
        }
    }
    else if (mes > 3 && mes <= 6){
        // CODE AMJ
        if (mes == 4)
        {
            mesCalendario = ABRIL;
        }
        if (mes == 5)
        {
            mesCalendario = MAIO;
        }
        else{
            mesCalendario = JUNHO;
        }
    }
    else if (mes > 6 && mes <= 9){
        // CODE JAS
        if (mes == 4)
        {
            mesCalendario = JULHO;
        }
        if (mes == 5)
        {
            mesCalendario = AGOSTO;
        }
        else{
            mesCalendario = SETEMBRO;
        }
    }
    else if (mes > 9 && mes <= 12){
        //CODE OND
        if (mes == 4)
        {
            mesCalendario = OUTUBRO;
        }
        if (mes == 5)
        {
            mesCalendario = NOVEMBRO;
        }
        else{
            mesCalendario = DEZEMBRO;
        }
    }
    anoFinal = anoFinal + mesCalendario;
    
    //5. Subtrair 1 se for bissexto e mes de janeiro ou fevereiro
    if (ano % 4 == 0 && nomeDoMes == "JANEIRO" && nomeDoMes == "FEVEREIRO"){
        anoFinal = anoFinal - 1;
    }

    //6. Some zero se estiver nos anos 1900 (século 20), 6 para os anos a partir de 2000, 4 para os anos 1700 e 2 para os anos 1800.
    //variveis
    int numSoma1, numSoma2, numSoma3, resultadoFinal, semana;
    string diaDaSemana; 
    numSoma1 = 6;
    numSoma2 = 4;
    numSoma3 = 2;
    semana = 7;

    if (ano < 1800){
         anoFinal = anoFinal + numSoma2;
    }
    else if (ano < 1900) {
        anoFinal = anoFinal + numSoma3;
    }
    else if(ano >= 2000){
        anoFinal = anoFinal + numSoma1;
    }

    //7. Somar o anoFinal com o ano
    anoFinal = anoFinal + ultimoDigitosDoAno;
    resultadoFinal = anoFinal % 7;

    string diasDaSemana[semana] = {"Sábado", "Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta"};
    diaDaSemana = diasDaSemana[resultadoFinal];
    
    
    // Saída
    cout << anoFinal << "\nCODE: "<< primeiraLetraDoMes << "\nHoje é: " << diaDaSemana <<endl;

    return 0;

}