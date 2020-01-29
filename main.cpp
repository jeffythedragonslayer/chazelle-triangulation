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
	/* To begin, observe that A1 and A2 are arcs or subarcs of either S1 or S2 but cannot overlay both 6C1 and 6C2.
 * The reason is that all chord endpoints in S1 and S2 are still chord endpoints in S (perhaps with different chords) and that we added chords incident upon the vertices of 6C resulting from the duplication of the vertex C1 n C2.
 * Therefore, because of the bounded number of arcs per region, it is still possible to do local shooting within any region of S.
 * Since y1 <= y2 and f is nondecreasing this takes O(f(y2)) time.  Thus, we can efficiently check, in time
 * O(f(y2)), whether a given vertex of A1, qualifies as the point v sought.  (Again, we must be careful that local shooting reports edges of P and does not tell us if the point hit is on the desired arc or is the companion of a point of the arc.  We already discussed how local checking can decide which way it is in constant time,
 * so we will not make further mention of that minor difficulty.)  Of course, we should not check all the vertices of A1 because there might just be too many of them.
 * Instead, we need to do some kind of binary search among the vertices of A1.
 * For that purpose we invoke the arc-cutter associated with the arc of S1 or S2 containing A1, which allows us to subdivide A1 into at most g(y1) subarcs, with l=1 if A1 6C1 and l=2 if A1 6C2.  Except for at most two-single edge subarcs attached to the endpoints of A1 (which we ignore), for each subarc a we have a normal-form h(yi)-granular conformal submap Sa of V(abar).  We search each subarc in turn, stopping as soon as we find a good vertex or point, if ever.
 * Since the normal-form representation of Sa provides us with the tree decomposition T of the submap,
 * we are able to check the candidacy of a in its entirety in O(f(y2)(h(y2)+log(y2)) time, provided that the following test can be performed in O(f(y2)) time: given a chord ab of Sa, either determine that a or b is a point of a and sees A2 with respect to C, or find some i{1,2} such that a n ai is empty or has no point that sees A2, where a1 and a2 denote the two pieces of 6abar between a and b.  Note that 6abar is a superset of a with twice the number of vertices (not fewer because the arc-cutter oracle guarantees that a does not double-back around an endpoint).  First we show how such a test can be used to check the candidacy of a.  Then we explain how to implement the test and why it covers all possible cases.
 * We begin by applying this test with respect to the chord correspondding to the root of the tree T
 * (corresponding to the hierarchical decomposition of Sa).  Then, as claimed, either we terminate with a positive answer or else we identify one of a1 or a2, say a1, such that a n a1 is empty or has no point that sees A2.
 * In that case, we find the child of the root that corresponds to a2 and we iterate on this process from that node.
 * This leads us to termination at some iternal node of T or perhaps takes us to the bottom of the tree.
 * Note that determining which node to branch to at each step is trivial once we have identified the ai to be rejected.
 * (So, we can perform the test just as stated above without having to "resize" a to reflect the current status of the ever-shrinking set of candidates).
 * If we reach a leaf, we examine each vertex of the region associated with it and, among those belonging to a, we check whether any of them can see A2.  Since there are only O(h(y2)) vertices in the region and the depth of the tree is O(log y2) the running time of the algorithm is O(f(y2)(h(y2)+logy2)), as claimed.  Again we use the fact that y1 <= y2 and that h is nondecreasing.
 * Whenever we discover a successful candidate point, the search can obviously be stopped right there.
 * What remains to be seen is why upon reaching a leaf the corresponding region is the only one which can still provvide the desired answer.
 * Let us assume that the search ends up at a leaf.  At the very beginning, let us say that each point of 6abar is a candidate.  Every time we branch down the tree we limit the candidacy to those points, of 6abar in the regions of Sa associated with the leaves of the subtree which we entere.  At the end, the remaining candidates are the vertices in the region associated with the leaf where the tree search ends.  This proves the correctness of the procedure.  So, to summarise, if the basic test stated earlier can be performed in O(f(y2)) time, then we can solve the entire problem in O(f(y2)g(y2)(h(y2)+logy2)) time, which proves the lemma.
 * We now show how to perform the test and why it is sound, i.e. covers all cases.
 * Removing 6abar from the spherical plane leaves two open regions, each polygonal and homeomorphic to a disk.
 * One of them is infinitesimally small; let D be the closure of the other one.
 * It is important that D should be homeomorphic to a closed disk and not to a 2-sphere, so the interior of abar, and,
 * more generally, of C, should be understood as being very small but nonempty.  Let c and d be the endpoints of a\on 6abar.  Removing c and d from 6C leaves a and a curve A, both lying in D, so we have set the stage for Lemma 2.4.
 * Figure 3.4 illustrates the correspondance: the snake on the left represents C; the disk D corresponds to the outside of the portion of the snake between c and d, while it is the inside of the circle on the right.
 * The curve A runs along the snake clockwise from d to c; note that it runs on the boundary of D part of the way.
 * The subarc a runs clockwise from c to d and corresponds to B1 U B2.  Figure 3.4 shows the case where only one endpoint of ab lies in B1 U B2, which corresponds to Figure 2.8.2.  The reader will easily draw an example matching the case of Figure 2.8.1, where both a and b lie in a = B1 U B2.
 * To compute a' and b' (if defined) can be done by local shooting in the region of S incident upon A1 and A2,
 * which takes O(f(y2)) time.  Note that no shooting is needed for a or b if the point in question does not lie in a.
 * If ever a (resp. b) is a point of a and a' (resp. b') belongs to A2, then obivously we are done and successful in our search, so we can assume that neither conjunction holds.  But, in that case, A2, lies entirely within one of the connected components of the curve A after it has been cut up by removing a' and b' (whichever exists).  Therefore, by Lemma 2.4, A2 must be shielded from some Bi, which means that it cannot be connected to Bj without crossing ab or A.  Futhermore, we know that Bj can be identified in constant time.  The kuey observation now is that Bj coincides precisely with one of a n a1 or a n a2, say, the first one.  It follows that no point of a n a1 can see A2, and the test is completed. */
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
 * Let C1 and C2 be two polygonal curves of n1 and n2 vertices, respectively, whose union forms a connected vertex-to-vertex piece of the input
 * (simple and nonclode) polygonal curve P.  Suppose that we are given a normal-form yi-granular conformal submap of each V(Ci), where y1 <= y2,
 * along with the ray-shooting and arc-cutting oracles necessary for merging.  Then, for any y >= y2, it is possible to compute a normal-form y-granular conformal submap of V(C)
 * in time O((n1/y1 + n2/y2 + 1)f(y2)g(y2)(h(y2) + log(n1+n2))). */
