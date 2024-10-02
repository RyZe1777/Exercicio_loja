#include <iostream>
#include <fstream> //biblioteca para ler (ifstream) // para criar e escrever (ofstream) ficheiros
#include <sstream> //getline
 
using namespace std;

struct Produto
{
    int id;
    char status; // A -> ativo / D -> eliminado
    string nome;
    float preco;
    int quantidade;
};
//--------------------------------------------------------------------------------------------------------------------
Produto produtos[150]; // array com 150 index's
int quantidadeAtual = 0; // mantem controlo da quantidade atual dos produtos adicionados no array
int ultimoIDutilizado = 0; // vai manter controlo do ID de cada produto
//---------------------------------------------------------------------------------------------------------------------
void menu(){
    system("clear");
    cout << "\n==========================" <<endl;
    cout << "          MENU" <<endl;
    cout << "==========================" <<endl;
    cout << "1-Adicionar Produto" <<endl;
    cout << "2-Consultar Produto" <<endl; 
    cout << "3-Alterar Produto" <<endl;
    cout << "4-Eliminar Produto" <<endl;
    cout << "5-SAIR" <<endl;
    cout << "==========================" << endl;

}

int getOpcao(){
    int opcao;
    cout << "Digite a sua opcao: " <<endl;
    cin >> opcao;

    return opcao;
}

//-------------------------------------------------------------------------------------------

void adicionarProdutoDB(Produto produtos[], int quantidadeAtual){ //pronto
    ofstream ficheiro("Database.csv"); // estamos a guardar dados no ficheiro Database.csv


    if(ficheiro.is_open()){
    for(int x = 0; x < quantidadeAtual; x ++){
        ficheiro << produtos[x].id << "," 
                 << produtos[x].nome << ","
                 << produtos[x].preco << ","
                 << produtos[x].quantidade << ","
                 << produtos[x].status <<endl;
    }
    ficheiro.close(); //fecha o ficheiro garantindo que esta td guardado em condiçoes
    }
}
//----------------------------------------------------------------------------------------
void adicionarProduto(Produto produtos[], int& quantidadeAtual, int& ultimoIDutilizado){ //pronto
    
    produtos[quantidadeAtual].id = ++ultimoIDutilizado; // fazemos uma encrementaçao para adicionar o ID a cada produto 
    
    cout << "\nQual o Nome do Produto: " << endl;
    cin.ignore(); //limpa o ENTER a seguir do cin e premite q o getline funcione
    getline(cin,produtos[quantidadeAtual].nome); //vai ler o cin e possibilita a escrita de um nome com espaços
    
    cout << "Qual o Preço do Produto: " <<endl ;
    cin >> produtos[quantidadeAtual].preco; 

    cout << "Qual a Quantidade do Produto: " <<endl;
    cin >> produtos[quantidadeAtual].quantidade; 
    
    produtos[quantidadeAtual].status = 'A';

    quantidadeAtual++;
    
    adicionarProdutoDB(produtos,quantidadeAtual); //invocaçao da funçao superior para elas funcionarem ao mesmo tempo
    
    cout << "\nProduto Adicionado Com Sucesso!" <<endl;

}
//-----------------------------------------------------------------------------------------
void modificarProduto(Produto produtos[], int quantidadeAtual){ //pronto
    
    int id;
    cout << "\nQual o ID do produto que deseja Modificar: " <<endl;
    cin >> id;
    
    for(int x = 0; x < quantidadeAtual; x++){
        
        if(id == produtos[x].id){ //igualar o id ao id do array produtos 
    
            cout << "Qual o Novo Preço do Produto: " <<endl ;
            cin >> produtos[x].preco;

            cout << "Qual a Nova Quantidade do Produto: " <<endl;
            cin >> produtos[x].quantidade;
        
            adicionarProdutoDB(produtos,quantidadeAtual);
        
        }
    }
}
//-----------------------------------------------------------------------------------------
void eliminarProduto(Produto produtos[], int quantidadeAtual){ //pronto
    
    int id;
    cout << "\nQual o ID do produto que deseja Excluir: " <<endl;
    cin >> id;
    
    for(int x = 0; x < quantidadeAtual; x++){
        
        if(id == produtos[x].id){ //igualar o id ao id do array produtos
            
            produtos[x].status = 'D'; //automaticamente muda o status para D
            
            adicionarProdutoDB(produtos,quantidadeAtual);
            
            cout << "O Produto Foi Excluido com Sucesso!" <<endl;
        }
        
    }
    
}
//------------------------------------------------------------------------------------------
void consultarProduto(Produto produtos[], int quantidadeAtual){ //pronto
    
    if(quantidadeAtual == 0){
        
        cout << "\nNenhum Produto encontrado";
    }
    
    for(int x = 0; x < quantidadeAtual; x++){
        
        cout << "\nO ID do Produto é: " << produtos[x].id << endl;
        cout << "O Nome do Produto é: " << produtos[x].nome << endl;
        cout << "O Preco do Produto é " << produtos[x].preco << endl;
        cout << "A Quantidade do Produto é: " << produtos[x].quantidade << endl;
        cout << "O Status do Produto é: " <<produtos[x].status << endl;
    }
}

//-----------------------------------------------------------------------------------------
int main(){
    
    int opcao;

do{
    menu();
  
    opcao = getOpcao(); // tem que ser assim senao o while nao reconhece a opcao de sair

    switch (opcao){
        
    case 1: //adicionar
        adicionarProduto (produtos,quantidadeAtual, ultimoIDutilizado);
        break;

    case 2://consultar
        consultarProduto(produtos,quantidadeAtual);
        break;

    case 3://alterar
       modificarProduto(produtos,quantidadeAtual);
        break;

    case 4://eliminar
        eliminarProduto(produtos,quantidadeAtual);
        break;
        
    case 5://sair
        cout << "\n Saindo do Programa (freaky....)" <<endl;
        break;

    default:
        break;
    }

}while (opcao !=5);

    return 0;
}
