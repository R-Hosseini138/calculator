#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
#include <vector>

using namespace std;

vector<string> history; 
void load() {
    system("cls");
    cout << "LOADING..." << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 80; j++) {
            cout << "_";
        }
        cout << endl;
    }
    system("cls");
}

void displayMainMenu() {
    cout << "\n\n\t CALCULATOR" << endl;
    cout << " ----------------------------------------" << endl;
    cout << " \n A --> LINEAR EQUATION" << endl;
    cout << " B --> QUADRATIC EQUATION" << endl;
    cout << " C --> CUBIC EQUATION" << endl;
    cout << " D --> EXPONENTIAL FUNCTION" << endl;
    cout << " E --> LOGARITHMIC FUNCTION" << endl;
    cout << " F --> TRIGONOMETRIC FUNCTIONS" << endl;
    cout << " G --> VIEW HISTORY" << endl;
    cout << " H --> DELETE EXISTING DATA" << endl;
    cout << " R --> READ-ME" << endl;
    cout << " X --> Exit" << endl;
}
void solveLinearEquation() {
    float a, b;

    cout << "LINEAR EQUATION (y = ax + b)\n";
    cout << "Enter coefficient of 'x' (a): ";
    cin >> a;
    cout << "Enter constant term (b): ";
    cin >> b;

    string equation = "y = " + to_string(a) + "(x) + " + to_string(b);
    history.push_back(equation); 
    cout << "\nYour Equation: " << equation << endl;
}

void solveQuadraticEquation() {
    float a, b, c, discriminant, root1, root2;

    cout << "QUADRATIC EQUATION (ax^2 + bx + c = 0)\n";
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter constant c: ";
    cin >> c;

    discriminant = b * b - 4 * a * c;

    string equation = to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c) + " = 0";
    history.push_back(equation); 

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different:\n";
        cout << "Root 1: " << root1 << "\nRoot 2: " << root2 << endl;
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        cout << "Roots are real and the same:\n";
        cout << "Root: " << root1 << endl;
    } else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex:\n";
        cout << "Root 1: " << realPart << " + " << imaginaryPart << "i\n";
        cout << "Root 2: " << realPart << " - " << imaginaryPart << "i\n";
    }
}

void solveCubicEquation() {
    float a, b, c, d;

    cout << "CUBIC EQUATION (ax^3 + bx^2 + cx + d = 0)\n";
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;
    cout << "Enter constant d: ";
    cin >> d;

    string equation = to_string(a) + "x^3 + " + to_string(b) + "x^2 + " + to_string(c) + "x + " + to_string(d) + " = 0";
    history.push_back(equation); 
    
    float f = ((3 * c / a) - ((b * b) / (a * a))) / 3;
    float g = ((2 * b * b * b) / (a * a * a) - (9 * b * c) / (a * a) + (27 * d / a)) / 27;
    
    float h = (g * g / 4) + (f * f * f / 27);

    if (h > 0) {
        float r = -(g / 2) + sqrt(h);
        r = pow(r, (1.0/3.0));
        float s = -(g / 2) - sqrt(h);
        s = pow(s, (1.0/3.0));
        
        float root1 = (r + s) - (b / (3 * a));
        cout << "One real root: x = " << root1 << endl;

    } else {


float realPart = -(g / 2);
        float imaginaryPart = sqrt(-h);
        
        cout << "Complex roots exist.\n";
        cout << "Root 1: " << realPart << " + " << imaginaryPart << "i\n";
        cout << "Root 2: " << realPart << " - " << imaginaryPart << "i\n";
    }
}

void solveExponentialFunction() {
    double base, exponent;

    cout << "EXPONENTIAL FUNCTION (y = a^x)\n";
    cout << "Enter base (a): ";
    cin >> base;
    cout << "Enter exponent (x): ";
    cin >> exponent;

    double result = pow(base, exponent);
    
    string equation = to_string(base) + "^" + to_string(exponent);
    history.push_back(equation); 

    cout << "\nResult: y = " << result << endl;
}

void solveLogarithmicFunction() {
    double value, base;

    cout << "LOGARITHMIC FUNCTION (y = log_a(b))\n";
    cout << "Enter value (b): ";
    cin >> value;
    cout << "Enter base (a): ";
    cin >> base;

    if (value <= 0 || base <= 0 || base == 1) {
        cout << "Invalid input for logarithm." << endl;
        return;
    }

    double result = log(value) / log(base);
    
    string equation = "log_" + to_string(base) + "(" + to_string(value) + ")";
    history.push_back(equation);

    cout << "\nResult: y = " << result << endl;
}

void solveTrigonometricFunctions() {
    double angle;

    cout << "TRIGONOMETRIC FUNCTIONS\n";
    cout << "Enter angle in degrees: ";
    cin >> angle;

    double radians = angle * M_PI / 180.0; 

    double sinValue = sin(radians);
    double cosValue = cos(radians);
    double tanValue = tan(radians);

    string equationSin = "sin(" + to_string(angle) + ")";
    string equationCos = "cos(" + to_string(angle) + ")";
    string equationTan = "tan(" + to_string(angle) + ")";
    
    history.push_back(equationSin); 
    history.push_back(equationCos); 
    history.push_back(equationTan); 

    cout << "\nResults:\n";
    cout << equationSin + ": y = " << sinValue << endl;
    cout << equationCos + ": y = " << cosValue << endl;
    
     if(cosValue != 0){
         cout<< equationTan + ": y = "<< tanValue<< endl;
     }else{
         cout<< equationTan + ": Undefined (division by zero)"<<endl;
     }
}

void viewHistory() {
    if (history.empty()) {
        cout << "\nNo calculations in history.\n";
        return;
    }

    cout << "\nHISTORY OF CALCULATIONS:\n";
    
    for (size_t i = 0; i < history.size(); ++i) {
        cout << i + 1 << ". " << history[i] << endl;
    }
}

void deleteExistingData() {
   history.clear(); 
   cout<< "\nExisting data deleted successfully.\n";
}

void readMe() {
   system("cls");
   cout<< "\nREAD-ME\n";
   cout<< "This program allows you to solve linear, quadratic, cubic equations,\n";
   cout<< "as well as exponential, logarithmic, and trigonometric functions.\n";
}

int main() {
   load();

   char option;

   while (true) { 
       displayMainMenu(); 

       cout<< "\nEnter your choice: ";
       cin>> option;

       switch(option) {
           case 'A':
           case 'a':
               solveLinearEquation();
               break;

           case 'B':
           case 'b':
               solveQuadraticEquation();
               break;

           case 'C':
           case 'c':
               solveCubicEquation();
               break;

           case 'D':
           case 'd':
               solveExponentialFunction();
               break;

           case 'E':
           case 'e':
               solveLogarithmicFunction();
               break;

           case 'F':
           case 'f':
               solveTrigonometricFunctions();
               break;

           case 'G':
           case 'g':
               viewHistory();
               break;

           case 'H':

           case 'h':
               deleteExistingData();
               break;

           case 'R':
           case 'r':
               readMe();
               break;

           case 'X':
           case 'x':
               return 0;

           default:
               cout<< "\nInvalid option! Please try again."<< endl;
               break;
       }

       cout<< "\nPress any key to return to the main menu...";
       cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
       cin.get(); 
       system("cls"); 
   }

   return 0;
}