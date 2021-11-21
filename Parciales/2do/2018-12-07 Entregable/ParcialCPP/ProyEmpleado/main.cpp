#include "Empleado.h"
#include "Persona.h"

using namespace std;

int main()
{
    Empleado e1;
    Empleado e2(e1);
    Persona p1(35674325,"Federico",'M'), p2(p1);
    Empleado e3(1000,"Obrero",p1);
    Empleado e4;
    cout<<"EMPLEADO 1"<<endl<<e1<<endl<<endl; ///debe mostrar vacio
    cout<<"EMPLEADO 2"<<endl<<e2<<endl<<endl;
    cout<<"EMPLEADO 3"<<endl<<e3<<endl<<endl;
    e2=e3;
    cout<<"EMPLEADO 2"<<endl<<e2<<endl<<endl;
    cin>>e4;
    cout<<"EMPLEADO 4"<<endl<<e4<<endl<<endl;
    if(p2==p1)
        e3=e3+1000;
    cout<<e3;
    return 0;
}
