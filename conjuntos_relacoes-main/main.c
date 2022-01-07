#include <stdio.h>
#include <stdlib.h>

/**
 * Printando o conjunto informado na tela/console
 * @param conjunto
 * @param tamanho
 * @param nomeConjunto
 */
void printarConjunto(int conjunto[], int tamanho, char nomeConjunto[]) {
    printf("Conjunto %s = { ",nomeConjunto);
    for(int i=0;i<tamanho;i++){
        printf("%d,",conjunto[i]);
    }
    printf("} \n");
}

/**
 * Verificando a existência de um determinado número no conjunto
 * @param conjunto
 * @param numero
 * @param tamanhoAtual: tamanho atual do conjunto
 * @return 1 para quando encontrar e -1 quando não encontrar
 */
int verificarExistencia(int conjunto[], int numero, int tamanhoAtual){
    for(int i=0;i<tamanhoAtual;i++){
        if(conjunto[i] == numero){
            return 1;
        }
    }
    return -1;
}

/**
 * Realizando a intersecção de dois conjuntos
 * @param conjuntoA
 * @param conjunto B
 * @param tamanho
 */
void intersecaoConjunto(int conjuntoA[], int conjuntoB[], int tamanho){
    int tamanhoInterseccao = 0;
    int intersecao[20];
    for(int i=0;i<tamanho;i++){
        if(verificarExistencia(conjuntoB, conjuntoA[i],10) == 1){
            intersecao[tamanhoInterseccao] = conjuntoA[i];
            tamanhoInterseccao++;
        }
    }
    printarConjunto(intersecao,tamanhoInterseccao,"intersecção\0");
}

/**
 * Realizando a diferença de dois conjuntos
 * @param conjuntoA
 * @param conjunto B
 * @param tamanho
 */
void diferencaConjunto(int conjuntoA[], int conjuntoB[], int tamanho){
    int tamanhoDiferenca = 0;
    int diferenca[10];
    for(int i=0;i<tamanho;i++){
        if(verificarExistencia(conjuntoB, conjuntoA[i],10) == -1){
            diferenca[tamanhoDiferenca] = conjuntoA[i];
            tamanhoDiferenca++;
        }
    }
    printarConjunto(diferenca,tamanhoDiferenca,"diferença\0");
}

/**
 * Realizando a união de dois conjuntos
 * @param conjuntoA
 * @param conjuntoB
 * @param tamanho: tamanho dos conjuntos
 */
void uniaoConjuntos(int conjuntoA[], int conjuntoB[], int tamanho){
    int tamanhoUniao = 0;
    int uniao[20];   
    //unindo os conjuntos
    for(int i=0;i<tamanho;i++){
        // verificando se o número já não existe no conjunto
        if(verificarExistencia(uniao,conjuntoA[i], tamanhoUniao) == -1){
            uniao[tamanhoUniao] = conjuntoA[i];
            tamanhoUniao++;
        }
        // verificando se o número já não existe no conjunto
        if(verificarExistencia(uniao,conjuntoB[i], tamanhoUniao) == -1){
            uniao[tamanhoUniao] = conjuntoB[i];
            tamanhoUniao++;
        }
    }
    printarConjunto(uniao,tamanhoUniao,"união\0");
}

/**
 * Fazendo a negação do conjunto, baseado no conjunto universo 0 <= x <= 50
 * @param conjunto a ser negado
 * @param tamanho: tamanho do conjunto a ser negado
 */
void negacaoConjuntoA(int conjuntoA[], int tamanho){
    int negacao[50];
    int tamanhoNegacao = 0;
    for(int i=0;i<=50;i++){
        if(verificarExistencia(conjuntoA, i, tamanho) == -1){
            negacao[tamanhoNegacao] = i;
            tamanhoNegacao++;
        }
    }
    printarConjunto(negacao,tamanhoNegacao,"negação do conjunto A\0");
}

/**
 * Gerando conjunto de forma aleatória entre 0 e 50
 * @param conjunto
 * @param tamanho: tamanho do conjunto a ser gerado
 */
void gerarConjunto(int conjunto[], int tamanho) {
    for(int i=0;i<tamanho;i++){
        conjunto[i] = rand() % 51;
    }
}

