//============================================================================
// Autor: Diardon
// Blog : https://diardon.wordpress.com/
//============================================================================

#include <iostream>

using namespace std;

// Clase base para pruebas
class CBase
{
	public:
		virtual ~CBase() = default;
		void metodo()
		{
			std::cout << "Método de CBase" << std::endl;
		}
};

// Clase derivada para pruebas
class CDerivada : public CBase
{
	public:
		virtual ~CDerivada() = default;

		void metodo()
		{
			std::cout << "Método de CDerivada" << std::endl;
		}
};

void modificarValor(int &valor);

int main()
{
	// Conversión entre tipos numéricos:
	int entero = 10;
	double real = static_cast<double> (entero);
	cout << "Real: " << real << endl;

	// Conversión en jerarquía de clases:
	CDerivada d = CDerivada ();
	CBase *pb = static_cast<CBase*> (&d); // Conversión segura, ya que CDerivada es una CBase

	d.metodo ();
	pb->metodo ();

	//--------------------------------------------------------------------------------------

	int num1 = 65;
	// Convertir la dirección de entero a un puntero a char
	char *ptrChar = reinterpret_cast<char*> (&num1);
	// Imprime el primer byte de la representación de entero
	cout << "Primer byte de entero: " << ptrChar[0] << endl;

	//--------------------------------------------------------------------------------------

	const int constante = 10;
	// Eliminar constancia para modificar el valor (solo seguro si se sabe lo que se hace)
	modificarValor (const_cast<int&> (constante));
	cout << "Valor modificado: " << constante << endl;
	return 0;

	//--------------------------------------------------------------------------------------

	CBase *pbase = new CDerivada();
	// Intentamos convertir de Base* a Derivada*
	CDerivada *pderivada = dynamic_cast<CDerivada*>(pbase);

	if(pderivada)
	{
		pderivada->metodo();
	}
	else
	{
		std::cout << "La conversión falló" << std::endl;
	}
	delete pb;
}

void modificarValor(int &valor)
{
	valor = 20;
}