void lemma35()
{
 /* Since by making S conformal we did not remove any exit chord, it is still the case that, as observed in the proof of Lemma 3.2, no arc has more than y2 edges.
 * Therefore, S is conformal and y2-semigranular.  We must now check whether the second citerion for y2-granularity holds.  This criterion says that contracting any edge of the submap
 * tree that is incident upon at least one node of degree less than 3 produces a new node whose weight exceeds y2.  This is very easy to enforce: if an edge does not pass the test,
 * we just contract it by removing its corresponding exit chord (and those endpoints that are not vertices of 6C).  Note that this will not cause a violation of the first criterion,
 * since the size of all the arcs will always remain within y2.  Similarly, the removal keeps the submap conformal.  We process each exit chord in turn and check whether it is removable.
 * Chords need be processed only once since the removals cannot make any chord removable if it was not already so before.  Therefore, y2-granularity, and more generally y-granularity,
 * for any y >= y2, can be enforced in this nondetermininistic fashion in time linear in the size of the submap tree, that is, O(n1/y1 + n2/y2 + 1).  We can now put S in normal form,
 * which includes computing its tree decomposition.  As we discussed earlier, this can be done very simply in time O((n1/y1 + n2/y2 + 1)log(n1+n2)).  With the inconsequential assumption that
 * yi = O(n1+n2), we derive the following result from Lemmas 3.1 and 3.4 */
}

/* Let C be a connectexd vertex-to-vertex piece of the input polygonal curve P and let m be its number of vertices.
 * Let S be a normal-form y-granular conformal submap of V(C).
 * Then it is possible to preprocess S in O(m(log m)/y+1) time so that ray-shooting within S can be done in time O(y^(1/3)m^(2/3)). */
