#include <stdio.h>
#include <stdlib.h>

typedef struct Lua { //conjunto de Luas
    char NomeLua[101];
    int RaioLua;
} Lua;

typedef struct Planeta { //Conjunto de planetas
    char NomePlaneta[101];
    int RaioPlaneta;
    int QuantLuas;
    Lua* Luas;
} Planeta;

typedef struct SistemaSolar { //Conjunto de sistemas solares
    char NomeSistema[101];
    int TempoDescoberta;
    int RaioSistema;
    int QuantPlanetas;
    Planeta* PlanetasSistema;
} SistemaSolar;

typedef struct NumSistemas { //Quantidade de Sistemas Solares
    int QuantSistemas;
    SistemaSolar* SistemasSistemas;
} NumSistemas;


void LeLuas(Planeta* p, int n_luas) { //Faz a leitura do quantidade de luas e solicita o nome e o raio
    p->QuantLuas = n_luas;
    p->Luas = (Lua*)malloc(n_luas * sizeof(Lua));//malloca o tamanho para a quantidade de luas
    for (int i = 0; i < n_luas; i++) {
        printf("\n\t\t");
        scanf("%s %d", p->Luas[i].NomeLua, &p->Luas[i].RaioLua);
    }
}

void LePlanetas(SistemaSolar* s, int n_planetas) { //Faz a leitura do quantidade de planetas e solicita o nome e a quantidade de luas
    s->QuantPlanetas = n_planetas;
    s->PlanetasSistema = (Planeta*)malloc(n_planetas * sizeof(Planeta));//malloca o tamanho para a quantidade de planetas
    for (int i = 0; i < n_planetas; i++) {
        printf("\n\t");
        scanf("%s %d %d", s->PlanetasSistema[i].NomePlaneta, &s->PlanetasSistema[i].RaioPlaneta, &s->PlanetasSistema[i].QuantLuas);
        LeLuas(&(s->PlanetasSistema[i]), s->PlanetasSistema[i].QuantLuas);
    }
}

void LeSistemas(NumSistemas* s, int n_sistemas) { //Faz a leitura do quantidade de sistemas e solicita o tempo de descoberta, o nome, o raio e a quantidade de planetas
    s->QuantSistemas = n_sistemas;
    s->SistemasSistemas = (SistemaSolar*)malloc(n_sistemas * sizeof(SistemaSolar));//malloca o tamanho para a quantidade de sistemas
    for (int i = 0; i < n_sistemas; i++) {
        printf("\n");
        scanf("%d %s %d %d", &s->SistemasSistemas[i].TempoDescoberta, s->SistemasSistemas[i].NomeSistema, &s->SistemasSistemas[i].RaioSistema, &s->SistemasSistemas[i].QuantPlanetas);
        LePlanetas(&(s->SistemasSistemas[i]), s->SistemasSistemas[i].QuantPlanetas);
    }
}

int AvaliaMelhorSistema(const SistemaSolar* sistemaA, const SistemaSolar* sistemaB) { // Faz toda a comparação entre sistemas para descobrir qual o mais interessante
    if (sistemaA->RaioSistema > sistemaB->RaioSistema) {// Maior Raio
        return 1;
    } else if (sistemaA->RaioSistema < sistemaB->RaioSistema) {
        return 0;
    }

    if (sistemaA->QuantPlanetas > sistemaB->QuantPlanetas) {// Maior quantidade de planetas
        return 1;
    } else if (sistemaA->QuantPlanetas < sistemaB->QuantPlanetas) {
        return 0;
    }

    if (sistemaA->QuantPlanetas > 0) { //Qual sistema possui o maior planeta
        int maiorRaioPlanetaA = sistemaA->PlanetasSistema[0].RaioPlaneta;
        int maiorRaioPlanetaB = sistemaB->PlanetasSistema[0].RaioPlaneta;

        for (int i = 1; i < sistemaA->QuantPlanetas; i++) {
            if (sistemaA->PlanetasSistema[i].RaioPlaneta > maiorRaioPlanetaA) {//Passa por todos os planetas do sistema A
                maiorRaioPlanetaA = sistemaA->PlanetasSistema[i].RaioPlaneta;
            }
        }

        for (int i = 1; i < sistemaB->QuantPlanetas; i++) {
            if (sistemaB->PlanetasSistema[i].RaioPlaneta > maiorRaioPlanetaB) {//Passsa por todos os planetas do sistema B
                maiorRaioPlanetaB = sistemaB->PlanetasSistema[i].RaioPlaneta;
            }
        }

        //Pega o maior planeta do sistema A e compara com o maior planeta do sistema B e retorna o resultado
        if (maiorRaioPlanetaA > maiorRaioPlanetaB) {
            return 1;
        } else if (maiorRaioPlanetaA < maiorRaioPlanetaB) {
            return 0;
        }
    }

    if (sistemaA->PlanetasSistema[0].QuantLuas > sistemaB->PlanetasSistema[0].QuantLuas) {//Qual sistema possui a maior quantidade de luas
        return 1;
    } else if (sistemaA->PlanetasSistema[0].QuantLuas < sistemaB->PlanetasSistema[0].QuantLuas) {
        return 0;
    }

    if (sistemaA->PlanetasSistema[0].QuantLuas > 0) {//Qual planeta possui a maior lua
        int maiorRaioLuaA = sistemaA->PlanetasSistema[0].Luas[0].RaioLua;
        int maiorRaioLuaB = sistemaB->PlanetasSistema[0].Luas[0].RaioLua;

        for (int i = 0; i < sistemaA->QuantPlanetas; i++) {
            for (int j = 0; j < sistemaA->PlanetasSistema[i].QuantLuas; j++) {
                if (sistemaA->PlanetasSistema[i].Luas[j].RaioLua > maiorRaioLuaA) {//Passa por todas as luas do sistema A
                    maiorRaioLuaA = sistemaA->PlanetasSistema[i].Luas[j].RaioLua;
                }
            }
        }

        for (int i = 0; i < sistemaB->QuantPlanetas; i++) {
            for (int j = 0; j < sistemaB->PlanetasSistema[i].QuantLuas; j++) {
                if (sistemaB->PlanetasSistema[i].Luas[j].RaioLua > maiorRaioLuaB) {//Passsa por todas as luas do sistema B
                    maiorRaioLuaB = sistemaB->PlanetasSistema[i].Luas[j].RaioLua;
                }
            }
        }

         //Pega a maior lua do sistema A e compara com a maior lua do sistema B e retorna o resultado
        if (maiorRaioLuaA > maiorRaioLuaB) {
            return 1;
        } else if (maiorRaioLuaA < maiorRaioLuaB) {
            return 0;
        }
    }

    if (sistemaA->TempoDescoberta > sistemaB->TempoDescoberta) {//Menor tempo de descobrimento
        return 1;
    } else if (sistemaA->TempoDescoberta < sistemaB->TempoDescoberta) {
        return 0;
    }
}

