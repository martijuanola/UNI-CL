func calc(a: int) : float
  var x: float
  x = 1 - 3*a/0.75;
  return 1/x;
endfunc

func dump(a : array [5] of float)
  var i: int
  i=0;
  while i<5 do
     write a[i];
     write "\n";
     i = i+1;
  endwhile
endfunc

func main()
  var a : array [5] of int
  var c : array [5] of float
  var i : int

  i=0;
  while i<5 do
     a[i] = 10*i;  c[i] = 77;
     i = i+1;
  endwhile

  map a into c using calc;  
  dump(c);
endfunc
