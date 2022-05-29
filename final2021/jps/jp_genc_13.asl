func dumpi(a : array [10] of int)
  var i: int
  i=0;
  while i<10 do
     write a[i]; write " "; i = i+1;
  endwhile
  write "\n";
endfunc

func dumpf(a : array [10] of float)
  var i: int
  i=0;
  while i<10 do
     write a[i]; write " "; i = i+1;
  endwhile
  write "\n";
endfunc

func toreal(x: int) : float
  return x*1.3;
endfunc

func getint(x: float) : int
   if x<10 then return 10; endif
   if x<20 then return 20; endif
   if x<50 then return 50; endif
   if x<100 then return 100; endif
   return 500;  
endfunc

func main()
  var a : array [10] of int
  var c : array [10] of float
  var i : int

  i=0;
  while i<10 do
     a[i] = 10*i;  c[i] = 77;  i = i+1;
  endwhile

  write "a: "; dumpi(a);
  map a into c using toreal;
  write "c: "; dumpf(c);  
  map c into a using getint;
  write "a: "; dumpi(a);

  map a into c using getint;
  write "c: "; dumpf(c);  
endfunc