/**
 * Ordenando o conjunto de forma crescente
 * @param conjunto
 * @param tamanho: tamanho do conjunto
 */
void ordenarConjunto(int conjunto[], int tamanho){
    int maior;
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(conjunto[i] < conjunto[j]){
                maior = conjunto[j];
                conjunto[j] = conjunto[i];
                conjunto[i] = maior;
            }
        }
    }
}

/**
 * Verifica se possui algum par igual aos passados por parâmetro
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 * @param x1
 * @param y1
 * @return 1- se encontrar algum par igual a (x1,y1) e 0- se não encontrar nenhum par igual a (x1.y1)
 */
int verificaParesIguais(int relacao[][2],int tamanhoLinha, int x1, int y1){
    int x,y;
    for(int i=0;i<tamanhoLinha;i++){
        x = relacao[i][0];
        y = relacao[i][1];
        if(x == x1 && y == y1){
            return 1;
        }
    }
    return 0;
}

/**
 * Gerando relação de forma aleatória entre 0 e 4
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 */
void gerarRelacao(int relacao[][2], int tamanhoLinha){
    int count = 0;
    int x,y;
    int regerar = 0;
    for(int i=0;i<tamanhoLinha;i++){
        do{
            x = rand() % 5;
            y = rand() % 5;
            for(int z=0;z<i;z++){
                if(relacao[z][0] == x && relacao[z][1] == y){
                    regerar = 1;
                    break;
                } else {
                    regerar = 0;
                }
            }
        }while(regerar == 1);
        relacao[i][0] = x;
        relacao[i][1] = y;
    }
}

/**
 * Função para ordenar uma matriz de duas colunas
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 */
void ordenarRelacao(int relacao[][2], int tamanhoLinha){
    int maiorX,maiorY;
    //ordenando o vetor
    for (int i=0;i<tamanhoLinha; i++){
        for(int j=i;j<tamanhoLinha;j++){
            if (relacao[i][0] > relacao[j][0]) {
                maiorX = relacao[i][0];
                relacao[i][0] = relacao[j][0];
                relacao[j][0] = maiorX;
                
                maiorY = relacao[i][1];
                relacao[i][1] = relacao[j][1];
                relacao[j][1] = maiorY;
            }
            if (relacao[i][0] == relacao[j][0] && relacao[i][1] > relacao[j][1]) {
                maiorY = relacao[i][1];
                relacao[i][1] = relacao[j][1];
                relacao[j][1] = maiorY;
            }
        }
    }
}
/**
 * Printando o relação informada na tela/console
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 * @param tamanhoColuna: quantidade de linhas
 */
void printarRelacao(int relacao[][2], int tamanhoLinha, int tamanhoColuna){
    int count = 0;
    printf("Relação = { ");
    for(int i=0;i<tamanhoLinha;i++){
        for(int j=0;j<tamanhoColuna;j++){
            if(count == 0){
                printf("(");
            }
            printf("%d, ",relacao[i][j]);
            count++;
            if(count == 2){
                printf("),");
                count = 0;
            }
        }
    }
    printf("}\n");
}

/**
 * Verificando se (x,y) são elementos reflexivos
 * @param x
 * @param y
 * @param tamanho: tamanho do conjunto
 * @return 1- se o elemento for reflexivo e 0- se o elemento não for reflexivo
 */
int verificarElementosReflexivos(int x, int y, int tamanho){
    for(int i=0;i<=tamanho;i++){
        if(x == i && y == i){
            return 1;
        }
    }
    return 0;
}

/**
 * Verifica se a relação é reflexiva
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 * @return quantidade de elemento reflexivos na relação
 */
int verificarReflexiva(int relacao[][2], int tamanhoLinha){
    int contarElementos = 0;
    for(int i=0;i<tamanhoLinha;i++){
        if(verificarElementosReflexivos(relacao[i][0],relacao[i][1], 4) == 1){
            contarElementos++;
        }
    }
    return contarElementos;
}

/**
 * Verifica se a relação é simetrica
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 * @return quantidade de elemento simétricos na relação
 */
