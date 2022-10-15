func main()
  var a,b,c: int
  var A: array [2] of int
  var B: array [3] of int
  var C: array [5] of char
  var x,y: float
  var t: char

  unpack A into a,b,c;
  c = A[0] + b;
  pack a*b, a+true, c-1+A[1] into B;
  unpack A into A[1], A[0], A[2];
  unpack A into B[b-1], B[x+1];
  pack 'a', 'b', t, 'c', t into C;
  pack 'a', 'b', t, 'c' into C;
endfunc
