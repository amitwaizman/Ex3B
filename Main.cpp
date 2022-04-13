
#include "sources/Matrix.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <stdexcept>
using namespace std;
using namespace zich;
int main() {
    Matrix a;
    Matrix b;
    string o;
    double d;
    bool ans;
    bool temp= true;
    try {
            cout << "Please insert mat1"<<endl;
            cin >> a;
            cout << "Please insert mat2"<<endl;
            cin >> b;
        while (true) {
            cout << "Please insert operator" << std::endl;
            cin >> o;
            ///+
            if (o == "+") {
                cout << a+b << std::endl;
            } else if (o == "+=") {
                a += b;
                cout << a << std::endl;
            } else if (o == "+a") {
                cout << +a << endl;
            }
                ///-
            else if (o == "-") {
                cout << a + b << std::endl;
            } else if (o == "-=") {
                a += b;
                cout << a << std::endl;
            } else if (o == "-a") {
                cout << +a << endl;
            }
                ///>
            else if (o == ">") {
                bool bo = a > b;
                cout << bo << std::endl;
            } else if (o == ">=") {
                bool bo = a >= b;
                cout << bo << std::endl;
            } else if (o == "<") {
                bool bo = a < b;
                cout << bo << std::endl;
            } else if (o == "<=") {
                bool bo = a <= b;
                cout << bo << std::endl;
            } else if (o == "==") {
                bool bo = a == b;
                cout << bo << std::endl;
            } else if (o == "!=") {
                bool bo = a != b;
                cout << bo << std::endl;
            }



///*
            else if (o == "*") {
                cout << a * b << std::endl;
            } else if (o == "n*a") {
                cout << "Please insert number" << std::endl;
                cin >> d;
                cout << d * a << std::endl;
            } else if (o == "*=") {
                a *= b;
                cout << a << endl;
            } else if (o == "*=n") {
                cout << "Please insert number" << std::endl;
                cin >> d;
                a *= d;
                cout << a << endl;
            } else if (o == "*n") {
                cout << "Please insert number" << std::endl;
                cin >> d;
                cout << a * d << std::endl;
            } else if (o == "a++") {
                cout << a++ << std::endl;
            } else if (o == "a--") {
                cout << a-- << std::endl;
            } else if (o == "++a") {
                cout << ++a << std::endl;
            } else if (o == "--a") {
                cout << --a << std::endl;
            }

        }
    } catch (std::out_of_range ex) {
        cout << ex.what()  << endl;
    }
    return 0;
}
