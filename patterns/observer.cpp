#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);


class Subject {
    vector<class ObserverBase *> views;
    int state;
public:
    Subject(): state(0) { }

    void attach(ObserverBase *obs) {
        views.push_back(obs);
    }

    void changeState(int val) {
        state = val;
        notify();
    }

    int getState() const {
        return state;
    }

    // declaration
    void notify();

};


// interface
class ObserverBase {
protected:
    Subject *model;
    string identifier;
public:
    ObserverBase(Subject *sub, string id) {
        identifier = id;
        model = sub;
        sub->attach(this);
    }

    virtual void update() = 0;
};

void Subject::notify() {
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}


class Observer: public ObserverBase {
public:
    Observer(Subject *sub, string id):
        ObserverBase(sub, id) { }
    void update() {
        cout << "Observer " << identifier;
        cout << ": Subject change state to " << model->getState() << endl;
    }
};




int main() { _
    Subject sub;
    Observer ob1(&sub, "first");
    Observer ob2(&sub, "second");

    sub.changeState(3);
    sub.changeState(4);

    return 0;
}


/**

Observer first: Subject change state to 3
Observer second: Subject change state to 3
Observer first: Subject change state to 4
Observer second: Subject change state to 4


*/
