#include <iostream>
#include <string>
#include "LightSaber.h"
// #include "Arduino.h" 


#include "KyloRenSaber.h"
// KyloRenSaber kyloSaber(10);


using namespace std;

int main()
{
    cout<<"Hello World"<<endl;

    LightSaber l1= LightSaber();
    KyloRenSaber k1= KyloRenSaber();
    KyloRenSaber k2= KyloRenSaber(true,255,0,0);
    l1.display();
    k2.display();
    return 0;
}
