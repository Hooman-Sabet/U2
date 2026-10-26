/****************************************/
/* Hooman Sabet*/
/* Datum: 26.10.2026 */
/* Status: lauffähig */
/****************************************/



#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <numeric>
using namespace std;
// das function laenge berechnet die abstand zwei punkte
double laenge(double x_1, double y_1, double x_2, double y_2);
//ellipse berechnet die n verschiedene coordinaten auf einen a * b ellipse
//umd dann die abstaende zu berechnen und einen approximation für die umfang zu finden
void ellipse(double a, double b, double t, double& x, double& y);
//umfang ist wie einen wraparounf function was alle functionen zusammen verbindet und das end produkt mittel addieren fkt berechnet
double umfang(double a, double b, int n);
double addieren(const vector<double>& werte);

double laenge(double x_1, double y_1, double x_2, double y_2){
    double lg = sqrt(pow(x_1 - x_2, 2.0) + pow(y_1 - y_2, 2.0));
    return lg;
}
//berechnet für jeder interval aufteilung, der neuer punkt auf die ellipse
void ellipse(double a, double b, double t, double& x, double& y){
    x = a*cos(t);
    y = b*sin(t);
}
//addiert die summe aller werte um den umfangzu berechnen 
double addieren(const vector<double>& werte){
    double sum = accumulate(werte.begin(), werte.end(), 0.0);
    return sum;
}

double umfang(double a, double b, int n){
    vector<double> werte(n, 0);
    vector<vector<double>> coor(n, vector<double>(2, 0));
    const double PI = std::acos(-1.0);
    for (int i = 0; i < n; ++i) {
        double t = i * 2 * PI / n;
        ellipse(a, b, t, coor[i][0], coor[i][1]);
    } 

    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        werte[i] = laenge(coor[i][0], coor[i][1], coor[next][0], coor[next][1]);
    }
    double sum = addieren(werte);
    return sum;
}

int main(void){
    int a;
    int b;
    cout << "Bitte die Halbachse a eingeben: ";
    cin >> a;
    cout << "Bitte die Halbachse b eingeben: ";
    cin >> b;
    double umf = umfang(a, b , pow(2, 24));
    cout << setprecision(10) << umf;
}


//Das endergebnis für a = 5 und b = 6 ist berechnet und als referenz liegt in das folder mit das berechnete antwort von claud was die gleiche zahlen sind.

