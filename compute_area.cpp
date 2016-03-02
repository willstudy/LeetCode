/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top
right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        int area1_length = abs( A - C );
        int area1_width = abs( B - D );

        int area2_length = abs( E - G );
        int area2_width = abs( F - H );

        int result = area1_length * area1_width + area2_length * area2_width;

        // 不重叠的情况
        if( B >= H || F >= D || C <= E || G <= A ) return result;

        // 重叠的情况下
        int length = abs( min(C,G) - max(A,E) );
        int width = abs( min(D,H) - max(B,F) );
        result = result - length * width;
        return result;
    }
};
