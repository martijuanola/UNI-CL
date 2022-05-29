func same(a: int) : int
  return a;
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
  var a : array [10] of int
  var i : int
  i=0;
  while i<10 do
     a[i] = 10*i;
     i = i+1;
  endwhile
  map a into a using same;  
  dump(a);
endfunc
