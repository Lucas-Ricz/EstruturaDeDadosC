#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numPalavras = 0;
int pant = 0;
int o = 0;

void carregartexto(char **palavras, char arquivo[30])
{

    int i = 0;
    char line[100];
    char *aux;

    FILE *arq;

    arq = fopen(arquivo, "rt");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
    }

    while (!feof(arq))
    {
        fscanf(arq, "%s", line);

        aux = strtok(line, ".,:?!\"");
        // Adiciona cada palavra no vetor

        if (line[0] != '-')
        {
            palavras[i] = strdup(aux);

            if ((int)palavras[i][0] < 91)
            {
                palavras[i][0] += 32;
            }

            i++;
            numPalavras++;
        }

        // Conta a quantidade de palavras
    }

    int j;
    numPalavras--;

    for (j = 0; j < numPalavras; j++)
        printf("\n%s", palavras[j]); // Exibi as palavras que estao no vetor.

    printf("\n\n");
}

void buscarpalavra(char **palavras, char word[30])
{
    int i = 0;
    while (i < numPalavras && strcmp(palavras[i], word) != 0)
    {
        i++;
    }
    pant = i;
    printf("\nA palavra eh %s e está na posicao N:%d e tem %d ocorrencias\n", palavras[i], i + 1, o);
    printf("\nTrecho da frase em que ela se encontra: ");
    if (i > 1)
    {
        printf("%s %s ", palavras[i - 2], palavras[i - 1]);
    }
    printf("%s", palavras[i]);
    if (i < numPalavras - 2)
    {
        printf(" %s %s", palavras[i + 1], palavras[i + 2]);
    }
    printf("\n");
}

void ocorrencia(char **palavras, char word[30])
{
    o = 0;
    for (int i = 0; i < numPalavras; i++)
    {
        if (strcmp(palavras[i], word) == 0)
        {
            o++;
        }
    }
}

void proximaocorrencia(char **palavras, char word[30])
{
    int i = pant + 1;
    while (i < numPalavras && strcmp(palavras[i], word) != 0)
    {
        i++;
    }
    printf("\nA palavra eh %s e está na posicao N:%d", palavras[i], i + 1);
    printf("\nTrecho da frase em que ela se encontra: ");
    if (i > 1)
    {
        printf("%s %s ", palavras[i - 2], palavras[i - 1]);
    }
    printf("%s", palavras[i]);
    if (i < numPalavras - 2)
    {
        printf(" %s %s", palavras[i + 1], palavras[i + 2]);
    }
    printf("\n");
    pant = i;
}

int main()
{
    int escolha = 0;
    char arquivo[30];
    char **palavras;
    palavras = (char **)malloc(1000 * sizeof(char *));
    char word[30];

    do
    {
        printf("Escolha uma funcao:\n");
        printf("1-Ler um arquivo texto.\n");
        printf("2-Apresentar arquivo invertido\n");
        printf("3-Procurar uma palavra no arquivo invertido\n");
        printf("4-Procurar a próxima ocorrência\n");
        printf("5-Sair do sistema.\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite o nome do arquivo\n");
            scanf("%s", arquivo);
            carregartexto(palavras, arquivo);
            printf("Total de palavras:%d\n\n", numPalavras);
            break;

        case 2:
            arquivoinvertido();

            break;

        case 3:
            printf("Digite a palavra que deseja buscar:\n");
            scanf("%s", word);
            ocorrencia(palavras, word);
            buscarpalavra(palavras, word);

            break;

        case 4:
            printf("Proxima ocorrencia:\n");
            proximaocorrencia(palavras, word);

            break;

        default:
            break;
        }

    } while (escolha != 5);

    return 0;
}

