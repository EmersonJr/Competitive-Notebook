// PI = acos(-1)

// area de um poligono, retorna 2*area
int area(vector<point> &polygon) {
    int a = 0;

    rep(i, 0, tam(polygon)) {
        a += polygon[i] ^ polygon[(i+1)%tam(polygon)];
    }

    return abs(a);
}

// numero de lattice points em um segmento de reta (a,b) -> (c,d):
// gcd(c-a, d-b) + 1

// lattice points em um poligono
// com base no teorema de Pick
// retorna um pair onde ff == numero de pontos dentro e ss == numero de pontos na borda
pii lattice_points(vector<point> &polygon) {
    int in, sobre = 0;
    rep(i, 0, tam(polygon)) {
        point p = polygon[i], q = polygon[(i+1)%tam(polygon)];

        sobre += abs(gcd(q.x-p.x, q.y-p.y)) + 1;
    }
    sobre -= tam(polygon);

    in = (area(polygon) - sobre + 2)/2;
    return {in, sobre};
}

// numero de lattice points  na circunferencia
// r > 0
int lattice_circ(int r) {
    int ans = 4;

    rep(x, 1, r) {
        int ySquare = r*r - x*x;
        int y = sqrt(ySquare);

        if (y*y == ySquare) ans += 4;
    }

    return ans;
}

// numero de triangulos de lado 1 dentro de um hexagono regular
lado_tri = sides[0] + sides[1] + sides[2];
ans = lado_tri * lado_tri - sides[0] * sides[0] - sides[2] * sides[2] - sides[4] * sides[4];

// produto vetorial de 3 pontos (uso pra saber a pos relativa de um ponto em relacao a um segmento de reta)
int cross3(point s1, point s2, point p) {
    point vector1, vector2;

    vector1.x = s2.x - s1.x;
    vector1.y = s2.y - s1.y;
 
    vector2.x = p.x - s1.x;
    vector2.y = p.y - s1.y;
 
    return vector1 ^ vector2;
}

// verifica se um ponto esta sobre um segmento de reta, ja sabendo que esse ponto eh colinear
bool sobreSegmento(point s1, point s2, point p) {
    return p.x >= min(s1.x, s2.x) && p.x <= max(s1.x, s2.x) && p.y >= min(s1.y, s2.y) && p.y <= max(s1.y, s2.y);
}

// verifica se 2 segmentos de reta intersectam
bool intersect(point s1, point s2, point t1, point t2) {
    int t1_rel_s = cross3(s1, s2, t1);
    int t2_rel_s = cross3(s1, s2, t2);
    int s1_rel_t = cross3(t1, t2, s1);
    int s2_rel_t = cross3(t1, t2, s2);
 
    if (t1_rel_s != t2_rel_s && s1_rel_t != s2_rel_t)
        return true;
 
    if (t1_rel_s == 0 && sobreSegmento(s1, s2, t1))
        return true;
    
    if (t2_rel_s == 0 && sobreSegmento(s1, s2, t2))
        return true;
 
    if (s1_rel_t == 0 && sobreSegmento(t1, t2, s1))
        return true;
 
    if (s2_rel_t == 0 && sobreSegmento(t1, t2, s2))
        return true;
 
    return false;
}