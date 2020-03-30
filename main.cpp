#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
using namespace boost;

struct Point
{
	uint x, y;
};

struct LineSegment
{
	Point a, b;
};

typedef unsigned uint;
typedef vector<Point> polygon;

struct Submap
{
	/* How do we represent visibility maps and submaps as data structures?+  We first describe our mode of representation, then we point out some of its idiosyncracies and explain why they are needed.
	 * Let P be the input polygonal curve (the one whose visibility map is sought) and let C be the subchain of P whose visibility map (or submap) we wish to represent.
	 * We assume that P is nonclodes, this is not restrictive since a little hole can always be punctured if it is closed to begin with.
	 * We assume that the edges of P are stored in a table (the input table) in the order in which they occur along the boundary of P.
	 * (A doubly linked list would also do.)
	 * Note that the notion of double boundary need not be encoded explicitly, i.e., no edges are duplicated in the table.
	 * The input table is read-only: it is never to be modified or even copied.  A visibility submap of V(C) is represented by its own data structure:
	 * arcs are encoded by pointing directly into the input table.
	 * More precisely, each arc is represented by a separate arc-structure.
	 * Null-length arcs can be represented explicitly so let us assume that the arc has nonzero length.
	 * Let e1, ..., et be the edges of an arc in clockwise order along the double boundary, where e1 and et are the edges adjacent to the two chords connected by the arc.
	 * If t=1, then the arc-structure consists of a single pointer into the input table to the edge e of P that contains e1.
	 * Since e1 is an edge of the double boundary, we also need to indicate by a flog which side of e is to be understood.
	 * We do not need to record the endpoints of the arc because chords take care of that.
	 * If t > 1, we store the same information as above but now with respect to both e1 and et in that order.
	 * We say that a submap (or map) is given in normal form if the following informaiton is provided:
	 * (i) The tree of the submap (or map) is represented in standard edge/node adjacency fashion.
	 * (ii) Each edge contains a record describing the corresponding chord as well as pointers to the arc-structures
	 * 	of the two, three, or four arcs adjacent to it.  Conversely, each arc-structure has a pointer to the node of the tree whose corresponding region is incident upon the arc in question.
	 * (iii) The arc-structures are stored in a table (the arc-sequence table) in the order corresponding to a canonical traversal of the double boundary ∂C.
	 * 	Also, the endpoints of C are identified by appropriate pointers int the input table as well as by pointers to the arc-structures whose corresponding arcs pass through the endpoints.
	 * (iv) If the submap is conformal, then its tree decomposition should be avilable. 
	 *
	 * We choose what may seem to be contrived representation of a submap in order to use storage proportional not to the number of edges in the submap but rather to the number of regions
	 * (which is of the same order of magnitude as the number of chords and arcs).
	 * It is essential to avoid duplication of information because we need to encode a collection of submaps whose number of distinct features is only O(n),
	 * but whose combined size, counting redundancc, is big theta(n log n).
	 * Note that our representation is powerful enough to let us perform canonical vertex/region enumerations in optimal time.
	 * If we wish to, we can also enumerate all the vertices of ∂C in clockwise order directly from a canonical vertex enumeration of the submap, since any arc can be reconstructed explicitly from the succinct
	 * information given by the arc-structure: it sufficies to explore the input table between the locations indicated by the two pointers of the arc-structure.
	 * Note that caution must be used since an arc might wrap around both sides of ∂C, something we call double-backing.
	 * This can be detected when we traverse the arc as soon as we reach an edge of P incident upon an endpoint of C.
	 * Perhaps a less obvious task is to retrieve the arc-structure corresponding to an arc, given one of its edges.  More specifically, suppose that we are given an edge e of C and a point q on it.
	 * The question is to find the arc-structures of all those arcs in the submap that pass through the point q.
	 * By passing through, we do not care whether the arc is on any particular side of the double boundary, so, for example, if q is not an endpoint of any chord in the submap,
	 * then there are most two distinct arcs to be found.
	 * Otherwise, there are at most six of them., two of which are of zero length: this worst case occurs when q coincides with a vertex of C that is a local extremum in the y-direction.
	 * Since we know the location of the two endpoints of C in the arc-sequence table
	 * (i.e, which arcs pass through them) we can conceptually break up the circular arc sequence into two linear sequences and perform in each of the a binary search,
	 * using the name of the containing edge e as a query.
	 * Either search might take us to a unique arc-structure, in which case we are done, or else to a contiguou interval of arc-structures: this might happen if e contributes several arcs.
	 * We can disambiguate by purusing the binary search, now using, say, the y-coordinate of q as a query.  The total running time is logarithmic in the number of arcs.
	 * This operation is very useful later when we want to navigate in a submap across its arcs: we call it the double identification of a point of C.
	 * We have said repeatedly that a submap has a tree structure.  Now let us change our perspective for a moment and look at a submap as a standard planar subdivision, without distinguishing between chords and arc edges.
	 * There are many standard representations of planar graphs [2], [15], [23] which allow us to navigate through a subdivision along the edges in constant time per step taken.
	 * Normal-form representations are not quite that powerful.  One problem arises if we attempt to cross from one side of an arc to the otehr along, say, a straight line.
	 * In order to find which region we are about to enter we must perform a double identification.  The difficultly here is that unlike what is commonly done in standard graph representations we do not keep adjacency information
	 * between regions and edges (except for chords).  More important yet, we do not provide an explicit correspondance between the features on the two sides of an edge of C.
	 * For reasons which will become clear later, it would be a very bad idea to try to do so.  */
};

/* If we remove a pair of mutually visible points from the double boundary of a simple polygonal curve, then no chord can connect the two resulting pieces. */
void lemma21()
{
	/* Let C1 and C2 be the two pieces of the double boundary resulting from the removal of a pair of visible points.
	 * Together with C1 and C2, the chord c connecting the two points subdivides the spherical plane into three polygonal regions
	 * (i.e., regions bounded by simple polygonal curves), one of which is the infinitesimally thin polygon C itself.
	 * Any chord connecting C1 and C2 lies outside the "polygon" C, so it must cross c.  But this is impossible because chords are horizontal. */
}

/* Let A1,...,Ak be the counter clockwise enumeration of the (oriented) arcs of a nonempty submap region (as induced from the region's orientation).
 * Then each Ai is oriented clockwise with respect to ∂C.  Moreover, the sequence A1,..,Ak also occurs clockwise around ∂C. */
