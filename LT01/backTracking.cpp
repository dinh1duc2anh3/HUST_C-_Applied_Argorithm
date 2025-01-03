try(k){
	for v = 1 to 2n do {
		if check(v,k){
			xk =v;
			f= f+ d[xk-1,xk];
			visited[v] = true;
			if v<= n then load +=1
			else load -= 1;
			if k = n then updateBest();
			else {
				if f + Cmin*(2n-k+1) < f* then try(k+1);
			}
			if v<= n then load -=1;
			else load += 1;
			f = f- d[xk-1,xk];
			visited[v] = false;
		}
	}
}

check(v,k){
	if (visited[v] = true) reutrn false;
	if v > n then {
		if (visited[v-n] = false) return false;
		
	}
	else {
		if (load + 1 > k) return false;
	}
	return true;
 }
 
 
 updateBest(){
 	if f + d[x2n,0] < f* then {
	 	f* = f + d[x2n,0]
	 }
 }
