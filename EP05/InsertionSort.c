/* Esta função rearranja o vetor v[0..n-1] em ordem
* crescente. */

void Inserção (int n, int v[]) {
    int i, j, x;
    for (j = 1; /*A*/ j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
        v[i+1] = v[i];
        v[i+1] = x;
    }
}