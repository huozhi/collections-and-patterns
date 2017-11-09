#include <iostream>
using namespace std;


class Singleton {
public:
    static Singleton* Instance() {
        if (_instance == NULL) {
            _instance = new Singleton;
        }
        return _instance;
    }
protected:
    Singleton() { }
private:
    static Singleton* _instance;
};

Singleton* Singleton::_instance = NULL;


int main() {
    Singleton *first = Singleton::Instance();
    Singleton *second = Singleton::Instance();
    cout << (first == second ? "equal" : "not equal") << endl;
    return 0;
}


/*

Output
equal

*/
