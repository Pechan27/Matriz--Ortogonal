#include"Matriz.h"

int main(){

	MatrizOrtogonal* matriz;
	matriz = new MatrizOrtogonal();
	
	matriz->insertar(1,1,1);
	matriz->insertar(1,3,3);
	matriz->insertar(4,6,5);
	matriz->insertar(5,4,6);
	matriz->insertar(7,7,8);
	
	return 0;
}
	
