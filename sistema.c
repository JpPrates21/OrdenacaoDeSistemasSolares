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