int verificarSimetria(int relacao[][2], int tamanhoLinha){
    int x,y;
    int contarElementos = 0;
    
    for(int i=0;i<tamanhoLinha;i++){
        x = relacao[i][0];
        y = relacao[i][1];
        if(verificaParesIguais(relacao,tamanhoLinha,y,x) == 1){
            contarElementos++;
        } 
    }
    return contarElementos;
}

/**
 * Verifica se a relação é antissimétrica
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 * @return 1- relação antissimetrica  0- relação não é antissimetrica
 */
int verificarAntissimetria(int relacao[][2], int tamanhoLinha){
    int x,y;
    int contarElementos = 0;
    int contarAntissimetrico = 0;
    
    for(int i=0;i<tamanhoLinha;i++){
        x = relacao[i][0];
        y = relacao[i][1];
        if(verificaParesIguais(relacao,tamanhoLinha,y,x) == 1){
            contarElementos++;
            if(x == y){
                contarAntissimetrico++;
            }
        } 
    }
    if(contarElementos == contarAntissimetrico){
        return 1;
    }
    return 0;
}

/**
 * Busca os elementos z, ou seja, se existir (x,y) e (y,x) na relação, deve existir (x,z)
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 * @param z[]: vetor que vai armazenar os possíveis valores de z, para um determinado y1
 * @param y1
 * @return tamanho do vetor z
 */
int buscarZ(int relacao[][2], int tamanhoLinha, int z[], int y1){
    int x,y;
    int indice = 0;
    for(int i=0;i<tamanhoLinha;i++){
        x = relacao[i][0];
        y = relacao[i][1];
        if(x == y1){
            //verificar se já não existe
            if(verificarExistencia(z,y,indice) == -1){
                z[indice] = y;
                indice++;
            } 
        }
    }
    return indice;
}

/**
 * Verifica se a relação é transtiva
 * @param relacao
 * @param tamanhoLinha: quantidade de linhas
 * @return 1- se for transitiva 0- se não for transitiva
 */
int verificarTransitividade(int relacao[][2], int tamanhoLinha){
    int x,y,tamanhoZ;
    int z[10];
    
    for(int i=0;i<tamanhoLinha;i++){
        x = relacao[i][0];
        y = relacao[i][1];
        //buscando os possíveis valores de z
        tamanhoZ = buscarZ(relacao,tamanhoLinha,z,y);
        for(int w=0;w<tamanhoZ;w++){
            //verificando se existe (x,z)
            if(verificaParesIguais(relacao,tamanhoLinha,x, z[w]) == 0 ){
                return 0;
            }
        }
    }
    return 1;
}


#define L 15 //linhas
#define C 2 //colunas
#define L2 30 //linhas da relação simetrica;

int i = 0,j = 0;
int m[L][C] = {}; //reflexiva; - matriz para o fecho reflexivo;
int m1[L2][C] = {}; //simetrica; - matriz para o fecho simétrico;


/*  Função para gerar aleatóriamente um a relação R, gravando
 *  seus valores um uma matriz 10x2 (varíavel global).
 */
void relacao() {
    srand(time(NULL));
    //preenchendo a matriz;
    gerarRelacao(m,10);
    //ordenar
    ordenarRelacao(m,10);
    //mostrar;
    printarRelacao(m,10,2);
}

/*  Função para verificar se a Relação R é reflexiva. Se não for,
 *  a função irá criar um fecho reflexivo com as tuplas que estão 
 *  faltando.
 */
