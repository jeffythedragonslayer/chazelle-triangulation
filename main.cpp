/* If we remove a pair of mutually visible points from the double boundary of a simple polygonal curve, then no chord can connect the two resulting pieces. */
void lemma21()
{
}

/* Let A1,...,Ak be the counter clockwise enumeration of the (oriented) arcs of a nonempty submap region (as induced from the region's orientation).
 * Then each Ai is oriented clockwise with respect to 6C.  Moreover, the sequence A1,..,Ak also occurs clockwise around 6C. */
void lemma22()
{
}

/* If C is a polygonal curve with n vertices, any y-granular conformal submap of the (possibly augmented) visibility map of C has O(n/y + 1) regions and each region is bounded by O(y) edges. */
void lemma23()
{
}

/* If a B1 u B2 (resp. b B1 u B2), let a' (resp. b') be the first (resp. last) point of ab n A encountered when traversing the diametrical chord ab from a to b.
 * The points a and b (which might not exist) subdivide A into a total of one, two, or three connected curves, each of which is shielded from some Bj (not necessarily 
 * the same j for all curves).  Furthermore, an appropriate Bj can be identified simply on the basis of a, b, c, d, a', b'. */
void lemma24()
{
}

/* It is possible to compute the fusion S of S1 and S2 in
 * O((n1/y1 + n2/y2 + 1)(f(y2) + log(n1+n2)))
 * time */
void lemma31()
{
}

/* Given two arcs A1 and A2 of the same region of S, assume that they have a pair of mutually visible points,
 * one of which is a vertex of 6C (meaning that, say, A1 contains a vertex v which is also a vertex eof 6C and is such that the point of 6C seen by v lies in A2).
 * Then we can find a point of A1 (not necessarily a vertex of 6C that sees A2 in time O(f(y2)g(y2)(h(y2) + log y2)) */
void lemma32()
{
}

/* Let A1,...,Ak be the clockwise circular sequence of arcs around a region of S.  If k > 4, then there exist i, j, such that
 * (i) i - j != -1, 0, 1 (mod k) and
 * (ii) Ai has a vertex of 6C that sees Aj (with respect to C). */
void lemma33()
{
}


/* The submap S can be made conformal in time
 * O((n1/y1 + n2/y2 + 1)f(y2)g(y2)h(y2) + log y2)). */
void lemma34()
{
}

/* Let C1 and C2 be two polygonal curves of n1 and n2 vertices, respectively, whose union forms a connected vertex-to-vertex piece of the input
 * (simple and nonclode) polygonal curve P.  Suppose that we are given a normal-form yi-granular conformal submap of each V(Ci), where y1 <= y2,
 * along with the ray-shooting and arc-cutting oracles necessary for merging.  Then, for any y >= y2, it is possible to compute a normal-form y-granular conformal submap of V(C)
 * in time O((n1/y1 + n2/y2 + 1)f(y2)g(y2)(h(y2) + log(n1+n2))). */
void lemma35()
{
}

/* Let C be a connectexd vertex-to-vertex piece of the input polygonal curve P and let m be its number of vertices.
 * Let S be a normal-form y-granular conformal submap of V(C).
 * Then it is possible to preprocess S in O(m(log m)/y+1) time so that ray-shooting within S can be done in time O(y^(1/3)m^(2/3)). */
void lemma36()
{
}

/* Suppose that all grades less than lambda have been processed.  Then, given any portion D of P of the form va,...,vb, where 2^l-1 < b - a <= 2^l, we can compute
 * a canonical submap of V(D) in time proportional to l^2(log l)2^(1-B/3+4B^2/3). */
void lemma41()
{
}

/* Let l be a any positive grade and let C be an arbitrary chain in any grade l >= l.  If a 2^[Bl]-granular conformal submap of V(C) is available in normal form,
 * then it is possible to compute V(C) in time at most (c-1/l)2^l, where c is some constant large enough. */
void lemma42()
{
}

/* It is possble to compute the visibility map of a simple polygonal curve, and, hence, a triangulation of a simple polygon, in linear time */
void theorem43()
{
}

int main()
{
}
