#define N 1e4+5;

int mem[N];

for (int i=0; i<n; i++){
	mem[i] =-1;
}

int Fib(int n){
	if (n <= 2) return 1;
	if (mem[n] != -1) return mem[n];
	
	int res = Fib(n-1) + Fib(n-2);
	mem[n] = res;
	
	return res;
}