void lemma36()
{
	/* Of the two oracles defined earlier, the ray-shooter is the more challenging to implement,
 * the reason being that it addresses the key issue in the triangulation business,
 * which is the discovery of new chords.  The arc-cutter is implemented by using the divide-and-conquer
 * structure of the up-phase of the visibility algorithm.
 * Since a better understanding of the up-phase is necessary to understand how that oracle works,
 * we postpone the discussion of its implementation a little.  Turning our attention to the ray-shooting oracle,
 * it might apppear at first that fast planar point location should be the answer.  But traditional methods, e.g,
 * [9] and [19], are inadequate for several reasons, the most crucial of which is their inability support merging
 * in sublinear time.  We turn this problem around by exploiting futher the approximation scheme provided by the concept of granularity.
 * Let C be a connected vertex-to-vertex piece of the input polygonal curve P and let m its number of vertices.
 * Let S be a normal-form y-granular conformal submap of V(C).  So far, we have focused mostly on the tree structure of S.
 * But let us now regard S as a planar graph.  For this purpose, we must temporarilty forget the fact that C has been given a double boundary.  We define S* to be the planar subdivision obtained by taking S and making every vertex
 * (vertices of 6C and chord endpoints) a vertex on both sides of the double boundary, whose thickness is now null.
 * As a result, the edges of S* might be smaller than those of S but, unlike in S, no edge of S* is of zero length
 * (zero-length edges are now "contracted" into vertices).  More important, each face of S* coincides exactly
 * with a distinct region of S, except for the fact that it might have many more vertices incident upon it.
 * Indeed, a region's only vertices are the endpoints of its own exit chords along with some vertices of 6C,
 * whereas the vertices of a face include all of the above plus all the chord endpoints that abut on the corresponding region from the outside.
 * Notice that since the notion of double boundary is lost, a face might have dangling edges or edges incident upon it on both sides.  There are several examples of this in Fig. 3.6, which shows the subdivision S* corresponding to the submap of Fig. 2.6.  Note also that the correspondence face/region is not surjective because empty regions have no associated faces.  Besides being planar, the graph S* has two remarkable properties:
 *
 * (i) From Lemma 2.3 we know that it has O(m/y+1) faces, which is much smaller than the number of vertices (when y is large).
 * (ii) Although a given face might be very complex (i.e., incident upon many edges) its number of noncollinear edges is small, i.e., O(y).
 *
 * These two features allow us to implement an efficient ray-shooting oracle.
 *
 * Let G be the dual graph of S*, that is, the graph obtained by associatting a distinct node with each face of S*
 * and connecting two nodes if and only if they are distict and their corresponding faces share a common edge.
 * It is a classical result of graph theory that G is planar.  How hard is it to compute G, say, in the form of
 * adjacency lists?  Two faces are adjacent if and only if either they share a chord or one of them has a chord
 * endpoint that abuts on a nonnull length arc of the region assoicated with the other face.
 * The first type of adjacencies can be detected immediately from S.  The latter can be done by double identification,
 * as discussed in Section 2.4, followed by sorting along C, which takes O(ulogm) time, where u=O(m/y+1) is
 * the number of nodes in G.  It can also be done faster by merging chord endpoints along both sides of 6C.
 * If u=1, then ray-shooting can be done trivially in O(m) time, so let us assume that u > 1.
 * We show that after O(nlogm) preprocessing we can do ray-shooting in O(yu^2/3) time.
 * The planarity of G works wonders for us.  The first payoff is that the number of edges is at most 3u-6.
 * The second reward is that we can apply the linear time algorithm of Lipton and Tarjan [21] to find a good separator.
 * This partitions the nodes of G into three subsets A, B, D, such that
 *
 * (i) no edge joins a node of A with a node of B,
 * (ii) neither A nor B contains more than 2u/3 nodes, and
 * (iii) D contains at most sqrt(8u) nodes.
 *
 * Let Ga (resp. Gb) be the graph obtained by keeping only the nodes of A (resp. B) and the edges of G that join only nodes of A (resp. B).
 * We repreat the procedure over with respect to each of Ga and Gb and iterate in this fashion until none of the graphs have more than u^sigma nodes, for smoe fixed sigma (9 < sigma < 1).  Let D* be the set of all separators,
 * i.e., the union of all the D's.  We easily verify that |D*| = O(u^sigma), provided that sigma is chosen large enough;
 * for example sigma = 2/3 [22].  In (ulogu) time we can compute D* and partition the remaining nodes into subsets D1, D2, etc., each of size at most u^2/3, such that no path of G can join two nodes in distinct subsets without passing through a node of D*.
 * What is the utility of D* for ray-shooting?  Take a vertical line passing to the right of all the vertices of P,
 * and intersect it with the chords of the regions in S.
 * This breaks up the line into segments, every one of which falls entirely within some region; to split up the line and identify the regions cut by each segment can be done by traversing G and checking each chord for intersection with a vertical line.  Since the regions cut correspond to nodes of G lying on a path, sorting the intersections comes for free, and all the work can be done in O(u) time.
 * We now claim that ray-shooting toward 6C from any point can be done in O(yu^2/3) time.
 * Our first task is to shoot within each region that is dual to a node of D* using a naive algorithm which involves checking all the O(y) edges of the region (and not the edges of the face, which might be much more numerous).
 * Assume that the ray of light hits a point among the edges of the regions dual to the nodes of D*.
 * Let R be the last region of S traversed before the first hit.
 * To identify R can be done by double identification, followed by checking the local orientation of the hit.
 * If R is a region dual to a node v of D*, then the starting point of the ray lies in R
 * (otherwise an earlier hit would have been detected) and we are trivially done.
 * So, assume now that R is dual to a node v not in D*.  Incidentally, note that double identification needed to find R might require a binary search among a large collection of collinear edges.
 * Let R' be the region incident upon the (region) edge containing the point of 6C actually hit by the ray-shooting:
 * this is the region that we are looking for (Fig. 3.7).  If R and R' are not the same then the two regions can be connected by a horizontal line segment that avoids all the regions dual to D*.
 * It follows that the node w associated with R' can be reached by a path in G from v that avoids D*.
 * Consequently, v and w both lie in the same Di.
 * We can find w, and, from there, answer the ray-shooting query, by first finding Di,
 * which takes constant time since we know R, and then naievly checking all the regions dual to nodes in Di,
 * which takes O(yu^2/3) time.
 * Returning to our ealier case analysis, assume now that the ray of light hits no region dual to a node in D*.
 * Then the ray-shooting takes place entirely within the regions dual to the nodes of a single Di.
 * To find out which one, we shoot toward the vertical line and find which segment of the line is hit.
 * This takes O(log u) time by binary search.
 * We can now identify the region R immediately.  The remainder of the algorithm is unchanged.
 * We conclude that ray-shooting can be done in O(m) time if u = 1, and O(yu^2/3{ time if u>1,
 * after O(ulogm) preprocessing.  Since u=O(m/y+1), we have */
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
	/* We proceed by induction on lambda.  Let S be the 2^[B*lambda]-granular conformal submap of V(C).
 * The case where lambda is a constant is trivial since the regions of S have bounded size, and therefore the missing chords can be provided in constant time per region.  So, let us switch directly to the inductive case,
 * assuming that lambda is large enough.  Let R be a region of S.
 * Because of conformality, the union of all the arcs of R can be partitioned into a constant number of single edges and vertex-to-vertex pieces of 6C with at most 2^[B*lambda] edges.  Applying Lemma 4.1, we can compute a canonical submap for each connected polygonal piece in the partition in time at most proportional to
 *
 * lambda^2(log lambda)2^(B*lambda(1-B/3+4*B^2/3{
 *
 * Each of these submaps has granularity at most 2^[B[Blambda]], so we can pursue the merging by putting
 * together all these submaps and thus create a single normal form 2^[B[B*lambda]]-granular conformal submap of V(R*),
 * where R* is the boundary of R minus a veretx (to ensure that it is nonclosed).
 * For consistency, we should regard R* as a standrad polygonal curve and not as part of a double boundary.
 * The operation requires a constant number of merges, so we can carry it out effectively by merging submaps
 * two-by-two like in Lemma 4.1.
 *
 * There is a small subtlety in this last round of merges, which we should explain.
 * To take a simple, suppose that R* has two arcs and two exit chords: a1,
 * a1b1, a2, a2b2, in cyclic order.  It could be that the endpoints of a1 or a2 are not vertices of 6C,
 * so to deal with the most general case, assume that a1 consists of b2b'2, B1, a'1,a1 and a2 consists of b1b'1, B2, a'2b2, where a1',b'1,a'2,b'2 are all vertices of 6C (Fig 4.1).  Let S1 (resp. S2) be the canonical submap for the vertex-to-vertex piece of P corresponding to B1 (resp. B2) and let T1 (resp. T2) be canonical submaps for the 3-edge polygonal curve a'1, a1, b1, b'1 (resp. a'2,a2,b2,b'2).  We obtain S1 and S2 by application of Lemma 4.1, while T1 and T2 are computed directly (tilting the edges a1b1 and a2b2 symbolically to keep the merging algorithm from complaining later.)
 * We are now ready to merge S1 with T1, then merge the resulting submap with S2, and finally merge the result with T2.
 * Note that we treat the edges a1b1 and a2b2 as part of the input curve although they are not part of P.
 * As a result, ceasing (temporarily) to be chords, these edges cannot be removed during the merges.
 * Since we add at most a constant number of new edges to the input curve, all the oracle machinery needed
 * for the merges is still available, i.e., the new edges create only constant-time multiplicative overhead.
 * Although the final submap is conformal it might no longer be so if we now reinterpret a1b1 and a2b2 as chords,
 * which we do once the last round of merges is completed.  To remedy this we apply the conformality-restoring
 * procedure of Section 3.2 to each region that might have more than four chords with this new interpretation.
 * Again, it is immediate to see that all the required oracles are still available.
 * The time taken by this last round of merges is dominated by the cost of the earlier merges,
 * so computing the 2^[B[Blambda]]-granular conformal submap of all the V(R*)'s takes time at most proportional to
 *
 * 2^i*lambda^2(log lambda)*2^B^2lambda(4B/3-1/3)
 *
 * We can now extract the relevant information, i.e., the exit chords falling entirely within each region R.
 * This involves checking the exit chords of the computed submap of V(R*) and keeeping only those both of whose endpoints lie on the arcs (in the double boundary sense) of the region R.  This leads to a new map S* of V(C) which is a refinement of S: all its arcs originate from the previous merges, therefore S* is a 2^[B[Blambda]]-semigranular conformal submap of V(C).  We can only speak of semigranularity because some of the chords connecting the R*'s might be removable now.  We can check each of the exit chords directly, which as we saw in Section 3.3, takes a total amount of time linear in the number of exit chords in S*.
 * Now that we have a 2^[B[B*lambda]]-granular conformal submap of V(C) at our disposal we observe that [Blambda] <= lambda - 1 for lambda large enough, so that we can apply the induction hypothesis and derive V(C) in
 * time at most (c-1/(lamdda-1))2^l.  Putting everything together, the total running time for the construction of V(C) is at most
 *
 * a2^l*lamda^2(log lambda)*2^(B^2*lambda*(4B/3-1/3) + (c-1/(lambda-1))*2^l
 *
 * for some constant a > 0.  With the setting B = 1/5, this is no more than
 *
 * a*2^l*lambda^2(log lambda)*2^[-lambda/375] + (c-1/(lambda-1)*2^l <= (c-1/lambda)*2^l
 *
 * for lambda large enough.
 *
 * During the up-phase we built a normal-form 2^[Bp]-granular conformal submap of V(P) in linear.
 * By Lemma 4.2, therefore, V(P) can be obtained also in linear time.  As demonstrated in [6] and [11],
 * a triangulation can be easily derived from the visibility map in linear time, so our main goal has been reached. */
}

/* It is possble to compute the visibility map of a simple polygonal curve, and, hence, a triangulation of a simple polygon, in linear time */
void theorem43()
{
}

int main(int argc, char* argv[])
{
}
