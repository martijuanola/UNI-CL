func f(x : int) : float
   var M : array[4] of int
   var R : array[4] of float
   var y : float
   var i : int

   R = [ y>0 ? y+1 : -i-1 for z in M ];
   M = [ y>0 ? i+1 : -y-1 for y in M ];
   R = [ q[4-R] ? y+1 : -i-1 for i in R ];
   R = [ -y*2+1 ? i+1 : -i-1 for i in R ];
   return R[0] + M[i];
endfunc

func main()
  var a,b,c: int
  var s : char
  var q : bool
  var A: array[10] of int
  var B: array[10] of int
  var C: array[5] of bool

  A[c] = B[q] - f(x);
  A = [ true ? b+1 : 0 for q in B ];
  if B[q] == C[b*a] then
     B = [ a[3] ? true : b*(-c+1) for b in B ];
  endif
  C[a] = q or A[3.2+b]=='x';
  C = [ s=='z' ? a%2==0 : a*b for s in A ];
  B = [ 5 + (q or b!=3) ? b*2 : b>0 for y in C];
  b[5] = A[B[2]] + B[A];
endfunc
