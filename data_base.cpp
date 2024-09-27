#include <iostream>
#include <fstream> //biblioteca para ler (ifstream) // para criar e escrever (ofstream) ficheiros
 
using namespace std;

struct Produto
{
    int id;
    char status; // A -> ativo / D -> eliminado
    string nome;
    float preco;
    int quantidade;
};

int criar_DataBase(){
    
    int escolha;
    ifstream ficheiro("Database.csv"); //variavel do tipo ifstream com o nome de ficheiro //Database é nome do arquivo que vamos usar para guardar os dados
    
    //se ja tivermos uma database
    if (ficheiro){ 
        cout << "Ja tens uma Base de Dados criada" <<endl;
    //senao tivermos uma database
    }else{
        cout << "Deseja criar um nova Base de Dados?" <<endl;
        cout << "1 - Sim" <<endl;
        cout << "2 - Nao" <<endl;
        cin >> escolha;
        
        if (escolha == 1){
            ofstream ficheiro_1("Database.csv"); //variavel do tipo ifstream com o nome de ficheiro_1
            if(ficheiro_1){
                cout<< "A sua Base de Dados foi criada com sucesso!" <<endl;
            }else{
                cout << "Ocorreu um erro na Criação da sua Base de Dados" <<endl;
            }
        }else if(escolha == 2){
            return 0;
        }
    }
}





void menu(){
    system("clear");
    cout << "\n==========================" <<endl;
    cout << "          MENU" <<endl;
    cout << "==========================" <<endl;
    cout << "1-Adicionar Produto" <<endl;
    cout << "2-Consultar Produto" <<endl; //penso que ja esteja pronto not sure
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
        criar_DataBase; // maybe posiçao errada
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
