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
/* We can assume that both B1 and B2 are nonempty and that A intersects ab (else the lemma is trivially correct).
 * By attaching B1 U B2 to A, we obtain a simple closed curve within D, which is, therefore, the boundary of a subset R of D homeomorphic to a disk.
 * If a (resp. b) belongs to B1 U B2, then the segment aa' (resp. bb') lies within R and thus, acting like a chord, subdivides R into two regions.
 * Since aa' and bb' cannot intersect, together they subdivide R into two regions.  The boundary of each such region intersects the boundary of D in
 * a single connected arc and therefore avoids one Bi (outside of a and b) entirely.  Figure 2.8 illustrates the two possbile cases; note that the third case, where the counterclockwise traversal from c to d
 * avoids a and b, was eliminated earlier, since it corresponds to a situation where one of the Bi's is empty.  None of the curves obtained by removing a' and b' (if they exist) from A can belong
 * to more than one of the subdividing regions, so each of them is shielded from some Bi.  Which one can be determined by simple examination of the relative order of the poinst a, b, c, d, a', b',
 * around the boundary of R. */
}

/* It is possible to compute the fusion S of S1 and S2 in
 * O((n1/y1 + n2/y2 + 1)(f(y2) + log(n1+n2)))
 * time */
void lemma31()
{
	/* We restrict our attention to the task of fusing S1 into S2, the other case being similar.
 * We have already shown that the start-up phase leads to a situation which satisfies the loop invariant,
 * so it sufficies to establish the correctness of the inner loop past a0.
 * In case (i) we know that aj lies in R (actually in its interior) and sees a point of 6C2, so invariant (B) is satisified.
 * How about (A)?  We made the claim that ak,...,aj-1 all see points of 6C1.  But actually the negation of (i0
 * for ak,...,aj-1 is not strong enough to reach the necessary conclusion about what ak,...,aj-1 must see.
 * Any of these points (if they exist) either sees 6C1, or lies outside of R.
 * Why should lying outside R imply seeing 6C1?  Suppose that, for some l (k <= l < j), al lies in region R' distict
 * from R (like ak+1 in Figure 3.2.1 but also sees 6C2.  We derive a contradiction.
 * Let A denote the directed portion of 6C1 as we go from p ta a1 clockwise, and let q (resp. q') be the point of 6C seen by p (resp. a1).  The union of A, the chords pq and a'q', and the portion B of 6C2 running clockwise (with respect to C2) from q' to q forms the boundary of a simple ploygon (Figure 3.3).  Since the dual graph of a submap is a tree, there is a unique exit chord ab of R that leads to R' (note that ab need not be an exit chord of R', since there might be one or even several regions separating R from R').  Because B runs from R' to R it passes through one of the chord endpoints, say, a.  Let a' be the point of ab n A first encountered as we go from a to b along the chord.  Note that ab cuts through A, so a' is well defined.  The points a and a' see each other with respect to 6C, and a' lies in Ak, for some h between k and l inclusive.
 *
 * Because, in clockwise order around 6C, the point a' is leaving R locally, it cannot be equal to p.
 * Therefore, the inequality l < j implies that case (ii) must have already aoccurred when the running variable j was assigned to some integer between k and l, which is impossible.
 *
 * Having shown that the loop invariant remains satisfied through case (i), we must do the same with case (ii).
 * Let A now denote the directed portion of 6C1 as we go from p to aj clockwise.
 * The new assignment of p is the last paint of A, distinct from p, that sees an endpoint of an exit chord of R.
 * Certainly, the new assignment of the current region satisfies invariant (B).  Figure 3.2.1 shows three candidate endpoints, with q3 winning the contest.  Turning now to invariant (A), we must prove our claim that the points of 6C seen by ak,...,aj-1 all belong to 6C1.  We omit the proof since it is identical to the previous one, with the role of aj now played by p'.
 *
 * What about termination?  Obivously, the three cases rule out an infinite loop.
 * Every time we fall in either of the two cases (i) or (ii) we determine more visibility information, so that all visiiblity relations are known from a0 all the way to the current position of p.  How about the last iteration, the one leading to case (iii)?  We claimed that all ai's (k <= i < m+1) see points of 6C1.  This follows from the proof of the last paragraph, which showed that if a1 sees 6C2, then either al lies in R (case (i)) or it does not, but then, we must fall in case (ii) after leaving p but upon or prior to getting to al.  The proof of correctness is now complete.
 *
 * Let us now analyze the complexity of the algorithm.  To test whether aj lies in R can be done in O(f(y2)) time by using the ray-shooters for each arc that bounds R: first we find which point of an arc is hit by a ray of light shot from aj in its assigned chord direction.  If there is no hit on any arc, aj is not in R.  Else, let s be the first point hit by the ray over all the arcs of R.  Whether aj lies in R or not can be directly inferred from the local orientation of the hit at s and which side of the double boundary is hit.  This is because, as we should recall, arc-structures encode on which side(s) of the boundary the arcs lie.  If aj lies in R, then s is the point of 6C2 seen by aj with respect to C2.  Next we use local shooting within S1 to determine the point t of 6C1 hit by a ray of light shot from aj in its assigned direction.  Note that most often (i.e. when 0<j<=m) aj is the endpoint of a chord of S1 so t is just the other endpoint of the chord.  Now that we know which points of 6C1 and 6C2 the point aj can see, we can immediately derive the point of 6C that it sees and, from there decide whether we are in case (i).
 * The test takes O(f(y1)+f(y2)) = O(f(y2)) time (since f is nondecreasing and y1<=y2).  This cost also includes the start-up phase.
 *
 * Regarding (ii), we must assess how fast we can find the point of 6C that is seen by an endpoint a of a given exit cord ab of R.  Actually, we must find that point only if it belongs Aj.  So, we can shoot a ray of light from a toward Aj in the appropriate direction and see what happens, which takes O(f(y1)) time.  If we do not get a hit, or if the hit does not lie on ab, or if it occurs before p along Aj, or if it does not have the proper orientation which lets a see Aj without the other side of the double boundary of Aj interfering (a constant-time test), then the endpoint can be disqualified.  Otherwise, we must find whether the point s of Aj hit by the ray of light can see a with respect to C:
 * the problem here is that other arcs Ai (i != j) might get in the way.  Using the local shooting in S1, however,
 * we can shoot a ray of light from s toward a.  We aim in the natuarl shooting direction from s since we have already ruled out that the "companion" point of s should prevent it from seeing a.  The point t hit by the ray is found in O(f(y1)) time.  If shooting from s to t passes through a, then s and a see each other with respect to C and we fall in case (ii), else we know that case (ii) cannot occur with respect to Aj and the endpoint a of the chord ab (although it might occur with respect to other endpoints of exit chords in R).  This shows that testing case (ii) takes O(f(y1)) time.
 *
 * We thus have shown that every elementary test (i), (ii) can be performed in O(f(y2)) time.
 * At each such test we advance through the list of Ai's or we report a pair of visible points in 6C,
 * one of which is an endpoint of an exit chord of S2.
 * These reports are never duplicated because we always move forward among the Ai's
 * Therefore, to discover all the chords of the fusion S of S1 and S2 takes time O(mf(y2)) time,
 * where m is the total number of arcs and exit chords in S1 and S2.
 * By Lemma 2.3, m is O(n1/y1+n2/y2+1).  Note that among the chords to be included in the fusion S,
 * we not only have the newly discovered chords that connect 6C1 and 6C, as well as the old chords of S1 and S2 that still form visible pairs of points with respect to C, but we also have all the null-length chords of S1 and S2 as well as the thords incident upon the vertices of 6C resulting from the duplication of the vertex C1 n C2; this last category is where null-length chords originate.
 * After fusing S1 (resp. S2) into S2 (resp. S1), we have all the chords of the submap S and we can set it up in normal form quite easily.  In order to allow for canoncial vertex enumerations, let us sort the endpoints of these chords along 6C, which is done by sorting the names of the edges of P on which these arcs abut, and then sorting the endpoints falling within the same edges by considering y-coordinates.  This allows us to set up the required arc-sequence table.
 * Note that merging can also be used instead of sorting but this step is not the dominant cost, anyway.
 * With this information it is now straightforward to set up the tree of the submap S, along with all the necessary arc-structures and their relevant pointers.  Since the submap might not be conformal we dispense with the tree decomposition at this point.  Very conservatievly, all this work can be done in time
 *
 * O((n1/y1 + n2/y2 + 1)log(n1+n2)).
 *
 * Putting everything together, we derive the upper bound of 
 *
 * O((n1/y1 + n2/y2 + 1)(f(y2) + log(n1+n2)))
 *
 * on the time needed to complete the fusion of S1 and S2. */
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
	/* Recall that the region is associtade with a subtree of the visibility tree of C.
 * If S contains chords incident upon no vertices of 6C, then we must include these chords as well and speak of the tree of the augmented visibility map of C.  Let us add to the subtree in question the edges that connect it to the rest of the visibility tree.  With respect to this augmented subtree, each exit chord of the region is associated with a distinct node of degree 1 (but the converse may not be true).
 * Note that some of these exit chords might be of zero length.  Consider the Steiner minimal tree of these particular degree-1 nodes (i.e., the smallest connected set of edges that join these nodes together), and for simplicity form a tree homomorphic to it by ignoring nodes of degree 2.  Now embed this new tree in the plane and enclode it by a simple closed curve that connects together all its degree-1 nodes (Fig. 3.5).  By using an embedding that preserves the local orientation of the edges around the nodes, the area inside the closed curve is partitioned into k faces, each corresponding to a distinct arc Ai.  Because there are at least five degree-1 nodes and the maximum node degree is 4, it is immediate that at least one edge of the tree must be indicent upon two faces associated with Ai, and Aj, respectively, where i-j != -1, 0, 1 (mod k).  (For a simple proof, try all possible cases with five or more nodes.)  Of all the chords in the region only the exit chords might fail to be incident upon at least on vertuex of 6C.  It follows that the edge in question corresponds to one or several chords of the original, nonaugmented V(C) that connect Ai and Aj. */
}


