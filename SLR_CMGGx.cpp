#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>   
#include <cstdlib> 

using namespace std;

double calculateSum(const vector<double>& values) {
    return accumulate(values.begin(), values.end(), 0.0);
}

double calculateSumOfSquares(const vector<double>& values) {
    double sum = 0;
    for (double value : values) {
        sum += pow(value, 2);
    }
    return sum;
}

double calculateSumOfProducts(const vector<double>& x, const vector<double>& y) {
    double sum = 0;
    for (size_t i = 0; i < x.size(); i++) {
        sum += x[i] * y[i];
    }
    return sum;
}

int main() {
    int n;
    cout << "Ingrese el número de valores:\n";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Ingrese los valores de X:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Ingrese los valores de Y:\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double sumX = calculateSum(x);
    double sumY = calculateSum(y);
    double sumX2 = calculateSumOfSquares(x);
    double sumXY = calculateSumOfProducts(x, y);
    
    double sumaXY = sumX * sumY;
    double sumaX2 = sumX * sumX;

   
    double denominator = n*sumaX2 - pow(sumX, 2);
    if (denominator == 0) {
        cerr << "Error: el denominador es cero. No se puede calcular B0 y B1.\n";
        return 1;
    }
    double B0 = ((sumaX2 * sumY) - (sumX * sumaXY) / denominator);
    double B1 = ((n*sumaXY) - (sumX * sumY) / denominator);

    
    double yn = B0 + B1 * x[1];
    
    cout << "\nResultado de la regresión:\n";
    cout << "B0 = " << B0 << "\n";
    cout << "B1 = " << B1 << "\n";
    cout << "y = " << yn << "\n";
    cout << "\nVALORES:\n";
    cout << "SUMX = " << sumX << "\n";
    cout << "SUMY = " << sumY << "\n";
    cout << "SUMXY = " << sumaXY << "\n";
    cout << "SUMX2 = " << sumaX2 << "\n";
    cout << "DENOMINATOR = " << denominator << "\n";
    cout << "x1 = " << x[0] << "\n";

    return 0;
}