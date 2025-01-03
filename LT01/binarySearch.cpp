 int lo =0, hi = n-1;
 while (hi < lo){
 	int mid = (lo + hi)/2;
 	if (P(mid)){
 		hi = mid;
	}
	else {
		lo = mid+1;
	}
 }
 
 if (lo == hi && P(lo)){
 	cout << "the minimum index where " << x<< "canbe found is " << lo << endl;
 }
 else {
 	cout << "cannot find " << x<<endl;
 }
 
 
 bool P(int i){
 	return a[i] >= x;
 }
