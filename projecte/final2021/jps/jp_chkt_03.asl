func f(r:float, b:bool) : char
  if r > 10 and b then
     return 'a';
  else
     if r< 5 then return 'B';
     else return '@';
     endif
  endif
endfunc

func main()
  var a,b: int
  var A: array[2] of float
  var x,y: float
  var p : char
  var n : bool

  x = 3;
  y = x**a;
  b = a**x;
  p = (a+2)**(x-1);  
  while a**b == 2 do
     A[0] = A[1]**(b+3);
     A[1] = a**p + y;
     a = y**p - 1;
  endwhile

  write f(p**n);
endfunc