void lemma22()
{
	/* The curve ∂C is homeomorphic to a circle embedded in the spherical plane.
	 * Adding a chord is topologically equivalent to connecting two points on the circle by simple curve lying entirely on one side of the circle.
	 * The requirement that all these curves should be mutually disjoint induces a parenthesis system which immediately reveals the tree structure of the dual graph.
	 * This is similar to teh parenthesis system in Jordan sorting [18].  As an example, Figure 2.5 depicts the topological equivalent of the submap of Fig. 2.4.
	 * From this perspective, the lemma should be completely obvious. */
}

/* If C is a polygonal curve with n vertices, any y-granular conformal submap of the (possibly augmented) visibility map of C has O(n/y + 1) regions and each region is bounded by O(y) edges. */
void lemma23()
{
	/* We can assume that the tree of the submap has at least one edge, otherwise the lemma is trivial because of the y-granularity.
	 * Among the edges of that tree, let E be the set of those incident upon at least one node of degree less than 3.
	 * It is trivial to show by induction on the size of the tree that E accounts for at least a fixed fraction of all the edges.
	 * Now, contracting any edge in E, or equivalently, removing a chord associated with E produces a merged region of weight greater than y,
	 * meaning that it has an arc with more than y edges of nonzero length.
	 * Since a vertex of C can give rise to at most four vertices of ∂C, and removed chords do not leave extra vertices behind except those of ∂C,
	 * such an arc must involve at least omega(y) distinct vertices of C.  If contracting any edge of E were always to produce a disjoint merged region,
	 * then it would follow from the pigeon-hole principle that E, and hence the whole tree, has O(n/y+1) edges.
	 * Unfortunately, two edges of E might produce overlapping merged regions (i.e, if they share a common node).
	 * From the conformality of the submap, however, we know that a given vertex of C can be used at most a constant number of times in this counting argument,
	 * therefore E has indeed O(n/y+1) edges and the first part of the lemma is established.  The second part derives from the conformality of the submap,
	 * which ensures that there is bounded number of arcs per region and, hence, that the total number of bounding edges is at most proportional to the weight of the region. */
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
	 * In case (i) we know that aj lies in R (actually in its interior) and sees a point of ∂C2, so invariant (B) is satisified.
	 * How about (A)?  We made the claim that ak,...,aj-1 all see points of ∂C1.  But actually the negation of (i0
	 * for ak,...,aj-1 is not strong enough to reach the necessary conclusion about what ak,...,aj-1 must see.
	 * Any of these points (if they exist) either sees ∂C1, or lies outside of R.
	 * Why should lying outside R imply seeing ∂C1?  Suppose that, for some l (k <= l < j), al lies in region R' distict
	 * from R (like ak+1 in Figure 3.2.1 but also sees ∂C2.  We derive a contradiction.
	 * Let A denote the directed portion of ∂C1 as we go from p ta a1 clockwise, and let q (resp. q') be the point of ∂C seen by p (resp. a1).
	 * The union of A, the chords pq and a'q', and the portion B of ∂C2 running clockwise (with respect to C2) from q' to q forms the boundary of a simple ploygon (Figure 3.3).
	 * Since the dual graph of a submap is a tree, there is a unique exit chord ab of R that leads to R' (note that ab need not be an exit chord of R', since there might be one or even several regions separating R from R').
	 * Because B runs from R' to R it passes through one of the chord endpoints, say, a.  Let a' be the point of ab n A first encountered as we go from a to b along the chord.  Note that ab cuts through A, so a' is well defined.
	 * The points a and a' see each other with respect to ∂C, and a' lies in Ak, for some h between k and l inclusive.
	 *
	 * Because, in clockwise order around ∂C, the point a' is leaving R locally, it cannot be equal to p.
	 * Therefore, the inequality l < j implies that case (ii) must have already aoccurred when the running variable j was assigned to some integer between k and l, which is impossible.
	 *
	 * Having shown that the loop invariant remains satisfied through case (i), we must do the same with case (ii).
	 * Let A now denote the directed portion of ∂C1 as we go from p to aj clockwise.
	 * The new assignment of p is the last paint of A, distinct from p, that sees an endpoint of an exit chord of R.
	 * Certainly, the new assignment of the current region satisfies invariant (B).  Figure 3.2.1 shows three candidate endpoints, with q3 winning the contest.
	 * Turning now to invariant (A), we must prove our claim that the points of ∂C seen by ak,...,aj-1 all belong to ∂C1.  We omit the proof since it is identical to the previous one, with the role of aj now played by p'.
	 *
	 * What about termination?  Obivously, the three cases rule out an infinite loop.
	 * Every time we fall in either of the two cases (i) or (ii) we determine more visibility information, so that all visiiblity relations are known from a0 all the way to the current position of p.
	 * How about the last iteration, the one leading to case (iii)?  We claimed that all ai's (k <= i < m+1) see points of ∂C1.
	 * This follows from the proof of the last paragraph, which showed that if a1 sees ∂C2, then either al lies in R (case (i)) or it does not, but then, we must fall in case (ii) after leaving p but upon or prior to getting to al.
	 * The proof of correctness is now complete.
	 *
	 * Let us now analyze the complexity of the algorithm.
	 * To test whether aj lies in R can be done in O(f(y2)) time by using the ray-shooters for each arc that bounds R: first we find which point of an arc is hit by a ray of light shot from aj in its assigned chord direction.
	 * If there is no hit on any arc, aj is not in R.  Else, let s be the first point hit by the ray over all the arcs of R.
	 * Whether aj lies in R or not can be directly inferred from the local orientation of the hit at s and which side of the double boundary is hit.
	 * This is because, as we should recall, arc-structures encode on which side(s) of the boundary the arcs lie.  If aj lies in R, then s is the point of ∂C2 seen by aj with respect to C2.
	 * Next we use local shooting within S1 to determine the point t of ∂C1 hit by a ray of light shot from aj in its assigned direction.
	 * Note that most often (i.e. when 0<j<=m) aj is the endpoint of a chord of S1 so t is just the other endpoint of the chord.
	 * Now that we know which points of ∂C1 and ∂C2 the point aj can see, we can immediately derive the point of ∂C that it sees and, from there decide whether we are in case (i).
	 * The test takes O(f(y1)+f(y2)) = O(f(y2)) time (since f is nondecreasing and y1<=y2).  This cost also includes the start-up phase.
	 *
	 * Regarding (ii), we must assess how fast we can find the point of ∂C that is seen by an endpoint a of a given exit cord ab of R.  Actually, we must find that point only if it belongs Aj.
	 * So, we can shoot a ray of light from a toward Aj in the appropriate direction and see what happens, which takes O(f(y1)) time.
	 * If we do not get a hit, or if the hit does not lie on ab, or if it occurs before p along Aj,
	 * or if it does not have the proper orientation which lets a see Aj without the other side of the double boundary of Aj interfering (a constant-time test), then the endpoint can be disqualified.
	 * Otherwise, we must find whether the point s of Aj hit by the ray of light can see a with respect to C:
	 * the problem here is that other arcs Ai (i != j) might get in the way.  Using the local shooting in S1, however,
	 * we can shoot a ray of light from s toward a.  We aim in the natuarl shooting direction from s since we have already ruled out that the "companion" point of s should prevent it from seeing a.
	 * The point t hit by the ray is found in O(f(y1)) time.
	 * If shooting from s to t passes through a, then s and a see each other with respect to C and we fall in case (ii),
	 * else we know that case (ii) cannot occur with respect to Aj and the endpoint a of the chord ab (although it might occur with respect to other endpoints of exit chords in R).
	 * This shows that testing case (ii) takes O(f(y1)) time.
	 *
	 * We thus have shown that every elementary test (i), (ii) can be performed in O(f(y2)) time.
	 * At each such test we advance through the list of Ai's or we report a pair of visible points in ∂C,
	 * one of which is an endpoint of an exit chord of S2.
	 * These reports are never duplicated because we always move forward among the Ai's
	 * Therefore, to discover all the chords of the fusion S of S1 and S2 takes time O(mf(y2)) time,
	 * where m is the total number of arcs and exit chords in S1 and S2.
	 * By Lemma 2.3, m is O(n1/y1+n2/y2+1).  Note that among the chords to be included in the fusion S,
	 * we not only have the newly discovered chords that connect ∂C1 and ∂C, as well as the old chords of S1 and S2 that still form visible pairs of points with respect to C,
	 * but we also have all the null-length chords of S1 and S2 as well as the thords incident upon the vertices of ∂C resulting from the duplication of the vertex C1 n C2; this last category is where null-length chords originate.
	 * After fusing S1 (resp. S2) into S2 (resp. S1), we have all the chords of the submap S and we can set it up in normal form quite easily.
	 * In order to allow for canoncial vertex enumerations, let us sort the endpoints of these chords along ∂C, which is done by sorting the names of the edges of P on which these arcs abut,
	 * and then sorting the endpoints falling within the same edges by considering y-coordinates.  This allows us to set up the required arc-sequence table.
	 * Note that merging can also be used instead of sorting but this step is not the dominant cost, anyway.
	 * With this information it is now straightforward to set up the tree of the submap S, along with all the necessary arc-structures and their relevant pointers.
	 * Since the submap might not be conformal we dispense with the tree decomposition at this point.  Very conservatievly, all this work can be done in time
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
 * one of which is a vertex of ∂C (meaning that, say, A1 contains a vertex v which is also a vertex eof ∂C and is such that the point of ∂C seen by v lies in A2).
 * Then we can find a point of A1 (not necessarily a vertex of ∂C that sees A2 in time O(f(y2)g(y2)(h(y2) + log y2)) */
void lemma32()
{
	/* To begin, observe that A1 and A2 are arcs or subarcs of either S1 or S2 but cannot overlay both ∂C1 and ∂C2.
	 * The reason is that all chord endpoints in S1 and S2 are still chord endpoints in S (perhaps with different chords) and that we added chords incident upon the vertices of ∂C resulting from the duplication of the vertex C1 n C2.
	 * Therefore, because of the bounded number of arcs per region, it is still possible to do local shooting within any region of S.
	 * Since y1 <= y2 and f is nondecreasing this takes O(f(y2)) time.  Thus, we can efficiently check, in time
	 * O(f(y2)), whether a given vertex of A1, qualifies as the point v sought.
	 * (Again, we must be careful that local shooting reports edges of P and does not tell us if the point hit is on the desired arc or is the companion of a point of the arc.
	 * We already discussed how local checking can decide which way it is in constant time,
	 * so we will not make further mention of that minor difficulty.)  Of course, we should not check all the vertices of A1 because there might just be too many of them.
	 * Instead, we need to do some kind of binary search among the vertices of A1.
	 * For that purpose we invoke the arc-cutter associated with the arc of S1 or S2 containing A1, which allows us to subdivide A1 into at most g(y1) subarcs, with l=1 if A1 ∂C1 and l=2 if A1 ∂C2.
	 * Except for at most two-single edge subarcs attached to the endpoints of A1 (which we ignore), for each subarc a we have a normal-form h(yi)-granular conformal submap Sa of V(abar).
	 * We search each subarc in turn, stopping as soon as we find a good vertex or point, if ever.
	 * Since the normal-form representation of Sa provides us with the tree decomposition T of the submap,
	 * we are able to check the candidacy of a in its entirety in O(f(y2)(h(y2)+log(y2)) time, provided that the following test can be performed in O(f(y2)) time: given a chord ab of Sa,
	 * either determine that a or b is a point of a and sees A2 with respect to C, or find some i{1,2} such that a n ai is empty or has no point that sees A2, where a1 and a2 denote the two pieces of 6abar between a and b.
	 * Note that 6abar is a superset of a with twice the number of vertices (not fewer because the arc-cutter oracle guarantees that a does not double-back around an endpoint).
	 * First we show how such a test can be used to check the candidacy of a.  Then we explain how to implement the test and why it covers all possible cases.
	 * We begin by applying this test with respect to the chord correspondding to the root of the tree T
	 * (corresponding to the hierarchical decomposition of Sa).  Then, as claimed, either we terminate with a positive answer or else we identify one of a1 or a2, say a1, such that a n a1 is empty or has no point that sees A2.
	 * In that case, we find the child of the root that corresponds to a2 and we iterate on this process from that node.
	 * This leads us to termination at some iternal node of T or perhaps takes us to the bottom of the tree.
	 * Note that determining which node to branch to at each step is trivial once we have identified the ai to be rejected.
	 * (So, we can perform the test just as stated above without having to "resize" a to reflect the current status of the ever-shrinking set of candidates).
	 * If we reach a leaf, we examine each vertex of the region associated with it and, among those belonging to a, we check whether any of them can see A2.
	 * Since there are only O(h(y2)) vertices in the region and the depth of the tree is O(log y2) the running time of the algorithm is O(f(y2)(h(y2)+logy2)), as claimed.
	 * Again we use the fact that y1 <= y2 and that h is nondecreasing.
	 * Whenever we discover a successful candidate point, the search can obviously be stopped right there.
	 * What remains to be seen is why upon reaching a leaf the corresponding region is the only one which can still provvide the desired answer.
	 * Let us assume that the search ends up at a leaf.  At the very beginning, let us say that each point of 6abar is a candidate.
	 * Every time we branch down the tree we limit the candidacy to those points, of 6abar in the regions of Sa associated with the leaves of the subtree which we entere.
	 * At the end, the remaining candidates are the vertices in the region associated with the leaf where the tree search ends.  This proves the correctness of the procedure.
	 * So, to summarise, if the basic test stated earlier can be performed in O(f(y2)) time, then we can solve the entire problem in O(f(y2)g(y2)(h(y2)+logy2)) time, which proves the lemma.
	 * We now show how to perform the test and why it is sound, i.e. covers all cases.
	 * Removing 6abar from the spherical plane leaves two open regions, each polygonal and homeomorphic to a disk.
	 * One of them is infinitesimally small; let D be the closure of the other one.
	 * It is important that D should be homeomorphic to a closed disk and not to a 2-sphere, so the interior of abar, and,
	 * more generally, of C, should be understood as being very small but nonempty.  Let c and d be the endpoints of a\on 6abar.  Removing c and d from ∂C leaves a and a curve A, both lying in D, so we have set the stage for Lemma 2.4.
	 * Figure 3.4 illustrates the correspondance: the snake on the left represents C; the disk D corresponds to the outside of the portion of the snake between c and d, while it is the inside of the circle on the right.
	 * The curve A runs along the snake clockwise from d to c; note that it runs on the boundary of D part of the way.
	 * The subarc a runs clockwise from c to d and corresponds to B1 U B2.  Figure 3.4 shows the case where only one endpoint of ab lies in B1 U B2, which corresponds to Figure 2.8.2.
	 * The reader will easily draw an example matching the case of Figure 2.8.1, where both a and b lie in a = B1 U B2.
	 * To compute a' and b' (if defined) can be done by local shooting in the region of S incident upon A1 and A2,
	 * which takes O(f(y2)) time.  Note that no shooting is needed for a or b if the point in question does not lie in a.
	 * If ever a (resp. b) is a point of a and a' (resp. b') belongs to A2, then obivously we are done and successful in our search, so we can assume that neither conjunction holds.
	 * But, in that case, A2, lies entirely within one of the connected components of the curve A after it has been cut up by removing a' and b' (whichever exists).
	 * Therefore, by Lemma 2.4, A2 must be shielded from some Bi, which means that it cannot be connected to Bj without crossing ab or A.
	 * Futhermore, we know that Bj can be identified in constant time.  The key observation now is that Bj coincides precisely with one of a n a1 or a n a2, say, the first one.
	 * It follows that no point of a n a1 can see A2, and the test is completed. */
}

/* Let A1,...,Ak be the clockwise circular sequence of arcs around a region of S.  If k > 4, then there exist i, j, such that
 * (i) i - j != -1, 0, 1 (mod k) and
 * (ii) Ai has a vertex of ∂C that sees Aj (with respect to C). */
void lemma33()
{
	/* Recall that the region is associtade with a subtree of the visibility tree of C.
	 * If S contains chords incident upon no vertices of ∂C, then we must include these chords as well and speak of the tree of the augmented visibility map of C.
	 * Let us add to the subtree in question the edges that connect it to the rest of the visibility tree.
	 * With respect to this augmented subtree, each exit chord of the region is associated with a distinct node of degree 1 (but the converse may not be true).
	 * Note that some of these exit chords might be of zero length.
	 * Consider the Steiner minimal tree of these particular degree-1 nodes (i.e., the smallest connected set of edges that join these nodes together), and for simplicity form a tree homomorphic to it by ignoring nodes of degree 2.
	 * Now embed this new tree in the plane and enclode it by a simple closed curve that connects together all its degree-1 nodes (Fig. 3.5).
	 * By using an embedding that preserves the local orientation of the edges around the nodes, the area inside the closed curve is partitioned into k faces, each corresponding to a distinct arc Ai.
	 * Because there are at least five degree-1 nodes and the maximum node degree is 4, it is immediate that at least one edge of the tree must be indicent upon two faces associated with Ai, and Aj, respectively,
	 * where i-j != -1, 0, 1 (mod k).  (For a simple proof, try all possible cases with five or more nodes.)
	 * Of all the chords in the region only the exit chords might fail to be incident upon at least on vertuex of ∂C.
	 * It follows that the edge in question corresponds to one or several chords of the original, nonaugmented V(C) that connect Ai and Aj. */
}


/*
 * The submap S can be made conformal in time
 * O((n1/y1 + n2/y2 + 1)f(y2)g(y2)h(y2) + log y2). */
void lemma34()
{
	/* Equipped with the two previous lemmas, making S conformal is now quite easy.  Recall that although S might not be conformal right after fusion, none of its regions has more than a bounded number of arcs.
	 * For any region with more than four arcs, let us apply lemma 3.2 to every pair of nonconsecutive arcs until we find a chord which we can add to S.  We iterate on this process until no region has more than four arcs.
	 * Note that although S keeps changing, Lemma 3.2 always holds since region arcs can only become smaller.  Lemma 3.3 tells us that this chord addition process will not stop until S becomes conformal.
	 * Since the total number of arcs in S is O(n1/y1 + n2/y2 + 1), we conclude: */
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
	 * we just contract it by removing its corresponding exit chord (and those endpoints that are not vertices of ∂C).  Note that this will not cause a violation of the first criterion,
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
	 * But let us now regard S as a planar graph.  For this purpose, we must temporarilty forget the fact that C has been given a double boundary.
	 * We define S* to be the planar subdivision obtained by taking S and making every vertex
	 * (vertices of ∂C and chord endpoints) a vertex on both sides of the double boundary, whose thickness is now null.
	 * As a result, the edges of S* might be smaller than those of S but, unlike in S, no edge of S* is of zero length
	 * (zero-length edges are now "contracted" into vertices).  More important, each face of S* coincides exactly
	 * with a distinct region of S, except for the fact that it might have many more vertices incident upon it.
	 * Indeed, a region's only vertices are the endpoints of its own exit chords along with some vertices of ∂C,
	 * whereas the vertices of a face include all of the above plus all the chord endpoints that abut on the corresponding region from the outside.
	 * Notice that since the notion of double boundary is lost, a face might have dangling edges or edges incident upon it on both sides.
	 * There are several examples of this in Fig. 3.6, which shows the subdivision S* corresponding to the submap of Fig. 2.6.
	 * Note also that the correspondence face/region is not surjective because empty regions have no associated faces.  Besides being planar, the graph S* has two remarkable properties:
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
	 * the number of nodes in G.  It can also be done faster by merging chord endpoints along both sides of ∂C.
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
	 * for example sigma = 2/3 [22].  In (ulogu) time we can compute D* and partition the remaining nodes into subsets D1, D2, etc., each of size at most u^2/3,
	 * such that no path of G can join two nodes in distinct subsets without passing through a node of D*.
	 * What is the utility of D* for ray-shooting?  Take a vertical line passing to the right of all the vertices of P,
	 * and intersect it with the chords of the regions in S.
	 * This breaks up the line into segments, every one of which falls entirely within some region;
	 * to split up the line and identify the regions cut by each segment can be done by traversing G and checking each chord for intersection with a vertical line.
	 * Since the regions cut correspond to nodes of G lying on a path, sorting the intersections comes for free, and all the work can be done in O(u) time.
	 * We now claim that ray-shooting toward ∂C from any point can be done in O(yu^2/3) time.
	 * Our first task is to shoot within each region that is dual to a node of D* using a naive algorithm which involves checking all the O(y) edges of the region (and not the edges of the face, which might be much more numerous).
	 * Assume that the ray of light hits a point among the edges of the regions dual to the nodes of D*.
	 * Let R be the last region of S traversed before the first hit.
	 * To identify R can be done by double identification, followed by checking the local orientation of the hit.
	 * If R is a region dual to a node v of D*, then the starting point of the ray lies in R
	 * (otherwise an earlier hit would have been detected) and we are trivially done.
	 * So, assume now that R is dual to a node v not in D*.  Incidentally, note that double identification needed to find R might require a binary search among a large collection of collinear edges.
	 * Let R' be the region incident upon the (region) edge containing the point of ∂C actually hit by the ray-shooting:
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

/* Suppose that all grades less than λ have been processed.  Then, given any portion D of P of the form va,...,vb, where 2^l-1 < b - a <= 2^l, we can compute
 * a canonical submap of V(D) in time proportional to l^2(log l)2^(1-B/3+4B^2/3). */
void lemma41()
{
	/* In O(λ) time we can partition D into j <= 2*λ chains, D1,...Dj, in grades less than λ, with at most two chains per grade. 
	 * This implies that, for each i = 1, ..., j a canonical submap S of V(Di) is available.  Let y be the granularity of a canonical submap of V(D); we have y = 2^(Bl)
	 * Since the granularity of canonical submap grows monotonically with the size of the underlying polygonal curve, we can trivially reset the granularity of each Si to y (Section 3.3).
	 * The time to do that is proportional to the total number of chords in all the Si's which, from Lemma 2.3, is on the order of E0<=k<=λ^2^[Bk], that is, O(2^λ(1-B)).
	 *
	 * Let us now merge these submaps two-by-two (D1 with D2, D3 with D4, etc.).  More generally, we consider a perfectly balanced binary tree whose leaves are in the bijection with Di's and we merge submaps bottom-up
	 * by following the tree pattern.  */

	lemma35();
	/* Application of Lemma 3.5 results in a canonical submap of V(D) provided, of course, that the required oracles are available.  But are they?
	 * Notice that during any merge any arc a in either of the two input submaps consists of at most y edges.  Therefore, any subarc a' <= a can be subdivided into a constant number of contiguous pieces
	 * (with no double-backing) whose corresponding portions of P consist of a single line segments (at most two of them) and vertex-to-vertex pieces of P, each with at most 2^[Bk] edges.
	 * Each of these pieces can be partitioned into a collection of O(λ) chains in grades at most [Bλ].  Our work at previous grades ensures that we have ray-shooting structures for the canonical submaps
	 * associated with these chains.  Thus, to shoot a ray toward a', we shoot toward each of the O(λ) subarcs of its decomposition and determine the closest hit (if any.)
	 * Shooting towards a single edge subarc is trivial.  Shooting toward any other subarc makes use of the shooting structure of a canonical submap for a chain in grade u < [Bλ].
	 * Assuming that [Bλ] < λ (which is true for λ large enough) all these shooting structures have been computed and therefore, by Lemma 3.6, ray-shooting can be done in time O(2^[Bu]/3+2u/3),
	 * which is O(2^B^2*lamda/3+2Bλ/3).  Since there are O(λ) subarcs, it follows that the ray-shooting oracle can be implemented so that
	 *
	 * f(y) = λ*2^[B^2*λ/3+2*B*λ/3].
	 *
	 * As we mentioned, the subarc a' is decomposed into at most two single-edge pieces, along with O(λ) pieces for which we have conformal submaps of granularity at most 2^[B[Bλ]].
	 * We verify that all the requirements of the arc-cutting oracle are satisfied by this decomposition, so that we can set
	 *
	 * g(y) = O(λ)
	 *
	 * and
	 *
	 * h(y) <= 2^[B[B*λ]]
	 *
	 * To appreciate the connection between the left- and right-hand sides of these relations, recall that y and λ are related by the identity y=2^[B*λ].  By lemma 3.5,
	 * if a merge takes input curves with a total of m vertices, then the time to carry it out is at most proportional to
	 *
	 * λ^2*(m/2^(B*λ))*2^(B^2*λ/3+2*B*λ/3)(2^((B^2)λ) + log m)
	 *
	 * There are O(log λ) levels of merging to be performed, each involving a total of b - a <= 2^λ edges, therefore the time to merge the submaps for all the Di's into one is at most
	 * (up to within a constant factor)
	 *
	 * λ^2*(log λ)*2^(λ-B*λ/3 + 4*B^2*λ/3)
	 *
	 * Since the initial cost of restting the granularity is only O(2^(λ(1-B)), the lemma follows readily. */
}

// log n stages
void uphase41()
{
	/* We begin with a piece of terminology, given a curve C consisting of m contigous edges of P, we say that a submap of V(C) is cannoncial if it is 2^[B[logm]]-granular,
	 * conformal, and represented in normal form.
	 * Note that a canonical submap for a chain in grade λ is 2^[Bk]-granular.  For lamba=0,1,..,p, in that order, we process grade λ, which means: */

	uint p = 0;
	uint B = 0;

	for( uint lambda = 0; lambda <= p; ++lambda){
		 /* (i) We compute a canonical submap of V(C) for each chain C in that grade.
		 * (ii) We proprocess each canonical submap for ray-shooting along the lines of Lemma 3.6, setting y to the value 2^[B*λ].*/
		uint y = pow(2.0, 1.0*ceil(B*lambda));
	}
 /*
 *
 * This work can be done naively for the early grades, so let us pick up the action at a grade λ larger than some appropriate constant, assuming that all grades less than λ have been processed already.
 *
 * Let us now turn to the processing of grade λ.  Lemma 4.1 can be called upon to compute a canonical submap of the visibility map of each chain in grade λ.
 * Preprocessing each chain for ray-shootidng is done by using Lemma 3.6.  Since there are (n-1)/2^λ chains in grade λ, we conclude that processing grade λ requires time at most proportional to
 *
 * n*λ^2(log λ)*2^(B*λ(4B/3-1/3))+ n*λ*2^(-B*λ)
 *
 *  From our choice of B - 1/5, it follows that preprocessing grade λ takes O(n2^[-lmabda/76) time, therefore processing all p+1 grades, and thereby completeing the up-phase, takes linear time. */

}

/* Let l be a any positive grade and let C be an arbitrary chain in any grade l >= l.  If a 2^[Bl]-granular conformal submap of V(C) is available in normal form,
 * then it is possible to compute V(C) in time at most (c-1/l)2^l, where c is some constant large enough. */
void lemma42()
{
	/* We proceed by induction on λ.  Let S be the 2^[B*λ]-granular conformal submap of V(C).
	 * The case where λ is a constant is trivial since the regions of S have bounded size, and therefore the missing chords can be provided in constant time per region.  So, let us switch directly to the inductive case,
	 * assuming that λ is large enough.  Let R be a region of S.
	 * Because of conformality, the union of all the arcs of R can be partitioned into a constant number of single edges and vertex-to-vertex pieces of ∂C with at most 2^[B*λ] edges.
	 * Applying Lemma 4.1, we can compute a canonical submap for each connected polygonal piece in the partition in time at most proportional to */

	lemma41();
	 /*
	 * λ^2(log λ)2^(B*λ(1-B/3+4*B^2/3{
	 *
	 * Each of these submaps has granularity at most 2^[B[Bλ]], so we can pursue the merging by putting
	 * together all these submaps and thus create a single normal form 2^[B[B*λ]]-granular conformal submap of V(R*),
	 * where R* is the boundary of R minus a veretx (to ensure that it is nonclosed).
	 * For consistency, we should regard R* as a standrad polygonal curve and not as part of a double boundary.
	 * The operation requires a constant number of merges, so we can carry it out effectively by merging submaps
	 * two-by-two like in Lemma 4.1.
	 *
	 * There is a small subtlety in this last round of merges, which we should explain.
	 * To take a simple, suppose that R* has two arcs and two exit chords: a1,
	 * a1b1, a2, a2b2, in cyclic order.  It could be that the endpoints of a1 or a2 are not vertices of ∂C,
	 * so to deal with the most general case, assume that a1 consists of b2b'2, B1, a'1,a1 and a2 consists of b1b'1, B2, a'2b2, where a1',b'1,a'2,b'2 are all vertices of ∂C (Fig 4.1).
	 * Let S1 (resp. S2) be the canonical submap for the vertex-to-vertex piece of P corresponding to B1 (resp. B2) and let T1 (resp. T2) be canonical submaps for the 3-edge polygonal curve a'1, a1, b1, b'1 (resp. a'2,a2,b2,b'2). */

	lemma41();

	 /* We obtain S1 and S2 by application of Lemma 4.1, while T1 and T2 are computed directly (tilting the edges a1b1 and a2b2 symbolically to keep the merging algorithm from complaining later.)
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
	 * so computing the 2^[B[Bλ]]-granular conformal submap of all the V(R*)'s takes time at most proportional to
	 *
	 * 2^i*λ^2(log λ)*2^B^2λ(4B/3-1/3)
	 *
	 * We can now extract the relevant information, i.e., the exit chords falling entirely within each region R.
	 * This involves checking the exit chords of the computed submap of V(R*) and keeeping only those both of whose endpoints lie on the arcs (in the double boundary sense) of the region R.
	 * This leads to a new map S* of V(C) which is a refinement of S: all its arcs originate from the previous merges, therefore S* is a 2^[B[Bλ]]-semigranular conformal submap of V(C).
	 * We can only speak of semigranularity because some of the chords connecting the R*'s might be removable now.  We can check each of the exit chords directly, which as we saw in Section 3.3,
	 * takes a total amount of time linear in the number of exit chords in S*.
	 * Now that we have a 2^[B[B*λ]]-granular conformal submap of V(C) at our disposal we observe that [Bλ] <= λ - 1 for λ large enough, so that we can apply the induction hypothesis and derive V(C) in
	 * time at most (c-1/(lamdda-1))2^l.  Putting everything together, the total running time for the construction of V(C) is at most
	 *
	 * a2^l*lamda^2(log λ)*2^(B^2*λ*(4B/3-1/3) + (c-1/(λ-1))*2^l
	 *
	 * for some constant a > 0.  With the setting B = 1/5, this is no more than
	 *
	 * a*2^l*λ^2(log λ)*2^[-λ/375] + (c-1/(λ-1)*2^l <= (c-1/λ)*2^l
	 *
	 * for λ large enough.
	 *
	 * During the up-phase we built a normal-form 2^[Bp]-granular conformal submap of V(P) in linear.
	 *
	 * By Lemma 4.2, therefore, V(P) can be obtained also in linear time.  As demonstrated in [6] and [11],
	 * a triangulation can be easily derived from the visibility map in linear time, so our main goal has been reached. */
}

/* It is possble to compute the visibility map of a simple polygonal curve, and, hence, a triangulation of a simple polygon, in linear time */
void theorem43()
{
}

void startup()
{
	/* Using local shooting, we find the point of ∂C1 that a0 sees with respect to C1.
	 * Although a0 is at worst infinitesimally close to ∂C2 it does not always lie on it, as we shall see in the next paragraph.
	 * However, using the information about the endpoints of C2 encoded in the normal-form representation of S2 (namely, pointers to incident arcs),
	 * we can find, in constant time, in which regions of S2 the point a0 lies.  This allows us to do local shooting and find the point of ∂C2 that a0 sees with respect to C2.
	 * These two pieces of information combine to give us the unique point c0 of ∂C that a0 sees with respect to C.  We distinguish between two cases:
	 *
	 * 1. If c0 belongs to ∂C2, then we set p = a0 and we call the region of S2 crossed by a0c0 current: the start-up phase is over (Figure 3.1.1).
	 * 2. If c0 belongs to ∂C1, from Lemma 2.1, the chord a0c0 splits ∂C into two curves, each closed under visibility.  One of these curves, the one running from a0 to c0 clockwise,
	 * is a piece of ∂C1.  (Fig. 3.1.2), so the points of ∂C that its exit chord endpoints see all belong to ∂C1, and thus are available directly from S1.
	 * We can therefore skip all the way to c0.  Now, however, c0 sees a point of ∂C2, namely a0, so we set p = c0 and call the region of S2 containing a0 current.
	 *
	 * Technically, it is not quite true that a0 is always a point of ∂C2.  It coincides with one most often, but when it sits at a local extremum (in the y-direction) it is not one because of duplication.
	 * What is true, however, is that when c0 cannot see a point of ∂C2, an infinitesimal deformation of ∂C2 locally around a0 can make c0 see one.
	 * This is a minor technicality which will not affect the remainder of the fusion algorithm, so for simplicity we still go on saying that c0 sees a point of ∂C2 with respect to C.
	 * Another minor problem is that a0c0 might lie on an exit chord of S2 and thus there might be more than one candidate for the status of current region.
	 * We break ties by electing the region that we locally enter as we leave p in a clockwise traversal of ∂C1.  This concludes the start-up-phase.
	 * At this point we have the following situation (all visibility being understood with respect to C):
	 *
	 * A. The points of ∂C that are seen by the exit chord endpoints of S1 on the portion of ∂C1 running clockwise from a0 to the point p in its current position have all been determined already.
	 * B. The point q of ∂C that is seen by p belongs to ∂C2 and the chord pq lies in the region of S2 called current.  If p lies on a chord between two regions of S2,
	 * then the current region should be the one that we enter as we locally leave p clockwise around ∂C1.
	 * These two conditions form our loop invariant, that is, they hold prior to veery iteration of the process which we now describe. */
}

void main_loop()
{
	/* Let Ai denote the oriented arc of S1 running from ai-1 to ai (in clockwise order around ∂C1): by extension A1 (resp. Am+1) stands for the subarc extending from a0 to a1 (resp. am to am+1).
	 * Let Ak be the arc containing p.  In the likely event that p is an endpoint of a chord of S1 and thus belongs to two arcs, we must choose the one starting (and not ending) at p, i.e., we set the condition
	 * p != ak.  When p is set to am+1, however, the algorithm simply terminates and no Ak need be defined.  Let R denote the current region prior to enterting the following loop:
	 * iterate through j = k, k+1,... until one of these three cases occurs: */

	uint k = 0;

	uint j = k;
	for( ;; ){
		 /* case:
		 * (i) aj lies in R and the point of ∂C that aj sees belongs to ∂C2 (Figure 3.2.1), or
		 * (ii) the previous conditiion (i) does not hold, but R has at least one exit chord such that the point of ∂C seen by one of its endpoints belongs to Aj, but strictly follows p (Fig. 3.2.2), or
		 * (iii) j = m+2 */

		 /* If case (i) occurs, find which point of ∂C is seen by aj, declare that all aj's (k<=i<j) see points of ∂C1 (with respect to C), set p = aj, let the current region still be R,
		 * and iterate through the loop, resetting k so as to comply with its definition.  If case (ii) occurs, then all of the candidate endpoints, i.e, those chord endpoints satisfying (ii),
		 * determine the one which sees the point p' that is the last one encountered as we traverse ∂C1 clockwise starting from p.  In Fig. 3.2.2, for example, p' is the point labeled p3 and the chose endpoint is labled q3.
		 * Next, declare that all aj's (k <= i < j) see points ∂C1, set p = p', make current the region of S2 which we enter as we locally cross the exit chord at p' along ∂C1,
		 * and iterate after updating k and R according to their defintiions.
		 * In case (iii) we stop and, unless k = m+2, we declare that all ai's (k <= i < m+1) see points of ∂C1.*/
	}

	 /* We have made several claims and skipped over important implementation issues in order to get the main idea of the algorithm across.  Next, we fill in the missing parts and substantiate our claims. */
}

void restore_conformality()
{
	/* As we said earlier, there is no reason to believe that the fusion of S should be confromal.  Things can never be too bad, however.  Indeed, let A1, A2,... be the arcs of a region R of S in counterclockwise order.
	 * It is clear that each Ai belongs to ∂C1 or ∂C2 but not both.
	 *
	 * So, we partition the sequence of arcs into runs, B1, B2,...,meaning that Bj = Ai,Ai+1,...,Aij+1-1 is a maximal subsequence of arcs from either ∂C1 or ∂C2 (but not both).
	 * In the defintion of maximal, we regard A1, A2, ... as a circular sequence.
	 * Because any exit chord endpoint of Si is still an endpoint of a chord in S and, with the possible exception of the chords incident upon a0 or am+1, every chord of S that connects two points of ∂Ci is also a chord of Si,
	 * it follows by conformality that a run associated with ∂Ci cannot have more than four exit chords in its midst,
	 * not counting the new chords incident upon a0 or am+1.  Therefore, a run cannot have more than a constant number of arcs.  On the other hand, it follows from Lemma 2.2 that there are at most two runs.
	 * Why is that so?  The lemma says that if we walk along ∂C clockwise we will in effect traverse, among other things, the boundary of R counterclockwise (except for the exit chords).
	 * If we begin our walk at one of the two points of ∂C corresponding to the vertex C1 n C2, we first exhaust, say ∂C1 and the ∂C2.
	 * Therefore, the counterclockwise traversal of the boundary of R must exhaust first the runs Bi contributed by S1 and then the runs contributed by S2.
	 * Obviously, this leaves only the possibilty of having at most one run of each type, and hence at total of at most two runs.
	 * The conclusion to draw is that, although not necessarily confromal, the submap S has no region with more than a bounded number of arcs.  If S is not confromal we must now reduce the number of arcs per region
	 * to four or less by adding new chords into S.  To discover these chords we need the ability to check whether two arcs or subarcs of the same region can "see" each other (Lemma 3.2).
	 * We also need to show that the desired chords do exist (Lemma 3.3). */
}

void merge_submaps()
{
	/* The inner loop of the visibility algorithm involves merging two confromal submaps.  Everything else in the algorithm is part of a control mechanism for deciding what gets to be merged with what,
	 * at what time, and with what desired granularity.
	 *
	 * Let C1 and C2 be two polygonal curves of n1 and n2 vertices respectively, whose union C forms a connected vertex-to-vertex piece of the input
	 * (simple and nonclosed) polygonal curve P; we assume that C1 n C2 is a vertex of P.  Let Si (i = 1,2) be a yi-granular confromal submap of V(Ci), with y1 <= y2.  Given any integer y >= y2,
	 * to merge S1 and S2 (where y is understood) means to compute a normal-form y-granular conformal submap of V(C).
	 * To facilitate the exposition we assume that we have at our dispoal two primitives: one is a ray-shooting oracle, which allows us to shoot a horizontal ray toward any subarc of S1 or S2 and discover which point,
	 * if any, is first hit by the ray; this gives us a way to discover new chords.  The other primitive is an arc-cutting oracle, which enables us to cut up any subarc into a small number of pieces for which 
	 * conformal submaps of the appropriate granularity have already been computed.  This is to be used for restoring the conformality of merged submaps.
	 * The merge proceeds in three stages.
	 *
	 * First we find which points of ∂C can be seen by the endpoints of the exit chords of Si (i=1,2) and by the companion vertices resulting from the duplication of C1 n C2;
	 * this gives us chords which we use to create a submap of S of V(C), called the fusion of S1 and S2 (Sectieon 3.1).
	 *
	 * In the second stage we ensure that the submap is conformal, which might involve adding new chords to cut up regions with more than four arcs.
	 * This is done by calling upon the arc-cutting oracle, which allows us to deal with subarcs for which conformal subamps and their tree decompositions are avilable.
	 * Finding new chords to cut up big regions is carried out by binary search through the appropriate tree decompositions, using the ray-shooting oracles along the way (Section 3.2).
	 * 
	 *
	 * In the third stage, finally, we bring the submap S to the desired granularity by removing chords if necessary (Section 3.3).  The implementation of the oracles is dicussed in Section 3.4.
	 * We need to be able to distinguish between an arc of ∂C and the piece of C from which it originates.  For this purpose we introduce the notation abar to refer to the portion of C to which an arc a of ∂C corresponds.
	 * Recall that an arc may double-back around an endpoint of C, so abar may not always be as "long" as a.  We assume that each Si is given in normal form and that the following set of primitives is avilable.
	 * For each region arc a of Si (i = 1, 2) specified by a pointer to its arc-structure:
	 * (i) There exists a ray-shooter which, given any point p along with a horizontal direction (left or right) and any subarc a' of a specified by its two endpoints
	 * 	(along with two pointers to the input table to indicate the names of the edges of P that contain these two endpoints as well as two flags indicating which side of 6P is to be understood),
	 * 	reports the single point of a' (if any) that a ray of light shot from p in the given direction would hit in the absence of any obstacle except a'.
	 * 	In addition to the point hit, the report should also include the name of the edge of P that contains it.
	 * 	The report should take O(f(yi)) time, where f is a nondecreasing function.
	 * (ii) There exists an arc-cutter which, in O(g(yi)) time, subdivides the subarc a' into at most g(yi) subarcs a1, a2, ..., such that
	 * 	(1) each aj is specified by its two endpoints and a pair of pointers into the input table to indicate which edges of P contain these endpoints;
	 * 		the pair should be ordered to reflect a clockwise traversal along 6P and two flags should be included to indicate on which sides of 6P these endpoints fall;
	 * 	(2) the relative interior of no aj sohuld contain a point of ∂Ci that corresponds to an endpoint of Ci, that is, each subarc must lie entirely on one side of ∂C (no double-backing); and
	 * 	(3) except for a1bar and a2bar (in the case where these are single-edge pieces attached to the points of C corresponding to the endpoints of a'), all the ajbas are vertex-to-vertex subchains of Ci
	 * (i.e., they do not stop in the middle of an edge) and, for each of them, an h(yi)-granular conformal submap of V(ajbar) is available in normal form.  Again, g and h are assumed to be nondecreasing functions.
	 *
	 * Given these oracles we show how to merge S1 and S2 in
	 *
	 * O((n1/y1 + n2/y2 + 1)f(y2)g(y2)(h(y2) + log(n1+n2)))
	 *
	 * time.  Ideally, we would like the extra factor f(y2)g(y2)(h(y2) + log(n1+n2)) to be constant.  This would mean that the merge could be done in time proportional not to the total size of the submaps
	 * but to the number of chords in them.  We cannot archive this, but we can find functions f, g, h which, although nonconstant, are small enough for our purposes.
	 * Specifically, we have f(x) = O(x^0.74), g(x) = O(log x{, and h(x) = O(x^0.20).  This allows us to carry out a merge in time almost proportional to the total number of chords.
	 * Note that to archive f(x) = g(x) = x is trivial but, for our purposes, completely useless. */
}

void visibility_algorithm()
{
	/* Let P be a simple nonclosed polygonal curve with n vertices v1, ..., vn.
	 * By padding the curve with additional vertices, if necessary, we can assume that n = 2^p + 1.
	 * Any subcurve of P of the form va, ..., vb, where a-1 is a multiple of 2^λ and b-a=2^λ is called a chain in grade λ.  Obviously,
	 *
	 * (i) a grade-λ chain has 2^λ+1 vertices,
	 * (ii) there are 2^(p-λ) chains in grade λ, and
	 * (iii) there are p+1 grades: 0,1, ..., p.
	 *
	 * We begin our work bottom-up, computing conformal submaps of granularity of roughly m^B,
	 * where m is the size of the underlying curve and B is some small enough positive constant;
	 * we set B=1/5, but to make the complexity analysis more explicit we leave B as a parameter in most of the calculations.
	 * We pursue the computation until the submap for the whole polygon has been obtained, which completes the up-phase.
	 * Then we reverse the process and work top-down until the submap has been completely refined into its full-fledged visibility map.
	 * The down-phase does not work by calling the visibility algorithm recursively on the regions of the top subamp,
	 * but rather it uses data structures left behind during the top-phase (the submaps for the chains and their ray-shooting structures) to speed up the refinement process. */
}

bool verify_triangulation(vector<Point> const& polygon, vector<LineSegment> const& triangulation)
{
	if( triangulation.size() != polygon.size() - 3 ) return false;

	// sweep line algorithm

	return true;
}

struct FileNotFound{};

vector<Point> load_polygon(string fname)
{
	ifstream in(fname);
	if( !in ){
		cerr << "file " << fname << " not found!\n";
		throw FileNotFound();
	}

	vector<Point> points;

	string str;
	while( getline(in, str) ){
		uint colon = str.find(",");
                string strx  = str.substr(0, colon); trim(strx);                                                      
                string stry  = str.substr(colon+1 ); trim(stry); 
                int   x     = lexical_cast<int>(strx);
                int   y     = lexical_cast<int>(stry);

		Point p;
		p.x = x;
		p.y = y;
		points.push_back(p);
	}

	return points;
}

int main(int argc, char* argv[])
{
	auto p = load_polygon("poly/square");
}
