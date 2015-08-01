int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int area1 = (C - A) * (D - B);
    int area2 = (G - E) * (H - F);
    int commonLeft = A, commonRight = C, commonTop = D, commonBottom = B;
    if (E > A) commonLeft = E;
    if (C > G) commonRight = G;
    if (F > B) commonBottom = F;
    if (D > H) commonTop = H;
    int width = 0;
    int height = 0;
    if (commonRight > commonLeft && commonTop > commonBottom) {
        width = commonRight - commonLeft;
        height = commonTop - commonBottom;
    }
    return area1 + area2 - width * height;
}