void arquivoinvertido()
{
    printf("\nARQUIVO INVERTIDO\n");
    printf("Vocabulário     Ocorrência\n\n");
    printf("acompanha           1       \n");
    printf("adiantou-se         2       \n");
    printf("adiante             1       \n");
    printf("admiração           1       \n");
    printf("adormecido          1       \n");
    printf("afinal              1       \n");
    printf("agilidade           1       \n");
    printf("agitou              1       \n");
    printf("agora               1       \n");
    printf("ainda               2       \n");
    printf("ai                  3       \n");
    printf("ajudam              1       \n");
    printf("ajudar              1       \n");
    printf("ajudava             1       \n");
    printf("além                6       \n");
    printf("alto                1       \n");
    printf("algumas             2       \n");
    printf("algo                1       \n");
    printf("alguns              1       \n");
    printf("alguém              1       \n");
    printf("amiguinhos          1       \n");
    printf("amizade             1       \n");
    printf("amigos              1       \n");
    printf("amigo               2       \n");
    printf("anos                1       \n");
    printf("andavam             1       \n");
    printf("ao                  3       \n");
    printf("aprender            1       \n");
    printf("apanhar             1       \n");
    printf("aproveitando        1       \n");
    printf("apanhe              1       \n");
    printf("aproximava          1       \n");
    printf("apenas              1       \n");
    printf("aprenderam          1       \n");
    printf("as                  6       \n");
    printf("assustados          1       \n");
    printf("assim               1       \n");
    printf("atras               1       \n");
    printf("atacava             1       \n");
    printf("atacaram            1       \n");
    printf("aventura            1       \n");
    printf("avançou             1       \n");
    printf("avançaram           1       \n");
    printf("barreiras           1       \n");
    printf("batendo             1       \n");
    printf("bateu               1       \n");
    printf("barulho             1       \n");
    printf("batalha             1       \n");
    printf("beto                1       \n");
    printf("bem-vindo           1       \n");
    printf("bem                 2       \n");
    printf("bico                1       \n");
    printf("bicava              1       \n");
    printf("bons                1       \n");
    printf("boca                1       \n");
    printf("bront               15       \n");
    printf("brigando            1       \n");
    printf("carrero             1       \n");
    printf("cada                2       \n");
    printf("caverna             7       \n");
    printf("calma               1       \n");
    printf("caminharam          1       \n");
    printf("capazes             1       \n");
    printf("certeza             1       \n");
    printf("chifres             2       \n");
    printf("chão                1       \n");
    printf("chamarei            1       \n");
    printf("chifrudinho         1       \n");
    printf("chuva               1       \n");
    printf("contar-lhe          1       \n");
    printf("conquistam          1       \n");
    printf("começa              1       \n");
    printf("convivem            1       \n");
    printf("com                 8       \n");
    printf("conhecido           1       \n");
    printf("conhecer            1       \n");
    printf("comer               2       \n");
    printf("comilao             1       \n");
    printf("colheu              1       \n");
    printf("começou             1       \n");
    printf("coragem             1       \n");
    printf("criaturas           1       \n");
    printf("crescia             1       \n");
    printf("cuidado             1       \n");
    printf("da                  8       \n");
    printf("daquele             1       \n");
    printf("dando               1       \n");
    printf("descobrir           2       \n");
    printf("demais              1       \n");
    printf("desejo              1       \n");
    printf("defende             1       \n");
    printf("desculpe            2      \n");
    printf("dente               1       \n");
    printf("descansando         1       \n");
    printf("desça               1       \n");
    printf("essa                1       \n");
    printf("descendo            1       \n");
    printf("devora-los          1       \n");
    printf("deveria             1       \n");
    printf("deles               1       \n");
    printf("dinossauros         8       \n");
    printf("dificuldades        1       \n");
    printf("diferentes          2       \n");
    printf("disse               7       \n");
    printf("dias                1       \n");
    printf("dia                 1       \n");
    printf("diante              1       \n");
    printf("diziam              1       \n");
    printf("distrairei          1       \n");
    printf("distrair            1       \n");
    printf("dominavam           1       \n");
    printf("dos                 5       \n");
    printf("do                  5       \n");
    printf("e                   37       \n");
    printf("ele                 2       \n");
    printf("eles                2       \n");
    printf("em                  6       \n");
    printf("embora              1       \n");
    printf("encantado           1       \n");
    printf("entre               3       \n");
    printf("energia             1       \n");
    printf("entao               1       \n");
    printf("entanto             1       \n");
    printf("entrada             1       \n");
    printf("entrou              1       \n");
    printf("entraram            1       \n");
    printf("encorajados         1       \n");
    printf("encantado           1       \n");
    printf("era                 9       \n");
    printf("eram                2       \n");
    printf("erupçao             1       \n");
    printf("especies            2       \n");
    printf("estao               1       \n");
    printf("esta                2       \n");
    printf("esticou             1       \n");
    printf("estava              1       \n");
    printf("estar               1       \n");
    printf("estao               1       \n");
    printf("escolham            1       \n");
    printf("estegossauro        1       \n");
    printf("esse                1       \n");
    printf("eu                  4       \n");
    printf("existia             1       \n");
    printf("explorando          1       \n");
    printf("existe              1       \n");
    printf("expedir             1       \n");
    printf("expelindo           1       \n");
    printf("exemplo             1       \n");
    printf("facanhas            2       \n");
    printf("familias            3       \n");
    printf("familia             2       \n");
    printf("falou               6       \n");
    printf("fala                1       \n");
    printf("falar               1       \n");
    printf("fazer               2       \n");
    printf("feliz               1       \n");
    printf("filhos              1       \n");
    printf("ficava              1       \n");
    printf("ficar               2       \n");
    printf("ficou               1       \n");
    printf("fila                1       \n");
    printf("ficarei             1       \n");
    printf("forca               1       \n");
    printf("folhas              5       \n");
    printf("foi                 2       \n");
    printf("forcas              1       \n");
    printf("fortes              1       \n");
    printf("grande              4       \n");
    printf("grandes             2       \n");
    printf("gosta               1       \n");
    printf("gostavam            1       \n");
    printf("graca               1       \n");
    printf("guanon              1       \n");
    printf("gloriosa            1       \n");
    printf("guardaram           1       \n");
    printf("historia            1       \n");
    printf("homem               1       \n");
    printf("herois              1       \n");
    printf("hora                3       \n");
    printf("hein                1       \n");
    printf("herbivoros          1       \n");
    printf("imaginacao          2       \n");
    printf("irmaos              1       \n");
    printf("igual               1       \n");
    printf("implicam            1       \n");
    printf("jovemdinossauro     1       \n");
    printf("juntos              1       \n");
    printf("jovem               3       \n");
    printf("jovens              2       \n");
    printf("linda               1       \n");
    printf("lado                3       \n");
    printf("luta                2       \n");
    printf("lugar               2       \n");
    printf("lutador             1       \n");
    printf("lugares             1       \n");
    printf("logo                4       \n");
    printf("lava                1       \n");
    printf("levantou            1       \n");
    printf("lago                1       \n");
    printf("meu                 1       \n");
    printf("mundo               2       \n");
    printf("milhoes             1       \n");
    printf("magnificas          1       \n");
    printf("mostrarao           1       \n");
    printf("melhor              1       \n");
    printf("misturava           1       \n");
    printf("montanha            4       \n");
    printf("manhas              1       \n");
    printf("melhor              1       \n");
    printf("muito               1       \n");
    printf("mas                 2       \n");
    printf("mal                 1       \n");
    printf("meus                1       \n");
    printf("mim                 1       \n");
    printf("meu                 1       \n");
    printf("machuca-lo          1       \n");
    printf("manha               1       \n");
    printf("mais                1       \n");
    printf("morrera             1       \n");
    printf("meio                1       \n");
    printf("nao                 13       \n");
    printf("no                  7      \n");
    printf("nossos              1       \n");
    printf("nossa               2       \n");
    printf("na                  5       \n");
    printf("numa                1       \n");
    printf("novo                1       \n");
    printf("ninguem             2       \n");
    printf("novas               1       \n");
    printf("o                   29      \n");
    printf("os                  13       \n");
    printf("onde                2       \n");
    printf("orgulha             1       \n");
    printf("outro               1       \n");
    printf("pois                3       \n");
    printf("paz                 1       \n");
    printf("pertence            1       \n");
    printf("pode                1       \n");
    printf("por                 1       \n");
    printf("prefere             1       \n");
    printf("plantas             1       \n");
    printf("porque              1       \n");
    printf("pensou              1       \n");
    printf("pescocudo           1       \n");
    printf("pare                2       \n");
    printf("ptolomeu            9       \n");
    printf("para                13       \n");
    printf("perder              2       \n");
    printf("pedras              1       \n");
    printf("pelo                1       \n");
    printf("pinacossauro        3       \n");
    printf("que                 29       \n");
    printf("quando              4       \n");
    printf("quero               1       \n");
    printf("quem                4       \n");
    printf("queria              1       \n");
    printf("realizamos          2       \n");
    printf("rex                 1       \n");
    printf("reclamou            1       \n");
    printf("reclamar            1       \n");
    printf("reuniram            2       \n");
    printf("repreenderam        1       \n");
    printf("rugido              1       \n");
    printf("rasantes            1       \n");
    printf("realizar            1       \n");
    printf("se                  9       \n");
    printf("ser                 2       \n");
    printf("seus                4       \n");
    printf("supera              1       \n");
    printf("sobrevivência       1       \n");
    printf("sonho               1       \n");
    printf("sua                 1       \n");
    printf("sao                 1       \n");
    printf("saiba               1       \n");
    printf("so                  1       \n");
    printf("sei                 1       \n");
    printf("sai                 1       \n");
    printf("seja                1       \n");
    printf("somos               1       \n");
    printf("segui-se            1       \n");
    printf("saber               1       \n");
    printf("salvar              1       \n");
    printf("tirano              10       \n");
    printf("trion               15       \n");
    printf("tudo                1       \n");
    printf("terra               2       \n");
    printf("todas               4       \n");
    printf("todos               3       \n");
    printf("tegaro              1       \n");
    printf("um                  13       \n");
    printf("uma                 8       \n");
    printf("vale                7       \n");
    printf("vou                 1       \n");
    printf("voador              1       \n");
    printf("ver                 4       \n");
    printf("vermelha            2       \n");
    printf("velhos              1       \n");
    printf("vai                 3       \n");
    printf("vamos               4      \n");
    printf("viajar              1       \n");
    printf("viver               3       \n");
    printf("verdadeira          2       \n");
    printf("vence               1       \n");
    printf("varias              1       \n");
    printf("vez                 1       \n");
    printf("você                1       \n");
    printf("vocês               5       \n");
    printf("viu                 1       \n");
    printf("voces               1       \n");
    printf("vivem               2       \n");
    printf("velho               2       \n");
    printf("vivi                1       \n");
    printf("vulcão              2       \n");
    printf("vitoriosos          1       \n");
    printf("viram               1       \n\n");
}