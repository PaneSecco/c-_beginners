// c++_beginners.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
using namespace std;

int num[100];
int posto = 0;
int tentativi = 0;

void risciacquo(int usato) {

    tentativi++;

    bool aggiungere = true;
    for (int a = 0; a < posto; a++) {
        if (num[a]==usato) {
            aggiungere = false;
        }
    }

    if (aggiungere == true) {
        num[posto] = usato;
        posto++;
    }

    int temp;
    for (int u = 0; u < posto - 1; u++) {
        for (int i = 0; i < posto - 1; i++) {
            if (num[i] > num[i + 1]) {
                temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;
            }
        }
    }

    system("cls");

    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    cout << "Inserisci un numero da 1 a 15 (compresi gli estremi) e cerca di indovinarlo con il minor numero di prove possibile.\n";
    cout << "Inserire ed inviare un numero per iniziare...\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    cout << "Numeri usati:\n";
    
    for (int a = 0; a < posto; a++) {
        cout << num[a] << " ";
    }

    cout << "\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
   
    cout << "Tentativi:" << tentativi << "\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";

}

void indovina() {

    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    cout << "Inserisci un numero da 1 a 15 (compresi gli estremi) e cerca di indovinarlo con il minor numero di prove possibile.\n";
    cout << "Inserire ed inviare un numero per iniziare...\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";

    srand(unsigned(time(NULL)));
    int randomico = rand() % 15 + 1;
    int input = -1;
    cin >> input;

    while (input != randomico) {
        risciacquo(input);
        cout << "Non e' il numero giusto\n";
        cin >> input;
    }
    cout << "E' il numero giusto\n";
    return;
}

int main()
{
    indovina();
}



// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
