#include"Matriz.h"
	/*MatrizOrtogonal* matriz;
	matriz = new MatrizOrtogonal();
	
	matriz->insertar(1,1,1);
	return 0;*/
	
using namespace std;

void pausa();

int main(){
	bool bandera = false;
	char tecla;
	MatrizOrtogonal* matriz;
	matriz = new MatrizOrtogonal();
	
	do
	{
		system("cls");
		cin.clear();
		cout<<"1. Ingresar un valor"<<endl;
		cout<<"2. mostrar"<<endl;
		cout<<"3. "<<endl;
		cout<<"4. "<<endl;
		cout<<"5."<<endl;
		cout<<"6. "<<endl;
		cout<<"Elije una opcion: ";
		
		cin>>tecla;
		switch(tecla){
			case 1:
				cout<<" "<<endl;
				matriz->insertar(1,1,1);
				matriz->insertar(5,4,2);
				break;

			case 2:
				cout<<" "<<endl;
				break;

			case 3:
				cout<<" "<<endl;
				break;
				
			case 4:
				cout<<" "<<endl;
				break;

			case 5:
				cout<<" "<<endl;
				break;
				
			case 6:
				cout<<" "<<endl;
				break;
		}
		
	}while(bandera!=true);
	
	return 0;
}
	
