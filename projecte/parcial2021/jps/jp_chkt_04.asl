func main()
  var a,b,c: int
  var A: array[2] of int
  var B: array[3] of float
  var C: array[5] of char
  var x,y : float
  var t : char

  unpack A into a,b,c;  
  c = A[0] + b;
  pack a*b, x+true, c-1.0+y into B; 
  unpack A into A[1], A[x+1], c; 
  pack a+1, 'b', x, 'c', t into C;
  pack a, true, x+1, 'c' into A;
endfunc

