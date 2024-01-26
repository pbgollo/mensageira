#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
/*---------------------------------------------------------------*/
struct mensagem {
    int idEmissor;
    char conteudo[256];
    struct mensagem *prox;
};
typedef struct mensagem Mensagem;

struct elemento{
    int id;
    char nome[100];
    struct elemento *prox;
    struct elemento *ant;
    Mensagem* filaMensagens;
};
typedef struct elemento Elemento;

struct header{
    Elemento *inicioEmissores;
    Elemento *inicioReceptores;
    Elemento *finalEmissores;
    Elemento *finalReceptores;
} h;

bool primeiro = true;
/*---------------------------------------------------------------*/
void printaBemVindo(){
    printf("━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━\n");
    printf("╭━━╮╱╱╱╱╱╱╱╱╱╱╱╱╱╭╮╱╱╭╮╱╱╱╱╱╱╱╱╭╮╱╱╱╱\n");
    printf("┃╭╮┃╱╱╱╱╱╱╱╱╱╱╱╱╱┃╰╮╭╯┃╱╱╱╱╱╱╱╱┃┃╱╱╱╱\n");
    printf("┃╰╯╰╮╭━━╮╭╮╭╮╱╱╱╱╰╮┃┃╭╯╭╮╭━━╮╭━╯┃╭━━╮\n");
    printf("┃╭━╮┃┃┃━┫┃╰╯┃╭━━╮╱┃╰╯┃╱┣┫┃╭╮┃┃╭╮┃┃╭╮┃\n");
    printf("┃╰━╯┃┃┃━┫┃┃┃┃╰━━╯╱╰╮╭╯╱┃┃┃┃┃┃┃╰╯┃┃╰╯┃\n");
    printf("╰━━━╯╰━━╯╰┻┻╯╱╱╱╱╱╱╰╯╱╱╰╯╰╯╰╯╰━━╯╰━━╯\n");
    printf("╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱\n");
    printf("━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━═━\n");   
}
/*---------------------------------------------------------------*/
void printaDivisao(){
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}
/*---------------------------------------------------------------*/
int pegaOpcaoPrincipal(){
    int opcaoPrincipal;
    
    if (primeiro){
        primeiro = false;
    }
    else{
        printaDivisao();
    }
    
    printf("> Menu Principal:\n");
    printf("  [1] Gerenciar Emissores\n");
    printf("  [2] Gerenciar Receptores\n");
    printf("  [3] Gerenciar Mensagens\n");
    printf("  [4] Relatórios\n");
    printf("  [0] Sair\n");
    printf("\n");
    printf("> Escolha uma opção: ");
    scanf("%d", &opcaoPrincipal);
    return opcaoPrincipal;
}
/*---------------------------------------------------------------*/
int pegaOpcaoEmissor(){
    int opcaoEmissor;
    printaDivisao();
    printf("> Menu Principal\n");
    printf("  > Menu de Emissores:\n");
    printf("    [1] Incluir emissor\n");
    printf("    [2] Remover emissor\n");
    printf("    [3] Consultar emissores\n");
    printf("    [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opção: ");
    scanf("%d", &opcaoEmissor);
    return opcaoEmissor;
}
/*---------------------------------------------------------------*/
int pegaOpcaoReceptor(){
    int opcaoReceptor;
    printaDivisao();
    printf("> Menu Principal\n");
    printf("  > Menu de Receptores:\n");
    printf("    [1] Incluir receptor\n");
    printf("    [2] Remover receptor\n");
    printf("    [3] Consultar receptores\n");
    printf("    [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opção: ");
    scanf("%d", &opcaoReceptor);
    return opcaoReceptor;
}
/*---------------------------------------------------------------*/
int pegaOpcaoMensagem(){
    int opcaoMensagem;
    printaDivisao();
    printf("> Menu Principal\n");
    printf("  > Menu de Mensagens:\n");
    printf("    [1] Enviar mensagem\n");
    printf("    [2] Retirar mensagem\n");
    printf("    [3] Consultar fila de mensagens\n");
    printf("    [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opção: ");
    scanf("%d", &opcaoMensagem);
    return opcaoMensagem;
}
/*---------------------------------------------------------------*/
int pegaOpcaoRelatorios(){
    int opcaoRelatorios;
    printaDivisao();
    printf("> Menu Principal\n");
    printf("  > Menu de Relatórios:\n");
    printf("    [1] Relatório Geral\n");
    printf("    [2] Exibir receptores com a fila vazia\n");
    printf("    [3] Quantidade de mensagens enviadas por emissor\n");
    printf("    [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opção: ");
    scanf("%d", &opcaoRelatorios);
    return opcaoRelatorios;
}
/*---------------------------------------------------------------*/
void menuPrincipal(){
    int opcaoPrincipal;
    
    do {
        opcaoPrincipal = pegaOpcaoPrincipal();

        switch(opcaoPrincipal){
            case 0:
                break;
            case 1:
                menuEmissor();
                break;
            case 2:
                menuReceptor();
                break;
            case 3:
                menuMensagem();
                break;
            case 4:
                menuRelatorios();
                break;
            default:
                printf("> Opção inválida!\n");
        }
    } while (opcaoPrincipal != 0);

    printf("> Programa finalizado com sucesso!\n");
    printaDivisao();
}
/*---------------------------------------------------------------*/
void menuEmissor(){
    int opcaoEmissor;
    
    do {
        opcaoEmissor = pegaOpcaoEmissor();

        switch (opcaoEmissor) {
            case 0:
                break;
            case 1:
                incluirEmissor();
                break;
            case 2:
                removerEmissor();
                break;
            case 3:
                consultarEmissor();
                break;
            default:
                printf("> Opção inválida!\n");
        }
    } while (opcaoEmissor != 0);
}
/*---------------------------------------------------------------*/
void menuReceptor(){
    int opcaoReceptor;
    
    do {
        opcaoReceptor = pegaOpcaoReceptor();

        switch(opcaoReceptor){
            case 0:
                break;
            case 1:
                incluirReceptor();
                break;
            case 2:
                removerReceptor();
                break;
            case 3:
                consultarReceptor();
                break;
            default:
                printf("> Opção inválida!\n");
        }
    } while (opcaoReceptor != 0);
}
/*---------------------------------------------------------------*/
void menuMensagem(){
    int opcaoMensagem;
    
    do {
        opcaoMensagem = pegaOpcaoMensagem();

        switch(opcaoMensagem){
            case 0:
                break;
            case 1:
                enviarMensagem();
                break;
            case 2:
                retirarMensagem();
                break;
            case 3:
                consultarFilaMensagem();
                break;
            default:
                printf("> Opção inválida!\n");
        }
    } while (opcaoMensagem != 0);
}
/*---------------------------------------------------------------*/
void menuRelatorios(){
    int opcaoRelatorios;
    
    do {
        opcaoRelatorios = pegaOpcaoRelatorios();

        switch (opcaoRelatorios) {
            case 0:
                break;
            case 1:
                mostrarRelatorioGeral();
                break;
            case 2:
                exibirReceptoresComFilaVazia();
                break;
            case 3:
                quantidadeMensagensPorEmissor();
                break;
            default:
                printf("> Opção inválida!\n");
        }
    } while (opcaoRelatorios != 0);
}
/*---------------------------------------------------------------*/
int perguntaId(int tipo) {
    int id;
    if (tipo == 1) {
        printf("> Digite o id do emissor: ");
    } else if (tipo == 2) {
        printf("> Digite o id do receptor: ");
    } else if (tipo == 3) {
        printf("> Digite o id da mensagem: ");
    } else {
        printf("> [0] Confirma\n");
        printf("> Digite o id de um dos receptores: ");
    }
    scanf("%d", &id);
    return id;
}
/*---------------------------------------------------------------*/
void perguntaTexto(int tipo, char *texto, int tamanho) {
    if (tipo == 1) {
        printf("> Digite o nome do emissor: ");
    } else if (tipo == 2) {
        printf("> Digite o nome do receptor: ");
    } else {
        printf("> Digite o conteúdo da mensagem: ");
    }

    fgets(texto, tamanho, stdin);

    size_t len = strlen(texto);
    if (len > 0 && texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
    }
}
/*---------------------------------------------------------------*/
bool validaId(int tipo, int id) {
    Elemento *aux;
    
    if (tipo == 1) {
        aux = h.inicioEmissores;
    } else if (tipo == 2) {
        aux = h.inicioReceptores;
    } 

    while (aux != NULL) {
        if (aux->id == id) {
            return true;
        }
        aux = aux->prox; 
    }
    return false;
}
/*---------------------------------------------------------------*/
void incluirEmissor(){
    
    int id = perguntaId(1);
    getchar();
    if (validaId(1, id)){
        printf("> Já existe um emissor cadastrado com esse id!\n");
        return;
    }  
    
    char nome[100];
    perguntaTexto(1, nome, sizeof(nome));
    
    Elemento *novo;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    novo->ant = NULL;
    
    if(h.inicioEmissores==NULL) { 
        h.inicioEmissores=novo;
        h.finalEmissores=novo;
    }
    else { 
        (h.finalEmissores)->prox = novo;
        novo->ant = h.finalEmissores;
        h.finalEmissores = novo;
    }
    printf("> Emissor cadastrado com sucesso!\n");
}
/*---------------------------------------------------------------*/
void removerEmissor() {
    if (h.inicioEmissores == NULL) {
        printf("> Não existem emissores cadastrados!\n");
        return;
    }

    int id = perguntaId(1);
    Elemento *aux = h.inicioEmissores;
    Elemento *ant = NULL;

    while (aux != NULL && aux->id != id) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("> Emissor não encontrado!\n");
        return;
    }

    if (ant == NULL) {
        h.inicioEmissores = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    free(aux);
    printf("> Emissor removido com sucesso!\n");
}
/*---------------------------------------------------------------*/
void consultarEmissor(){
    int cont = 0;
    Elemento *aux;
    aux = h.inicioEmissores;
    
    if (aux == NULL){
        printf("> Não existem emissores cadastrados!\n");
    } else {
        printf("> Lista de emissores:\n");
        while(aux != NULL){
            printf("  (%d) %s\n", aux->id, aux->nome);
            aux = aux->prox;
            cont++;
        }
        printf("> Existem %d emissores!\n", cont);
    }
}
/*---------------------------------------------------------------*/
void incluirReceptor(){
    
    int id = perguntaId(2);
    getchar();
    
    if (validaId(2, id)){
        printf("> Já existe um receptor cadastrado com esse id!\n");
        return;
    }  
    
    char nome[100];
    perguntaTexto(2, nome, sizeof(nome));
    
    Elemento *novo;
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    novo->ant = NULL;
    
    if(h.inicioReceptores==NULL) {
        h.inicioReceptores=novo;
        h.finalReceptores=novo;
    }
    else { //inserção ao final da lista
        (h.finalReceptores)->prox = novo;
        novo->ant = h.finalReceptores;
        h.finalReceptores = novo;
    }
    printf("> Receptor cadastrado com sucesso!\n");
}
/*---------------------------------------------------------------*/
void removerReceptor(){
    if (h.inicioReceptores == NULL) {
        printf("> Não existem receptores cadastrados!\n");
        return;
    }

    int id = perguntaId(2);
    Elemento *aux = h.inicioReceptores;
    Elemento *ant = NULL;

    while (aux != NULL && aux->id != id) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("> Receptor não encontrado!\n");
        return;
    }

    if (ant == NULL) {
        h.inicioReceptores = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    free(aux);
    printf("> Receptor removido com sucesso!\n");
}
/*---------------------------------------------------------------*/
void consultarReceptor(){
    int cont = 0;
    Elemento *aux;
    aux = h.inicioReceptores;
    
    if (aux == NULL){
        printf("> Não existem receptores cadastrados!\n");
    } else {
        printf("> Lista de receptores:\n");
        while(aux != NULL){
            printf("  (%d) %s\n", aux->id, aux->nome);
            aux = aux->prox;
            cont++;
        }
        printf("> Existem %d receptores!\n", cont);
    }
}
/*---------------------------------------------------------------*/
Elemento* encontrarReceptorPorId(int id) {
    Elemento* aux = h.inicioReceptores;
    while (aux != NULL) {
        if (aux->id == id) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL; 
}
/*---------------------------------------------------------------*/
void enviarMensagem() {
    int idEmissor = perguntaId(1);
    getchar();
    
    if (!validaId(1, idEmissor)) {
        printf("> Não existe um emissor cadastrado com esse id!\n");
        return;
    }

    int idReceptor;
    char conteudo[256];
    perguntaTexto(3, conteudo, sizeof(conteudo));

    do {
        idReceptor = perguntaId(4);
        if (idReceptor != 0) {
            if (!validaId(2, idReceptor)) {
                printf("> Não existe um receptor cadastrado com esse id!\n");
            } else {
                printf("> O receptor %d foi adicionado à lista de transmissão!\n", idReceptor);
                Mensagem* novaMensagem = (Mensagem*)malloc(sizeof(Mensagem));
                novaMensagem->idEmissor = idEmissor;
                strcpy(novaMensagem->conteudo, conteudo);
                novaMensagem->prox = NULL;

                Elemento* receptor = encontrarReceptorPorId(idReceptor);
                if (receptor != NULL) {
                    if (receptor->filaMensagens == NULL) {
                        receptor->filaMensagens = novaMensagem;
                    } else {
                        Mensagem* ultimaMensagem = receptor->filaMensagens;
                        while (ultimaMensagem->prox != NULL) {
                            ultimaMensagem = ultimaMensagem->prox;
                        }
                        ultimaMensagem->prox = novaMensagem;
                    }
                } else {
                    printf("> Receptor não encontrado!\n");
                    free(novaMensagem);
                }
            }
        }
    } while (idReceptor != 0);

    printf("> Mensagem enviada para os receptores escolhidos!\n");
}
/*---------------------------------------------------------------*/
void retirarMensagem() {
    int idReceptor = perguntaId(2);
    Elemento *receptor = encontrarReceptorPorId(idReceptor);

    if (receptor == NULL) {
        printf("> Não existe um receptor cadastrado com esse id!\n");
        return;
    }

    Mensagem *mensagemRetirada = receptor->filaMensagens;

    if (mensagemRetirada == NULL) {
        printf("> A fila de mensagens do receptor %d está vazia! Não é possível retirar mensagens!\n", idReceptor);
        return;
    }

    receptor->filaMensagens = mensagemRetirada->prox;

    printf("> Mensagem retirada do receptor %d:\n", idReceptor);
    printf("  [Emissor]: %d\n", mensagemRetirada->idEmissor);
    printf("  [Conteúdo]: %s\n", mensagemRetirada->conteudo);

    free(mensagemRetirada);
}
/*---------------------------------------------------------------*/
void consultarFilaMensagem() {
    int idReceptor = perguntaId(2);
    Elemento *receptor = encontrarReceptorPorId(idReceptor);

    if (receptor == NULL) {
        printf("> Não existe um receptor cadastrado com esse id!!\n");
        return;
    }

    Mensagem* mensagemAtual = receptor->filaMensagens;
    if (mensagemAtual == NULL) {
        printf("> A fila de mensagens do receptor %d está vazia!\n", idReceptor);
    } else {
        int i=1;
        printf("> Fila de mensagens do receptor %d:\n", idReceptor);
        while (mensagemAtual != NULL) {
            printf("  (%d) Emissor %d: %s\n", i, mensagemAtual->idEmissor, mensagemAtual->conteudo);
            mensagemAtual = mensagemAtual->prox;
            i++;
        }
    }
}
/*---------------------------------------------------------------*/
void imprimirDataHoraAtual() {
    time_t tempoAtual;
    struct tm *infoTempo;
    char dataHora[80];
    
    putenv("TZ=America/Sao_Paulo");
    tzset();

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);
    strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", infoTempo);
    
    printf("[%s]\n", dataHora);
}
/*---------------------------------------------------------------*/
void mostrarRelatorioGeral() {
    Elemento* emissorAtual = h.inicioEmissores;
    Elemento* receptorAtual = h.inicioReceptores;

    printf("\n=======================================\n");
    printf("> Relatório Geral ");
    imprimirDataHoraAtual();

    // Percorre e exibe emissores
     printf("\n============ Emissores ================\n");
    while (emissorAtual != NULL) {
        printf("  [Id]: %d [Nome]: %s\n", emissorAtual->id, emissorAtual->nome);
        emissorAtual = emissorAtual->prox;
    }

    printf("\n============ Receptores ===============\n");
    while (receptorAtual != NULL) {
        printf("  [Id]: %d [Nome]: %s\n", receptorAtual->id, receptorAtual->nome);

        Mensagem* mensagemAtual = receptorAtual->filaMensagens;
        if (mensagemAtual != NULL) {
            printf("  - Fila de mensagens:\n");
            int i=1;
            while (mensagemAtual != NULL) {
                printf("    (%d) Emissor: %d, Conteúdo: %s\n", i, mensagemAtual->idEmissor, mensagemAtual->conteudo);
                mensagemAtual = mensagemAtual->prox;
                i++;
            }
        } else {
            printf("  - Nenhuma mensagem na fila\n");
        }
        receptorAtual = receptorAtual->prox;
    }
    printf("\n=======================================\n");
}
/*---------------------------------------------------------------*/
void exibirReceptoresComFilaVazia() {
    Elemento *receptorAtual = h.inicioReceptores;
  
    printf("> Receptores com a fila de mensagens vazia:\n");
    
    while (receptorAtual != NULL) {
        if (receptorAtual->filaMensagens == NULL) {
            printf("  [Id]: %d [Nome]: %s\n", receptorAtual->id, receptorAtual->nome);
        }
        receptorAtual = receptorAtual->prox;
    }
}
/*---------------------------------------------------------------*/
void quantidadeMensagensPorEmissor() {
    Elemento *emissorAtual = h.inicioEmissores;
    Elemento *receptorAtual = h.inicioReceptores;

    printf("> Quantidade de mensagens enviadas por emissor:\n");

    while (emissorAtual != NULL) {
        int idEmissor = emissorAtual->id;
        char nomeEmissor[100];
        strcpy(nomeEmissor, emissorAtual->nome);

        int mensagensEnviadas = 0;

        while (receptorAtual != NULL) {
            Mensagem *mensagemAtual = receptorAtual->filaMensagens;
            while (mensagemAtual != NULL) {
                if (mensagemAtual->idEmissor == idEmissor) {
                    mensagensEnviadas++;
                }
                mensagemAtual = mensagemAtual->prox;
            }
            receptorAtual = receptorAtual->prox;
        }

        printf("  [Id]: %d [Nome]: %s - Mensagens Enviadas: %d\n", idEmissor, nomeEmissor, mensagensEnviadas);

        emissorAtual = emissorAtual->prox;
        receptorAtual = h.inicioReceptores;
    }
}
/*---------------------------------------------------------------*/
int main() {
    
    printaBemVindo();
    
    menuPrincipal();

    return 0;
}
/*---------------------------------------------------------------*/