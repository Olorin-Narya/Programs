class ShellSort {

public shellsort() {

}
public void init(int[]) {
	 int i, temp, flag = 1, numLength = num.length( );
	 int d = numLength;
	 while( flag || (d > 1)) {                    // boolean flag (true when not equal to 0)
	      flag = 0;                               // reset flag to 0 to check for future swaps
	      d = (d+1) / 2;
	      for (i = 0; i < (numLength - d); i++) {
	           if (num[i + d] > num[i]) {
	                  temp = num[i + d];         // swap positions i+d and i
	                  num[i + d] = num[i];
	                  num[i] = temp;
	                  flag = 1;                  // tells swap has occurred
	           }
	      }
	 }
}
}
