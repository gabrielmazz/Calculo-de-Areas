#include <iostream>
#include <cmath>
#include "extras.hpp"

const double PI = 3.14159;

using namespace std;

class Objeto{
    public:
        double area;
};

class Conversao{
    public:
        double alfaCoversao(double alfa){
            double alfa_conv = ((alfa * PI)/180);
            return alfa_conv;
        }
};

//Usando herança, aplicaremos nos objetos a seguir
class Triangulo : public Objeto{
    private:
        double base;
        double altura;

    public:
        //Seta os parametros testando eles se são negativos
        void SetParametros(double base, double altura){
            if(base < 0 || altura < 0){
                cout << "Base ou altura estão com valor negativo" << endl;
                this->base = 0;
                this->altura = 0;
            }else{
                this->base = base;
                this->altura = altura;
            }   
        }

        void areaTriangulo(){
            this->area = ((this->base * this->altura)/2);
        }

        void printTriangulo(){
            cout << "Área do triangulo: " << this->area << endl;
        }
};

class Trapezio : public Objeto {
    private:
        double base_maior;
        double base_menor;
        double altura;

    public:

        void SetParametros(double base_maior, double base_menor, double altura){
            if(base_maior < 0 || base_menor < 0 || altura < 0){
                cout << "Bases ou altura estão com valor negativo" << endl;
                this->base_maior = 0;
                this->base_menor = 0;
                this->altura = 0;
            }else{
                this->base_maior = base_maior;
                this->base_menor = base_menor;
                this->altura = altura;
            }
        }

        void areaTrapezio(){
            this->area = (((this->base_maior + this->base_menor) * altura)/2);
        }

        void printTrapezio(){
            cout << "Área do Trapezio: " << this->area << endl;
        }
};

class Paralelogramo : public Objeto{
    private:
        double base;
        double altura;

    public:

        void SetParametros(double base, double altura){
            if(base < 0 || altura < 0){
                cout << "A base ou a altura estão com valores negativos" << endl;
                this->base = 0;
                this->altura = 0;
            }else{
                this->base = base;
                this->altura = altura;
            }
        }

        void areaParalelogramo(){
            this->area = (this->base * this->altura);
        }

        void printParalelogramo(){
            cout << "Área do Paralelogramo: " << this->area << endl;
        }
};

class Losango : public Objeto{
    private:
        double diagonal_maior;
        double diagonal_menor;

    public:
        void SetParametros(double diagonal_maior, double diagonal_menor){
            if(diagonal_maior < 0 || diagonal_maior < 0){
                cout << "A diagonal maior ou menor estão com valores negativo" << endl;
                this->diagonal_maior = 0;
                this->diagonal_menor = 0;
            }else{
                this->diagonal_maior = diagonal_maior;
                this->diagonal_menor = diagonal_menor;
            }
        }

        void areaLosango(){
            this->area = ((this->diagonal_maior * this->diagonal_menor)/2);
        }

        void printLosango(){
            cout << "Área do Losango: " << this->area << endl;
        }
};

class Triangulo_Equilatero : public Objeto{
    private:
        double lado;

    public:

        void SetParametros(double lado){
            if(lado < 0){
                cout << "Os lados estão com valor negativo" << endl;
                this->lado = 0;
            }else{
                this->lado = lado;
            }
        }

        void areaTrianguloEquilatero(){
            this->area = ((pow(lado, 2) * sqrt(3))/4);
        }    

        void printTrianguloEquilatero(){
            cout << "Área do Triangulo Equilatero: " << this->area << endl;
        }
};

class Hexagono_Regular : public Objeto{
    private:
        double lado;

    public:
        void SetParametros(double lado){
            if(lado < 0){
                cout << "Os lados estão com valor negativo" << endl;
                this->lado = 0;
            }else{
                this->lado = lado;
            }
        }

        void areaHexagonoRegular(){
            this->area = (((3 * pow(lado,2)) * sqrt(3))/2);
        }

        void printHexagonoRegular(){
            cout << "Área do Hexagono Regular: " << this->area << endl;
        }
};

class Circulo : public Objeto{
    private:
        double raio;

    public:
        void SetParametros(double raio){
            if(raio < 0){
                cout << "O raio está com valor negativo" << endl;
                this->raio = 0;
            }else{
                this->raio = raio;
            }
        }

        void areaCirculo(){
            this->area = (PI * pow(raio, 2));
        }

        void printCirculo(){
            cout << "Área do Circulo: " << this->area << endl;
        }
};

class Setor_Circular : public Objeto, public Conversao{
    private:
        double raio;
        double alfa;
        double alfa_conv;

    public:
        void SetParametros(double raio, double alfa){
            if(raio < 0 || alfa < 0){
                cout << "O raio ou o ângulo estão com valor negativo" << endl;
                this->raio = 0;
                this->alfa = 0;
            }else{
                this->raio = raio;
                this->alfa = alfa;
            }
        }

        void areaSetorCircular(){
            this->alfa_conv = alfaCoversao(this->alfa);
            this->area = ((this->alfa_conv * pow(this->raio, 2))/2);
        }

        void printSetorCircular(){
            cout << "Área do Setor Circular: " << this->area << endl;
        }
};

class Coroa : public Objeto{
    private:
        double raio_maior;
        double raio_menor;

    public:

        void SetParametros(double raio_maior, double raio_menor){
            if(raio_maior < 0 || raio_menor < 0){
                cout << "Os raios estão com valores negativos" << endl;
                this->raio_maior = 0;
                this->raio_menor = 0;
            }else{
                this->raio_maior = raio_maior;
                this->raio_menor = raio_menor;
            }
        }

