/* NELSON MOSQUERA
RICHARD FONSECA*/
#include <iostream>
#include <cstdlib>
#include <iomanip>



using namespace std;

#define maxcalle 100
#define maxcarrera 100
#define maxcanti 1000
#define maxcuad 5
#define maxauto 5
#define maxvan 10

const char cuadro = 219;

struct datos
{
    int contador;
    string placa;
    char vehiculo;//a o v
    int puestos;
    bool disponible;
    bool activo;
    char estado; // L o O
    int calle;
    int carrera;
    int suma; // variable que ayuda a saber cual taxi esta mas cerca
    bool posible;// sirve para en la funcion 5 saber cuales taxis pueden llevar al pasajero
    bool encontrado; // sirve para saber que taxi es el que va a llevar al pasajero

};
void delay(unsigned int mseconds);
void leer_taxi(datos taxi[],int canti, int canti_calle, int canti_carrera);
void imprimir_datos(datos taxi[],int canti);
void extraer (datos taxi[],int canti, int canti_calle, int canti_carrera);
void inactivar (datos taxi[], int canti);
void libre (datos taxi[], int canti, int canti_calle, int canti_carrera);
void mapa_ciudad (datos taxi[], int canti, int canti_calle, int canti_carrera);
void mover_taxi(datos taxi[], int canti, int canti_calle, int canti_carrera);
void datos_por_placa(datos taxi[],int canti);
void disponible(datos taxi[],int canti);
void pedir_taxi(datos taxi[], int canti, int canti_calle, int canti_carrera);

