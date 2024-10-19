# 🌌 Ordenador de Sistemas Solares

## 📜 Descrição do Projeto

Este projeto implementa um algoritmo para ordenar sistemas solares recém-descobertos com base em características consensuais entre astrônomos. A ordenação facilita a priorização dos estudos dos cientistas, que estão sob pressão para fazer grandes descobertas rapidamente.

### ⭐ Características de Ordenação

Os sistemas solares são ordenados com base nas seguintes características, em ordem de prioridade:

1. **Raio do sol do sistema** ☀️.
2. **Quantidade de planetas no sistema** 🌍.
3. **Raio do maior planeta do sistema** 🌌.
4. **Quantidade de luas no sistema** 🌙.
5. **Raio da maior lua do sistema** 🌑.
6. **Tempo de descoberta do sistema** ⏳.

### 📋 Requisitos

O código foi desenvolvido para funcionar com grandes quantidades de dados, já que a entrada pode conter até **1 milhão** de sistemas solares, com cada sistema possuindo até **100 planetas** e cada planeta até **100 luas**.

### 📏 Regras de Ordenação

Um sistema solar **A** será considerado mais interessante que um sistema solar **B** se, nesta ordem:

1. O raio do sol de **A** for maior que o raio do sol de **B**.
2. O sistema **A** tiver mais planetas que o sistema **B**.
3. O maior planeta de **A** for maior que o maior planeta de **B**.
4. O sistema **A** tiver mais luas que o sistema **B**.
5. A maior lua de **A** for maior que a maior lua de **B**.
6. O tempo de descoberta de **A** for menor que o de **B**.

## 📥 Entrada

A entrada segue um formato padronizado:

1. **N**: Quantidade de sistemas solares.
2. Para cada sistema, os dados são fornecidos na seguinte ordem:
   - **T**: Tempo de descoberta do sistema.
   - **S**: Nome do sistema.
   - **R**: Raio do sol do sistema.
   - **P**: Quantidade de planetas no sistema.

3. Para cada planeta, os dados são fornecidos na seguinte ordem:
   - **Nome do planeta**, **raio do planeta**, **quantidade de luas**.
   - Para cada lua, os dados são fornecidos na seguinte ordem:
     - **Nome da lua**, **raio da lua**.

A entrada utiliza tabs (`\t`) para indicar o nível hierárquico dos elementos. Sistemas solares não possuem tabulação, planetas possuem uma tabulação e luas possuem duas tabulações.

### 🔒 Restrição

- 1 ≤ **N** ≤ 1.000.000 (Número de sistemas solares).
- 1 ≤ **Ti** ≤ 1.000.000 (Tempo de descoberta de cada sistema).
- Cada nome possui entre 1 e 100 caracteres.
- O raio de qualquer astro (sol, planeta, lua) é no máximo 10.000.
- Cada sistema possui no máximo 100 planetas, e cada planeta possui no máximo 100 luas.

### 📤 Saída

O programa deve imprimir os sistemas solares ordenados de acordo com as regras de prioridade descritas anteriormente.

### ⚙️ Complexidade

O algoritmo é otimizado para lidar com até 1 milhão de sistemas solares, utilizando técnicas de ordenação eficientes para garantir desempenho aceitável, mesmo com a quantidade máxima de dados.

### 📚 Exemplo de Entrada

```text
6                           // # Sistemas Solares
3 X1dhcdfx35 889 0              // Sistema #1 | Raio | # Planetas
1 nmok0lee2 298 2               // Sistema #2 | Raio | # Planetas
    V8VP5P 743 2                    // Planeta #1 | Raio | # Luas
        SKZJqLg 538                     // Lua #1 | Raio
        VFgWcFM3 978                    // Lua #2 | Raio
    ueJSO 805 1                     // Planeta #2 | Raio | # Luas
        phuVmf 484                      // Lua #1 | Raio
2 jW2Ol 557 1                   // Sistema #3 | Raio | # Planetas
    LUTmBvC8C 901 1             // ...
        zzMpnv 636
20 wP30Hu 944 3
    nBSykm3G 187 1
        Hbf1J58 932
    pUA1xD1wO 980 4
        bfFx 357
        MkEM 438
        cSLdX 222
        XHbj8C 137
    yzYmj 316 3
        WZepWXuYaW 471
        u4Fz2 418
        kqYsyi 9
kNahmOcQLr 298 3
    wIO 468 3
        Ryl4D3A 358
        QBPGgLD 659
        bsIGvPap 311
    ke2ice 348 0
    YxjJRC 645 4
        r6TwFh 873
        u8bBOSu 736
        dxmIJWNT 377
        ih6PPWGt 611
YRGgCqY 557 1
    t7ipn3 207 1
        CwDd 268
```

### 📊 Exemplo de Saída Esperada

```text
wP30Hu                      // Maior tamanho
X1dhcdfx35                  // Segundo maior tamanho
jW2Ol                       // Empate no tamanho e # de planetas, mas planeta MAIOR
9YRGgCqY                    // Empate no tamanho e # de planetas, mas planeta menor
kNahmOcQLr                  // Empate no tamanho, mas mais planetas
nmok0lee2                   // Empate no tamanho, mas menos planetas