        void areaCoroa(){
            this->area = (PI * (pow(this->raio_maior, 2) - pow(this->raio_menor, 2)));
            cout << "Área da Coroa: " << this->area << endl;
        }
};

//Funções para chamada das classes
void triangulo_area();
void trapezio_area();
void paralelogramo_area();
void losango_area();
void triangulo_equilatero_area();
void hexagono_regular_area();
void circulo_area();
void setor_circular_area();
void coroa_area();

int main(void){

    clear_screen();
    int switch1;

    RETORNO:
    cout << "Escolha uma opção para definir a área do objeto desejado:" << endl;
    cout << "1 - Área do Triangulo" << endl;
    cout << "2 - Área do Trapezio" << endl;
    cout << "3 - Área do Paralelogramo" << endl;
    cout << "4 - Área do Losango" << endl;
    cout << "5 - Área do Triangulo Equilatero" << endl;
    cout << "6 - Área do Hexagono Regular" << endl;
    cout << "7 - Área do Circulo" << endl;
    cout << "8 - Área do Setor Circular" << endl;
    cout << "9 - Área da Coroa" << endl;
    cout << "R: ";
    cin >> switch1;

    clear_screen();
    switch(switch1){
        case 1:
            triangulo_area();
            break;

        case 2:
            trapezio_area();
            break;

        case 3:
            paralelogramo_area();
            break;

        case 4:
            losango_area();
            break;

        case 5:
            triangulo_equilatero_area();
            break;

        case 6:
            hexagono_regular_area();
            break;

        case 7:
            circulo_area();
            break;

        case 8:
            setor_circular_area();
            break;

        case 9:
            coroa_area();
            break;

        default:
            cout << "Valor inserido errado, tente novamente..." << endl;
            stop_time(3);
            goto RETORNO;
    }

    setbuf(stdin, NULL);
    stop();
    clear_screen();
    return EXIT_SUCCESS;
}

void triangulo_area(){
    Triangulo triangulo;

    double temp_base= 0, temp_altura = 0;

    cout << "Defina a base: ";
    cin >> temp_base;

    cout << "Defina a altura: ";
    cin >> temp_altura;

    triangulo.SetParametros(temp_base, temp_altura);
    triangulo.areaTriangulo();
    triangulo.printTriangulo();
}

void trapezio_area(){
    Trapezio trapezio;

    double temp_base_maior = 0, temp_base_menor = 0, temp_altura = 0;

    cout << "Defina a base maior: ";
    cin >> temp_base_maior;

    cout << "Defina a base menor: ";
    cin >> temp_base_menor;

    cout << "Defina a altura: ";
    cin >> temp_altura;

    trapezio.SetParametros(temp_base_maior, temp_base_menor, temp_altura);
    trapezio.areaTrapezio();
    trapezio.printTrapezio();
}

void paralelogramo_area(){
    Paralelogramo paralelogramo;

    double temp_base = 0, temp_altura = 0;

    cout << "Defina a base: ";
    cin >> temp_base;

    cout << "Defina a altura: ";
    cin >> temp_altura;

    paralelogramo.SetParametros(temp_base, temp_altura);
    paralelogramo.areaParalelogramo();
    paralelogramo.printParalelogramo();
}

void losango_area(){
    Losango losango;

    double temp_diagonal_maior = 0, temp_diagonal_menor = 0;

    cout << "Defina a diagonal maior: ";
    cin >> temp_diagonal_maior;

    cout << "Defina a diagonal menor: ";
    cin >> temp_diagonal_menor;

    losango.SetParametros(temp_diagonal_maior, temp_diagonal_menor);
    losango.areaLosango();
    losango.printLosango();
}

void triangulo_equilatero_area(){
    Triangulo_Equilatero triangulo_equilatero;

    double temp_lado = 0;

    cout << "Defina o lado: ";
    cin >> temp_lado;

    triangulo_equilatero.SetParametros(temp_lado);
    triangulo_equilatero.areaTrianguloEquilatero();
    triangulo_equilatero.printTrianguloEquilatero();
}

void hexagono_regular_area(){
    Hexagono_Regular hexagono_regular;

    double temp_lado = 0;

    cout << "Defina o lado: ";
    cin >> temp_lado;

    hexagono_regular.SetParametros(temp_lado);
    hexagono_regular.areaHexagonoRegular();
    hexagono_regular.printHexagonoRegular();
}

void circulo_area(){
    Circulo circulo;

    double temp_raio;

    cout << "Defina o raio: ";
    cin >> temp_raio;

    circulo.SetParametros(temp_raio);
    circulo.areaCirculo();
    circulo.printCirculo();
}

void setor_circular_area(){
    Setor_Circular setor_circular;

    double temp_raio = 0;
    double temp_alfa = 0;

    cout << "Defina o raio: ";
    cin >> temp_raio;

    cout << "Defina o ângulo: ";
    cin >> temp_alfa;

    setor_circular.SetParametros(temp_raio, temp_alfa);
    setor_circular.areaSetorCircular();
    setor_circular.printSetorCircular();
}

void coroa_area(){
    Coroa coroa;

    double temp_raio_maior = 0, temp_raio_menor = 0;
    double temp_alfa;

    cout << "Defina o raio maior: ";
    cin >> temp_raio_maior;

    cout << "Defina o raio menor: ";
    cin >> temp_raio_menor;

    coroa.SetParametros(temp_raio_maior, temp_raio_menor);
    coroa.areaCoroa();
}