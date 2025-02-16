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
			std::cout << "M�todo de CBase" << std::endl;
		}
};

// Clase derivada para pruebas
class CDerivada : public CBase
{
	public:
		virtual ~CDerivada() = default;

		void metodo()
		{
			std::cout << "M�todo de CDerivada" << std::endl;
		}
};

void modificarValor(int &valor);

int main()
{
	// Conversi�n entre tipos num�ricos:
	int entero = 10;
	double real = static_cast<double> (entero);
	cout << "Real: " << real << endl;

	// Conversi�n en jerarqu�a de clases:
	CDerivada d = CDerivada ();
	CBase *pb = static_cast<CBase*> (&d); // Conversi�n segura, ya que CDerivada es una CBase

	d.metodo ();
	pb->metodo ();

	//--------------------------------------------------------------------------------------

	int num1 = 65;
	// Convertir la direcci�n de entero a un puntero a char
	char *ptrChar = reinterpret_cast<char*> (&num1);
	// Imprime el primer byte de la representaci�n de entero
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
		std::cout << "La conversi�n fall�" << std::endl;
	}
	delete pb;
}

void modificarValor(int &valor)
{
	valor = 20;
}
