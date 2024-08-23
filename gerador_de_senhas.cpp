//inclui bibliotecas usadas no projeto
#include <iostream>
#include <random>
#include <limits>


//função que gera as senhas, ela recebe o parametro n que é o número de caracteres na senha
std::string gera_senha(int n)
{

    //array constante que tem todos os caracteres especiais, letras maiusculas e minusculas e números
    const char caracteres[] = {
        ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', 
        ':', ';', '<', '=', '>', '?', '@', 
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };

    //cria a variável que vai armazenar a senha
    std::string senha;

        //cria uma instância da classe random_device que serve para usar a situação do hardware para gerar números aleatórios chamda rd
    std::random_device rd;

    //cria uma instancia da classe mt19937 que contém o algoritimo para gerar números aleatórios
    std::mt19937 gerador_numeros(rd());

    //loopa até dar o número de caracteres desejado pelo usuário
    for(int i = 0; i < n; i++)
    {

        //define a distribuição entre 1 e o tamanho do array com os caracteres
        std::uniform_int_distribution<> distribuicao(0,sizeof(caracteres)-1);

        //armazena o número aleatório na variável opcao_pc
        char caracter = caracteres[distribuicao(gerador_numeros)];

        //adiciona um novo caracter à senha
        senha = senha + caracter;

    }

    //retorna a senha
    return senha;


}

int main()
{
    //Controi o menu
    std::cout << "Digite o tamanho da senha:" << std::endl;
    int tamanho_senha;
    std::cin >> tamanho_senha;

    if(std::cin.fail())
    {
  
            //limpa o buffer de entrada
            std::cin.clear();

            //ignora a próxima linha
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
    }
    else
    {
        std::cout << gera_senha(tamanho_senha);
    }

}