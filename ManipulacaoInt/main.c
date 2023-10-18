#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Variaveis globais para o tempo
clock_t iniciot, fimt;
double diff;
// tamanho lista sequencial
int countListaSeq, countadorrg = 0, cseq = 0,cenc = 0, mseq = 0,menc = 0;
// Structs para as listas, string para nome e rg
typedef struct
{
    char nome[20];
    char RG[20];
} Pessoa;
// Structs para a lista encadeada, struct para apontar o proximo nó
typedef struct No
{
    Pessoa pessoa;
    struct No *proximo;
} No;
//Structs para apontar o inicio e o fim da lista e o tamanho
typedef struct Lista
{
    struct No *inicio, *fim;
    int tam;
} Lista;
// Função Cria pessoa na hora de inserir um no
Pessoa criarPessoa()
{
    Pessoa pessoa;

    printf("Digite o nome da pessoa\n");
    scanf("%s", pessoa.nome);
    printf("Digite o RG da pessoa\n");
    scanf("%s", pessoa.RG);

    return pessoa;
}
// Função inserir nó no inicio lista encadeada
void inserirInicioEnc(Lista *lista, Pessoa pessoa)
{

    iniciot = clock();
    No *novo = (No *)malloc(sizeof(No));
    novo->pessoa = pessoa;
    //Se o inicio da lista for nulo, quer dizer que a lista é vazia portanto anula-se o proximo e a lista ficara com 1 elemento sendo esse o novo;
    if (lista->inicio == NULL)
    {
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
        menc=2;
        cenc++;
    }
    //Se incio nao for nulo, o novo nó apontara para o inicio da lista e depois o inicio recebera o novo nó que foi a pessoa passada por referencia
    else
    {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        cenc++;
        menc=2;
    }
    lista->tam++;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
// Inserir nó no fim da lista encadeada
void inserirFimEnc(Lista *lista, Pessoa pessoa)
{

    iniciot = clock();
    No *novo = (No *)malloc(sizeof(No));
    novo->pessoa = pessoa;
    novo->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
        cenc++;
    }
    //Caso o inicio nao seja nulo quer dizer que a lista nao e vazia, entao o ponteiro final passa a apontar para o novo nó passado
    else
    {
        lista->fim->proximo = novo;
        lista->fim = novo;
        cenc++;
    }
    lista->tam++;
    menc++;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);

}
// Inserir em uma posição N determinada na lista encadeada
void inserirPosicaoNEnc(Lista *lista, Pessoa pessoa, int posicao)
{
    //Seta um ponteiro anterior apontando para o comeco
    iniciot = clock();
    No *anterior = lista->inicio;
    No *novo = (No *)malloc(sizeof(No)); // Alocação dinamica para defifnir espaço de memoria do ponteiro
    novo->pessoa = pessoa;
    novo->proximo = NULL;

    if (posicao == 1)
    {
        //Passa o comeco para segunda posicao e o inicio passa a ser o novo no
        novo->proximo = anterior;
        lista->inicio = novo;
        cenc++;
        menc=2;
    }
    else
    {
        //Se a posicao nao for 1, roda o laço de repetição até a posicao estabelecida
        for (int i = 1; i < posicao - 1; i++)
        {
            anterior = anterior->proximo;
            printf(" ");//Por algum motivo precisa de um printf para compilar aqui
        }
        //troca para onde os ponteiros apontam para encaixar o novo no na posicao determinada
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
        cenc++;
        menc=2;
    }
    lista->tam++;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
// Remove do Inicio da encadeada
void removerInicioEnc(Lista *lista)
{

    iniciot = clock();
    if (lista->inicio != NULL)
    {
        cenc++;
        No *no = lista->inicio;
        //O inicio passa a apontar para o proximo assim elimitando o inicio da lista
        lista->inicio = no->proximo;
        lista->tam--;
        menc=2;
        if (lista->inicio == NULL)
        {
            lista->fim = NULL;
            cenc++;
        }
    }
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

//Remove um No especifico
void removerPosicaoNEnc(Lista *lista, int posicao)
{

    iniciot = clock();
    No *anterior = lista->inicio;
    No *noARemover = NULL;

    //Se quiser remover o inicio da lista, o ponteiro que remove, vai ser anterior que recebeu inicio, e o inicio apontara para o proximo
    if (posicao == 1)
    {

        cenc++;
        noARemover = anterior;
        lista->inicio = anterior->proximo;
        menc=2;
    }
    //Se nao, percorre ate a posicao N desejada e entao o ponteiro remove o proximo que seria o N desejado, e trocando o lugar para que a posicao apontara agora
    else
    {
        cenc++;
        for (int i = 1; i < posicao - 1; i++)
        {
            anterior = anterior->proximo;
        }
        printf(" ");
        noARemover = anterior->proximo;
        anterior->proximo = noARemover->proximo;
        menc=2;
    }

    //um free para liberar o espaço e limpa o ponteiro
    if (noARemover)
    {
        cenc++;
        free(noARemover);
        lista->tam--;
    }
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
    //printf("Tempo de execução:%f\n", diff);
}
//Roda o laço de repeticao começando do inicio ate bater os parametros passados na funcao STRCMP
void procurarPessoaEnc(Lista *lista, char RG[20])
{
    iniciot = clock();
    printf("----------LISTA ENCADEADA----------\n");
    No *inicio = lista->inicio;
    //Hora que os valores da funcao batem, joga o no pro inicio e descobrese o nome de quem é o dono de determinado RG
    while (inicio != NULL && strcmp(inicio->pessoa.RG, RG) != 0)
    {
        inicio = inicio->proximo;
        cenc++;
    }
    menc=0;
    printf("NOME: %s RG: %s\n\n", inicio->pessoa.nome, inicio->pessoa.RG);
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

//Funcao vai rodando cada elemento da lista partindo do inicio e dando um printf
void imprimirListaEnc(Lista *lista)
{
    iniciot = clock();
    printf("----------LISTA ENCADEADA----------\n");
    No *inicio = lista->inicio;
    for (int i = 0; i < lista->tam; i++)
    {
        printf("NOME: %s RG: %s\n", inicio->pessoa.nome, inicio->pessoa.RG);
        inicio = inicio->proximo;
    }
    printf("Tamanho da lista: %d\n", lista->tam);

    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

//Carrega a lista de um TXT
void carregarListaEnc(Lista *lista, char arquivo[30])
{
    printf("----------LISTA ENCADEADA----------\n");

    Pessoa pessoa;

    iniciot = clock();

    //Abertura e leitura de arquivo
    FILE *arq;

    arq = fopen(arquivo, "rt");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
    }

    //Funções necessarias para separar o nome do rg de cada TXT, uma vez que os arquivos foram passados com uma virgula separando eles "Nome,Rg"
    char str1[30];
    for (int i = 0; fscanf(arq, "%s", str1) != EOF; i++)
    {
        strcpy(pessoa.nome, strtok(str1, ","));
        strcpy(pessoa.RG, strtok(NULL, "\n"));

        inserirFimEnc(lista, pessoa);
    }

    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Salva as listas atuais em um novo TXT
void salvaArquivoEnc(Lista *lista, char arquivo[30])
{
    iniciot = clock();
    printf("----------LISTA ENCADEADA----------\n");
    No *inicio = lista->inicio;
    
    char arqq[35];
    strcpy(arqq, "ENC");
    strcat(arqq, arquivo);

    //Manipulações e verificações do arquivo
    FILE *arq;
    arq = fopen(arqq, "w+");
    if (arq == NULL)
    {
        printf("Erro na Abertura do arquivo");
    }
    else
    {
        if (inicio == NULL)
        {
            fprintf(arq, "Lista Vazia!\n");
        }
        else
        {
            //Produzindo o txt de fato de acordo com cada Nome e Rg da lista atual, percorrendo os nós das listas
            while (inicio != NULL)
            {
                fprintf(arq, "%s,%s\n", inicio->pessoa.nome, inicio->pessoa.RG);
                inicio = inicio->proximo;
            }
            printf("Salvo com Sucesso!\n");

            cenc++;
        }
        fclose(arq);
    }
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

//Insere um nó no comeco da lista seq
void inserirInicioSeq(Pessoa *lista, Pessoa pessoa)
{
    iniciot = clock();
    //Verifica se a lista é vazia se for, coloca nela a pessoa passada
    if (countListaSeq == 0)
    {
        lista[0] = pessoa;
        cseq++;
        mseq++;
    }
    //Se nao, percorre o tamanho da lista do final para o comeco, ate a posicao inicial que é i=0, quando chega no primeiro nó, coloca a pessoa passada na função
    else
    {
        cseq++;
        for (int i = countListaSeq; i > 0; i--)
        {
            lista[i] = lista[i - 1];
            mseq++;
        }
        lista[0] = pessoa;
        mseq++;
    }

    countListaSeq++;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Coloca na ultima posicao da lista a pessoa passada
void inserirFimSeq(Pessoa *lista, Pessoa pessoa)
{
    iniciot = clock();
    lista[countListaSeq] = pessoa;
    countListaSeq++;
    mseq=0;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Insere um nó na posicao N da lista seq
void inserirPosicaoNSeq(Pessoa *lista, Pessoa pessoa, int posicao)
{
    iniciot = clock();
    //Calculo para achar N utilizando o tamanho da lista e o N passado
    int count = countListaSeq - (countListaSeq - posicao);
    //Percorre a lista ate achar a posicao desejada e por fim coloca na posicao a pessoa passada por parametro na funcao
    for (int i = countListaSeq; i >= count; i--)
    {
        lista[i] = lista[i - 1];
        mseq++;
    }
    lista[count - 1] = pessoa;
    mseq++;
    countListaSeq++;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Vai jogando cada um dos nós uma posicao para trás assim removendo o inicio
void removerInicioSeq(Pessoa *lista)
{
    iniciot = clock();
    for (int i = 0; i < countListaSeq - 1; i++)
    {
        lista[i] = lista[i + 1];
        mseq++;
    }
    countListaSeq--;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Tira da lista a ultima posicao passada por referencia pelo ponteiro
void removerFimSeq(Pessoa *lista)
{
    iniciot = clock();
    countListaSeq--;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Vai passando os nós de um em um para atras assim excluindo a posicao N 
void removerPosicaoNSeq(Pessoa *lista, int posicao)
{
    iniciot = clock();
    for (int i = posicao - 1; i < countListaSeq - 1; i++)
    {
        lista[i] = lista[i + 1];
        mseq++;
    }
    countListaSeq--;
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Faz uma comparacao  entre duas strings usando WHILE até achar a semelhante e descobrir o nome do dono daquele RG
void procurarPessoaSeq(Pessoa *lista, char RG[20])
{
    iniciot = clock();
    printf("----------LISTA SEQUENCIAL----------\n");
    int i = 0;
    while (i < countListaSeq && strcmp(lista[i].RG, RG) != 0)
    {
        i++;
        cseq++;
    }
    countadorrg = i;
    printf("NOME: %s RG: %s\n\n", lista[i].nome, lista[i].RG);
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
void buscabinaria(Pessoa *lista, char RG[20])
{
    iniciot = clock();
    printf("----------LISTA SEQUENCIAL----------\n");
    int comeco=0;
    int fim=countListaSeq-1;
    int i=0;

    while (comeco <= fim) {  /* Condição de parada */

        i = (comeco + fim) / 2;  /* Calcula o meio do sub-vetor */

        if (strcmp(lista[i].RG, RG) == 0) {  /* Item encontrado */
            cseq++;
            break;
        }

        if (strcmp(lista[i].RG, RG) < 0) {  /* Item está no sub-vetor à direita */
            comeco = i + 1;
            cseq++;
        } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
            fim = i;
            cseq++;
        }
    }

    countadorrg=i;
    printf("NOME: %s RG: %s\n\n", lista[i].nome, lista[i].RG);
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

//Printf na Lista Sequencial
void imprimirListaSeq(Pessoa *lista, int countLista)
{
    iniciot = clock();
    printf("----------LISTA SEQUENCIAL----------\n");
    for (int i = 0; i < countLista; i++)
    {
        printf("NOME: %s RG: %s\n", lista[i].nome, lista[i].RG);
    }
    printf("Tamanho da lista: %d\n", countLista);
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Le os arquivos TXT coloca eles nas duas listas
void carregarListaSeq(Pessoa *lista, char arquivo[30])
{
    printf("----------LISTA SEQUENCIAL----------\n");

    Pessoa pessoa;

    iniciot = clock();

    FILE *arq;

    arq = fopen(arquivo, "rt");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
    }
    // Procedimento necessario para separar a virgula das strings pois nos txts passados está no formato "NOME,RG"
    char str1[30];
    for (int i = 0; fscanf(arq, "%s", str1) != EOF; i++)
    {
        strcpy(pessoa.nome, strtok(str1, ","));
        strcpy(pessoa.RG, strtok(NULL, "\n"));

        inserirFimSeq(lista, pessoa);
    }
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//Salva a lista atual em um novo arquivo de texto
void salvaArquivoSeq(Pessoa *lista, char arquivo[30])
{
    iniciot = clock();
    printf("----------LISTA SEQUENCIAL----------\n");
    int i = 0;

    char arqq[35];
    //Copia "SEQ" para a string arqq
    strcpy(arqq, "SEQ");
    //Junta a string ate entao como "SEQ", junto com a string passada como referencia na função digitada pelo usuario ficando "SEQ[nomedoarquivodigitado]"
    strcat(arqq, arquivo);

    FILE *arq;
    arq = fopen(arqq, "w+");
    if (arq == NULL)
    {
        printf("Erro na Abertura do arquivo");
    }
    else
    {
        cseq++;
        //Enquanto nao chegar ao fim da lista, continua escrevendo e produzindo o TXT
        while (i < countListaSeq)
        {
            fprintf(arq, "%s,%s\n", lista[i].nome, lista[i].RG);
            i++;
            cseq++;
        }
        printf("Salvo com Sucesso!\n");
        fclose(arq);
    }
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}
//printf menu
void showMenu()
{
    printf("\n1- Inserir nó no inicio\n");
    printf("2- Inserir nó no fim\n");
    printf("3- Inserir nó na posição N\n");
    printf("4- Retirar nó do início\n");
    printf("5- Retirar nó do fim da lista \n");
    printf("6- Retirar nó da posição N\n");
    printf("7- Procurar um nó com campo RG\n");
    printf("8- Mostrar a lista na tela\n");
    printf("9- Salvar a lista em um arquivo\n");
    printf("10- Ler a lista de um arquivo\n");
    printf("11- Ordenar\n");
    printf("12- Sair do sistema\n");
}
//Função de escolha, botao digitado pelo usuario apos aparecer o menu na tela
int escolhaMenu()
{
    int escolha = 0;

    showMenu();
    scanf("%d", &escolha);
    return escolha;
}



void selectionSortSeq(Pessoa *lista)
{
    iniciot = clock();
    Pessoa menor=lista[0];
    int posicao=0;

    for(int i=0;i<countListaSeq;i++){
        menor=lista[i];
        for(int j=i+1;j<countListaSeq;j++){
            if(strcmp(lista[j].RG,menor.RG)<0){
                menor = lista[j];
                posicao=j;
                cseq++;

            }
        }
        lista[posicao]=lista[i];
        lista[i]=menor;
        mseq++;
        imprimirListaSeq(lista, countListaSeq);
    }
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

void insertionSortSeq(Pessoa *lista)
{
    iniciot = clock();
    int i, j;
    Pessoa aux;

    for(i = 1; i < countListaSeq; i++)
    {
        aux = lista[i];
        for(j = i-1; j >= 0 && strcmp(aux.RG,lista[j].RG)<0; j--)
        {
            lista[j+1] = lista[j];
            cseq++;
        }
        lista[j+1] = aux;
        mseq++;
        imprimirListaSeq(lista, countListaSeq);
    }
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

void merge (Pessoa *lista, int inicio, int meio, int fim)
{
    Pessoa *temp;
    int p1, p2, tamanho, i, j, k;
    tamanho=fim-inicio+1;
    p1=inicio;
    p2=meio+1;
    temp = (Pessoa*)malloc(tamanho * sizeof(Pessoa));
    if(temp!=NULL){
        int countListaTemp=0;
        for(i=0;i<tamanho;i++){
            if(p1 <= meio && p2 <= fim){
                if(strcmp(lista[p1].RG,lista[p2].RG)<0) {
                    temp[i]=lista[p1++];
                    countListaTemp++;
                    cseq++;
                } else {
                    temp[i]=lista[p2++];
                    countListaTemp++;
                    cseq++;
                }
            }else if(p1 <= meio){
                    temp[i]=lista[p1++];
                    countListaTemp++;
                    cseq++;
            }
             else if(p2 <= fim){
                    temp[i]=lista[p2++];
                    countListaTemp++;
                    cseq++;
            }
            imprimirListaSeq(temp,countListaTemp);
        }
        for(j=0,k=inicio;j<tamanho;j++,k++){
            lista[k]=temp[j];
            mseq++;
            }
    }
    free(temp);
    
}


void mergeSort(Pessoa *lista, int inicio, int fim){
    iniciot = clock();
    int meio=0;
    if(inicio<fim) {
        meio = (inicio + fim) / 2;
        mergeSort(lista,inicio,meio);
        mergeSort(lista,meio+1,fim);
        merge(lista,inicio,meio,fim);
    }
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

void BubbleSortSeq(Pessoa *lista)
{
    iniciot = clock();
    int i;
    Pessoa aux;


    for (int k = 1; k < countListaSeq; k++)
    {
        for(i = 0; i < countListaSeq-1; i++)
        {
            if (strcmp(lista[i].RG,lista[i+1].RG)>0)
            {
                cseq++;
                aux=lista[i];
                lista[i]=lista[i+1];
                mseq++;
                lista[i+1]=aux;
            }
            
            imprimirListaSeq(lista, countListaSeq);
        }
    }
    
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

void ShellSortSeq(Pessoa *lista) {

    iniciot = clock();
    int i, j, h;
    Pessoa aux;
    for(h = 1; h < countListaSeq; h = 3*h+1); /* calcula o h inicial. */
    while(h > 0) {
        h = (h-1)/3; /* atualiza o valor de h. */
        for(i = h; i < countListaSeq; i++) {
            cseq++;
            aux = lista[i];
            j = i;
            /* efetua comparações entre elementos com distância h: */
            while(strcmp(lista[j-h].RG, aux.RG)>0) {
                cseq++;
                lista[j] = lista[j-h];
                mseq++;
                j -= h;
                if(j < h) break;
            }
            lista[j] = aux;
            mseq++;
        }
        imprimirListaSeq(lista, countListaSeq);
    }

    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);   
}

void QuickSortSeq(Pessoa *lista ,int inicio ,int fim)
{
    iniciot = clock();
    int i,j;
    Pessoa x,y;
    i=inicio;
    j=fim;
    x= lista[(inicio+fim)/2];

    while (i<=j)
    {
        while (strcmp(lista[i].RG,x.RG)<0 && i<fim)
        {
            i++;
            cseq++;
        }
        while (strcmp(lista[j].RG,x.RG)>0 && j>inicio)
        {
            j--;
            cseq++;
        }
        if(i <= j) {
            y = lista[i];
            mseq++;
            lista[i] = lista[j];
            mseq++;
            lista[j] = y;
            mseq++;
            i++;
            j--;
            cseq++;
        }
        imprimirListaSeq(lista, countListaSeq);
    }
    if(j > inicio) {
        QuickSortSeq(lista, inicio, j);
        cseq++;
    }
    if(i < fim) {
        QuickSortSeq(lista, i, fim);
        cseq++;
    }
    
    fimt = clock();
    diff = (((double)fimt - (double)iniciot) / 1000000.0F);
}

//Função principal do trabalho 1
int main()
{
    int escolha = 0;
    countListaSeq = 0; // tamanholistaseq
    int posicao, b, o;       // PosicaoN
    Pessoa pessoa, *listaSeq;
    listaSeq = (Pessoa*)malloc(100000000 * sizeof(Pessoa));
    Lista listaEnc;
    //Setando valores para lista encadeada
    listaEnc.inicio = NULL;
    listaEnc.fim = NULL;
    listaEnc.tam = 0;
    char rg[20], arquivo[30];

    //Enquanto nao apertar 11 nao sai do menu
    while (escolha != 12)
    {
        escolha = escolhaMenu();
        cseq = 0,cenc = 0;
        mseq = 0, menc = 0;

        switch (escolha)
        {
        //INSERIR NÓ NO INICIO
        case 1:
            pessoa = criarPessoa();
            inserirInicioSeq(listaSeq, pessoa);
            printf("Tempo de execução Sequencial:%f\n", diff);
            inserirInicioEnc(&listaEnc, pessoa);
            printf("Tempo de execução Encadeada:%f\n", diff);
            printf("Nome: %s RG: %s\n",pessoa.nome,pessoa.RG);
            printf("A posicao eh 1\n");
            printf("O numero de comparacoes foi %d na sequencial e %d na encadeada\n", cseq,cenc);
            printf("O numero de movimentacoes foi %d na sequencial e %d na encadeada\n", mseq-1, menc);
            break;
        //INSERIR NÓ NO FIM
        case 2:
            pessoa = criarPessoa();
            inserirFimSeq(listaSeq, pessoa);
            printf("Tempo de execução Sequencial:%f\n", diff);
            inserirFimEnc(&listaEnc, pessoa);
            printf("Tempo de execução Encadeada:%f\n", diff);
            printf("Nome: %s RG: %s\n",pessoa.nome,pessoa.RG);
            printf("A posicao eh %d\n", countListaSeq);
            printf("O numero de comparacoes foi %d na sequencial e %d na encadeada\n", cseq, cenc);
            printf("O numero de movimentacoes foi %d na sequencial e %d na encadeada\n", mseq, menc);
            break;
        //INSERIR NÓ NA POSIÇÃO N
        case 3:
            printf("Digite a posicao\n");
            scanf("%d", &posicao);

            pessoa = criarPessoa();
            inserirPosicaoNSeq(listaSeq, pessoa, posicao);
            printf("Tempo de execução Sequencial:%f\n", diff);
            inserirPosicaoNEnc(&listaEnc, pessoa, posicao);
            printf("Tempo de execução Encadeada:%f\n", diff);
            printf("Nome: %s RG: %s\n",pessoa.nome,pessoa.RG);
            printf("A posicao eh :%d\n", posicao);
            printf("O numero de comparacoes foi %d na sequencial e %d na encadeada\n", cseq, cenc);
            printf("O numero de movimentacoes foi %d na sequencial e %d na encadeada\n", mseq-1, menc);
            break;
        //RETIRAR NÓ DO INICIO
        case 4:
            printf("Nome: %s RG: %s\n",listaSeq[0].nome,listaSeq[0].RG);
            removerPosicaoNSeq(listaSeq, 1); // Ao inves de criar removeinicioSeq, Utilizei a mesma funcao de remover posicao n, mas setado para 1
            printf("Tempo de execução Sequencial:%f\n", diff);
            removerInicioEnc(&listaEnc);
            printf("Tempo de execução Encadeada:%f\n", diff);
            printf("A posicao retirada foi 1\n");
            printf("O numero de comparacoes foi %d na sequencial e %d na encadeada\n", cseq, cenc);
            printf("O numero de movimentacoes foi %d na sequencial e %d na encadeada\n", mseq, menc);
            break;
        //RETIRAR NÓ DO FIM DAS LISTAS
        case 5:
            removerFimSeq(listaSeq);
            printf("Tempo de execução Sequencial:%f\n", diff);
            removerPosicaoNEnc(&listaEnc, listaEnc.tam); // Ao inves de Criar removefimEnc, reutilizei setado para o tamanho da lista que seria o ultimo Nó
            printf("Tempo de execução Encadeada:%f\n", diff);
            printf("Nome: %s RG: %s\n",listaSeq[countListaSeq].nome,listaSeq[countListaSeq].RG);
            printf("A posicao retirada foi %d\n", countListaSeq + 1);
            printf("O numero de comparacoes foi %d na sequencial e %d na encadeada\n", cseq, cenc);
            printf("O numero de movimentacoes foi %d na sequencial e %d na encadeada\n", mseq, menc);
            break;
        //RETIRAR NÓ DA POSIÇÃO N
        case 6:
            // Funções mais trabalhosas do projeto, responsaveis por remover um Nó especifico de determinada região da lista
            printf("Digite a posicao\n");
            scanf("%d", &posicao);
            printf("Nome: %s RG: %s\n",listaSeq[posicao-1].nome,listaSeq[posicao-1].RG);
            removerPosicaoNSeq(listaSeq, posicao);
            printf("Tempo de execução Sequencial:%f\n", diff);
            removerPosicaoNEnc(&listaEnc, posicao);
            printf("Tempo de execução Encadeada:%f\n", diff);
            printf("A posicao retirada foi %d\n", posicao);
            printf("O numero de comparacoes foi %d na sequencial e %d na encadeada\n", cseq, cenc);
            printf("O numero de movimentacoes foi %d na sequencial e %d na encadeada\n", mseq, menc);
            break;
        //PROCURAR UM NÓ COM CAMPO RG
        case 7:
            printf("Digite 1 para busca sequencial e 2 para binaria:\n");
            scanf("%d", &b);
                if (b==1)
                {
                    printf("Digite o RG\n");
                    scanf("%s", rg);
                    procurarPessoaSeq(listaSeq, rg);
                    printf("Tempo de execução Sequencial:%f\n", diff);
                    procurarPessoaEnc(&listaEnc, rg);
                    printf("Tempo de execução Encadeada:%f\n", diff);
                    printf("A posicao eh %d\n", countadorrg+1);
                    printf("O numero de comparacoes foi %d na sequencial e %d na encadeada\n", cseq, cenc);
                    printf("O numero de movimentacoes foi %d na sequencial e %d na encadeada\n", mseq, menc);
                }
                else if (b==2)
                {
                    printf("Digite o RG\n");
                    scanf("%s", rg);
                    buscabinaria(listaSeq,rg);
                    printf("Tempo de execução Sequencial:%f\n", diff);
                    printf("A posicao eh %d\n", countadorrg+1);
                    printf("O numero de comparacoes foi %d na sequencial e %d na encadeada\n", cseq, cenc);
                    
                }
                
            break;
        //MOSTRAR A LISTA NA TELA
        case 8:
            // Printf das Listas
            imprimirListaSeq(listaSeq, countListaSeq);
            printf("Tempo de execução Sequencial:%f\n", diff);
            imprimirListaEnc(&listaEnc);
            printf("Tempo de execução Encadeada:%f\n", diff);
            break;
        //SALVAR A LISTA EM UM ARQUIVO
        case 9:
            // Salva em outro arquivo as listas atuais
            printf("Digite o nome do arquivo\n");
            scanf("%s", arquivo);

            salvaArquivoSeq(listaSeq, arquivo);
            printf("Tempo de execução Sequencial:%f\n", diff);
            salvaArquivoEnc(&listaEnc, arquivo);
            printf("Tempo de execução Encadeada:%f\n", diff);
            break;
        //LER A LISTA DE UM ARQUIVO
        case 10:
            // Le um txt e carrega ele em duas listas distintas
            printf("Digite o nome do arquivo\n");
            scanf("%s", arquivo);
            carregarListaSeq(listaSeq, arquivo);
            printf("Tempo de execução Sequencial:%f\n", diff);
            carregarListaEnc(&listaEnc, arquivo);
            printf("Tempo de execução Encadeada:%f\n", diff);
            printf("\nLISTAS CARREGADAS COM SUCESSO!\n");
            break;
        case 11:
            printf("Escolha qual metodo de ordenacao deseja ultilizar:\n");
            printf("1- SelectionSort\n");
            printf("2- InsertionSort\n");
            printf("3- MergeSort\n");
            printf("4- BubbleSort\n");
            printf("5- ShellSort\n");
            printf("6- QuickSort\n");
            scanf("%d", &o);

            if (o==1)
            {
                selectionSortSeq(listaSeq);
                printf("Tempo de execução Sequencial:%f\n", diff);
                printf("O numero de comparacoes foi %d na sequencial\n", cseq);
                printf("O numero de movimentacoes foi %d na sequencial\n", mseq);
            }
            else if (o==2)
            {
                insertionSortSeq(listaSeq);
                printf("Tempo de execução Sequencial:%f\n", diff);
                printf("O numero de comparacoes foi %d na sequencial\n", cseq);
                printf("O numero de movimentacoes foi %d na sequencial\n", mseq);
            }
            else if (o==3)
            {
                mergeSort(listaSeq, 0, countListaSeq-1);
                printf("Tempo de execução Sequencial:%f\n", diff);
                printf("O numero de comparacoes foi %d na sequencial\n", cseq);
                printf("O numero de movimentacoes foi %d na sequencial\n", mseq);
            }
            else if (o==4)
            {
                BubbleSortSeq(listaSeq);
                printf("Tempo de execução Sequencial:%f\n", diff);
                printf("O numero de comparacoes foi %d na sequencial\n", cseq);
                printf("O numero de movimentacoes foi %d na sequencial\n", mseq);
            }
            else if (o==5)
            {
                ShellSortSeq(listaSeq);
                printf("Tempo de execução Sequencial:%f\n", diff);
                printf("O numero de comparacoes foi %d na sequencial\n", cseq);
                printf("O numero de movimentacoes foi %d na sequencial\n", mseq);
            }
            else if (o==6)
            {
                QuickSortSeq(listaSeq,0,countListaSeq-1);
                printf("Tempo de execução Sequencial:%f\n", diff);
                printf("O numero de comparacoes foi %d na sequencial\n", cseq);
                printf("O numero de movimentacoes foi %d na sequencial\n", mseq);
            }
            
            break;
        default:
            break;
        }
    }
    return 0;
}
