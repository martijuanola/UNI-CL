func main()
  var a,b,c: int
  var A: array[2] of int
  var B: array[3] of int
  var C: array[5] of char
  var x,y : float

  unpack A into a,b;  
  c = A[x+1] + b;
  pack a*b, a+2, c-1+A[1] into B; 
  unpack A into A[1], A[0]; 
  unpack A into B[b-1], B[c+1]; 
  B[x] = C[y-1];
endfunc
