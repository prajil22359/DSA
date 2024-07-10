void mul(int A[2][2], int R[2][2], int n) {
if (n == 1) {
R[0][0] = A[0][0]; 
R[0][1] = A[0][1];
R[1][0] = A[1][0]; 
R[1][1] = R[1][1];
return;
}

if (n % 2 == 0) {
mul(A, R, n/2);

// mul2 takes two 2x2 matrices as input and
// returns the multiplication in the first
// matrix
mul2(R, R); // R <- R * R
}
else {
mul(A, R, (n-1)/2);
mul2(R, R); // R <- R * R
mul2(R, A); // R <- R * A
}
}