int main()
{
    datos taxi[maxcanti];
    bool bandera = true;
    int opcion = 0, canti = 0/*cantidad de taxis*/, canti_calle=0, canti_carrera=0;
    string mapa[maxcarrera][maxcalle];

    system("color f0");
    system ("cls");
    system("mode con: cols=70 lines=30");
    do
    {
        cout <<"0. INTRODUCIR DATOS POR PRIMERA VEZ. "<< endl
             <<" LEER Y ALMACENAR DATOS " << endl
             <<"DE LOS TAXIS DE LA CIUDAD (En forma masiva). "<< endl
             <<"1. LISTAR TODOS LOS DATOS BASICOS DE LOS TAXIS "<<endl
             <<"2. MOSTRAR EL PLANO DE LA CIUDAD, INDICANDO LOS TAXIS " << endl
             <<"DISPONIBLES EN CADA CUADRANTE "<<endl
             <<"3. INACTIVAR UN TAXI"<< endl
             <<"4. ACTIVAR COMO LIBRE UN TAXI EN UN CUADRANTE"<< endl
             <<"5. SOLICITAR UN SERVICIO DE TAXI"<< endl
             <<"6. EXTRAER LOS DATOS COMPLETOS DE UN TAXI DADO (por placa)"<< endl
             <<"7. EXTRAER LOS DATOS DE UN CUADRANTE DADO"<< endl
             <<"8. MOVER UN TAXI DE UN CUADRANTE A OTRO"<< endl
             <<"9. SALIR DEL PROGRAMA" << endl;
        cout << "que opcion desea escoger? " << endl;
        cin>> opcion;
        while(opcion < 0 || opcion > 9)
        {

            system("color f4");
            cout << "opcion invalida, vuelva a intentar"<<endl;
            cout << "que opcion desea escoger? " << endl;
            cin>> opcion;
        }
        system("color f0");
        while(bandera && opcion != 0 && opcion != 9)
        {
            system("color f4");
            cout <<"Primero se debe introducir los datos por primera vez"<<endl
                 << "intente con la opcion 0" << endl;
            cin >> opcion;
        }
        system("color f0");
        while (bandera == false && opcion == 0)
        {
            system("color f4");
            cout << "la opcion 0 solo se puede escoger una vez" << endl
                 << "intente con otra opcion "<<endl;
            cin >> opcion;

        }
        system("color f0");
        switch (opcion)
        {
        case 0:
        {
            system("cls");
            cout << "porfavor dijite el numero  de carreras " << endl;
            cin>> canti_carrera;
            while (canti_carrera < 0)
            {
                system("color f4");
                cout << "respuesta invalida" << endl;
                cout << "porfavor dijite el numero maximo de caarreras"<<endl;
                cin >> canti_carrera;
            }
            cout << "porfavor dijite el numero maximo de calles "<<endl;
            cin >> canti_calle;
            while(canti_calle <0 )
            {
                system("color f4");
                cout << "respuesta invalida" << endl;
                cout << "porfavor dijite el numero maximo de calles "<<endl;
                cin >> canti_calle;

            }
            system("color f0");
            cout << "porfavor ingerese la cantidad de taxistas" << endl;
            cin >> canti;
            while (canti <= 0)
            {
                system("color f4");
                cout << "respuesta invalida" << endl;
                cout << "porfavor ingerese la cantidad de taxistas" << endl;
                cin >> canti;
            }
            leer_taxi(taxi,canti,canti_calle,canti_carrera);
            bandera=false;
            system("mode con: cols=70 lines=30");
            break;
        }
        case 1:
        {
            system("mode con: cols=50 lines=100");
            imprimir_datos(taxi,canti);
            system("pause");
            system("cls");
            system("mode con: cols=70 lines=30");
            break;
        }
        case 2:
        {
            system("mode con: cols=200 lines=200");
            mapa_ciudad (taxi,canti,canti_calle,canti_carrera);
            system("pause");
            system("cls");
            system("mode con: cols=70 lines=30");
            break;
        }
        case 3:
        {
            inactivar (taxi,canti);
            system("cls");
            system("mode con: cols=70 lines=30");

            break;
        }
        case 4:
        {
            system("mode con: cols=100 lines=50");
            libre (taxi,canti,canti_calle,canti_carrera);
            system("cls");
            system("mode con: cols=70 lines=30");
            break;
        }
        case 5:
        {
            pedir_taxi(taxi,canti,canti_calle,canti_carrera);
            system("mode con: cols=70 lines=30");
            break;
        }
        case 6:
        {
            datos_por_placa(taxi,canti);
            system("mode con: cols=70 lines=30");
            break;
        }
        case 7:
        {
            system("cls");
            extraer(taxi,canti, canti_calle, canti_carrera);
            system("mode con: cols=70 lines=30");
            break;
        }
        case 8:
        {
            system("mode con: cols=100 lines=50");
            mover_taxi(taxi,canti,canti_calle,canti_carrera);
            system("mode con: cols=70 lines=30");
            break;
        }
        default:
        {
            system("mode con: cols=70 lines=30");
            break;
        }

        }
    }
    while(opcion != 9);
    system ("cls");
}


