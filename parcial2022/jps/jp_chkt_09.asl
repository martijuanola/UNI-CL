func f(a: bool) : bool
  return a > 1;
endfunc

func main()
  var i : int
  var x,y: float
  var b: bool
  var t : struct {x1:int, x2:bool, x3:float}
  var q : struct {a1:float, a2:int}

  t.x1 = 3*(i+b);
  t.x2 = 1 - q.a1 * 5;
  t.x2 = q.a2 > 5.2;
  if x+i then
     q.a1 = q.a2 <= x-1;
     y = t.x2;
  endif
  x = 2*t.x3 + q.a1;
  y = q.a2 - f(q.a1);
  if f(t.x2) then
     b = t.x2 or x>0;
  endif
  z = i + f(not b);
  q.z6 = 3.2;
endfunc
