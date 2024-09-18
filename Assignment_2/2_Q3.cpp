#include <iostream>
using namespace std;

int globalcallcount = 0;

void countfuncglobal(){
    globalcallcount++;
    cout<<"Global: I have been called "<< globalcallcount<<" times" <<endl;
}

void countfuncstatic(){
    static int staticcallcount = 0;
    staticcallcount++;
    cout<<"static: I have been called "<<staticcallcount<<" times"<<endl;

}

int main(){
    cout<<"Calling Global Count Function"<<endl;
    for (int i=0; i<10;i++){
        countfuncglobal();
    }

    cout<<"Calling Global Count Function"<<endl;
    for (int i=0; i<10;i++){
        countfuncstatic();
    }

    return 0;
}

/* Using a local static variable is generally more appropiate. It limits the scope of the
variable to the function, avoiding unintended side effects elsewhere in the code. It also
makes the function more self-contained and easier to manage.*/

/*A regilar local variable is reinitialized every time the function is called. This means
that it won't be able to keep track of how many times the function has been called because
it would reset to its initial value on each function call.*/