//funcion para insertar datos de los taxis
void leer_taxi(datos taxi[],int canti, int canti_calle, int canti_carrera)
{
    system("cls");
    system("color f0");
    for(int i = 0; i<canti; ++i)
    {

        system("cls");
        taxi[i].disponible = true;
        taxi[i].activo = true;
        taxi[i].estado = 'l';
        taxi[i].contador=0;
        taxi[i].suma = 0;
        taxi[i].encontrado = false;
        taxi[i].posible = false;
        cout << "porfavor dijite la placa del carro " << i << endl;
        cin >> taxi[i].placa;
        cout << "porfavor dijite que tipo de vehiculo es " << endl
             << "para van escriba 'v' y para automovil dijite 'a'" << endl;
        cin >> taxi[i].vehiculo;
        while (taxi[i].vehiculo != 'v' && taxi[i].vehiculo != 'a')
        {
            system("color f4");
            cout << "opcion incorrecta " << endl;
            cout << "porfavor dijite que tipo de vehiculo es " << endl
                 << "para van escriba 'v' y para automovil dijite 'a'" << endl;
            cin >> taxi[i].vehiculo;

        }
        system("color f0");
        if (taxi[i].vehiculo == 'a')
        {
            cout << "porfavor dijite cuantos puestos tiene" << endl;
            cin >> taxi[i].puestos;
            while (taxi[i].puestos > maxauto)
            {
                system("color f4");
                cout << "opcion invalida, el maximo de puestos es "<< maxauto << endl;
                cin>> taxi[i].puestos;

            }
            system("color f0");
        }
        if (taxi[i].vehiculo == 'v')
        {
            cout << "porfavor dijite cuantos puestos tiene" << endl;
            cin >> taxi[i].puestos;
            while (taxi[i].puestos > maxvan)
            {
                system("color f4");


                cout << "opcion invalida, el maximo de puestos es "<< maxvan << endl;
                cin>> taxi[i].puestos;

            }
            system("color f0");
        }
        cout << "porfavor dijite en que carrera esta el taxi"<< endl;
        cin >> taxi[i].carrera;
        while(taxi[i].carrera > canti_carrera)
        {
            system("color f4");
            cout <<  "opcion invalida"<<endl
                 << "porfavor dijite en que carrera esta el taxi"<< endl;
            cin >> taxi[i].carrera;
        }
        system("color f0");
        cout << "porfavor dijite en que calle esta el taxi"<<endl;
        cin >> taxi[i].calle;
        while (taxi[i].calle > canti_calle)
        {
            system("color f4");
            cout << "opcion invalida"<<endl
                 << "porfavor dijite en que calle esta el taxi"<<endl;
            cin >> taxi[i].calle;
        }
        system("color f0");



    }

    system("cls");
}
void imprimir_datos(datos taxi[],int canti)
{
    disponible(taxi,canti);
    system("cls");
    for(int i=0; i<canti; ++i)
    {
        cout << "taxi numero " << i <<endl
             << "numero de placa es igual a" << "\t" << taxi[i].placa<<endl
             << "tipo de vehiculo es igual a " << "\t" << taxi[i].vehiculo << endl
             << "numero de puestos disponibles " << "\t" << taxi[i].puestos<< endl;

        if(taxi[i].disponible)
        {
            cout << "el taxi esta disponible" << endl;
        }
        else
        {
            cout << "el taxi no esta disponible" << endl;
        }
        cout << "el taxi se encuentra en el cuadrante" <<"\t" << "[" << taxi[i].carrera << "]["<< taxi[i].calle << "]" << endl;
        cout << endl << endl;
    }


}
void extraer(datos taxi[],int canti, int canti_calle, int canti_carrera)
{
    int calle=0, carrera=0;
    bool bandera = false;
    disponible(taxi,canti);
    cout << "por favor digite de que cuadrante quiere la info." << endl;
    cout << "carrera" << "\t";
    cin >> carrera;
    while (carrera > canti_carrera)
    {
        system("color f4");
        cout << "opcion invalida, vuelva a intentar"<<endl;
        cin>> carrera;
    }
    system("color f0");
    cout << "calle" << "\t";
    cin >> calle;
    while (calle > canti_calle)
    {
        system("color f4");
        cout << "opcion invalida, vuelva a intentar"<<endl;
        cin>> calle;
    }
    system("color f0");
    system("cls");
    for(int i =0; i < canti; i++)
    {
        if(taxi[i].calle == calle && taxi[i].carrera == carrera)
        {
            cout << "informacion general del taxi "<< endl;
            cout    << "numero de placa es igual a" << "\t" << taxi[i].placa<<endl
                    << "tipo de vehiculo es igual a " << "\t" << taxi[i].vehiculo << endl
                    << "numero de puestos disponibles " << "\t" << taxi[i].puestos<< endl;

            if(taxi[i].disponible)
            {
                cout << "el taxi esta disponible" << endl;
            }
            else
            {
                cout << "el taxi no esta disponible" << endl;
            }
            cout << "el taxi se encuentra en el cuadrante" <<"\t" << "[" << taxi[i].carrera << "]["<< taxi[i].calle << "]" << endl;
            cout << endl << endl;
            bandera =true;
        }
    }
    if (!bandera)
    {
        cout << "no hay taxis en ese cuadrante" << endl;
    }
    system("pause");
    system ("cls");
}
void inactivar(datos taxi[], int canti)
{
    system("cls");
    string placa;
    bool bandera = false;
    cout << "por favor digite la placa que desea inactivar" << endl;
    cin >>  placa;
    for(int i =0; i < canti; ++i)
    {
        if (taxi[i].placa == placa)
        {
            bandera=true;
            taxi[i].activo =false;
            cout << "el taxi de placa " << taxi[i].placa << " a quedado inactivado" << endl;
        }
    }
    if (!bandera)
    {
        cout << "la placa que dijito no existe" << endl;
    }
    system("pause");
}
void libre (datos taxi[], int canti, int canti_calle, int canti_carrera)
{
    system("cls");
    string placa;
    int calle, contador = 0, contador2 =0;
    int carrera;
    bool bandera = false;
    cout << "por favor dijite el cuadrante desde donde se va a activar el taxi como libre " << endl
         << "carrera :"<< "\t";
    cin >> carrera;
    while (carrera > canti_carrera)
    {
        system("color f4");
        cout << "opcion invalida, vuelva a intentar" << endl;
        cin >> carrera;
    }
    system("color f0");
    cout << "calle :  " << "\t";
    cin>>calle;
    while (calle > canti_calle)
    {
        system("color f4");
        cout << "opcion invalida, vuelva a intentar" << endl;
        cin >> calle;
    }
    system("color f0");
    cout << "por favor digite la placa que desea activar como libre" << endl;
    cin >>  placa;
    for(int i =0; i < canti; ++i)
    {
        if (taxi[i].placa == placa)
        {
            bandera=true;
            if(taxi[i].activo == false || taxi[i].estado == 'o')
            {

                taxi[i].estado ='l';
                taxi[i].activo = true;
                cout << "el taxi de placa " << taxi[i].placa << " que esta en el cuadrante [" << carrera << "][" << calle << "]"<<endl
                     << "a quedado activado como libre." << endl;

                for(int k = 0; k<canti; k++)
                {
                    if(taxi[i].calle == taxi[k].calle && taxi[i].carrera == taxi[k].carrera)//acomodar el orden de los taxis que se quedaron en el cuadrante
                    {
                        if(i < k && taxi[k].contador > 0)
                        {
                            contador2++;
                            taxi[k].contador -= contador2;
                        }
                    }
                    contador2=0;
                    if(taxi[k].calle == calle && taxi[k].carrera == carrera)
                    {
                        contador++;
                    }
                }
                taxi[i].carrera=carrera;
                taxi[i].calle = calle;
                taxi[i].contador = contador;
            }
            else
            {
                cout << "no se puede activar el taxi, ya que este ya se encuentra activado"<<endl;
            }
        }
    }


    if (!bandera)
    {
        cout << "la placa que dijito no existe" << endl;
    }

    system("pause");
}
void mapa_ciudad (datos taxi[], int canti, int canti_calle, int canti_carrera)
{

    int tam = 0;//que tan largos van a ser los cuadrantes
    int lleno=0;
    if(canti > maxcuad)
    {
        tam = canti;
    }
    else
    {
        tam = maxcuad;
    }
    disponible(taxi,canti);
    for(int k = 0; k< canti_carrera; k++)
    {
        for(int l = 0; l < 12*canti_calle; l++)
            cout<<cuadro;

        cout << endl;
        for(int i = 0; i < tam; i++)
        {
            for(int j = 0; j < canti_calle; j++)
            {

                if((taxi[i].calle == j && taxi[i].carrera == k) && (taxi[i].disponible) && lleno < 5)
                {
                    cout << cuadro << taxi[i].contador << "." << setw(4) << taxi[i].placa <<setw(5)<< cuadro;
                    lleno++;
                }

                else
                    cout << cuadro<< "  " << setw(8) << "        " << cuadro;
            }
            cout << endl;

        }
        lleno=0;
        for(int l = 0; l < 12*canti_calle; l++)
            cout<<cuadro;
        cout << endl;
    }


}
void datos_por_placa(datos taxi[],int canti)
{
    system("cls");
    disponible(taxi,canti);
    bool bandera;
    string placa;
    cout << "Por favor digite la placa del taxi"<< "\t";
    cin >> placa;
    for(int i = 0; i < canti; ++i)
    {
        if (taxi[i].placa == placa)
        {
            cout << "informacion general del taxi "<< endl;
            cout << "numero de placa es igual a" << "\t" << taxi[i].placa<<endl
                 << "tipo de vehiculo es igual a " << "\t" << taxi[i].vehiculo << endl
                 << "numero de puestos disponibles " << "\t" << taxi[i].puestos<< endl;

            if(taxi[i].disponible)
            {
                cout << "el taxi esta disponible" << endl;
            }
            else
            {
                cout << "el taxi no esta disponible" << endl;
            }
            cout << "el taxi se encuentra en el cuadrante" <<"\t" << "[" << taxi[i].carrera << "]["<< taxi[i].calle << "]" << endl;
            cout << endl << endl;
            bandera =true;
        }
    }
    if (!bandera)
    {
        cout << "La placa que ingreso no existe" << endl;
    }
    system("pause");
    system("cls");
}
void mover_taxi(datos taxi[], int canti, int canti_calle, int canti_carrera)
{
    system("cls");
    bool bandera;
    string placa;
    int calle = 0, carrera = 0,contador=0,contador2 = 0;
    cout << "Por favor digite la placa del taxi que desea mover"<< "\t";
    cin >> placa;
    for(int i = 0; i < canti; ++i)
    {
        if (taxi[i].placa == placa)
        {
            cout << "por favor dijite el cuadrante a donde desea mover el taxi" << endl
                 << "carrera :"<< "\t";
            cin >> carrera;
            while (carrera > canti_carrera || carrera < 0)
            {
                system("color f4");
                cout << "opcion invalida, vuelva a intentar" << endl;
                cin >> carrera;
            }
            system("color f0");
            cout << "calle :  " << "\t";
            cin>>calle;
            while (calle > canti_calle || calle <0)
            {
                system("color f4");
                cout << "opcion invalida, vuelva a intentar" << endl;
                cin >> calle;
            }
            system("color f0");
            while (!((carrera == taxi[i].carrera && calle == taxi[i].calle+1)||(carrera == taxi[i].carrera && calle == taxi[i].calle-1)||(carrera == taxi[i].carrera+1 && calle == taxi[i].calle)||(carrera == taxi[i].carrera-1 && calle == taxi[i].calle)))
            {
                system("color f4");
                cout << "El taxi no se puede mover a ese cuadrante" <<endl;
                cout<< "Sólo se puede mover a cuadrantes adyacentes (arriba, abajo, izquierda, derecha)."<<endl;
                cout << "por favor dijite el cuadrante a donde desea mover el taxi" << endl
                     << "carrera :"<< "\t";
                cin >> carrera;
                while (carrera > canti_carrera)
                {
                    cout << "opcion invalida, vuelva a intentar" << endl;
                    cin >> carrera;
                }
                cout << "calle :  " << "\t";
                cin>>calle;
                while (calle > canti_calle)
                {
                    cout << "opcion invalida, vuelva a intentar" << endl;
                    cin >> calle;
                }
            }
            system("color f0");
            for(int k = 0; k<canti; k++)
            {
                if(taxi[i].calle == taxi[k].calle && taxi[i].carrera == taxi[k].carrera)//acomodar el orden de los taxis que se quedaron en el cuadrante
                {
                    if(i < k && taxi[k].contador > 0)
                    {
                        contador2++;
                        taxi[k].contador -= contador2;
                    }
                }
                contador2=0;
                if(taxi[k].calle == calle && taxi[k].carrera == carrera)
                {
                    contador++;
                }
            }
            taxi[i].carrera=carrera;
            taxi[i].calle = calle;
            taxi[i].contador = contador;
            bandera =true;
        }
    }
    if (!bandera)
    {
        cout << "La placa que ingreso no existe" << endl;
    }
    system("pause");
    system("cls");
}
void disponible(datos taxi[],int canti)
{
    for(int i = 0; i<canti; i++)
    {
        if (taxi[i].activo && taxi[i].estado == 'l')
        {
            taxi[i].disponible = true;
        }
        else
        {
            taxi[i].disponible = false;
        }
    }
}
void pedir_taxi(datos taxi[], int canti, int canti_calle, int canti_carrera)
{

    disponible(taxi,canti);
    system("cls");
    int calle, carrera,personas,aux = 0, aux2 = 0,menor = 9999, menor_tiempo = 1998, contador = 0;
    char tipo_taxi;
    bool bandera = false;

    cout << "por favor digite en que cuadrante se encuntra ud." << endl;
    cout << "carrera" << "\t";
    cin >> carrera;
    while (carrera > canti_carrera)
    {
        system("color f4");
        cout << "opcion invalida, vuelva a intentar"<<endl;
        cin>> carrera;
    }
    system("color f0");
    cout << "calle" << "\t";
    cin >> calle;
    while (calle > canti_calle)
    {
        system("color f4");
        cout << "opcion invalida, vuelva a intentar"<<endl;
        cin>> calle;
    }
    system("color f0");
    system("cls");
    cout <<"Desea un auto o una van?"<<endl
         << "(A/V)"<<endl;
    cin>> tipo_taxi;
    while (tipo_taxi != 'v' && tipo_taxi != 'a')
    {
        system("color f4");
        cout << "opcion incorrecta " << endl;
        cout << "porfavor dijite que tipo de vehiculo es " << endl
             << "para van escriba 'v' y para automovil dijite 'a'" << endl;
        cin >> tipo_taxi;

    }
    system("color f0");
    if (tipo_taxi == 'a')
    {
        cout << "porfavor dijite cuantos puestos necesita" << endl;
        cin >> personas;
        while (personas > maxauto)
        {
            system("color f4");
            cout << "opcion invalida, el maximo de puestos de un auto es de "<< maxauto << endl;
            cin>> personas;

        }
        system("color f0");
    }
    if (tipo_taxi == 'v')
    {
        cout << "porfavor dijite cuantos puestos tiene" << endl;
        cin >> personas;
        while (personas > maxvan)
        {
            system("color f4");


            cout << "opcion invalida, el maximo de puestos es "<< maxvan << endl;
            cin>> personas;

        }
        system("color f0");
    }
    for(int i = 0; i<canti; i++)
    {
        if (taxi[i].vehiculo == tipo_taxi && taxi[i].disponible && taxi[i].puestos >= personas)
        {
            if(taxi[i].calle>calle)
            {
                aux = taxi[i].calle - calle;
            }
            else
            {
                aux= calle - taxi[i].calle;
            }
            if(taxi[i].carrera>carrera)
            {
                aux2= taxi[i].carrera - carrera;
            }
            else
            {
                aux2 = carrera - taxi[i].carrera;
            }
            taxi[i].suma = aux+aux2;
            taxi[i].posible = true;
            aux=0;
            aux2=0;

            if(taxi[i].suma < menor)
            {
                menor = taxi[i].suma;
            }

        }
    }
    for(int i = 0; i<canti; i++)
    {
        if (taxi[i].posible && taxi[i].suma == menor)
        {
            if(taxi[i].contador<menor_tiempo)
            {
                menor_tiempo = taxi[i].contador;
            }
        }

    }
    for(int i =0; i<canti; ++i)
    {
        if (taxi[i].posible && taxi[i].suma == menor && taxi[i].contador == menor_tiempo && contador == 0)
        {
            taxi[i].encontrado=true;
            taxi[i].estado = 'o';
            cout << "el taxi de placa " << taxi[i].placa << " va en camino" << endl
            << "esta a una distancia de " << taxi[i].suma  << " cuadrantes"<<endl;
            bandera=true;
            contador++;
        }
    }
    for(int i =0; i<canti ; ++i)
    {
        taxi[i].posible = false;
        taxi[i].encontrado=false;
        taxi[i].suma=0;
    }
    if(bandera==false)
    {
        cout << "Lo sentimos no hay taxis disponibles para recogerlo"<<endl;
    }


    system("pause");


}
