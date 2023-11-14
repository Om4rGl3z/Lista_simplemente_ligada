#include <iostream>
using namespace std;
template<class T>
class LSLSE;


class Socio
{
private:

    string NombreSocio;
    string DomicilioSocio;
    int AnioIngreso;
    int NumeroSocio;
public:
    Socio();

    Socio(int NumSo, string NomSo, string DomSo, int AnioIng);
    friend std::ostream& operator<<( std::ostream&, Socio&);
    friend std::istream& operator>>( std::istream&, Socio&);
    bool operator==(Socio&p)
    {
        return p.NumeroSocio==NumeroSocio&&p.NombreSocio==NombreSocio&&p.DomicilioSocio==DomicilioSocio&&p.AnioIngreso==AnioIngreso;
    }

    bool operator<(const Socio& p) const
    {
        return AnioIngreso < p.AnioIngreso;
    }
    bool operator<=(const Socio& p) const
    {
        return AnioIngreso < p.AnioIngreso;
    }
    bool operator>=(const Socio& p) const
    {
        return AnioIngreso < p.AnioIngreso;
    }
    void operator=(Socio& x);
    void NombreDomiSocio();
    void IncrementarNum();
    void DecrementarNum();

};

void Socio::DecrementarNum(){
    NumeroSocio--;
}

void Socio::IncrementarNum(){
    NumeroSocio++;
}



void Socio::NombreDomiSocio(){

    cout<<"\nIngresa Nombre: ";
    cin>>NombreSocio;
    cout<<"\nIngresa Domicilio: ";
    cin>>DomicilioSocio;

}
Socio::Socio()
{
    NumeroSocio= 0;
    NombreSocio ="";
    DomicilioSocio = "";
    AnioIngreso = 0;
}

Socio::Socio(int NumSo, string NomSo, string DomSo, int AnioIng): NumeroSocio(NumSo),NombreSocio(NomSo),DomicilioSocio(DomSo), AnioIngreso(AnioIng) {}

void Socio::operator=(Socio& x)
{
    NumeroSocio=x.NumeroSocio;
    NombreSocio = x.NombreSocio;
    DomicilioSocio=x.DomicilioSocio;
    AnioIngreso=x.AnioIngreso;
}


std::ostream& operator<<( std::ostream& o, Socio& p)
{
    o<<"Numero de Socio: "<<p.NumeroSocio
     <<"\nNombre de Socio: "<<p.NombreSocio<<
     "\nDomicilio de Socio: "<<p.DomicilioSocio
     <<"\nAnio de Ingreso de Socio: "<<p.AnioIngreso<<endl;
    return o;
}
std::istream& operator>>( std::istream& o, Socio& p)
{
    cout<<"\n Inserta Numero de Socio: ";
    o>>p.NumeroSocio;
    cin.ignore();
    std::cout<<"\n Inserta Nombre de Socio: ";
    getline (o,p.NombreSocio);
    std::cout<<"\n Inserta Domicilio de Socio: ";
    getline (o,p.DomicilioSocio);
    std::cout<<"\n Inserta Anio de Ingreso de Socio: ";
    o>>p.AnioIngreso;
    return o;
}





template<class T>
class node
{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr) {};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE
{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr) {};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    void imprimirTodo()const;
    void agregar(T elem);
    node<T>* buscar(T elem) const;
};

template<class T>
void LSLSE<T>::agregar(T elem)
{
    node<T>* aux = new node<T>;
    aux->data = elem;
    aux->sig = lista;
    lista = aux;
}

template<class T>
node<T>* LSLSE<T>::buscar(T elem) const
{
    node<T>* aux = lista;
    while (aux != nullptr)
    {
        if (aux->data == elem)
        {
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

template<class T>
void LSLSE<T>::imprimir()const
{
    node<T>* aux=lista;
    while(aux!=nullptr)
    {
        std::cout<<"\n"<<aux->data<<"\n \n";
        aux=aux->sig;
    }
}


template<class T>
void LSLSE<T>::imprimirTodo()const
{
    int cont =0;
    node<T>* aux=lista;
    while(aux!=nullptr)
    {
        aux=aux->sig;
        cont++;
    }
    cout<<"Total:"<<cont<<endl;
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos)
{
    if(vacia() || pos==nullptr)
    {
        return false;
    }

    if(pos==lista)
    {
        lista=lista->sig;
    }
    else
    {
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem)
{
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr)
    {
        aux->sig=lista;
        lista=aux;
    }
    else
    {
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const
{
    if(vacia() || pos==nullptr)
    {
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos)
    {
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const
{
    if(vacia())
    {
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const
{
    if(vacia())
    {
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr)
    {
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const
{
    if(lista==nullptr)
        return true;
    return false;
}

int main()
{
    LSLSE<Socio> MiLista;
    Socio MiSocio;
    node<Socio>* SocioEncontrado;
    int a=0;
    int opc=0;
    do
    {
        cout<<"_________-*-_________\n";
        cout<<"1. Registrar un nuevo socio.\n";
        cout<<"2. Dar de baja un socio del club.\n";
        cout<<"3. Generar un reporte con los datos de todos los socios.\n";
        cout<<"4. Buscar por nombre y domicilio a un socio del club.\n";
        cout<<"5. Calcular e imprimir el total de socios registrados.\n";
        cout<<"_________-*-_________\n";

        cout<<">>";
        cin>>opc;
        cin.ignore();
        switch(opc)
        {
        case 1:
            cout<<"Ingrese los datos del Socio\n";
            cin>>MiSocio;
            MiLista.agregar(MiSocio);

            break;

        case 2:
            cout<<"Ingrese los datos del Socio\n";
            cin>>MiSocio;
            cin.ignore();
            SocioEncontrado=MiLista.buscar(MiSocio);


            if (!MiLista.buscar(MiSocio))
            {
                 cout<<"\nElemento no encontrado .\n";
            }
            else
            {
                MiLista.eliminar(MiLista.buscar(MiSocio));
                std::cout << "\nElemento eliminado." << std::endl;
            }

            break;
        case 3:
            cout<<"3.Se genero el reporte \n";
            MiLista.imprimir();
            break;
        case 4:
            cout<<"Ingrese nombre y domicilio \n";
            cin>>MiSocio;
            cin.ignore();
            SocioEncontrado=MiLista.buscar(MiSocio);
            if (SocioEncontrado != nullptr)
            {
                cout<<"\n\nSocio Encontrado.\n";
                cout<<MiSocio;

            }
            else
            {
                std::cout << "\n\nSocio:\n" << MiSocio << "\nNo encontrado en la lista." << std::endl;
            }
            break;
        case 5:
            MiLista.imprimirTodo();
            break;
        }
    }
    while(opc!=6);

    return 0;
}
