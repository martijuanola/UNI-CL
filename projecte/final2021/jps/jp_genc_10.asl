func tres(a: int) : int
  return 3;
endfunc

func dump(a : array [10] of int)
  var i: int
  i=0;
  while i<10 do
     write a[i]; write " ";
     i = i+1;
  endwhile
  write "\n";
endfunc

func main()
  var a,b: array [10] of int
  var i : int
  i=0;
  while i<10 do
     a[i] = 3;
     b[i] = 77;
     i = i+1;
  endwhile
  map a into b using tres;
  dump(b);
endfunc