/* Equipped with the two previous lemmas, making S conformal is now quite easy.  Recall that although S might not be conformal right after fusion, none of its regions has more than a bounded number of arcs.
 * For any region with more than four arcs, let us apply lemma 3.2 to every pair of nonconsecutive arcs until we find a chord which we can add to S.  We iterate on this process until no region has more than four arcs.
 * Note that although S keeps changing, Lemma 3.2 always holds since region arcs can only become smaller.  Lemma 3.3 tells us that this chord addition process will not stop until S becomes conformal.
 * Since the total number of arcs in S is O(n1/y1 + n2/y2 + 1), we conclude:
 *
 * The submap S can be made conformal in time
 * O((n1/y1 + n2/y2 + 1)f(y2)g(y2)h(y2) + log y2)). */
void lemma34()
{
}

/* Maintaining Granularity
 *
 * Since by making S conformal we did not remove any exit chord, it is still the case that, as observed in the proof of Lemma 3.2, no arc has more than y2 edges.
 * Therefore, S is conformal and y2-semigranular.  We must now check whether the second citerion for y2-granularity holds.  This criterion says that contracting any edge of the submap
 * tree that is incident upon at least one node of degree less than 3 produces a new node whose weight exceeds y2.  This is very easy to enforce: if an edge does not pass the test,
 * we just contract it by removing its corresponding exit chord (and those endpoints that are not vertices of 6C).  Note that this will not cause a violation of the first criterion,
 * since the size of all the arcs will always remain within y2.  Similarly, the removal keeps the submap conformal.  We process each exit chord in turn and check whether it is removable.
 * Chords need be processed only once since the removals cannot make any chord removable if it was not already so before.  Therefore, y2-granularity, and more generally y-granularity,
 * for any y >= y2, can be enforced in this nondetermininistic fashion in time linear in the size of the submap tree, that is, O(n1/y1 + n2/y2 + 1).  We can now put S in normal form,
 * which includes computing its tree decomposition.  As we discussed earlier, this can be done very simply in time O((n1/y1 + n2/y2 + 1)log(n1+n2)).  With the inconsequential assumption that
 * yi = O(n1+n2), we derive the following result from Lemmas 3.1 and 3.4:
 *
 * Let C1 and C2 be two polygonal curves of n1 and n2 vertices, respectively, whose union forms a connected vertex-to-vertex piece of the input
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
	/* In O(lambda) time we can partition D into j <= 2*lambda chains, D1,...Dj, in grades less than lambda, with at most two chains per grade. 
 * This implies that, for each i = 1, ..., j a canonical submap S of V(Di) is available.  Let y be the granularity of a canonical submap of V(D); we have y = 2^(Bl)
 * Since the granularity of canonical submap grows monotonically with the size of the underlying polygonal curve, we can trivially reset the granularity of each Si to y (Section 3.3).
 * The time to do that is proportional to the total number of chords in all the Si's which, from Lemma 2.3, is on the order of E0<=k<=lambda^2^[Bk], that is, O(2^lambda(1-B)).
 * Let us now merge these submaps two-by-two (D1 with D2, D3 with D4, etc.).  More generally, we consider a perfectly balanced binary tree whose leaves are in the bijection with Di's and we merge submaps bottom-up
 * by following the tree pattern.  Application of Lemma 3.5 results in a canonical submap of V(D) provided, of course, that the required oracles are available.  But are they?
 * Notice that during any merge any arc a in either of the two input submaps consists of at most y edges.  Therefore, any subarc a' <= a can be subdivided into a constant number of contiguous pieces
 * (with no double-backing) whose corresponding portions of P consist of a single line segments (at most two of them) and vertex-to-vertex pieces of P, each with at most 2^[Bk] edges.
 * Each of these pieces can be partitioned into a collection of O(lambda) chains in grades at most [Blambda].  Our work at previous grades ensures that we have ray-shooting structures for the canonical submaps
 * associated with these chains.  Thus, to shoot a ray toward a', we shoot toward each of the O(lambda) subarcs of its decomposition and determine the closest hit (if any.)
 * Shooting towards a single edge subarc is trivial.  Shooting toward any other subarc makes use of the shooting structure of a canonical submap for a chain in grade u < [Blambda].
 * Assuming that [Blambda] < lambda (which is true for lambda large enough) all these shooting structures have been computed and therefore, by Lemma 3.6, ray-shooting can be done in time O(2^[Bu]/3+2u/3),
 * which is O(2^B^2*lamda/3+2Blambda/3).  Since there are O(lambda) subarcs, it follows that the ray-shooting oracle can be implemented so that
 *
 * f(y) = lambda*2^[B^2*lambda/3+2*B*lambda/3].
 *
 * As we mentioned, the subarc a' is decomposed into at most two single-edge pieces, along with O(lambda) pieces for which we have conformal submaps of granularity at most 2^[B[Blambda]].
 * We verify that all the requirements of the arc-cutting oracle are satisfied by this decomposition, so that we can set
 *
 * g(y) = O(lambda)
 *
 * and
 *
 * h(y) <= 2^[B[B*lambda]]
 *
 * To appreciate the connection between the left- and right-hand sides of these relations, recall that y and lambda are related by the identity y=2^[B*lambda].  By lemma 3.5,
 * if a merge takes input curves with a total of m vertices, then the time to carry it out is at most proportional to
 *
 * lambda^2*(m/2^Blambda) ---------------
 *
 * There are O(log lambda) levels of merging to be performed, each involving a total of b - a <= 2^lambda edges, therefore the time to merge the submaps for all the Di's into one is at most
 * (up to within a constant factor)
 *
 * lambda -----
 *
 * Since the initial cost of restting the granularity is only O(2^(lambda(1-B)), the lemma follows readily. */
}

