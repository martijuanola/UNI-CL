func main()
  var i : int
  var x: float
  var b: bool
  var t : struct {h:int, y:bool, z:float}
  var q : struct {k:float, p:int}

  t.h = 3*(i+b);
  t.y = q.k > 5.2;
  if x+i then
     q.k = q.p*x-1;
  endif
  x = t.z + q.k;
  i = x*2;
endfunc
