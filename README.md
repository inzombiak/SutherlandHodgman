# SutherlandHodgman
2D Implementation of Sutherland-Hodgman Clipping

A basic implementation of the Sutherland-Hodgman Clipping algorithm.

## Controls:
 * Q - switches between drawing and selecting mode. When drawing, a little red dot will follow the cursor
 * Drawing Mode:
   * Left Click - place vertex
   * Space - links the vertices in the order they were placed. Note: There is no testing for non-simple polygons yet, so KISS
 * Selecting Mode:
   * Left Click and Drag - move a shape around
   * Hold Left Click + Delete/Backspace - delete shape
   * LCtrl + Left Click - selects the polygon to clip
   * LAlt + Left Click - select polygon to use as clipping plane ~(concave shapes cant be used as a clipping plane)~
   * Space - clips polygon
   
## Build Requirements:
SFML 2.4.2 for rendering

## References:
Sutherland-Hodgman Algorithm - [wikipedia.org](https://en.wikipedia.org/wiki/Sutherland%E2%80%93Hodgman_algorithm)