void Ritacao(SistemaSolar* sistemas, int esquerda1, int direita1, int esquerda2, int direita2) {
    int tamanho1 = direita1 - esquerda1;
    int tamanho2 = direita2 - esquerda2;

    // Criar cópias dos vetores de sistemas solares
    SistemaSolar* copia1 = (SistemaSolar*)malloc(tamanho1 * sizeof(SistemaSolar));
    SistemaSolar* copia2 = (SistemaSolar*)malloc(tamanho2 * sizeof(SistemaSolar));

    // Copiar os sistemas solares para as cópias
    for (int i = 0; i < tamanho1; i++) {
        copia1[i] = sistemas[esquerda1 + i];
    }

    for (int i = 0; i < tamanho2; i++) {
        copia2[i] = sistemas[esquerda2 + i];
    }

    int i = 0, j = 0, k = esquerda1;

    while (i < tamanho1 && j < tamanho2) {
        if (AvaliaMelhorSistema(&copia1[i], &copia2[j])) {
            sistemas[k] = copia1[i];
            i++;
        } else {
            sistemas[k] = copia2[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes, se houver, de copia1
    while (i < tamanho1) {
        sistemas[k] = copia1[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes, se houver, de copia2
    while (j < tamanho2) {
        sistemas[k] = copia2[j];
        j++;
        k++;
    }

    // Libera memória das cópias
    free(copia1);
    free(copia2);
}


void BromeroSort(SistemaSolar* sistemas, int esquerda, int direita) {//BromeroSort igual ao codigo do PDF da atividade
    int tamanho = direita - esquerda;
    if (tamanho == 1) {
        return; // sistema já ordenado
    }
    if (tamanho % 2 == 1) {
        BromeroSort(sistemas, esquerda, direita - 1);
        Ritacao(sistemas, esquerda, direita - 1, direita - 1, direita);
        return;
    }
    int meio = (direita + esquerda) / 2;
    BromeroSort(sistemas, esquerda, meio);
    BromeroSort(sistemas, meio, direita);
    Ritacao(sistemas, esquerda, meio, meio, direita);
}


int main() {
    int n_sistemas;
    scanf("%d", &n_sistemas); //Solicita a quantidade de sistemas

    NumSistemas sistemas;
    LeSistemas(&sistemas, n_sistemas);//Chama a função que faz a leitura dos sistemas

    BromeroSort(sistemas.SistemasSistemas, 0, n_sistemas);//Chama a função de separação do BromeroSort

    for (int i = 0; i < n_sistemas; i++) {
        printf("\n%s", sistemas.SistemasSistemas[i].NomeSistema);//imprime na tela os sistemas em ordem do mais interessante para o menos interessante
    }


    for (int i = 0; i < n_sistemas; i++) {//Libera memória alocada
        for (int j = 0; j < sistemas.SistemasSistemas[i].QuantPlanetas; j++) {
            free(sistemas.SistemasSistemas[i].PlanetasSistema[j].Luas);
        }
        free(sistemas.SistemasSistemas[i].PlanetasSistema);
    }
    free(sistemas.SistemasSistemas);

    return 0;
}