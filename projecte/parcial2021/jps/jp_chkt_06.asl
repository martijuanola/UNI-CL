func main()
  var i : int
  var x: float
  var b: bool
  var t : {int, bool, float}
  var q : {float, int}

  t{0} = 3*(i+b);
  t{1} = q{0} > 5.2;
  if x+i then
     q{0} = q{1}*x-1;
  endif
  x = t{2} + q{0};
  i = x*2;
endfunc