void uphase41()
{
	/* We begin with a piece of terminology, given a curve C consisting of m contigous edges of P, we say that a submap of V(C) is cannoncial if it is 2^[B[logm]]-granular,
 * conformal, and represented in normal form.  Note that a canonical submap for a chain in grade lambda is 2^[Bk]-granular.  For lamba=0,1,..,p, in that order, we process grade lambda, which means:
 *
 * (i) We compute a canonical submap of V(C) for each chain C in that grade.
 * (ii) We proprocess each canonical submap for ray-shooting along the lines of Lemma 3.6, setting y to the value 2^[Blambda[.
 *
 * This work can be done naively for the early grades, so let us pick up the action at a grade lambda larger than some appropriate constant, assuming that all grades less than lambda have been processed already.
 *
 * Let us now turn to the processing of grade lambda.  Lemma 4.1 can be called upon to compute a canonical submap of the visibility map of each chain in grade lambda.
 * Preprocessing each chain for ray-shootidng is done by using Lemma 3.6.  Since there are (n-1)/2^lambda chains in grade lambda, we conclude that processing grade lambda requires time at most proportional to
 *
 * ----
 *
 *  From our choice of B - 1/5, it follows that preprocessing grade lambda takes O(n2^[-lmabda/76) time, therefore processing all p+1 grades, and thereby completeing the up-phase, takes linear time. */
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

int main(int argc, char* argv[])
{
}
