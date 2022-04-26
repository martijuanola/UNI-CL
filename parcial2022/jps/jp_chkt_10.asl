func g(p: struct {x1:int, x2:bool, x3:float}, a: bool) : int
  var s : struct {b1:bool, b2:bool, a:char}
  if a then
     s.b1 = p.x2 and not p.x1<3;
  else
     s.b2 = p.x3 != 0.3;
  endif
  s.a = p+3;
  s.a = 'c';
endfunc

func main()
  var i : int
  var x,y: float
  var b: bool
  var t : struct {u:int, h4:bool, u:bool, t:float}
  var p1 : struct {x1:int, x2:bool, x3:float}
  var p2 : struct {i:int, b:bool, f:float}
  var q,q2 : struct {f:float, i:int}

  t.u = 3*(i+b);
  t.h4 = q.f > 5.2;
  if t.u then
     q.f = q.h * x-1;     
  endif
  t.u = true;
  x = t.y + t.u;
  q.f = q.i + 3.2;
  i = x*2 + q;
  y = g(b, q.a2);
  if g(p2, p2.b) then
     b = p1.x2 or x>0;
  endif
  z = i + g(p1, b) - g(q, p2.b);
  z1.k = 33 > t;
  t.t = z2.n1 * 5;
  q = p1;
  q2 = q;
endfunc
