#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define N 6 // Número total de atividades

// Struct utilizada para armazenar as informações de cada atividade
typedef struct {
    char nome;
    int duracao, ES, EF, LS, LF, folga;
    // ES = Início mais cedo e EF = Fim mais cedo
    // LS = Início mais tarde e LF = Fim mais tarde
    // Folga da atividade
} Atividade;

// Função utilizada para mostrar a data e a hora atual
void DataHora(){
    time_t tempoAtual;

    time(&tempoAtual);

    struct tm *infoTempo = localtime(&tempoAtual);

    int hora = infoTempo->tm_hour;
    int minuto = infoTempo->tm_min;
    int segundo = infoTempo->tm_sec;
    printf("Hora Atual: %02d:%02d:%02d\n",hora,minuto,segundo);

    int dia = infoTempo->tm_mday;
    int mes = infoTempo->tm_mon + 1;
    int ano = infoTempo->tm_year + 1900;
    printf("Data Atual: %02d/%02d/%02d\n",dia,mes,ano);
}

int main() {
    setlocale(LC_ALL, "portuguese");
    // Inicialização das atividades de A até F e suas respectivas durações
    Atividade atividades[N] = {
        {'A', 2, 0,0,0,0,0}, // Índice 0
        {'B', 3, 0,0,0,0,0}, // Índice 1
        {'C', 4, 0,0,0,0,0}, // Índice 2
        {'D', 2, 0,0,0,0,0}, // Índice 3
        {'E', 3, 0,0,0,0,0}, // Índice 4
        {'F', 1, 0,0,0,0,0}  // Índice 5
    };

    // Matriz utilizada para representar a precedência entre as atividades
    int precedencia[N][N] = {0};
    precedencia[0][1] = 1; // A -> B
    precedencia[1][3] = 1; // B -> D
    precedencia[3][5] = 1; // D -> F
    precedencia[0][2] = 1; // A -> C
    precedencia[2][4] = 1; // C -> E
    precedencia[1][4] = 1; // B -> E
    precedencia[4][5] = 1; // E -> F

    // Passo para frente utilizado para determinar o ES e o EF
    for (int i = 0; i < N; i++) {
        int ESmax = 0;

        // Verifica todas as atividades que antecedem a atividade atual
        for (int j = 0; j < N; j++) {
            if (precedencia[j][i] == 1 && atividades[j].EF > ESmax) {
                ESmax = atividades[j].EF; // O ES recebe o maior EF entre os predecessores
            }
        }

        atividades[i].ES = ESmax;
        atividades[i].EF = atividades[i].ES + atividades[i].duracao;
    }

    // A duração do projeto corresponde ao maior EF encontrado entre as atividades
    int duracaoProjeto = 0;
    for (int i = 0; i < N; i++) {
        if (atividades[i].EF > duracaoProjeto) {
            duracaoProjeto = atividades[i].EF;
        }
    }

    // Passo para trás utilizado para determinar o LF, LS e a folga
    for (int i = N-1; i >= 0; i--) {
        int LFmin = duracaoProjeto;
        int temSucessor = 0;
        
        // Verifica todas as atividades que sucedem a atividade atual
        for (int j = 0; j < N; j++) {
            if (precedencia[i][j] == 1) {
                temSucessor = 1;

                if (atividades[j].LS < LFmin) {
                    LFmin = atividades[j].LS; // O LF recebe o menor LS entre os sucessores
                }
            }
        }

        atividades[i].LF = temSucessor ? LFmin : duracaoProjeto;
        atividades[i].LS = atividades[i].LF - atividades[i].duracao;
        
        // Calcula a diferença entre o início mais tarde e o início mais cedo
        atividades[i].folga = atividades[i].LS - atividades[i].ES;
    }

    // Exibe os resultados e identifica as atividades críticas
    printf("Atividade | Duração | ES | EF | LS | LF | Folga  | critico\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("  %c        | %2d \t| %2d | %2d | %2d | %2d | %2d     | %s\n",
            atividades[i].nome, atividades[i].duracao,
            atividades[i].ES, atividades[i].EF,
            atividades[i].LS, atividades[i].LF, atividades[i].folga,
            (atividades[i].folga == 0 ? "Sim" : "Nao")); // Folga igual a zero indica atividade crítica
    }

    printf("\nDuracao minima do projeto: %d\n", duracaoProjeto);

    printf("\nGustavo Santos Oliveira, Kaik Henrique Naves Soares\n");
    DataHora();
    return 0;
}