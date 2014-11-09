//Biblioteca C++
#include <iostream>
//Biblioteca C
#include <stdio.h>
#include <stdlib.h>

struct Nodafila
{
    struct Nodafila *anterior;
    int dados;
    struct Nodafila *proximo;

    Nodafila(int d, Nodafila* p, Nodafila* a)
    {
        dados = d;
        proximo = p;
        anterior = a;
    }
    Nodafila() {}


};

/**Função responsável por inserir elementos no inicio da fila*/
void incluirnoinicio(struct Nodafila **i, struct Nodafila **f)
{
    int dados;
    std::cout << "Digite o valor :"<<std::endl;
    std::cin >> dados;
    Nodafila* novoNodafila = new Nodafila(dados, NULL, NULL), aux;
    if(*i!=NULL)
    {
        novoNodafila->anterior = NULL;
        novoNodafila->proximo = *i;
        //*i = novoNodafila;
        aux = **i;
        aux.anterior = novoNodafila;
        **i = aux;
        *i = novoNodafila;
    };
    if(*i==NULL)
    {
        *f = novoNodafila;
        *i = novoNodafila;
        novoNodafila->anterior = NULL;
        novoNodafila->proximo = NULL;
    };
    std::cout << "Valor endereço inicio: " << *i;
    std::cout << "\nValor endereço Final: " << *f << "\n";
}

/**Função responsável por inserir elementos no final da fila*/
void incluirnofinal(struct Nodafila **i, struct Nodafila **f)
{
    int dados;
    std::cout << "Digite o valor :"<<std::endl;
    std::cin >> dados;
    Nodafila* novoNodafila = new Nodafila(dados, NULL, NULL), aux;

    if(*f!=NULL)
    {
        novoNodafila->anterior = *f;
        novoNodafila->proximo = NULL;
        aux = **f;
        aux.proximo = novoNodafila;
        **f = aux;
        *f = novoNodafila;
    };
    if(*f==NULL)
    {
        *f = novoNodafila;
        *i = novoNodafila;
        novoNodafila->anterior = NULL;
        novoNodafila->proximo = NULL;
    };
    std::cout << "Valor endereço inicio: " << *i;
    std::cout << "\nValor endereço Final: " << *f << "\n";
}

/**Função responsável por Remover elementos do inicio da fila*/
void removerdoinicio(Nodafila **i)
{
    Nodafila* aux = *i;

    if(*i==NULL)
    {
        printf("Nao existem elementos para serem removidos na lista");
    }
    else
    {
        *i = aux->proximo;
        aux->anterior = NULL;
        free(aux);
    }
}

/**Função responsável por Remover elementos do final da fila*/
void removerdofinal(Nodafila **f)
{
    Nodafila* aux = *f;

    if(*f==NULL)
    {
        printf("Nao existem elementos para serem removidos na lista");
    }
    else
    {
        *f = aux->anterior;
        if(aux->anterior!=NULL)
            aux->anterior->proximo = NULL;
        delete aux;
        //printf("aux %d ", aux);
    }

}

/**Função responsável por imprimir a lista na tela.*/
void imprimirlista(struct Nodafila **i, struct Nodafila **f)
{
    int contador = 1;
    Nodafila nodafilatemp, nodafilatemp2, *nodafilatemp3;
    nodafilatemp = **i;
    nodafilatemp2 = **f;
    nodafilatemp3 = *i;
    if(nodafilatemp3!=NULL){
            while(nodafilatemp.proximo!=NULL)
    {
        std::cout << "================================\n";
        std::cout << "Endereço " << contador << ": " << nodafilatemp3 ;
        std::cout << "\nDados:" << nodafilatemp.dados << "\n\n";
        std::cout << "================================\n";
        nodafilatemp = *(nodafilatemp.proximo);
        nodafilatemp3 = nodafilatemp.proximo;
        contador++;
    }
    std::cout << "Endereço " << contador << ": " << nodafilatemp3 ;
    std::cout << "\nDados:" << nodafilatemp2.dados << "\n\n";
    std::cout << "================================\n\n";
    }
    else
    {
        std::cout << "Lista Vazia!";
    }


}
/**Função Principal Main*/
int main(int argc, char * argv[])
{
    struct Nodafila *iniciolista = NULL, *finallista = NULL;
    int op;
    std::cout << "OPCOES: \n" << "1 - Inserir no Inicio; \n" << "2 - Inserir no Final; \n" << "3 - Excluir do Inicio; \n" << "4 - Excluir do final; \n" << "5 - Imprimir a Lista.\n" << "0 - Encerrar o Programa.\n";
    std::cin >> op;
    while (op != 0)
    {

        switch (tolower(op))
        {
        case 1:
            std::cout << "Inserir no Inicio: \n";
            incluirnoinicio(&iniciolista,&finallista);
            break;
        case 2:
            std::cout << "Inserir no Final: \n";
            incluirnofinal(&iniciolista,&finallista);
            break;
        case 3:
            std::cout << "Remove do Inicio: \n";
            removerdoinicio(&iniciolista);
            break;
        case 4:
            std::cout << "Remove do Final: \n";
            // printf("\nfinal %d\n",finallista);
            removerdofinal(&finallista);
            break;
        case 5:
            std::cout << "Imprimir Lista: \n";
            imprimirlista(&iniciolista,&finallista);
            break;
        default:
            std::cout << "Opcao Invalida!\n";
            break;
        }
        std::cout << "OPCOES: \n" << "1 - Inserir no Inicio; \n" << "2 - Inserir no Final; \n" << "3 - Excluir do Inicio; \n" << "4 - Excluir do final; \n" << "5 - Imprimir a Lista;\n" << "0 - Encerrar o Programa.\n";
        std::cin >> op;
    }

    /*
        std::cout << "Inicio Endereço: " << iniciolista;
        std::cout << "\nDados:" << iniciolista->dados;
        std::cout << "\nFinal Endereço: " << finallista;
        std::cout << "\nDados:" << finallista->dados;
    */



    return 0;
}


