/****************************************/
/* Hooman Sabet*/
/* Datum: 26.10.2026 */
/* Status: lauffähig */
/****************************************/


//erst ueberpruefen ob n%2 == 1, wenn nicht wiederholen wir die eingabe text
//als n eingegeben und bestaetigt wird :
//erstellen wird einen n*n feld und füllen wir das mit nullen auf
// erst mal 1 in n/2 +1 einfügen 
//dann periodisch feld(i,j) für i und j == i und j von 1, mit zahlen ab 1 eintragen 
//dann mussen wir in jeder i++ oder j++ auch %n rechnen damit die indize nicht ausserhalb unser matrizt kommen 
// falls feld(ineu , jneu ) != 0 -> j+=2

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;



void schreib(vector<vector<int>>& feld, int n){
    int i = (n/2) + 1;
    int j = (n/2);
    int zahl = 1;
    int full = n*n;
    feld [i][j] = zahl;
    while(zahl < full){
        int i_neu = (i+1)%n;
        int j_neu = (j+1)%n;
        if(feld[i_neu][j_neu] == 0){
            i = i_neu;
            j = j_neu;
            ++zahl;
            feld[i][j] = zahl;
        }
        else if(feld[i_neu][j_neu] != 0){
            i = (i_neu + 1)%n;
            ++zahl;
            feld[i][j] = zahl;
        }
    }   
}

void ausgabe(vector<vector<int>> feld, int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << setw(4) << feld[i][j];
        }
        cout << "\n";
    }
}


int main(void){
        int n;
    //bekomme ich hier einen n als eingabe einen ungeraden zahl und das läuft solang bis ein erlaubten zahl eingegeben wird;
    do{
        cout<< "Bitte geben Sie eine ungerade Zahl ein: ";
        cin >> n;
        if((n%2) == 1){
            break;
        }
    }while((n%2) != 1);
    //deklarieren wir einen vektor von vektoren mit integer werte was einen 2 dim dynamisches array entscpriecht und damit 
    //kann ich einen array nxn habe, was im laufzeit deklariert wird.
    vector<vector<int>> feld(n, vector<int>(n, 0));

    schreib(feld, n);
    ausgabe(feld, n);
}
   //Das programm funktioniert wie erwartet und das Ausgabe referenz liegt auch auf dem folder um zu sehen.