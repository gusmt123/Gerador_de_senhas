//inclui bibliotecas usadas no projeto
#include <iostream>
#include <random>
#include <limits>

    //array constante que tem todos os caracteres especiais, letras maiusculas e minusculas e números
const char caracteres[] = {
    ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', 
    ':', ';', '<', '=', '>', '?', '@', 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

char nums[] = {'0', '1','2','3','4','5','6','7','8','9'};

char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";

char caracteres_Especiais[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

char letras_Maiusculas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


void lida_Com_Respostas_Invalidas();

std::string gera_Senha_Numerica(int& n);

std::string gera_Senha_Letras_Numeros_Talvez_Especiais(int& n);

std::string gera_Senha_Sem_Criterios(int& n);

//Gera senha númerica
std::string gera_Senha_Numerica(int& n)
{
    
    std::string senha;

    //cria uma instância da classe random_device que serve para usar a situação do hardware para gerar números aleatórios chamda rd
    std::random_device rd;

    //cria uma instancia da classe mt19937 que contém o algoritimo para gerar números aleatórios
    std::mt19937 gerador_numeros(rd());

    //loopa até dar o número de caracteres desejado pelo usuário
    for(int i = 0; i < n; i++)
    {

        //define a distribuição entre 1 e o tamanho do array com os caracteres
        std::uniform_int_distribution<> distribuicao(0,sizeof(nums)-1);

        //armazena o número aleatório na variável opcao_pc
        char caracter = nums[distribuicao(gerador_numeros)];

        //adiciona um novo caracter à senha
        senha = senha + caracter;

    }

    //retorna a senha
    return senha;

}

std::string gera_Senha_Letras_Numeros_Talvez_Especiais(int& n)
{

    std::string senha;
    bool tem_letra_maiuscula = false;
    bool tem_letra_minuscula = false;
    bool tem_numero = false;

    //loopa até que a senha tenha letras maiusculas e minusculas, números e caracteres especiais
    while(!(tem_letra_minuscula && tem_numero && tem_letra_maiuscula))
    {
        //gera a senha
        senha = gera_Senha_Sem_Criterios(n);

        //loopa para cada caracter na senha
        for (int i = 0; i < n ; i++) 
        {
            if (std::isupper(senha[i]))
            {
                tem_letra_maiuscula = true;
            }
            if (std::islower(senha[i])) 
            {
                tem_letra_minuscula = true;
            }
            if (std::isdigit(senha[i])) 
            {
                tem_numero = true;
            }
            
        }

    }

    
        //retorna a senha
        return senha;

}

//função que gera as senhas, ela recebe o parametro n que é o número de caracteres na senha
std::string gera_Senha_Sem_Criterios(int& n)
{



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

void lida_Com_Respostas_Invalidas()
{
    //limpa o buffer de entrada
    std::cin.clear();

    //ignora a próxima linha
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    //Constroi o menu
    INICIO_MENU: std::cout << "Digite o tamanho da senha:" << std::endl;
    int tamanho_senha;
    std::cin >> tamanho_senha;

    if(std::cin.fail())
    {
  
        lida_Com_Respostas_Invalidas();
  
    }
    else
    {
        //armazena o tipo de senha
        std::cout << "Digite uma opcao:" << std::endl;
        std::cout << "1. Senha numerica" << std::endl;
        std::cout << "2. Senha aleatoria" << std::endl;
        std::cout << "3. Senha com letras e numeros" << std::endl;
        char tipo_senha;
        std::cin >> tipo_senha;

        if(std::cin.fail() || tipo_senha < '1' || tipo_senha > '3')
        {
            lida_Com_Respostas_Invalidas();
        }
        else
        {
            if(tipo_senha == '1')
            {
                std::cout << gera_Senha_Numerica(tamanho_senha) << std::endl;
                
            }
            else if(tipo_senha == '2')
            {
                std::cout << gera_Senha_Sem_Criterios(tamanho_senha) << std::endl;
            }
            else if(tipo_senha == '3')
            {
                if(tamanho_senha > 4)
                {
                    std::cout << gera_Senha_Letras_Numeros_Talvez_Especiais(tamanho_senha) << std::endl;
                }
                else
                {
                    std::cout << "Caso queira uma senha com letras e numeros digite peca por uma senha com mais digios" << std::endl;
                    goto INICIO_MENU;
                }
            }
            else
            {
                std::cout << "Digite uma opcao valida:" << std::endl;
            }
            }
        }
    }

