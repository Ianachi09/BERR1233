#include <iostream>
using namespace std;

int main()
{
    int ops;
    cout << "Enter your operation :" << endl;
    cout << "'0' : Accending" << endl;
    cout << "'1' : Decending" << endl;
    cout << "'3' : Even" << endl;
    cout << "'4' : Odd" << endl;
    cin >> ops;
    
    switch (ops)
    {
        case 0 :
            for (int i=0; i<=50; i++) {
                cout << i << "\t";
            }
        break;
    
        case 1 :
            for (int i=50; i>=0; i--) {
              cout << i << "\t";
            }
        break;

        case 3 :
            for (int i=0; i<=50; i+=2) {
              cout << i << "\t";
            }
        break;
        case 4 :
            for (int i=0; i<=50; i+=1) {
              cout << i << "\t";
            }
        break;

        default:
            cout << "Invalid Operation" << endl;
        break;
    }

return 0;
}