void reflexiva() {
    int cont0 = 0;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    int cont4 = 0;
    
    //verificar se o fecho é reflexivo;
    for (i = 0;i < L-5;i++) {
       if (m[i][0] == 0 && m[i][1] == 0) {
           cont0++;
       }
       if (m[i][0] == 1 && m[i][1] == 1) {
           cont1++;
       }
       if (m[i][0] == 2 && m[i][1] == 2) {
           cont2++;
       }
       if (m[i][0] == 3 && m[i][1] == 3) {
           cont3++;
       }
       if (m[i][0] == 4 && m[i][1] == 4) {
           cont4++;
       }         
    }
    //acrescentar as tuplas;
    int k = 10;
    if (cont0 == 0) {
        m[k][0] = 0;
        m[k][1] = 0;
        k++;
    }
    if (cont1 == 0) {
        m[k][0] = 1;
        m[k][1] = 1;
        k++;
    }
    if (cont2 == 0) {
        m[k][0] = 2;
        m[k][1] = 2;
        k++;
    }
    if (cont3 == 0) {
        m[k][0] = 3;
        m[k][1] = 3;
        k++;
    }
    if (cont4 == 0) {
        m[k][0] = 4;
        m[k][1] = 4;
        k++;
    }
    
    if (k == 10) {
        printf("\nA relação é reflexiva, ou seja, não precisa do fecho reflexivo.");
    }
       
    //mostrar;
    printf("\nFecho Reflexivo (R*): {");
    for (i = 0;i < k;i++) {
        if (i < k - 1) {
           printf("(%d,%d),",m[i][0],m[i][1]);
        }else {
           printf("(%d,%d)} \n",m[i][0],m[i][1]);
        }
    }    
}


/*  Função para verificar se a Relação R é simétrica. Se não for,
 *  a função irá criar um fecho simétrico com as tuplas que estão 
 *  faltando.
 */
void simetrica() {
    //variaveis temporarias;
    int x = 0;
    int y = 0;
       
    //passar dos valores de uma matriz para a outra;
    for (i = 0;i < L - 5;i++) {
       for (j = 0;j < C;j++) {
           m1[i][j] = m[i][j];        
       }
    }
    
    int cont = 0;
    int k = 10;
    for (i = 0;i < L-5;i++) {
        x = m1[i][0];
        y = m1[i][1];
        for (j = 0;j < L -5;j++) {
            if (m1[j][0] == y && m1[j][1] == x) {
                cont++;
            }
        }
        if (cont == 0) {
            m1[k][0] = y;
            m1[k][1] = x;
            k++;
        }
        cont = 0;
    }
    
    //mostrar;
    if (k > 10) {
        printf("\nFecho Simétrico (R*): {");
        for (i = 0;i < k;i++) {
            if (i < k - 1) {
               printf("(%d,%d),",m1[i][0],m1[i][1]);
            }else {
               printf("(%d,%d)} \n",m1[i][0],m1[i][1]);
            }
        }  
    }else {
        printf("\nA relação é simétrica, ou seja, não precisa do fecho simétrico.");
    }   
}

void questao01() {
   printf("Questão 01 \n");
   srand(time(NULL));
   int conjuntoA [10];
   int conjuntoB [10];
   //gerando conjunto A 
   gerarConjunto(conjuntoA,10);
   //gerando conjunto B
   gerarConjunto(conjuntoB,10);
   //ordenando conjunto A
   ordenarConjunto(conjuntoA,10);
   //printando conjunto A
   printarConjunto(conjuntoA,10,"A\0");
   //ordenando conjunto B;
   ordenarConjunto(conjuntoB,10);
   //printando conjunto B
   printarConjunto(conjuntoB,10,"B\0");
   //realizando a união dos dois conjuntos
   uniaoConjuntos(conjuntoA, conjuntoB, 10);
   //realizando a intersecção dos dois conjuntos
   intersecaoConjunto(conjuntoA, conjuntoB,10);
   //realizando a diferença de dos dois conjuntos A-B
   diferencaConjunto(conjuntoA, conjuntoB, 10);
   //realizando a diferença de dos dois conjuntos B-A
   diferencaConjunto(conjuntoB, conjuntoA, 10);
   //realizando a negação do conjunto A
   negacaoConjuntoA(conjuntoA,10);
}

/*  Função para gerar um conjunto A e B aleatório e, verificar
 *  se o conjunto B é subconjunto de A.
 */
void questao02() {
    srand(time(NULL));
    int conjuntoA[20] = {};
    int conjuntoB[5] = {};
    int i,j,k,l;
    int cont = 0;
    int cont_help = 0;
    //gerando valores para o conjunto A;
    gerarConjunto(conjuntoA, 20);
    ordenarConjunto(conjuntoA,20);
    printarConjunto(conjuntoA,20, "Conjunto A\0");
    //gerando valores para o conjunto B;
    gerarConjunto(conjuntoB, 5);
    ordenarConjunto(conjuntoB,5);
    printarConjunto(conjuntoB,5, "Conjunto B\0");
    int pass = 1;
    //verificar se o conjunto B é subconjunto de A;
    do {
        for (k = 0;k < 5;k++) {
            for (j = 0;j < 20;j++) {
                if (conjuntoB[k] == conjuntoA[j]) {
                    if (cont_help == 0) {
                        cont_help++;
                        cont++;
                    }
                }else {
                    pass = 0;
                }
            }
            cont_help = 0;
        }
    }while (pass == 1);
    
    printf("\n");
    if (cont >= 5) {
        printf("\n O conjunto B é subconjunto de A! \n");
    }else printf("\n O conjunto B não é subconjunto de A! \n");
}

