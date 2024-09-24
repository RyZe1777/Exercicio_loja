#include <iostream>
using namespace std;

struct Produto
{
    string nome;
    float preco;
    int quantidade;
};

Produto produtos[150]; // array com 150 index's
int quantidadeAtual = 0 // mantem controlo da quantidade atual dos produtos adicionados no array

void menu(){
    system("clear");
    cout << "\n==========================" <<endl;
    cout << "          MENU" <<endl;
    cout << "==========================" <<endl;
    cout << "1-Adicionar Produto" <<endl;
    cout << "2-Exibir Produto" <<endl;
    cout << "3-Calcular Valor total de Stock" <<endl;
    cout << "0-SAIR" <<endl;
    cout << "==========================" << endl;

}

int getOpcao(){
    int opcao;
    cout << "Digite a sua opcao: ";
    cin >> opcao;

    return opcao;
}

void adicionarProduto(Produto produtos[], int& quantidadeAtual){
    cout << "Qual o Nome do Produto: " << endl;
    cin >> produtos[quantidadeAtual].nome; 
    
    cout << "Qual o Preço do Produto: " <<endl ;
    cin >> produtos[quantidadeAtual].preco;

    cout << "Qual a Quantidade do Produto: " <<endl;
    cin >> produtos[quantidadeAtual].quantidade;

    quantidadeAtual++;
    
    cout << "\nProduto Adicionado Com Sucesso!" <<endl;
}

void exibirProduto(const Produto produtos[], int quantidadeAtual){
    if (quantidadeAtual== 0){
        cout << "\n Nenhum Produto Encontrado" <<endl;
    }else{
        cout << "==========================" <<endl;
        cout << "  Lista de Produtos" <<endl;
        for (int x = 0; x < quantidadeAtual; x++){
            cout << "\nProduto: " << x + 1 <<endl; //metemos x+1 pa começar a contar do 1
            cout << "Nome: " << produtos[x].nome <<endl; //metemos produtos[x] para este ter uam referencia no array 
            cout << "Preço: " << produtos[x].preco <<endl;
            cout << "Quantidade: " << produtos[x].quantidade <<endl;
            cout << "==========================" <<endl;
        }   
    }
}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual){
    float total = 0;
    for(int x = 0; x < quantidadeAtual; x++){
        total += produtos[x].preco * produtos[x].quantidade; //total do stock total
    }
    return total;
}

int main(){
    
int opcao;

do{
    menu();
  
    opcao = getOpcao(); // tem que ser assim senao o while nao reconhece a opcao de sair

    switch (opcao){
    case 1: 
        adicionarProduto(produtos,quantidadeAtual);
        break;

    case 2:
        exibirProduto(produtos,quantidadeAtual);
        break;

    case 3:
        cout << "\nValor total é: " << calcularValorTotal(produtos,quantidadeAtual) << "€";
        break;

    case 0:
        cout <<"\n Fechando o Programa....." <<endl;
        break;

    default:
        break;
    }

}while (opcao !=0);

    return 0;
}
