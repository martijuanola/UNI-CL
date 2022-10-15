func main()
  var a,b: int
  var x,y: float

  x = 3;
  a = 2;
  b = 6;
  y = x**a;
  write y*2; write "\n";

  while x**b > 3 do
     write x;
     write "**";
     write b;
     write "=";
     write x**b; write "\n";
     b = b-1;
  endwhile

  write 3 + (y-2.5)**(b+4) - x**(b-1); write "\n";
endfunc
