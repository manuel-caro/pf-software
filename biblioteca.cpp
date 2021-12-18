#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#define N 50

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

//Se declaran 2 estructuras, una para libro y otra para bibliotecas
typedef struct{
	char nombre_lib[N];
	char autor[N];
	int lleno_lib;
}libro;

typedef struct{
	char nombre_bi[N];
	libro lib[10];
	int lleno_bi;
}biblioteca;


biblioteca bi[7];

//Definicion de las funciones
void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
void CursorOn(bool visible, DWORD size);
void CursorOff();
void limpia();
void vacio();
void menu();
void anadebi();
void cambio(char a[]);
void anadelib();
void consultar();


//Funcion principal main
int main(){
	system("mode con: cols=80 lines=25");
	CursorOff();
 cout << "          SISTEMA PARA BIBLIOTECA";
	menu();
	getch();
	return 0;
}

//Funcion del menu de opciones
void menu(){
	char op;
	CursorOn(1,10);
	do{
		gotoxy(3,6); cout << "MENU PRINCIPAL";
		gotoxy(3,9); cout << "(1) Agregar Biblioteca";
		gotoxy(3,11); cout << "(2) Agregar Libro";
		gotoxy(3,13); cout << "(3) Consultar libro";
		gotoxy(3,15); cout << "(4) Cerrar";
		gotoxy(3,17); cout << "Ingrese opcion: ";
		cin >> op;
		
		if(op!='1' && op!='2' && op!='3' && op!='4'){
			gotoxy(3,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			gotoxy(3,22); cout << "                                                                       ";
			gotoxy(3,17); cout << "                                                                       ";
			CursorOn(1,10);	
		}
			
	}while(op!='1' && op!='2' && op!='3' && op!='4');
	
	
	if (op=='1'){
		anadebi();
	}
	
	if (op=='2'){
		int a = 0;
		for(int i = 0; i < 10 && a==0; i++){
			if ( bi[i].lleno_bi == 1)
				a = 1;
		}
		if (a==0){
			CursorOff();
			gotoxy(3,21); cout << "No hay bibliotecas. Primero se debe ingresar una biblioteca.";
			gotoxy(3,23); cout << "Presione una tecla para continuar..";
			getch();
			gotoxy(3,17); cout << "                                                       ";
			gotoxy(3,21); cout << "                                                                    ";
			gotoxy(3,23); cout << "                                       ";
			menu();
		}
		else
			anadelib();
	}
	
	if (op=='3'){
		int a = 0;
		for(int i = 0; i < 7 && a==0; i++){
			for(int j = 0; j < 10 && a==0; j++){
				if ( bi[i].lib[j].lleno_lib == 1)
				a = 1;	
			}
			
		}
		if (a==0){
			CursorOff();
			gotoxy(3,21); cout << "No hay libros. Primero se debe ingresar un libro.";
			gotoxy(3,23); cout << "Presione una tecla para continuar..";
			getch();
			gotoxy(3,17); cout << "                                                       ";
			gotoxy(3,21); cout << "                                                                    ";
			gotoxy(3,23); cout << "                                       ";
			menu();
		}
		else
			consultar();
	}
	
	if (op=='4')
		exit(0);
	
}

void anadebi(){
	limpia();
	int aux = 0;
	char op;
	for(int i = 0; i < 7 && aux == 0; i++){
		if (bi[i].lleno_bi == 0){
			gotoxy(3,6); cout << "AGREGAR BIBLIOTECA\n";
			gotoxy(3,9); cout << "Ingrese un nombre: ";
			fflush(stdin);
			fgets(bi[i].nombre_bi, N, stdin);
			cambio(bi[i].nombre_bi);
			bi[i].lleno_bi = 1;
			
			do{
				CursorOff();
				gotoxy(3,22); cout << "Pulse una tecla: <1> Ingresar otra biblioteca / <2> Ir al menu principal ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if(op=='1'){
					CursorOn(1,10);
					gotoxy(3,9); printf("                                                        ");
					gotoxy(3,22);printf("                                                                          ");
				}
				
			if (op == '2')
					aux=1;
				
		}	
	}
	
	if (aux == 0){
		gotoxy(3,22); cout << "No quedan mas espacios. Presione una tecla para continuar..";
		getch();
		CursorOff();
	}
	
	limpia();
	menu();
}


void anadelib(){
	limpia();
	int op,aux=0,f=8;
	char op2;
	for(int i = 0; i < 7; i++){
		if(bi[i].lleno_bi==1){
			gotoxy(3,6); cout << "BIBLIOTECAS:";
			gotoxy(3,f); cout << "(" << i+1 << ") " << bi[i].nombre_bi;
			f+=2;
		}
	}
	gotoxy(3,f); cout << "Ingrese opcion: ";
	cin >> op;
	
	limpia();
	
	for (int i = 0; i < 10 && aux == 0; i++){
		if(bi[op-1].lib[i].lleno_lib == 0){
			gotoxy(3,6); cout << "BIBLIOTECA: " << bi[op-1].nombre_bi;
			gotoxy(3,8); cout << "INGRESO DE LIBROS";
			gotoxy(3,11); cout << "Ingrese nombre del libro: ";
			fflush(stdin);
			fgets(bi[op-1].lib[i].nombre_lib, N, stdin);
			cambio(bi[op-1].lib[i].nombre_lib);
			
			gotoxy(3,13); cout << "Ingrese nombre del autor: ";
			fflush(stdin);
			fgets(bi[op-1].lib[i].autor, N, stdin);
			cambio(bi[op-1].lib[i].autor);
			
			bi[op-1].lib[i].lleno_lib = 1;
			
		
			do{
				CursorOff();
				gotoxy(3,22); cout << "Pulse una tecla: <1> Ingresar otro libro / <2> Ir al menu principal ";
				op2 = getch();	
			}while (op2!='1' && op2!='2');
			
			if(op2=='1'){
					CursorOn(1,10);
					gotoxy(3,11); cout << "                                                        ";
					gotoxy(3,13); cout << "                                                                          ";
					gotoxy(3,22); cout << "                                                                          ";
			}
					
			else if (op2 == '2')
					aux=1;	
		}	
	}
	
	limpia();
	menu();	
}

void consultar(){
	limpia();
	char buscar[N]; 
	char op;
	char op2;
	CursorOn(1,10);
	do{
		gotoxy(3,6); cout << "CONSULTA DE LIBROS\n";
		gotoxy(3,9); cout << "(1) Busqueda por nombre";
		gotoxy(3,11); cout << "(2) Busqueda por autor";
		gotoxy(3,13); cout << "(3) Busqueda por biblioteca";
		gotoxy(3,15); cout << "Ingrese opcion: ";
		cin >> op;
		
		if(op!='1' && op!='2' && op!='3') {
			gotoxy(3,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			gotoxy(3,22); cout << "                                                                       ";
			gotoxy(3,13); cout << "                                                          ";
			CursorOn(1,10);	
		}
			
	}while(op!='1' && op!='2' && op!='3');
	
	limpia();
	
	
	switch(op){
		case '1':{
			gotoxy(3,6); cout << "CONSULTA DE LIBROS";
			gotoxy(3,9); cout << "Ingrese nombre del libro: ";
			fflush(stdin);
			fgets(buscar, N, stdin);
			cambio(buscar);
			
			int aux=0;
			for(int i = 0; i < 10; i++){
				for (int j = 0; j < 10; j++){
					if (strcmpi(buscar,bi[i].lib[j].nombre_lib) == 0 ){
						aux=1;
						gotoxy(3,12); cout << "Libro:      " << bi[i].lib[j].nombre_lib;
						gotoxy(3,16); cout << "Biblioteca: " << bi[i].nombre_bi;
						gotoxy(3,14); cout << "Autor:      " << bi[i].lib[j].autor;	
					}
				}
			}
			
			if (aux ==1){
				do{
					CursorOff();
					gotoxy(3,22); cout << "Pulse una tecla: <1> Consultar otro libro / <2> Ir al menu principal ";
					op2 = getch();	
				}while (op2!='1' && op2!='2');
						
				if (op2 == '1'){
					limpia();
					consultar();
				}
						
				else if (op2 == '2'){
					limpia();
					menu();
				}
			}
			
			
			else if (aux==0){
				CursorOff();
				gotoxy(3,22); cout << "Busqueda no encontrada. Presione una tecla para continuar..";
				getch();
				limpia();
				menu();
			}
			
			break;
		}
		
		case '2':{
			gotoxy(3,6); cout << "CONSULTA DE LIBROS";
			gotoxy(3,9); cout << "Ingrese nombre del autor: ";
			fflush(stdin);
			fgets(buscar, N, stdin);
			cambio(buscar);
			
			int f=12, aux=0;
			for(int i = 0; i < 7; i++){
				for (int j = 0; j < 10; j++){
					if (strcmpi(buscar,bi[i].lib[j].autor) == 0 ){
						aux=1;
						gotoxy(3,f); cout << "Libro:  " << bi[i].lib[j].nombre_lib;
						gotoxy(40,f); cout << "Biblioteca: " <<bi[i].nombre_bi;
						f+=2;
					}
				}
			}
			
			if (aux ==1){
				do{
					CursorOff();
					gotoxy(3,22); cout << "Pulse una tecla: <1> Consultar otro libro / <2> Ir al menu principal ";
					op2 = getch();	
				}while (op2!='1' && op2!='2');
						
				if (op2 == '1'){
					limpia();
					consultar();
				}
						
				else if (op2 == '2'){
					limpia();
					menu();
				}
			}
			
			
			else if (aux==0){
				CursorOff();
				gotoxy(3,22); cout << "Busqueda no encontrada. Presione una tecla para continuar..";
				getch();
				limpia();
				menu();
			}
			
			
			
			
			break;
		}
		
		case '3':{
			limpia();
			int op,aux=0,f=8;
			char op2;
			for(int i = 0; i < 7; i++){
				if(bi[i].lleno_bi==1){
					gotoxy(3,6); cout << "BIBLIOTECAS:";
					gotoxy(3,f); cout << "(" << i+1 <<") " << bi[i].nombre_bi;
					f+=2;
				}
			}
			gotoxy(3,f); cout << "Ingrese opcion: ";
			cin >> op;
			
			limpia();
			CursorOff();
			gotoxy(3,6); cout << "CONSULTA DE LIBROS";
			int f2=11;
			for (int i = 0; i < 10; i++){
				if(bi[op-1].lib[i].lleno_lib == 1){
					gotoxy(3,8); cout << "BIBLIOTECA: " << bi[op-1].nombre_bi;
					gotoxy(3,f2); cout << "Libro: " << bi[op-1].lib[i].nombre_lib;
					f2+=2;
				}	
			}
			
			do{
				
				gotoxy(3,22); cout << "Pulse una tecla: <1> Consultar otro libro / <2> Ir al menu principal ";
				op2 = getch();	
			}while (op2!='1' && op2!='2');
			
			if (op2 == '1'){
				limpia();
				consultar();
			}
			
			else if (op2 == '2'){
				limpia();
				menu();
			}
			
			break;
		}
	}
	
	getch();
	menu();
}


void vacio(){
	for(int i = 0; i < 7; i++){
		bi[i].lleno_bi = 0;
		for(int j = 0; j < 10; j++){
			bi[i].lib[j].lleno_lib = 0;
		}
	}
}


void cambio(char a[]){
	int aux;
	aux = strlen(a);
	a[aux-1] = '\0';
}


void limpia(){
	int i,j;
	for(i=5;i<=23;i++){
		for(j=3;j<=76;j++){
			gotoxy(j,i); printf(" ");}}
}


void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 
void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "?";
		gotoxy(i,y2); cout << "?";
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout << "?";
		gotoxy(x2,i); cout << "?";
    }
    
    gotoxy(x1,y1); cout << "?";
    gotoxy(x1,y2); cout << "?";
    gotoxy(x2,y1); cout << "?";
    gotoxy(x2,y2); cout << "?";
}


void CursorOff(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}


void CursorOn(bool visible, DWORD size){
	if(size == 0)
	{
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

