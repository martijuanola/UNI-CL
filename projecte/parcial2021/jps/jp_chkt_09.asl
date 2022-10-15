func f(p: {int, bool, float}, a: bool) : bool
  var s : {bool, bool, char}
  if a then
     s{0} = p{1} and not p{0}<3;
  else
     s{1} = p{2} != 0.3;
  endif
  s{2} = p+3;
  s{2} = 'c';
endfunc

func main()
  var i : int
  var x,y: float
  var b: bool
  var t : {int, bool, float}
  var q : {float, int}

  t{0} = 3*(i+b);
  t{1} = 1 - q{0} * 5;
  t{1} = q{1} > 5.2;
  if x+i then
     q{0} = q{1} <= x-1;
     y = t{1};
  endif
  x = 2*t{2} + q{0};
  y = q{1} - f(t, q{0}) + f(b, q{1});
  z = i + f(t, b);
  z = 4 - f(q, not b);
  q{5} = 3.2;
endfunc
