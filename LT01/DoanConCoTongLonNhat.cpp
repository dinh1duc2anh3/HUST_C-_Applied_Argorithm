//dung chia de tri
int SubSeqMax(int i,int j){
	if (i == j) return a[i];
	int m = (i+j)/2;
	int wL = SubSeqMax(i,m);
	int wR = SubSeqMax(m+1,r);
	
	int wLM = MaxLeftMid(i,m);
	int wRM = MaxRightMid(m+1, j);
	int wM = wLM + wRM;
	
	return max(max(wL,wR),wM);
}

int MaxLeftMid(int i, int m){
	int ans =a[m],sum =0;
	for(int k=m; k>=i; k--){
		sum += a[k];
		ans = max(sum,ans);
	}
	return ans;
}

int MaxRightMid(int m, int j){
	int ans = a[m], sum =0;
	for (int k=m; k<=j; k++){
		sum += a[k];
		ans = max(sum,ans);
	}
	return ans;
}