/*  Função para gerar um conjunto B aleatóriamente até 
 *  que ele seja subconjunto do conjunto A.
 *  
*/
void questao02_2() {
    srand(time(NULL));
    int conjuntoA[20];
    int conjuntoB[5];
    int i,j,k,l;
    int cont = 0;
    int cont_help = 0;
    do {
        cont = 0;
        //gerando valores para o conjunto A;
        gerarConjunto(conjuntoA, 20);
        ordenarConjunto(conjuntoA,20);
        //gerando valores para o conjunto B;
        gerarConjunto(conjuntoB, 5);
        ordenarConjunto(conjuntoB,5);
        //verificar se o conjunto B é subconjunto de A;
            for (k = 0;k < 5;k++) {
                for (j = 0;j < 20;j++) {
                    if (conjuntoB[k] == conjuntoA[j]) {
                        if (cont_help == 0) {
                            cont_help++;
                            cont++;
                        }
                    }                     
                }
                cont_help = 0;
            }
  }while (cont < 5); 
  printarConjunto(conjuntoA,20, "Conjunto A\0");
  printarConjunto(conjuntoB,5, "Conjunto B\0");
   if (cont >= 5) {
       printf("\n O conjunto B é subconjunto de A! \n");
   }
}

void questao03(){
    printf("Questão 03 \n");
    srand(time(NULL));
    int relacao[10][2];
    gerarRelacao(relacao,10);
    ordenarRelacao(relacao,10);
    printarRelacao(relacao,10,2);
    if(verificarReflexiva(relacao,10) == 5){
        printf("Relação reflexiva! \n");
    }else{
        printf("Relação não é reflexiva! \n");
    }
    if(verificarSimetria(relacao, 10)/2 == 5){
        printf("Relação simétrica! \n");
    }else{
        printf("Relação não simétrica! \n");
    }
    
    if(verificarAntissimetria(relacao, 10) == 1){
        printf("Relação antissimétrica! \n");
    }else{
        printf("Relação não antissimétrica! \n");
    }
    
    if(verificarTransitividade(relacao,10) == 1){
        printf("Relação transitiva! \n");
    }else{
        printf("Relação não é transitiva! \n");
    }
}

void questao04() {
    printf("Questão 4: \n");
    relacao();
    reflexiva();
    simetrica(); 
}

int main(int argc, char** argv) {
    int opc;
    int op1;
    int op2;
    
    while(opc != 5){
        printf("---------------------------------- \n");
        printf("TRABALHO PRÁTICO \n");
        printf(" 1- Questão \n");
        printf(" 2- Questão \n");
        printf(" 3- Questão \n");
        printf(" 4- Questão \n");
        printf(" 5- Sair \n");
        printf("Insira o número da questão: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                printf("---------------------------------- \n");
                questao01();
                break;
            case 2:
                printf("---------------------------------- \n");
                printf("Questão 2: \n");
                printf("\n1 - Executar apenas 1 vez.");
                printf("\n2 - Executar até achar o subconjunto.");
                printf("\n--> ");
                scanf("%d",&op1);
                switch (op1) {
                    case 1: 
                        questao02();
                        break;

                    case 2:
                        questao02_2();
                        break;
                    default: printf("\nOpção inválida!");
                }
                break;
            case 3:
                printf("---------------------------------- \n");
                questao03();
                break;
            case 4:
                printf("---------------------------------- \n");
                questao04();
                break;
            case 5:
                printf("Saindo... \n");
                break;
            default:
                printf("Opção inválida! \n");
        }
    }
    return (EXIT_SUCCESS);
}