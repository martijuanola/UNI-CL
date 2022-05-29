func main()
  var a,b: int
  var x,y: float

  x = 3;
  a = 2;
  b = 6;
  y = 2**3**4;
  write y; write "\n";

  y = 2/2.1**3**4;
  write y; write "\n";

  y = (2/2.1)**3**4;
  write y; write "\n";

  while a**b > 10 do
     write 2*a**b/5; write "\n";
     write (2*a)**b/5; write "\n";
     write 2*a**(b/5); write "\n";
     write 2*(a**b)/5; write "\n";
     write (2*a)**(b/5); write "\n";
     b = b-1;
  endwhile
  write 2**(b+4/a)**(b-1); write "\n";
endfunc
