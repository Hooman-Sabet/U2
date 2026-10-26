/****************************************/
/* Hooman Sabet*/
/* Gruppe: Mi16, Leiter: Humam Hamdan */
/* Übungsblatt: 2, Aufgabe: 1 */
/* Datum: 22.10.2026 */
/* Status: lauffähig */
/****************************************/

#include <iostream>
#include <iomanip>
using namespace std;


int main(void){
    int zahl;
    //eingabe schleife
    do{
        cout << "Eingabe einer Zahl ≥ 10: ";
        cin >> zahl;
    }while(zahl < 10);
    int umdrehen = 0;
    int stelle = 0;
    //umdrehungs schleife
    while(zahl > 0){
        umdrehen = (umdrehen * 10) + (zahl%10);
        zahl/= 10;
        stelle++;
    }
    //usgabe
    cout << "umgedrehte Zahl: " << setfill('0') << setw(stelle) << umdrehen <<endl;
}


//Das programm funktioniert schon wie erwartet und die ausgaben sind auch als einen screen shot auf dem aufgabe folder
// zur verfügung, die eingaben sind die gleichen wie im uebungsblatt schon gekommen und meine ergebnisse sind auch 
//die gleiche wie erwartet bis zur formatierung.