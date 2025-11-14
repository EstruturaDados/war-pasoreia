// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO


// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

#define TAM_STRING  100
#define MAX_TROPAS  5


// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio{
    char nome[30];
    char cor[10];
    int tropas;
    int forca;
};


// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.


void atacar(struct Territorio* atacante, struct Territorio* defensor){
    int dadoAtacante = rand() % 6 + 1 ;
    int dadoDefensor = rand() % 6 + 1;

    printf("O Atacante %s rolou o dado, e tirou: %d\n",atacante -> nome, dadoAtacante);
    printf("O defensor %s rolou o dado, e tirou: %d\n", defensor -> nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor){
        if (defensor->tropas > 0) {
            defensor->tropas--;
        }

        printf("Atacante %s venceu!! Tropas do defensor: %d\n", atacante->nome, defensor->tropas);

        if (defensor->tropas == 0) {
            strcpy(defensor->cor, atacante->cor);
            if (atacante->tropas > 1) {
                atacante->tropas--;
                defensor->tropas = 1; 
            }
            

            printf("Território conquistado por %s!\n", atacante->cor);
        }
    } else {
        if (atacante->tropas > 0 ) {
            atacante->tropas--;
        }

        printf("Defensor %s venceu, tropas do atacante restantes: %d\n", defensor->nome, atacante->tropas);

    
        
    }

    printf("=================\n");
       

   
}




// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.

void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);

}

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {

    

     
    

    int opcao;
    struct Territorio* t = malloc( MAX_TROPAS * sizeof(struct Territorio));
    if(t == NULL){
        printf("Erro ao alocar memória!!.\n");
    }
    int totalTropas = 0;
    int indiceDefensor;
    int indiceAtacante;
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    srand(time(NULL));
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
        printf("================\n");
        for(int i = 0; i < 5; i++){

            //cadastrando nome das tropas
            printf("---Cadastrando o território %d ---\n", i + 1);
            printf("Nome do território: \n");
            scanf("%s", t[i].nome);


            //cadastrando cor dos exercitos
            printf("Cor das tropas: \n");
            scanf("%s", t[i].cor);

            //cadastrando numero das tropas
            printf("Número de tropas: \n");
            scanf("%d", &t[i].tropas);

            limparBufferEntrada();

            printf("===================\n");

            
             }

             printf("----MAPA MUNDO ATUAL---- \n");

             for(int  i = 0; i < MAX_TROPAS; i++){
                printf( "%d. %s (Exército %s, Tropas: %d)\n", i + 1, t[i].nome, t[i].cor, t[i].tropas);
              
             }

            



    // - Define a cor do jogador e sorteia sua missão secreta.


    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.
            do{
        printf("===ESCOLHA UMA OPÇÃO!===\n");
        printf("1 - Iniciar fase de ataque.\n");
        printf("2 - Verificar quem venceu.\n");
        printf("0 - Encerrar jogo.\n");
        scanf("%d", &opcao);
        limparBufferEntrada();
        

        switch (opcao){
        case 1:
        while(1){
            printf("Escolha um território atacante de 1 a 5, (aperte 0 para sair)\n");
            
            scanf("%d", &indiceAtacante);
            limparBufferEntrada();
            printf("Escolha um território de 1 a 5 para se defender\n");

            if(indiceAtacante == 0) break;
            
            scanf("%d", &indiceDefensor );
            limparBufferEntrada();

            if(indiceDefensor == 0) break;

            

            if(indiceAtacante == indiceDefensor){
                printf("Vocês escolheram o mesmo território\n");
                continue;;
            }

            if(indiceAtacante < 1 || indiceAtacante > 5 || indiceDefensor < 1 || indiceDefensor> 5){
                printf("Opção inválida, escolha de 1 a 5 seu território.\n");
                continue;;
            }

            atacar(&t[indiceAtacante - 1], &t[indiceDefensor - 1]);

            printf("----MAPA MUNDO ATUAL---- \n");
              for(int  i = 0; i < MAX_TROPAS; i++){

                printf( "%d. %s (Exército %s, Tropas: %d)\n", i + 1, t[i].nome, t[i].cor, t[i].tropas);
               
              
             }
             printf("==================\n");
             printf("Aperte [ENTER] para continuar... \n");
             getchar();
             
            
           
        }

        break;

        case 2: 
            printf("=====Verificação dos status=====\n");
            printf("==============\n");
            if(t -> tropas == 0){
                printf("O vencedor do jogo foi o %s \n", t[0].cor);
            }else{
                printf("Ainda existem territórios ocupados, volte a jogar!.\n");
            }

            printf("=================\n");
            printf("Aperte [ENTER] para continuar..\n");
            getchar();           
            break;


        case 0: 
            printf("Saindo jogo....\n");
            break;
            
             
        default:
            printf("Opção inválida escolha novamente!!\n");
            break;
        }

      

           


        

    }while (opcao != 0);
    
      

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.
    free(t);
    

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.

// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.




// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

