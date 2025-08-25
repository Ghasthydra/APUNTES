#include <iostream>
#include <cmath> 
#include <limits> 
using namespace std; 
void mostrarMenuOperaciones() {
    std::cout << "\n--- Operaciones Disponibles ---\n";
    std::cout << "+ (suma)     - (resta)     * (multi)     / (div)     ^ (potencia)\n";
    std::cout << "r (raiz) --> solo necesita un número (el actual del acumulador)\n";
    std::cout << "c (limpiar) -> reiniciar el acumulador a 0\n";
    std::cout << "s (salir)   -> terminar el programa\n";
    std::cout << "-----------------------------\n";
}

int main () { 
    double num1; 
    constexpr double pi = 3.14159265358979323846;
    constexpr double e = 2.71828182845904523536;    // Número de Euler
    constexpr double phi = 1.61803398874989484820;   // Proporción áurea
    constexpr double raiz_de_2 = 1.41421356237309504880;

    // --- Constantes Físicas (con unidades en comentarios) ---
    constexpr double c = 299792458.0;               // Velocidad de la luz en el vacío (m/s)
    constexpr double g = 9.80665;                   // Aceleración de la gravedad estándar (m/s²)
    constexpr double G = 6.67430e-11;               // Constante de gravitación universal (N·m²/kg²)
    constexpr double h = 6.62607015e-34;            // Constante de Planck (J·s)
    constexpr double NA = 6.02214076e23;            // Número de Avogadro (mol⁻¹)
      double acumulador = 0.0;
    double numero_nuevo; // <-- CAMBIO: Este será el 'num2' en cada operación
    char op;

    std::cout << "--- Calculadora con Operaciones Encadenadas ---\n";
    std::cout << "Ingrese el primer número para empezar: ";
    std::cin >> acumulador;

    // Bucle principal que se ejecuta indefinidamente hasta que el usuario elige 's'
    while (true) {
        std::cout << "\n===================================";
        std::cout << "\n   Acumulador actual: [" << acumulador << "]";
        std::cout << "\n===================================\n";
        
        mostrarMenuOperaciones();
        std::cout << "Ingrese operación: ";
        std::cin >> op;

        if (op == 's' || op == 'S') {
            break; // Salir del bucle
        }
        
        if (op == 'c' || op == 'C') {
            std::cout << "--- Acumulador reiniciado --- \n";
            std::cout << "Ingrese el primer número para empezar: ";
            std::cin >> acumulador;
            continue; // Se salta el resto del bucle y empieza de nuevo
        }

        // <-- CAMBIO CLAVE: Pedimos el segundo número solo si la operación lo requiere
        // La raíz cuadrada no necesita un segundo número.
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
            std::cout << "Ingrese el siguiente número: ";
            std::cin >> numero_nuevo;
        }

        // --- Switch para realizar los cálculos ---
        // La lógica ahora es modificar el 'acumulador'
        switch (op) {
            case '+':
                acumulador += numero_nuevo; // Es lo mismo que: acumulador = acumulador + numero_nuevo;
                break;
            case '-':
                acumulador -= numero_nuevo;
                break;
            case '*':
                acumulador *= numero_nuevo;
                break;
            case '/':
                if (numero_nuevo == 0) {
                    std::cout << "Error: División por cero. La operación no se realizó." << std::endl;
                } else {
                    acumulador /= numero_nuevo;
                }
                break;
            case '^':
                acumulador = pow(acumulador, numero_nuevo);
                break;
            case 'r':
                if (acumulador < 0) {
                    std::cout << "Error: Raíz de número negativo. La operación no se realizó." << std::endl;
                } else {
                    acumulador = sqrt(acumulador);
                }
                break;
            default:
                std::cout << "Operador no válido. Intente de nuevo." << std::endl;
                break;
        }
    }

    std::cout << "\nCalculadora terminada. ¡Adiós!" << std::endl;
    return 0;
}