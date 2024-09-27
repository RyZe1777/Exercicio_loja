#include <iostream>
#include <fstream> //biblioteca para ler (ifstream) e para criar e escrever (ofstream) ficheiros
 
using namespace std;

struct Produto
{
    int id;
    char status; // A -> ativo / D -> eliminado
    string nome;
    float preco;
    int quantidade;
};

void menu(){
    system("clear");
    cout << "\n==========================" <<endl;
    cout << "          MENU" <<endl;
    cout << "==========================" <<endl;
    cout << "1-Adicionar Produto"
    cout << "2-Consultar Produto <<endl;
    cout << "3-Alterar Produto" <<endl;
    cout << "4-Eliminar Produto" <<endl;
    cout << "5-SAIR" <<endl;
    cout << "==========================" << endl;

}

int getOpcao(){
    int opcao;
    cout << "Digite a sua opcao: ";
    cin >> opcao;

    return opcao;
}

int main(){
    
    int opcao;

do{
    menu();
  
    opcao = getOpcao(); // tem que ser assim senao o while nao reconhece a opcao de sair

    switch (opcao){
    case 1: //adicionar
        
        break;

    case 2://consultar
        
        break;

    case 3://alterar
       
        break;

    case 4://eliminar

        break;
        
    case 5://sair

        break;

    default:
        break;
    }

}while (opcao !=0);

    return 0;
}
