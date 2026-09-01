# Diário de Bordo — Uso de IA
Disciplina: Teoria dos Grafos — Lista 4 (Localização e CPM)

Dupla: [Kaik Henrique] + [Gustavo Santos]

Chat utilizado: Gemini

## Entrada 1 — 27/08/2026 às 10:33

● Questão(ões): Questão 2 (Definir o Método do Caminho Crítico, diferença entre
caminho máximo e caminho mínimo, e conceito de folga).

● Onde travamos / objetivo: Tínhamos dúvida se o Caminho Crítico era a "atividade
de maior preferência" ou de "maior dependência", e quer tínhamos que definir por
que o CPM foca no caminho máximo e não no mínimo.

● O que perguntamos ao tutor:
1. "no caso então o metodo do caminho critico é a execução da atividade de
maior preferencia?"
2. "A tarefa B foi escolhida para mandar no tempo final porque outras atividades
dependem dela concluida..."
3. "O metodo do caminho critico é a execução de atividade de maior
dependencia"
4. "O projeto atrasa, então resta o gestor mover a equipe mais eficiente..."
5. "A diferença entre caminho máximo e caminho mínimo em um grafo, e por
que o CPM foca no caminho máximo." (testando nossa resposta construída).
6. "A folga total é a soma de toda folga que as atividades podem ter em relação
ao caminho mais longo..."

● O que o tutor respondeu ou perguntou (resumo ou link): A IA não deu a
resposta pronta. Ela usou o método socrático: fez perguntas provocativas usando
um exemplo prático (Tarefas A, B e C), corrigiu o uso do termo "preferência" e
"quantidade de atividades", explicou a diferença entre caminho mínimo em grafos
(como GPS) e caminho máximo no CPM, e nos guiou a entender que o caminho
mais longo dita o tempo mínimo do projeto.
● O que fizemos com isso (aceitamos? questionamos? corrigimos?): Refletimos
sobre as perguntas da IA e fomos ajustando nossa resposta passo a passo.
Inicialmente achamos que o caminho mais longo dependia da quantidade de
atividades, mas corrigimos o texto percebendo que depende da duração total
acumulada. Também admitimos quando confundimos o conceito de caminho mínimo
de um grafo comum com o do CPM.
● A IA tentou dar a resposta pronta ou errou? Como reagimos?: Não deu a
resposta pronta; ela insistiu em nos fazer formular os conceitos com nossas próprias
palavras. Quando cometemos um deslize (dizendo que o projeto terminaria em 8
dias no caminho mínimo), a IA nos fez notar que as tarefas paralelas ainda estariam
em execução, o que nos fez corrigir o raciocínio.
● O que aprendemos:

1. O Caminho Crítico é a sequência de tarefas dependentes com a maior
duração total (caminho máximo do grafo).
2. O objetivo do CPM é determinar o menor tempo total para concluir o projeto e
garantir que as atividades críticas não sofram atrasos.
3. Caminho Mínimo vs. Máximo: O caminho mínimo busca a rota mais
rápida/barata (como o GPS). O CPM foca no caminho máximo porque, como
as atividades acontecem em paralelo, o projeto só finaliza quando a última
tarefa (a mais longa) termina.
4. Folga Total: É a margem de tempo que uma tarefa não crítica pode atrasar
sem impactar o prazo final do projeto.

Reflexão final
● Onde a IA mais ajudou: Em desconstruir termos vagos que estávamos usando
(como "preferência" ou "maior quantidade de tarefas") e nos guiar até conceitos
técnicos precisos usando exemplos práticos.
● Onde tentou entregar a resposta pronta: Em momento nenhum nesta questão; ela
sempre devolveu perguntas de verificação e pediu para reescrevermos com nossas
palavras.
● Onde errou e como verificamos: A IA fez uma pergunta de pegadinha sobre o
prazo de 8 vs 15 dias no CPM. Inicialmente respondemos errado por interpretar
como um grafo de rota simples, mas ao reler a provocação da IA, percebemos a
diferença lógica do parallelismo no CPM e corrigimos.

## Entrada 2 — 31/08/2026
Questão(ões): 3 e 4.

Onde travamos / objetivo: Precisávamos resolver as questões da lista, validar a lógica do cálculo da folga total das atividades $B$ e $D$, e entender o método do passo para trás (backward pass) para calcular o Término Tarde ($LF$).

O que perguntamos ao tutor:

Solicitamos a resolução direta das duas questões enviadas por imagem (pedindo para focar no conteúdo e evitar perguntas de reflexão).

Apresentamos nosso raciocínio mental sobre a folga das atividades $B$ e $D$ para validação.

Perguntamos explicitamente como é feito o cálculo do Término Tarde ($LF$).

O que o tutor respondeu ou perguntou (resumo ou link):

Forneceu a resolução estruturada de ambas as questões (caminhos, durações, tabela $ES/EF/LS/LF$ e caminho crítico).

Validou a folga de $B$ (1 dia), mas explicou que caímos em uma pegadinha na folga de $D$ (que é 2 dias, e não 1), detalhando a diferença entre a folga total da atividade e a folga compartilhada do caminho.

Explicou a fórmula e a regra do backward pass ($LF = \min(LS_{\text{sucessoras}})$).

O que fizemos com isso (aceitamos? questionamos? corrigimos?): Aceitamos as respostas das imagens, porém contestamos a folga de $D$ apresentando nossa própria lógica. Após o esclarecimento da IA sobre a diferença entre folga individual e acumulada, aceitamos e corrigimos nosso entendimento.

A IA tentou dar a resposta pronta ou errou? Como reagimos?: A IA iniciou tentando aplicar o método socrático, mas entregou as respostas completas das duas questões assim que pedimos foco direto. Não houve erros matemáticos por parte da IA; a discordância na folga de $D$ foi um equívoco da nossa interpretação, o qual a IA ajudou a esclarecer.

O que aprendemos: Aprendemos a identificar caminhos críticos (sequência de maior duração/folga zero), a montar tabelas de tempos de rede AON, a diferença entre a folga individual de uma tarefa (assumindo que as anteriores não atrasam) e a folga do caminho, e a aplicação prática do backward pass para encontrar o $LF$.

Reflexão final
Onde a IA mais ajudou: Na estruturação e conferência das tabelas de tempos ($ES, EF, LS, LF$) e no esclarecimento do conceito de Folga Total individual versus Folga Compartilhada.

Onde tentou entregar a resposta pronta: Entregou os gabaritos completos das alíneas a, b, c e d das duas questões após pedirmos para evitar o formato socrático.

Onde errou e como verificamos: A IA não apresentou erros de cálculo. Verificamos a explicação conceitual da folga de $D$ analisando a janela de tempo disponível entre o término no tempo normal de $B$ (dia 5) e o início limite da atividade $F$ (dia 9).