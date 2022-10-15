func main()
  var i : int
  var x: float
  var b: bool
  var t : {int, bool, float}
  var q : {float, int}

  t{0} = 3*(i+b);
  t{1} = q{0} > 5.2;
  if x+i then
     q{0} = q{4}*x-1;
  endif
  x = t{3} + q{0};
  q{5} = 3.2;
  i = x*2;
endfunc
