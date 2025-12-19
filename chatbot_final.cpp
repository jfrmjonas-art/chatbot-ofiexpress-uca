#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void logOpcion(ofstream &log, const string &texto) {
    log << texto << endl;
}

void mostrarMenu() {
    cout << "\n=== Menu OfiExpress ===" << endl;
    cout << "1) Ver horario" << endl;
    cout << "2) Datos de contacto" << endl;
    cout << "3) Mensajes aleatorios" << endl;
    cout << "4) Servicios principales" << endl;
    cout << "5) Salir" << endl;
    cout << "Elige una opcion: ";
}

void mostrarHorario() {
    cout << "Bot: Horario de atencion: 10:00 a 15:00, de lunes a miercoles." << endl;
}

void mostrarContacto() {
    cout << "Bot: Tel: 55-0000-0000 | Correo: sin-definir@ofiexpress.mx" << endl;
}

void mostrarServicios() {
    cout << "Bot: Informacion de servicios no disponible." << endl;
}

void mensajeAleatorio() {
    string mensajes[4] = {
        "Tu pedido sera revisado en los proximos dias.",
        "No tenemos informacion de tu pedido en este momento.",
        "Por favor llama mas tarde.",
        "No hay pedidos registrados."
    };

    int indice = rand() % 4;
    cout << "Bot: " << mensajes[indice] << endl;
}

int main() {
    srand(time(0));

    ofstream log("historial_ofiexpress.txt", ios::app);
    if (!log) {
        cout << "Error al abrir el archivo de historial." << endl;
        return 1;
    }

    string empresa = "OfiExpress";
    string nombre;
    int opcion = 0;

    cout << "=== Chatbot " << empresa << " v9 ===" << endl;
    cout << "Como te llamas? ";
    getline(cin, nombre);

    while (opcion != 5) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
        mostrarHorario();
        logOpcion(log, "Cliente consulto horario.");
        break;
    case 2:
        mostrarContacto();
        logOpcion(log, "Cliente consulto datos de contacto.");
        break;
    case 3:
        mensajeAleatorio();
        logOpcion(log, "Cliente recibio mensaje aleatorio.");
        break;
    case 4:
        mostrarServicios();
        logOpcion(log, "Cliente consulto servicios.");
        break;
    case 5:
        cout << "Bot: Gracias por tu visita, " << nombre << ". Hasta luego." << endl;
        break;
    default:
        cout << "Bot: Opcion no valida." << endl;
        }
    }

    log.close();

    return 0;
}
