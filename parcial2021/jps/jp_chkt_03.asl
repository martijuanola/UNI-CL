func main()
  var a,b,c: int
  var A: array [2] of int
  var B: array [3] of int
  var C: array [5] of char
  var x,y : float

  unpack x into a,b;  
  c = A[0] + b;
  pack a*b, a+true, c-1+A[1] into B; 
  pack A,C,y,a into b; 
  pack a[1], b-1, 3 into B; 
  unpack A into A[1], A[0]; 
  unpack A into B[b-1], B[x+1]; 
  x = C[b+c-2];
  C[y-1] = y+1;
endfunc
