func main()
  var a,b,c: int
  var A: array[2] of int
  var B: array[3] of float
  var C: array[5] of char
  var x,y : float
  var t : char

  unpack A into a,b,c;  
  c = A[0] + b;
  pack a*b, a+true, x-1+A[1] into B; 
  unpack A into A[1], A[0], x; 
  unpack A into B[b-1], B[x+1]; 
  pack a+1, 'b', x, 'c', t into C;
  pack a, true, x+1, 'c' into A;
  unpack B into x, y, B[0]; 
  unpack B into a, y, t, x; 
endfunc

