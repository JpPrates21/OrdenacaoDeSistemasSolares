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