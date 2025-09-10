// formas de escolher b elementos entre a possiveis sem ordem (com ordem multiplica por b!)
// lembrar que pode ser expresso como a * (a-1) * ... * (a-b+1) / b!
// tambem temos que comb(a, b) = comb(a-1, b-1) + comb(a-1, b) (tri pascal)
// se b > a || b < 0, comb(a, b) == 0
// se a < 0, comb(a, b) == 0
int comb(int a, int b) {
    return fat[a] * fati[b] * fati[a-b];
}


// Inclusao-Exclusao
// | A U B U ... U C |
// Soma os termos que incluem quantidade impar de conjutos
// Subtrai os termos que incluem quantidade par de conjuntos 
// Por termo entende-se a cardinalidade da interseccao de partes dessess conjuntos


// Stars and Bars
// Formas de colocar n objetos iguais em k caixas
// pois devemos escolher n posicoes pros objetos, e as outras k-1 sao as separacoes entre as caixas
// comb(n+k-1, n)

// Numero de somas de numeros nao-negativos
// x1 + x2 + ... + xk = n, xi >= 0
// Aplicacao direta de stars and bars comb(n+k-1, n)

// Numero de somas com lower bound
//    x1  + x2  + ... + xk  = n, xi >= ai
// => x1' + x2' + ... + xk' = n - a1 - a2 - .. - ak
// cai no caso anterior, ja que agora xi' >= 0

// Numero de somas com inteiros >= 1
// x1 + x2 + ... + xk = n, xi >= 1
// nao podemos ter duas barras consecutivas (implicaria um elem 0), logo temos n-1 posicoes pra colocar k-1 barras
// comb(n-1, k-1)

// Numeros de somas com upper bound
// x1 + x2 + ... + xk = n, xi <= b
// resolve com inclusao-exclusao, basicamente, a gente faz na quantidade de caras que excedem o limite b
// Sum(i=0 -> k) comb(k, i) * comb(n + k - 1 - (b+1)*i, d-1)


// Burnside Lemma
// Forma de contar o numero de combinacoes de forma que so um representante eh contado para um grupo simetrico
// Sum(k=1 -> n) c(k)/n
// onde ha n formas de mudar uma combinacao
// e existem c(k) combinacoes que nao trocam de grupo ao aplicar a k-esima forma

// Numeros de Catalan
// Numero de expressoes de parenteses balanceados, caminhos no grid que nao passam da diagonal, arvores binarias, etc.
// Formula 1: Cn = comb(2*n, n) - comb(2*n, n-1)
// Formula 2: Cn = Sum(i=0 -> n-1) Ci * C(n-i-1)

// Teorema do taco de hoquei
// Sum(r=k -> n) comb(r, k) = comb(r+1, k+1)

// Identidade importante
// n*comb(n-1, k-1) = (k)*comb(n, k)

// Valor esperado:
// E(X) = sum i * p(x == i) (valor do evento vezes a chance dele ocorrer)
// E(X) = sum p(x >= i)

// Soma dos n primeiros termos da PG
// a1 * (q**n - 1) / (q-1);

// Soma de PG infinita (0 <= |q| < 1)
// a1 / (1 - q)

// Soma dos n primeiros termos da PA
// n * (a1 + an) / 2

// Probabilidade Condicional
// Prob de A ocorrer dado que B ocorre
// P(A|B) = P(A inter B) / P(B)

// Distribuicao Binomial
// n tentativas sao feitas e a probabilidade de uma unica tentativa acertar eh p
// X conta o numero de acertos
// P(X = x) = p**x * (1-p)**(n-x) * comb(n, x)
// E(X) = p*n

// Distribuicao geometrica
// tentativa de acerto eh x, e continuamos ate acertar pela primeira vez
// X conta o numero de tentativas necessarias
// P(X = x) = (1-p)**(x-1) * p
// E(X) = 1/p